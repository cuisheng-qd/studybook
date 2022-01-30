#include <math.h>

bool isHappy(int n){
    int slow = n;
    int fast = n;
    do {
        slow = nextNumber(slow);
        fast = nextNumber(fast);
        fast = nextNumber(fast);
        if (slow == fast) {
            break;
        }
    } while (fast != 1);
    return fast == 1;
}

// 求下一个值（每个位置数字的平方的和）
int nextNumber(int n) {
    int sum = 0;
    do {
        sum += pow(n % 10, 2); // 余数，计算平方
        n = n / 10;
    } while (n != 0);
    return sum;
}
