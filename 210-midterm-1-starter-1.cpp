#include <iostream>
using namespace std;

//These are variables declared constant with the const keyword.
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

//Class for a Doubly Linked List
class DoublyLinkedList {
private:
    //Node struct holds one element of the list. Each Node reps. a single "link" in the list.
    struct Node {
        int data; //stores the node's value
        Node* prev; //pointer to the previous node
        Node* next; //pointer to the next node

        //Node constructor to initialize a node with a val. and pointers...
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; //store the value
            prev = p; //link to previous node (if any)
            next = n; //set pointer to next node
        }
    };

    Node* head; //pointer to the first node in the list
    Node* tail; //pointer to the last node in the list

public:
//Constructor for an empty list
    DoublyLinkedList() {
         head = nullptr; //list starts empty, no head
         tail = nullptr; //list starts empty, not tail
     }

     //insert a new node with 'value' after the node at 'position'
    void insert_after(int value, int position) {
        if (position < 0) { //check for invalid negative position
            cout << "Position must be >= 0." << endl;
            return; //exit function if invalid
        }

        Node* newNode = new Node(value); //create a new node with the given value
        
        if (!head) { //checks if list is empty - if list is empty
            head = tail = newNode; //new node is both head and tail
            return; //done inserting
        }

        Node* temp = head; //start from the head node
        for (int i = 0; i < position && temp; ++i) //move temp forward to the called position
            temp = temp->next; //go to next node/advance

        if (!temp) { //if position exceeds list length
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode; //avoid memory leak!
            return; //exit function
        }

        newNode->next = temp->next; //new node points forward to temp's next
        newNode->prev = temp; //new node points back to temp

        if (temp->next) //if temp is not the last node
            temp->next->prev = newNode; //next node points back to new node
        else
            tail = newNode; //if temp was tail, new node is new tail
        temp->next = newNode; //temp now points forward to new node
    }

    //Delete the first node with the specified value
    void delete_val(int value) {
        if (!head) return; //list empty, nothing to delete

        Node* temp = head; //start at head
        
        while (temp && temp->data != value) //()/ search for node containing value
            temp = temp->next; //mov to next node

        if (!temp) return; 

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}