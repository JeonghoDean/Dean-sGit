#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sorting_by_one_element() {
	vector<pair<string, int>> v;
	v.push_back(pair<string,int>("��", 90));
	v.push_back(pair<string,int>("��", 97));
	v.push_back(pair<string,int>("��", 95));
	v.push_back(pair<string,int>("��", 79));
	v.push_back(pair<string,int>("��", 88));
	
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {	//v.size()�� 5
		cout << v[i].second << ' ';
	}
	return 0;
}

bool compare(pair<string, pair<int, int>> a,
			pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}
int sorting_by_two_elements() {
	vector<pair<string, pair<int, int>>> v;
	v.push_back(pair<string, pair<int, int>>("��", pair<int, int>(90, 19961222)));
	v.push_back(pair<string, pair<int, int>>("��", pair<int, int>(97, 19930518)));
	v.push_back(pair<string, pair<int, int>>("��", pair<int, int>(95, 19930203)));
	v.push_back(pair<string, pair<int, int>>("��", pair<int, int>(90, 19921207)));
	v.push_back(pair<string, pair<int, int>>("��", pair<int, int>(88, 19900302)));

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {	//v.size()�� 5
		cout << v[i].first << ' ';
	}
	return 0;
}

int main() {
	//sorting_by_one_element();
	sorting_by_two_elements();
	return 0;
}