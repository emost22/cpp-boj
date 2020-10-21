#include <iostream>
#include <string>
using namespace std;

string str;
int dp[11][10];
long long int sum = -1;

int Z(int x, int num) {
	for (int i = 0; i < x; i++) {
		num /= 10;
	}

	return num;
}

int X(int x) {
	int mul = 1;
	for (int i = 0; i <= x; i++) {
		mul *= 10;
	}

	return mul;
}

long long int st(int x, int y) {
	int a = 0, b = 0;
	long long int z;
	z = y;
	for (int i = 0; i < x - 1; i++) {
		z *= 10;
		a += b;
		b = (Z(i, b) + 1) * X(i);
	}

	z += a;

	return z;
}

long long int find(int N) {
	if (N >= 1023) return -1;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
		sum += dp[1][i];
		if (sum == N) return i;
	}
	for (int i = 2; i <= 10; i++) {
		for (int j = i - 1; j < 10; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			sum += dp[i][j];
			if (sum >= N) {
				sum -= dp[i][j];
				for (long long int k = st(i, j); ; k++) {
					int check = 0;
					str = to_string(k);
					for (int x = 0; str[x + 1]; x++) {
						if (str[x] <= str[x + 1]) {
							check = 1;
							break;
						}
					}
					if (check == 0) sum++;
					if (sum == N) return k;
				}
			}
		}
	}

	int a = 1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	cout << find(N) << '\n';

	return 0;
}