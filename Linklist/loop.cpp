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

Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}

Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
}

void insertAtTail(Node* &tail,Node * head, int d) {
    
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
    tail->next = head;
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;


    while(temp != head ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main(){
    Node* node1 =  new Node(3);
    Node * head = node1;
    Node * tail = node1;
    insertAtTail(node1,head,29);
    insertAtTail(node1,head,2);
    insertAtTail(node1,head,9);
    insertAtTail(node1,head,34);
    insertAtTail(node1,head,23);
    insertAtTail(node1,head,6);
    print(head);
    if(floydDetectLoop(head)){
        cout<<"loop is present";
    }

    Node * startnode = getStartingNode(head);
    cout<<"start node is : "<<startnode->data;

    Node * removeloop = removeLoop(head);
    print(removeloop);
    





}