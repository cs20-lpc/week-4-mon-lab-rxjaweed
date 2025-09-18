#include <iostream>
#include <stdexcept>

using namespace std;


template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), length(0) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) 
{
    Node *newNode = new Node;

    newNode->value = elem;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }

    else 
    {
        Node* nodePtr = head;
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
    ++length;

}

template <typename T>
void LinkedList<T>::clear() 
{
    Node* nodePtr = head;
    while (nodePtr != nullptr)
    {
        Node* temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;
    }
    head = nullptr;
    length = 0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const 
{
    Node* nodePtr = head;
    int count = 0;

    while (nodePtr != nullptr) 
    {
        if (count == position)
        {
            return nodePtr->value;
        }
        ++count;
        nodePtr = nodePtr->next;
    }
    throw out_of_range("Index out of range");
    
}

template <typename T>
int LinkedList<T>::getLength() const 
{
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const 
{
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) 
{
    Node* nodePtr = head;
    int count = 0;

    while (nodePtr != nullptr)
    {
        if (count == position)
        {
            nodePtr->value = elem;
            return;
        }
        count++;
        nodePtr = nodePtr->next;
    }
    throw out_of_range("Index out of range");
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
