#include <iostream>
using namespace std;

int list[11], N;
long long int reslut, max_value = -1000000000, min_value = 1000000000;

long long int Max(long long int x, long long int y) {
	return x > y ? x : y;
}

long long int Min(long long int x, long long int y) {
	return x < y ? x : y;
}

void dfs(int s, long long int result, int sum, int sub, int mul, int div) {
	if (!sum && !sub && !mul && !div) {
		max_value = Max(max_value, result);
		min_value = Min(min_value, result);
	}

	if (sum > 0) dfs(s + 1, result + list[s], sum - 1, sub, mul, div);
	if (sub > 0) dfs(s + 1, result - list[s], sum, sub - 1, mul, div);
	if (mul > 0) dfs(s + 1, result * list[s], sum, sub, mul - 1, div);
	if (div > 0) dfs(s + 1, result / list[s], sum, sub, mul, div - 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int sum, sub, mul, div;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> sum >> sub >> mul >> div;

	dfs(1, list[0], sum, sub, mul, div);

	cout << max_value << '\n' << min_value << '\n';

	return 0;
}