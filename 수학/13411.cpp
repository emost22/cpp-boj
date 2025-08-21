#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 100000
using namespace std;

typedef struct Node {
	int idx;
	double x, y, v, t;
}Node;

Node list[MAX];
int N;

double getDistance(double x, double y) {
	return sqrt(x * x + y * y);
}

void func() {
	for (int i = 0; i < N; i++) {
		list[i].t = getDistance(list[i].x, list[i].y) / list[i].v;
	}

	sort(list, list + N, [](Node a, Node b) {
		if (a.t == b.t) return a.idx < b.idx;
		return a.t < b.t;
	});

	for (int i = 0; i < N; i++) {
		cout << list[i].idx << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].x >> list[i].y >> list[i].v;
		list[i].idx = i + 1;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}