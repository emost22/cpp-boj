#include <iostream>
#include <string>
#include <vector>
#define MAX 26
using namespace std;
typedef long long ll;

string a, b, ans;
vector<ll> v;
bool chk[MAX], num[MAX];
ll alpha[MAX];
int N, M, len;

bool calc() {
	ll x = 0;
	for (int i = 0; i < N; i++) {
		x = x * 10LL + alpha[a[i] - 'A'];
	}

	ll y = 0;
	for (int i = 0; i < M; i++) {
		y = y * 10LL + alpha[b[i] - 'A'];
	}

	ll z = 0;
	for (int i = 0; i < len; i++) {
		z = z * 10LL + alpha[ans[i] - 'A'];
	}

	return x + y == z;
}

bool dfs(int idx) {
	if (idx == v.size()) {
		return calc();
	}

	for (int i = 0; i < 10; i++) {
		if (num[i]) continue;

		num[i] = true;
		alpha[v[idx]] = i;
		bool flag = dfs(idx + 1);
		alpha[v[idx]] = -1;
		num[i] = false;

		if (flag) return true;
	}

	return false;
}

void func() {
	if (dfs(0)) cout << "YES\n";
	else cout << "NO\n";
}

void init() {
	for (int i = 0; i < N; i++) {
		if (chk[a[i] - 'A']) continue;
		chk[a[i] - 'A'] = true;
		v.push_back(a[i] - 'A');
	}

	for (int i = 0; i < M; i++) {
		if (chk[b[i] - 'A']) continue;
		chk[b[i] - 'A'] = true;
		v.push_back(b[i] - 'A');
	}

	for (int i = 0; i < len; i++) {
		if (chk[ans[i] - 'A']) continue;
		chk[ans[i] - 'A'] = true;
		v.push_back(ans[i] - 'A');
	}
}

void input() {
	cin >> a >> b >> ans;
	N = a.size();
	M = b.size();
	len = ans.size();
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}