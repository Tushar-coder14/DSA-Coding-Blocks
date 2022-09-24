#include <iostream>
using namespace std;

int main(){
    char a[] = {'A','B','C','D','\0'};
    char b[] = {'A','B','C','D','\0'};
    // char c[] = "ABCD"; //Automatically adds NULL at the end as it is string
    char c[5] = "ABCD";
    cout<<"A:"<<a<<endl;
    cout<<"B:"<<b<<endl;
    cout<<"C:"<<c<<endl;
    return 0;
}