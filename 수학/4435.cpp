#include <iostream>
#define GAN 6
#define SA 7
using namespace std;

int scores[2][SA] = { {1,2,3,3,4,10,0},{1,2,2,2,3,5,10} };
int list[2][SA];

void func(int tc) {
	int g = 0;
	for (int i = 0; i < GAN; i++) {
		g += (scores[0][i] * list[0][i]);
	}

	int s = 0;
	for (int i = 0; i < SA; i++) {
		s += (scores[1][i] * list[1][i]);
	}

	cout << "Battle " << tc << ": ";
	if (g > s) cout << "Good triumphs over Evil\n";
	else if (g < s) cout << "Evil eradicates all trace of Good\n";
	else cout << "No victor on this battle field\n";
}

void input() {
	for (int i = 0; i < GAN; i++) {
		cin >> list[0][i];
	}

	for (int i = 0; i < SA; i++) {
		cin >> list[1][i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}