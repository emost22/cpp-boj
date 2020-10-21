#include <iostream>
#include <string>
using namespace std;

string str;
int sosu[1041], alpha[52];

void init() {
	for (int i = 0; i < 52; i++) {
		alpha[i] = i + 1;
	}

	for (int i = 1; i <= 1040; i++) {
		sosu[i] = 1;
	}

	for (int i = 2; i <= 1040; i++) {
		if (!sosu[i]) continue;
		for (int j = 2; i * j <= 1040; j++) {
			if (!sosu[i*j]) continue;
			sosu[i*j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int sum = 0;

	init();

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 97) sum += alpha[str[i] - 97];
		else sum += alpha[str[i] - 65 + 26];
	}

	if (sosu[sum]) cout << "It is a prime word.\n";
	else cout << "It is not a prime word.\n";

	return 0;
}