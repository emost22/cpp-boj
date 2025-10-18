#include <iostream>
#include <algorithm>
#define MAX 3
#define TOTAL 100
using namespace std;
typedef pair<int, int> pii;

const pii FROM_TO[MAX] = { {0,1},{1,2},{2,0} };
int mx[MAX], now[MAX];

void func() {
	int t = 0;
	for (int i = 0; i < TOTAL; i++, t = (t + 1) % MAX) {
		int from = FROM_TO[t].first;
		int to = FROM_TO[t].second;
		int amount = min(now[from], mx[to] - now[to]);
		now[from] -= amount;
		now[to] += amount;
	}

	for (int i = 0; i < MAX; i++) {
		cout << now[i] << '\n';
	}
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> mx[i] >> now[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}