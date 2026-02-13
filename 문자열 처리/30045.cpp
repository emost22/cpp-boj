#include <iostream>
#include <string>
#define OI1 "01"
#define OI2 "OI"
#define MAX 500
using namespace std;

string list[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += ((list[i].find(OI1) != string::npos) || (list[i].find(OI2) != string::npos));
	}

	cout << ret << '\n';
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