#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> m;

void init() {
	m.insert({ "NLCS", "North London Collegiate School" });
	m.insert({ "BHA", "Branksome Hall Asia" });
	m.insert({ "KIS", "Korea International School" });
	m.insert({ "SJA", "St. Johnsbury Academy" });
}

void input() {
	string str;
	cin >> str;
	cout << m[str] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}