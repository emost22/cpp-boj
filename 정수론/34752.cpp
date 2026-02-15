#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 100000
using namespace std;

typedef struct Node {
	string name;
	string no;
	int score;
}Node;

vector<int> prime;
bool chk[MAX];
Node list[MAX];
int N;

void init() {
	for (int i = 2; i < MAX; i++) {
		if (chk[i]) continue;

		prime.push_back(i);
		for (int j = 1; i * j < MAX; j++) {
			if (chk[i * j]) continue;
			chk[i * j] = true;
		}
	}
}

void func() {
	init();

	int mn = 1e9;
	int mx = -1;
	string mnret = "";
	string mxret = "";
	for (int i = 0; i < N; i++) {
		int l = stoi(list[i].no.substr(0, 5));
		int r = stoi(list[i].no.substr(5));
		if (l > r) swap(l, r);
		
		int a = prime.size() - (upper_bound(prime.begin(), prime.end(), r) - prime.begin());
		int b = prime.size() - (lower_bound(prime.begin(), prime.end(), l) - prime.begin());
		list[i].score = b - a;

		if (mn >= list[i].score) {
			if (mn == list[i].score) {
				if (mnret > list[i].name) {
					mnret = list[i].name;
				}
			}
			else {
				mn = list[i].score;
				mnret = list[i].name;
			}
		}

		if (mx <= list[i].score) {
			if (mx == list[i].score) {
				if (mxret > list[i].name) {
					mxret = list[i].name;
				}
			}
			else {
				mx = list[i].score;
				mxret = list[i].name;
			}
		}
	}
	
	cout << mxret << '\n' << mnret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].name >> list[i].no;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}