#include <iostream>
using namespace std;

int length(char a[]){
    int i = 0;
    //int count = 0;
    for(i=0 ; a[i] != '\0' ; i++){
        //count++;
    }
    return i;
}

void copy(char largest[], char a[]){
    int i=0 , j=0;
    int lena = length(a);
    while(j<=lena){
        largest[i++] = a[j++];
    }
}

int main(){
    char largest[100];
    char a[100];
    int largest_len = 0;
    int n;
    cin>>n;
    cin.get(); // OR cin.ignore();
    for(int i=0 ; i<n ; i++){
        cin.getline(a,100);
        int len = length(a);
        if(len>largest_len){
            copy(largest , a);
            largest_len = len;
        }
    }

    cout<<"Largest String: "<<largest<<endl;
    cout<<"Largest String Length: "<<largest_len<<endl;

    return 0;
}