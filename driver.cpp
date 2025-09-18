#include <iostream>
#include "LinkedList.hpp"

using namespace std;


int main()
{
    LinkedList<int> list; //creates list of ints
    int option; 


    do
    {
        cout << "Welcome to the Linked List program. Please select an option from the following. Enter -1 to quit the program:" << endl;

        cout << "1) Append element" << endl;
        cout << "2) Get Element" << endl;
        cout << "3) Clear List" << endl;
        cout << "4) Replace value" << endl;

        cin >> option;

        if (option == 1)
        {
            int value;
        
            cout << "What is the value of the element you would like to append?" << endl;
            cin >> value;

            list.append(value);
            cout << "The value has been added to the list" << endl;
        
        }

        if (option == 2)
        {
            int elem;

            cout << "Enter the element you would like to retrieve: " << endl;
            cin >> elem;
            cout << "The value at the requested element is " << list.getElement(elem) << endl;;
        }

        if (option == 3)
        {
            list.clear();
            cout << "The list has been cleared" << endl;
        }

        if (option == 4)
        {
            int elem;
            int value;
            cout << "Which element's value would you like to replace? " << endl;
            cin  >> elem;

            cout << "What is the new value? " << endl;
            cin >> value;

            list.replace(elem, value);
        }
    } 
    
    
    while (option != -1);
    {
        cout << "Thank you for using the Program" << endl;
    }
    

    
}