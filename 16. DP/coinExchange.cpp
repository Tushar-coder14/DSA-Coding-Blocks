#include <iostream>
using namespace std;

int CoinExchange(int amount , int *deno , int n){
    //base case
    if(amount == 0){
        return 0;
    }

    //recursive case
    int ans = INT_MAX;
    for(int i=0 ; i<n ; i++){
        if(amount >= deno[i]){
            int chotiAmount = amount - deno[i];
            int chotiAmountCoins = CoinExchange(chotiAmount , deno , n);
            if(chotiAmount != INT_MAX){
                ans = min(chotiAmountCoins+1 , ans);
            }
        }
    }
    return ans; 
}

int main(){
    int deno[] = {1, 7, 10};
    int n = sizeof(deno)/sizeof(int);
    cout<<CoinExchange(15 , deno , n)<<endl;
    
    return 0;
}