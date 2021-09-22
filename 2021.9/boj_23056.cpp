#include <bits/stdc++.h>
using namespace std;

int check[11];

struct student {
	bool color;
	int numb;
	string name;
};

bool cmp(student& a, student& b) {
	if (a.color != b.color) return a.color < b.color;
	else {
		if (a.numb != b.numb) return a.numb < b.numb;
		else {
			if (a.name.size() != b.name.size()) return a.name.size() < b.name.size();
			else return a.name < b.name;
		}
	}
}

int main() {
	int n, m, a;
	string str;
	cin >> n >> m;
	memset(check, 0, sizeof(check));
	vector<student>v;
	while (1) {
		cin >> a >> str;
		if (a == 0) break;
		if (check[a] < m) {
			check[a]++;
			bool flag = a % 2 == 1 ? false : true;
			student temp = { flag, a, str };
			v.push_back(temp);
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) cout << v[i].numb << " " << v[i].name << "\n";
}