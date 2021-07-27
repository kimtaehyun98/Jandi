#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, a, b, c, sum = 0, e = 0;
vector<pii>v[100007];
bool check[100007];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back(pii(b, c));
		v[b].push_back(pii(a, c));
	}
	memset(check, false, sizeof(check));
	// prim �˰����� ���� ���غ���
	// 1. 1�� ������ ���д� Ʈ���� ��Ʈ��� ����
	int start = 1;
	// 2. �켱���� ť�� ���� Ʈ���� ����� ���� �� ����ġ�� ���� ���� ������ ã�Ƽ� Ʈ���� �����Ѵ�
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int ver = pq.top().second;
		int edge = pq.top().first;
		pq.pop();
		// �̹� �湮�� �����̶�� �ǳʶڴ�.
		if (check[ver]) continue;
		// �湮���� ���� �����̶�� �ش� ������ ����� ��� ������ pq�� (����, ����) ���� �־��ش�
		check[ver] = true;
		// pq�� ���� �������� ��� ���� ������� Ʈ������ �湮�� �� �ִ� �������̴�.
		for (int i = 0; i < v[ver].size(); i++) {
			pair <int, int> nx = v[ver][i];
			if (check[nx.first] == false) pq.push(make_pair(nx.second, nx.first));
		}
		sum += edge; // MST�� ��� �������� ��
		e = max(e, edge); // MST�� ����ġ�� ���� ū ����
	}
	cout << sum - e << "\n";
}