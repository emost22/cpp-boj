#include <iostream>
#define MAX 11
using namespace std;

int v[MAX];
int N;

void func() {
	int ret = 1;
	int cnt = 1;
	int sum = v[1];
	for (int i = 2; i <= N; i++) {
		sum += v[i];
		if (v[ret] > v[i]) continue;

		if (v[ret] == v[i]) cnt++;
		else {
			ret = i;
			cnt = 1;
		}
	}

	if (cnt == 1) {
		if ((v[ret] << 1) > sum) cout << "majority winner " << ret << '\n';
		else cout << "minority winner " << ret << '\n';
	}
	else cout << "no winner\n";
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
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