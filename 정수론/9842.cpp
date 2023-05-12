#include <iostream>
#include <vector>
#define MAX 104801
using namespace std;

vector<int> v;
bool isNotPrime[MAX];
int N;

void init() {
	for (int i = 2; i < MAX; i++) {
		if (isNotPrime[i]) continue;

		v.push_back(i);
		for (int j = 2; i * j < MAX; j++) {
			isNotPrime[i * j] = true;
		}
	}
}

void func() {
	init();
	cout << v[N - 1] << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}