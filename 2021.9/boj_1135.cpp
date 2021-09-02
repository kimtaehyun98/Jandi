#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<int>tree[55];

int solve(int node) {
	// ���������
	if (tree[node].empty()) {
		return 1;
	}
	// ������尡 �ƴ϶��
	// �ڽ� ����� cost �迭���� �� index�� + ���ְ� �� �� max ���� �ɸ��� �ð��� = �� �ش� ����� cost
	// �ش� ����� cost ���� ���Ϸ��� �ڽ� ������ ���� ���� ������ �־�� �Ѵ�.
	vector<int>child;
	for (int i = 0; i < tree[node].size(); i++) {
		child.push_back(solve(tree[node][i]) + 1); // �ش� ��嵵 ���� Ƚ���� �߰��Ǿ�� ��, �� + 1
	}
	sort(child.begin(), child.end(), greater<int>());
	int ret = 0;
	for (int i = 0; i < child.size(); i++) {
		ret = max(ret, child[i] + i);
	}
	return ret;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i == 0) continue; 
		tree[v[i]].push_back(i); // �ڽ� ������ ������ ����
	}
	// -1 �ϴ� ������ root ���� ����
	cout << solve(0) - 1 << "\n";
}