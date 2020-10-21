#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> v;
bool xzero, chk;
int N, cnt;
pair<int, int> p[200];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + N);

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double a = p[j].first - p[i].first;
			double b = p[j].second - p[i].second;

			if (a == 0) {
				if (xzero) continue;
				xzero = true;
				cnt++;
			}
			else {
				for (int k = 0; k < v.size(); k++) {
					if (v[k] == b / a) {
						chk = true;
						break;
					}
				}
				if (!chk) {
					cnt++;
					v.push_back(b / a);
				}
				chk = false;
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}