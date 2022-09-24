#include <iostream>
using namespace std;

int main(){
    int stock[] = {2,3,1,5,1,6};
    int n  = sizeof(stock)/sizeof(n);

    int maxProfit = INT_MIN;
    int minPrice = INT_MAX;
    for(int day=0 ; day<n ; day++){
        int price = stock[day];
        int profit = price - minPrice;
        if(profit>maxProfit){
            maxProfit = profit;
        }

        if(price<minPrice){
            minPrice = price;
        }
    }
    cout<<maxProfit<<endl;
    return 0;
}