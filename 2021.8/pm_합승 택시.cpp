#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX / 2;
int dis[202][202];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    // 가중치가 존재, 최대 노드 200개
    // 플로이드 와샬 알고리즘으로 모든 경로쌍의 최단 거리를 구하고
    // 모든 경우에 대해서 확인해보자.

    // 풀이
    // dis배열 초기화
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) i == j ? dis[i][j] = 0 : dis[i][j] = INF;
    // 간선 입력
    for (int i = 0; i < fares.size(); i++) {
        // 간선 정보 ( u <-> v , 가중치 = w) 
        int u = fares[i][0];
        int v = fares[i][1];
        int w = fares[i][2];
        dis[u][v] = w; dis[v][u] = w;
    }
    // 플로이드 와샬
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    // 브루트포스
    // 시작점 = s, 도착지 = a, b
    // (s -> 정점 x) + (정점 x -> a) + (정점 y -> b)  가 최소가 되는 정점 x 구하기
    for (int x = 1; x <= n; x++) {
        if (dis[s][x] == INF || dis[x][a] == INF || dis[x][b] == INF) continue;
        int temp = dis[s][x] + dis[x][a] + dis[x][b];
        answer = min(answer, temp);
    }

    return answer;
}