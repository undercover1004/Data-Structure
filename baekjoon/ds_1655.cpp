#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, less<int>> maxpq; //최대 힙
	priority_queue<int, vector<int>, greater<int>> minpq; //최소 힙
	int mid;
	int n;
	cin >> n;
	int i = 0;

	while (n--) {
		int k;
		cin >> k;

		if (i == 0) {
			// 비어있을 경우
			mid = k;
			i++;
		}
		else {
			if (k >= mid) minpq.push(k);
			// 중간값보다 크면
			else if (k < mid) maxpq.push(k);
			// 중간값보다 작으면

			int minsize = minpq.size();
			int maxsize = maxpq.size();

			if ((minsize + maxsize + 1) % 2 == 0) {
				//전체 짝수개라면
				if (minsize <= maxsize) {
					int tmp = mid;
					mid = maxpq.top();
					maxpq.pop();
					minpq.push(tmp);
				}
			}
			else {
				//전체 홀수개라면 
				if (minsize < maxsize) {
					// max가 더 많으면 max에서 젤 큰게 중간값
					minpq.push(mid);
					mid = maxpq.top();
					maxpq.pop();
				}
				else if (minsize > maxsize) {
					// min가 더 많으면 min에서 젤 작은게 중간값
					maxpq.push(mid);
					mid = minpq.top();
					minpq.pop();
				}
			}
		}
		cout << mid << '\n';
	}
	return 0;
}