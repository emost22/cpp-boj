#include <iostream>
#include <cstring>
using namespace std;

int list[11];
char ch[1 << 10][2046];
int N;

void print() {
	if (N % 2) {
		int e = (1 << N) - 1;
		for (int i = 1; i <= (1 << N) - 1; i++) {
			for (int j = 1; j <= e; j++) {
				cout << ch[i][j];
			}
			e++;
			cout << '\n';
		}
	}
	else {
		int e = ((1 << N) - 1) * 2 - 1;
		for (int i = 1; i <= (1 << N) - 1; i++) {
			for (int j = 1; j <= e; j++) {
				cout << ch[i][j];
			}
			e--;
			cout << '\n';
		}
	}
}

void solve(int n, int x, int y) {
	if(n == 1){
		ch[x][y] = '*';
		return;
	}

	int nx = x;
	int ny = y;
	if (n % 2) {
		for (int i = 0; i < (1 << n) - 1; i++, nx++, ny--) {
			ch[nx][ny] = '*';
		}
		nx--;
		ny++;
		for (int i = 0; i < ((1 << n) - 1) * 2 - 1; i++, ny++) {
			ch[nx][ny] = '*';
		}
		ny--;
		for (int i = 0; i < (1 << n) - 1; i++, nx--, ny--) {
			ch[nx][ny] = '*';
		}
		nx = x + (1 << n) - 3;
		ny = y;
		solve(n - 1, nx, ny);
	}
	else {
		for (int i = 0; i < (1 << n) - 1; i++, nx--, ny--) {
			ch[nx][ny] = '*';
		}
		nx++;
		ny++;
		for (int i = 0; i < ((1 << n) - 1) * 2 - 1; i++, ny++) {
			ch[nx][ny] = '*';
		}
		ny--;
		for (int i = 0; i < (1 << n) - 1; i++, nx++, ny--) {
			ch[nx][ny] = '*';
		}
		nx = x - (1 << n) + 3;
		ny = y;
		solve(n - 1, nx, ny);
	}
}

void func() {
	if (N % 2) solve(N, 1, (1 << N) - 1);
	else solve(N, (1 << N) - 1, (1 << N) - 1);
}

void init() {
	int diff = 4;
	list[1] = 1;
	for (int i = 2; i <= 10; i++) {
		list[i] = list[i - 1] + diff;
		diff *= 2;
	}
	memset(ch, ' ', sizeof(ch));
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();
	print();

	return 0;
}