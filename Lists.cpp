#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to add a new element to the end of the list
    void addElement(int val) {
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
        std::cout << "Element added: " << val << std::endl;
    }

    // Function to delete an element from the list
    void deleteElement(int val) {
        if (!head) {
            std::cout << "List is empty. Cannot delete element." << std::endl;
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "Element deleted: " << val << std::endl;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (!temp->next) {
            std::cout << "Element not found in the list." << std::endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        std::cout << "Element deleted: " << val << std::endl;
    }

    // Function to display the elements in the list
    void displayList() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        std::cout << "Elements in the list: ";
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Function to display the menu
    void displayMenu() {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Element\n";
        std::cout << "2. Delete Element\n";
        std::cout << "3. Display List\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
    }

    // Function to handle user input and perform corresponding operations
    void handleUserInput() {
        int choice;
        int element;

        do {
            displayMenu();
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Enter the element to add: ";
                    std::cin >> element;
                    addElement(element);
                    break;
                case 2:
                    std::cout << "Enter the element to delete: ";
                    std::cin >> element;
                    deleteElement(element);
                    break;
                case 3:
                    displayList();
                    break;
                case 4:
                    std::cout << "Exiting the program.\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 4);
    }
};

int main() {
    LinkedList myList;
    myList.handleUserInput();

    return 0;
}

