class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        mergesort(nums, left, right);
        return nums;
    }

private:
    void mergesort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergesort(nums, left, mid);
            mergesort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }
    void merge(vector<int>& nums, int left, int mid, int right) {
        int lsize = mid - left + 1;
        int rsize = right - mid;
        vector<int> leftvec(lsize);
        vector<int> rightvec(rsize);
        for (int i = 0; i < lsize; i++) {
            leftvec[i] = nums[left + i];
        }
        for (int j = 0; j < rsize; j++) {
            rightvec[j] = nums[mid + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = left;
        while (i < lsize && j < rsize) {
            if (leftvec[i] <= rightvec[j]) {
                nums[k] = leftvec[i];
                i++;
            } else {
                nums[k] = rightvec[j];
                j++;
            }
            k++;
        }
        while (i < lsize) {
            nums[k] = leftvec[i];
            i++;
            k++;
        }
        while (j < rsize) {
            nums[k] = rightvec[j];
            j++;
            k++;
        }
    }
};