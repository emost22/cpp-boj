#include <iostream>
using namespace std;

int N, M;

void func() {
	if (M == 1 || M == 2) cout << "NEWBIE!\n";
	else if (M <= N) cout << "OLDBIE!";
	else cout << "TLE!\n";
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}