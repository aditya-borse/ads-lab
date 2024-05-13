/* Q. Min/max Heaps: Marks obtained by students of second year in an
online examination of a particular subject are stored by the teacher.
Teacher wants to find the minimum and maximum marks of the subject.
Write a menu driven C++ program to find out maximum and minimum
marks obtained in that subject using heap data structure. Analyze the
algorithm
*/

#include <bits/stdc++.h>
using namespace std;

void min_heapify(vector<int> &marks, int i, int n)
{
    int smallest = i;
    int left_child = i * 2 + 1;
    int right_child = i * 2 + 2;

    if (left_child < n && marks[left_child] < marks[smallest])
        smallest = left_child;
    
    if (right_child < n && marks[right_child] < marks[smallest]) 
        smallest = right_child;
    
    if (i != smallest)
    {
        swap(marks[i], marks[smallest]);
        min_heapify(marks, smallest, n);
    }
}

void max_heapify(vector<int> &marks, int i, int n)
{
    int largest = i;
    int left_child = i * 2 + 1;
    int right_child = i * 2 + 2;

    if (left_child < n && marks[left_child] > marks[largest])
        largest = left_child;
    
    if (right_child < n && marks[right_child] > marks[largest]) 
        largest = right_child;
    
    if (i != largest)
    {
        swap(marks[i], marks[largest]);
        max_heapify(marks, largest, n);
    }
}

int main()
{
    vector<int> marks;
    int m;
    int choice = 0;
    while (choice != 6)
    {
        cout << "Menu\n";
        cout << "1. insert\n";
        cout << "2. Minimum marks\n";
        cout << "3. Maximum marks\n";
        cout << "4. print in ascending order\n";
        cout << "5. print in decending order\n";
        cout << "6. exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter marks: ";
            cin >> m;
            marks.push_back(m);
            cout << "Marks entered successfully\n";
            break;

        case 2:
            if (marks.size() != 0)
            {
                for (int i = (marks.size() / 2) - 1; i >= 0; i--)
                {
                    min_heapify(marks, i, marks.size());
                }
                cout << marks[0] << endl;
            }
            else
            {
                cout << "No marks entered yet\n";
            }
            break;

        case 3:
            if (marks.size() != 0) 
            {
                for (int i = (marks.size() / 2) - 1; i >= 0; i--) 
                {
                    max_heapify(marks, i, marks.size());
                }
                cout << marks[0] << endl;
            }
            else 
            {
                cout << "No marks entered yet\n";
            }
            break;

        case 4:
            if (marks.size() != 0)
            {
                sort(marks.begin(), marks.end());
                cout << "Ascending Order: ";
                for (int i = 0; i < marks.size(); i++) {
                    cout << marks[i] << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "No marks entered yet\n";
            }
            break;

        case 5:
            if (marks.size() != 0) 
            {
                sort(marks.begin(), marks.end(), greater<int>());
                cout << "Decending Order: ";
                for (int i = 0; i < marks.size(); i++) {
                    cout << marks[i] << " ";
                }
                cout << endl;
            }
            else 
            {
                cout << "No marks entered yet\n";
            }
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    }
}