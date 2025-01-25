#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;
typedef pair<int, int> pii;

pii a[MAX];
int b[MAX];
int N;

void func() {
	sort(a, a + N);
	sort(b, b + N);

	for (int i = 0; i < N; i++) {
		if (a[i].first > b[i]) {
			cout << "-1\n";
			return;
		}
		a[i].first = b[i];
	}

	sort(a, a + N, [](pii x, pii y) {
		return x.second < y.second;
	});

	for (int i = 0; i < N; i++) {
		cout << a[i].first << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}