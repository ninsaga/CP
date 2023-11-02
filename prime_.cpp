#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int choice, starting_range, end_range, number_p;
    while (true) {
        cout << "Menu: \n 1. Find primes in range\n 2. Check if prime\n 3. Exit Enter: " << endl;
        cin >> choice;
        if (choice == 1) {
            cin >> starting_range >> end_range;
            for (number_p = max(starting_range, 2); number_p <= end_range; number_p++) {
                bool p = number_p > 1;
                for (int i = 2; i * i <= number_p && p; i++) p = number_p % i;
                if (p) cout << number_p << ' ';
            }
            cout << endl;
        }
        else if (choice == 2) {
            cin >> number_p;
            bool p = number_p > 1;
            for (int i = 2; i * i <= number_p && p; i++) p = number_p % i;
            cout << number_p << (p ? " is prime." : " is not prime.") << endl;
        }
        else if (choice == 3) {
            cout << "Goodbye!" << endl;
            break;
        }
        else cout << "Invalid choice. Select a valid option." << endl;
    }
    return 0;
}
