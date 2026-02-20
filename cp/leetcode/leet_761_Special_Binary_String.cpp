class Solution {
    vector<string> splitBySection(string s){
        string curr="";
        vector<string> sections;

        int bal = 0;
        for(auto ch : s){
            bal += (ch=='0'?-1:1);
            curr += ch;

            if(!bal){
                sections.push_back(curr);
                curr="";
            }
        }
        
        if(curr.length()>0){
            sections.push_back(curr);
        }

        return sections;

    }
public:
    string makeLargestSpecial(string s) {

        if(s.length()<=2){
            return s;
        }
        vector<string> sections = splitBySection(s);

        for(int i=0;i<sections.size();i++){
            //cout<<sections[i]<<endl;
            string inners = sections[i].substr(1, sections[i].length() - 2);
            sections[i] = '1'+makeLargestSpecial(inners)+'0';
        }

        sort(sections.begin(), sections.end(), greater<string>());
        string joined_string = accumulate(sections.begin(), sections.end(), string(""));

        return joined_string;

    }
};
