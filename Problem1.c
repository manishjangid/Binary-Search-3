/* Problem Statement:
Verified on leetcode

50. Pow(x, n)
Medium

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:

    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]

 *
 * Time Complexity : O(log N) 
 * Space complexity : O(1) excluding result variable 
 */
class Solution {
public:
    /* calculate x raised to power of n */
    double calculatepower(double x, unsigned long n) {
        /* return the same element if asking for only n = 1*/
        if (n == 1) {
            return x;
        }
        /* get the result for n/2 */
        double res = calculatepower(x, n/2);
        /* multiply it by itself to reuse the output */
        res = res * res;
        /* if its odd then multiply it again by the original x  number */
        if (n % 2 != 0) {
            res = res * x;
        }
        return res;
    }
    
    double myPow(double x, int n) {
        /* can store negation of large number */
        long n_big = n;
        
        /* validation for power 0 */
        if (n == 0) {
            return 1;
        }
        /* negative power calculation.invert x too */
        if (n < 0) {
            x = (1/x);
            n_big = -(long)n;
        }
        
        return calculatepower2(x, n_big);
        
    }
};
/* Execute on leetcode platform */


