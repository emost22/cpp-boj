#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
	char c;
	int x;
}Node;

vector<Node> v;
int o, w;

void func(int tc) {
	int now = w;
	for (auto a : v) {
		if (a.c == 'E') now -= a.x;
		else now += a.x;

		if (now <= 0) {
			cout << tc << " RIP\n";
			return;
		}
	}

	if ((now << 1) > o && now < (o << 1)) cout << tc << " :-)\n";
	else cout << tc << " :-(\n";
}

void input() {
	cin >> o >> w;
	if (!o) exit(0);

	char c;
	int x;
	while (1) {
		cin >> c >> x;
		if (c == '#') break;
		v.push_back({ c,x });
	}
}

void init() {
	v.clear();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; ; t++) {
		input();
		func(t);
		init();
	}

	return 0;
}