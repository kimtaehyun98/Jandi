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
int dy[] = { 0, 1, 1, 1, 0, -1 ,-1, -1 }; // �ð����
pii ari = { 0,0 }; int a = 4;
bool fire[20][20], arr[20][20];
vector<zombie>z;

void simul() {
	// �־��� ��� �̵�
	for (int i = 0; i < str.size(); i++) {
		char move = str[i];
		// F�� ������ 1ĭ ����, L�� �Ƹ��� ���� �ٶ󺸰� �ִ� ������ �������� �������� 90�� ���� ��ȯ, R�� ���������� 90�� ������ ��ȯ�Ѵ�.
		if (move == 'F') {
			int nx = ari.first + dx[a];
			int ny = ari.second + dy[a];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) ari = pii(nx, ny);
		}
		else if (move == 'L') a == 0 ? a = 6 : a -= 2;
		else a == 6 ? a = 0 : a += 2;
		// �� �Ӽ� ������ �ѱ�
		if (fire[ari.first][ari.second]) {
			arr[ari.first][ari.second] = true;
			for (int k = 0; k < 8; k++) {
				int nx = ari.first + dx[k];
				int ny = ari.second + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) arr[nx][ny] = true;
			}
		}
		// ari�� �̵����� �� ���� �̹� �� ĭ�� ���� ��� ���� 
		for (int k = 0; k < z.size(); k++) {
			if (z[k].x == ari.first && z[k].y == ari.second && arr[ari.first][ari.second] == false) {
				ans = "Aaaaaah!";
				return;
			}
		}
		// �л� ���� �̵�
		for (int k = 0; k < z.size(); k++) {
			int nx = z[k].x + dx[z[k].dir];
			int ny = z[k].y + dy[z[k].dir];
			// �л� ������� ��ĭ ����
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				z[k].x = nx; z[k].y = ny;
			}
			else { // ���� �ε����ٸ� ������ �ݴ�� ��ȯ 
				z[k].dir += z[k].dir <= 2 ? 4 : (-4);
			}
		}
		// ���� �̵� �� �Ƹ��� �����ϴ��� Ȯ�� 
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