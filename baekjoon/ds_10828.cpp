#include <iostream>
#include <stack>
#include <string>

using namespace std;
int n;
stack<int> stk;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;

		cin >> str;
		if (str == "push") {
			int s;
			cin >> s;
			stk.push(s);
		}

		else if (str == "top") {
			if (stk.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << stk.top() << endl;
			}
		}

		else if (str == "size") {
			cout << stk.size() << endl;
		}

		else if (str == "empty") {
			if (stk.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}

		else if (str == "pop") {
			if (stk.empty()) cout << -1 << endl;
			else {
				cout << stk.top() << endl;
				stk.pop();
			}
		}

	}
}
