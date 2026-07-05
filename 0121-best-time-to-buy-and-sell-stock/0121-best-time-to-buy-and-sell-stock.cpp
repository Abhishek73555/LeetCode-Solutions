class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_p=INT_MAX;
        int max_profit=0;
        for(int price:prices){
            if(price<min_p){
                min_p=price;
            }else if(price-min_p>max_profit){
                max_profit=price-min_p;
            }
        }
        return max_profit;
    }
};