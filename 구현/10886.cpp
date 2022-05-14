#include <iostream>
#include <string>
using namespace std;

string str[] = { "Junhee is not cute!", "Junhee is cute!" };
int num[2];

void input() {
	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		num[x]++;
	}

	cout << (num[0] > num[1] ? str[0] : str[1]) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}