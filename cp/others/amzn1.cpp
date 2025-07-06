#include <bits/stdc++.h>
#define ll long long
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

bool sortby(const pair<string,pair<string,ll>> &a,const pair<string,pair<string,ll>> &b)
{
    if(a.first==b.first)return a.second.first<b.second.first;
    return (a.first < b.first);
}
/*
 * Complete the 'sortBoxes' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY boxList as parameter.
 */

vector<string> sortBoxes(vector<string> boxList) {
    vector<ll> new_versions;
    vector<pair<string,pair<string,ll>>> older_version;
    vector<string> ans;
    for(ll p=0;p<boxList.size();p++){
        ll i=0;
        for(;i<boxList[p].size();i++){
            if(boxList[p][i]==' ')
                break;
        }
        string id,ver;
        id=boxList[p].substr(0,i);
        ver=boxList[p].substr(i+1,boxList[p].size()-i);
        //cout<<id<<":"<<ver<<endl;
        if('0'<=ver[0] && ver[0]<='9'){
            older_version.push_back({ver,{id,p}});
        }else{
            new_versions.push_back(p);
        }
    }
    sort(older_version.begin(),older_version.end(),sortby);
    for(auto xd:older_version){
        ans.push_back(boxList[xd.second.second]);
    }
    for(auto xd:new_versions){
        ans.push_back(boxList[xd]);
    }
    return ans;
}

int cc_main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string boxList_count_temp;
    getline(cin, boxList_count_temp);

    int boxList_count = stoi(ltrim(rtrim(boxList_count_temp)));

    vector<string> boxList(boxList_count);

    for (int i = 0; i < boxList_count; i++) {
        string boxList_item;
        getline(cin, boxList_item);

        boxList[i] = boxList_item;
    }

    vector<string> result = sortBoxes(boxList);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}
