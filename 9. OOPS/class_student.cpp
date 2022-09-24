#include <iostream>
using namespace std;

class student{
    private:
    int marks;
    
    public:
    char* name = new char[1000];
    int roll;
    char branch[4];
    static int count;

    ////////CONSTRUCTORS//////
    // 1.Constructor:
    student(){
        cout<<"Inside Default Constructor"<<endl;
        name = NULL;
        count ++;
    }

    // 2. Parametrized Constructor:
    student(char *n, int roll, char branch[], int marks){
        cout<<"Inside Parametrized COnstructor"<<endl;
    }

    void print(){
        cout<<"Name       :"<<name<<endl;
        cout<<"Roll No.   :"<<roll<<endl;
        cout<<"Branch     :"<<branch<<endl;
        cout<<"Marks      :"<<marks<<endl;

    }

    //1. SETTER:
    void setMarks(int n){
        if(marks>30 and marks<45)
        marks  = 40;
        else
        marks = 25;
    }
    //2. GETTER:
    int getMarks(){
    return marks;
    }
};
int student::count = 0;

int main(){
    student s1;
    

    
    return 0;
}