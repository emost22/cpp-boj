#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> D;
int visit[300000], a, sum, mul = 1;

int dfs(int A, int P) {
	D.push_back(A);
	visit[A] = 1;
	while (1) {
		if (A > 99999) a = 100000;
		else if (A > 9999) a = 10000;
		else if (A > 999) a = 1000;
		else if (A > 99) a = 100;
		else if (A > 9) a = 10;
		else a = 1;
		
		while (a) {
			for (int i = 0; i < P; i++) {
				mul *= A / a;
			}
			sum += mul;
			A %= a;
			a /= 10;
			mul = 1;
		}

		D.push_back(sum);
		visit[sum]++;
		if (visit[sum] == 2) {
			D.pop_back();
			while (visit[D.back()] != 2) {
				D.pop_back();
			}
			D.pop_back();
			break;
		}
		A = sum;
		sum = 0;
	}

	return D.size();
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, P;
	cin >> A >> P;

	cout << dfs(A, P) << '\n';

	return 0;
}