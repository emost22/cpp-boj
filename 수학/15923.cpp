#include <iostream>
#include <algorithm>
#define MAX 21
using namespace std;

typedef struct Node {
	int x, y;
}Node;

Node list[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		ret += (abs(list[i].x - list[i - 1].x) + abs(list[i].y - list[i - 1].y));
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].x >> list[i].y;
	}
	list[N] = list[0];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}