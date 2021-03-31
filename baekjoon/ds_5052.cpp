#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
int T, n;

int main(){
	cin >> T;
	while (T--) {
		vector<string> vec;
		bool check = false;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			vec.push_back(str);
		}

		sort(vec.begin(), vec.end());
		// 정렬
		for (int i = 0; i < vec.size() - 1; i++) {
			if (vec[i].size() <= vec[i + 1].size()) {
				if (vec[i] == vec[i + 1].substr(0, vec[i].size())) {
					// 똑같은 크기로 잘랐을 때 같으면
					check = true;
					break;
				}
			}
		}

		if (check) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
}