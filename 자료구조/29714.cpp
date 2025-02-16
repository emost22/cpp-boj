#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m, tmp;
int N, Q;

bool isPossibleEat() {
	if (!N) return true;

	for (auto t : tmp) {
		if (m[t.first] < t.second) return false;
	}

	return true;
}

void renew() {
	for (auto t : tmp) {
		m[t.first] -= t.second;
		N -= t.second;
	}
}

void func() {
	int K, x;
	while (Q--) {
		tmp.clear();
		cin >> K;

		while (K--) {
			cin >> x;
			tmp[x]++;
		}

		bool flag = isPossibleEat();
		if (!N) tmp.clear();

		cin >> K;
		while (K--) {
			cin >> x;

			if (!flag) continue;
			tmp[x]--;
		}

		if (!flag) continue;
		renew();
	}

	cout << N << '\n';
	for (auto x : m) {
		int t = x.second;
		while (t--) {
			cout << x.first << ' ';
		}
	}
	cout << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		m[x]++;
	}
	cin >> Q;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}