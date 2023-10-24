// #include <iostream>

// struct Node {
//     int data;
//     Node* next;
// };

// class LinkedList {
// private:
//     Node* head;

// public:
//     LinkedList() : head(nullptr) {}

//     // Function to insert a new node at the front of the list
//     void insertAtFront(int value) {
//         Node* newNode = new Node;
//         if (!newNode){
//             std::cerr << "Memory allocation failed\n";
//             return;
//         }
//         newNode->next = head;
//         newNode->data = value;
//         head = newNode;
//     }

//     // Function to delete the first occurrence of a value from the list
//     void deleteByValue(int value) {
//         Node* current = head;
//         Node* previous = nullptr;
//         while (current != nullptr && current->data != value){
//             previous = current;
//             current = current->next;
//         }

//         if (current != nullptr){
//             if (previous != nullptr){
//                 previous->next = current->next;
//             }
//             else {
//                 head = current->next;
//             }
//             delete current;
//         }
        
//     }

//     // Function to display the elements of the list
//     void display() {
//         Node* current = head;
//         while (current != nullptr){
//             std :: cout << current->data << " ";
//             current = current->next;
//         }
//         std :: cout << std::endl;
       
//     }

//     // Function to delete all nodes and free memory
//     void cleanup() {
//         Node* current = head; 
//         while(current != nullptr){
//             Node* temp = current;
//             current = current->next;
//             delete temp;
//         }
//         head = nullptr;
        
//     }

//     // Destructor to ensure cleanup when the object is destroyed
//     ~LinkedList() {
//         cleanup();
//     }
// };

// int main() {

   
//     // Create a linked list and perform operations
//     LinkedList myList;

//     myList.insertAtFront(5);
//     myList.insertAtFront(4);
//     myList.insertAtFront(3);
//     myList.insertAtFront(2);
//     myList.insertAtFront(23);
//     myList.insertAtFront(1);

//     myList.display();
//     myList.deleteByValue(23);
//     myList.display();
//     myList.cleanup();
//     return 0;
// }


// The following is the same code except it used smart pointers 

#include <iostream>
#include <memory>

// Define Node using std::unique_ptr
struct Node {
    int data;
    std::unique_ptr<Node> next;

    // Constructor to initialize Node with a value
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    std::unique_ptr<Node> head;

public:
    // Constructor to initialize the LinkedList
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the front of the list
    void insertAtFront(int value) {
        // Use std::make_unique for memory allocation and object construction
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
        // Link the new node to the current front of the list
        newNode->next = std::move(head);
        // Update the head pointer to the new node
        head = std::move(newNode);
    }

    void reverseList() {
        std::unique_ptr<Node> prev = nullptr;
        std::unique_ptr<Node> current = std::move(head);
        std::unique_ptr<Node> next = nullptr;

        while (current != nullptr) {
            // Save the next node
            next = std::move(current->next);
            // Reverse the link
            current->next = std::move(prev);
            // Move to the next nodes
            prev = std::move(current);
            current = std::move(next);
        }

        // Update the head to the last node (previous)
        head = std::move(prev);
    }

    // Function to delete the first occurrence of a value from the list
    void deleteByValue(int value) {
        Node* current = head.get();
        Node* previous = nullptr;

        // Traverse the list to find the node with the specified value
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next.get();
        }

        // If the node with the value is found, delete it
        if (current != nullptr) {
            if (previous != nullptr) {
                // Link the previous node to the next node, skipping the current node
                previous->next = std::move(current->next);
            } else {
                // Update the head to the next node, effectively removing the current node
                head = std::move(current->next);
            }
        }
    }

    // Function to find and return the middle node of the linked list
    Node* findMiddleNode() {
        Node* fastPointer = head.get();
        Node* slowPointer = head.get();

        while(fastPointer != nullptr){
            fastPointer = fastPointer->next->next.get();
            slowPointer = slowPointer->next.get();
        }
        return slowPointer; // Replace this with the actual result
    }

    // Function to display the elements of the list
    void display() {
        Node* current = head.get();
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next.get();
        }
        std::cout << std::endl;
    }

    // Destructor (not explicitly needed with smart pointers)
    // ~LinkedList() = default;
};

int main() {
    // Create a linked list and perform operations
    LinkedList myList;

    // Insert elements at the front of the list
    myList.insertAtFront(5);
    myList.insertAtFront(4);
    myList.insertAtFront(3);
    myList.insertAtFront(2);
    myList.insertAtFront(23);
    myList.insertAtFront(1);

    // Display the elements of the list
    myList.display();

    // Delete a node by value
    myList.deleteByValue(23);

    // Display the updated list
    myList.display();

    myList.reverseList();
    myList.display();

    return 0;
}








