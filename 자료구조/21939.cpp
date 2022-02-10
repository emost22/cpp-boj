#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#define MAX 100001
using namespace std;
typedef pair<int, int> pi;

priority_queue<pi, vector<pi>, less<pi> > mxq;
priority_queue<pi, vector<pi>, greater<pi> > mnq;
int levellist[MAX];
int N, M;

void func() {
	string type;
	int x, y;
	cin >> M;
	while (M--) {
		cin >> type;
		if (type == "add") {
			cin >> x >> y;
			mxq.push({ y,x });
			mnq.push({ y,x });
			levellist[x] = y;
		}
		else {
			cin >> x;
			if (type == "recommend") {
				if (x == 1) {
					while (1) {
						int p = mxq.top().second;
						int l = mxq.top().first;
						if (levellist[p] == l) break;
						mxq.pop();
					}

					cout << mxq.top().second << '\n';
				}
				else {
					while (1) {
						int p = mnq.top().second;
						int l = mnq.top().first;
						if (levellist[p] == l) break;
						mnq.pop();
					}

					cout << mnq.top().second << '\n';
				}
			}
			else {
				levellist[x] = 0;
			}
		}
	}
}

void input() {
	int P, L;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		mxq.push({ L,P });
		mnq.push({ L,P });
		levellist[P] = L;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	
	return 0;
}