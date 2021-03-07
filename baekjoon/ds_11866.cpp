#include <iostream>
#include <list>

using namespace std;

int n, k;

// 1158과 같은문제
int main() {
	cin >> n >> k;
	list<int> lst;
	// list 활용
	for (int i = 1; i <= n; i++) {
		lst.push_back(i);
	}

	list<int>::iterator it = lst.begin();

	cout << "<";
	while (lst.size() != 1) {
		for (int i = 0; i < k - 1; i++) {
			if (it == lst.end()) {
				it = lst.begin();
				// 넘어가면 처음으로
			}
			it++;
			if (it == lst.end()) {
				it = lst.begin();
				// 넘어가면 처음으로
			}
		}

		cout << *it << ", ";
		it = lst.erase(it);
		if (it == lst.end()) {
			it = lst.begin();
		}
	}

	cout << *it << ">";
	return 0;
}