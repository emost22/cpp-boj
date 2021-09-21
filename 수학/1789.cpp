#include <iostream>
using namespace std;
typedef long long ll;

ll N, ans;

void input() {
	ll sum = 0;
	int x = 1;
	int cnt = 0;
	cin >> N;
	while (1) {
		sum += x;
		cnt++;
		if (sum > N) {
			cout << cnt - 1 << '\n';
			return;
		}
		x++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}