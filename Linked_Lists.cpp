#include <iostream>

using namespace std;

// Node structure
class Node {
    public:
    int data;
    Node* next;
    
    // Constructor
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Function to insert an element at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Element inserted at the beginning: " << val << endl;
    }

    // Function to delete the last element
    void deleteLastElement() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }

        cout << "Last element deleted successfully." << endl;
    }

    // Function to display all elements in the linked list
    void displayAllElements() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Elements in the linked list: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to search for an element
    bool searchElement(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

// Menu function
void printMenu() {
    cout << "Linked List Menu:" << endl;
    cout << "1. Insert at the beginning" << endl;
    cout << "2. Delete last element" << endl;
    cout << "3. Display all elements" << endl;
    cout << "4. Search for an element" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    LinkedList linkedList;
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                int insertVal;
                cout << "Enter the value to insert: ";
                cin >> insertVal;
                linkedList.insertAtBeginning(insertVal);
                break;

            case 2:
                linkedList.deleteLastElement();
                break;

            case 3:
                linkedList.displayAllElements();
                break;

            case 4:
                int searchVal;
                cout << "Enter the value to search: ";
                cin >> searchVal;
                if (linkedList.searchElement(searchVal)) {
                    cout << "Element found in the list." << endl;
                } else {
                    cout << "Element not found in the list." << endl;
                }
                break;

            case 5:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 5);

    return 0;
}
