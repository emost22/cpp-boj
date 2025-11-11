#include <iostream>
#define MAX 51
using namespace std;

char list[MAX][MAX];
int N, M, a, b;

void func() {
	for (int i = 0; i < N; i++) {
		for (int x = 0; x < a; x++) {
			for (int j = 0; j < M; j++) {
				for (int y = 0; y < b; y++) {
					cout << list[i][j];
				}
			}
			cout << '\n';
		}
	}
}

void input() {
	cin >> N >> M >> a >> b;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}