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

//Bring n characters from end to the front
void rotateString(char a[] , int lena , int n){
    int j=0;
    int i = lena;
    while(j<n){
        a[j] = a[i];
        i++;
        j++;
    }
}

int main(){
    char a[100] = "Coding";
    int n=4;
    int lena = length(a);
    if(n>lena){
        n = n%lena;
    }

    //Move all characters forward by n positions to make space.
    int i = lena-1;
    while(i>=0){
        a[i+n] = a[i];
        i--;
    }
    cout<<a<<endl;

    rotateString(a,lena ,n);

    //Add NULL to the lena position:
    a[lena] = '\0';
    cout<<a<<endl;

    return 0;
}