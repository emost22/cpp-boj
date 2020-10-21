#include <cstdio>
#define PI 3.141592
using namespace std;

double d1, d2;

int main() {
	scanf("%lf %lf", &d1, &d2);
	printf("%.6lf\n", d1 * 2.0 + 2.0 * PI * d2);

	return 0;
}