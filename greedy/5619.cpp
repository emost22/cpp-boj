#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

priority_queue<int> q;

void func() {
	vector<int> v;
	while (!q.empty()) {
		v.push_back(q.top());
		q.pop();
	}

	vector<int> tmp;
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			tmp.push_back(stoi(to_string(v[i]) + to_string(v[j])));
			tmp.push_back(stoi(to_string(v[j]) + to_string(v[i])));
		}
	}
	sort(tmp.begin(), tmp.end());
	cout << tmp[2] << '\n';
}

void input() {
	int N, x;
	cin >> N;
	while (N--) {
		cin >> x;
		q.push(x);
		if (q.size() > 4) q.pop();
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}