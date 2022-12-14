#include <iostream>
#include <string>
#include <vector>
#define A 350
#define B 250
#define C 400
#define SUM 55
using namespace std;

typedef struct Point {
	string name;
	int a, b, c;

	bool isBasicScore() {
		return a >= A * 3 / 10 && b >= B * 3 / 10 && c >= C * 3 / 10;
	}

	int getSum() {
		return (a + b + c) / 10;
	}
}Point;

vector<Point> v;
int N;

void func() {
	for (int i = 0; i < N; i++) {
		bool flag = v[i].isBasicScore();
		int sum = v[i].getSum();
		if (!flag || sum < SUM) {
			cout << v[i].name << ' ' << v[i].getSum() << " FAIL\n";
			continue;
		}

		cout << v[i].name << ' ' << v[i].getSum() << " PASS\n";
	}
}

void input() {
	string name;
	int a, b, c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> a >> b >> c;
		v.push_back({ name,a * 10,b * 10,c * 10 });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}