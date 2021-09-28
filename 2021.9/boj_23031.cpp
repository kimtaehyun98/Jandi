#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct zombie {
	int x;
	int y;
	int dir;
};

int n; string str, temp, ans = "Phew...";
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1 ,-1, -1 }; // 시계방향
pii ari = { 0,0 }; int a = 4;
bool fire[20][20], arr[20][20];
vector<zombie>z;

void simul() {
	// 주어진 대로 이동
	for (int i = 0; i < str.size(); i++) {
		char move = str[i];
		// F는 앞으로 1칸 전진, L은 아리가 현재 바라보고 있는 방향을 기준으로 왼쪽으로 90도 방향 전환, R은 오른쪽으로 90도 방향을 전환한다.
		if (move == 'F') {
			int nx = ari.first + dx[a];
			int ny = ari.second + dy[a];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) ari = pii(nx, ny);
		}
		else if (move == 'L') a == 0 ? a = 6 : a -= 2;
		else a == 6 ? a = 0 : a += 2;
		// 불 켤수 있으면 켜기
		if (fire[ari.first][ari.second]) {
			arr[ari.first][ari.second] = true;
			for (int k = 0; k < 8; k++) {
				int nx = ari.first + dx[k];
				int ny = ari.second + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) arr[nx][ny] = true;
			}
		}
		// ari가 이동했을 때 좀비가 이미 그 칸에 있을 경우 기절 
		for (int k = 0; k < z.size(); k++) {
			if (z[k].x == ari.first && z[k].y == ari.second && arr[ari.first][ari.second] == false) {
				ans = "Aaaaaah!";
				return;
			}
		}
		// 학생 좀비 이동
		for (int k = 0; k < z.size(); k++) {
			int nx = z[k].x + dx[z[k].dir];
			int ny = z[k].y + dy[z[k].dir];
			// 학생 좀비들은 한칸 전진
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				z[k].x = nx; z[k].y = ny;
			}
			else { // 벽에 부딪힌다면 방향을 반대로 전환 
				z[k].dir += z[k].dir <= 2 ? 4 : (-4);
			}
		}
		// 좀비 이동 후 아리가 기절하는지 확인 
		for (int k = 0; k < z.size(); k++) {
			if (z[k].x == ari.first && z[k].y == ari.second && arr[ari.first][ari.second] == false) {
				ans = "Aaaaaah!";
				return;
			}
		}
	}
}

int main() {
	cin >> n >> str;
	memset(fire, false, sizeof(fire));
	memset(arr, false, sizeof(arr));
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int k = 0; k < n; k++) {
			if (temp[k] == 'Z') z.push_back(zombie{ i, k, 4 });
			else if (temp[k] == 'S') fire[i][k] = true;
		}
	}
	simul();
	cout << ans << "\n";
}