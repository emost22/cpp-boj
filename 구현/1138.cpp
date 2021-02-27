#include <iostream>
using namespace std;

int list[11], num[11];
int N;

void print() {
	for (int i = 1; i <= N; i++) {
		cout << num[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (!num[j] && cnt == list[i]) {
				num[j] = i;
				break;
			}
			if (!num[j] || num[j] > i) cnt++;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	print();

	return 0;
}