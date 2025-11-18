#include <iostream>
#define MAX 100
using namespace std;
typedef pair<int, int> pii;

pii list1[MAX], list2[MAX];
int s1, s2;

void func() {
	for (int i = 0; i < s1; i++) {
		if (list1[i].first == list1[i].second) continue;
		cout << "Wrong Answer\n";
		return;
	}

	for (int i = 0; i < s2; i++) {
		if (list2[i].first == list2[i].second) continue;
		cout << "Why Wrong!!!\n";
		return;
	}

	cout << "Accepted\n";
}

void input() {
	cin >> s1 >> s2;
	for (int i = 0; i < s1; i++) {
		cin >> list1[i].first >> list1[i].second;
	}

	for (int i = 0; i < s2; i++) {
		cin >> list2[i].first >> list2[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}