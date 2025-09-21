#include <iostream>
#define MAX 100
using namespace std;

typedef struct Node {
	int a;
	int b;
	int x;
}Node;

Node list[MAX];
int N;

void func() {
	for (int i = 0; i < N; i++) {
		cout << list[i].a * (list[i].x - 1) + list[i].b << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].a >> list[i].b >> list[i].x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}