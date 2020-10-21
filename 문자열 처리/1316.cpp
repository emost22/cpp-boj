#include <iostream>
#include <memory.h>
using namespace std;

char str[100];
bool visit[26], check;
int cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	while (N--) {
		cin >> str;
		for (int i = 0; str[i]; i++) {
			if (!visit[str[i] - 97]) {
				visit[str[i] - 97] = true;
				check = true;
			}
			else {
				if (str[i - 1] != str[i]) {
					check = false;
					break;
				}
				else check = true;
			}
		}

		if (check) cnt++;

		memset(visit, false, sizeof(visit));
	}

	cout << cnt << '\n';

	return 0;
}