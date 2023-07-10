#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

string str;
int N;

void func() {
	ll c = 0;
	ll o = 0;
	ll w = 0;

	for (int i = 0; i < N; i++) {
		if (str[i] == 'C') c++;
		else if (str[i] == 'O') o += c;
		else if (str[i] == 'W') w += o;
	}

	cout << w << '\n';
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}