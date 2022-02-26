#include <bits/stdc++.h>
using namespace std;
pair<int, string> pis;

struct love{
	int score;
	string name;
};

bool cmp(love a, love b) {
	if (a.score != b.score) return a.score > b.score;
	else return a.name < b.name;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string yd, str; int t, a = 0, b = 0, c = 0, d = 0;
	cin >> yd;
	for (int i = 0; i < yd.size(); i++) {
		if (yd[i] == 'L') a++;
		if (yd[i] == 'O') b++;
		if (yd[i] == 'V') c++;
		if (yd[i] == 'E') d++;
	}
	vector<love>v;
	cin >> t;
	while (t--) {
		cin >> str;
		int L = a, O = b, V = c, E = d;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'L') L++;
			if (str[i] == 'O') O++;
			if (str[i] == 'V') V++;
			if (str[i] == 'E') E++;
		}
		int temp = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
		v.push_back({ temp, str });
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].name << "\n";
}