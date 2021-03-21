#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
int n, k;
priority_queue<int, vector<int>, greater<int>> mq;
priority_queue<int, vector<int>, less<int>> pq;
// 오름차순, 내림차순

int main() {
	cin >> n;
	while (n--) {
		cin >> k;
		if (k == 0) {
			if (pq.empty() && mq.empty()) cout << 0 << endl;
			else if (pq.empty()) {
				cout << mq.top() << endl;
				mq.pop();
			}
			else if (mq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			}
			else {
				if (abs(pq.top()) > abs(mq.top())) {
					//양수에서 젤 작은것과 음수에서 젤 큰것 비교(절댓값)
					cout << mq.top() << endl;
					mq.pop();
				}
				else {
					cout << pq.top() << endl;
					pq.pop();
				}
			}
		}
		else {
			if (k > 0) {
				// 양수일때
				mq.push(k);
			}
			else {
				// 음수일때
				pq.push(k);
			}
		}
	}
}
