#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 123457
using namespace std;
typedef long long ll;

typedef struct Room {
	int type;
	ll a;
	ll h;
}Room;

Room list[MAX];
int N;
ll A, l, r;

void func() {
	ll ans = 0;
	r = LLONG_MAX;
	while (l <= r) {
		ll m = (l + r) / 2;

		ll nowA = A;
		ll nowH = m;
		bool flag = true;
		for (int i = 0; i < N; i++) {
			if (list[i].type == 1) {
				if (list[i].h % nowA) {
					nowH -= (list[i].h / nowA * list[i].a);
				}
				else {
					nowH -= ((list[i].h / nowA - 1) * list[i].a);
				}
			}
			else {
				nowA += list[i].a;
				nowH = min(m, nowH + list[i].h);
			}

			if (nowH <= 0) {
				flag = false;
				break;
			}
		}

		if (flag) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	l = LLONG_MAX;
	cin >> N >> A;
	for (int i = 0; i < N; i++) {
		cin >> list[i].type >> list[i].a >> list[i].h;
		l = min(l, list[i].h);
		r = max(r, list[i].h);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}