#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1001
using namespace std;

string list[MAX];
bool flag;
int N;

bool cmp(string a, string b) {
	return a + b > b + a;
}

void func() {
	if (!flag) {
		cout << "0\n";
		return;
	}

	sort(list, list + N, cmp);
	for (int i = 0; i < N; i++) {
		cout << list[i];
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		flag |= (list[i] != "0");
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}