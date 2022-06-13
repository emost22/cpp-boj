#include <iostream>
#define MAX 41
using namespace std;

int dp1[MAX], dp2[MAX];
int N;

void init() {
	dp1[1] = 1;
	dp1[2] = 1;
	for (int i = 3; i < MAX; i++) {
		dp1[i] = dp1[i - 1] + dp1[i - 2];
	}

	dp2[1] = 0;
	for (int i = 2; i < MAX; i++) {
		dp2[i] = i - 2;
	}
}

void input() {
	cin >> N;
	cout << dp1[N] << ' ' << dp2[N] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}