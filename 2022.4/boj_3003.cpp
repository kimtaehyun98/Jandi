#include <bits/stdc++.h>
using namespace std;

int cmp[] = {1, 1, 2, 2, 2, 8};

int main() {
	int arr[6];
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 6; i++) {
		cout << cmp[i] - arr[i] << " ";
	}
}