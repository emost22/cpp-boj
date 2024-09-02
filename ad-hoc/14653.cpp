#include <iostream>
#define MAX 10001
using namespace std;
typedef pair<int, char> pii;

pii list[MAX];
bool chk[26];
int N, K, Q;

void func() {
	if (!list[Q].first) {
		cout << "-1\n";
		return;
	}

	for (int i = 1; i < Q; i++) {
		if (list[i].first != list[Q].first) continue;
		chk[list[i].second - 'A'] = true;
	}
	for (int i = Q; i <= K; i++) {
		chk[list[i].second - 'A'] = true;
	}

	for (int i = 1; i < N; i++) {
		if (chk[i]) continue;
		cout << (char)(i + 'A') << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> K >> Q;
	for (int i = 1; i <= K; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}