#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> m;
vector<string> v;
int N;

void init() {
	m.insert({ "Poblano", 1500 });
	m.insert({ "Mirasol", 6000 });
	m.insert({ "Serrano", 15500 });
	m.insert({ "Cayenne", 40000 });
	m.insert({ "Thai", 75000 });
	m.insert({ "Habanero", 125000 });
}

void func() {
	init();

	int ret = 0;
	for (auto x : v) {
		ret += m[x];
	}

	cout << ret << '\n';
}

void input() {
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}