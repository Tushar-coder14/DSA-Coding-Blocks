#include <iostream>
#include<cmath>
using namespace std;

bool isSafe(int mat[9][9] , int i , int j , int n , int no){
    //Row and column mein nhi hona chaiye number:
    for(int k=0 ; k<n ; k++){
        if(mat[i][k] == no || mat[k][j] == no){
            return false;
        }
    }

    //Lets iterate over the smaller box
    n = sqrt(n); // n = 3
    int si = (i/n) * n;
    int sj = (j/n) * n;

    for(int k = si ; k < si+n ; k++){
        for(int l = sj ; l< sj+n ; l++){
            if(mat[k][l] == no){
                return false;
            }
        }
    }
    return true;
}



bool SudokuSolver(int mat[9][9] , int i , int j , int n){
    //Base case:
    if(i == n){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    //Recursive Case:
    if(j == n){
        return SudokuSolver(mat , i+1 , 0, n);
    }
    
    if(mat[i][j] != 0){
        return SudokuSolver(mat, i , j+1, n);
    }

    //Ek empty cell ka kaam yaha par kar rhe h sabse pehle
    for(int no = 0 ; no<=n  ; no++){
        if(isSafe(mat, i, j, n , no)){
            mat[i][j] = no;
            bool kyaBaakiSolveHua = SudokuSolver(mat , i , j+1 , n);
            if(kyaBaakiSolveHua ==true){
                return true;
            }
        }
        mat[i][j] = 0; //Backtracking
    }
    return false;
}

int main(){
    
    int mat[9][9] =
	{	{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

    SudokuSolver(mat, 0 , 0 ,9);

    // if(SudokuSolver(mat, 0 , 0 ,9) == 0){
    //     cout<<"Entered Wrong matrix of Sudoku"<<endl;
    // }

    return 0;
}