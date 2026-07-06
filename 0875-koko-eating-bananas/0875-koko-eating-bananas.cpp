class Solution {
public:
    double hourlyRate(vector<int>& piles, int mid){
        double sum = 0;
        for(int i = 0; i<piles.size(); i++){
            sum+=ceil((double)piles[i]/(double)mid);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        int max = *max_element(piles.begin(), piles.end());
        while(min<max){
            int mid = (max+min)/2;
            double totaltime = hourlyRate(piles,mid);
            if(totaltime<=h){
                max = mid;
            }else{
                min = mid+1;
            }
        }
        return min;
    }
};