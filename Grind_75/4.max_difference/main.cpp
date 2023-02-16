#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() <2) return 0;
    int profitMax = prices[1] - prices[0];
    int elementMin = prices[0];
    for (int i=1; i<prices.size(); i++){
        if (prices[i] - elementMin > profitMax) profitMax = prices[i] - elementMin;
        if (prices[i] <elementMin) elementMin = prices[i];
    }
    
    return max(profitMax,0);
};

int main(){
    vector<int> prices = {7,1,3,5,6,4,0};
    cout << "Output: " << maxProfit(prices) << endl;
}