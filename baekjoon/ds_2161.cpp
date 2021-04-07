#include <iostream>
#include <deque>

using namespace std;
int n;

int main() {
	cin >> n;
	deque<int> deq;
	for (int i = 1; i <= n; i++) {
		deq.push_back(i);
	}

	while (!deq.empty()) {
		cout << deq.front() << " ";
		deq.pop_front();
		if (deq.empty()) break;
		deq.push_back(deq.front());
		deq.pop_front();
	}
}