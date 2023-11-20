#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1000001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	for (int i = 0; i < N; i++) {
		string str = to_string(list[i]);
		reverse(str.begin(), str.end());
		list[i] = stoll(str);
	}
	sort(list, list + N);

	for (int i = 0; i < N; i++) {
		cout << list[i] << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}