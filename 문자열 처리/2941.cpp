#include <iostream>
using namespace std;

char str[100];
int cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	for (int i = 0; str[i];) {
		if (str[i] == 'c') {
			if (str[i + 1] == '=' || str[i + 1] == '-') {
				cnt++;
				i += 2;
			}
			else cnt++, i++;
		}
		else if (str[i] == 'd') {
			if (str[i + 1] == '-') {
				cnt++;
				i += 2;
			}
			else if (str[i + 1] == 'z' && str[i + 2] == '=') {
				cnt++;
				i += 3;
			}
			else cnt++, i++;
		}
		else if (str[i] == 'l' || str[i] == 'n') {
			if (str[i + 1] == 'j') {
				cnt++;
				i += 2;
			}
			else cnt++, i++;
		}
		else if (str[i] == 's' || str[i] == 'z') {
			if (str[i + 1] == '=') {
				cnt++;
				i += 2;
			}
			else cnt++, i++;
		}
		else {
			cnt++, i++;
		}
	}

	cout << cnt << '\n';

	return 0;
}