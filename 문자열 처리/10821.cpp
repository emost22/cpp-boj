#include <iostream>
#include <string>
using namespace std;

string str;
int ans;

void input() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') ans++;
	}

	cout << ans + 1 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}