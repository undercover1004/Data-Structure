#include <iostream>
#include <stack>

using namespace std;

int main() {
	string str;
	stack<char> s;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '(') {
			s.push(c);
		}
		else if (c == '*' || c == '/') {
			// * /는 우선순위가 높으므로 따로 처리
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(c);
		}
		else if (c == '+' || c == '-') {
			while (!s.empty() && s.top() != '(') {
				// (가 나오기 전까지 다
				cout << s.top();
				s.pop();
			}
			s.push(c);
		}
		else if (c == ')') { 
			// )가 나올경우 (나오기 전까지 다
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			cout << c;
		}
	}
	while (!s.empty()) {
		char ch = s.top();
		s.pop();
		cout << ch;
	}

}