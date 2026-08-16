class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        // if (m > n)
        //      swap(nums1, nums2);

        int low = 0, high = m;
        // int leftSize = (m + n + 1) / 2;

        while (low <= high) {
            // Partition of nums1
            int partitionA = (low + high) / 2;

            // Partition of nums2
            int partitionB = (m + n + 1) / 2 - partitionA;

            int leftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];

            int rightA = (partitionA == m) ? INT_MAX : nums1[partitionA];

            int leftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];

            int rightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            if (leftA <= rightB && leftB <= rightA) {

                // Odd total elements
                if ((m + n) % 2 == 1) {
                    return max(leftA, leftB);
                }

                // Even total elements
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            }

            // Too many elements taken from nums1
            else if (leftA > rightB) {
                high = partitionA - 1;
            }

            // Too few elements taken from nums1
            else {
                low = partitionA + 1;
            }
        }
        return 0.0;
    }
};