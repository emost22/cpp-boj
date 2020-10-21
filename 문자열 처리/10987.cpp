#include <iostream>
using namespace std;

char str[100];
int cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') cnt++;
	}

	cout << cnt << '\n';

	return 0;
}