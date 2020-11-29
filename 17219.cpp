#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> m;
string web[100000];
int N, M;

void func() {
	for (int i = 0; i < M; i++) {
		cout << m.find(web[i])->second << '\n';
	}
}

void input() {
	string www, str;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> www >> str;
		m.insert({ www,str });
	}

	for (int i = 0; i < M; i++) {
		cin >> web[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}