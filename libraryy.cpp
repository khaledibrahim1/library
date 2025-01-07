#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string name;
    int price;
    vector<string> borrowers;
};

void printMenu() {
    cout << " ----------------------------------------------------------------------------------- \n";
    cout << "|       USER NAME        |         NAMES OF BOOKS         |     LIBRARY WORKERS     |\n";
    cout << " -----------------------------------------------------------------------------------  \n";
    cout << " --------------------------------------------\n";
    cout << "|1- Search for a book                        |\n";
    cout << "|2- Add a book                               |\n";
    cout << "|3- Update book details                      |\n";
    cout << "|4- Add borrower for a book                  |\n";
    cout << "|5- Show borrowers of a book                 |\n";
    cout << "|6- Exit                                     |\n";
    cout << " --------------------------------------------\n";
}

void addBook(vector<Book>& library) {///////0
    Book newBook;
    cout << "Enter the name of the book: ";
    cin.ignore();
    getline(cin, newBook.name); // Read the entire line including spaces
    cout << "Enter the price of the book: ";
    cin >> newBook.price;
    library.push_back(newBook);
    cout << "Book added successfully!\n";
}

void searchBook(const vector<Book>& library) {
    string searchName;
    cout << "Enter the name of the book to search for: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (const auto& book : library) {
        if (book.name == searchName) {
            cout << "Book found!\n";
            cout << "Name: " << book.name << ", Price: $" << book.price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found in the library.\n";
    }
}

void updateBook(vector<Book>& library) {
    string searchName;
    cout << "Enter the name of the book to update: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (auto& book : library) {
        if (book.name == searchName) {
            cout << "Enter new price for the book: ";
            cin >> book.price;
            cout << "Book details updated successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found in the library. Cannot update.\n";
    }
}

void addBorrower(vector<Book>& library) {
    string searchName;
    cout << "Enter the name of the book to add a borrower: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (auto& book : library) {
        if (book.name == searchName) {
            string borrowerName;
            cout << "Enter the name of the borrower: ";
            getline(cin, borrowerName);
            book.borrowers.push_back(borrowerName);
            cout << borrowerName << " added as borrower for " << book.name << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found in the library. Cannot add borrower.\n";
    }
}

void showBorrowers(const vector<Book>& library) {
    string searchName;
    cout << "Enter the name of the book to show borrowers: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (const auto& book : library) {
        if (book.name == searchName) {
            if (book.borrowers.empty()) {
                cout << "No borrowers for " << book.name << " yet.\n";
            }
            else {
                cout << "Borrowers of " << book.name << ":\n";
                for (const auto& borrower : book.borrowers) {
                    cout << "- " << borrower << endl;
                }
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found in the library. Cannot show borrowers.\n";
    }
}

int main() {
    vector<Book> library;
    int choice;

    do {
        printMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1:
            searchBook(library);
            break;
        case 2:
            addBook(library);
            break;
        case 3:
            updateBook(library);
            break;
        case 4:
            addBorrower(library);
            break;
        case 5:
            showBorrowers(library);
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
