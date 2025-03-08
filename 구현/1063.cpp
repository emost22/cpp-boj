#include <iostream>
#include <string>
using namespace std;

string k, s;
int direct[8][2] = { {1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1} };
int M;

int getIdx(string str) {
	if (str == "R") return 0;
	if (str == "L") return 1;
	if (str == "B") return 2;
	if (str == "T") return 3;
	if (str == "RT") return 4;
	if (str == "LT") return 5;
	if (str == "RB") return 6;
	return 7;
}

bool isPossibleMove(char x, int y) {
	return x >= 'A' && y > 0 && x <= 'H' && y <= 8;
}

void func() {
	string str;
	char kx = k[0];
	int ky = k[1] - '0';
	char sx = s[0];
	int sy = s[1] - '0';
	while (M--) {
		cin >> str;

		int idx = getIdx(str);
		char knx = kx + direct[idx][0];
		int kny = ky + direct[idx][1];
		if (!isPossibleMove(knx, kny)) continue;
		if (knx == sx && kny == sy) {
			char snx = sx + direct[idx][0];
			int sny = sy + direct[idx][1];
			if (!isPossibleMove(snx, sny)) continue;
			sx = snx;
			sy = sny;
		}
		kx = knx;
		ky = kny;
	}
	cout << kx << ky << '\n' << sx << sy << '\n';
}

void input() {
	cin >> k >> s >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}