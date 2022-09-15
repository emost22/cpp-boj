#include <iostream>
#include <algorithm>
using namespace std;

int s, e, fp, f, nfp;

void func() {
	int ans = 0;
	if (s < 0) ans += ((-s) * fp + f);
	ans += ((e - max(0, s)) * nfp);

	cout << ans << '\n';
}

void input() {
	cin >> s >> e >> fp >> f >> nfp;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}