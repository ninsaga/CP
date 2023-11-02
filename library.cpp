#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int fpd = 1; // fine per day
    string books[100];
    int due_date[100];
    int book_c = 0;

    while (true) {
        int choice;
        cout << "Menu: \n 1. Issue a book\n 2. Return a book\n 3. Exit\n Enter your choice" << endl;
        cin >> choice;

        if (choice == 1) {
            cin.ignore();
            string title;
            cout << "Enter the title of the book: ";
            getline(cin, title);

            if (book_c < 100) {
                books[book_c] = title;
                due_date[book_c] = book_c + 1;
                cout << "Book '" << title << "' has been issued." << endl;
                cout << "Due date: " << due_date[book_c] << " day(s) from today." << endl;
                book_c++;
            }
            else {
                cout << "The library is full. Cannot issue more books." << endl;
            }
        }
        else if (choice == 2) {
            cin.ignore();
            string title;
            cout << "Enter the title of the book to return: ";
            getline(cin, title);

            bool book_ret = false;
            int ret_d = 0;
            for (int i = 0; i < book_c; i++) {
                if (books[i] == title) {
                    book_ret = true;
                    cout << "Enter the return date (days from due date): ";
                    cin >> ret_d;

                    if (ret_d <= due_date[i]) {
                        cout << title << "' returned on time. No fines will be charged." << endl;
                    }
                    else {
                        int daysLate = ret_d - due_date[i];
                        int fine = daysLate * fpd;
                        cout << "Fine: " << daysLate << " days late: " << fine << endl;
                    }
                    for (int j = i; j < book_c - 1; j++) {
                        books[j] = books[j + 1];
                        due_date[j] = due_date[j + 1];
                    }

                    book_c--;
                    break;
                }
            }

            if (!book_ret) {
                cout << "The book is not found." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Exiting the Library System. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}