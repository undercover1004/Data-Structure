#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
stack<string> stk;

int main() {
	while (1) {
		getline(cin, str);
		if (str == "고무오리 디버깅 끝") break;
		else if (str == "문제") {
			stk.push(str);
		}
		else if (str == "고무오리") {
			if (stk.empty()) {
				stk.push("문제");
				stk.push("문제");
			}
			else {
				stk.pop();
			}
		}
	}
	if (stk.empty()) cout << "고무오리야 사랑해";
	else cout << "힝구";
}