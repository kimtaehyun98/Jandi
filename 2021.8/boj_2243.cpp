#include <bits/stdc++.h>
using namespace std;

const int ts = 1000000;
int n, a, b, c;
int tree[4000007];

void update(int node, int start, int end, int index, int diff) {
	if (index < start || end < index) return;
	tree[node] += diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int sum(int node, int start, int end, int left, int right) {
	if (left > end || start > right) return 0;
	if (left <= start && end <= right) return tree[node];
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a;
		if (a == 1) { // »çÅÁÀ» ²¨³»´Â °æ¿ì (b = ²¨³¾ »çÅÁÀÇ ¼øÀ§)
			cin >> b;
			int l = 1, r = ts, ans = INT_MAX;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (sum(1, 1, ts, 1, mid) >= b) {
					ans = min(ans, mid);
					r = mid - 1;
				}
				else l = mid + 1;
			}
			cout << ans << "\n";
			update(1, 1, ts, ans, -1); 
		}
		else { // »çÅÁÀ» ³Ö´Â °æ¿ì (b = ³ÖÀ» »çÅÁÀÇ ¸À, c = »çÅÁÀÇ °³¼ö)
			// c > 0 : »çÅÁÀ» ³ÖÀº °æ¿ì, c < 0 : »çÅÁÀ» »©´Â °æ¿ì
			cin >> b >> c;
			update(1, 1, ts, b, c);
		}
	}
}