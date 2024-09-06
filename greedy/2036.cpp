#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	sort(list, list + N);
	int l = 0;
	ll ret = 0;
	while (l < N) {
		if (!list[l]) l++;
		else if (list[l] > 0) break;
		else {
			if (l + 1 < N) {
				if (list[l + 1] > 0) {
					ret += list[l];
					l++;
					break;
				}
				else if (!list[l + 1]) {
					l += 2;
				}
				else {
					ret += (list[l] * list[l + 1]);
					l += 2;
				}
			}
			else {
				ret += list[l];
				l++;
			}
		}
	}

	while (l < N && list[l] == 1) {
		ret += list[l++];
	}

	int r = N - 1;
	if ((r - l + 1) & 1) {
		ret += list[l++];
	}

	while (l <= r) {
		ret += (list[r] * list[r - 1]);
		r -= 2;
	}

	cout << ret << '\n';
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