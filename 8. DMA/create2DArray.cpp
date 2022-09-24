#include <iostream>
using namespace std;

int main(){
    int rows, columns;
    cin>>rows>>columns;


    int ** a = new int*[rows];
    for(int i=0; i<rows; i++){
        a[i] = NULL;
    }

    for(int i = 0; i  < rows; i++){
        a[i] = new int[columns];
    }

    /////CREATE 2D Array
    int number=1;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            a[i][j] = number++;
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    //////DELETE 2D DYNAMIC ARRAY
    for(int i=0; i<rows; i++){
        delete []a[i];
    }

    delete []a;
    a = NULL;
    

    return 0;
}