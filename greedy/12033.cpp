#include <iostream>
#include <vector>
#include <map>
#define MAX 8
using namespace std;

int list[MAX];
int N;

void func(int tc) {
	map<int, int> m;
	vector<int> v;
	for (int i = N - 1; i >= 0; i--) {
		if (m.find(list[i]) == m.end() || !m[list[i]]) {
			m[list[i] * 0.75]++;
		}
		else {
			m[list[i]]--;
			v.push_back(list[i]);
		}
	}

	cout << "Case #" << tc << ": ";
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	N <<= 1;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}