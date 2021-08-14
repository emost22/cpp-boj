#include <iostream>
#include <string>
using namespace std;

string str;

void input() {
	cin >> str;
	int N = str.size();

	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0, j = N / 2; i < N / 2; i++, j++) {
		sum1 += str[i] - '0';
		sum2 += str[j] - '0';
	}

	if (sum1 == sum2) cout << "LUCKY\n";
	else cout << "READY\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}