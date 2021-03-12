#include <iostream>
#include <deque>

using namespace std;
int n, k;
int result = 0;

int main() {
	deque<int> deq;
	// 양방향 접근 = deque활용
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		deq.push_back(i);
	}

	int score = 0;
	while (k--) {
		int a, index;
		cin >> a;
		while (1) {
			if (deq.front() == a) {
				// 맨 앞이 맞다면 pop
				deq.pop_front();
				break;
			}
			for (int i = 0; i < deq.size(); i++) {
				if (deq[i] == a) {
					index = i;
					// 원소의 위치 찾기
				}
			}
			if (index <= deq.size() / 2) {
				// 위치가 앞쪽이라면
				// 앞에서 뒤로 옮기기
				int num = deq.front();
				deq.push_back(num);
				deq.pop_front();
				result++;
			}
			else {
				// 위치가 뒤쪽이라면
				// 뒤에서 앞으로 옮기기
				int num = deq.back();
				deq.push_front(num);
				deq.pop_back();
				result++;
			}
		}
	}

	cout << result;
}