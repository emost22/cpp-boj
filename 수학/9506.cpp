#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

void func() {
	vector<int> v;
	int sum = 0;
	for (int i = 1; i * i <= N; i++) {
		if (!(N % i)) {
			v.push_back(i);
			sum += i;
			if (i > 1 && i != N / i) {
				v.push_back(N / i);
				sum += (N / i);
			}
		}
	}

	if (sum != N) {
		cout << N << " is NOT perfect.\n";
		return;
	}

	sort(v.begin(), v.end());
	cout << N << " = 1";
	for (int i = 1; i < v.size(); i++) {
		cout << " + " << v[i];
	}
	cout << '\n';
}

void input() {
	cin >> N;
	if (N == -1) exit(0);
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