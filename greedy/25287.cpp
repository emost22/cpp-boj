#include <iostream>
#include <algorithm>
#define MAX 50001
using namespace std;

int list[MAX];
int N;

void func() {
	list[0] = min(list[0], N - list[0] + 1);
	for (int i = 1; i < N; i++) {
		int l = min(list[i], N - list[i] + 1);
		int r = max(list[i], N - list[i] + 1);

		if (list[i - 1] <= l) list[i] = l;
		else if (list[i - 1] <= r) list[i] = r;
		else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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
	
	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}
	
	return 0;
}