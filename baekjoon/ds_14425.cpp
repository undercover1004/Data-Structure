#include <iostream>
#include <map>

using namespace std;

map<string, int> word;
int m, n, score = 0;

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		word[str]++;
	}

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (word[str] != 0) score++;
	}
	// map으로 풀었지만 원래 트리이를 사용하는 문제
	// 트리이에 대해서 한번 공부해볼 필요가 있다

	cout << score;
}