#include <iostream>
#include <set>
#include <cmath>
using namespace std;

set<int> s;
int N, M, cyclestart, ans;

void func(int num, int cnt) {
	s.insert(num);

	int n = num;
	int next = 0;
	while (1) {
		int tmp = n % 10;
		tmp = pow(tmp, M);
		next += tmp;
		n /= 10;
		if (!n) break;
	}

	if (s.find(next) != s.end()) {
		cyclestart = next;
		if (cyclestart == num) ans = cnt - 1;
		return;
	}

	func(next, cnt + 1);
	if (num == cyclestart)
		ans = cnt - 1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	func(N, 1);
	cout << ans << '\n';
	
	return 0;
}