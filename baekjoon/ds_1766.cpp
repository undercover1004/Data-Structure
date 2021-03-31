#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[100000];
int n, m;
int arr[32001];

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		arr[b]++;
		// 선행문제의 개수
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	// 번호가 작은 순으로 나열
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			// 선행문제가 없는 것
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int t = pq.top();
		pq.pop();
		cout << t << " ";
		for (int i = 0; i < vec[t].size(); i++) {
			int cnt = vec[t][i];
			arr[cnt]--;
			// 선행문제가 하나 실행했으니 빼주기
			if (arr[cnt] == 0) pq.push(cnt);
			// 선행문제를 다 했다면
		}
	}
}