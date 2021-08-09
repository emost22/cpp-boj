#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> list[2][3];
int N;

void input() {
	int t = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[t][0].first >> list[t][1].first >> list[t][2].first;

		list[t][0].second = list[t][0].first + min(list[1 - t][0].second, list[1 - t][1].second);
		list[t][1].second = list[t][1].first + min(list[1 - t][0].second, min(list[1 - t][1].second, list[1 - t][2].second));
		list[t][2].second = list[t][2].first + min(list[1 - t][1].second, list[1 - t][2].second);
		
		list[t][0].first = list[t][0].first + max(list[1 - t][0].first, list[1 - t][1].first);
		list[t][1].first = list[t][1].first + max(list[1 - t][0].first, max(list[1 - t][1].first, list[1 - t][2].first));
		list[t][2].first = list[t][2].first + max(list[1 - t][1].first, list[1 - t][2].first);
		t = 1 - t;
	}

	cout << max(list[1 - t][0].first, max(list[1 - t][1].first, list[1 - t][2].first)) << ' ' << min(list[1 - t][0].second, min(list[1 - t][1].second, list[1 - t][2].second)) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}