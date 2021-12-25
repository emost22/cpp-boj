#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 3
using namespace std;

vector<int> ans;
int list[MAX];
int N;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void func() {
	int x = list[0];
	for (int i = 1; i < N; i++) {
		x = gcd(x, list[i]);
	}

	for (int i = 1; i * i <= x; i++) {
		if (!(x % i)) {
			ans.push_back(i);
			if (i != x / i) ans.push_back(x / i);
		}
	}
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}