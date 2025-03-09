#include <iostream>
#define MAX 1001
#define GRADE 5
using namespace std;

int list[MAX][MAX];
int cnt[MAX];
int N;

void func() {
	int ret = 1;
	int value = 0;
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = 0; k < GRADE; k++) {
				if (list[i][k] == list[j][k]) {
					cnt[i]++;
					cnt[j]++;
					if (value < cnt[i]) {
						value = cnt[i];
						ret = i;
					}

					if (value < cnt[j] || (value == cnt[j] && ret > j)) {
						value = cnt[j];
						ret = j;
					}
					break;
				}
			}
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < GRADE; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}