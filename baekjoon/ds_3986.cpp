#include <iostream>
#include <stack>

using namespace std;
int n;
int result = 0;

int main() {
	cin >> n;
	while (n--) {
		stack<char> s;
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (s.empty()) {
				s.push(str[i]);
			}
			else {
				if (s.top() == str[i]) s.pop();
				else {
					s.push(str[i]);
				}
			}
		}
		if (s.empty()) result++;
		// 좋은 단어면 stack이 비어있음
	}

	cout << result;
}