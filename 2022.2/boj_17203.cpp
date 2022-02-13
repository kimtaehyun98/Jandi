#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, s, e;
    cin >> n >> q;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // 부분합 구해놓기
    vector<int>pf;
    pf.push_back(0);
    for (int i = 1; i < n; i++) {
        pf.push_back(abs(v[i] - v[i - 1]) + pf[i - 1]);
    }
    for (int i = 0; i < q; i++) {
        cin >> s >> e;
        cout << abs(pf[s - 1] - pf[e - 1]) << "\n";
    }
}