#include <iostream>
#include <cmath>
#include <string>
#define MAX 11
using namespace std;
typedef pair<int, double> pii;

pii list[MAX];
int N;

void func() {
	double ret = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[i].first * list[i].second);
		sum += list[i].first;
	}
	string str = to_string(round(ret * 10 / sum) / 10).substr(0, 3);
	if (str == "0") str = "0.0";

	cout << sum << ' ' << str << '\n';
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

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}