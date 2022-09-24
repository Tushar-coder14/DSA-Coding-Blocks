#include <iostream>
using namespace std;

class Vector{
    public:
    int cs;
    int cap;
    int *a;

    //Constructor: To allocate memory to array "a"
    Vector(int s=1){
        a = new int[s];
        cs = 0;
        cap = s;
    }

    void push_back(int d){
        if(cs ==cap){
            int *olda = a;
            int oldcap = cap;

            a = new int[2*cap];
            cap *= 2;
            for(int i=0 ; i<oldcap ; i++){
                a[i] = olda[i];
            }
            delete [] olda;
        }
        a[cs++] = d;
    }

    void pop_back(){
        if(cs>0){
        cs--;
        }
    }

    bool empty(){
        // if(cs == 0){
        //     return true;
        // }
        // return false;
        
    //OR
    return cs==0;
    }

    int size(){
        return cs;
    }

    int capacity() {
        return cap;
    }

    //Operator Overloading:
    int operator[](int i){
        return a[i];
    }

};

int main(){

    Vector v;

    v.push_back(1);    
    v.push_back(2);    
    v.push_back(3);    
    v.push_back(4);    
    v.push_back(5);

    cout<<v.capacity()<<endl;
    cout<<v.size()<<endl;

    for(int i=0 ; i<v.size() ; i++){
        cout<<v[i]<<" ";
    }    
    cout<<endl;
    return 0;
}