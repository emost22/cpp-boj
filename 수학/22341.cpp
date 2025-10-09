#include <iostream>
#define MAX 10000
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, C;

int getArea(pii s, pii e) {
	return (e.first - s.first) * (e.second - s.second);
}

void func() {
	int a = N;
	int b = N;
	for (int i = 0; i < C; i++) {
		if (list[i].first >= a || list[i].second >= b) continue;

		int r = getArea({ 0,0 }, { list[i].first, b });
		int c = getArea({ 0,0 }, { a,list[i].second });
		if (r >= c) a = list[i].first;
		else b = list[i].second;
	}

	cout << a * b << '\n';
}

void input() {
	cin >> N >> C;
	for (int i = 0; i < C; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}