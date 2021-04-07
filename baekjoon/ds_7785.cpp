#include <iostream>
#include <map>
#include <string>
#include <stack>

using namespace std;
int n;

int main() {
	cin >> n;
	stack<string> stk;
	map<string, bool> p;
	// map으로 풀었는데 풀고 나니 set이 더 깔끔한 것 같다..
	while (n--) {
		string a, b;
		cin >> a >> b;
		if (b == "enter") {
			// 출근
			p[a] = true;
		}
		else {
			// 퇴근
			p[a] = false;
		}
	}

	for (auto it = p.begin(); it != p.end(); it++) {
		if (it->second == true)
			// 출근한 상태라면
			stk.push(it->first);
		// 역순으로 정렬하기 위해 stack사용
	}

	while (!stk.empty()) {
		cout << stk.top() << '\n';
		stk.pop();
	}
}
