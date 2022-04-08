#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef pair<char, bool> psb;

vector<psb> list;
string str1, str2;
int N, M, T, len;

void func() {
	while (T--) {
		for (int i = 0; i < len - 1; i++) {
			if (list[i].second != list[i + 1].second) {
				if (list[i].second) continue;
				swap(list[i], list[i + 1]);
				i++;
			}
		}
	}

	for (int i = 0; i < len; i++) {
		cout << list[i].first;
	}
	cout << '\n';
}

void init() {
	len = N + M;
	reverse(str1.begin(), str1.end());
	for (int i = 0; i < N; i++) {
		list.push_back({ str1[i], false });
	}

	for (int i = 0; i < M; i++) {
		list.push_back({ str2[i], true });
	}
}

void input() {
	cin >> N >> M >> str1 >> str2 >> T;
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}