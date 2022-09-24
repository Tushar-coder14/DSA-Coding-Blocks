#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

int LengthLL(node* head){
    int count = 0;
    while(head != NULL){
        head = head -> next;
        count+=1;
    }
    return count;
}

void InsertAtFront(node* &head , node* &tail , int d){
    if(head  == NULL){
        node *n = new node(d);
        head = tail = n;
    }
    else{
        node* n = new node(d);
        n -> next = head;
        head = n;
    }
}

void InsertAtEnd(node* &head , node* &tail , int d){
    if(head == NULL){
        node* n = new node(d);
        head = tail = n;
    }
    else{
        node* n = new node (d);
        tail -> next = n;
        tail = n;
    }
}

void InsertAtMid(node* head , node* tail , int data , int pos){
    if(pos == 0){
        InsertAtFront(head, tail , data);
    }
    else if(pos >= LengthLL(head)){
        InsertAtEnd(head, tail, data);
    }

    node* temp = head;
    for(int i=0 ; i<pos-1 ; i++){
        temp = temp -> next;
    }
    node* n = new node(data);
    n->next = temp->next;
    temp->next = n;
}


void PrintLL(node* head){
    while(head != NULL){
        cout << head -> data <<"-->";
        head = head -> next;
    }
    cout<<"NULL"<<endl;
}


/////////////////////DELETION IN LL////////////////
void deleteAtFront(node* &head , node* &tail){
    if(head == NULL){
        return;
    }
    else if(head->next == NULL){
        delete head;
        head = tail = NULL;
    }
    else{
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){

    node* head = NULL , *tail = NULL;
    
    InsertAtFront(head, tail , 1);
    InsertAtFront(head, tail , 2);
    InsertAtFront(head, tail , 3);
    InsertAtFront(head, tail , 4);
    InsertAtFront(head, tail , 5);


    InsertAtEnd(head, tail , 4);
    InsertAtEnd(head, tail , 6);
    InsertAtEnd(head, tail , 7);
    InsertAtEnd(head, tail , 8);
    InsertAtEnd(head, tail , 9);

    PrintLL(head);
    cout<<"Length: "<<LengthLL(head)<<endl;

    InsertAtMid(head, tail , 200 , 5);

    PrintLL(head);
    cout<<"Length: "<<LengthLL(head)<<endl;

    while(head != NULL){
        PrintLL(head);
        deleteAtFront(head,tail);
    }
    
    return 0;
}