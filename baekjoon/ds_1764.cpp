#include <iostream>
#include <set>

using namespace std;

int n, m;

string str;
set<string> s1, s2;

int main() {
	cin >> n >> m;
	// 자동정렬해주는 set 사용
	
	for (int i = 0; i < n; i++) {
		cin >> str;
		s1.insert(str);
	}

	for (int j = 0; j < m; j++) {
		cin >> str;
		auto it = s1.find(str);
		// 찾으면 넣기
		if (it != s1.end()) s2.insert(str);
	}

	cout << s2.size() << endl;
	for (auto it = s2.begin(); it != s2.end(); it++) {
		cout << *it << endl;
	}
}