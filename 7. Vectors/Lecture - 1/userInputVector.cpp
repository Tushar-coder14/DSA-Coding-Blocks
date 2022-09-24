#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n = 5;
    // cin>>n;

    // vector<int> v(n);  //Ek vector bana raha hai of n buckets/capacity

    //To declare same values to all elements of array:
    vector<int> v(n, 20);


    // v.push_back(10);
    // cout<<v.size()<<endl;
    // cout<<v.capacity()<<endl;



    // for(int i = 0; i < n; i++){
    //     cin>>v[i];
    // }

    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;


    return 0;
}