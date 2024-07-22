#include <bits/stdc++.h>
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

Node * uniqueSortedList(Node * &head) {

    if(head == NULL)
        return NULL;
  
    Node* curr = head;
    
    while(curr != NULL) {
        
        if( (curr -> next != NULL) && curr -> data == curr -> next -> data) {
            Node* next_next = curr ->next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else //not equal
        {
            curr = curr -> next;
        }   
    }
    
    return head; 
}

Node * uniqueunsortedList(Node * head) {

    if(head == NULL)
        return NULL;
    map<int , bool> visited;
  
    Node* curr = head;
    Node* prev = head;
    bool p = false;
    while (curr != NULL)
    {
        if(p){
            prev= prev->next;
        }
        if(visited[curr->data]==true){
            cout<<"true ";
            Node* temp = curr;
            curr= curr->next;
            delete(temp);
            
        }
        // cout<<"hello ";
        else{
            cout<<visited[curr->data]<<' ';
        visited[curr->data]=true;
        cout<<visited[curr->data]<<" ";
        
        curr=curr->next;
        p= true;
        }
    }
    
    
    return head; 
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
    insertAtTail(node1,29);
    insertAtTail(node1,9);
    insertAtTail(node1,34);
    insertAtTail(node1,6);
    insertAtTail(node1,6);
    print(head);
    // Node* ans = uniqueSortedList(head);
    Node * ans = uniqueunsortedList(head);
    print(ans);




}