#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int countpecialNumbers(int n)
    {
        // We first get all the numbers that are not special
        int digits[10];
        int digit_size = 0;

        for (int i = n; i > 0; i /= 10)
        {
            digits[digit_size] = (i % 10);
            digit_size++;
        }
        // reverse the digits
        reverse(digits, digits + digit_size);
        // for 3642, we first computes how many digits are special between 0 ~ 999,
        // Then we compute how many digits are special between 1000~2999,
        // Then we compute how many digits are special between 3000~3599,
        // Then we compute how many digits are special between 3600~3639,
        // Then we compute how many digits are special between 3640~3642,
        // Then we can sum them up and get the total number of special digits.
        int not_special_number_count = 0;
        // step 1: compute how many digits are special between 0 ~ 999, should be 9 + 9*9 + 9*9*8
        int count = 0;
        for (int i = 0; i < digit_size - 1; i++)
        {
            count = 9;
            for (int j = 0; j < i; j++)
            {
                count *= (10 - j - 1);
            }
            not_special_number_count += count;
        }

        // step 2: compute how many digits are special between 1000~2999
        count = digits[0] - 1;
        for (int i = 1; i < digit_size; i++)
        {
            count *= (10 - i);
        }
        not_special_number_count += count;
        // step 3: compute how many digits are special between 3000~3599 and the following numbers
        // The previous digits that are specified
        int prev_digits[10];
        int prev_digits_size = 0;
        for (int i = 1; i < digit_size; i++)
        {
            // if there are identical digits between digits[i -1] and the digits in prev_digits, then we return the total_numbers
            for (int j = 0; j < prev_digits_size; j++)
            {
                if (digits[i - 1] == prev_digits[j])
                {
                    return not_special_number_count;
                }
            }
            prev_digits[prev_digits_size] = (digits[i - 1]);
            prev_digits_size++;
            count = digits[i];

            // if digits[i] > numbers in prev_digits, then we need to minus 1
            for (int j = 0; j < prev_digits_size; j++)
            {
                if (digits[i] > prev_digits[j])
                {
                    count--;
                }
            }
            for (int j = i; j < digit_size-1; j++)
            {
                count *= (10 - j - 1);
            }
            not_special_number_count += count;
        }
        // if n it self is a special number, +1
        int is_special = true;
        for (int i = 0; i < digit_size -1; i++)
        {
            if (digits[digit_size -1] == digits[i])
            {
                is_special = false;
            }
        }
        if (is_special)
        {
            not_special_number_count++;
        }
        return not_special_number_count;
    }
};

int main()
{
    Solution s;
    int n = 20;
    int ret = s.countpecialNumbers(n);
    printf("ret = %d\n", ret);
    return 0;
}
