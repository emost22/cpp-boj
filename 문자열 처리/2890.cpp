#include <iostream>
using namespace std;

typedef struct team {
	int num;
	int dis;
}team;

team list[10];
char Map[51][51];
int R, C, idx, Rank[10];

void Swap(int x, int y) {
	team tmp = list[x];
	list[x] = list[y];
	list[y] = tmp;
}

void partition(int s, int e, int &pivot) {
	team p = list[s];
	int j = s;

	for (int i = s + 1; i <= e; i++) {
		if (list[i].dis < p.dis) {
			j++;

			Swap(i, j);
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

void func() {
	int cnt = 1;
	Rank[list[0].num] = cnt;
	int pre = list[0].dis;
	for (int i = 1; i < 9; i++) {
		if (list[i].dis != pre) {
			cnt++;
		}
		Rank[list[i].num] = cnt;

		pre = list[i].dis;
	}

	for (int i = 1; i <= 9; i++) {
		cout << Rank[i] << '\n';
	}
}

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> Map[i];
		for (int j = 0; j < C; j++) {
			if ('1' <= Map[i][j] && Map[i][j] <= '9') {
				list[idx].num = Map[i][j] - '0';
				list[idx++].dis = C - j;
				break;
			}
		}
	}

	quicksort(0, 8);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}