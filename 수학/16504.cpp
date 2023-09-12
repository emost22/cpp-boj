#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void input() {
	int N;
	ll x;
	ll ret = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			ret += x;
		}
	}

	cout << ret << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}