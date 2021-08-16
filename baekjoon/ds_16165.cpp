#include <iostream>
#include <string>
#include <map>

using namespace std;

int group, quiz;
map<string, string> m;

int main() {
	cin >> group >> quiz;
	string str;
	for (int i = 0; i < group; i++) {
		cin >> str;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			string member;
			cin >> member;
			m[member] = str;
		}
	}

	string q;
	int n;
	for (int i = 0; i < quiz; i++) {
		cin >> q;
		cin >> n;
		if (n == 1) {
			cout << m[q] << endl;
		}
		else {
			for (const auto& k : m) {
				if (k.second == q)
					cout << k.first << endl;
			}
		}
	}
}