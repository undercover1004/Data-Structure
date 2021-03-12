#include <iostream>
#define MAX 1000000
using namespace std;

int n, m, parent[MAX + 1];

int find(int n) {
	if (parent[n] < 0) return n;
	parent[n] = find(parent[n]);
	return find(parent[n]);
	// root 노드를 찾는 함수
}

void uni(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	// root가 같다면
	parent[b] = a;
	// 다르면 서로 연결
	// 연결해주는 함수
}

int main() {
	// 유니온 파운드 문제
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cout.tie(NULL);

	fill(parent, parent + MAX + 2, -1);

	int a, b, c;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 0) uni(b, c);
		else {
			if (find(b) == find(c)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
}