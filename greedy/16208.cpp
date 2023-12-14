#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;
typedef long long ll;

ll list[MAX];
ll sum;
int N;

void func() {
	sort(list, list + N);

	ll tmp = sum;
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		tmp -= list[i];
		ret += (tmp * list[i]);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		sum += list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}