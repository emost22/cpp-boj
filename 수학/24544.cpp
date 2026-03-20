#include <iostream>
#define MAX 1000
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	int total = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		total += list[i].first;
		if (!list[i].second) sum += list[i].first;
	}

	cout << total << '\n' << sum << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first;
	}

	for (int i = 0; i < N; i++) {
		cin >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}