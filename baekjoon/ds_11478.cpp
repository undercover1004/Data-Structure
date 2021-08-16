#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

string str;
set<string> s;

int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		string hs = "";
		for (int j = i; j < str.size(); j++) {
			hs += str[j];
			s.insert(hs);
		}
	}

	cout << s.size() << endl;
}