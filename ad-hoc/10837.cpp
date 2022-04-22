#include <iostream>
#define MAX 100001
using namespace std;
typedef pair<int, int> pi;

pi list[MAX];
int N, K;

void func() {
	for (int i = 0; i < N; i++) {
		int ans = 0;
		if (list[i].first == list[i].second) {
			ans = 1;
		}
		else if (list[i].first > list[i].second) {
			if (list[i].second + (K - list[i].first + 2) >= list[i].first) {
				ans = 1;
			}
		}
		else {
			if (list[i].first + (K - list[i].second + 1) >= list[i].second) {
				ans = 1;
			}
		}

		cout << ans << '\n';
	}
}

void input() {
	cin >> K >> N;
	for (int i = 0; i < N; i++) {
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