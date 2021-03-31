#include <iostream>
#include <string>
#include <map>

using namespace std;
int T, n;

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		int result = 1;
		map<string, int> clothes;
		// map 활용
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			clothes[b]++;
			// 종류 개수 파악하기
		}

		map<string, int>::iterator it;
		for (auto it = clothes.begin(); it != clothes.end(); it++) {
			result *= it->second + 1;
			// 하나씩 곱해주기
		}
		cout << result - 1 << endl;
		clothes.clear();
	}
}