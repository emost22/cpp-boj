#include <iostream>
#include <algorithm>
#define MAX 111222
using namespace std;
typedef long long ll;

typedef struct Node {
	ll x;
	char c;
}Node;

Node list[MAX];
int Q;

void func() {
	ll l = -1e18;
	ll r = 1e18;
	int ret = 0;
	for (int i = 0; i < Q; i++) {
		if (list[i].c == 'v') r = min(r, list[i].x - 1LL);
		else l = max(l, list[i].x + 1LL);

		if (l > r) {
			cout << "Paradox!\n" << i + 1 << '\n';
			return;
		}

		if (l == r) {
			if (ret) continue;
			ret = i + 1;
		}
	}

	if (ret) cout << "I got it!\n" << ret << '\n';
	else cout << "Hmm...\n";
}

void input() {
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> list[i].x >> list[i].c;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}