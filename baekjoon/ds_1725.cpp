#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int N, ans, height[100002];
stack<int> s;

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> height[i];

	s.push(0);
	for (int i = 1; i <= N + 1; i++)
	{

		while (!s.empty() && height[s.top()] > height[i])
			// 높이가 높은 것들을 저장
			// 높이가 낮아졌다면 i보다 높이가 높은 것들의 넓이 구하기
		{
			int check = s.top();
			// 높이
			s.pop();
			ans = max(ans, height[check] * (i - s.top() - 1));
		}
		s.push(i);
		// 높이 저장
	}
	cout << ans;

}