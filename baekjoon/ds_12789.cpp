#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n;
int num = 1;
stack<int> stk;
queue<int> q;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		q.push(m);
	}

	while (1) {
		if (num == n + 1) {
			// 모두가 간식을 받으면
			cout << "Nice";
			break;
		}
		if (!q.empty() && q.front() == num) {
			// 순서가 맞으면 그냥 간식을 받으러 직행
			num++;
			q.pop();
		}
		else if (!stk.empty() && stk.top() == num) {
			stk.pop();
			num++;
		}
		else {
			if (q.empty()) {
				// 모두 간식을 못받으면
				cout << "Sad";
				break;
			}
			// 한명씩 서는 공간으로 이동
			stk.push(q.front());
			q.pop();
		}
	}

}