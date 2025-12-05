#include <iostream>
#include <vector>
#include <string>
#define DR 60
#define CR 70
#define BR 80
#define AR 90
using namespace std;

typedef struct Node {
	string name;
	int score;
}Node;

vector<Node> v;
int N;

string getGrade(int score) {
	if (score < DR) return "F";

	string ret;
	if (score < CR) ret = "D";
	else if (score < BR) ret = "C";
	else if (score < AR) ret = "B";
	else ret = "A";

	if (score == 100 || score % 10 > 6) ret += '+';
	return ret;
}

void func() {
	for (auto x : v) {
		cout << x.name << ' ' << getGrade(x.score) << '\n';
	}
}

void input() {
	string name;
	int score;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> score;
		v.push_back({ name, score });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}