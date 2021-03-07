#include <iostream>
#include <deque>

using namespace std;
deque<int> deq;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;

		cin >> str;
		if (str == "push_front") {
			int s;
			cin >> s;
			deq.push_front(s);
		}

		else if (str == "push_back") {
			int s;
			cin >> s;
			deq.push_back(s);
		}

		else if (str == "front") {
			if (deq.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << deq.front() << endl;
			}
		}

		else if (str == "size") {
			cout << deq.size() << endl;
		}

		else if (str == "empty") {
			if (deq.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}

		else if (str == "pop_front") {
			if (deq.empty()) cout << -1 << endl;
			else {
				cout << deq.front() << endl;
				deq.pop_front();
			}
		}

		else if (str == "pop_back") {
			if (deq.empty()) cout << -1 << endl;
			else {
				cout << deq.back() << endl;
				deq.pop_back();
			}
		}

		else if (str == "back") {
			if (deq.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << deq.back() << endl;
			}
		}

	}
}