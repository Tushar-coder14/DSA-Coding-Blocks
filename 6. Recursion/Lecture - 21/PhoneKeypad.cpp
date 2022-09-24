#include <iostream>
using namespace std;

char keys[][10] = {
    "","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"
};

string contacts[100] = {
    "TUSHAR",
    "ANIKET",
    "NOBITA",
    "KULDEEP",
    "AB",
    "VARUN"
};

void PhoneKeypad(char in[] , int i ,char out[], int j){
    //Base case:
    if(in[i] == '\0'){
        out[j] = '\0';
        // cout<<out<<endl;
        string x(out);  //x is converted to string whose value is same as out.
        for(int i=0 ; i<6 ; i++){
            if(x == contacts[i]){
                cout<<x<<endl;
            }
        }
        return;
    }

    //Recursive case:
    int d = in[i] - '0';
    for(int k=0 ; keys[d][k] != '\0' ; k++){
        out[j] = keys[d][k];
        PhoneKeypad(in , i+1 , out  ,j+1 );
    }

}

int main(){
    char in[100], out[100];
    cin>>in;
    PhoneKeypad(in , 0 , out, 0);
    return 0;
}