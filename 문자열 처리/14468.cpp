#include <iostream>
#include <string>
#include <vector>
#define MAX 26
using namespace std;

string str;
vector<int> pos[MAX];
int len;

bool isCross(int x, int y) {
	return pos[x][0] < pos[y][0] && pos[x][1] < pos[y][1] && pos[x][1] > pos[y][0];
}

void func() {
	for (int i = 0; i < len; i++) {
		pos[str[i] - 'A'].push_back(i);
	}

	int ret = 0;
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = i + 1; j < MAX; j++) {
			ret += (isCross(i, j) + isCross(j, i));
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}