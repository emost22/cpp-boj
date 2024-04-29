#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	if (!(N % 5LL) || N % 5LL == 2) cout << "CY\n";
	else cout << "SK\n";
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}