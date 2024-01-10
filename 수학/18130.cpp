#include <iostream>
#define MAX 10001
using namespace std;
typedef long long ll;

typedef struct Node {
	ll p, k, c;
}Node;

Node list[MAX];
int N;
ll M;

void func() {
	int idx = 1;
	ll cnt = (M - 1) / list[1].k;
	ll minValue = list[1].p + cnt * (cnt + 1) * list[1].c / 2LL;
	for (int i = 2; i <= N; i++) {
		cnt = (M - 1) / list[i].k;
		ll sum = list[i].p + cnt * (cnt + 1) * list[i].c / 2LL;
		if (minValue > sum) {
			minValue = sum;
			idx = i;
		}
	}
	
	cout << idx << ' ' << minValue << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].p >> list[i].k >> list[i].c;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}