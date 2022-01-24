#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t, n, x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &x);
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", n / x, n % x);
    }
}