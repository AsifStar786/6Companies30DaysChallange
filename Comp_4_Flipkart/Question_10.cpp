//  Question #10 of challenge #4(Flipkart)
//  Name - Distance Barcodes
//  LeetCode #1054


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& bar) {
        priority_queue<pair<int, int>> maxH;
        sort(bar.begin(), bar.end());
        int el = bar[0], i = 1, cnt = 1;

        while(i < bar.size()){
            if(bar[i] == el) cnt++;
            else{
                maxH.push({cnt, el});
                el = bar[i];
                cnt = 1;
            }
            i++;
        }
        maxH.push({cnt, el});
        
        bar.clear();

        while(maxH.size() > 1){
            auto [cnt, el] = maxH.top();
            maxH.pop();
            auto [c2, el2] = maxH.top();
            maxH.pop();

            bar.push_back(el); cnt--;
            bar.push_back(el2); c2--;
            if(cnt) maxH.push({cnt, el});
            if(c2) maxH.push({c2, el2});
        }
        if(maxH.size()) bar.push_back(maxH.top().second);
        return bar;
    }
};