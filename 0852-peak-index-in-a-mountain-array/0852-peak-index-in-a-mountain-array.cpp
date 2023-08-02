class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size();
        while(r>l){
            int mid = (l+r)/2;
            if(arr[mid] > arr[mid+1]){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};