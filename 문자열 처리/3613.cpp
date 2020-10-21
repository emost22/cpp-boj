#include <iostream>
using namespace std;

char st[101], ans[202];
int idx, er;

void javatocpp() {
	ans[idx] = '_';
	idx++;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	bool chk = false;
	cin >> st;
	for (int i = 0; st[i];) {
		if (st[i] == '_') {
			if (er == 2 || chk || i == 0 || !st[i + 1]) {
				er = -1;
				break;
			}
			er = 1;
			chk = true;
			i++;
			continue;			
		}
		else if ('A' <= st[i] && st[i] <= 'Z') {
			if (er == 1 || i == 0) {
				er = -1;
				break;
			}
			javatocpp();
			er = 2;
			st[i] -= ('A' - 'a');
		}
		else if (st[i]<'a' || st[i]>'z') {
			er = -1;
			break;
		}
		if (chk) {
			st[i] += ('A' - 'a');
			chk = false;
		}
		ans[idx] = st[i];
		i++;
		idx++;
	}

	if (er == -1) cout << "Error!\n";
	else cout << ans << '\n';

	return 0;
}