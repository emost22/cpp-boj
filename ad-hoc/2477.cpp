#include <iostream>
#include <algorithm>
#define MAX 4
using namespace std;
typedef pair<int, int> pi;

pi list[6];
int cnt;

void func() {
	int ans = 0;
	int idx = 0;
	for (int i = 0; i < 6; i++) {
		int ret = list[i].second * list[(i + 1) % 6].second;
		if (ans < ret) {
			ans = ret;
			idx = i;
		}
	}

	cout << (ans - list[(idx + 3) % 6].second*list[(idx + 4) % 6].second) * cnt << '\n';
}

void input() {
	cin >> cnt;
	for (int i = 0; i < 6; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}