#include <iostream>
#include<vector>
using namespace std;
#define pb push_back

int main(){
    int n;
    cin>>n;

    vector<vector<int> > v(n);

    v[0].pb(1);
    v[1].pb(2);
    v[1].pb(3);
    v[2].pb(4);
    v[3].pb(5);
    v[3].pb(6);

    for(int i=0 ; i<v.size(); i++){
        cout<<"Row"<<i<<": ";
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}