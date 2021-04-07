#include <iostream>
#include <stack>

using namespace std;
int arr[1000001];
int n;
stack<int> stk;
stack<int> result;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = n; i >= 1; i--) {
		// 오른쪽부터 접근
		if (stk.empty()) result.push(-1);
		// 큰 수가 비어있다면
		else {

			while (1) {
				if (arr[i] < stk.top()) {
					// 큰수가 있다면
					result.push(stk.top());
					// 저장하기
					break;
				}
				else {
					// 크지 않으면 오른쪽에서 다른 큰수 찾기
					stk.pop();
				}
				if (stk.empty()) {
					result.push(-1);
					break;
				}
			}
		}
		stk.push(arr[i]);
		// 넣어주기
	}

	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}
}