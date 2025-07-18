#include <iostream>
#define MAX 100
using namespace std;

typedef struct Node {
	double v, f, c;
}Node;

Node list[MAX];
double D;
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		double t = D / list[i].v;
		ret += (t * list[i].c <= list[i].f);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		cin >> list[i].v >> list[i].f >> list[i].c;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}