class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        if(turnedOn>8)
            return ans;
    

        vector<vector<string>> hr(4,vector<string>());
        vector<vector<string>> mn(6,vector<string>());

        for(int i=0;i<12;i++){
            hr[__builtin_popcount(i)].push_back(to_string(i));
        }
        
        for(int i=0;i<60;i++){
            mn[__builtin_popcount(i)].push_back((i<10?"0":"")+to_string(i));
        }

        // for(auto x: hr){
        //     for(auto y: x){
        //         cout<<y<<" ";
        //     }cout<<endl;
        // }cout<<endl;

        // for(auto x: mn){
        //     for(auto y: x){
        //         cout<<y<<" ";
        //     }cout<<endl;
        // }cout<<endl;


        for(int hb=0; hb<4; hb++){
            for(int mb=0;mb<6; mb++){
                if(hb+mb == turnedOn){
                    for(auto hs: hr[hb]){
                        for(auto ms: mn[mb]){
                            ans.push_back(hs+":"+ms);
                        }
                    }
                }
            }
        }
        

        return ans;
    }
};