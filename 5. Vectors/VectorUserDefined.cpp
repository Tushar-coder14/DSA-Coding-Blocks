#include <iostream>
using namespace std;

class Vector {
    public:
    int *a;
    int cs;
    int cap;

    //Constructor: To allocate memory to array "a"
    Vector(int s=1){
        a = new int[s];
        cs = 0;
        cap = s;
    }


    void push_back(int data){
        if (cs == cap){
            //Storing old array;
            int* olda = a;
            int olds = cs;

            //Creating new array of double capacity
            a = new int[2*cap];
            cap = 2*cap;

            //Storing elements of old array to new array
            for(int i=0 ; i<olds ; i++){
                a[i] = olda[i];
            }

            //Deleting old array
            delete [] olda;
        }
        a[cs] = data;
        cs++;
    }  

    void pop_back() {
        if(cs>0){
            cs--;
        }
    }

    void empty() {
        if (cs == 0){
    cout<<"empty array";
        }
    else{
        cout<<"Not empty";
    }
        }
        

    int size(){
        return cs;
    }

    int capacity(){
        return cap;
    }

    int operator [] (int index){
        return a[index];
    } 

};

int main(){
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout<<"size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    for(int i=0 ; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    v.empty();
    return 0;
}