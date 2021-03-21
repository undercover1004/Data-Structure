#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;
int n, k;

int main() {
	cin >> n;
	while (n--) {
		string str, input;
		bool check = false;
		cin >> str;
		cin >> k;
		cin >> input;
		deque<int> dq;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] != '[' && input[i] != ']' && input[i] != ',') {
				string temp;
				while (1) {
					temp += input[i];
					// 42의 경우 하나씩 넣으면 4랑 2가 들어감
					// 그래서 더해준 다음에 변환
					i++;
					if (input[i] == ']' || input[i] == ',') {
						break;
					}
				}
				dq.push_back(stoi(temp));
				// int로 변환
			}
		}

		bool reverse = false;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'R') {
				// 뒤집기
				if (reverse) reverse = false;
				else reverse = true;
			}
			else if (str[i] == 'D') {
				if (dq.empty()) {
					check = true;
					break;
				}
				else {
					if (reverse == false) dq.pop_front();
					// 안뒤집히면 앞에꺼 지우기
					else dq.pop_back();
					// 뒤집히면 뒤에꺼 지우기
				}
			}
		}

		if (check) cout << "error" << endl;
		else {
			cout << "[";
			if (!dq.empty()) {
				// 비어있으면 [ ]출력
				if (reverse == false) {
					// 뒤집지 않으면 앞에서부터 출력
					while (1) {
						cout << dq.front();
						dq.pop_front();
						if (!dq.empty()) cout << ",";
						if (dq.empty()) break;
					}
				}
				else {
					// 뒤집어 있으면 뒤에서부터 출력
					while (1) {
						cout << dq.back();
						dq.pop_back();
						if (!dq.empty()) cout << ",";
						if (dq.empty()) break;
					}
				}
			}
			cout << "]" << endl;
		}
	}
}