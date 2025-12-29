#include <iostream>
#define MAX 3
using namespace std;

typedef struct Node {
	double p;
	double w;
}Node;

Node list[MAX];

void func() {
	int idx = 0;
	double mx = 0;
	for (int i = 0; i < MAX; i++) {
		double tmp = list[i].p * 10.0;
		if (tmp >= 5000.0) tmp -= 500.0;
		tmp = list[i].w * 10.0 / tmp;

		if (tmp >= mx) {
			mx = tmp;
			idx = i;
		}
	}

	if (!idx) cout << "S\n";
	else if (idx == 1) cout << "N\n";
	else cout << "U\n";
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> list[i].p >> list[i].w;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}