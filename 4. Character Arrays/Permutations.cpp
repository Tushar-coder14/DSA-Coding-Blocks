#include <iostream>
using namespace std;

int main(){
    char a[] = "abac";
    char b[] = "baca";
    int freq[26] = {0};

    for(int i=0 ; a[i] != '\0' ; i++){
        char ch = a[i];
        int index = ch - 'a';  //int index = ch - 97;

        freq[index]++;
    }

    for(int i = 0 ; i<26 ;i ++){
        cout<<freq[i]<<" ";
    }
    cout<<endl;

    for(int i=0 ; b[i] != '\0' ; i++){
        char ch = b[i];
        int index = ch - 'a';

        freq[index]--;
    }

    bool isPermutation = true;
    for(int i = 0 ; i<26 ;i ++){
    if(freq[i] != 0){
        isPermutation  = false;
        break;
    }
    }

    if(isPermutation){
        cout<<"Permutation"<<endl;
    }
    else{
        cout<<"Not a Permutation"<<endl;
    }
    return 0;
}