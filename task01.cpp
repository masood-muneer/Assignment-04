#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct book_details
{
    string book_id;
    string title;
    string author;
    int quantity;
} 
book[100];

ofstream file("Books.txt", ios::app);


void add_new_book() 
{
    static int i = 0;
    cin.ignore();
    cout<<"Enter book id:";
    getline(cin, book[i].book_id);
    file<<book[i].book_id<<endl;
    cout<<"Enter book title:";
    getline(cin, book[i].title);
    file<<"Book Title: "<<book[i].title<<endl;
    cout<<"Enter book author name:";
    getline(cin, book[i].author);
    file<<book[i].author<<endl;
    cout<<"Enter book quantity:";
    cin>>book[i].quantity;
    file<<book[i].quantity<<endl;
    file<<"========================"<<endl;
    cout<<"Book added successfully"<<endl;
    i++;
}

void load_books() 
{
    ifstream file("Books.txt");
    if (!file) 
    {
        cout<<"Error opening file"<<endl;
        return;
    }

    int i = 0;
    while (!file.eof() && i < 100) {
        getline(file, book[i].book_id);
        getline(file, book[i].title);
        getline(file, book[i].author);
        file>>book[i].quantity;
        file.ignore(); // Ignore the newline character after the quantity
        i++;
    }
    file.close();
    cout<<"Books loaded successfully from file"<<endl;
}

void search_book()
{
    load_books();
    while (true)
        {
        string search;
        cout<<"Enter book title:";
        cin.ignore();
        getline(cin, search);
        for (int i = 0; i < 100; i++)
        {
            if (search == book[i].title)
            {
                cout<<"Book id:"<<book[i].book_id<<endl;
                cout<<"Book title:"<<book[i].title<<endl;
                cout<<"Book author:"<<book[i].author<<endl;
                cout<<"Book quantity:"<<book[i].quantity<<endl;
                return;
            }
        }
        cout<<"Book not found"<<endl;
        }
    
}

void display_books()
{
    load_books();
    for (int i = 0; i < 100; i++)
    {
        if (book[i].title != "")
        {
            cout<<"Book id:"<<book[i].book_id<<endl;
            cout<<"Book title:"<<book[i].title<<endl;
            cout<<"Book author:"<<book[i].author<<endl;
            cout<<"Book quantity:"<<book[i].quantity<<endl;
        }
    }
    
}
void menu()
{
    int choice;
    while (true)
    {
        cout<<"Welcome to the library management system"<<endl;
        cout<<"1. Add new book"<<endl;
        cout<<"2. Search book"<<endl;
        cout<<"3. Display all books"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            add_new_book();
            break;
        case 2:
            search_book();
            break;
        case 3:
            display_books();
            break;
        case 4:
            return;
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
}
int main()
{
    menu();
}
