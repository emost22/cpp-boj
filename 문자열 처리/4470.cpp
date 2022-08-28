#include <iostream>
#include <string>
using namespace std;

void input() {
	int N;
	string str;
	cin >> N;
	getline(cin, str);
	for (int i = 1; i <= N; i++) {
		getline(cin, str);
		cout << i << ". " << str << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}