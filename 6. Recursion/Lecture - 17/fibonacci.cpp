#include<iostream>
using namespace std;


 int fibo(int n){      //(Fibonacci Series: 0 ,1 ,1 ,2 ,3 ,5 ,8 ,13 ,21 ,34 , ...)
    if (n==0 || n==1){          // Position        :  0 1  2  3  4  5  6   7  8   9     
    return n;
    }
    return fibo(n-1)+ fibo(n-2);
}
int main(){
    int n;
    cout<<"Enter nth term"<<endl;
    cin>>n;
    cout<<"The term in fibonacci series at position "<<n<<" is "<<fibo(n)<<endl;
     return 0;
}
