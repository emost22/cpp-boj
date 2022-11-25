#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

typedef struct Node {
	int a, d, g;
}Node;

Node list[MAX];
int N;

int multiply(int a, int d, int g) {
	return (a == d + g) ? 2 : 1;
}

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, (list[i].a * (list[i].d + list[i].g)) * multiply(list[i].a, list[i].d, list[i].g));
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].a >> list[i].d >> list[i].g;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}