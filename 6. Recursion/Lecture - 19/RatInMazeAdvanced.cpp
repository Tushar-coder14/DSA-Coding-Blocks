#include <iostream>
using namespace std;

bool RatInMaze(char maze[][100] , int sol[][10] , int i  , int j ,int n ,int m){
    //Base case:
    if(i == n-1 and j == m-1 ){
        sol[i][j] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        // cout<<endl;
        return true;
        
    }

    //Recursive case:
    sol[i][j] = 1; //Ho sakta hai i,j solution ka part ho

    //1. Check right se raasta mila? --> (i,j+1)
    if(j+1<m and maze[i][j+1] != 'X' and sol[i][j+1] != 1){
        bool kyaRightSeRaastaMila = RatInMaze(maze,sol,i,j+1,n,m);
        if(kyaRightSeRaastaMila == true){
            return true;
        }
    }

    //2. Check neeche se raasta mila? --> (i+1,j)
    if(i+1<n and maze[i+1][j] != 'X' and sol[i+1][j] != 1){
        bool kyaNeecheSeRaastaMila = RatInMaze(maze,sol,i+1,j,n,m);
        if(kyaNeecheSeRaastaMila == true){
            return true;
        }
    }

    //3. Check backwards se raasta mila? --> (i,j-1)
    if(j-1 >=0 and maze[i][j-1] != 'X' and sol[i][j-1] != 1){
        bool kyaBackwardsSeRaastaMila = RatInMaze(maze,sol,i,j-1,n,m);
        if(kyaBackwardsSeRaastaMila == true){
            return true;
        }
    }

    //4. Check upwards se raasta mila? --> (i-1,j)
    if(i-1>= 0 and maze[i-1][j] != 'X' and sol[i-1][j] != 1){
        bool kyaUpwardSeRaastaMila = RatInMaze(maze , sol, i-1,j,n,m);
        if(kyaUpwardSeRaastaMila == true){
        return true;
        }
    }

    sol[i][j] = 0;
    return false;
}


int main(){
    
    char maze[][100] = {
        "0X000",
        "0X0X0",
        "000X0",
        "XXXX0"
    };

    int sol[10][10] = {0};

    RatInMaze(maze,sol,0,0,4,5);
    return 0;
}