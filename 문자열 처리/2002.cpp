#include <iostream>
#include <cstring>
using namespace std;

typedef struct car {
	char st[9];
	int s;
	int e;
}car;

car list[1000];
int N, ans;

void func() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (list[i].e < list[j].e) {
				ans++;
				break;
			}
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].st;
		list[i].s = i;
	}

	char ch[9];
	for (int i = 0; i < N; i++) {
		cin >> ch;
		for (int j = 0; j < N; j++) {
			if (!strcmp(ch, list[j].st)) {
				list[j].e = i;
				break;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}