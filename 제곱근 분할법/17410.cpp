#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAXN 100001
#define MAXB 320
using namespace std;

vector<int> v[MAXB];
int list[MAXN];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, sqrtN;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	sqrtN = 1000;
	for (int i = 0; i < N; i++) {
		v[i / sqrtN].push_back(list[i]);
	}
	for (int i = 0; i < MAXB; i++) {
		sort(v[i].begin(), v[i].end());
	}

	int type, a, b, c;
	cin >> M;
	while (M--) {
		cin >> type;
		if (type == 2) {
			cin >> a >> b >> c;
			a--;
			b--;

			int ans = 0;
			while (a % sqrtN && a <= b) {
				if (list[a] > c) ans++;
				a++;
			}
			while ((b + 1) % sqrtN && a <= b) {
				if (list[b] > c) ans++;
				b--;
			}
			while (a <= b) {
				ans += (v[a / sqrtN].end() - upper_bound(v[a / sqrtN].begin(), v[a / sqrtN].end(), c));
				a += sqrtN;
			}

			cout << ans << '\n';
		}
		else {
			cin >> a >> b;
			a--;
			v[a / sqrtN].erase(lower_bound(v[a / sqrtN].begin(), v[a / sqrtN].end(), list[a]));
			v[a / sqrtN].insert(lower_bound(v[a / sqrtN].begin(), v[a / sqrtN].end(), b), b);
			list[a] = b;
		}
	}

	return 0;
}