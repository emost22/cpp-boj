#include <iostream>
#include <iomanip>
using namespace std;

int x_direct[] = { 0,0,1,-1 }, y_direct[] = { 1,-1,0,0 };
bool visit[40][40];
double per[4], result;
int M, E, W, N, S;

void dfs(int x, int y, double p) {
	visit[x][y] = true;

	if (M == 0) {
		result += p;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (visit[xx][yy]) continue;

		M--;
		dfs(xx, yy, p * per[i]);
		M++;
		visit[xx][yy] = false;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int X = 20, Y = 20;

	cin >> M >> E >> W >> N >> S;

	per[0] = E * 0.01;
	per[1] = W * 0.01;
	per[2] = N * 0.01;
	per[3] = S * 0.01;

	dfs(X, Y, 1.0);

	cout << fixed;
	cout << setprecision(10) << result << '\n';

	return 0;
}