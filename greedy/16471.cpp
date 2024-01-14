#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list1[MAX], list2[MAX];
int N;

void func() {
	sort(list1, list1 + N);
	sort(list2, list2 + N);

	int ret = 0;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = idx; j < N; j++) {
			if (list1[i] < list2[j]) {
				ret++;
				idx = j + 1;
				break;
			}
		}
	}

	if (ret >= ((N + 1) >> 1)) cout << "YES\n";
	else cout << "NO\n";
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list1[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> list2[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}