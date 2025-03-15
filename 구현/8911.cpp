#include <iostream>
#include <string>
using namespace std;

int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
string str;

void func() {
	int x = 0;
	int y = 0;
	int mnx = 0;
	int mny = 0;
	int mxx = 0;
	int mxy = 0;
	int d = 0;
	for (auto s : str) {
		if (s == 'F') {
			x += direct[d][0];
			y += direct[d][1];
		}
		else if (s == 'B') {
			x -= direct[d][0];
			y -= direct[d][1];
		}
		else if (s == 'L') {
			d = (d + 3) % 4;
		}
		else {
			d = (d + 1) % 4;
		}

		mnx = min(mnx, x);
		mny = min(mny, y);
		mxx = max(mxx, x);
		mxy = max(mxy, y);
	}

	cout << (mxx - mnx) * (mxy - mny) << '\n';
}

void input() {
	cin >> str;
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