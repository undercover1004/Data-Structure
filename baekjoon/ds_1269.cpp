#include <iostream>
#include <set>

using namespace std;
int n, m, score = 0;
set<int> s;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (s.count(num) == 1) score++;
		// 교집합 찾으면 ++
	}

	cout << n + m - score * 2;
	// 원소 전체의 개수 - 교집합의 개수 * 2
}