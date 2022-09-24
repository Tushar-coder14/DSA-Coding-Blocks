#include <iostream>
using namespace std;

///////BLUEPRINT////////
class Car {
    private:
    int price;
    const int tyres;

    public:
    //Data Members:
    char *name = new char[1000];
    // int price;
    int mileage;
    int model;
    static int cnt;


    /////DEFAULT FUNCTIONS/////

    // Constructors: By default hota hai, bus dikhta nhi   // Constructor is called when object of class is made.

    //////////////1. Default Constructor///////////////////////////////////
    Car(): tyres(4), name(NULL){
    cout<<"Inside Default Constructor"<<endl;
    // name = NULL;
    // tyres = 4; //Assignment   //We cannot store tyres like this because it is a constant integer.
    cnt++;
    }

    ///////////////2. Parametrized Constructor///////////////////////////////
    Car(char *n, int p, int m, int mil): tyres(4), price(p), model(m), mileage(mil) {
        cout<<"Inside Parametrized Constructor"<<endl;
        name  = new char[strlen(n) + 1];
        strcpy(name,n);
        // price = p;
        // model = m;
        // mileage = mil;
        cnt++;
    }

    ///////////////////3. Copy Constructor/////////////////////////////////
    // D = C;
    Car(Car &X):tyres(4) {
        cout<<"Inside Copy Constructor"<<endl;
        name  = new char[strlen(X.name + 1) + 1];
        strcpy(name, X.name);
        price = X.price;
        mileage = X.mileage;
        model = X.model;
    }

    /////////////////4. Copy Assignment Operator (=)//////////////////////
    void operator=(Car &X){
        cout<<"Inside Copy Assignment Operator"<<endl;
        if(name != NULL){
            delete [] name;
        }
        name = new char[strlen(X.name) + 1];
        strcpy(name, X.name);
        price = X.price + 700;
        model = X.model;
        mileage = X.mileage;

    }

    ///////////////////5. Destructor: Object ko destroy karta hai///////////////   
    ~Car () {
        cout<<"Deleting Car: "<<name<<endl;
        cnt--;
    }


    //////FUNCTION//////
    void print(){
    cout<<"Name      :"<<name<<endl;
    cout<<"Price     :"<<price<<endl;
    cout<<"Mileage   :"<<mileage<<endl;
    cout<<"Model     :"<<model<<endl<<endl;
    }


    void setName(char *n){
        if(name != NULL){
            delete [] name;
        }
        name  = new char[strlen(n) + 1];
        strcpy(name, n);

    }

    //////////////////OPERATOR OVERLOADING/////////
    void operator += (Car&X) {
        char* temp = name;
        name = new char[strlen(name) + strlen(X.name) + 1];
        strcpy(name, temp);
        strcat(name, X.name);  //To add two strings
        delete [] temp;
        temp = NULL;

        price += X.price;
        model += X.model;
        mileage += X.mileage;
       
    }


    ////////////////////GETTER & SETTER//////////
    // 1. SETTER:
    void setPrice(int p){
        if (p > 100 and p < 200) {
            price = p;
        }
        else{
            price  = 150;
        }
    }
    // 2. GETTER:
    int getPrice() {
        return price;
    }

};
int Car::cnt = 0;

int main(){

    // 1. Default Constructor: 
    Car A; //Object of class Car

    // A.name = "AUDI"; Wrong method

    //Correct Method:
    // A.name[0] = 'A';
    // A.name[1] = 'U';
    // A.name[2] = 'D';
    // A.name[3] = 'I';
    // A.name[4] = '\0';

    // strcpy(A.name, "AUDI");

    A.setName("AUDI");

    // A.price = 10000;
    A.setPrice(120);   //Because price is private member and hence not accessible by "A.price".
    A.getPrice();
    A.mileage = 10;
    A.model = 2020;
    // cout<<"Name      :"<<A.name<<endl;
    // cout<<"Price     :"<<A.price<<endl;
    // cout<<"Mileage   :"<<A.mileage<<endl;
    // cout<<"Model     :"<<A.model<<endl;
    A.print();

    Car B;
    // strcpy(B.name, "BMW");
    B.setName("BMW");
    // B.price = 150;
    B.setPrice(200);
    B.getPrice();
    B.mileage = 8;
    B.model = 2022;
    B.print();

    // 2. Parametrized Constructor:
    Car C("Volvo", 1500, 2022, 10);
    C.print();

    // 3. Copy Constructor : Jab new car banani h aur usme dusre car ki details store karni ho
    Car D = C; //OR Car D(C);    //Details of Car C will be copied to new Car D.
    D.print();

    D.name[0] = 'T';
    D.print();

    // 4. Copy Assignment Operator(=) : Jab car already bani hui h bus details copy karni ho.
    D = B;
    D.print();

    cout<<"Checking the operator OVERLOADING: "<<endl;
    A+=B; //A = A + B;
    A.print();

    cout<<A.cnt<<endl;
    cout<<Car::cnt<<endl;    




return 0;
}