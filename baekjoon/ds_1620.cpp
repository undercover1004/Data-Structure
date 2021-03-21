#include <iostream>
#include <map>
#include <string>

using namespace std;
int n, k;
string str[100001];

int main() {
	cin >> n >> k;
	map<string, int> m;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		m[s] = i;
		str[i] = s;
	}

	while (k--) {
		string a;
		cin >> a;
		if (isdigit(a[0])) {
			cout << str[stoi(a)] << '\n';
		}
		else {
			cout << m[a];
		}
	}
}