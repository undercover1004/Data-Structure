#include <iostream>
#include <stack>

using namespace std;
string str1, str2;
bool check = false;

int main() {
	stack<char> stk;
	// list썼다가 시간초과로 스택으로 변경
	cin >> str1;
	cin >> str2;
	int index = str2.size() - 1;
	for (int i = 0; i < str1.size(); i++) {
		stk.push(str1[i]);
		// 일단 넣어주고

		if (stk.top() == str2[index] && i >= index) {
			// 제일 끝 문자를 찾았을 때, 길이가 적당할때
			stack<char> save;
			for (int i = index; i >= 0; i--) {
				if (stk.top() == str2[i]) {
					// 뒤에서부터 하나씩 비교
					save.push(stk.top());
					// 저장용 스택에 저장
					stk.pop();
				}
				else {
					// 비교하다가 틀렸다면
					while (!save.empty()) {
						stk.push(save.top());
						save.pop();
						// 다시 복구해주기
					}
					break;
				}
			}
		}
	}

	if (stk.empty()) cout << "FRULA";
	// 스택이 비어있다면
	else {
		stack<char> c;
		while (!stk.empty()) {
			c.push(stk.top());
			stk.pop();
		}
		while (!c.empty()) {
			cout << c.top();
			c.pop();
		}
	}
}