#include <iostream>
#define MAX 101
using namespace std;

int cnt[MAX * 2];
int N;

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		cnt[x + 100]++;
	}
	cin >> x;
	cout << cnt[x + 100] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}