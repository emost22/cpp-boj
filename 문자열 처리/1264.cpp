#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') str[i] += 32;
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') ans++;
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		getline(cin, str);
		if (str == "#") return 0;
		func();
	}
}