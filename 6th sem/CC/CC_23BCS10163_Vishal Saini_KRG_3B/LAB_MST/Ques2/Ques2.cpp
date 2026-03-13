#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MOD = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>temp(32,0);
        for(int num : nums){
            for(int j = 0; j<32; j++){
                if(num&(1<<j) ){
                    temp[j]++;
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i<k; i++){
            long long val = 0;
            for(int b = 0; b<32; b++){
                if(temp[b]>0){
                    val |= (1LL<<b); 
                    temp[b]--;
                }
            }
            ans = (ans + (val*val)%MOD)%MOD;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    int result = sol.maxSum(nums, k);

    cout << "Maximum sum: " << result << endl;

    return 0;
}
