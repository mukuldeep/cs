class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> ans,st;
        for(auto it=heights.rbegin();it!=heights.rend();it++){
            auto pos=lower_bound(st.rbegin(),st.rend(),*it);
            int elen=pos-st.rbegin()+(pos!=st.rend()?1:0);
            ans.push_back(elen);
            
            while(st.size() && st.back()<*it)
                st.pop_back();
            st.push_back(*it);
        }
        reverse(ans.begin(),ans.end());
            return ans;
    }
};

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> ans;
        stack<int> st;
        
        for(auto it=heights.rbegin();it!=heights.rend();it++){
            int elen=0;
            while(st.size() && st.top()<*it){
                st.pop();
                elen++;
            }
            if(st.size())elen++;
            ans.push_back(elen);
            st.push(*it);
        }
        reverse(ans.begin(),ans.end());
            return ans;
    }
};

