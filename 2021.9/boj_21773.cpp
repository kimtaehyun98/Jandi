#include <bits/stdc++.h>
using namespace std;

struct process {
	int id;
	int time;
	int priority;
};

struct cmp {
	bool operator() (process a, process b) {
		if (a.priority != b.priority) return a.priority < b.priority;
		else return a.id > b.id;
	}
};

int main() {
	int t, n, a, b, c;
	cin >> t >> n;
	priority_queue<process, vector<process>, cmp> pq;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		pq.push(process{ a,b,c + 1000000 });
	}
	while (t--) {
		if (pq.empty()) break;
		process temp = pq.top();
		pq.pop();
		cout << temp.id << "\n";
		temp.time--;
		temp.priority--;
		if(temp.time != 0) pq.push(temp);
	}
}