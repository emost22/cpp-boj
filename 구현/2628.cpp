#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> col, row;
int N, M, K;

void func() {
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());

	int rSize = row.size();
	int cSize = col.size();
	int ret = 0;
	for (int i = 1; i < rSize; i++) {
		for (int j = 1; j < cSize; j++) {
			ret = max(ret, (row[i] - row[i - 1]) * (col[j] - col[j - 1]));
		}
	}

	cout << ret << '\n';
}

void input() {
	int type, x;
	cin >> N >> M >> K;
	while (K--) {
		cin >> type >> x;
		if (type) row.push_back(x);
		else col.push_back(x);
	}
	row.push_back(0);
	row.push_back(N);
	col.push_back(0);
	col.push_back(M);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}