#include <iostream>
#define MAX 6
using namespace std;

int list[MAX];

void input() {
	int ans = 0;
	for (int i = 0; i < MAX; i++) {
		cin >> list[i];
		ans += list[i];
	}
	
	cout << ans * 5 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}