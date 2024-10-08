#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	sort(list + 1, list + N);

	ll f = list[0];
	for (int i = 1; i < N; i++) {
		if (f <= list[i]) {
			cout << "No\n";
			return;
		}
		f += list[i];
	}
	cout << "Yes\n";
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