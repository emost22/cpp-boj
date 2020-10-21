#include <iostream>
#include <cstring>
using namespace std;

typedef struct word {
	char w[14];
	char r[14];
	int si;
}word;

word list[100];
int N;

void func() {
	for (int i = 0; i < N; i++) {
		if (!strcmp(list[i].w, list[i].r)) {
			cout << list[i].si << ' ' << list[i].w[list[i].si / 2] << '\n';
			return;
		}
		for (int j = i + 1; j < N; j++) {
			if (list[i].si != list[j].si) continue;
			if (!strcmp(list[i].w, list[j].w)) {
				cout << list[i].si << ' ' << list[i].w[list[i].si / 2] << '\n';
				return;
			}
			else if (!strcmp(list[i].w, list[j].r)) {
				cout << list[i].si << ' ' << list[i].w[list[i].si / 2] << '\n';
				return;
			}
			else if (!strcmp(list[i].r, list[j].w)) {
				cout << list[i].si << ' ' << list[i].w[list[i].si / 2] << '\n';
				return;
			}
			else if (!strcmp(list[i].r, list[j].r)) {
				cout << list[i].si << ' ' << list[i].w[list[i].si / 2] << '\n';
				return;
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].w;
		list[i].si = strlen(list[i].w);
		for (int j = 0; j < list[i].si / 2; j++) {
			list[i].r[j] = list[i].w[j] ^ list[i].w[list[i].si - j - 1];
			list[i].r[list[i].si - j - 1] = list[i].r[j] ^ list[i].w[list[i].si - j - 1];
			list[i].r[j] = list[i].r[j] ^ list[i].r[list[i].si - j - 1];
		}
		list[i].r[list[i].si / 2] = list[i].w[list[i].si / 2];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}