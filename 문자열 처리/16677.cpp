#include <iostream>
#include <string>
#define MAX 101
using namespace std;
typedef pair<string, double> psd;

string str;
psd list[MAX];
int N, len;

double getScore(string x) {
	int i = 0;
	int j = 0;
	double cnt = 0.0;
	while (1) {
		if (str[i] == x[j]) {
			i++;
			j++;
		}
		else {
			j++;
			cnt += 1.0;
		}

		if (i >= len) {
			return cnt + x.size() - j;
		}
		else if (j >= x.size()) {
			return -1.0;
		}
	}

	return -1.0;
}

void func() {
	string ret = "No Jam";
	double g = 0.0;
	for (auto x : list) {
		double cnt = getScore(x.first);
		if (cnt < 0) continue;
		if (g < x.second / cnt) {
			g = x.second / cnt;
			ret = x.first;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> str >> N;
	len = str.size();
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}