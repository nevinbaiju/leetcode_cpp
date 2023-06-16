#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int max = 0;
        for(vector<int> interval: intervals){
            max = (max > interval[1])? max : interval[1];
        }
        int prefix_array[max] = {0};

        for(vector<int> interval: intervals){
            prefix_array[interval[0]] += 1;
            prefix_array[interval[1]] -= 1;
        }
        int prev_val = 0;

        for(int i=0; i<max; i++){
            prev_val += prefix_array[i];
            prefix_array[i] = prev_val;
            cout << prev_val << ", ";
        }
        cout << "\n";
        int flag = 0;
        int start_index;
        vector<vector<int>> ans;

        for(int i=0; i<max; i++){
            if((flag==0) & (prefix_array[i] == 1)){
                start_index = i;
                flag = 1;
            }
            else if((flag==1) & (prefix_array[i] == 0)){
                ans.push_back({start_index, i});
                flag = 0;
            }
        }
        if (flag == 1){
            ans.push_back({start_index, max});
        }
        return ans;
}

int main() {
    
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ans = merge(intervals);

    for(vector index: ans){
        for(int interval: index){
            cout << interval << ", ";
        }
        cout << "\n";
    }
    
}