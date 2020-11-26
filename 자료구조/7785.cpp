#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	string name, str;
	int N;
	cin >> N;
	while (N--) {
		cin >> name >> str;
		if (!str.compare("enter")) {
			if (m.find(name) == m.end()) {
				m.insert({ name, 1 });
			}
		}
		else {
			m.erase(name);
		}
	}

	map<string, int>::iterator iter;
	iter = m.end();
	iter--;
	for (; ; iter--) {
		cout << iter->first << '\n';
		if (iter == m.begin()) break;
	}

	return 0;
}