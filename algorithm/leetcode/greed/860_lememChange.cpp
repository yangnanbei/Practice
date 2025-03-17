class Solution {

public:
    bool lemonadeChange(vector<int>& bills) {
        int five_cnt = 0;
        int ten_cnt = 0;
        int twt_cnt = 0;
        int size = bills.size();
        for (int val: bills) {
            switch (val) {
                case 5:
                    five_cnt += 1;
                    break;
                case 10:
                    ten_cnt += 1;
                    if (five_cnt > 0) {
                        five_cnt--;
                    } else {
                        return false;
                    }
                    break;
                case 20:
                    twt_cnt += 1;
                    int succ_handle_flag = false;
                    if (ten_cnt && five_cnt) {
                        ten_cnt--;
                        five_cnt--;
                        succ_handle_flag = true;
                    }

                    if (!succ_handle_flag && five_cnt >= 3) {
                        five_cnt -= 3;
                        succ_handle_flag = true;
                    }

                    if (!succ_handle_flag) {
                        return false;
                    }
                    break;
            } 
        }

        return true;
    }
};
