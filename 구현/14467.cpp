#include <iostream>
#define MAX 101
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int pos[11];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (pos[list[i].first] == -list[i].second) {
			ret++;
		}
		pos[list[i].first] = list[i].second;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
		if (!list[i].second) list[i].second = -1;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}