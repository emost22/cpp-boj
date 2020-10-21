#include <iostream>
using namespace std;

char st1[21], st2[21];

void func() {
	cout << "Distances:";
	for (int i = 0; st1[i]; i++) {
		if (st1[i] <= st2[i]) {
			cout << ' ' << st2[i] - st1[i];
		}
		else cout << ' ' << st2[i] - st1[i] + 26;
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> st1 >> st2;
		func();
	}

	return 0;
}