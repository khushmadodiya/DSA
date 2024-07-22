#include <iostream>
using namespace std;

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };



Node* kReverse(Node* head, int k) {
    if(head == NULL) {
        return NULL;
    }
    
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
  
    if(next != NULL) {
        head -> next = kReverse(next,k);
    }
 
    return prev;
}

void insertAtTail(Node* &tail, int d) {
    
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main(){
    Node* node1 =  new Node(3);
    Node * head = node1;
    Node * tail = node1;
    insertAtTail(node1,29);
    insertAtTail(node1,2);
    insertAtTail(node1,9);
    insertAtTail(node1,34);
    insertAtTail(node1,23);
    insertAtTail(node1,6);
    print(head);
    Node* ans = kReverse(head , 3);
    print(ans);




}