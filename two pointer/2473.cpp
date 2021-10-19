#include <iostream>
#include <algorithm>
#define MAX 5000
using namespace std;
typedef long long ll;

ll list[MAX], ansList[3];
int N;

void func() {
	ll ans = 3e9;
	for (int i = 0; i < N - 2; i++) {
		int l = i + 1;
		int r = N - 1;
		while (l < r) {
			ll sum = list[i] + list[l] + list[r];
			if (abs(sum) < abs(ans)) {
				ans = sum;
				ansList[0] = list[i];
				ansList[1] = list[l];
				ansList[2] = list[r];
			}

			if (sum >= 0) r--;
			else l++;
		}
	}
	sort(ansList, ansList + 3);
	cout << ansList[0] << ' ' << ansList[1] << ' ' << ansList[2] << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}