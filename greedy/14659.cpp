#include <iostream>
#include <algorithm>
#define MAX 30000
using namespace std;

int list[MAX];
int N, ans;

void func() {
	int maxHeight = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (maxHeight < list[i]) {
			maxHeight = list[i];
			ans = max(ans, cnt);
			cnt = 0;
		}
		else cnt++;
	}
	
	cout << max(ans, cnt) << '\n';
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