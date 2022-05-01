#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << max((a * b) / c, (a * c) / b) << "\n";
}