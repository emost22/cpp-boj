#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

typedef struct Node {
	int a;
	int b;
	int c;
}Node;

Node list[MAX];
Node x;
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret = max(ret, x.a * list[i].a + x.b * list[i].b + x.c * list[i].c);
	}
	cout << ret << '\n';
}

void input() {
	cin >> x.a >> x.b >> x.c >> N;

	int a, b, c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a >> b >> c;
			list[i].a += a;
			list[i].b += b;
			list[i].c += c;
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