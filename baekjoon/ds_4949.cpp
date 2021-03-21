#include <iostream>
#include <string>
#include <stack>

using namespace std;
int n;
bool check;

int main() {
	while(1) {
		string str;
		getline(cin, str);

		if (str == ".") break;
		// .이 들어오면 종료

		stack<char> stk;

		int Left = 0;
		int Right = 0;
		int left = 0;
		int right = 0;
		check = false;


			for (int j = 0; j < str.size(); j++) {
				if(str[j] == '[' || str[j] == '(')
					stk.push(str[j]);
				// [, (이 들어오면 스택에 넣기

				if (str[j] == ')') {
					// )이 들어왔을 때 앞에 (가 있어야 함
					if (stk.empty()) {
						check = true;
						break;
					}
					else if (stk.top() != '(') {
						check = true;
						break;
					}
					else stk.pop();
				}
				else if (str[j] == ']') {
					// ]이 들어왔을 때 앞에 [가 있어야 함
					if (stk.empty()) {
						check = true;
						break;
					}
					else if (stk.top() != '[') {
						check = true;
						break;
					}
					else stk.pop();
				}
			}

			if (check == false && stk.empty()) {
				// 스택이 비어있지 않으면 대칭X
				cout << "yes" << endl;
			}
			else cout << "no" << endl;
	}
}