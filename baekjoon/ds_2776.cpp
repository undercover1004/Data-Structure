#include <iostream>
#include <algorithm>

using namespace std;

int T, m, n;
int arr[1000005];

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> arr[i];
		}
		
		sort(arr + 1, arr + 1 + m);
		// 작은순서대로 분류

		cin >> n;
		for (int i = 1; i <= n; i++) {
			int start = 1;
			// 시작번호
			int end = m;
			// 끝번호
			int mid = (start + end) / 2;
			// 중간번호
			int num, result = 0;
			cin >> num;
			while (start <= end) {
				mid = (start + end) / 2;
				// 중간번호 설정
				if (arr[mid] < num) {
					//입력값이 중간에 있는 값보다 클경우
					// mid + 1 ~ end
					start = mid + 1;
				}
				else if (arr[mid] > num) {
					// 입력값이 중간에 있는 값보다 작을경우
					// start ~ mid - 1
					end = mid - 1;
				}
				else {
					result = 1;
					break;
				}
			}

			cout << result << '\n';
		}
	}
}