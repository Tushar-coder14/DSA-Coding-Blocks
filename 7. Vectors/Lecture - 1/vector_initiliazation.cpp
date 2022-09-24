#include <iostream>
#include<vector>
using namespace std;

int main(){
    // Initialization way: 1
    // 1st way:
    vector<int> v = {1, 2, 3, 4, 5};

    //2nd way:
    // vector<int> v({1,2,3,4,5});


    // Initialization Way: 2 (using array)
    // int a[] = {1, 2, 3, 4, 5, 6, 7};
    // int n = sizeof(a)/sizeof(int);

    // vector<int> v(a, a+n); //To make vector from array

    // for(int i=0 ; i<v.size(); i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;

    //OR

    // Initialization Way: 3(using array)
    vector <int> v;

    for(int i=1 ; i<=5 ; i++){
        cout<<"Inserting: "<<i<<" :: ";
        v.push_back(i);
        cout<<"Size:"<<v.size()<<", Capacity: "<<v.capacity()<<endl;
    }

    return 0;
}