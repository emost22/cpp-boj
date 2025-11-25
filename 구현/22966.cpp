#include <iostream>
#include <string>
#define MAX 4
using namespace std;

typedef struct Node {
	string title;
	int level;
}Node;

Node list[MAX];
int N;

void func() {
	string ret = list[0].title;
	int mn = list[0].level;
	for (int i = 1; i < N; i++) {
		if (mn < list[i].level) continue;
		mn = list[i].level;
		ret = list[i].title;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].title >> list[i].level;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}