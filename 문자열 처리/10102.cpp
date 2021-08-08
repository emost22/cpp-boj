#include <iostream>
#include <string>
using namespace std;

string str;
int cnt[2];
int N;

void input() {
	cin >> N >> str;
	for (int i = 0; i < N; i++) {
		cnt[str[i] - 'A']++;
	}

	if (cnt[0] == cnt[1]) cout << "Tie\n";
	else if (cnt[0] > cnt[1]) cout << "A\n";
	else cout << "B\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}