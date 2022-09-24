#include <iostream>
using namespace std;

int main(){
    int a[] = {1,8,-5,13,-10,8};
    // int a[] = {1,-2,4,1,-3,5,-10};
    int n = sizeof(a)/sizeof(int);
    int sum = 0;
    int max_sum = INT_MIN;
    int start = 0 ,  end = 0;
    int s;

    for(int i=0 ; i<n ; i++){
        sum += a[i];
        if(sum<0){
            sum = 0;
            s = i+1;
        }

        if(sum>max_sum){
            end = i;
            start = s;
        }
        max_sum = max(max_sum,sum);
    }

    cout<<"{"<<start<<","<<end<<"}"<<endl;
    cout<<max_sum<<endl;
    return 0;
}