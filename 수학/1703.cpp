#include <iostream>
#define MAX 20
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int a;

void func() {
	int ret = 1;
	for (int i = 0; i < a; i++) {
		ret = ret * list[i].first - list[i].second;
	}
	cout << ret << '\n';
}

void input() {
	cin >> a;
	if (!a) exit(0);
	for (int i = 0; i < a; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}