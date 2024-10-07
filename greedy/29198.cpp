#include <iostream>
#include <algorithm>
#include <string>
#define MAX 301
using namespace std;

string list[MAX];
int N, M, K;

void func() {
	sort(list, list + N);

	string ret = "";
	for (int i = 0; i < K; i++) {
		ret += list[i];
	}
	sort(ret.begin(), ret.end());
	cout << ret << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		sort(list[i].begin(), list[i].end());
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}