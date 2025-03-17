class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0;
        int size = ratings.size();
        vector<int> candy(size, 1);

        /* rchild > lchild */
        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
        /* lchild > rchild */
        for (int i = size - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        for (int val: candy) {
            res += val;
        }

        return res;
    }
};
