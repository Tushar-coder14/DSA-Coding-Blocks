#include <iostream>
using namespace std; 

void spiralPrint(int a[100][100], int r, int c){
    int sr=0 , er = r-1, sc = 0, ec = c-1;
    while(sr<=er and sc<=ec){

        //1. Print sr from sc to ec and do sr++
        int row = sc;
        while(row<=ec){
            cout<<a[row][sc]<<" ";
            row++;
        }
        sr++;

        //2. Print ec from sr to er and do ec--
        int col1 = sr;
        while(col1<=er){
            
            cout<<a[ec][col1]<<" ";
            col1++;
        }
        ec--;

        //3. Print er from ec to sc and do er--
        int col = ec;
        while(col>=ec){
            cout<<a[er][col]<<" ";
            col--;
        }
        er--;


        //4. Print sc from er to sr and do sc++
        int row2 = er;
        while(row2>=er){
            cout<<a[row2][sc]<<" ";
            row2--;
        }
        sc++;
    }

}


int main(){ 
    int a[100][100];
    int r,c;
    cin>>r>>c;
    

    for(int i=0; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            cin>>a[i][j];
        }
    }

    spiralPrint(a, r, c);
     

    return 0;
} 
