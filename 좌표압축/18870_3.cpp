#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000
using namespace std;

vector<int> v, w;
int N;

void func() {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < N; i++) {
		cout << lower_bound(v.begin(), v.end(), w[i]) - v.begin() << ' ';
	}
	cout << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
		w.push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}