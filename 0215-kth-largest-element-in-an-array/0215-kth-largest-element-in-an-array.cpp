class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size() - 1, nums.size() - k);
    }

private:
    void swap(int& a, int& b) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    int quickselect(vector<int>& nums, int left, int right, int k) {
        if (left >= right) return nums[left];

        int pivot = nums[left + (right - left) / 2];
        int i = left;
        int lt = left;
        int rt = right;

        while (i <= rt) {
            if (nums[i] < pivot) {
                swap(nums[lt++], nums[i++]);
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[rt--]);
            } else {
                i++;
            }
        }

        if (k >= lt && k <= rt) {
            return nums[k];
        } else if (k < lt) {
            return quickselect(nums, left, lt - 1, k);
        } else {
            return quickselect(nums, rt + 1, right, k);
        }
    }
};