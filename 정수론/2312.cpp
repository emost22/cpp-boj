#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> prime;
bool isPrime[MAX];
int N;

void init() {
	isPrime[0] = isPrime[1] = true;
	for (int i = 2; i < MAX; i++) {
		if (isPrime[i]) continue;
		prime.push_back(i);
		for (int j = 2; i * j < MAX; j++) {
			isPrime[i * j] = true;
		}
	}
}

void func() {
	int x;
	int len = prime.size();
	while (N--) {
		cin >> x;
		for (auto p : prime) {
			int cnt = 0;
			while (!(x % p)) {
				cnt++;
				x /= p;
			}

			if (!cnt) continue;
			cout << p << ' ' << cnt << '\n';
		}
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}