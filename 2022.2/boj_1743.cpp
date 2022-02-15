#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int arr[101][101];
int ans = 0, n, m, k, r, c;
bool check[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1, -1, 0, 0 };

int bfs(int x, int y) {
    int ret = 1;
    queue<pii>q;
    q.push(pii(x, y));
    check[x][y] = true;
    while (!q.empty()) {
        pii temp = q.front();
        q.pop();
        x = temp.first; y = temp.second;
        for (int s = 0; s < 4; s++) {
            int nx = x + dx[s];
            int ny = y + dy[s];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (arr[nx][ny] == 1 && check[nx][ny] == false) {
                    check[nx][ny] = true;
                    q.push(pii(nx, ny));
                    ret += 1;
                }
            }
        }
    }
    return ret;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        arr[r - 1][c - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && check[i][j] == false) {
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans << "\n";
}