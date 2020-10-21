#include <iostream>
using namespace std;

char st1[31], st2[31];
int alpha[26], x, y;

void func() {
	for (int i = 0; st2[i]; i++) {
		if (alpha[st2[i] - 'A']) continue;
		alpha[st2[i] - 'A'] = i + 1;
	}

	for (int i = 0; st1[i]; i++) {
		if (alpha[st1[i] - 'A']) {
			x = alpha[st1[i] - 'A'] - 1;
			y = i;
			break;
		}
	}
}

void print() {
	int n1 = 0;
	int n2 = 0;
	for (int i = 0; st2[i]; i++) {
		for (int j = 0; st1[j]; j++) {
			if (j == y) {
				cout << st2[n2++];
				if (i == x) n1++;
			}
			else if (i == x) {
				cout << st1[n1++];
			}
			else cout << '.';
		}
		cout << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> st1 >> st2;
	func();
	print();

	return 0;
}