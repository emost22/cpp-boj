#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A, B;
int ALength, BLength;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B;
	ALength = A.size();
	BLength = B.size();
	while (ALength != BLength) {
		if (B[BLength - 1] == 'A') {
			B.pop_back();
		}
		else {
			B.pop_back();
			reverse(B.begin(), B.end());
		}
		BLength--;
	}

	if (!A.compare(B)) cout << "1\n";
	else cout << "0\n";

	return 0;
}