#include <iostream>
#define MAX 1000001
using namespace std;

int list[MAX + 1];
int N;

void input() {
	int x;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		list[x]++;
		if (!list[x + 1]) {
			ans++;
		}
		else {
			list[x + 1]--;
		}
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}