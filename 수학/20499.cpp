#include <cstdio>
using namespace std;

int k, d, a;

void func() {
	if (k + a < d || !d) printf("hasu\n");
	else printf("gosu\n");
}

void input() {
	scanf("%d/%d/%d", &k, &d, &a);
}

int main() {
	input();
	func();

	return 0;
}