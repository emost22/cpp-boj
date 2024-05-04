#include <iostream>
#include <string>
#define MAX 30
using namespace std;

char list[MAX][MAX];
int N, M;

string getResult(string a, string b) {
	if (a == "") return b;
	if (b.size() < 2) return a;
	if (a < b) return a;
	return b;
}

void func() {
	string ret = "";
	for (int i = 0; i < N; i++) {
		string str = "";
		for (int j = 0; j < M; j++) {
			if (list[i][j] == '#') {
				ret = getResult(ret, str);
				str = "";
			}
			else str += list[i][j];
		}
		ret = getResult(ret, str);
	}

	for (int i = 0; i < M; i++) {
		string str = "";
		for (int j = 0; j < N; j++) {
			if (list[j][i] == '#') {
				ret = getResult(ret, str);
				str = "";
			}
			else str += list[j][i];
		}
		ret = getResult(ret, str);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}