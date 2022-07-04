#include <cstdio>
#include <vector>
#define MAX 21
using namespace std;

vector<int> v;
int N, M;

void func() {
	while (M--) {
		vector<int> nv;
		int vsize = v.size();
		for (int i = 1; i < vsize; i++) {
			nv.push_back(v[i] - v[i - 1]);
		}

		v = nv;
		nv.clear();
	}

	int vsize = v.size();
	printf("%d", v[0]);
	for (int i = 1; i < vsize; i++) {
		printf(",%d", v[i]);
	}
	printf("\n");
}

void input() {
	int x;
	scanf("%d %d", &N, &M);
	scanf("%d", &x);
	v.push_back(x);
	for (int i = 1; i < N; i++) {
		scanf(",%d", &x);
		v.push_back(x);
	}
}

int main() {
	input();
	func();

	return 0;
}