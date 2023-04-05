#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
 * Set next word in the vector
 * params:
 *      OUT v - vector that is storing the word
 *      IN  start_symbol - Starting symbol of the symbols to generate words with
 *      IN  end_symbol - Ending symbol of the symbols to generate words with
 * Return:
 */
void set_next_letter(vector<char> &v,char start_symbol,char end_symbol){
    for(int x=v.size()-1;x>=0;x--){
        if(v[x]==end_symbol){
            /* End symbol resets to the start symbol */
            v[x]=start_symbol;
        }else{
            /* Any other symbol to the next symbol */
            v[x]++;
            return;
        }
    }
}
int main() {
    /* Starting symbol of the symbols to generate words with */
    char start_symbol='0';

    /* Ending symbol of the symbols to generate words with */
    char end_symbol='3';

    /* Size of the word to be generated */
    int word_size=2;

    int symbol_range=end_symbol-start_symbol+1;
    if(start_symbol<=0){
        cout<<"invalid symbol range "<<start_symbol<<" to "<<end_symbol<<endl;
        return -1;
    }

    vector<char> v(word_size,start_symbol);

    cout<<"Generating "<<pow(symbol_range,v.size())<<" words"<<endl;
    cout<<"Estimated time: "<<pow(symbol_range,v.size())/100000<<" seconds"<<endl;
    if(pow(symbol_range,v.size())>1e6){
        cout<<"stalling! for number of possible combination is too high"<<endl;
        return -1;
    }
    /* iterating over all combinations */
    for(int i=0;i<pow(symbol_range,v.size());i++) {

        /* Printing the word */
        for (auto x:v) {
            cout << x;
        }
        cout << " ";

        /* Setting next word in the vector */
        set_next_letter(v,start_symbol,end_symbol);
    }

    return 0;
}