#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, P;

void func() {
	vector<int> v;
	if (P % 2) v.push_back(P + 1);
	else v.push_back(P - 1);

	int tmp = N + 1 - P;
	v.push_back(tmp);
	if (tmp % 2) v.push_back(tmp + 1);
	else v.push_back(tmp - 1);

	sort(v.begin(), v.end());
	for (int i = 0; i < 3; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	if (!N) exit(0);
	cin >> P;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}