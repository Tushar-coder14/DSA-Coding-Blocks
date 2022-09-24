#include <iostream>
using namespace std;

int main(){
    
    //Initialization:
    string s = "Hello World";
    string s1("Hello World");
    
    char a[] = "Hello Coding!";
    string s2(a);

    cout<<s<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;

    string x = "Hello";
    string y = "Zello";
    int ans = x.compare(y);

    if(ans==0){
        cout<<"X and Y are equal";
    }
    else if(ans>0){
        cout<<"X is greater than Y";
    }
    else if(ans<0){
        cout<<"X is smaller than Y";
    }
    cout<<endl;

    //to insert characters inside string:
    //push_back('!');  //Inserts the character at the end. 
    //pop_back(); //Removes character from the end.

    x.push_back('!');
    x.push_back('!');
    cout<<x<<endl;
    x.pop_back();
    cout<<x<<endl;

    // x.clear();
    // cout<<"X is: "<<x<<endl;

    int f = 10;
    auto ch1 = 'C'; //auto will identify the datatype on its own
    cout<<sizeof(ch1)<<endl;

    //String iteration:
    for(int i=0 ; i<x.length() ; i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;

    //OR
    for(char ch : x){  //For each character ch, belonging to string
        cout<<ch<<" ";
    }
    cout<<endl;

    //Printing Substrings:
    string z = "Learning coding!";
    string z1 = z.substr(2,8); //z.substr(starting index , no._of_buckets)
    cout<<z1<<endl;

    return 0;
}