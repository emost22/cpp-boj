#include <iostream>
#define MAX 1000000
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	int a = 0;
	int b = 0;
	for (int i = 0; i < N; i++) {
		if (list[i].first > list[i].second) a++;
		else if (list[i].first < list[i].second) b++;
	}

	cout << a << ' ' << b << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
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