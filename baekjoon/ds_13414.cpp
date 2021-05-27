#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, m;
map<string, int> student;
vector<string> vec;


int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		student[str]++;
		vec.push_back(str);
	}

	for (int i = 0; i < vec.size(); i++) {
		if (student[vec[i]] == 1) {
			cout << vec[i] << '\n';
			n--;
		}
		else {
			student[vec[i]]--;
		}
		if (n == 0) break;
	}
}