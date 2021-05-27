#include <iostream>
#include <deque>

using namespace std;

int n, k, m;
int num = 0;
bool check = false;
deque<int> deq;

int main() {
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		deq.push_back(i);
	}

	while (!deq.empty()) {
		if (!check) {
			for (int i = 0; i < k - 1; i++) {
				deq.push_back(deq.front());
				deq.pop_front();
			}
			cout << deq.front() << endl;
			deq.pop_front();
			num++;
		}
		else {
			for (int i = 0; i < k - 1; i++) {
				deq.push_front(deq.back());
				deq.pop_back();
			}
			cout << deq.back() << endl;
			deq.pop_back();
			num++;
		}
		if (num == m) {
			num = 0;
			check = !check;
			// 방향을 반대로
		}
	}
}