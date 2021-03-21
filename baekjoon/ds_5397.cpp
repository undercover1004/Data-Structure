#include <iostream>
#include <string>
#include <list>

using namespace std;
int n;
char c;

int main() {
	cin >> n;
	while (n--) {
		list<char> vec;
		string str;
		cin >> str;
		list<char>::iterator it = vec.begin();
		// 처음부터 시작

		for (int i = 0; i < str.size(); i++) {
			char c = str[i];
			if (c == '<' && it != vec.begin()) {
				// < 나올시 한 칸 앞으로
				it--;
			}
			else if (c == '>' && it != vec.end()) {
				// > 나올시 한 칸 뒤로
				it++;
			}
			else if (c == '-' && it != vec.begin()) {
				it = vec.erase(--it);
				// - 나오면 앞에 있는거 지우기
			}
			else {
				if (c == '<' || c == '>' || c == '-') continue; 
				// 그 외 문자면 넣기
				it = vec.insert(it, c);
				it++;
			}
		}
		for (auto i = vec.begin(); i != vec.end(); i++) {
			cout << *i;
		}
		cout << '\n';
	}
}