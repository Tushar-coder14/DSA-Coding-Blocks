#include<iostream>
#include<cstring>
using namespace std;

int stringToInt(char *a, int n ){
    //Base Case
    if(n == 0 ){
        return 0;
    }

    //Recursive Case
    int ld = a[n-1] - '0';
    return stringToInt(a,n-1) * 10 + ld;
}
int main(){
    char a[100]= "1123";
    int n = strlen(a);
    int ans = stringToInt(a, n);
    cout<<ans;

    return 0;

}