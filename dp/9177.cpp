#include <iostream>
#include <string>
#include <cstring>
#define max(a, b) {a > b ? a : b}
using namespace std;

string str1, str2, result;
int dp[201][201];
int size1, size2, rsize;

int func(int idx1, int idx2, int idx) {
	if (idx == rsize) return 1;

	int &ret = dp[idx1][idx2];

	if (ret != -1) return ret;
	ret = 0;

	if (idx1 < size1 && str1[idx1] == result[idx]) ret = func(idx1 + 1, idx2, idx + 1);
	if (idx2 < size2 && str2[idx2] == result[idx]) ret = max(ret, func(idx1, idx2 + 1, idx + 1));

	return ret;
}

void input() {
	cin >> str1 >> str2 >> result;
	size1 = str1.size();
	size2 = str2.size();
	rsize = result.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		memset(dp, -1, sizeof(dp));
		cout << "Data set " << t << ": ";
		input();
		if (func(0, 0, 0)) cout << "yes\n";
		else cout << "no\n";
	}


	return 0;
}