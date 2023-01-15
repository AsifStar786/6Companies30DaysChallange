//  Question #11 of challenge #3(Adobe)
//  Name - Stock Price Fluctuation...
//  LeetCode #2034

class StockPrice {
    set<int> stamp;
    multiset<int> cost;
    unordered_map<int, int> map;
public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if(map.find(timestamp) == map.end()){
            map[timestamp] = price;
            stamp.insert(timestamp);
            cost.insert(price);
            return ;
        }

        int c = map[timestamp];
        cost.erase(cost.find(c));
        cost.insert(price);
        map[timestamp] = price;
    }
    int current() {
        auto t = stamp.rbegin();
        return map[*t];
    }
    
    int maximum() {
        auto maxi = cost.rbegin();
        return *maxi;
    }
    
    int minimum() {
        auto mini = cost.begin();
        return *mini;
    }
};