#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int a, b;
	double cnt = 0;
	scanf("%d %d", &a, &b);
	vector<int>v;
	for (int i = 1; i <= 10; i++) {
		if (i != a) v.push_back(i);
		if (i != b)v.push_back(i);
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] == v[j]) { 
				if (a == b) { 
					if (a > v[i]) cnt++;
				}
				else continue;

			}
			else {
				int now = v[i] + v[j];
				if (a == b) cnt++;
				else {
					if ((a + b) % 10 > now % 10) cnt++;
				}
			}
		}
	}
	printf("%.3lf\n", cnt/153);
}