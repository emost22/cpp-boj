#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

typedef struct Node {
	int ww;
	int we;
	int ew;
	int ee;
}Node;

Node list[MAX];
int N, W, E;

void func(int tc) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += max(list[i].ww * W + list[i].ew * E, list[i].we * W + list[i].ee * E);
	}
	cout << "Data Set " << tc << ":\n" << ret << "\n\n";
}

void input() {
	cin >> N >> W >> E;
	for (int i = 0; i < N; i++) {
		cin >> list[i].ww >> list[i].we >> list[i].ew >> list[i].ee;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}