#include <iostream>
#include <stack>
using namespace std;

stack<int> alpha;
pair<pair<int, int>, int> node[2001];
int parent[2001];
int last = 0, level = 0, N, X, Y;

int Max(int x, int y) {
	return x > y ? x : y;
}

void pushpop(char c, int i) {
	if (c == '0') {
		if (alpha.empty()) {
			alpha.push(1);
			last = 1;
			node[alpha.top()].first.first = i;
			node[alpha.top()].second = 1;
		}
		else {
			last++;
			parent[last] = alpha.top();
			alpha.push(last);
			node[alpha.top()].first.first = i;
			node[alpha.top()].second = node[parent[last]].second + 1;
		}
	}
	else {
		last = Max(last, alpha.top());
		node[alpha.top()].first.second = i;
		alpha.pop();
	}
}

int findnode(int del) {
	for (int i = 1; i <= N; i++) {
		if (node[i].first.first == del || node[i].first.second == del) {
			return i;
		}
	}
}

void delnode(int del1, int del2) {
	int a = node[del1].second;
	int b = node[del2].second;
	if (a > b) {
		while (a != b) {
			del1 = parent[del1];
			a = node[del1].second;
		}
	}
	else if (a < b) {
		while (a != b) {
			del2 = parent[del2];
			b = node[del2].second;
		}
	}

	if (del1 != del2) {
		while (del1 != del2) {
			del1 = parent[del1];
			del2 = parent[del2];
		}
	}

	cout << node[del1].first.first << ' ' << node[del2].first.second << '\n';
	return;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int del1, del2;
	char c;

	cin >> N;
	for (int i = 1; i <= 2 * N; i++) {
		cin >> c;
		pushpop(c, i);
	}

	cin >> del1 >> del2;
	del1 = findnode(del1);
	del2 = findnode(del2);

	delnode(del1, del2);

	return 0;
}