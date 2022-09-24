#include <iostream>
using namespace std;

int length(char a[]){
    int i = 0;
    //int count = 0;
    for(i=0 ; a[i] != '\0' ; i++){
        //count++;
    }
    return i;
}

bool isPalindrome(char a[]){
    int i=0;
    int len = length(a);
    int j = len-1;
    while(i<j){
        if(a[i] != a[j]){
            return false;
        } 
        i++;
        j--;
    }
    return true;

}

int main(){
    char a[100] = "ABCBvA";
    if(isPalindrome(a)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}