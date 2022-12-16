#include <iostream>
#include <queue>
using namespace std;

//Input
// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

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


////////////////CREATION OF TREE///////////////////
node* createTree(){
    //base case:
    int data;
    cin>>data;
    if(data ==-1){
        return NULL;
    }

    //recursive case:
    node* root = new node(data);
    root -> left = createTree();
    root -> right = createTree();
    return root;
}


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


//////////COUNT NODES//////////////////
int countNodes(node* root){
    //base case:
    if(!root){
        return 0;
    }

    //recursive case:
    int leftKaCount = countNodes(root -> left);
    int rightKaCount = countNodes(root -> right);
    return leftKaCount + rightKaCount + 1;
}

////////HEIGHT OF TREE/////////////
int height(node* root){
    if(!root)
    return 0;

    return max(height(root -> left) , height(root -> right)) + 1;
}

///////////////////DIAMETER OF TREE/////////////
int diameter(node* root){
    //base case:
    if(!root) return 0;

    //recursive case:
    //when height is present in both Left and Right Subtree:
    int op1 = height(root -> left) + height(root -> right);

    //when height is only present in Left SubTree:
    int op2 = height(root -> left);

    //when height is only present in Right SubTree:
    int op3 = height(root -> right);

    return max(op1 , max(op2 , op3));
}

////////////////DIAMETER OF TREE (FAST WAY)//////////////
class Pair {
    public:
    int height;
    int diameter;
};

Pair fastDiameter(node* root){
    Pair ans;
    if(!root){
        ans.height = ans.diameter = 0;
        return ans;
    }

    Pair left = fastDiameter(root -> left);
    Pair right = fastDiameter(root -> right);

    ans.height = max(left.height , right.height) + 1;
    int op1 = left.height + right.height;
    int op2 = left.diameter;
    int op3 = right.diameter;

    ans.diameter = max(op1, max(op2 , op3));
    return ans;
}

/////////////FIND KEY/////////////////
node* findKey(node* root , int key){
    if(!root){
        return NULL;
    }
    if(root -> data == key){
        return root;
    }

    node* ans = findKey(root -> left , key);
    if(ans){
        return ans;
    }
    return findKey(root -> right , key);
}

/////////MIRROR TREE////////////
void mirror(node* root){
    //base case:
    if(!root){
        return ;
    }

    //recursive case:
    swap(root -> left , root -> right);
    mirror(root -> left);
    mirror(root -> right);
}

/////////////LEVEL ORDER TRAVERSAL////////
void levelOrder(node* root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        q.pop();
        if( f != NULL){
            cout<<f -> data<<" ";
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
        else{
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}

////////////INPUT TREE LEVELWISE/////////
node* levelWiseBuild(node* root){
    int data;
    cout<<"Enter root data: ";
    cin>>data;
    if(data == -1){
        return NULL;
    }

    node* root1 = new node(data);
    queue <node*> q;
    q.push(root1);
    while(!q.empty()){
        node* f = q.front();
        q.pop();
        cout<<"Enter data for: "<<f->data<<" ";
        int l,r;
        cin>>l>>r;
        if(l != -1){
            f -> left = new node(l);
            q.push(f->left);
        }
        if(r != -1){
            f -> right = new node(r);
            q.push(f->right);
        }
    }
    return root;
}


//////////////MAKE TREE USING INORDER AND PREORDER//////////////
int pre[] = {8,10,1,6,4,7,3,14,13};
int k=0;
int in[] = {1,10,4,6,7,8,3,13,14};

node* makeTree(int *in , int s , int e){
    //base case:
    if(s > e){
        return NULL;
    }

    //recursive case:
    node* root = new node(pre[k++]);
    int i = -1;
    for(int j=s ; j<=e ; j++){
        if(in[j] == root -> data){
            i = j;
            break;
        }
    }
    root -> left = makeTree(in , s , i - 1);
    root -> right = makeTree(in , i + 1 , e);

    return root;
}

int main(){
    
    //1. Tree Creation:
    node* root = createTree();

    //2. Printing Tree:
    cout<<"Pre-Order: ";
    preorder(root);
    cout<<endl;

    cout<<"In-Order: ";
    inorder(root);
    cout<<endl;

    cout<<"Post-Order: ";
    postorder(root);
    cout<<endl;

    //3. Count nodes of a Binary Tree:
    cout<<"Total Nodes: "<<countNodes(root)<<endl;

    //4. Height of Tree:
    cout<<"Tree Height: "<<height(root)<<endl;

    //5. Diameter of Tree:
    cout<<"Diameter of Tree: "<<diameter(root)<<endl;

    //6 . Diameter(fast method):
    Pair ans = fastDiameter(root);
    cout<<"Tree Fast Height: "<<ans.height<<endl;
    cout<<"Tree Fast Diameter: "<<ans.diameter<<endl;

    //7. Key Find:
    cout<<findKey(root , 5)<<endl;

    //8. Mirror Tree
    //mirror(root);
    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;

    //9. Level Order Traversal:
    levelOrder(root);

    //10. Input Tree Levelwise:
    // levelWiseBuild(root);

    // cout<<"Pre-Order: ";
    // preorder(root);
    // cout<<endl;

    // cout<<"In-Order: ";
    // inorder(root);
    // cout<<endl;

    // cout<<"Post-Order: ";
    // postorder(root);
    // cout<<endl;

    //11. Make tree using Inorder and Postorder:
    node* root1 = makeTree(in , 0 , 8);

    cout<<"Pre-Order: ";
    preorder(root1);
    cout<<endl;

    cout<<"In-Order: ";
    inorder(root1);
    cout<<endl;

    cout<<"Post-Order: ";
    postorder(root1);
    cout<<endl;

    return 0;
}