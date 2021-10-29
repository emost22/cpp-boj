#include <iostream>
#include <string>
#include <algorithm>
#define MAX 300000
using namespace std;

string list;
int N, B, W;

void func() {
	int l = 0;
	int r = 0;
	int bCnt = 0;
	int wCnt = 0;
	int ans = 0;
	while (r < N) {
		if (list[r] == 'B') bCnt++;
		else wCnt++;

		if (bCnt > B) {
			while (bCnt > B) {
				if (list[l] == 'B') bCnt--;
				else wCnt--;

				l++;
			}
		}
		if (wCnt < W) {
			r++;
			continue;
		}

		ans = max(ans, r - l + 1);
		r++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> B >> W >> list;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}