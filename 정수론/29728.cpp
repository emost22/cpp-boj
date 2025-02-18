#include <iostream>
#define MAX 5000001
using namespace std;

bool prime[MAX];
int N;

void checkPrime() {
	prime[1] = true;
	for (int i = 2; i * i <= N; i++) {
		if (prime[i]) continue;
		for (int j = 2; i * j <= N; j++) {
			prime[i * j] = true;
		}
	}
}

void func() {
	checkPrime();

	bool flag = false;
	int b = 0;
	int s = 0;
	for (int i = 1; i <= N; i++) {
		if (prime[i]) {
			b++;
			flag = true;
		}
		else {
			if (flag) {
				b--;
				s += 2;
			}
			else s++;
			flag = false;
		}
	}

	cout << b << ' ' << s << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}