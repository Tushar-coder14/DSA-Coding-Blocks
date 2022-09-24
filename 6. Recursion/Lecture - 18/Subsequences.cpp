#include <iostream>
using namespace std;

void subsequences(char in[], char out[], int i , int j){
    //Base case:
    if(in[i] == '\0'){
        out[j]=  '\0';
        cout<<out<<endl;
        return;
    }

    //Recursive Case:
    //1. ith character ko output mein mat lo:
    subsequences(in, out, i+1, j);

    //2. ith character ko output mein lo:
    out[j] = in[i];
    subsequences(in , out, i+1 , j+1);
}

int main(){

    char in[100] = "abc";
    char out[100];

    subsequences(in , out, 0,0);
    
    return 0;
}