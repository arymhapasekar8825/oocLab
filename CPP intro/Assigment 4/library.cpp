#include <iostream>
#include <string>

using namespace std;

class LibraryBook {
private:
    string title;
    string author;
    string isbn;
    bool isIssued;

public:
    // Simple parameterized constructor
    LibraryBook(string bTitle, string bAuthor, string bIsbn) {
        title = bTitle;
        author = bAuthor;
        isbn = bIsbn;
        isIssued = false; // Initially the book is available
    }

    // Function to issue the book
    void issueBook() {
        if (isIssued) {
            cout << "\nError: \"" << title << "\" is already issued.\n";
        } else {
            isIssued = true;
            cout << "\nSuccess: \"" << title << "\" has been issued.\n";
        }
    }

    // Function to return the book
    void returnBook() {
        if (!isIssued) {
            cout << "\nError: \"" << title << "\" is not currently issued.\n";
        } else {
            isIssued = false;
            cout << "\nSuccess: \"" << title << "\" has been returned.\n";
        }
    }

    // Function to display book details
    void displayBook() {
        cout << "\n--- Book Details ---\n";
        cout << "Title  : " << title << "\n";
        cout << "Author : " << author << "\n";
        cout << "ISBN   : " << isbn << "\n";
        cout << "Status : " << (isIssued ? "Issued" : "Available") << "\n";
        cout << "--------------------\n";
    }
};

int main() {
    string bTitle, bAuthor, bIsbn;

    // Get input from user
    cout << "Enter Book Title: ";
    getline(cin, bTitle);

    cout << "Enter Author Name: ";
    getline(cin, bAuthor);

    cout << "Enter ISBN: ";
    getline(cin, bIsbn);

    // Initializing object with simple parameterized constructor
    LibraryBook book(bTitle, bAuthor, bIsbn);

    int choice = 0;
    do {
        cout << "\n=== Library Menu ===";
        cout << "\n1. Display Book Details";
        cout << "\n2. Issue Book";
        cout << "\n3. Return Book";
        cout << "\n4. Exit";
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                book.displayBook();
                break;
            case 2:
                book.issueBook();
                break;
            case 3:
                book.returnBook();
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please choose between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}