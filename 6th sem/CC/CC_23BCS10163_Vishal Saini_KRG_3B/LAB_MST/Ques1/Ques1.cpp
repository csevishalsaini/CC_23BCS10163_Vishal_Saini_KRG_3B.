#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>&nums, int mid, int op){
        long long total = 0;
        for(int x : nums){
            if(x%mid == 0){
                total += (x/mid)-1;
            }
            else{
                total += (x/mid);
            }
        }
        return total<=op;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        int ans = h;
        while(l<=h){
            int mid = (l+h)/2;
            if(isPossible(nums,mid,maxOperations)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }

        }
        return ans;
    }
};
int main() {
    Solution sol;

    int n, maxOperations;
    cout << "Enter number of bags: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter number of balls in each bag:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter max operations: ";
    cin >> maxOperations;

    int result = sol.minimumSize(nums, maxOperations);

    cout << "Minimum possible maximum balls in a bag: " << result << endl;

    return 0;
}
