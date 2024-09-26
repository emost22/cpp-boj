#include <iostream>
#include <unordered_set>
#define MAX 1001
using namespace std;

unordered_set<int> s;
int arrList[MAX];
int N, M;

void func() {
	int ret = 0;
	for (int i = 0; i < M; i++) {
		ret += (s.find(arrList[i]) == s.end());
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arrList[i];
	}

	int x;
	for (int i = 0; i < M; i++) {
		cin >> x;
		s.insert(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}