#include <iostream>
#include <algorithm>
#define STA 3
#define MAX 100000
using namespace std;
typedef pair<int, int> pii;

typedef struct Node {
	int x, y;
	int t[STA];
}Node;

pii stations[STA];
Node list[MAX];
int Q;

void func() {
	for (int i = 0; i < Q; i++) {
		int ret = 1e9;
		for (int j = 0; j < STA; j++) {
			int dis = abs(list[i].x - stations[j].first) + abs(list[i].y - stations[j].second);
			int t = dis / list[i].t[j] + (dis % list[i].t[j] != 0);
			t *= list[i].t[j];
			ret = min(ret, t);
		}

		cout << ret << '\n';
	}
}

void input() {
	cin >> stations[0].first >> stations[0].second >> stations[1].first >> stations[1].second >> stations[2].first >> stations[2].second >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> list[i].x >> list[i].y >> list[i].t[0] >> list[i].t[1] >> list[i].t[2];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}