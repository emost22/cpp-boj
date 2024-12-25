#include <iostream>
#define MAX 100001
using namespace std;
typedef long long ll;

typedef struct Node {
	ll a;
	ll b;
	ll k;
}Node;

Node list[MAX];
int N;

void func() {
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		if (list[i].k < 10) ret += (list[i].a - list[i].b * list[i].k / 10LL);
		else ret += (list[i].a * list[i].k / 10LL - list[i].b);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].a;
	}

	for (int i = 0; i < N; i++) {
		cin >> list[i].b;
	}

	double x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		list[i].k = x * 10LL;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}