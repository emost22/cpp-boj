#include <iostream>
#define MAX 2
using namespace std;

typedef struct Node {
	int t, e, f;

	int getTime() {
		return t * 3 + e * 20 + f * 120;
	}
}Node;

Node list[MAX];

void func() {
	int mx = list[0].getTime();
	int ml = list[1].getTime();

	if (mx < ml) cout << "Mel\n";
	else if (mx > ml) cout << "Max\n";
	else cout << "Draw\n";
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> list[i].t >> list[i].e >> list[i].f;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}