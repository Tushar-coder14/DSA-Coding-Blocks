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

void copy(char a[], char b[]){
    int i=0;
    int lenb = length(b);
    int j = 0;
    while(j<=lenb){
        a[i++] = b[j++];
    }
}

void append(char a[] , char b[]){
    int i = length(a);
    int lenb = length(b);
    int j = 0;
    while(j<=lenb){
        a[i++] = b[j++];
    }

}

int main(){
    char a[100] = "Hello";
    char b[] = "World";
    cout<<a<<endl;
    append(a,b);    
    // copy(a,b);   -->Function to copy string B to A.
    cout<<a<<endl;
    
    return 0;
}