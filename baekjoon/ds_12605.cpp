#include <iostream>
#include <stack>
#include <string>

using namespace std;
int n;

stack<string> s;

int main() {
	cin >> n;
	cin.ignore();
	// 입력 한번 무시
	for (int i = 1; i <= n; i++) {
		string str;
		getline(cin, str);
		string word;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ' ') {
				s.push(word);
				word.clear();
			}
			else {
				word += str[j];
			}
		}
		s.push(word);

		cout << "Case #" << i << ": ";
		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
}