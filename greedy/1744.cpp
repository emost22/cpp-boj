#include <iostream>
#include <algorithm>
using namespace std;

long long int sum;
int list[10000], check[10000];

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
	
	for (int i = 0; i + 1 < N && list[i] < 1 && list[i + 1] < 1; i += 2) {
		sum += list[i] * list[i + 1];
		check[i] = 1, check[i + 1] = 1;
		if (list[i + 2] < 1 && i + 2 == N - 1) {
			sum += list[i + 2];
			check[i + 2] = 1;
		}
	}
	for (int i = N - 1; i - 1 >= 0 && list[i] >= 1; i -= 2) {
		if (list[i - 1] > 1) {
			sum += list[i] * list[i - 1];
			check[i] = 1;
			check[i - 1] = 1;
		}
		else if (list[i - 1] == 1) {
			sum += list[i] + list[i - 1];
			check[i] = 1;
			check[i - 1] = 1;
		}
		else {
			sum += list[i];
			check[i] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) sum += list[i];
	}

	cout << sum << '\n';

	return 0;
}