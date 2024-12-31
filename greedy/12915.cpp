#include <iostream>
#include <algorithm>
using namespace std;

int e, em, m, mh, h;

void func() {
	int ret = min(e, min(m, h));
	e -= ret;
	m -= ret;
	h -= ret;

	while (1) {
		if (!e) {
			if (!em) break;
			e++;
			em--;
		}
		if (!m) {
			if (!em && !mh) break;
			if (em >= mh) em--;
			else mh--;
			m++;
		}
		if (!h) {
			if (!mh) break;
			h++;
			mh--;
		}
		e--;
		m--;
		h--;
		ret++;
	}

	cout << ret << '\n';
}

void input() {
	cin >> e >> em >> m >> mh >> h;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}