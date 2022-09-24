#include <iostream>
using namespace std;

int main(){
    int x=0 , y=0;
    char ch = cin.get(); 
    //cin.get() is used to input single character and also inputs white space characters like tab(\t), new line(\n) and spaces.

    while(ch != '\n'){
        if(ch == 'E'){
            x++;
        }
        else if(ch == 'N'){
            y++;
        }
        else if(ch == 'W'){
            x--;
        }
        else if(ch == 'S'){
            y--;
        }
        ch = cin.get();
    }

    //1st quad:
    if(x>=0 && y>=0){
        while(x){
            cout<<"E";
            x--;
        }
        while(y){
            cout<<"N";
            y--;
        }
    }

    //2nd quad:
    else if(x<=0 && y>=0){
        x *= -1;
        while(y){
            cout<<"N";
            y--;
        }
        while(x){
            cout<<"W";
            x--;
        }
    }

    //3rd quad:
    else if(x<=0 && y<=0){
        x *= -1;
        y *= -1;
        while(y){
            cout<<"S";
            y--;
        }
        while(x){
            cout<<"W";
            x--;
        }
    }

    //4th quad:
    else if(x>=0 && y<=0){
        y *= -1;
        while(x){
            cout<<"E";
            x--;
        }
        while(y){
            cout<<"S";
            y--;
        }
    }
    cout<<endl;

    return 0;
}