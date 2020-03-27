/* C++ STL sort�Լ� �⺻����
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

//�����͸� ��� �����ϴ� ��� ex) �̸��� ��
class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	//���� ������ ������ ���� ����
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};
int main() {
	Student students[] = {
		Student("�� ", 90),
		Student("�� ", 92),
		Student("�� ", 97),
		Student("�� ", 88),
		Student("�� ", 79)
	};
	sort(students, students + 5);
	for(int i=0;i<5;i++){
		cout << students[i].name << ' ';
	}
}