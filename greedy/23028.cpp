#include <iostream>
#include <algorithm>
#define MAX 10
#define MIN_A 66
#define MIN_B 130
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, A, B;

void func() {
	int a = MIN_A - A;
	int b = MIN_B - B;
	for (int i = 0; i + N < 8; i++) {
		a -= (list[i].first * 3);
		b -= (list[i].first * 3);
		if (list[i].first < 6) {
			b -= (min(list[i].second, 6 - list[i].first) * 3);
		}
	}
	
	if (a <= 0 && b <= 0) cout << "Nice\n";
	else cout << "Nae ga wae\n";
}

void input() {
	cin >> N >> A >> B;
	for (int i = 0; i < MAX; i++) {
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