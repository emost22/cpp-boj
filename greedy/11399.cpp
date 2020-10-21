#include <iostream>
#include <algorithm>
using namespace std;

int list[1000], ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);

	for (int i = 0; i < N; i++) {
		ans += (N - i) * list[i];
	}

	cout << ans << '\n';

	return 0;
}