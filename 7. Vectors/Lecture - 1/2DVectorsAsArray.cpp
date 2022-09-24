#include <iostream>
#include<vector>
using namespace std;

//MACROS:
#define NFV(v,rows,cols) for(int i=0; i<rows; i++)\
{\
        for(int j=0; j<cols; j++)\
        {\
            cout<<v[i][j]<<" ";\
        }\
        cout<<endl;\
    }\


int main(){

    int rows,cols;
    cin>>rows>>cols;
    
    //SYNTAX:
    //vector<vector<data_type>> v(rows, vector<data_type>(cols, initial_value));

    vector<vector<int> > v(rows, vector<int>(cols,1));
    
    NFV(v, rows, cols);
    cout<<endl;
    NFV(v, rows, cols);

    // for(int i=0; i<v.size(); i++){
    //     for(int j=0; j<v[i].size(); j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}