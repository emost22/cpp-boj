#include <iostream>
#include <string>
#include <vector>
#define MAX 5
using namespace std;

vector<string> v;
string str;
int N;

int getIdx(char x) {
	if (x == 'q') return 0;
	else if (x == 'u') return 1;
	else if (x == 'a') return 2;
	else if (x == 'c') return 3;
	else return 4;
}

void func() {
	for (auto x : str) {
		int idx = getIdx(x);
		bool flag = false;
		for (int i = 0; i < v.size(); i++) {
			int pre = v[i][v[i].size() - 1] - '0';
			if ((idx + MAX - 1) % MAX == pre) {
				flag = true;
				v[i] = v[i] + to_string(idx);
				break;
			}
		}

		if (!flag) {
			if (!idx) {
				v.push_back("0");
			}
			else {
				cout << "-1\n";
				return;
			}
		}
	}

	for (auto x : v) {
		if (x.size() % 5) {
			cout << "-1\n";
			return;
		}
	}

	cout << v.size() << '\n';
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}