#include <iostream>
#include <string>
#define MAX (1 << 20) - 1
using namespace std;

int M, K;

void Add(int x) {
	if (K & x) return;
	K |= x;
}

void Remove(int x) {
	if (!(K & x)) return;
	K ^= x;
}

void Check(int x) {
	cout << (K & x ? 1 : 0) << '\n';
}

void Toggle(int x) {
	K ^= x;
}

void All() {
	K = MAX;
}

void Empty() {
	K = 0;
}

void input() {
	string type;
	int x;
	cin >> M;
	while (M--) {
		cin >> type;
		if (type == "all") {
			All();
		}
		else if (type == "empty") {
			Empty();
		}
		else {
			cin >> x;
			if (type == "add") {
				Add(1 << (x - 1));
			}
			else if (type == "remove") {
				Remove(1 << (x - 1));
			}
			else if (type == "check") {
				Check(1 << (x - 1));
			}
			else {
				Toggle(1 << (x - 1));
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}