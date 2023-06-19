#include <iostream>
#include <cmath>
#define MAX 1000
using namespace std;

int list[MAX];
int N, avg;

void func() {
	cout << fixed;
	cout.precision(3);

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (avg < list[i]) cnt++;
	}

	double ret = round((double)(cnt * 100000.0) / (double)(N)) / 1000;

	cout << ret << "%\n";
}

void input() {
	avg = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		avg += list[i];
	}

	avg /= N;
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