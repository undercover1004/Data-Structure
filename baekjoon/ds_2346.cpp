#include <iostream>
#include <deque>

using namespace std;

int n;
deque<pair<int, int>> deq;

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		deq.push_back({ a, i });
	}

	while (!deq.empty()) {
		int cnt = deq.front().first;
		int index = deq.front().second;
		deq.pop_front();
		cout << index << " ";

		if (cnt > 0) {
			for (int i = 1; i < cnt; i++) {
				deq.push_back({ deq.front().first, deq.front().second });
				deq.pop_front();
			}
		}

		else {
			cnt = -cnt;
			for (int i = 1; i <= cnt; i++) {
				deq.push_front({ deq.back().first, deq.back().second });
				deq.pop_back();
			}
		}
	}

	return 0;
}