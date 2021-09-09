#include <iostream>
#define MAX 1000000
using namespace std;
typedef long long ll;

int list[MAX + 1], sorted[MAX + 1];
int N;
ll ans;

void mergeSort(int l, int m, int r) {
	int i = l;
	int j = m + 1;
	int k = l;
	while (i <= m && j <= r) {
		if (list[i] < list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			ans += (ll)(j - k);
			sorted[k++] = list[j++];
		}
	}

	if (i > m) {
		while (j <= r) {
			sorted[k++] = list[j++];
		}
	}
	else {
		while (i <= m) {
			sorted[k++] = list[i++];
		}
	}

	for (int t = l; t <= r; t++) {
		list[t] = sorted[t];
	}
}

void merge(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		merge(l, m);
		merge(m + 1, r);
		mergeSort(l, m, r);
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	merge(1, N);
	cout << ans << '\n';

	return 0;
}