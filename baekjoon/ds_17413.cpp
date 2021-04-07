#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	stack<char> stk;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {
			// <가 나왔을 경우
			if (!stk.empty()) {
				while (!stk.empty()) {
					cout << stk.top();
					stk.pop();
					// 이미 들어간 단어들 뒤집어주기
				}
			}
			while (1) {
				cout << str[i];
				if (str[i] == '>') break;
				// >나오기 전까지 그대로 출력
				i++;
			}
		}

		else if (str[i] == ' ') {
			// 띄어쓰기 나왔을 경우
			while (!stk.empty()) {
				cout << stk.top();
				stk.pop();
				// 들어간 단어들 뒤집기
			}
			cout << ' ';
			// 띄어쓰기 출력
		}

		else if (i == str.size() - 1) {
			// 끝에 도달한 경우
			stk.push(str[i]);
			// 마지막 문자 더해주기
			while (!stk.empty()) {
				cout << stk.top();
				stk.pop();
				// 거꾸로 출력
			}
		}

		else {
			// 뒤집을 문자들 저장
			stk.push(str[i]);
		}
	}
}