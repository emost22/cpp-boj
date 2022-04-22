#include <iostream>
#include <string>
#include <unordered_set>
#define MAX 100001
using namespace std;

typedef struct Chat {
	int time;
	string name;
}Chat;

unordered_set<string> s;
Chat chatList[MAX];
int timeTable[3];
int N;

int stringToInt(string str) {
	return (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[3] - '0') * 10 + (str[4] - '0');
}

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (chatList[i].time <= timeTable[0]) {
			s.insert(chatList[i].name);
		}
		else if (timeTable[1] <= chatList[i].time && chatList[i].time <= timeTable[2]) {
			if (s.find(chatList[i].name) == s.end()) continue;
			s.erase(chatList[i].name);
			ans++;
		}
	}

	cout << ans << '\n';
}

void input() {
	string str;
	for (int i = 0; i < 3; i++) {
		cin >> str;
		timeTable[i] = stringToInt(str);
	}

	for (int i = 0; cin >> str; i++) {
		int x = stringToInt(str);
		cin >> str;

		chatList[i] = { x,str };
		N = i;
	}
	N++;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}