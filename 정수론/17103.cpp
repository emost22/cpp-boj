#include <iostream>
#include <vector>
using namespace std;

vector<int> list;
bool sosu[1000001];
int cnt[1000001];
int N;

void func() {
	int ans = 0;
	for (int i = 0; i < list.size(); i++) {
		if (list[i] > N / 2) break;
		if (!sosu[list[i]] && !sosu[N - list[i]]) {
			ans++;
		}
	}
	cout << ans << '\n';
}

void init() {
	for (int i = 2; i <= 1000000; i++) {
		if (sosu[i]) continue;
		list.push_back(i);
		for (int j = 2; i * j <= 1000000; j++) {
			if (sosu[i*j]) continue;
			sosu[i * j] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> N;
		func();
	}

	return 0;
}