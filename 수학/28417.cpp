#include <iostream>
#include <algorithm>
#define MAX 100000
#define RND 7
using namespace std;

int list[MAX][RND];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret = max(ret, max(list[i][0], list[i][1]) + list[i][RND - 1] + list[i][RND - 2]);
	}
	
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < RND; j++) {
			cin >> list[i][j];
		}

		sort(list[i] + 2, list[i] + RND);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}