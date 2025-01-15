#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct patient {
    int id;
    string name ;
    int age;
    string disease;
    int room;
} patient1;

void add_patient ();
void search_patient ();
void display_patient ();
void save_patient ();
void main_menu ();

int main()
{
    main_menu();
    return 0;

}

void main_menu()
{
    int choice;
    cout<< "-----------------------------------"<<endl;
    cout << "Hospital Patient Management System" << endl;
    cout << "1. Add new patient" << endl;
    cout << "2. Search for a patient" << endl;
    cout << "3. Display all patients" << endl;
    cout << "4. Exit" << endl;
    
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
            add_patient();
            break;
        case 2:
            search_patient();
            break;
        case 3:
            display_patient();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}

void add_patient()
{
    ofstream file;
    cout<< "-----------------------------------"<<endl;
    cout << "Add new patient" << endl;
    file.open("patient.txt", ios::app);
    cout << "Enter patient ID: ";
    cin >> patient1.id;
    cout << "Enter patient name: ";
    cin >> patient1.name;
    cout << "Enter patient age: ";
    cin >> patient1.age;
    cout << "Enter patient disease: ";
    cin >> patient1.disease;
    cout << "Enter patient room number: ";
    cin >> patient1.room;
    file << patient1.id << " " << patient1.name << " " << patient1.age << " " << patient1.disease << " " << patient1.room << endl;
    file.close();
    main_menu();
}

void search_patient()
{
    ifstream file;
    file.open("patient.txt", ios::in);
    int id;
    cout<< "-----------------------------------"<<endl;
    cout << "Enter patient ID to search: ";
    cin >> id;
    while (file >> patient1.id >> patient1.name >> patient1.age >> patient1.disease >> patient1.room)
    {
        if (id == patient1.id){
            cout << "Patient ID: " << patient1.id << endl;
            cout << "Patient Name: " << patient1.name << endl;
            cout << "Patient Age: " << patient1.age << endl;
            cout << "Patient Disease: " << patient1.disease << endl;
            cout << "Patient Room Number: " << patient1.room << endl;
            file.close();
            main_menu();
        }
    }
    cout << "Patient ID not found" << endl;
    file.close();
    main_menu();
}

void display_patient()
{
    ifstream file;
    cout<< "-----------------------------------"<<endl;
    file.open("patient.txt", ios::in);
    while (file >> patient1.id >> patient1.name >> patient1.age >> patient1.disease >> patient1.room){
        cout << "Patient ID: " << patient1.id << endl;
        cout << "Patient Name: " << patient1.name << endl;
        cout << "Patient Age: " << patient1.age << endl;
        cout << "Patient Disease: " << patient1.disease << endl;
        cout << "Patient Room Number: " << patient1.room << endl;
    }
    file.close();
    main_menu();
}

void save_patient()
{
    ifstream file;
    file.open("patient.txt", ios::in);
    ofstream file1;
    file1.open("patient1.txt", ios::out);
    while (file >> patient1.id >> patient1.name >> patient1.age >> patient1.disease >> patient1.room)
    {
        file1 << patient1.id << endl;
        file1<< patient1.name << endl;
        file1<< patient1.age << endl;
        file1<< patient1.disease << endl;
        file1 << patient1.room << endl;
    }
    file.close();
    file1.close();
    main_menu();
}
