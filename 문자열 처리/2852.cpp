#include <iostream>
#include <string>
#include <algorithm>
#define MAX 101
using namespace std;

typedef struct Node {
	int t;
	int s;
}Node;

Node list[MAX];
int N;

bool cmp(Node a, Node b) {
	return a.s < b.s;
}

void func() {
	sort(list, list + N, cmp);

	int s = 0;
	int a = 0;
	int b = 0;
	int as = 0;
	int bs = 0;
	for (int i = 0; i < N; i++) {
		if (list[i].t == 1) {
			a++;
			if (a <= b) {
				bs += (list[i].s - s);
			}
			else if (a > b + 1) {
				as += (list[i].s - s);
			}
		}
		else {
			b++;
			if (a >= b) {
				as += (list[i].s - s);
			}
			else if (b > a + 1) {
				bs += (list[i].s - s);
			}
		}
		s = list[i].s;
	}

	if (a > b) {
		as += (60 * 48 - s);
	}
	else if (a < b) {
		bs += (60 * 48 - s);
	}

	string am = to_string(as / 60);
	if (am.size() == 1) am = "0" + am;
	am = am + ":";
	string ass = to_string(as % 60);
	if (ass.size() == 1) ass = "0" + ass;

	string bm = to_string(bs / 60);
	if (bm.size() == 1) bm = "0" + bm;
	bm = bm + ":";
	string bss = to_string(bs % 60);
	if (bss.size() == 1) bss = "0" + bss;

	cout << am << ass << '\n' << bm << bss << '\n';
}

void input() {
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].t >> str;
		list[i].s = ((str[0] - '0') * 10 + str[1] - '0') * 60 + (str[3] - '0') * 10 + str[4] - '0';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}