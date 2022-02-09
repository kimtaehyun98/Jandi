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
            // ��� ī�� �˰������� hash �� ���ϱ�
            if (i == 0) {
                for (int j = 0; j < mid; j++) { // mid ������ hash�� ���ϱ�
                    // �̶� abcde ��� e���� ���ʴ�� ���Ѵ� -> 2^3000 �̷��� �����ϱ� ���ؼ�
                    h = MOD(h + 1LL * str[mid - 1 - j] * pow);
                    if (j < mid - 1) pow = MOD(pow * 2); // �� pow�� overflow ���� �ʰ� ����
                }
            }
            else {
                h = MOD(2 * (h - 1LL * str[i - 1] * pow) + str[i + mid - 1]); // // ���� hash ������ ���� hash�� ���ϱ�
            }
            if (!Hash[h].empty()) { // hash ���̺��� ������� �ʴ� = �ؽ� �浹 or ������ ���ڿ�
                // �浹���� Ȯ��
                for (int c : Hash[h]) { // ���� hash ���� ���� ��� ���ڿ� �˻�
                    bool stop = true;
                    for (int k = 0; k < mid; k++) {
                        if (str[i + k] != str[c + k]) {
                            stop = false;
                            break;
                        }
                    }
                    if (stop) { // �� ���ڿ� ����
                        check = true;
                        break;
                    }
                }
            }
            if (check) { // mid ���� ������ �� �� ���� -> �� �̻� ���� X
                break;
            }
            else { // ���� ���ڿ��� ���ٸ� ��� ����
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