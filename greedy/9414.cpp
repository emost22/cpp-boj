#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 41
#define LIM 5000000
using namespace std;

vector<int> v;
int N;

void func() {
	sort(v.begin(), v.end(), [](int a, int b) {
		return a > b;
	});

	int ret = 0;
	for (int i = 0; i < N; i++) {
		int tmp = 2;
		for (int j = 0; j <= i; j++) {
			tmp *= v[i];
		}
		ret += tmp;
		if (ret > LIM) {
			cout << "Too expensive\n";
			return;
		}
	}

	cout << ret << '\n';
}

void input() {
	int x;
	while (1) {
		cin >> x;
		if (!x) break;
		v.push_back(x);
	}
	N = v.size();
}

void init() {
	v.clear();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		init();
	}

	return 0;
}