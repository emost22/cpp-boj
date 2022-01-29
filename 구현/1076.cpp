#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

map<string, pi> m;
string str1, str2, str3;

void init() {
	m.insert({ "black", { 0,1 } });
	m.insert({ "brown", { 1,10 } });
	m.insert({ "red", { 2,100 } });
	m.insert({ "orange", { 3,1000 } });
	m.insert({ "yellow", { 4,10000 } });
	m.insert({ "green", { 5,100000 } });
	m.insert({ "blue", { 6,1000000 } });
	m.insert({ "violet", { 7,10000000 } });
	m.insert({ "grey", { 8,100000000 } });
	m.insert({ "white", { 9,1000000000 } });
}

void func() {
	ll ans = 0;
	ans = (ll)m[str1].first * 10LL + (ll)m[str2].first;
	ans *= (ll)m[str3].second;

	cout << ans << '\n';
}

void input() {
	cin >> str1 >> str2 >> str3;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}