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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int dc = list[i] - list[j];
			if (dc <= 0) continue;

			int cnt = upper_bound(v.begin(), v.end(), dc) - lower_bound(v.begin(), v.end(), dc);
			if (cnt) {
				cout << list[i] << '\n';
				return;
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