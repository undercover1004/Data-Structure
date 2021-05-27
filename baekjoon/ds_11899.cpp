#include <iostream>
#include <stack>

using namespace std;

string str;
stack<char> stk;
int score = 0;

int main() {
	cin >> str;

	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] == '(') {
			// (가 나왔을 때
			if (stk.empty()) {
				score++;
				// 스택이 비어있다면 )를 추가
			}
			else {
				// )가 있다면 () 한 쌍 제거
				stk.pop();
			}
		}
		else if (str[i] == ')') {
			stk.push(')');
		}
	}

	while (!stk.empty()) {
		// 만약 )가 남아있다면 (를 추가
		stk.pop();
		score++;
	}

	cout << score;
}