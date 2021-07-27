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
	// prim 알고리즘을 통해 구해보자
	// 1. 1번 정점을 스패닝 트리의 루트라고 가정
	int start = 1;
	// 2. 우선순위 큐를 통해 트리와 연결된 간선 중 가중치가 가장 작은 간선을 찾아서 트리로 연결한다
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int ver = pq.top().second;
		int edge = pq.top().first;
		pq.pop();
		// 이미 방문한 정점이라면 건너뛴다.
		if (check[ver]) continue;
		// 방문하지 않은 정점이라면 해당 정점과 연결된 모든 정점을 pq에 (간선, 정점) 으로 넣어준다
		check[ver] = true;
		// pq에 들어가는 정점들은 모두 현재 만들어진 트리에서 방문할 수 있는 정점들이다.
		for (int i = 0; i < v[ver].size(); i++) {
			pair <int, int> nx = v[ver][i];
			if (check[nx.first] == false) pq.push(make_pair(nx.second, nx.first));
		}
		sum += edge; // MST의 모든 간선들의 합
		e = max(e, edge); // MST중 가중치가 가장 큰 간선
	}
	cout << sum - e << "\n";
}