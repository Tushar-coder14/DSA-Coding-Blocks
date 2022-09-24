#include <iostream>
using namespace std;

void readString(char a[]){
    char ch;
    ch = cin.get();
    int i = 0;
    while(ch != '\n'){
        a[i] = ch;
        i++;
        ch = cin.get();
    }
    a[i] = '\0';
}

void printString(char a[]){
    for(int i=0 ; a[i] != '\0' ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    char a[100];
    // cin>>a;

    // readString(a);

    // cin.getline(array_name , size , delimiter); //By default delimiter is '\n'
    // cin.getline(a,6); //One size is fixed for NULL.
    cin.getline(a,15,'*');

    printString(a);

    cout<<a<<endl;
    return 0;
}