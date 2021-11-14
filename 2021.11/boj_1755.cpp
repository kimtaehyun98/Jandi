#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> psi;

string arr[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main() {
	int n, m;
	cin >> n >> m;
	vector<psi>v;
	for (int i = n; i <= m; i++) {
		string temp = "";
		if (i < 10) {
			v.push_back(psi(arr[i], i));
		}
		else {
			v.push_back(psi(arr[i / 10] + arr[i % 10], i));
		}
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (cnt == 10) {
			cout << "\n";
			cnt = 0;
		}
		cout << v[i].second << " ";
		cnt++;
	}
}