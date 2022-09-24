#include <iostream>
using namespace std;

void permutation(char a[] , int i){
    //Base case:
    if(a[i] == '\0'){
        cout<<a<<endl;
        return;

    }

    //Recursive Case:
    for(int j=i ; a[j] != '\0' ; j++){
        swap(a[j] , a[i]);
        permutation(a, i+1);
        swap(a[j] , a[i]);
        }

}

int main(){
    
    char a[] = "abc";
    permutation(a,0);
    return 0;
}