#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;
int A, B, G;

void func() {
	int scores[2] = { 0,0 };
	string str;
	while (G--) {
		cin >> str;
		scores[m[str]]++;
	}

	if (scores[0] > scores[1]) cout << "A\n";
	else if (scores[0] < scores[1]) cout << "B\n";
	else cout << "TIE\n";
}

void input() {
	string str;
	cin >> A >> B >> G;
	while (A--) {
		cin >> str;
		m.insert({ str, 0 });
	}

	while (B--) {
		cin >> str;
		m.insert({ str, 1 });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}