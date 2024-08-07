#include <iostream>
#include<string>

using namespace std;
void books_adding(string Books[][4], int& rows);
void books_displyment(string Books[][4], int rows);
void book_update(string Books[][4], int rows);
void Book_find(string Books[][4], int rows);
void book_borrow(string Books[][4], int rows);
void book_return(string Books[][4], int rows);
void book_remove(string[][4], int& rows);
int rows = 1;
string Books[100][4] = {
    {
        "1","Diary_of_a_wimpy_kid","Jeff_kinney","Avalibale"
    }

};
int book_price[100]{ 50 };
int check_out = 0;
int main()
{

    int choice;
    do {

        cout << "\nMenu:" << endl;
        cout << "1.Add Book \n2.Display books\n3.Update Book\n4.Find book\n5.Borrow a book\n6.Book return\n7.Book remove\n8.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Add books in form of \n" << "ID  Name Author " << endl;
            rows++;
            books_adding(Books, rows);
            cout << "Book added successfully " << endl;
            books_displyment(Books, rows);

            break;
        case 2:
            books_displyment(Books, rows);
            break;
        case 3:
            book_update(Books, rows);
            break;
        case 4:
            Book_find(Books, rows);
            break;
        case 5:
            book_borrow(Books, rows);
            cout << "\nTotal Price:" << check_out;
            break;
        case 6:
            book_return(Books, rows);
            break;
        case 7:
            book_remove(Books, rows);
            books_displyment(Books, rows);
            break;
        case 8:
            cout << "Exiting... See you soon, " << "!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
            break;
        }
    } while (choice != 8);
}







void books_displyment(string Books[][4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            cout << Books[i][j] << " ";
        }
        cout << book_price[i];
        cout << endl;
    }


}
void book_update(string Books[][4], int rows) {

    int row_num;
    string id;
    cout << "enter Id: ";
    cin >> id;
    bool findd = false;
    while (findd != true) {
        for (int i = 0; i < rows; i++) {
            if (id == Books[i][0]) {
                row_num = i;
                findd = true;
                break;
            }
            else
                continue;
        }
        if (findd == false) {
            cout << "invalid id \n" << "enter another id: ";
            cin >> id;


        }
    }
    cout << "Add books in form of \n" << "ID  Name Author Price " << endl;
    for (int i = row_num; i == row_num; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> Books[i][j];

        }
        Books[i][3] = "Avalibale";
        cin >> book_price[i];


    }

}


void books_adding(string Books[][4], int& rows) {
    int row_num;
    bool findd;
    string id;
    cout << "enter Id: ";
    cin >> id;
    findd = false;
    while (findd != true) {
        cin >> id;

        for (int i = 0; i < rows; i++) {
            if (id == Books[i][0]) {
                cout << "ID already exist\n" << "please enter another ID: ";
                cin >> id;
            }
            else {
                findd = true;
                row_num = i;
            }
        }
    }


    for (int i = row_num; i < rows; i++) {


        Books[i][0] = id;
        cout << "Name: ";
        cin >> Books[i][1];
        cout << "Author: ";
        cin >> Books[i][2];
        Books[i][3] = "Avalibale";
       // cout << Books[i][3]<<endl;
        cout << "Price: ";
        cin >> book_price[i];

        break;



    }

}
void Book_find(string Books[][4], int rows) {
    string id;
    cout << "Enter ID of the book you want to find: ";
    cin >> id;

    bool findd = false;
    while (findd != true) {
        cin >> id;

        for (int i = 0; i < rows; i++) {
            if (id == Books[i][0]) {
                cout << Books[i][0] << " ";
                cout << Books[i][1] << " ";
                cout << Books[i][2] << " ";
                cout << Books[i][3];
                cout << book_price[i];
                findd = true;
                break;
            }
            else
                continue;

        }
        if (findd == false) {
            cout << "invalid id \n" << "enter another id: ";
            cin >> id;
        }


    }
}

void book_borrow(string Books[][4], int rows) {
    string id;
    cout << "enter Id: ";
    cin >> id;
    bool findd = false;
    while (findd != true) {
        if (id.size() > 1) {
            cout << "invalid id " << "please enter another id: ";
            cin >> id;
        }
        for (int i = 0; i < rows; i++) {
            if (id == Books[i][0]) {
                if (Books[i][3] == "Avalibale") {
                    cout << "Book borrowed succefully";
                    Books[i][3] = "unavalible";
                    check_out += book_price[i];
                }
                else {
                    cout << "Book is already Borrowed";
                }


                findd = true;
                break;
            }
            else
                continue;
        }
        if (findd == false) {
            cout << "invalid id \n" << "enter another id: ";
            cin >> id;
        }

    }


}
void book_return(string Books[][4], int rows) {
    int row_num;
    string id;
    cout << "enter Id: ";
    cin >> id;
    bool findd = false;
    while (findd != true) {
        cin >> id;
        for (int i = 0; i < rows; i++) {
            if (id == Books[i][0]) {
                if (Books[i][3] == "unavalible") {
                    cout << "Book returned succefully";
                    Books[i][3] = "Avalibale";
                }
                else {
                    cout << "Book is already returned";
                }
                findd = true;
                break;
            }
            else
                continue;
        }
    }


}
void book_remove(string[][4], int& rows) {
    string id;
    cout << "Enter ID of the book you want to remove: ";
    cin >> id;
    int row_num;

    bool findd = false;
    while (findd != true) {
        cin >> id;
        for (int i = 0; i < rows; i++) {
            if (id == Books[i][0]) {
                row_num = i;
                findd = true;
                break;
            }
            else
                continue;

        }
        if (findd == false) {
            cout << "invalid id \n" << "enter another id: ";
            cin >> id;
        }


    }
    for (int i = row_num; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            Books[i][j] = Books[i + 1][j];
        }
    }
    rows--;
    cout << "Book removed succefuly ";

}




