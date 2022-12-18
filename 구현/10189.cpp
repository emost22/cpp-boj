#include <iostream>
#include <string>
using namespace std;

string str = "#  # #### #### #  #\n#### #  # #  # # #\n#### #  # #  # # #\n#  # #### #### #  #\n";

void func() {
    cout << str << '\n';
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    func();

    return 0;
}