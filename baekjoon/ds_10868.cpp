#include <iostream>

using namespace std;
int n, m;
long long* tree;

typedef long long ll;
ll arr[100010];

class segment {
public:
	segment(int n) {
		tree = new long long[n * 4];
		// 4배의 크기
	}

	ll init(ll left, ll right, ll node) {
		if (left >= right) {
			tree[node] = arr[left];
			return tree[node];
		}

		ll mid = (left + right) / 2;
		// 중간값
		ll a = init(left, mid, node * 2);
		ll b = init(mid + 1, right, node * 2 + 1);

		tree[node] = min(a, b);
		return tree[node];
	}

	ll find_min(ll start, ll end, ll left, ll right, ll node) {
		if (right < start || end < left) {
			return 1000000010;
			// 범위를 벗어나면
		}
		if (right <= end && left >= start) {
			return tree[node];
		}
		ll mid = (left + right) / 2;
		ll a = find_min(start, end, left, mid, node * 2);
		ll b = find_min(start, end, mid + 1, right, node * 2 + 1);
		// 최솟값 찾기
		ll result = min(a, b);
		return result;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	segment s(n);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	s.init(1, n, 1);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << s.find_min(a, b, 1, n, 1) << '\n';
	}
}