#include <iostream>
#include <cstring>
#define MOD 100
using namespace std;

typedef struct name {
	char ch[21];
	int p;
}name;

name list[50];
int N;
char myname[21];

void Swap(int x, int y) {
	name tmp = list[x];
	list[x] = list[y];
	list[y] = tmp;
}

void partition(int s, int e, int &pivot) {
	name p = list[s];
	int j = s;

	for (int i = s + 1; i <= e; i++) {
		if (list[i].p > p.p) {
			j++;

			Swap(i, j);
		}
		else if (list[i].p == p.p) {
			if (strcmp(list[i].ch, p.ch) < 0) {
				j++;

				Swap(i, j);
			}
		}
	}

	pivot = j;
	Swap(pivot, s);
}

void quicksort(int s, int e) {
	if (s < e) {
		int pivot = s;

		partition(s, e, pivot);
		quicksort(s, pivot - 1);
		quicksort(pivot + 1, e);
	}
}

int sol(int idx) {
	int L = 0, O = 0, V = 0, E = 0;
	for (int i = 0; myname[i]; i++) {
		if (myname[i] == 'L') L++;
		else if (myname[i] == 'O') O++;
		else if (myname[i] == 'V') V++;
		else if (myname[i] == 'E') E++;
	}

	for (int i = 0; i < list[idx].ch[i]; i++) {
		if (list[idx].ch[i] == 'L') L++;
		else if (list[idx].ch[i] == 'O') O++;
		else if (list[idx].ch[i] == 'V') V++;
		else if (list[idx].ch[i] == 'E') E++;
	}

	return ((L + O)*(L + V)*(L + E)*(O + V)*(O + E)*(V + E)) % MOD;
}

void input() {
	cin >> myname >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].ch;
		list[i].p = sol(i);
	}
	quicksort(0, N - 1);

	cout << list[0].ch << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}