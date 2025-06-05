#include <iostream>
#include <string>
using namespace std;

int main() {
    char ch;
    int ans = 0;
    cout << "Enter any character:";
    while (cin >> ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ans++;
        }
    }
    cout << "yuanyin have" << ans << endl;
}