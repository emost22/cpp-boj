#include <iostream>
#define MAX 5
using namespace std;

int list[MAX];
int N;

void input() {
	int ans = 0;
	cin >> N;
	for (int i = 0; i < MAX; i++) {
		cin >> list[i];
		if (N == list[i]) ans++;
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}