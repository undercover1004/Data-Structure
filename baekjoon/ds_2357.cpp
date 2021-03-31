#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100010];
pair<long long, long long>* tree;
int n, m;

// 세그먼트 트리
class segment {
public:
	segment(int n) {
		tree = new pair<long long, long long>[n * 4];
		// 사이즈는 4배
	}

	pair<long long, long long> init(long long left, long long right, long long node) {
		if (left >= right) {
			tree[node].first = tree[node].second = arr[left];
			return tree[node];
		}

		long long mid = (left + right) / 2;
		// 중간값 찾기
		pair<long long, long long> a, b;
		a = init(left, mid, node * 2);
		// left ~ mid
		b = init(mid + 1, right, node * 2 + 1);
		// mid+1 ~ right
		tree[node].first = min(a.first, b.first);
		tree[node].second = max(a.second, b.second);
		return tree[node];
	}

	pair<long long, long long> find_max(long long left, long long right, long long start, long long end, long long node) {
		if (right < start || end < left) {
			return { 1000000010, 0 };
		}
		if (right <= end && left >= start) {
			return tree[node];
		}
		long long mid = (left + right) / 2;
		pair<long long, long long> a, b, result;
		a = find_max(left, mid, start, end, node * 2);
		b = find_max(mid + 1, right, start, end, node * 2 + 1);
		result.first = min(a.first, b.first);
		result.second = max(a.second, b.second);
		return result;
	}

	void del() {
		delete[]tree;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	segment seg(n);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	seg.init(1, n, 1);
	for (int i = 1; i <= m; i++) {
		long long a, b;
		cin >> a >> b;
		pair<long long, long long> p = seg.find_max(1, n, a, b, 1);
		cout << p.first << " " << p.second << '\n';
	}
	seg.del();
}