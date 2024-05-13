/* Q. Sequential File: The students’ club members (MemberID, name, phone,
email) list is to be maintained. The common operations performed
include these: add member, search member, delete member, and update
the information. Write a menu driven C++ program that uses file
operation to implement the same and perform all operations. */

#include <bits/stdc++.h>
using namespace std;

void addStudent()
{
    fstream f("club.txt", ios::app);
    cout << "Enter the student details:\n";
    string id;
    string name;
    string phone;
    string email;
    cout << "Member id: ";
    getline(cin, id);

    // check for duplicates
    ifstream checkfile("club.txt");
    string line;
    bool duplicate = false;
    while (getline(checkfile, line))
    {
        if (line.find(id) != string::npos)
        {
            duplicate = true;
            break;
        }
    }
    checkfile.close();
    if (duplicate)
    {
        cout << "Member with this id already exis\n";
        return;
    }

    cout << "Name: ";
    getline(cin, name);
    cout << "Phone: ";
    getline(cin, phone);
    cout << "Email: ";
    getline(cin, email);
    f << left << setw(20) << id << setw(20) << name << setw(20) << phone << setw(20) << email << endl;
    cout << "Student added successfully\n";
    f.close();
    return;
}

void searchStudent()
{
    cout << "Member ID: ";
    string id;
    cin >> id;

    ifstream f("club.txt");
    string line;
    bool found = false;

    while (getline(f, line)) 
    {
        if (line.find(id) != string::npos)
        {
            found = true;
            cout << "Student found\n\n";
            cout << line << endl;
            cout << endl;
            break;
        }
    }

    f.close();

    if (!found)
    {
        cout << "Student not found\n";
        return;
    }
}

void deleteStudent()
{
    ifstream f("club.txt");
    string line;
    string id;
    cout << "Member ID: ";
    cin >> id;

    bool found = false;
    while (getline(f, line))
    {
        if (line.find(id) != string::npos) 
        {
            found = true;
            break;
        }
    }

    f.close();

    if (found)
    {
        string filedata;
        string line;
        fstream f1("club.txt");
        while(getline(f1, line))
        {
            if(line.find(id) == string::npos)
            {
                filedata += line;
                filedata += "\n";
            }
        }
        f1.close();

        ofstream f("club.txt", ios::out);
        f << filedata;
        f.close();
        cout << "Student deleted successfully\n";
    }

    else 
    {
        cout << "Student not found\n";
    }
}

void updateStudent()
{
    ifstream f("club.txt");
    string line;
    string id;
    cout << "Member ID: ";
    cin >> id;
    cin.ignore();
    bool found = false;
    string filedata;
    while (getline(f, line))
    {
        if (line.find(id) != string::npos)
        {
            found = true;
            string newId, newName, newEmail, newPhone;
            cout << "Enter new details:\n";
            cout << "Member ID: ";
            getline(cin, newId);
            cout << "Name: ";
            getline(cin, newName);
            cout << "Phone: ";
            getline(cin, newPhone);
            cout << "Email: ";
            getline(cin, newEmail);
            std::stringstream ss;
            ss << left << setw(20) << newId << setw(20) << newName << setw(20) << newPhone << setw(20) << newEmail << endl;
            line = ss.str();
        }
        filedata += line + "\n";
    }
    f.close();
    if (!found) 
    {
        cout << "Student not found\n";
        return;
    }

    ofstream w("club.txt", ios::out);
    w << filedata;
    w.close();
    cout << "Student details updated successfully\n";
    return;
}

void printStudent()
{
    ifstream f("club.txt");
    string line;
    while(getline(f, line))
    {
        cout << line << endl;
    }
    f.close();
}

int main()
{
    ofstream f("club.txt");
    f << left << setw(20) << "Member ID" << setw(20) << "Name" << setw(20) << "Phone" << setw(20) << "Email" << endl;
    f.close();
    int choice = 0;
    while (choice != 6)
    {
        cout << "\n\n-------------------------------------------------------------------------------\n\n";
        cout << "\n\n\t\t\tMenu";
        cout << "\n\n\t\t\t1. Add";
        cout << "\n\n\t\t\t2. Search";
        cout << "\n\n\t\t\t3. Delete";
        cout << "\n\n\t\t\t4. Update";
        cout << "\n\n\t\t\t5. Print";
        cout << "\n\n\t\t\t6. Exit";
        cout << "\n\n\t\t\tEnter Choice: ";
        cin >> choice;
        cin.ignore();
        cout << "\n\n-------------------------------------------------------------------------------\n\n";
        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            searchStudent();
            break;

        case 3:
            deleteStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            printStudent();
            break;

        case 6:
            cout << "Exiting...\n\n";
            break;

        default:
            cout << "Invalid Choic\n";
        }
    }
}