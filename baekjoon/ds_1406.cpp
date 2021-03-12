#include <iostream>
#include <list>
#include <string>

using namespace std;
int n;

int main() {
	list<char> lst;
	// list 사용
	string str;
	cin >> str;
	for(int i = 0; i <str.size(); i++)
	lst.push_back(str[i]);
	cin >> n;
	list<char>::iterator it = lst.end();
	while(n--) {
		char ch;
		cin >> ch;

		if (ch == 'L') {
			if (it != lst.begin()) {
				it--;
				// 처음이 아니라면 커서를 왼쪽으로
			}
		}
		else if (ch == 'D') {
			if (it != lst.end()) {
				it++;
				// 마지막이 아니라면 커서를 오른쪽으로
			}
		}
		else if (ch == 'B') {
			if (it != lst.begin()) {
				it = lst.erase(--it);
				// 커서 왼쪽 지우기
			}
		}
		else if (ch == 'P') {
			char d;
			cin >> d;
			lst.insert(it, d);
			// 추가
		}
	}

	for (auto i = lst.begin(); i != lst.end(); i++) {
		cout << *i;
	}
}