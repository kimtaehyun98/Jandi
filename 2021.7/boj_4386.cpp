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
	// �� = ���, ���� ������ �Ÿ� = ����ġ�� �׷��� �𵨸�
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
	// prim �˰����� ���� ���غ���
	// 1. 1�� ������ ���д� Ʈ���� ��Ʈ��� ����
	int start = 0;
	// 2. �켱���� ť�� ���� Ʈ���� ����� ���� �� ����ġ�� ���� ���� ������ ã�Ƽ� Ʈ���� �����Ѵ�
	priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int ver = pq.top().second;
		double edge = pq.top().first;
		pq.pop();
		// �̹� �湮�� �����̶�� �ǳʶڴ�.
		if (check[ver]) continue;
		// �湮���� ���� �����̶�� �ش� ������ ����� ��� ������ pq�� (����, ����) ���� �־��ش�
		check[ver] = true;
		// pq�� ���� �������� ��� ���� ������� Ʈ������ �湮�� �� �ִ� �������̴�.
		for (int i = 0; i < v[ver].size(); i++) {
			pid nx = v[ver][i];
			if (check[nx.first] == false) pq.push(pdi(nx.second, nx.first));
		}
		sum += edge; // MST�� ��� �������� ��
	}
	printf("%.2lf\n", sum);
}