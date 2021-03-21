#include <iostream>
#include <stack>

using namespace std;
int n, k;
int result[500001];
stack<pair<int, int>> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		while (!stk.empty()) {
			if (stk.top().first >= k) {
				// 앞에 큰 숫자가 존재하면
				cout << stk.top().second << " ";
				break;
				// 그 숫자의 index출력하고 break;
			}
			stk.pop();
			// 숫자가 작으면 필요없으니 삭제
			// i보다 i+1이 크면 i+1에 부딪히기 때문에 i는 삭제해도 된다
		}
		if (stk.empty()) cout << 0 << " ";
		// 큰 숫자가 존재하지 않으면
		stk.push({ k, i });
		// 입력받으면서 비교
	}
	
}