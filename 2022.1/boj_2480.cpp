#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    if (a == b && b == c) ans = 10000 + (a * 1000);
    else if (a == b || a == c) ans = 1000 + (a * 100);
    else if (b == c) ans = 1000 + (b * 100);
    else ans = max(max(a, b), c) * 100;
    cout << ans << "\n";
}