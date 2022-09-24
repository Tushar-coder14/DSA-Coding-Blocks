#include <iostream>
using namespace std;


//   int factorial(int n){
//         if(n<=1)
//         {
//             return 1;
//         }
//         return n*factorial(n-1);     //because n!=n*(n-1)!
//     }

// int main(){
//     int a;
//     cout<<"Enter any integer"<<endl;
//     cin>>a;
//     cout<<"Factorial of "<<a<<" is "<<factorial(a)<<endl;
//      return 0;
// }
//STEP BY STEP:
// factorial(4)=4*factorial(3);
// factorial(4)=4*3*factorial(2);
// factorial(4)=4*3*2*factorial(1);
// factorial(4)=4*3*2*1;
// factorial(4)=24;
// ---------------------------------------------------------------------------------

//Q. To find nth term of a fibonacci series
// int fibo(int n){      //(Fibonacci Series:1,1,2,3,5,8,13,...)
//     if (n<2){
//     return n;
//     }
//     return fibo(n-1)+ fibo(n-2);
// }
// int main(){
//     int n;
//     cout<<"Enter nth term"<<endl;
//     cin>>n;
//     cout<<"The term in fibonacci series at position "<<n<<" is "<<fibo(n)<<endl;
//      return 0;
// }


// Coding Blocks DSA
//1> Is Array Sorted (By addressing)
bool isSorted(int *a,int n){
    //base case
    if(n==0 || n==1){
        return true;
    }

//Recursive Case
    bool kyaChotaSortedHai = isSorted(a+1,n-1);
    if(kyaChotaSortedHai == true and a[0]<=a[1]){
        return true;
    }
    else{
        return false;
    }
}
// int main(){
//     int a[]= {1,4,5,8,9};
//     int n= sizeof(a)/sizeof(int);

//     if(isSorted(a,n)) {
//         cout<<"Sorted Hai"<<endl;
//     }
//     else{
//         cout<<"Sorted nhi hai"<<endl;
//     }
//     return 0;
// }


//2> Is Array Sorted (By iterator)
bool isSorted(int *a,int n,int i){
    //base case
    if(i==n-1 || i==n){
        return true;
    }

//Recursive Case
    bool kyaChotaSortedHai = isSorted(a,n,i+1);
    if(kyaChotaSortedHai == true and a[i]<=a[i+1]){
        return true;
    }
    else{
        return false;
    }
}
// int main(){
//     int a[]= {1,4,5,8,9};
//     int n= sizeof(a)/sizeof(int);

//     if(isSorted(a,n,0)) {
//         cout<<"Sorted Hai"<<endl;
//     }
//     else{
//         cout<<"Sorted nhi hai"<<endl;
//     }
//     return 0;
// }

//3> Array Sum:
//By Address:
int arraySum(int *a,int n){
    //Base Case
    if(n==0){
        return 0;
    }

    //Recursive Case
    int c_sum=arraySum(a+1,n-1);
    return a[0] + c_sum;
}

//By iterator:
int arraySum2(int *a,int n, int i){
    //Base Case
    if(i==n){
        return 0;
    }

    //Recursive Case
    int c_sum=arraySum2(a,n,i+1);
    return a[i] + c_sum;
}

//By 3rd Method:
int arraySum3(int *a,int n){
    //Base Case
    if(n==0){
        return 0;
    }

    //Recursive Case
    int c_sum=arraySum(a,n-1);
    return a[n-1] + c_sum;
}

// int main(){
//     int a[]= {1,4,5,8,9};
//     int n= sizeof(a)/sizeof(int);

//     cout<<arraySum(a,n)<<endl;
//     cout<<arraySum3(a,n)<<endl;

//     return 0;
// }


//Q1. Power of x^n :
int power(int x , int n){
    if(n==0){
    return 1;
    }

    int pow = x*power(x,n-1);
    return pow;
}
// int main(){
//     int ans = power(2,3);
//     cout<<ans<<endl;
//     }


//Q2.Convert 2048 to string:
char a[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void IntToString(int n){
    //base case
    if(n==0){
        return ;
    }

    //recursive case
    int ld=n%10;
    cout<<a[ld]<<" ";
    IntToString(n/10);
}

void IntToString1(int n){
    //base case
    if(n==0){
        return ;
    }

    //recursive case
    int ld=n%10;
    IntToString1(n/10);
    cout<<a[ld]<<" ";
    
}
// int main(){
//     int n=2048;
//     IntToString(n);
//     cout<<endl;
//     IntToString1(n);

// }


//Q3.a)Check if array contains 7
bool check7(int *a,int n){
    //base case
    if(n==0){
        return false;
    }
    //recursive case
    if(a[0]==7){
        return true;
    }
    return check7(a+1,n-1);
} 

//b) find first index of 7 (By using address)
int first7(int *a,int n){
    //base case
    if(n==0){
        return -1;
    }

    //recursive case
    if(a[0]==7){
        return 0;
    }

    int ci = first7(a+1,n-1);
    return ci == -1 ? -1 : ci+1;  //Ternary Operator(similar to if else)

}

//b) find first index of 7 (By using iterator)
int first7_1(int *a,int n,int i){
    //base case
    if(i==n){
        return -1;
    }

    //recursive case
    if(a[i]==7){
        return i;
    }

    return first7_1(a,n,i+1);

}

//c) int all7()
int all7(int *a,int n,int i){
    //base case
    if(i==n){
        return -1;
    }

    //recursive case
    if(a[i]==7){
        cout<<i<<" ";
    }

    return all7(a,n,i+1);

}

//d) Find last index of 7
int lastIndex7(int *a, int n, int i){
    //Base case
    if(i==n){
        return 0;
    }

    //Recursive Case
    if(a[i]==7){
        return max(i, lastIndex7(a,n,i+1));
    }
    else{
    int bi=lastIndex7(a,n,i+1);
    return bi;
    }
}

// int main(){
//     int a[]={1,2,4,6,9,7,8,7,7};
//     int n=sizeof(a)/sizeof(int);
//     if(check7(a,n)){
//         cout<<"7 is present"<<endl;
//     }
//     else{
//         cout<<"7 is not present"<<endl;
//     }
    
//     cout<<first7(a,n)<<endl;
//     cout<<first7_1(a,n,0)<<endl;
//     cout<<all7(a,n,0)<<endl;
//     cout<<lastIndex7(a,n,0)<<endl;


//     return 0;
// }

//Q4. Multiply two numbers using recursion:
int multiply(int a,int b){
    //Base case
    if(b==0){
        return 0;
    }

    //Recursive Case
    int ans = a+multiply(a,b-1);
    return ans;
}
// int main(){
//     int a,b;
//     cin>>a>>b;
//     cout<<a<<"*"<<b<<"="<<multiply(a,b);

// }


//Q5. Bubble Sort using recursion
void bubbleSort(int *a, int n , int i){
    if(i == n-1){
        return;
    }
    for(int j=0; j<=n-1-i; ++j){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
            }
    }
    bubbleSort(a, n, i+1);

}

void printArray(int *a, int n , int i){
    if(i == n){
        return ;
    }
    cout<<a[i]<<" ";
    printArray(a, n, i+1);
}

// int main(){
//     int a[]= {10,4,3,5};
//     int n = sizeof(a)/sizeof(int);

//     printArray(a,n,0);
//     cout<<endl;
//     bubbleSort(a,n,0);
//     printArray(a,n,0);
//     cout<<endl;
//     return 0;

// }


