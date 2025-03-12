#include <iostream>
#define MAX 81
using namespace std;

int s1, s2, s3;

void func() {
	int* cnt = new int[MAX] {};
	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				cnt[i + j + k]++;
			}
		}
	}

	int ret = 0;
	int value = 0;
	for (int i = 3; i <= s1 + s2 + s3; i++) {
		if (value < cnt[i]) {
			value = cnt[i];
			ret = i;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> s1 >> s2 >> s3;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}