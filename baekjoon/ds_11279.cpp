#include <iostream>
#include <queue>

using namespace std;

int n, k;
priority_queue<int, vector<int>, less<int>> pq;
// 1927의 반대문제
// 큰 순서대로 정렬

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> k;
		if (k == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				// endl 말고 \n 사용하자
				// 시간초과
				pq.pop();
			}
		}
		else {
			pq.push(k);
		}
	}
}