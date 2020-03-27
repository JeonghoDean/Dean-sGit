/*
스택
입구오 ㅏ출구가 하나밖에 없는 상태
*/
#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop(); 
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;

}