#include <iostream>
using namespace std;

char str[1000000];
int cnt, e;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin.getline(str, 1000000);
	for (int i = 0; str[i]; i++) {
		if (i == 0 && str[i] == ' ') continue;
		
		if (str[i] == ' ') cnt++;

		if (str[i + 1] == NULL) e = i;
	}
	if (str[e] == ' ') cnt--;

	cout << cnt + 1 << '\n';

	return 0;
}