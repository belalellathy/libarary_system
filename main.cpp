#include <iostream>
#include<string>
#include<vector>
#include <fstream>
#include <sstream>


using namespace std;
void book_read(vector<vector<string>>& Books1);
void book_write(vector<vector<string>>& Books1);
void books_displyment1(vector<vector<string>>& Books1);
void Books_adding1(vector<vector<string>>& Books1);
void Books_update(vector<vector<string>>& Books1);
void books_find(vector<vector<string>>&Books1);
void books_borrow(vector<vector<string>>&Books1);
void books_return(vector<vector<string>>&Books1);
void books_remove(vector<vector<string>>&Books1);
vector<vector<string>> Books1 (1,vector<string>(5));
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
        case 1:{
           book_read(Books1);
           cout<<Books1.size();
           Books_adding1(Books1);
            cout << "Book added successfully " << endl;
            books_displyment1(Books1);
            break;}
        case 2:
            book_read(Books1);
            books_displyment1(Books1);
            break;
        case 3:
            book_read(Books1);
            Books_update(Books1);
            books_displyment1(Books1);
            break;
        case 4:
            book_read(Books1);
            books_find(Books1);

            break;
        case 5:
            book_read(Books1);

            books_borrow(Books1);

            cout << "\nTotal Price:" << check_out<<endl;
            break;
        case 6:
            books_return(Books1);
            break;
        case 7:
            books_remove(Books1);
           // book_remove(Books, rows);
           // books_displyment(Books, rows);
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



void books_remove(vector<vector<string>>&Books1){
    book_read(Books1);
    string id;
    cout << "Enter ID of the book you want to remove: ";
    cin >> id;
    int row_num;

    bool findd = false;
    while (findd != true) {

        for (int i = 0; i < Books1.size(); i++) {
            if (id == Books1[i][0]) {
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
    Books1.erase(Books1.begin()+row_num);
    book_write(Books1);
}

void books_find(vector<vector<string>>&Books1){
     string id;
 cout << "Enter ID of the book you want to find: ";
 cin >> id;

 bool findd = false;
 while (findd != true) {


     for (int i = 0; i < Books1.size(); i++) {
         if (id == Books1[i][0]) {
             cout << Books1[i][0] << " ";
             cout << Books1[i][1] << " ";
             cout << Books1[i][2] << " ";
             cout << Books1[i][3]<<" ";
             cout << Books1[i][4];
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
void books_borrow(vector<vector<string>>&Books1){
   string id;
    cout << "enter Id: ";
    cin >> id;
    bool findd = false;
    while (findd != true) {
        for (int i = 0; i < Books1.size(); i++) {
            if (id == Books1[i][0]) {
                if (Books1[i][3] == "Avalibale") {
                    cout << "Book borrowed succefully";
                    Books1[i][3] = "unavalible";
                    check_out += stoi(Books1[i][4]);
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
     fstream Myfile("Books.txt",ios::out);
        for(int i=0;i<Books1.size();i++){
            for(int j=0;j<Books1[i].size();j++){
                Myfile<<Books1[i][j]<<"|";
            }
            Myfile<<endl;


        }

}


void books_return(vector<vector<string>>&Books1){
    book_read(Books1);
    string id;
    cout << "enter Id: ";
    cin >> id;
    bool findd = false;
    while (findd != true) {
        for (int i = 0; i < Books1.size(); i++) {

            if (id == Books1[i][0]) {
                if (Books1[i][3] == "unavalible") {
                    cout << "Book returned succefully";
                    Books1[i][3] = "Avalibale";
                }
                else {
                    cout << "\nBook is already returned\n";
                }
                findd = true;
                break;
            }
            else{
                continue;
                }
        }
        if(findd==false){
            cout<<"wrong id "<<"please enter valid id: ";
            cin>>id;
        }
    }
    book_write(Books1);

}

void books_displyment1(vector<vector<string>>& Books1) {
    // Reading data from file
    for (int i = 0; i < Books1.size(); i++) {
        for (int j = 0; j < Books1[i].size(); j++) {
            cout << Books1[i][j]<<" ";
        }
        cout<<endl;
    }
}
void book_write(vector<vector<string>>& Books1){
     fstream Myfile("Books.txt",ios::out);
        for(int i=0;i<Books1.size();i++){
            for(int j=0;j<Books1[i].size();j++){
                Myfile<<Books1[i][j]<<"|";
            }
            Myfile<<endl;


        }
     Myfile.close();
}
void Books_adding1(vector<vector<string>>& Books1){
    int row_num;
    bool findd;
    string id;
    cout << "enter Id: ";
    cin>>id;
    if(Books1.size()>0&&Books1[0][0]!=" "){
    findd = false;
    while (findd ==false) {
            for (int i = 0; i <= Books1.size(); i++) {

            if (id == Books1[i][0]) {
                cout << "ID already exist\n" ;
                break;
               // cin >> id;
               // i=0;
            }
            else {
             int s=Books1.size();
            s-=1;
            //cout<<i;
            if(i==s){
                findd=true;
                break;
            }
            }
        }
        if(findd==false){
        cout<< "please enter another ID: ";
        cin>>id;

        }
    }
    }

vector<string>sub(5);

        sub[0] = id;
        cout << "Name: ";
       cin >> sub[1];
        cout << "Author: ";
        cin >> sub[2];
        sub[3] = "Avalibale";
       // cout << Books[i][3]<<endl;
        cout << "Price: ";
        cin >> sub[4];


    Books1.push_back(sub);
    sub.clear();
    book_write(Books1);
}





void Books_update(vector<vector<string>>& Books1){
int row_num;
    string id;
    cout << "enter Id: ";
    cin >> id;
    bool findd = false;
    while (findd != true) {
        for (int i = 0; i < Books1.size(); i++) {
            if (id == Books1[i][0]) {
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

    for (int i = row_num; i == row_num; i++) {
        Books1[i][0] = id;
        cout << "Name: ";
        cin >> Books1[i][1];
        cout << "Author: ";
        cin >> Books1[i][2];
        Books1[i][3] = "Avalibale";
       // cout << Books[i][3]<<endl;
        cout << "Price: ";
        cin>>Books1[i][4];


    }
    book_write(Books1);
    }


void book_read(vector<vector<string>>& Books1){
     Books1.clear();
    string part;
     vector<string>parts;
    string s;
    fstream file;
    file.open("Books.txt",ios::in);
    while(getline(file,s)){
        stringstream ss(s);
        while(getline(ss,part,'|')){
            parts.push_back(part);

        }
         Books1.push_back(parts);
         parts.clear();
    }

    file.close();
}


