#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

vector<int> v;
int list[MAX];
int N;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v.push_back(list[i] + list[j]);
		}
	}
	sort(v.begin(), v.end());

	int vsize = v.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int dc = list[i] - list[j];
			if (dc <= 0) continue;

			int l = 0;
			int r = vsize - 1;
			bool flag = false;
			while (l <= r) {
				int m = (l + r) / 2;

				if (v[m] == dc) {
					cout << list[i] << '\n';
					return;
				}
				else if (v[m] > dc) {
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N, [](int a, int b) {
		return a > b;
	});
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}