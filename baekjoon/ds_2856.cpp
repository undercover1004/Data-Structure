#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
priority_queue<float, vector<float>, less<float>> pq;
vector<float>vec[101];

int n, m, k;

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			float b;
			cin >> a >> b;
			vec[a].push_back(b);
			// 참가자별로 분류
		}
	}

	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end(), greater<float>());
		// 참가자가 자신있는 점수
		pq.push(vec[i].front());
	}

	float score = 0;
	while (k--) {
		// 제일 높은 점수 k개 뽑기
		score += pq.top();
		pq.pop();
	}

	score = abs(score);
	printf("%.1f", score);
}