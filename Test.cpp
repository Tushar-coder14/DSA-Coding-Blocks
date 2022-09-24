#include <iostream>
#include<cmath>

using namespace std;

bool isPrime(int n){
    for (int i=2 ; i<=sqrt(n) ; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

//OR

bool isPrime1(int n){
    for (int i=2 ; i*i<=n ; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

//OR

bool isPrime2(int n){
    if(n!=2 and n%2 == 0) return false;
    // BigO(sqrt(N)/2)
    for(int i=3 ; i<=sqrt(n); i+=2){

        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void primeSieve(int n){
    bool *a = new bool[n+1];
    for(int i=0 ; i<=n ; i++){
        a[i] = true;
    }

    for(int i=2 ; i<=n ; i++){
        if(a[i] == true){
            for(int j=2*i ; j<=n ; j+=i){
                a[j] = false;
            }
        }
    }

    for(int i=2 ; i<=n ; i++){
        if(a[i] == true){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main(){

    int n;
    cin>>n;

    if (isPrime(n)){
        cout<<"Prime"<<endl;
    }
    else{
        cout<<"Not Prime"<<endl;
    }

    for(int i=2 ; i<=n ; i++){
        {
            if(isPrime2(i)){
                cout<<i<<" ";
            }
        }
    }
    cout<<endl;

    primeSieve(n);

    
    return 0;
}

