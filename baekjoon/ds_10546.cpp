#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;
vector<string> vec;
int n;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		m[str]++;
		vec.push_back(str);
	}

	for (int i = 0; i < n - 1; i++) {
		string str;
		cin >> str;
		m[str]--;
	}

	for (int i = 0; i < n; i++) {
		if (m[vec[i]] == 1) {
			cout << vec[i];
			break;
		}
	}
}