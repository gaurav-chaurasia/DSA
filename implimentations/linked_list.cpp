// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

#define sq(a) (a)*(a)
#define EPS   1e-9
#define PI    3.1415926535897932384626433832795
#define MOD   1000000007
 
typedef long long ll;
typedef unsigned long long ull;

// cpp node 
class Node {
    private:
        int data;
        Node *next {nullptr}; //setting default nullptr 
        
    public:
        Node() { //cunstructor without perameters
            data = 0;
        }
        Node(const int &data) { //cunstroctor with perameters
            this->data = data;
        }
        void setNode(const int &data) { // setter value of node
            this->data = data;
        } 
        int getNode() { // getter value of node
            return data;
        }
        Node *getNext() { // get the value of next pointer
            return next;
        }
        // to set the value for pointer
        void setNext(Node *n) {
            this->next = n;
        }
};
Node *head = NULL;
Node *tail = NULL;

class LinkedList {
    public:
        void add_front(int data) {
            Node* new_node = new Node(data);
            if (head == NULL) {
                head = new_node;
            } else {
                new_node->setNext(head);
                head = new_node;
            }
        }
        void display() {
            if (head == NULL) {
                cout << "###list is empty###";
            } else {
                Node* temp = head;
                cout << "###[ ";
                while (temp != NULL) {
                    cout << temp->getNode() << " ";
                    temp = temp->getNext();
                } cout << "]###";
            }
        }
        void add_end() {
            
        }
        void is_empty() {

        }
        void search(int data) {

        }
        // int delete_node() {

        // }
};
 
int main() {
    int choose, data;
    LinkedList *list = new LinkedList();
    while (choose != 5){
        cout << "\n\n\n\n***List of Operations you can do now is given below select***" << endl;
        cout << "1: see list\n";
        cout << "2: add-in-front\n";
        cout << "3: is empty\n";
        cout << "4: search element and print it's reference, data, and reference to next node\n";
        cout << "5: exit\n\n";
        cout << "please enter your choise: ";
        cin >> choose;
        cout << choose <<" options is selected.";
        switch (choose) {
            case 1:
                cout << "Operation was successfull returned code 1!! list is shown below\n";
                list->display();
                break;
            case 2:
                cout << "Enter value to add: "; cin >> data;
                cout << "Operation was successfull. element is added to the list\n";
                list->add_front(data);
                break;
            case 3:
                cout << "Operation was successfull. showing status below\n";
                list->is_empty();
                break;
            case 4:
                cout << "Operation was successfull. showing status below\n";
                list->search(data);
                break;
            case 5:
                cout << "returning......!!!!";
                break;

            default:
                cout << "invalid input"; 
                break;
        }
    }
    return 0;
}
