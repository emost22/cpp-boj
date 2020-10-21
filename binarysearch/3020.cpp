#include <iostream>
#include <algorithm>
using namespace std;

int broken[500001], list1[100000], list2[100000], N, H, ans, min_broke;

int binarysearch(int s, int e, int height, int type) {
	if (s > e) {
		if (ans != -1) return N / 2 - ans;
		else return 0;
	}

	int m = (s + e) / 2;

	if (!type) {
		if (height <= list1[m]) {
			ans = m;
			return binarysearch(s, m - 1, height, type);
		}
		else {
			return binarysearch(m + 1, e, height, type);
		}
	}
	else {
		if (H - height < list2[m]) {
			ans = m;
			return binarysearch(s, m - 1, height, type);
		}
		else {
			return binarysearch(m + 1, e, height, type);
		}
	}
}

void chk() {
	int cnt = 0;

	for (int i = 1; i <= H; i++) {
		ans = -1;
		cnt = binarysearch(0, N / 2 - 1, i, 0);
		ans = -1;
		cnt += binarysearch(0, N / 2 - 1, i, 1);

		broken[i] = cnt;
	}
	sort(broken + 1, broken + 1 + H);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int cnt = 0;
	
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		if (!(i % 2)) cin >> list1[i / 2];
		else cin >> list2[i / 2];
	}

	sort(list1, list1 + N / 2);
	sort(list2, list2 + N / 2);

	chk();
	min_broke = broken[1];
	for (int i = 2; i <= H; i++) {
		if (min_broke != broken[i]) break;
		else cnt++;
	}

	cout << min_broke << ' ' << cnt + 1 << '\n';

	return 0;
}