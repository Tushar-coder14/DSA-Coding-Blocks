#include<iostream>
using namespace std;

void toh(int n , char src, char helper, char dest){
    //base case
    if(n==0){
        return; 
    }

    //recursive case
    //1.Move n-1 disks from src to helper using rescursion
    toh(n - 1, src, dest, helper);

    //2.Take nth disk manually from src to dest
    cout<<"Taking disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    
    //3.Move n-1 disks from helper to dest using recursion
    toh(n - 1, helper, src, dest);
}
   
int main(){
    int n;
    cin>>n;

    toh(n, 'A', 'B', 'C');
    return 0;

}