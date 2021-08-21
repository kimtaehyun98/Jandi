#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX / 2;
int dis[202][202];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    // ����ġ�� ����, �ִ� ��� 200��
    // �÷��̵� �ͼ� �˰������� ��� ��ν��� �ִ� �Ÿ��� ���ϰ�
    // ��� ��쿡 ���ؼ� Ȯ���غ���.

    // Ǯ��
    // dis�迭 �ʱ�ȭ
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) i == j ? dis[i][j] = 0 : dis[i][j] = INF;
    // ���� �Է�
    for (int i = 0; i < fares.size(); i++) {
        // ���� ���� ( u <-> v , ����ġ = w) 
        int u = fares[i][0];
        int v = fares[i][1];
        int w = fares[i][2];
        dis[u][v] = w; dis[v][u] = w;
    }
    // �÷��̵� �ͼ�
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    // ���Ʈ����
    // ������ = s, ������ = a, b
    // (s -> ���� x) + (���� x -> a) + (���� y -> b)  �� �ּҰ� �Ǵ� ���� x ���ϱ�
    for (int x = 1; x <= n; x++) {
        if (dis[s][x] == INF || dis[x][a] == INF || dis[x][b] == INF) continue;
        int temp = dis[s][x] + dis[x][a] + dis[x][b];
        answer = min(answer, temp);
    }

    return answer;
}