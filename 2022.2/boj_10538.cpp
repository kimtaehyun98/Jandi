#include <iostream>
using namespace std;
typedef unsigned long long ul;

#define MAXN 2002
#define HASH_SIZE (1 << 23)
#define DIV (HASH_SIZE - 1)

int H, W, N, M;

int myPic[MAXN][MAXN], samPic[MAXN][MAXN];
int samHash[MAXN][MAXN], tmp[MAXN][MAXN];

// �ش� �ڵ尡 ��¥ �ű��� �κ��ε� hashing ���� ���� �ǵ��ư��� ���ش�. ���..?
int CalcMul(int num, int shift) {
    ul rev = 1;
    for (int i = 1; i < num; i++) {
        rev = (rev << shift) + rev;
    }
    return (int)(rev & DIV);
}

// �Ϲ����� hash ���� �Լ�
int GetHash(int* piv, int num, int shift) {
    ul hash = 0;
    for (int i = 0; i < num; i++) {
        hash = (hash << shift) + hash + *piv++;
    }
    return (int)(hash & DIV);
}

// ���� hash���� ���ϴ� �Լ��̴�
/*
    ������� oxxox �� ���� ��
    w = 4 ���� ���� oxxo�� ���� hash���� ���ߴٰ� ���� -> �� ���� prev
    prev ���� ������? ������ ���� xxo�� hash���� ���ѵ�
    ������ ���� x�� �ٿ��� xxox�� hash���� ���Ѵ�.
*/
int GetNext(int prev, int sub, int mul, int add, int shift) {
    ul hash = prev - (sub * mul);
    hash = (hash << shift) + hash + add;
    return (int)(hash & DIV);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> H >> W >> N >> M;
        for (int h = 0; h < H; h++) for (int w = 0; w < W; w++) {
            char a;
            cin >> a;
            myPic[h][w] = a == 'o' ? 1 : 0;
        }
        for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) {
            char a;
            cin >> a;
            samPic[n][m] = a == 'o' ? 1 : 0;
        }

        // Get My Hash -> base���� hash ���� ���ϴ� ���̴�
        for (int i = 0; i < H; i++) tmp[0][i] = GetHash(myPic[i], W, 5);
        int myHash = GetHash(tmp[0], H, 3); // ��������� �ش� ���� w*h ��ü�� hash���̴�

        // Get Sam Hash -> ���ϴ� �迭�� hash�� ���Ѵ�
        // �̶� �ð��� ���̴� ����� �ſ� �ű��ϴ�
        // �� ���� �ڵ���� oxxo ������ xxox�� ����ؼ� �ؽ��߱� ������ ���⼭ O(w*w)�ε�
        // �� �ڵ�� oxxo ������ O(1)�� hash ���� ���ϱ� ������ O(w)�̴�.
        int mulC = CalcMul(W, 5);
        int mulR = CalcMul(H, 3);
        for (int i = 0; i < N; i++) {
            tmp[0][i] = GetHash(samPic[i], W, 5);
            for (int j = 1; j < M - W + 1; j++) {
                tmp[j][i] = GetNext(tmp[j - 1][i], samPic[i][j - 1], mulC, samPic[i][j + W - 1], 5);
            }
        }
        for (int i = 0; i < M - W + 1; i++) {
            samHash[0][i] = GetHash(tmp[i], H, 3);
            for (int j = 1; j < N - H + 1; j++) {
                samHash[j][i] = GetNext(samHash[j - 1][i], tmp[i][j - 1], mulR, tmp[i][j + H - 1], 3);
            }
        }

        // Compare
        int cnt = 0;
        for (int i = 0; i < N - H + 1; i++) for (int j = 0; j < M - W + 1; j++)
            if (samHash[i][j] == myHash) cnt++;
        cout << '#' << tc << ' ' << cnt << '\n';
    }
    return 0;
}