#include <iostream>
using namespace std;

template<typename T>
class Vector {
    public:
    T *a;
    int cs;
    int cap;

    //Constructor: To allocate memory to array "a"
    Vector(int s=1){
        a = new T[s];
        cs = 0;
        cap = s;
    }


    void push_back(T data){
        if (cs == cap){
            //Storing old array;
            T* olda = a;
            int olds = cs;

            //Creating new array of double capacity
            a = new T[2*cap];
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
    cout<<"empty array"<<endl;
        }
    else{
        cout<<"Not empty"<<endl;
    }
        }
        

    int size(){
        return cs;
    }

    int capacity(){
        return cap;
    }

    T operator [] (int index){
        return a[index];
    } 

};

int main(){
    Vector<char> v;
    v.push_back('A');
    v.push_back('B');
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    cout<<"size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    for(int i=0 ; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    v.empty();
    return 0;
}