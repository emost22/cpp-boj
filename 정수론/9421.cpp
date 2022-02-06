#include <iostream>
#include <vector>
#include <set>
#define MAX 1000001
#define SUM 500
using namespace std;

vector<int> list;
bool sosu[MAX], chk[SUM];
int N;

void func() {
	for (auto x : list) {
		int n = x;
		int ret = 0;
		while (n) {
			ret += ((n % 10) * (n % 10));
			n /= 10;
		}

		if (chk[ret]) cout << x << '\n';
	}
}

void init() {
	for (int i = 2; i * i <= N; i++) {
		if (sosu[i]) continue;
		for (int j = i; i * j <= N; j++) {
			sosu[i * j] = true;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (sosu[i]) continue;
		list.push_back(i);
	}

	for (int i = 1; i < SUM; i++) {
		int n = i;
		
		set<int> s;
		while (1) {
			if (n == 1) {
				chk[i] = true;
				break;
			}
			s.insert(n);
			
			int ret = 0;
			int m = n;
			while (m) {
				ret += (m % 10) * (m % 10);
				m /= 10;
			}

			n = ret;

			if (s.find(ret) != s.end()) break;
		}
		s.clear();
	}
}

void input() {
	cin >> N;
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}