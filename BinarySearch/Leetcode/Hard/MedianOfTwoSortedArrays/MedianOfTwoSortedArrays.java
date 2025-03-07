// https://leetcode.com/problems/median-of-two-sorted-arrays/

public class MedianOfTwoSortedArrays {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int i1 = 0, i2 = 0;
        int ind = -1;
        int n1 = 0, n2 = 0;
        int n = nums1.length + nums2.length, lastEle = 0;
        while (i1 < nums1.length && i2 < nums2.length) {
            int currEle = 0;
            if (nums1[i1] < nums2[i2]) {
                currEle = nums1[i1];
                i1++;
            } else {
                currEle = nums2[i2];
                i2++;
            }
            ind++;
            if (ind == n / 2) {
                if ((n & 1) == 1) {
                    return currEle;
                }
                return (currEle + lastEle) / 2.0;
            }
            lastEle = currEle;
        }
        while (i1 < nums1.length) {
            int currEle = nums1[i1];
            i1++;
            ind++;
            if (ind == n / 2) {
                if ((n & 1) == 1) {
                    return currEle;
                }
                return (currEle + lastEle) / 2.0;
            }
            lastEle = currEle;
        }
        while (i2 < nums2.length) {
            int currEle = nums2[i2];
            i2++;
            ind++;
            if (ind == n / 2) {
                if ((n & 1) == 1) {
                    return currEle;
                }
                return (currEle + lastEle) / 2.0;
            }
            lastEle = currEle;
        }
        return -1;
    }
}
