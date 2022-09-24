#include <iostream>
#include<vector>
using namespace std;

int main(){
    //vector<int> v(no._of_buckets , initial_value);
    //vector <int> v(10000); //Capacity: 10000

    int n;
    cin>>n;
    vector <int> v(n,10);
    cout<<v.capacity()<<endl;

    for(int i=0 ; i<n ; i++){
        v[i] = i+1;
    }

    reverse(v.begin(), v.end()); //Sorting in descending order
    v.clear();
    cout<<v.size()<<endl;
    
    for(int i=0 ; i<n ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}