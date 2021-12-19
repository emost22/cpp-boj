#include <iostream>
#include <algorithm>
#define MAX 11
using namespace std;

int list[MAX], opCnt[4];
int maxValue, minValue;
char opList[4] = { '+', '-', '*', '/' };
int N;

int calc(int sum, int x, char op) {
	if (op == '+') return sum + x;
	else if (op == '-') return sum - x;
	else if (op == '*') return sum * x;
	else return sum / x;
}

void dfs(int idx, int sum) {
	if (idx == N) {
		maxValue = max(maxValue, sum);
		minValue = min(minValue, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!opCnt[i]) continue;

		opCnt[i]--;
		dfs(idx + 1, calc(sum, list[idx], opList[i]));
		opCnt[i]++;
	}
}

void func() {
	maxValue = -1e9;
	minValue = 1e9;
	dfs(1, list[0]);

	cout << maxValue << '\n' << minValue << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	
	for (int i = 0; i < 4; i++) {
		cin >> opCnt[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}