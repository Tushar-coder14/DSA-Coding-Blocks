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

/////////////////MERGE TWO SORTED LIST/////////////////
node* mergeSortedLL(node* h1 , node* h2){
    //base case:
    if(h2 == NULL) {
        return h1;
    }
    if(h1 == NULL) return h2;

    //recursive case:
    node* nH = NULL;
    if(h1 -> data < h2 -> data){
        nH = h1;
        nH -> next = mergeSortedLL(h1->next , h2);
    }
    else{
        nH = h2;
        nH -> next = mergeSortedLL(h1 , h2 -> next);
    }
    return nH;
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


/////////////////MERGE SORT-LL////////////////
node* mergeSort(node* head){
    //base case:
    if(head == NULL || head -> next == NULL){
        return head;
    }

    //recursive case:
    //1. DIVIDE:
    node* m = midLL(head);
    node* a = head ; 
    node* b = m -> next;
    m -> next = NULL;

    //2. SORT:
    a = mergeSort(a);
    b = mergeSort(b);

    //3. MERGE:
    node* nH = mergeSortedLL(a,b);
    return nH;
}


/////////////////BUBBLE SORT////////////
void bubbleSort(node* &head){
    int len = LengthLL(head);
    for(int i=0 ; i< len-1 ; i++){
        node* c = head , *p = NULL;
        while(c!=NULL and c->next == NULL){
            node* n = c-> next;
            if(c->data > n-> data){
                //swapping hogi
                if(p==NULL){
                    c-> next = n-> next;
                    n-> next = c;
                    p = head = n;
                }
                else{
                    c -> next = n -> next;
                    n-> next = c;
                    p -> next = n;
                    p = n;
                }
            }
            else{
                //swapping nhi hogi
                p = c;
                c = n;
            }
        }
    }
}

////////////////////////BREAK CYCLE LL/////////////////
void breakCycle(node* head , node* fast){
    node* prev = head;

    //1. Set the previoud behind fast
    while(prev -> next != fast){
        prev = prev -> next;
    }

    //2. Break the cycle
    node* slow = head;
    while(fast != slow){
        prev = fast;
        fast = fast -> next;
        slow = slow -> next;
    }
    prev -> next = NULL;
}

///////////////////////CYCLE DETECTION LL/////////////
bool isCyclic(node* head){
    node* s = head , *f = head;
    while(f != NULL and f-> next != NULL){
        f = f->next->next;
        s = s-> next;
        if(s == f){
            breakCycle(head , f);
            return true;
        }
    }
    return false;
}


void createCycle(node* head , node* tail){
    tail -> next = head -> next -> next -> next;
}


int main(){
    node* head = NULL , *tail = NULL;
    // node* head1 = NULL , *tail1 = NULL;
    
    // InsertAtEnd(head, tail , 1);
    // InsertAtEnd(head, tail , 3);
    // InsertAtEnd(head, tail , 5);
    // InsertAtEnd(head, tail , 6);
    // InsertAtEnd(head, tail , 8);

    // InsertAtEnd(head1, tail1 , 2);
    // InsertAtEnd(head1, tail1 , 4);
    // InsertAtEnd(head1, tail1 , 7);
    // InsertAtEnd(head1, tail1 , 9);
    // InsertAtEnd(head1, tail1, 10);

    // PrintLL(head);
    // PrintLL(head1);

    // head = mergeSortedLL(head , head1);
    // PrintLL(head);


    ///////////MERGE SORT-LL//////////////
    InsertAtEnd(head, tail , 6);
    InsertAtEnd(head, tail , 5);
    InsertAtEnd(head, tail , 4);
    InsertAtEnd(head, tail , 3);
    InsertAtEnd(head, tail , 2);
    InsertAtEnd(head, tail , 1);
    InsertAtEnd(head, tail , 1);
    InsertAtEnd(head, tail , 1);
    InsertAtEnd(head, tail , 1);
    InsertAtEnd(head, tail , 1);
    // head = mergeSort(head);
    // // bubbleSort(head);
    // PrintLL(head);

 
    /////////////Cycle Detection LL///////////
    createCycle(head, tail);
    isCyclic(head);
    PrintLL(head);
    
    // if(isCyclic(head) != true){
    //     PrintLL(head);
    // }
    // else{
    //     cout<<"Print mat kar"<<endl;
    // }

    return 0;
}

