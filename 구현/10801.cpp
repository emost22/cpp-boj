#include <iostream>
#define MAX 10
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];

void func() {
	int a = 0;
	int b = 0;
	for (int i = 0; i < MAX; i++) {
		if (list[i].first > list[i].second) a++;
		else if (list[i].first < list[i].second)b++;
	}

	if (a > b) cout << "A\n";
	else  if (a < b) cout << "B\n";
	else cout << "D\n";
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> list[i].first;
	}

	for (int i = 0; i < MAX; i++) {
		cin >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}