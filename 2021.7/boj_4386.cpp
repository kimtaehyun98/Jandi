#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996)
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;

int n;
double x, y, sum = 0;
vector<pid>v[107];
bool check[107];

int main() {
	scanf("%d", &n);
;	vector<pdd>star(n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &x, &y);
		star[i] = pdd(x, y);
	}
	// 별 = 노드, 별들 사이의 거리 = 가중치로 그래프 모델링
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			x = star[i].first - star[j].first; x *= x;
			y = star[i].second - star[j].second; y *= y;
			double dis = sqrt(x + y);
			v[i].push_back(pid(j, dis));
			v[j].push_back(pid(i, dis));
		}
	}
	memset(check, false, sizeof(check));
	// prim 알고리즘을 통해 구해보자
	// 1. 1번 정점을 스패닝 트리의 루트라고 가정
	int start = 0;
	// 2. 우선순위 큐를 통해 트리와 연결된 간선 중 가중치가 가장 작은 간선을 찾아서 트리로 연결한다
	priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int ver = pq.top().second;
		double edge = pq.top().first;
		pq.pop();
		// 이미 방문한 정점이라면 건너뛴다.
		if (check[ver]) continue;
		// 방문하지 않은 정점이라면 해당 정점과 연결된 모든 정점을 pq에 (간선, 정점) 으로 넣어준다
		check[ver] = true;
		// pq에 들어가는 정점들은 모두 현재 만들어진 트리에서 방문할 수 있는 정점들이다.
		for (int i = 0; i < v[ver].size(); i++) {
			pid nx = v[ver][i];
			if (check[nx.first] == false) pq.push(pdi(nx.second, nx.first));
		}
		sum += edge; // MST의 모든 간선들의 합
	}
	printf("%.2lf\n", sum);
}