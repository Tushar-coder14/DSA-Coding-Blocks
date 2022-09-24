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

int main(){
    char a[100] = "Code with Fun";
    cout<<length(a)<<endl;
    return 0;
}