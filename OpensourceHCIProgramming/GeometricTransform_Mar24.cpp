#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#include <opencv2/opencv.hpp>

using namespace cv;

typedef struct {
	int r, g, b;
}int_rgb;


int** IntAlloc2(int height, int width)
{
	int** tmp;
	tmp = (int**)calloc(height, sizeof(int*));
	for (int i = 0; i < height; i++)
		tmp[i] = (int*)calloc(width, sizeof(int));
	return(tmp);
}

void IntFree2(int** image, int height, int width)
{
	for (int i = 0; i < height; i++)
		free(image[i]);

	free(image);
}

int_rgb** IntColorAlloc2(int height, int width)
{
	int_rgb** tmp;
	tmp = (int_rgb * *)calloc(height, sizeof(int_rgb*));
	for (int i = 0; i < height; i++)
		tmp[i] = (int_rgb*)calloc(width, sizeof(int_rgb));
	return(tmp);
}

void IntColorFree2(int_rgb** image, int height, int width)
{
	for (int i = 0; i < height; i++)
		free(image[i]);

	free(image);
}

int** ReadImage(char* name, int* height, int* width)
{
	Mat img = imread(name, IMREAD_GRAYSCALE);
	int** image = (int**)IntAlloc2(img.rows, img.cols);

	*width = img.cols;
	*height = img.rows;

	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++)
			image[i][j] = img.at<unsigned char>(i, j);

	return(image);
}

void WriteImage(char* name, int** image, int height, int width)
{
	Mat img(height, width, CV_8UC1);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			img.at<unsigned char>(i, j) = (unsigned char)image[i][j];

	imwrite(name, img);
}


void ImageShow(char* winname, int** image, int height, int width)
{
	Mat img(height, width, CV_8UC1);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			img.at<unsigned char>(i, j) = (unsigned char)image[i][j];
	imshow(winname, img);
	waitKey(0);
}



int_rgb** ReadColorImage(char* name, int* height, int* width)
{
	Mat img = imread(name, IMREAD_COLOR);
	int_rgb** image = (int_rgb * *)IntColorAlloc2(img.rows, img.cols);

	*width = img.cols;
	*height = img.rows;

	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++) {
			image[i][j].b = img.at<Vec3b>(i, j)[0];
			image[i][j].g = img.at<Vec3b>(i, j)[1];
			image[i][j].r = img.at<Vec3b>(i, j)[2];
		}

	return(image);
}

void WriteColorImage(char* name, int_rgb** image, int height, int width)
{
	Mat img(height, width, CV_8UC3);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			img.at<Vec3b>(i, j)[0] = (unsigned char)image[i][j].b;
			img.at<Vec3b>(i, j)[1] = (unsigned char)image[i][j].g;
			img.at<Vec3b>(i, j)[2] = (unsigned char)image[i][j].r;
		}

	imwrite(name, img);
}

void ColorImageShow(char* winname, int_rgb** image, int height, int width)
{
	Mat img(height, width, CV_8UC3);
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			img.at<Vec3b>(i, j)[0] = (unsigned char)image[i][j].b;
			img.at<Vec3b>(i, j)[1] = (unsigned char)image[i][j].g;
			img.at<Vec3b>(i, j)[2] = (unsigned char)image[i][j].r;
		}
	imshow(winname, img);

}

template <typename _TP>
void ConnectedComponentLabeling(_TP** seg, int height, int width, int** label, int* no_label)
{

	//Mat bw = threshval < 128 ? (img < threshval) : (img > threshval);
	Mat bw(height, width, CV_8U);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			bw.at<unsigned char>(i, j) = (unsigned char)seg[i][j];
	}
	Mat labelImage(bw.size(), CV_32S);
	*no_label = connectedComponents(bw, labelImage, 8); // 0까지 포함된 갯수임

	(*no_label)--;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			label[i][j] = labelImage.at<int>(i, j);
	}
}

#define imax(x, y) ((x)>(y) ? x : y)
#define imin(x, y) ((x)<(y) ? x : y)

int BilinearInterpolation(int** image, int width, int height, double x, double y)
{
	int x_int = (int)x;
	int y_int = (int)y;

	int A = image[imin(imax(y_int, 0), height - 1)][imin(imax(x_int, 0), width - 1)];
	int B = image[imin(imax(y_int, 0), height - 1)][imin(imax(x_int + 1, 0), width - 1)];
	int C = image[imin(imax(y_int + 1, 0), height - 1)][imin(imax(x_int, 0), width - 1)];
	int D = image[imin(imax(y_int + 1, 0), height - 1)][imin(imax(x_int + 1, 0), width - 1)];

	double dx = x - x_int;
	double dy = y - y_int;

	double value
		= (1.0 - dx) * (1.0 - dy) * A + dx * (1.0 - dy) * B
		+ (1.0 - dx) * dy * C + dx * dy * D;

	return((int)(value + 0.5));
}


void GT0(int** img_in, int** img_out, int size){
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			img_out[y][x] = img_in[y][x];
}
void GT1(int** img_in, int** img_out, int size){
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			img_out[y][x] = img_in[y][size - 1 - x];
}
void GT2(int** img_in, int** img_out, int size){
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			img_out[y][x] = img_in[size - 1 - y][x];
}
void GT3(int** img_in, int** img_out, int size){
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			img_out[y][x] = img_in[size - 1 - y][size - 1 - x];
}
void GT4(int** img_in, int** img_out, int size){
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			img_out[y][x] = img_in[x][y];
}
void GT5(int** img_in, int** img_out, int size){
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			img_out[y][x] = img_in[x][size - 1 - y];
}
void GT6(int** img_in, int** img_out, int size){
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			img_out[y][x] = img_in[size - 1 - x][y];
}
void GT7(int** img_in, int** img_out, int size){
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			img_out[y][x] = img_in[size - 1 - x][size - 1 - y];
}

void main() {
	int height, width;
	int** image = ReadImage((char*)"barbara.png", &height, &width);
	int** image_out = IntAlloc2(height, width);

	ImageShow((char*)"barbara_Original", image, height, width);
	
	GT0(image, image_out, height);
	ImageShow((char*)"GT0", image_out, height, width);
	
	GT1(image, image_out, height);
	ImageShow((char*)"GT1", image_out, height, width); 
	
	GT2(image, image_out, height);
	ImageShow((char*)"GT2", image_out, height, width); 
	
	GT3(image, image_out, height);
	ImageShow((char*)"GT3", image_out, height, width); 
	
	GT4(image, image_out, height);
	ImageShow((char*)"GT4", image_out, height, width); 
	
	GT5(image, image_out, height);
	ImageShow((char*)"GT5", image_out, height, width); 

	GT6(image, image_out, height);
	ImageShow((char*)"GT6", image_out, height, width); 

	GT7(image, image_out, height);
	ImageShow((char*)"GT7", image_out, height, width);

	IntFree2(image, height, width);
	IntFree2(image_out, height, width);
}