#include <iostream>
#include <queue>
using namespace std;

//CODE:
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

//////////////PRINTING TREE//////////////////
void preorder(node* root){
    if(root == NULL){
        return ;
    }
    cout<< root -> data <<" ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(node* root){
    if(root == NULL){
        return ;
    }
    inorder(root -> left);
    cout<< root -> data <<" ";
    inorder(root -> right);
}

void postorder(node* root){
    if(root == NULL){
        return ;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout<< root -> data <<" ";
}

/////////////////!PRINTING TREE/////////////////
node* insertInBST(node* root , int d){
    if(!root){
        root = new node(d);
        return root;
    }

    if(root -> data >= d){
        root -> left = insertInBST(root -> left , d);
    }
    else{
        root -> right = insertInBST(root -> right , d);
    }
    return root;
}


//Input
// 8 3 10 1 6 14 7 13 -1
node* createBST(){
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    node* root = NULL;
    while(data != -1){
        root = insertInBST(root , data);
        cin>>data;
    }
    return root;
}


////////////PRINTING ELEMENTS IN RANGE K1 & K2/////////
void printRange(node* root , int k1 , int k2){
    if(root == NULL){
        return ;
    }
    printRange(root->left,k1,k2);
    if(root->data >= k1 and root->data <=k2){
        cout<<root->data<<" ";
    }
    printRange(root->right , k1 , k2);
}

//////////SEARCHING AND ADDING ELEMENTS IN BST////////
node* searchBST(node* root , int key){
    //base key:
    if(!root){
        return NULL;
    }

    //recursive case:
    if(root->data == key){
        return root;
    }
    else if(root->data > key){
        return searchBST(root -> left , key);
    }
    else{
        return searchBST(root -> right , key);
    }
}

//////////////CHECK WHETHER BALANCED OR NOT////////////////////////


////////////////CHECK WHETHER BST OR NOT//////////////////
bool isBST(node* root , int min = INT_MIN , int max = INT_MAX){
    //base case:
    if(!root){
        return true;
    }

    //recursive case:
    if(root->data >= min and root->data<=max and
    isBST(root->left , min , root->data) == true and
    isBST(root->right , root->data , max)){
        return true;
    } 
    return false;
}

//////////////SORTED ARRAY TO BST/////////////
node* createBalancedBST(int *a , int s, int e){
    //base case:
    if(s>e){
        return NULL;
    }

    //recursive case:
    int m = (s+e)/2;
    node* root = new  node(a[m]);
    root->left = createBalancedBST(a,s,m-1);
    root->right = createBalancedBST(a,m+1,e);
    return root;
}


///////////////BST TO LL///////////////
class LinkedList{
    public:
    node* head , *tail;
};

LinkedList BSTtoLL(node* root){
    LinkedList l;
    //base case:
    if(!root){
        l.head = l.tail = NULL;
        return l;
    }

    //recursive case:
    if(root->left and root->right){
        LinkedList left = BSTtoLL(root -> left);
        LinkedList right = BSTtoLL(root->right);
        left.tail->right = root;
        root->right = right.head;
        l.head = left.head;
        l.tail = right.tail;
        return l;
    }
    else if (root->left and !root->right){
        LinkedList left = BSTtoLL(root->left);
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;
        return l;
    }
    else if(!root->left and root->right){
        LinkedList right = BSTtoLL(root->right);
        root->right = right.head;
        l.head = root;
        l.tail = right.tail;
        return l;
    }
    else{
        l.head= l.tail = root;
        return l;
    }


}


int main(){
    /*

    node* root = createBST();

    cout<<"Pre-Order: ";
    preorder(root);
    cout<<endl;

    cout<<"In-Order: ";
    inorder(root);
    cout<<endl;

    cout<<"Post-Order: ";
    postorder(root);
    cout<<endl;

    //PRINTING ELEMENTS IN RANGE K1 & K2:
    printRange(root, 4 , 10);
    cout<<endl;

    //SEARCHING AND ADDING ELEMENTS IN BST:
    node* ans = searchBST(root , 6);
    if(ans){
        cout<<ans->data<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    //CHECK BALANCED OR NOT:

    //CHECK WHETHER BST OR NOT:
    if(isBST(root)){
        cout<<"Balanced Hai"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    */

    //SORTED ARRAY TO BST
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(a)/sizeof(int);
    node* root1 = createBalancedBST(a,0,n-1);

    // cout<<"Pre-Order: ";
    // preorder(root1);
    // cout<<endl;

    // cout<<"In-Order: ";
    // inorder(root1);
    // cout<<endl;

    // cout<<"Post-Order: ";
    // postorder(root1);
    // cout<<endl;

    //BST TO LL:
    LinkedList l = BSTtoLL(root1);

    node* head = l.head;
    while(head){
        cout<<head->data<<"-->";
        head = head->right;
    }
    cout<<"NULL"<<endl;


    return 0;
}