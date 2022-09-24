#include <iostream>
using namespace std;

int main(){
    int a[100][100];
    int row,col;
    cout<<"Enter no. of rows and columns: "<<endl;
    cin>>row>>col;
   

    int val =1;
    for(int r=0 ;r<row ; r++){
        for(int c=0 ;c <col ; c++){
            a[r][c] = val;
            val++;
        }
    }

    for(int r=0 ;r<row ; r++){
        for(int c=0 ;c <col ; c++){
                cout<<a[r][c]<<" ";
            }
            cout<<endl;
        }

    cout<<"Enter key to Search:"<<endl;
    int key;
    cin>>key;

    bool isKeyPresent = false;
    for(int r=0 ;r<row ; r++){
        for(int c=0 ;c <col ; c++){
            if(a[r][c] == key){
                cout<<"Key found at: "<<r<<","<<c<<endl;
                isKeyPresent = true;
                break;
            }
        }
        if(isKeyPresent == true){
            break;
        }
    }

    if(isKeyPresent ==false){
        cout<<"Key not found"<<endl;
    }


    return 0;
}