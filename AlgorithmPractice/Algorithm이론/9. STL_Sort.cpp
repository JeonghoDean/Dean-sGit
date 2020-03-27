/* C++ STL sort함수 기본사용법
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int Basic_Sorting() {
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10);
	for (int i : a) printf("%d ", i);
	sort(a, a + 10, compare);
	for (int i : a) printf("%d ", i);

	return 0;
}

//데이터를 묶어서 정렬하는 방법 ex) 이름과 값
class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	//정렬 기준은 점수가 작은 순서
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};
int main() {
	Student students[] = {
		Student("김 ", 90),
		Student("이 ", 92),
		Student("박 ", 97),
		Student("최 ", 88),
		Student("송 ", 79)
	};
	sort(students, students + 5);
	for(int i=0;i<5;i++){
		cout << students[i].name << ' ';
	}
}