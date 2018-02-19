// 7ms, 27.55%
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.empty()) return 0;
        int buy = 0;
        int sell = prices.size() - 1;
        while(buy < sell && prices[buy] > prices[buy + 1]) ++buy;
        while(buy < sell && prices[sell] < prices[sell - 1]) --sell;
        if(buy == sell) return 0;
        
        int dif = 0;
        while(buy < sell)
        {
            int i = 0;
            while(i++ < sell - buy)
            {            
                int tmp = prices[sell] - prices[sell - i];
                if(tmp <= 0)
                {
                    sell = sell - i + 1;
                    break;
                }
                else dif = tmp > dif ? tmp : dif;
            }
            --sell;
        }
        return dif;
    }
};
