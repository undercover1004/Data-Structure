#include <iostream>
#include <stack>

using namespace std;
int n, k;
int result = 0;

int main() {
	stack<int> stk;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k == 0) stk.pop();
		// 0이면 최근에 들어간 것 지우기
		else stk.push(k);
		// 아니면 쓰기
	}

	while (!stk.empty()) {
		int num = stk.top();
		stk.pop();
		result += num;
	}

	cout << result;
}