#include <iostream>
#include <vector>
using namespace std;

vector<int> list, v;
int N, K;

void func() {
	for (int i = 1; i <= N; i++) {
		list.push_back(i);
	}
	int idx = 0;
	while (!list.empty()) {
		int lsize = list.size();
		int next = (idx + K - 1) % lsize;
		v.push_back(list[next]);
		list.erase(list.begin() + next);
		idx = next;
	}

	cout << '<' << v[0];
	for (int i = 1; i < v.size(); i++) {
		cout << ", " << v[i];
	}
	cout << ">\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	func();

	return 0;
}