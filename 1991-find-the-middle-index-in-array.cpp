#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // sum
        int sum = 0;
        for (int i=0;i<nums.size();i++){
            sum += nums[i];
        }

        // tranverse from left
        int count = 0;
        for (int i=0;i<nums.size();i++){
            if (count == sum-nums[i]){
                return i;
            } else {
                count += nums[i];
            }
        }

        // no case
        return -1; 
    }
};

int main(){
    
}