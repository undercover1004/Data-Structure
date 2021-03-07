#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	stack<int> stk;
	int result = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			// (가 나오면 쇠막대기의 개수++
			stk.push(i);
		}
		else {
			// )가 나오면 --
			if (stk.top() + 1 == i) {
				// 레이저일 경우
				stk.pop();
				result += stk.size();
				// 막대기의 개수만큼 추가
			}
			else {
				// 레이저가 아닐경우
				// 막대기 하나가 끝나므로 + 1
				stk.pop();
				result += 1;
			}
		}
	}

	cout << result;
}