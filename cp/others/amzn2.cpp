#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'routePairs' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER maxTravelDist
 *  2. 2D_INTEGER_ARRAY forwardRouteList
 *  3. 2D_INTEGER_ARRAY returnRouteList
 */
bool comp(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.first < b.first);
}
vector<vector<int>> routePairs(int maxTravelDist, vector<vector<int>> forwardRouteList, vector<vector<int>> returnRouteList) {

    vector<pair<int,int>> ret_sorted;
    vector<vector<int>> ans;
    vector<pair<int,vector<pair<int,int>>>> tem(forwardRouteList.size());
    for(auto xd:returnRouteList){
        ret_sorted.push_back({xd[1],xd[0]});
    }
    sort(ret_sorted.begin(),ret_sorted.end());
    vector<int> ret_sorted_first;
    for(auto xd:ret_sorted){
        ret_sorted_first.push_back(xd.first);
    }
    for(int i=0;i<forwardRouteList.size();i++){
        int x=forwardRouteList[i][1];
        int y=maxTravelDist-x;
        int pos=upper_bound(ret_sorted_first.begin(),ret_sorted_first.end(),y)-ret_sorted_first.begin();
        tem[i].first=-1;
        if(pos==ret_sorted.size()){//last position
            int cur_mx=ret_sorted.back().first+x;
            tem[i].first=cur_mx;
            for(int j=ret_sorted.size()-1;j>=0 && (ret_sorted[j].first+x)==cur_mx;j--){
                (tem[i].second).push_back({forwardRouteList[i][0],ret_sorted[j].second});
            }
        }else if(pos){
            if(ret_sorted[pos].first!=y){
                pos--;
            }
            int cur_mx=ret_sorted[pos].first+x;
            tem[i].first=cur_mx;
            for(int j=pos;j>=0 && (ret_sorted[j].first+x)==cur_mx;j--){
                (tem[i].second).push_back({forwardRouteList[i][0],ret_sorted[j].second});
            }
        }

    }
    int mx=-1;
    for(int i=0;i<tem.size();i++){
        mx=max(mx,tem[i].first);
    }
    for(int i=0;i<tem.size();i++){
        if(tem[i].first==mx){
            for(auto xd:tem[i].second){
                vector<int> p2v;
                p2v.push_back(xd.first);
                p2v.push_back(xd.second);
                ans.push_back(p2v);
            }
        }
    }
    return ans;


}

int cc_main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string maxTravelDist_temp;
    getline(cin, maxTravelDist_temp);

    int maxTravelDist = stoi(ltrim(rtrim(maxTravelDist_temp)));

    string forwardRouteList_rows_temp;
    getline(cin, forwardRouteList_rows_temp);

    int forwardRouteList_rows = stoi(ltrim(rtrim(forwardRouteList_rows_temp)));

    string forwardRouteList_columns_temp;
    getline(cin, forwardRouteList_columns_temp);

    int forwardRouteList_columns = stoi(ltrim(rtrim(forwardRouteList_columns_temp)));

    vector<vector<int>> forwardRouteList(forwardRouteList_rows);

    for (int i = 0; i < forwardRouteList_rows; i++) {
        forwardRouteList[i].resize(forwardRouteList_columns);

        string forwardRouteList_row_temp_temp;
        getline(cin, forwardRouteList_row_temp_temp);

        vector<string> forwardRouteList_row_temp = split(rtrim(forwardRouteList_row_temp_temp));

        for (int j = 0; j < forwardRouteList_columns; j++) {
            int forwardRouteList_row_item = stoi(forwardRouteList_row_temp[j]);

            forwardRouteList[i][j] = forwardRouteList_row_item;
        }
    }

    string returnRouteList_rows_temp;
    getline(cin, returnRouteList_rows_temp);

    int returnRouteList_rows = stoi(ltrim(rtrim(returnRouteList_rows_temp)));

    string returnRouteList_columns_temp;
    getline(cin, returnRouteList_columns_temp);

    int returnRouteList_columns = stoi(ltrim(rtrim(returnRouteList_columns_temp)));

    vector<vector<int>> returnRouteList(returnRouteList_rows);

    for (int i = 0; i < returnRouteList_rows; i++) {
        returnRouteList[i].resize(returnRouteList_columns);

        string returnRouteList_row_temp_temp;
        getline(cin, returnRouteList_row_temp_temp);

        vector<string> returnRouteList_row_temp = split(rtrim(returnRouteList_row_temp_temp));

        for (int j = 0; j < returnRouteList_columns; j++) {
            int returnRouteList_row_item = stoi(returnRouteList_row_temp[j]);

            returnRouteList[i][j] = returnRouteList_row_item;
        }
    }

    vector<vector<int>> result = routePairs(maxTravelDist, forwardRouteList, returnRouteList);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
