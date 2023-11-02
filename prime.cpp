#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int c, s, e, n;
    while (true) {
        cout << "Menu: 1. Find primes in range 2. Check if prime 3. Exit Enter: ";
        cin >> c;
        if (c == 1) {
            cin >> s >> e;
            for (n = max(s, 2); n <= e; n++) {
                bool p = n > 1;
                for (int i = 2; i * i <= n && p; i++) p = n % i;
                if (p) cout << n << ' ';
            }
            cout << endl;
        }
        else if (c == 2) {
            cin >> n;
            bool p = n > 1;
            for (int i = 2; i * i <= n && p; i++) p = n % i;
            cout << n << (p ? " is prime." : " is not prime.") << endl;
        }
        else if (c == 3) {
            cout << "Goodbye!" << endl;
            break;
        }
        else cout << "Invalid choice. Select a valid option." << endl;
    }
    return 0;
}
