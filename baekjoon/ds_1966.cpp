#include <iostream>
#include <queue>

using namespace std;
int n, m, cnt;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		// 중요도가 높은 순
		cin >> m >> cnt;
		int result = 0;

		for (int i = 0; i < m; i++) {
			int a;
			cin >> a;
			pq.push(a);
			q.push({ a, i });
		}

		while (1) {
			int num = q.front().first;
			int index = q.front().second;
			if (num == pq.top()) {
				// 중요도가 젤 높으면 출력
				result++;
				// result번째 출력
				if (index == cnt) {
					// 우리가 찾던 것이 출력하면
					cout << result << endl;
					break;
				}
				q.pop();
				pq.pop();
			}

			else {
				// 중요도가 젤 높은거보다 낮으면
				// 뒤로 넘기기
				q.push({ num, index });
				q.pop();
			}
		}
	}
}