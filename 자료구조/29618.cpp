#include <iostream>
#include <set>
#include <vector>
#define MAX 100001
using namespace std;

set<int> s;
int ret[MAX];
int N, M;

void init() {
	for (int i = 1; i <= N; i++) {
		s.insert(i);
	}
}

void func() {
	init();

	int a, b, x;
	while (M--) {
		cin >> a >> b >> x;

		set<int>::iterator iter = s.lower_bound(a);
		vector<int> v;
		for (; iter != s.end() && *iter <= b; iter++) {
			ret[*iter] = x;
			v.push_back(*iter);
		}

		for (auto i : v) {
			s.erase(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ret[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}