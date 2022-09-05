#include <iostream>
#include <algorithm>
using namespace std;

void input() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	cout << a + b + c + d - min({ a,b,c,d }) + max(e, f) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}