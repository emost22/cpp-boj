#include <iostream>
#define MAX 200001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;
ll avg;

void func() {
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] == avg) continue;
		if (list[i] > avg) {
			ret += (list[i] - avg);
			list[i + 1] += (list[i] - avg);
			list[i] = avg;
		}
		else {
			ret += (avg - list[i]);
			list[i + 1] -= (avg - list[i]);
			list[i] = avg;
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		avg += list[i];
	}
	avg /= (ll)N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}