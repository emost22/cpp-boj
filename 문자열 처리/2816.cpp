#include <iostream>
#include <cstring>
using namespace std;

int N, now, idx;
char ch[100][11], ans[500];

void num1() {
	now++;
}

void num4() {
	char tmp[11];
	strcpy(tmp, ch[now]);
	strcpy(ch[now], ch[now - 1]);
	strcpy(ch[now - 1], tmp);
	now--;
}

void func() {
	while (strcmp(ch[now], "KBS1")) {
		num1();
		ans[idx++] = '1';
	}

	while (strcmp(ch[0], "KBS1")) {
		num4();
		ans[idx++] = '4';
	}

	while (strcmp(ch[now], "KBS2")) {
		num1();
		ans[idx++] = '1';
	}

	while (strcmp(ch[1], "KBS2")) {
		num4();
		ans[idx++] = '4';
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ch[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}