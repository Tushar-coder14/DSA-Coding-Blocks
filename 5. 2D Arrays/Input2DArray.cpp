#include <iostream>
#include<string>
using namespace std;

int main(){
    // int a[4][4];
    // int row,col;

    // cout<<"Enter rows and columns"<<endl;
    // cin>>row>>col;
    // for(int r = 0 ; r<row ; r++){
    //     for(int c = 0 ; c<col ; c++){
    //         cin>>a[r][c];
    //     }
    // }

    // for(int r = 0 ; r<row ; r++){
    //     for(int c = 0 ; c<col ; c++){
    //         cout<<a[r][c]<<" ";
    //     }
    //     cout<<endl;
    // }

//Character 2D Array:
//    char b[][5] = {
//         {'A','M','A','N' , '\0'},
//         {'T','O','M','S', '\0'},
//         {'M','O','M','S', '\0'}
//     };
//     int row = 3;


//     for(int r=0 ; r<row ; r++){
//         cout<<b[r]<<endl;
//     }

//     //Print character by character:
//     for(int r=0 ; r<row ; r++){
//         for(int c=0 ; b[r][c] != '\0' ; c++){
//             cout<<b[r][c]<<" ";
//         }
//         cout<<endl;
//     }

    // //Taking input of 2D character array (without space like "Coding"):
    // char arr[100][100];
    // int row;
    // cout<<"Enter no. of strings to input: "<<endl;
    // cin>>row;
    // //In strings NULL is added to end by default.

    // for(int r=0 ; r<row ; r++){
    //     cin>>arr[r];
    // }

    // for(int r = 0 ; r<row ; r++){
    //     cout<<arr[r]<<endl;
    // }


    // //Print character by character:
    // for(int r=0 ; r<row ; r++){
    //     for(int c=0 ; arr[r][c] != '\0' ; c++){
    //         cout<<arr[r][c]<<" ";
    //     }
    //     cout<<endl;
    // }


//   Taking Input of 2D Array for spaced character like "Coding Blocks" :
    char arr[100][100];
    int row;
    cout<<"Enter no. of strings to input: "<<endl;
    cin>>row;
    cin.get(); //or cin.ignore();

    for(int r=0 ; r<row ; r++){
        cin.getline(arr[r],100);
    }

    for(int r = 0 ; r<row ; r++){
        cout<<arr[r]<<endl;
    }


    //Print character by character:
    for(int r=0 ; r<row ; r++){
        for(int c=0 ; arr[r][c] != '\0' ; c++){
            cout<<arr[r][c]<<" ";
        }
        cout<<endl;
    }





    return 0;
}