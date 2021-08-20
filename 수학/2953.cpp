#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> list[5];

void input() {
	int x;
	for (int i = 0; i < 5; i++) {
		list[i].second = i + 1;
		for (int j = 0; j < 4; j++) {
			cin >> x;
			list[i].first += x;
		}
	}
	sort(list, list + 5);

	cout << list[4].second << ' ' << list[4].first << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}