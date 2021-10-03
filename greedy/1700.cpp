#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000000000
#define MAX 100
using namespace std;

vector<int> useList;
int list[MAX];
int N, M;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		bool flag = false;

		int vsize = useList.size();
		for (int j = 0; j < vsize; j++) {
			if (useList[j] == list[i]) {
				flag = true;
				break;
			}
		}

		if (flag) continue;

		if (vsize < M) {
			useList.push_back(list[i]);
			continue;
		}

		int maxValue = 0;
		int findIdx = 0;
		for (int j = 0; j < vsize; j++) {
			int idx = INF;
			for (int k = i + 1; k < N; k++) {
				if (useList[j] == list[k]) {
					idx = k;
					break;
				}
			}

			if (maxValue < idx) {
				maxValue = idx;
				findIdx = j;
			}
		}

		useList[findIdx] = list[i];
		ans++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> M >> N;
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