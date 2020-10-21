#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

pair<string, int> str[100000];
pair<int, string> str2[100000];

int binarysearch(int s, int e, string x) {
	int m = (s + e) / 2;

	if (str[m].first == x) return str[m].second;
	else if (str[m].first > x) return binarysearch(s, m - 1, x);
	else return binarysearch(m + 1, e, x);
}

string binarysearch(int s, int e, int x) {
	int m = (s + e) / 2;

	if (str2[m].first == x) return str2[m].second;
	else if (str2[m].first > x) return binarysearch(s, m - 1, x);
	else return binarysearch(m + 1, e, x);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	string data;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> data;
		str[i] = { data, i + 1 };
		str2[i] = { i + 1, data };
	}
	sort(str, str + N);
	sort(str2, str2 + N);

	for (int i = 0; i < M; i++) {
		cin >> data;

		if (data[0] >= '0' && data[0] <= '9') {
			int a = stoi(data);
			cout << binarysearch(0, N - 1, a) << '\n';
		}
		else {
			cout << binarysearch(0, N - 1, data) << '\n';
		}
	}

	return 0;
}