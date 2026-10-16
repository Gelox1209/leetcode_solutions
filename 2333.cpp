class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        // vector<int> v;
        // Allowed to just modify nums1
        int len = nums1.size();
        long long sum = 0;
        int k = k1 + k2;
        int shouldbreak = false; // For tracking something later
        for(int i = 0; i < len; i++) {
            // Absolute value so I dont have to check for min element later.
            nums1[i] = (abs(nums1[i] - nums2[i]));
        }

        // Off case, len is 1
        if (len == 1) {

            if (nums1[0] < k) {
                return 0;

            } else {
                nums1[0] -= k;
                return nums1[0] * nums1[0];

            }

        }

        sort(nums1.begin(), nums1.end(), greater<int>());

        while (k > 0) {
            
            if (nums1[0] == 0)
                break;

            for (int i = 0; i < len; i++) {
                
                if (i != len - 1) {
                    // Not Last Element
                    // The moment current element does not equal next, break and restart.
                    if (nums1[i] != nums1[i + 1]) {
                        shouldbreak = true;
                    }                

                    if (k > 0) {

                        nums1[i]--;
                        k--;

                    } else {
                        break;
                    }

                    if (shouldbreak) {

                        shouldbreak = false;
                        break;

                    }

                } else {
                    // Last element
                    if (k > 0 && nums1[i] != 0) {
                        nums1[i]--;
                        k--;

                    }

                }
            
            }

        }

        for(int i = 0; i < len; i++) {

            // Long long in case of super big numbers
            sum += (long long)nums1[i] * nums1[i];

        }

        return sum;

    }
};