#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, t, start = 0;
	string str;
	cin >> n >> k;
	// n자리 숫자 중 숫자 k개를 지워서 얻을 수 있는 가장 큰 수 구해라
	// 맨 앞자리가 자신이 지울 수 있는 숫자 중 최대값이여야 함
	cin >> str;
	deque<char>dq; t = k;
	dq.push_back(str[0]);
	for (int i = 1; i < str.size(); i++) {
		while (!dq.empty() && dq.back() < str[i] && k > 0) {
			dq.pop_back();
			k--;
		}
		dq.push_back(str[i]);
	}
	for (int i = 0; i < n - t; i++)cout << dq[i];
}