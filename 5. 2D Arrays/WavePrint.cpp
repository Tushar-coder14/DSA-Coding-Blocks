#include <iostream>

using namespace std;

int main()
{
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
    
    for(int c=0 ; c<col ; c++){
        if(c%2 == 0){
            for(int r=0 ; r<row; r++){
                cout<<a[r][c]<<" ";
            }
        }
        else{
            for(int r=row-1 ; r>=0; r--){
                cout<<a[r][c]<<" ";
            }
        }
    }
    return 0;
}

