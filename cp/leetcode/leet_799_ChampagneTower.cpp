class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<double> glasses;
        glasses.push_back((double)poured);


        for(int r=1; r<=query_row; r++){
            vector<double> nextRow;
            double carry = 0;
            for(double glass: glasses){

                double innextGlass = ((glass-1.0)/2.0);
                if(innextGlass < 0.0) innextGlass = 0.0;
                innextGlass+=carry;

                carry = (glass-1.0)/2.0;
                if(carry < 0.0) carry = 0.0;

                //cout<<innextGlass<<" "<<carry<<"  ,  ";
                nextRow.push_back(innextGlass);
            }//cout<<endl;
            nextRow.push_back(carry);
            glasses = nextRow;

            // for(double g:glasses){
            //     cout<<g<<"\t";
            // }cout<<endl;
        }

        return glasses[query_glass]>1.0?1.0:glasses[query_glass];
        
    }
};