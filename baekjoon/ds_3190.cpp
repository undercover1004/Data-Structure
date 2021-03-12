#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int arr[101][101];
int n, m, k;
int X[] = { 0, 1, 0, -1 };
int Y[] = { 1, 0, -1, 0 };
char turn[101];
queue <pair<int, int>> q;
// 큐
vector < pair<int, char>> vec;
// 회전 저장용 벡터

int move(int x, int y) {
	int k = 0;
	int i = 0;
	int count = 0;
	arr[x][y] = 1;
	q.push({ x, y });
	while (1) {
		count++;
		int dx = x + X[k];
		int dy = y + Y[k];
		// 전진
		x = dx;
		y = dy;
		if (dx > n || dy > n || dx <= 0 || dy <= 0) break;;
		if (arr[dx][dy] == 1) break;
		// 방문했던 곳이면
		else if (arr[dx][dy] == 2) {
		}
		else if (arr[dx][dy] == 0) {
			// 제일 먼저 들어온 곳 삭제
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			arr[a][b] = 0;
			// 빈곳 = 0
		}
		q.push({ dx, dy });
		arr[dx][dy] = 1;
		// 방문 = 1

		if (i < vec.size()) {
			if (vec.at(i).first == count) {
				char ch = vec.at(i).second;
				if (ch == 'L') {
					k--;
					if (k < 0) k += 4;
					// 왼쪽으로 회전
				}
				if (ch == 'D') {
					k++;
					if (k > 3) k -= 4;
					// 오른쪽으로 회전
				}
				i++;
			}
		}
	}
	return count;
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 2;
		// 사과 = 2
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a;
		char c;
		cin >> a >> c;
		vec.push_back({ a,c });
	}

	cout << move(1, 1);
	return 0;
}