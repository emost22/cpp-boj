#include <iostream>
#include <string>
using namespace std;

string str;

void input() {
	int N;
	cin >> N;
	while (N--) {
		cin >> str;
		cout << (str.size() >= 6 && str.size() <= 9 ? "yes\n" : "no\n");
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}