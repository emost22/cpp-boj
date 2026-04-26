#include <iostream>
#include <algorithm>
#define MAX 300000
using namespace std;
typedef long long ll;

typedef struct Node {
	ll a, b, c, p;
}Node;

Node list[MAX];
int N;

void func() {
	ll a = 0;
	ll b = 0;
	ll c = 0;
	for (ll i = 0; i < N; i++) {
		a = max(a, list[i].a);
		b = max(b, list[i].b);
		c = max(c, list[i].c);

		if (a + b + c + i >= list[i].p) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].a >> list[i].b >> list[i].c >> list[i].p;
	}
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