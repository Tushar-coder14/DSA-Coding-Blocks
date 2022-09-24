#include <iostream>
using namespace std;

int main(){
    int a[] = {1,3,5,7};
    int n = sizeof(a) / sizeof(int);
    int t = 8;

    bool isAnsFound = false;
    for(int i=0 ; i<n ; i++){
        if(a[i] == t || a[i]>t){
            cout<<i<<endl;
            isAnsFound = true;
        }
    }

    if(t>a[n-1] && isAnsFound == false){
        cout<<n<<endl;
    }

    return 0;
}