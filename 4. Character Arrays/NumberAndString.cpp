#include <iostream>
using namespace std;

int main(){
    char a[100];
    int n;
    cin>>n;
    cin.get(); //OR cin.ignore();

    cin.getline(a,10,'$');
    cout<<n;
    cout<<a;
    return 0;
}