#include <iostream>
#include <map>

using namespace std;

int n, m;

map<string, string> mp;
string str1, str2, site;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2;
		mp[str1] = str2;
	}

	for (int j = 0; j < m; j++) {
		cin >> site;
		cout << mp[site] << endl;
	}
}