#include <iostream>
#include <queue>
#include <string>
#define MAX 10
using namespace std;

string str1, str2;
bool visit[1 << MAX];
int s, e;

int bfs() {
	queue<int> q;
	q.push(s);
	visit[s] = 1;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (x == e) {
				return t;
			}

			int bit = 1;
			while (1) {
				if (!x) break;
				if (x & bit) {
					if (bit > x / 2) break;
				}

				int next = x ^ bit;
				if (!visit[next]) {
					q.push(next);
					visit[next] = true;
				}
				bit <<= 1;
			}

			if (x + 1 < 1024 && !visit[x + 1]) {
				q.push(x + 1);
				visit[x + 1] = true;
			}
			if (x && !visit[x - 1]) {
				q.push(x - 1);
				visit[x - 1] = true;
			}
		}
	}

	return 0;
}

void func() {
	cout << bfs() << '\n';
}

void init() {
	int len1 = str1.size();
	int mul = 1;
	for (int i = len1 - 1; i >= 0; i--) {
		if (str1[i] == '1') s += mul;
		mul <<= 1;
	}

	int len2 = str2.size();
	mul = 1;
	for (int i = len2 - 1; i >= 0; i--) {
		if (str2[i] == '1') e += mul;
		mul <<= 1;
	}
}

void input() {
	cin >> str1 >> str2;
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}