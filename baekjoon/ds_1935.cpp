#include <iostream>
#include <stack>
#include <string>
using namespace std;

double arr[26];
string str;

int main() {
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    int num;
    cin >> num;
    cin >> str;
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
        // 숫자 입력받기
    }
    stack<double> stk;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
            // 연산기호가 나오면 제일 최근 두개 숫자 연산
            double a = stk.top();
            stk.pop();
            double b = stk.top();
            stk.pop();
            if (str[i] == '*') stk.push(a * b);
            else if (str[i] == '/') stk.push(b / a);
            else if (str[i] == '+') stk.push(b + a);
            else if (str[i] == '-') stk.push(b - a);
        }
        else stk.push(arr[str[i] - 'A']);
        // 해당하는 숫자 push
    }

    cout << fixed;
    cout.precision(2); //소숫점 둘째자리까지 출력
    cout << stk.top();
    return 0;
}