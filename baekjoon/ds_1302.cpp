#include <iostream>
#include <map>

using namespace std;
int n;
map<string, int> book;
int score = 0;
string result;

int main() {
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		// ÆÈ¸° °³¼ö
		book[str]++;
	}

	for (auto it = book.begin(); it != book.end(); it++) {
		if (score < it->second) {
			// Á¦ÀÏ ¸¹ÀÌ ÆÈ·È´Ù¸é
			score = it->second;
			result = it->first;
		}
	}

	cout << result;
}