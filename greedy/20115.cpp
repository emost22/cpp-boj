#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

priority_queue<double> q;
int N;

void func() {
	cout << fixed;
	cout.precision(5);

	while (q.size() > 1) {
		double x = q.top();
		q.pop();
		double y = q.top();
		q.pop();

		if (x > y) q.push(x + y / 2.0);
		else q.push(x / 2.0 + y);
	}

	cout << q.top() << '\n';
}

void input() {
	double x;
	cin >> N;
	while (N--) {
		cin >> x;
		q.push(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}