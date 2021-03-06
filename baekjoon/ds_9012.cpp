#include <iostream>
#include <stack>
#include <string>

using namespace std;
int n;
bool check;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		stack<char> stk;
		// 스택 초기화를 안해서 틀렸다
		// 스택을 전부 비우지 않고 다음 케이스로 넘어갔을 때가 문제였다

		int Left = 0;
		int Right = 0;
		check = false;

		if (str[0] == ')') {
			cout << "NO" << endl;
		}

		else {
			for (int j = 0; j < str.size(); j++) {
				stk.push(str[j]);
			}

			while (!stk.empty()) {
				char c = stk.top();
				stk.pop();
				if (c == ')') {
					Right++;
				}
				if (c == '(') {
					if (Left == Right) {
						cout << "NO" << endl;
						// () 개수가 똑같은데 (가 먼저 나올 때
						check = true;
						break;
					}
					else
					{
						Left++;
					}
				}
			}

			if (check == false) {
				if (Left == Right) {
					// ( )의 개수가 같으면
					cout << "YES" << endl;
				}
				else {
					cout << "NO" << endl;
				}
			}
		}
	}
}
