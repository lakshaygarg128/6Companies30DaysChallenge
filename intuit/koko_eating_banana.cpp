class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int l=1,r=1000000000;
        int hr;
        while(l<=r){
            int mid = l+(r-l)/2;
            hr=0;
            for(int i =0;i<n;i++){
                hr = hr + (piles[i]/mid);
                hr = piles[i]%mid ? hr+1:hr;
            }
            
            if(hr<=h){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
        
    }
};