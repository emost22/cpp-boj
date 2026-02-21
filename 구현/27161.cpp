#include <iostream>
#define HRG "HOURGLASS"
#define MAX 1000
using namespace std;

typedef struct Card {
	string type;
	int h;
}Card;

Card list[MAX];
int N;

void func() {
	int now = 1;
	int t = 1;
	for (int i = 0; i < N; i++) {
		if (HRG == list[i].type && list[i].h == now) {
			cout << now << " NO\n";
		}
		else if (HRG == list[i].type) {
			t *= -1;
			cout << now << " NO\n";
		}
		else if (list[i].h == now) {
			cout << now << " YES\n";
		}
		else {
			cout << now << " NO\n";
		}
		
		now += t;
		if (now == 13) now = 1;
		else if (!now) now = 12;
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].type >> list[i].h;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}