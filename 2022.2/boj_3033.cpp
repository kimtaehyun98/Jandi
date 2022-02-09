#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 100003;

int MOD(ll n) {
    if (n >= 0) return n % mod;
    else return ((-n / mod + 1) * mod + n) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; string str;
    cin >> n;
    cin >> str;
    int l = 0, r = n, ans = 0;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        ll pow = 1, h = 0;
        bool check = false;
        vector<int>Hash[mod];
        for (int i = 0; i + mid < n; i++) {
            // 라빈 카프 알고리즘으로 hash 값 구하기
            if (i == 0) {
                for (int j = 0; j < mid; j++) { // mid 길이의 hash값 구하기
                    // 이때 abcde 라면 e부터 차례대로 구한다 -> 2^3000 이런걸 방지하기 위해서
                    h = MOD(h + 1LL * str[mid - 1 - j] * pow);
                    if (j < mid - 1) pow = MOD(pow * 2); // 즉 pow가 overflow 나지 않게 방지
                }
            }
            else {
                h = MOD(2 * (h - 1LL * str[i - 1] * pow) + str[i + mid - 1]); // // 이전 hash 값으로 다음 hash값 구하기
            }
            if (!Hash[h].empty()) { // hash 테이블이 비어있지 않다 = 해시 충돌 or 동일한 문자열
                // 충돌인지 확인
                for (int c : Hash[h]) { // 같은 hash 값을 갖는 모든 문자열 검사
                    bool stop = true;
                    for (int k = 0; k < mid; k++) {
                        if (str[i + k] != str[c + k]) {
                            stop = false;
                            break;
                        }
                    }
                    if (stop) { // 두 문자열 동일
                        check = true;
                        break;
                    }
                }
            }
            if (check) { // mid 값이 정답이 될 수 있음 -> 더 이상 진행 X
                break;
            }
            else { // 같은 문자열이 없다면 계속 진행
                Hash[h].push_back(i);
            }
        }
        if (check) {
            ans = max(ans, mid);
            l = mid;
        }
        else r = mid;
    }
    cout << l << "\n";
}