#include <iostream>
#include <algorithm>
#define MAX 600
using namespace std;

int list[MAX];
int N;

void func() {
	int ans = 2e9;
	for (int i = 0; i < N - 3; i++) {
		for (int j = i + 3; j < N; j++) {
			int l = i + 1;
			int r = j - 1;
			int firstSum = list[i] + list[j];
			while (l < r) {
				int secondSum = list[l] + list[r];
				ans = min(ans, abs(firstSum - secondSum));
				
				if (firstSum < secondSum) r--;
				else l++;
			}
		}
	}

	cout << ans << '\n';
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