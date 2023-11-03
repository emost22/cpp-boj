#include <iostream>
#define MAX 100001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	ll major = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!cnt) major = list[i];

		if (major == list[i]) cnt++;
		else cnt--;
	}

	int k = 0;
	for (int i = 0; i < N; i++) {
		if (major == list[i]) {
			k++;
		}
	}

	if (k > (N >> 1)) cout << major << '\n'; 
	else cout << "SYJKGW\n";
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}