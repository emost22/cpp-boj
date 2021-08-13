#include <iostream>
#include <string>
using namespace std;

string str;
int N, M;

void input() {
	cin >> N >> M;

	str = to_string(N);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < str.size(); j++) {
			cout << str[j];
			cnt++;
			if (cnt == M) {
				cout << '\n';
				return;
			}
		}
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}