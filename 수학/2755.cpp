#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Node {
	double grade;
	double score;
}Node;

vector<Node> v;
int N;

double getAddScore(char x) {
	if (x == '+') return 0.3;
	else if (x == '0') return 0.0;
	else return -0.3;
}

double getScore(string s) {
	if (s[0] == 'F') return 0.0;
	return getAddScore(s[1]) + (double)'E' - (double)s[0];
}

void func() {
	cout << fixed;
	cout.precision(2);

	double total = 0.0;
	double sum = 0.0;
	for (int i = 0; i < N; i++) {
		total += v[i].grade;
		sum += (v[i].grade * v[i].score);
	}

	cout << sum / total + 1e-9 << '\n';
}

void input() {
	string str, score;
	double grade;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str >> grade >> score;
		v.push_back({ grade, getScore(score) });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}