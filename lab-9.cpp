/* Q. Telephone book management: Consider the telephone book database of N clients. Write a menu driven C++ program to make use of a hash table implementation to quickly look up a client's telephone number. Use of two collision handling techniques linear and quadratic probing and compare them using number of comparisons required to find a set of telephone numbers. the hash function should be phone number mod table size. */

#include <bits/stdc++.h>
using namespace std;

const int SIZE = 10;

void linearProbing(vector <long long int> &LinArr, long long int num);
void quadraticProbing(vector <long long int> &QuaArr, long long int num);
int searchLinearProbing(vector <long long int> &LinArr, long long int num, int &counter);
int searchQuadraticProbing(vector <long long int> &QuaArr, long long int num, int &counter);
int hashfunction(long long int num, int SIZE);

int main()
{
    vector <long long int> LinArr(SIZE, 0);
    vector <long long int> QuaArr(SIZE, 0);
    long long int num;
    int choice, result1, result2, counter1, counter2;

    do
    {
        cout << "\n\t\t\t\tMenu\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Exit\n";
        cout << endl;
        cout << "Choice: ";
        cin >> choice;
        cout << "\n-------------------------------------------------------------------------------------------\n";
        switch(choice) 
        {
            case 1:
                cout << "Number: ";
                cin >> num;
                linearProbing(LinArr, num);
                quadraticProbing(QuaArr, num);
                break;
            
            case 2:
                cout << "Number: ";
                cin >> num;
                counter1 = 0;
                counter2 = 0;
                result1 = searchLinearProbing(LinArr, num, counter1);
                result2 = searchQuadraticProbing(QuaArr, num, counter2);
                if (result1 == -1 && result2 == -1) 
                    cout << "Not found\n";
                else 
                {   
                    cout << "Found" << endl;
                    cout << "Took " << counter1 << " comparisons using Linear Probing\n";
                    cout << "Took " << counter2 << " comparisons using quadratic probing\n";
                }
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid input\n";
        }

    } while (choice != 3);
}

int hashfunction(long long int num, int SIZE)
{
    return num % SIZE;
}


void linearProbing(vector <long long int> &LinArr, long long int num) 
{
    int index = hashfunction(num, SIZE);
    int probs = 0;
    while (LinArr[index] != 0) 
    {
        if (LinArr[index] == num) 
        {
            cout << "Phone number already exist in the hash table.\n";
            return;
        }
        index = (index + ++probs) % SIZE;
    }
    LinArr[index] = num;
    cout << num << " inserted using Linear probing at index " << index << " after " << probs << " probs\n";
}

void quadraticProbing(vector <long long int> &QuaArr, long long int num)
{
    int index = hashfunction(num, SIZE);
    int probs = 0;
    while (QuaArr[index] != 0) 
    {
        if (QuaArr[index] == num)
        {
            cout << "Phone number alread exist in the hash table. \n";
            return;
        }
        ++probs;
        index = (index + (probs * probs)) % SIZE;
    }
    QuaArr[index] = num;
    cout << num << " inserted using Quadratic probing at index " << index << " after " << probs << " probs\n";
}

int searchLinearProbing(vector <long long int> &LinArr, long long int num, int &counter)
{
    int index = hashfunction(num, SIZE);
    int probs = 0;
    while (LinArr[index] != 0)
    {
        counter++;
        if (LinArr[index] == num)
            return 1;

        index = (index + ++probs) % SIZE;
    }
    return -1;
}

int searchQuadraticProbing(vector <long long int> &QuaArr, long long int num, int &counter)
{
    int index = hashfunction(num, SIZE);
    int probs = 0;
    while (QuaArr[index] != 0) 
    {
        counter++;
        if (QuaArr[index] == num)
            return 1;

        ++probs;
        index = (index + (probs * probs)) % SIZE;
    }
    return -1;
}
