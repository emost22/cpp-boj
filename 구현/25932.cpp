#include <iostream>
#include <string>
#define MAX 10
using namespace std;

string ans[] = { "none", "zack", "mack", "both" };
int list[MAX];

void func() {
	int cnt = 0;
	for (int i = 0; i < MAX; i++) {
		cin >> list[i];
		cout << list[i] << ' ';
		if (list[i] == 17) cnt |= 1;
		else if (list[i] == 18) cnt |= 2;
	}
	cout << '\n' << ans[cnt] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		func();
		if (tc) cout << '\n';
	}

	return 0;
}