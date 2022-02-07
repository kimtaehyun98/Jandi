#include <iostream>
using namespace std;
typedef unsigned long long ul;

#define MAXN 2002
#define HASH_SIZE (1 << 23)
#define DIV (HASH_SIZE - 1)

int H, W, N, M;

int myPic[MAXN][MAXN], samPic[MAXN][MAXN];
int samHash[MAXN][MAXN], tmp[MAXN][MAXN];

// 해당 코드가 진짜 신기한 부분인데 hashing 후의 값이 되돌아가게 해준다. 어떻게..?
int CalcMul(int num, int shift) {
    ul rev = 1;
    for (int i = 1; i < num; i++) {
        rev = (rev << shift) + rev;
    }
    return (int)(rev & DIV);
}

// 일반적인 hash 생성 함수
int GetHash(int* piv, int num, int shift) {
    ul hash = 0;
    for (int i = 0; i < num; i++) {
        hash = (hash << shift) + hash + *piv++;
    }
    return (int)(hash & DIV);
}

// 다음 hash값을 구하는 함수이다
/*
    예를들어 oxxox 가 있을 때
    w = 4 여서 먼저 oxxo에 대한 hash값을 구했다고 하자 -> 이 값이 prev
    prev 값과 적절한? 연산을 통해 xxo의 hash값을 구한뒤
    다음에 오는 x를 붙여서 xxox의 hash값을 구한다.
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

        // Get My Hash -> base값의 hash 값을 구하는 것이다
        for (int i = 0; i < H; i++) tmp[0][i] = GetHash(myPic[i], W, 5);
        int myHash = GetHash(tmp[0], H, 3); // 결론적으로 해당 값은 w*h 전체의 hash값이다

        // Get Sam Hash -> 비교하는 배열의 hash값 구한다
        // 이때 시간을 줄이는 방법이 매우 신기하다
        // 내 이전 코드들은 oxxo 다음에 xxox를 계속해서 해싱했기 때문에 여기서 O(w*w)인데
        // 이 코드는 oxxo 다음에 O(1)로 hash 값을 구하기 때문에 O(w)이다.
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