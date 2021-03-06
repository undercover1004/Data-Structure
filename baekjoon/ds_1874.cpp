#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int n, k;
vector<char> vec;
int num = 0;
int result;
bool check = false;

int main() {
	cin >> n;
	stack<int> stk;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		if (num < k) {
			// 크면 하나씩  다 넣기
			while (num <= k - 1) {
				num++;
				stk.push(num);
				vec.push_back('+');
			}

			// 다 넣은후 num값 pop
			result = stk.top();
			stk.pop();
			vec.push_back('-');
			continue;
		}

		else {
			// 작을 때는 바로 pop
			result = stk.top();
			
			if (result == k) {
				// pop한 값이 입력값과 같으면
				stk.pop();
				vec.push_back('-');
			}
			else {
				// 다르면 불가능
				check = true;
			}
		}

	}

	if (check == true) {
		cout << "NO";
	}

	else {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << '\n';
		}
	}

}