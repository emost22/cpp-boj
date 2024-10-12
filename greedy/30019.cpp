#include <iostream>
#define MAX 200001
using namespace std;
typedef pair<int, int> pii;

typedef struct Node {
	int idx;
	int s;
	int e;
}Node;

Node list[MAX];
pii room[MAX];
int N, M;

void func() {
	for (int i = 0; i < M; i++) {
		if (room[list[i].idx].second > list[i].s) {
			cout << "NO\n";
			continue;
		}

		room[list[i].idx] = { list[i].s, list[i].e };
		cout << "YES\n";
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> list[i].idx >> list[i].s >> list[i].e;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}