#include <iostream>
using namespace std;

bool isSafe(int board[100][100] , int i , int j,int n){
    int l= i , m=j;

    //Check for up and down & right and left
    for(int k=0 ; k<n ; k++){
        if(board[k][j] == 1 || board[i][k] == 1)
        return false;
    }

    //Check upper right diagonal
    while(i>=0 and j<n){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }

    //Check upper left diagonal
    while(l>=0 and m>=0){
        if(board[l--][m--]){
            return false;
        }
    }

    return true;
}



bool NQueen(int board[100][100] , int i , int n){
    //Base case:
    if(i==n){
        for(int i=0 ; i<n ; i++ ){
            for(int j=0 ; j<n ; j++){
                // cout<<board[i][j]<<" ";
                board[i][j] == 1 ? cout<<"Q" : cout<<"_";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    //recursive case:
    //Har column par iterate karo ith row ke:
    for(int j=0 ; j<n ; j++){
        // Check karlo jis cell ho waha queen rakhna safe hai ya nhi
        if(isSafe(board,i,j,n) == true){
            board[i][j] = 1; //Agar safe hai toh rakhdo

            //Ab baaki N-1 Queens recursion ko pucho usne rakhi ya nhi?
            bool kyaBaakiPlaceHui = NQueen(board, i+1 , n);

            //Agar place ho gayi to bann gayi baat
            if(kyaBaakiPlaceHui == true){
                return true;
            }
            //Agar place nahi ho paai N queens toh jo rakhi thi uski pos galat h
            board[i][j] = 0; //BackTracking
        }
    }
    return false; //Har column par check karlia kahi nhi place hui, ab return faslse
}

int main(){
    int board[100][100];

    NQueen(board,0,4);
   
    return 0;
}



// #include<iostream>
// using namespace std;

// bool isSafe(int b[11][11] , int i , int j , int n){
//     int l = i , m = j;
// 	//For vertical and horizontal:
// 	for(int k=0 ; k<n ; k++){
// 		if(b[k][j] == 1 || b[i][k] == 1 ){
// 			return false;
// 		}
// 	}

// 	//For upper right diagonal:
	
// 	while(i>=0 and j<n){
// 		if(b[i][j] == 1){
// 			return false;
// 		}
// 		i--;
// 		j++;
// 	}

// 	//For upper left diagonal:
// 	while(l>=0 and m>=0){
// 		if(b[l][m]){
// 			return false;
// 		}
// 		l--;
// 		m--;
// 	}

// 	return true;

// }

// bool NQueen(int b[11][11] , int i , int n , int &a){
// 	//base case:
// 	if(i == n){
// 		for(int i=0 ; i<n ; i++){
// 		    for(int j=0 ; j<n ; j++){
// 		        b[i][j] == 1 ? cout<<"Q" : cout<<"_";
// 		    }
// 		    cout<<endl;
// 		}
// 		cout<<endl;
// 		a +=1;
// 		return false;
// 	}

// 	//recursive case:
// 	for(int j=0 ; j<n ; j++){
// 		if(isSafe(b , i , j , n) == true){
// 			b[i][j] = 1;
// 			bool baakiHui = NQueen(b , i+1 , n , a);
// 			if(baakiHui == true){
// 				return true;
// 			}
// 			b[i][j] = 0; //back-tracking
// 		}
// 	}
// 	return false;
// }

// int main() {
// 	int n = 4;
// // 	cin>>n;
// 	int b[11][11];
// 	int cnt = 0;
// 	NQueen(b , 0 , n , cnt);
// 	cout<<cnt<<endl;

// 	return 0;
// }
