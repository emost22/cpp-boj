#include <iostream>
#define MAX 50
using namespace std;

int list[MAX];
int N, W, H;

void func() {
	int x = W * W + H * H;
	for (int i = 0; i < N; i++) {
		if (list[i] * list[i] <= x) cout << "YES\n";
		else cout << "NO\n";
	}
}

void input() {
	cin >> N >> W >> H;
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