#include <iostream>
#include <string>
#include <stack>

using namespace std;
int n;
bool check;

int main() {
		string str;
		cin >> str;

		stack<char> stk;

		int temp = 1;
		int result = 0;
		check = false;


		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				// (나오면 2 곱하기
				temp *= 2;
				stk.push(str[j]);
			}
			else if (str[j] == '[') {
				// [나오면 3 곱하기
				temp *= 3;
				stk.push(str[j]);
			}

			else if (str[j] == ')') {
				if (stk.empty() || stk.top() != '(') {
					check = true;
				}
				else {
					if (str[j - 1] == '(') {
						// ()나올경우 더해주기
						result += temp;
					}
					// 마무리했으니 다시 2로 나눠주기
					stk.pop();
					temp /= 2;
				}
			}
			else if (str[j] == ']') {
				if (stk.empty() || stk.top() != '[') {
					check = true;
				}
				else {
					if (str[j - 1] == '[') {
						// [] 나올경우 더해주기
						result += temp;
					}
					// 마무리했으니 다시 3으로 나누기
					stk.pop();
					temp /= 3;
				}
			}
			
		}

		if (check == false && stk.empty()) {
			// 스택이 비어있지 않으면 대칭X
			cout << result << endl;
		}
		else cout << 0 << endl;
}