/**
 * CSC 301 - Data Structures
 * Singly Linked List Implementation with Memory Management & Error Handling
 */

#include <iostream>
#include <stdexcept>

// Node structure representing each element in the singly linked list
struct Node {
    int data;
    Node* next;

    // Node constructor
    Node(int val) : data(val), next(nullptr) {}
};


// SinglyLinkedList class encapsulating the linked list operations

class SinglyLinkedList {
private:
    Node* head;
    int size;

public:
    // Constructor initializes an empty list
    SinglyLinkedList() : head(nullptr), size(0) {}

    // Destructor to dynamically clean up allocated heap memory
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        size = 0;
    }

    /**
     * Inserts a node at the beginning of the list.
     * Time Complexity: O(1)
     */
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
        std::cout << "[SUCCESS] Inserted " << val << " at the beginning.\n";
    }

    /**
     * Inserts a node at the end of the list.
     * Time Complexity: O(N)
     */
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
        std::cout << "[SUCCESS] Inserted " << val << " at the end.\n";
    }

    /**
     * Inserts a node at a zero-based position (middle insertion).
     * Time Complexity: O(N)
     */
    void insertAtPosition(int val, int position) {
        if (position < 0 || position > size) {
            std::cout << "[ERROR] Invalid position " << position << ". Insertion aborted.\n";
            return;
        }
        if (position == 0) {
            insertAtBeginning(val);
            return;
        }
        if (position == size) {
            insertAtEnd(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < position - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        std::cout << "[SUCCESS] Inserted " << val << " at index position " << position << ".\n";
    }

    /**
     * Deletes a node by matching value.
     * Time Complexity: O(N)
     */
    bool deleteByValue(int val) {
        // Error handling for empty list
        if (head == nullptr) {
            std::cout << "[ERROR] Cannot delete " << val << ": List is empty.\n";
            return false;
        }

        // Deleting head node
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            std::cout << "[SUCCESS] Deleted value " << val << " from list.\n";
            return true;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            std::cout << "[ERROR] Value " << val << " not found in the list.\n";
            return false;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        size--;
        std::cout << "[SUCCESS] Deleted value " << val << " from list.\n";
        return true;
    }

    /**
     * Deletes a node by its zero-based position.
     * Time Complexity: O(N)
     */
    bool deleteByPosition(int position) {
        // Error handling for empty list
        if (head == nullptr) {
            std::cout << "[ERROR] Cannot delete position " << position << ": List is empty.\n";
            return false;
        }

        // Out-of-bounds position check
        if (position < 0 || position >= size) {
            std::cout << "[ERROR] Position " << position << " is out of bounds (Current size: " << size << ").\n";
            return false;
        }

        // Deleting initial head node
        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            std::cout << "[SUCCESS] Deleted node at index position 0.\n";
            return true;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1; ++i) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        size--;
        std::cout << "[SUCCESS] Deleted node at index position " << position << ".\n";
        return true;
    }

    /**
     * Displays all node values sequentially.
     * Time Complexity: O(N)
     */
    void display() const {
        if (head == nullptr) {
            std::cout << "List Contents: [EMPTY]\n";
            return;
        }

        std::cout << "List Contents: ";
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

// Driver Program demonstrating 3 distinct test datasets
int main() {
    SinglyLinkedList list;

    std::cout << "========================================\n";
    std::cout << "  TEST SET 1: Empty List & Error Handling\n";
    std::cout << "========================================\n";
    list.display();
    list.deleteByValue(10);
    list.deleteByPosition(0);

    std::cout << "\n========================================\n";
    std::cout << "  TEST SET 2: Insertion Operations\n";
    std::cout << "========================================\n";
    list.insertAtBeginning(30);       // List: 30
    list.insertAtBeginning(10);       // List: 10 -> 30
    list.insertAtEnd(50);             // List: 10 -> 30 -> 50
    list.insertAtPosition(20, 1);     // Middle insertion at index 1 -> List: 10 -> 20 -> 30 -> 50
    list.insertAtPosition(40, 3);     // Middle insertion at index 3 -> List: 10 -> 20 -> 30 -> 40 -> 50
    list.display();

    std::cout << "\n========================================\n";
    std::cout << "  TEST SET 3: Deletion & Boundary Cases\n";
    std::cout << "========================================\n";
    list.deleteByValue(30);           // Deleting middle value
    list.display();

    list.deleteByPosition(0);         // Deleting position 0 (head element 10)
    list.display();

    list.deleteByPosition(10);        // Deleting invalid out-of-bounds position
    list.deleteByValue(999);          // Deleting non-existent value
    list.display();

    return 0;
}