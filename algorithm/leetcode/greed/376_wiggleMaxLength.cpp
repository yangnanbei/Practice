typedef enum num_state_{
    NULL_STATE_NUM,
    POSITIVE_NUM,
    NEGATIVE_NUM,
} num_state;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int res = 1;
        int diff = 0;
        int num_state = NULL_STATE_NUM; 
        for (int i = 1; i < nums.size(); i++) {
            diff = nums[i] - nums[i - 1];
            if (num_state == NULL_STATE_NUM) {
                if (diff > 0) {
                    num_state = POSITIVE_NUM;
                } else if (diff < 0) {
                    num_state = NEGATIVE_NUM;
                } else {
                    continue;
                }
                res += 1;
            }

            if (num_state == POSITIVE_NUM) {
                if (diff < 0) {
                    num_state = NEGATIVE_NUM;
                    res += 1;
                } else {
                    continue;
                }
            } else {
                if (diff > 0) {
                    num_state = POSITIVE_NUM;
                    res += 1;
                } else {
                    continue;
                }
            }
        }
        
        return res;
    }
};
