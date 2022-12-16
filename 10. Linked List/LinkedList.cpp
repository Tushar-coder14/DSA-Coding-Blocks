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

////////////////LENGTH OF LL/////////////////////
int LengthLL(node* head){
    int count = 0;
    while(head != NULL){
        head = head -> next;  //head = *(head).next;
        count+=1;
    }
    return count;
}

///////////////////INSERTION AT FRONT////////////////
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

///////////////////INSERTION AT END////////////////
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

///////////////////INSERTION AT MID////////////////
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

///////////////////PRINTING LL//////////////////////
void PrintLL(node* head){
    while(head != NULL){
        cout << head -> data <<"-->";  //cout<< *(head).data;
        head = head -> next; // head = *(head).next;
    }
    cout<<"NULL"<<endl;
}


/////////////////////DELETION IN LL AT FRONT////////////////
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

///////////////////DELETION AT END////////////////////
void deleteAtEnd(node* &head , node* &tail){
    if(head == NULL){
        return;
    }
    else if(head -> next == NULL){
        delete head;
        head = tail = NULL;
    }
    else{
        node* temp = head;
        while(temp ->next != tail){
            temp = temp -> next;
        }
        delete tail;
        tail = temp;
        temp -> next = NULL;
    }
}

//////////////////DELETION AT MID///////////////
void deleteAtMid(node *head , node *tail ,int pos){
    if (pos == 0){
        deleteAtFront(head, tail);
    }
    else if( pos>= LengthLL(head)-1){
        deleteAtEnd(head, tail);
    }
    else{
    node* temp = head;
    for (int i = 1 ; i <= pos - 1; i++)
    {
        temp = temp -> next;
    }
    node* n = temp -> next;
    temp -> next = n -> next;
    delete n;
    }
}

////////////////////////////REVERSE A LL/////////////////
void reverseLL(node* &head, node* &tail){
    node* c = head;
    node* p = NULL;
    while(c != NULL){
        node* n = c-> next;
        c -> next = p;
        p = c;
        c = n;
    }
    swap(head, tail);
}

////////////////////////////REVERSE A LL BY RECURSION/////////////////
void reverseLLRecursionHelper(node* c , node* p){
    //base case:
    if (c == NULL){
        return;
    }

    //recursive case:
    node* n = c -> next;
    c -> next = p;
    reverseLLRecursionHelper(n , c);
}

void reverseLLRecursion(node* &head , node* &tail){
    reverseLLRecursionHelper(head , NULL);
    swap(head , tail);
}

////////////////MIDDLE OF LL/////////////////
node* midLL(node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    node* slow = head;
    node* fast = head -> next;
    while(fast != NULL and fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

int main(){

    node* head = NULL , *tail = NULL;
    node* head1 = NULL , *tail1 = NULL;
    
    InsertAtFront(head, tail , 1);
    InsertAtFront(head, tail , 3);
    InsertAtFront(head, tail , 5);
    InsertAtFront(head, tail , 6);
    InsertAtFront(head, tail , 8);

    InsertAtEnd(head, tail , 2);
    InsertAtEnd(head, tail , 4);
    InsertAtEnd(head, tail , 7);
    InsertAtEnd(head, tail , 8);
    InsertAtEnd(head, tail , 9);

    PrintLL(head);
    cout<<"Length: "<<LengthLL(head)<<endl;

    // InsertAtMid(head, tail , 200 , 5);

    //////////////////DELETION AT MID///////////////
    deleteAtMid(head,tail ,2);
    PrintLL(head);
    cout<<"Length: "<<LengthLL(head)<<endl;


    ////////////////////////////PRINTING REVERSED LL/////////////////
    // reverseLL(head, tail);
    reverseLLRecursion(head, tail);
    PrintLL(head);
    cout<<"Length: "<<LengthLL(head)<<endl;

    
        //////////////////DELETION AT FRONT///////////////
    // while(head != NULL){
    //     PrintLL(head);
    //     deleteAtFront(head,tail);
    // }

    //////////////////DELETION AT END///////////////
    // while(head != NULL){
    //     PrintLL(head);
    //     deleteAtEnd(head,tail);
    // }

    /////////////////PRINTING MIDDLE OF LL////////////////
    
    
    return 0;
}

