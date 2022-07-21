#include <iostream>
using namespace std; 

int main(){ 
    int r,c;
    cin>>r>>c;
    int a[r][c];

    for(int i=0; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            cin>>a[i][j];
        }
    }

    int key;
    cin>>key;
    bool keyFound = false;
     for(int i=0; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            if(key == a[i][j]){
                keyFound = true;
                cout<<"Key found at: "<<i<<j<<endl;
                break;
            }
        }
        if(keyFound == true){
                break;
            }
    }

    if(keyFound == false){
            cout<<"Key not Found"; 
        }

    return 0;
} 
