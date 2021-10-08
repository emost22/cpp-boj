#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef pair<int, int> pi;

pi list[MAX];
int N;

void func() {
	int ans = 0;
	int s = 301;
	int e = 1130;

	int idx = -1;
	int tmp = 0;
	while (1) {
		bool flag = false;
		idx++;

		for (int i = 0; i < N; i++) {
			if (list[i].first > s) break;

			if (tmp < list[i].second) {
				tmp = list[i].second;
				idx = i;
				flag = true;
			}
		}

		if (flag) ans++;
		else {
			cout << "0\n";
			return;
		}

		s = tmp;
		if (s > e) break;
	}

	cout << ans << '\n';
}

void input() {
	int sm, sd, em, ed;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sm >> sd >> em >> ed;
		list[i] = { sm * 100 + sd, em * 100 + ed };
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}