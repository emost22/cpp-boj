#include <iostream>
#include <algorithm>
using namespace std;

const int km[] = { 0,1,3,5 };
int G, C, E;

void func() {
	cout << max(0, (E - C) * km[G]) << '\n';
}

void input() {
	cin >> G >> C >> E;
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