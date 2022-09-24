#include <iostream>
using namespace std;

string a[10] = {"Zero", "One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

void intToString(int n){
    if(n==0){
        return;
    }
    

    //Recursive Case:
    int last_digit = n%10;
    cout<<a[last_digit]<<" ";
    intToString(n/10);
}

void intToString1(int n){
    if(n==0){
        return;
    }
    

    //Recursive Case:
    int last_digit = n%10;
    intToString1(n/10);
    cout<<a[last_digit]<<" ";
}

int main(){
    int n = 2048;
    intToString(n);
    cout<<endl;
    intToString1(n);

    return 0;
}