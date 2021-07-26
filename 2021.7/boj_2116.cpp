#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	// 주사위의 모양은 모두 크기가 가튼 정육면체이며 1 ~ 6 써있음
	// 마주 보는 면에 적힌 숫자의 합이 7이 되진 않는다 (랜덤)
	// 쌓기 규칙 : 아래에 있는 주사위의 윗면에 적혀있는 숫자는
	// 위에 있는 주사위의 아랫면에 적혀있는 숫자와 같다
	// 1번 주사위는 마음대로 놓을 수 있다
	// 긴 사각기둥이 됨 -> 4개의 긴 옆면이 있음
	// 4개의 옆면 중에서 어느 한 면의 숫자의 합이 최대가 되도록 주사위를 쌓고자 함
	// 쌓여진 주사위를 회전 가능
	// 한 옆면의 숫자의 합의 최댓값을 구해라 

	int n, a, b, c, d, e, f;
	cin >> n;
	vector<pii>dice[10007];
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d >> e >> f;
		dice[i].push_back(pii(a, f));
		dice[i].push_back(pii(b, d));
		dice[i].push_back(pii(c, e));
	}
	// A-F, B-D, C-E 짝임 (즉 0-5, 1-3, 2-4 짝임)
	int Answer = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			int ans = 0;
			pii temp = dice[0][i];
			int bottom, top;
			bottom = temp.first, top = temp.second;
			int pp = 0;
			for (int t = 1; t <= 6; t++) if (t != bottom && t != top) pp = max(pp, t);
			ans += pp;
			if (j == 1) swap(bottom, top);
			for (int k = 1; k < n; k++) {
				for (int t = 0; t < 3; t++) {
					if (dice[k][t].first == top) {
						bottom = top; top = dice[k][t].second; break;
					}
					if (dice[k][t].second == top) {
						bottom = top; top = dice[k][t].first; break;
					}
				}
				if (bottom != 6 && top != 6) ans += 6;
				else {
					int p = 0;
					for (int t = 1; t <= 6; t++) if (t != bottom && t != top) p = max(p, t);
					ans += p;
				}
			}
			Answer = max(ans, Answer);
		}
	}
	cout << Answer << "\n";
}