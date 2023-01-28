//  Question #4 of challenge #6(Amazon)
//  Name - Get tweets accordint to frequency
//  LeetCode #1348

class TweetCounts {
    unordered_map<string, vector<int>> map;
public:
    TweetCounts(){}
    
    void recordTweet(string tweet, int time) {
        map[tweet].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweet, int start, int end){
        int chunk = 60;
        if(freq == "hour") chunk = 3600;
        else if(freq == "day") chunk = 3600*24;

        vector<int> ans((end-start)/chunk+1);

        for(auto it:map[tweet]){
            if(it >= start && it <= end){
                int idx = (it-start)/chunk;
                ans[idx]++;
            }
        }

        return ans;
    }
};