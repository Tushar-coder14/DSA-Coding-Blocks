#include <iostream>
#include<vector>
using namespace std;

#define pb push_back

int main(){
    int n;
    cin>>n;

    vector<vector<int> > v(n);

    v[0].pb(1);
    v[0].pb(2);
    v[0].pb(3);
    // v[0].pb(3);
    // v[0].pb(3);
    v[1].pb(2);
    v[1].pb(3);
    v[2].pb(4);
    v[3].pb(5);
    v[3].pb(6);
    v[3].pb(7);

    for(int i=0 ; i<v.size(); i++){
        cout<<"Row "<<i<<" : ";
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
        cout<<v[i].capacity()<<endl;
    }

    //OR
    // vector<vector<int> > v;

	// vector<int> v1({1, 2, 3, 4});
	// vector<int> v2({1, 2, 3, 4, 5, 6});
	// vector<int> v3({1, 2});
	// vector<int> v4({1, 2, 9, 10, 11, 12, 13});

	// v.push_back(v1);
	// v.push_back(v2);
	// v.push_back(v3);
	// v.push_back(v4);

	// for (int i = 0 ; i < v.size() ; i++) {
	// 	for (int j = 0; j < v[i].size(); ++j)
	// 	{
	// 		cout << v[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
    return 0;
}