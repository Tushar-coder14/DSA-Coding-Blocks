#include <iostream>
using namespace std;

void getLine(char a[] , int s , char delimiter = '\n'){
    char ch;
    ch = cin.get();
    int i=0;
    while(ch != delimiter and i<s-1){
        a[i] = ch;
        i++;
        ch = cin.get();
    }
    a[i] = '\0';
}

int main(){
    char a[100];
    getLine(a,20,'%');
    cout<<a<<endl;
    
    return 0;
}