#include <iostream>
#include <string>
#define MAX 1001
using namespace std;
typedef pair<string, string> pss;

string str, ans;
pss list[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (list[i].first == str) {
			cout << ret << '\n';
			return;
		}
		ret += (list[i].second == ans);
	}
}

void input() {
	cin >> N >> str;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
		if (list[i].first == str) {
			ans = list[i].second;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}