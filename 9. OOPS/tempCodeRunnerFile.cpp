#include <iostream>
#include<cstring>
using namespace std;

////////////////BLUEPRINT/////////////////////////
class Car{
    private:
    int price;

    public:
    //Data Members:
    // char name[100];  //100 bytes
    char *name;       //Pointer
    int model;       //  4 bytes
    // int price;       //  4 bytes
    int seats;       //  4 bytes 
                     // Total = 112 bytes
    static int cnt;
    const int tyres;

    ///DEFAULT METHODS
    ///////////////1. DEFAULT CONSTRUCTOR/////////////////
    Car():tyres(4){
        cnt++;
        cout<<"Inside Default constructor"<<endl;
        name  = NULL;
    }

    //////////////2. PARAMETRIZED CONSTRUCTOR////////
    // Car(char *n , int p , int s , int m){
    //     cout<<"Inside Parametrized Constructor"<<endl;
    //     name  = new char[strlen(n)+1];
    //     strcpy(name,n);
    //     price = p;
    //     model =  m;
    //     seats = s;
    // }

    //////OR//////
    //////////////2. PARAMETRIZED CONSTRUCTOR////////
    Car(int p , char *n , int s , int m):tyres(4){
        cnt++;
        cout<<"Inside Parametrized Constructor"<<endl;
        name  = new char[strlen(n)+1];
        strcpy(name,n);
        price = p;
        model =  m;
        seats = s;
    }

    /////////////3. COPY CONSTRUCTOR//////////////
    Car(Car &X) : tyres(4){
        cnt++;
        cout<<"Inside Copy Constructor"<<endl;
        name = X.name;
        // name = new char[strlen(X.name) + 1];
        // strcpy(name , X.name);
        price = X.price;
        model = X.model;
        seats = X.seats;
    }

    /////////4. COPY ASSIGNMENT OPERATOR///////////
    // void operator = (Car &X){  //Operator Overloading
    //     cout<<"Inside Copy Assignment Operator"<<endl;
    //     name = new char[strlen(X.name)+1];
    //     strcpy(name , X.name);
    //     price = X.price;
    //     model = X.model;
    //     seats = X.seats;
    // }

    /////////////5. DESTRUCTOR//////////////////
    ~Car(){
        cnt--;
        cout<<"Destroying: "<<name<<endl;
    }

    // Functions:
    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Seats: "<<seats<<endl;
        cout<<"Tyres: "<<tyres<<endl<<endl;
    }

    //SetName
    void setName(char *n){
        if(name != NULL){
            delete [] name;
        }
        name = new char[strlen(n)+1];
        strcpy(name , n);
    }

    /////////////////////OPERATOR OVERLOADING/////////////////  
    void operator += (Car X){
        char *oldname = name;
        cout<<"Count of Cars: "<<cnt<<endl;

        name = new char[strlen(name) + strlen(X.name)];

        strcpy(name , oldname);

        strcat(name , X.name);

        delete [] oldname;

        price += X.price;
        seats += X.seats;

    }

    //SETTER FOR PRICE:
    void updatePrice(int p){
        if(p>800 and p<1000){
        price = p;
        }
        else{
            price = 1000;
        }
    }

    //GETTER FOR PRICE:
    int getPrice(){
        return price;
    }
};       

int Car::cnt = 0; 

int main(){

    Car A; //A is an object of class Car. 
    // A.name = "AUDI"; Wrong method

    //Correct Method:
    // A.name[0] = 'A';
    // A.name[1] = 'U';
    // A.name[2] = 'D';
    // A.name[3] = 'I';
    // A.name[4] = '\0';
    // A.name = new char[4];
    // strcpy(A.name , "AUDI");
    A.setName("AUDI");

    A.model = 2022;
    // A.price = 100;
    A.updatePrice(850); 
    cout<<A.getPrice()<<endl;
    A.seats = 4;
    // A.print();
    

    // cout<<A.name<<endl;
    // cout<<A.model<<endl;
    // cout<<A.price<<endl;
    // cout<<A.seats<<endl;
    // A.name[0]='T';
    Car B = A;
    // strcpy(B.name , "BMW");
    // B.setName("BMW");

    // B.model = 2022;
    // B.price = 150;
    // B.seats = 4;
    // B.print();
    

    // Car C("Maruti" , 500 , 2 , 2020);
    Car C = B;

    //OR
    // Car C(500 ,"Maruti", 2 , 2020);
    // C.print();

    // Car D = A;
    //OR    
    Car D(C);
    // D.print();
    // D.name[0] = 'T';

    D+=A;

    A.print();
    B.print();
    C.print();
    D.print();

    cout<<"Count of Cars: "<<Car::cnt<<endl;

    //Copy Assignment Operator:
    // D = A;
    // D.print();

    return 0;
}