#include <iostream>
using namespace std; 

void spiralPrint(int a[100][100], int r, int c){
    int sr=0 , er = r-1, sc = 0, ec = c-1;
    while(sr<=er and sc<=ec){

        //1. Print sr from sc to ec and do sr++
        int col1 = sc;
        while(col1<=ec){
            cout<<a[sr][col1]<<" ";
            col1++;
        }
        sr++;

        //2. Print ec from sr to er and do ec--
        int row1 = sr;
        while(row1<=er){
            
            cout<<a[row1][ec]<<" ";
            row1++;
        }
        ec--;

        //3. Print er from ec to sc and do er--
        // if(sr<er){
        int col2 = ec;
        while(sc<=col2){
            cout<<a[er][col2]<<" ";
            col2--;
        }
        er--;
        


        //4. Print sc from er to sr and do sc++
        // if(sc<ec){
        int row2 = er;
        while(sr<=row2){
            cout<<a[row2][sc]<<" ";
            row2--;
        }
        sc++;
        
    }

}


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

    spiralPrint(a, row, col);
     

    return 0;
} 
