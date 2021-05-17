#include <iostream>
#include <stack>

using namespace std;
int n, num;

stack<int> stk;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		while (1) {
			if (stk.empty() || num < stk.top()) {
				stk.push(num);
				break;
			}
			else {
				stk.pop();
			}
		}
	}

	cout << stk.size();
}