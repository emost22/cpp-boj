#include <iostream>
#include <string>
using namespace std;

string str = "SHIP NAME      CLASS          DEPLOYMENT IN SERVICE\nN2 Bomber      Heavy Fighter  Limited    21        \nJ-Type 327     Light Combat   Unlimited  1         \nNX Cruiser     Medium Fighter Limited    18        \nN1 Starfighter Medium Fighter Unlimited  25        \nRoyal Cruiser  Light Combat   Limited    4         ";

void print() {
	cout << str << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	print();

	return 0;
}