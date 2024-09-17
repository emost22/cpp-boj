#include <iostream>
#include <string>
using namespace std;

string str;
int grade[4];
int N;

void func() {
	int pre = 0;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'B') {
			ret += (grade[0] - 1 - pre);
			pre = (grade[0] - 1 - pre);
		}
		else if (str[i] == 'S') {
			ret += (grade[1] - 1 - pre);
			pre = (grade[1] - 1 - pre);
		}
		else if (str[i] == 'G') {
			ret += (grade[2] - 1 - pre);
			pre = (grade[2] - 1 - pre);
		}
		else if (str[i] == 'P') {
			ret += (grade[3] - 1 - pre);
			pre = (grade[3] - 1 - pre);
		}
		else {
			ret += grade[3];
			pre = grade[3];
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}