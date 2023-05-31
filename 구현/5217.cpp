#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int N;

void func() {
	vector<pii> v;
	for (int i = 1; i < (N + 1) / 2; i++) {
		v.push_back({ i, N - i });
	}

	cout << "Pairs for " << N << ":";
	for (int i = 0; i < v.size(); i++) {
		if (i) cout << ',';
		cout << ' ' << v[i].first << ' ' << v[i].second;
	}
	cout << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}