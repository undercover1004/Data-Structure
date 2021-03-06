#include <iostream>
#include <queue>
#include <string>

using namespace std;
int n;
queue<int> q;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;

		cin >> str;
		if (str == "push") {
			int s;
			cin >> s;
			q.push(s);
		}

		else if (str == "front") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.front() << endl;
			}
		}

		else if (str == "size") {
			cout << q.size() << endl;
		}

		else if (str == "empty") {
			if (q.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}

		else if (str == "pop") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}

		else if (str == "back") {
			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.back() << endl;
			}
		}

	}
}