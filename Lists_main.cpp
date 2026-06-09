#include <iostream>

using namespace std;
class Node {
    public:
    int data;
    Node* next;
    
    
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList{
private:
    Node* head;

public:
    
    LinkedList() : head(nullptr) {}

    
    void insert_beg(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insert_spec(int val)
    {
         Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;

    }
    }
    void l_delete()
    {
        if(head==nullptr)
        {
            cout<<"Empty list.Cannot delete"<<endl;
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

    }
    void display()
    {
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
        cout<<"\n";
    }
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
int main()
{
    LinkedList l;
    int choice;
    cout<<"press 1 to insert at beginning"<<endl;
    cout<<"press 2 to insert at specific position"<<endl;
    cout<<"press 3 to delete last element"<<endl;
    cout<<"press 4 to display all element"<<endl;
    cout<<"press 5 to search for an element"<<endl;
    
    while(1)
    {
        cout<<"enter your choice:"<<endl;
        cin>>choice;
         switch (choice) {
            case 1:
                int insertVal;
                cout << "Enter the value to insert at the beginning: "<<endl;
                cin >> insertVal;
                l.insert_beg(insertVal);
                break;

            case 2:
            int value;
            cout<<"enter value to insert at specific position\n";
            cin>>value;
                l.insert_spec(value);
                break;

            case 3:
                l.l_delete();
                break;
                case 4:
                l.display();
                break;

            case 5:
                int searchVal;
                cout << "Enter the value to search: ";
                cin >> searchVal;
                if (l.searchElement(searchVal)) {
                    cout << "Element found in the list." << endl;
                } else {
                    cout << "Element not found in the list." << endl;
                }
                break;

            case 6:
                cout << "Exiting the program." << endl;
                exit(0);
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                
        }

    } 

    return 0;
}


