#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int cnt, ans = 0, temp = 0;
vector<int>g[33];
int cost[33], blue[3], moving[10], arr[4];
bool check[33];

void init() {
	for (int i = 0; i <= 20; i++) {
		g[i].push_back(i + 1);
		cost[i] = i * 2;
	}
	cnt = 13;
	for (int i = 22; i <= 24; i++) {
		g[i].push_back(i != 24 ? i + 1 : 30);
		cost[i] = cnt; 
		cnt += 3;
	}
	cnt = 22;
	for (int i = 25; i <= 26; i++) {
		g[i].push_back(i != 26 ? i + 1 : 30);
		cost[i] = cnt;
		cnt += 2;
	}
	cnt = 28;
	for (int i = 27; i <= 30; i++) {
		if (i != 30) g[i].push_back(i + 1);
		cost[i] = cnt--;
	}
	cnt = 25;
	for (int i = 30; i <= 32; i++) {
		g[i].push_back(i != 32 ? i + 1 : 20);
		cost[i] = cnt;
		cnt += 5;
	}
	blue[0] = 22; // 5번 노드 -> 22번 노드 (파란색)
	blue[1] = 25; // 10번 노드 -> 25번 노드 (파란색)
	blue[2] = 27; // 15번 노드 -> 27번 노드 (파란색)
}

int simul(int x, int m) {
	int now = arr[x]; // x 번째 말의 현재 위치
	if (now == 5 || now == 10 || now == 15) { // 파란 칸이라면
		now = blue[(now / 5) - 1]; 
		m--;
	}
	for (int i = 0; i < m; i++) {
		if (now == 21) break; // 종료 칸이라면 중단
		now = g[now][0];
	}
	return now;
}

void backTracking(int cnt) {
	if (cnt == 10) {
		ans = max(ans, temp);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (arr[i] == 21) continue; // 도착칸이라면 선택 불가
		// 이번에 움직일 말 = i번째 말, moving[cnt] 만큼 이동 가능
		int next = simul(i, moving[cnt]);
		if (next == 21 || !check[next]) {
			// 말 이동
			int prev = arr[i]; // 이전 위치 저장
			check[arr[i]] = false;
			arr[i] = next;
			check[arr[i]] = true;
			temp += cost[arr[i]];
			backTracking(cnt + 1);
			// 말 복귀
			temp -= cost[arr[i]];
			check[arr[i]] = false;
			arr[i] = prev;
			check[arr[i]] = true;
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> moving[i];
	}
	init();
	backTracking(0);
	cout << ans << "\n";
}