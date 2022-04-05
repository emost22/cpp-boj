#include <iostream>
#include <string>
#define MAX 101
using namespace std;

string list[MAX];
int N;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			string tmp = list[i] + list[j];
			int r = tmp.size() - 1;
			int l = 0;
			bool flag = true;
			while (l < r) {
				if (tmp[l] != tmp[r]) {
					flag = false;
					break;
				}
				l++;
				r--;
			}

			if (flag) {
				cout << tmp << '\n';
				return;
			}
		}
	}

	cout << "0\n";
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}