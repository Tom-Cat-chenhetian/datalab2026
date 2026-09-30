/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */
/*
 * 注意：不要在这里包含任何其他头文件，
 * 否则运行 test.py 时会报错。
 * 你仍然可以在不包含 <stdio.h> 的情况下使用 printf 来调试，
 * 尽管编译器可能会给出一个警告。一般来说，
 * 忽略编译器警告不是好习惯，但在这种情况下是可以的。
 *
 * 使用 printf 会干扰我们的脚本捕获执行结果。
 * 到这一步为止，你只能用 ./btest 测试正确性。
 * 在 ./btest 中确认一切正确后，删掉 printf，
 * 再用 test.py 运行完整测试。
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
 /*
 * bitAnd —— 只用 ~ 和 | 实现 x & y
 * 例如：bitAnd(4, 5) = 4
 * 允许的运算符：~ |
 * 最多运算符个数：7
 * 难度：1
 */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
/*
 * bitXor —— 只用 ~ 和 & 实现 x ^ y
 *   例如：bitXor(4, 5) = 1
 *   允许的运算符：~ &
 *   最多运算符个数：7
 *   难度：1
 */
int bitXor(int x, int y) {
    int a = ~(x & y);
    int b = ~(~x & ~y);
    return a & b;
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
/*
 * samesign —— 判断两个整数是否同号。
 *   0 既不是正数，也不是负数
 *   例如：samesign(0, 1) = 0，samesign(0, 0) = 1
 *         samesign(-4, -5) = 1，samesign(-4, 5) = 0
 *   允许的运算符：>> << ! ^ && if else &
 *   最多运算符个数：12
 *   难度：2
 *
 * 参数：
 *   x - 第一个整数。
 *   y - 第二个整数。
 *
 * 返回值：
 *   若 x 和 y 同号返回 1，否则返回 0。
 */
int samesign(int x, int y) {
    int a = !x;
    int b = !y;
    if (a ^ b) {
        return 0;
    }
    return !((x >> 31) ^ (y >> 31));
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
/*
 * logtwo —— 用移位计算一个正整数的以 2 为底的对数。
 *   （可以参考 bitCount 的思路）
 *   注意：可以假定 v > 0
 *   例如：logtwo(32) = 5
 *   允许的运算符：> < >> << |
 *   最多运算符个数：25
 *   难度：4
 */
int logtwo(int v) {
    int r = 0;
    int t = (v > 0xFFFF) << 4;
    r |= t;
    v >>= t;
    t = (v > 0xFF) << 3;
    r |= t;
    v >>= t;
    t = (v > 0xF) << 2;
    r |= t;
    v >>= t;
    t = (v > 0x3) << 1;
    r |= t;
    v >>= t;
    r |= (v > 0x1);
    return r;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
/*
 *  byteSwap —— 交换第 n 个字节和第 m 个字节
 *    例如：byteSwap(0x12345678, 1, 3) = 0x56341278
 *          byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    注意：可以假定 0 <= n <= 3，0 <= m <= 3
 *    允许的运算符：! ~ & ^ | + << >>
 *    最多运算符个数：17
 *    难度：2
 */
int byteSwap(int x, int n, int m) {
    int sn = n << 3;
    int sm = m << 3;
    int a = (x >> sn) & 0xFF;
    int b = (x >> sm) & 0xFF;
    int mask = ~((0xFF << sn) | (0xFF << sm));
    x = x & mask;
    x = x | (b << sn);
    x = x | (a << sm);
    return x;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
/*
 * reverse —— 颠倒一个 32 位无符号整数的位序。
 *   例如：reverse(0xFFFF0000) = 0x0000FFFF  reverse(0x80000000)=0x1  reverse(0xA0000000)=0x5
 *   注意：可以假定一个 unsigned 整数是 32 位长。
 *   允许的运算符：<< | & - + >> for while ! ~（在这个函数里你可以定义 unsigned）
 *   最多运算符个数：30
 *   难度：3
 */
unsigned reverse(unsigned v) {
    unsigned r = 0;
    int i = 32;
    while (i) {
        r = (r << 1) | (v & 1);
        v = v >> 1;
        i = i - 1;
    }
    return r;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
/*
 * logicalShift —— 用逻辑右移把 x 右移 n 位
 *   例如：logicalShift(0x87654321,4) = 0x08765432
 *   注意：可以假定 0 <= n <= 31
 *   允许的运算符：! ~ & ^ | + << >>
 *   最多运算符个数：20
 *   难度：3
 */
int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
/*
 * leftBitCount —— 返回一个字最左端（高位）连续 1 的个数。
 *   例如：leftBitCount(-1) = 32，leftBitCount(0xFFF0F0F0) = 12，
 *         leftBitCount(0xFE00FF0F) = 7
 *   允许的运算符：! ~ & ^ | + << >>
 *   最多运算符个数：50
 *   难度：4
 */
int leftBitCount(int x) {
    int y = ~x;
    int r = 0;
    int t = !(y >> 16);
    r = r + (t << 4);
    y = y << (t << 4);
    t = !(y >> 24);
    r = r + (t << 3);
    y = y << (t << 3);
    t = !(y >> 28);
    r = r + (t << 2);
    y = y << (t << 2);
    t = !(y >> 30);
    r = r + (t << 1);
    y = y << (t << 1);
    t = !(y >> 31);
    r = r + t;
    y = y << t;
    r = r + !y;
    return r & (x >> 31);
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
/*
 * float_i2f —— 返回表达式 (float) x 的位级等价形式
 *   结果以 unsigned int 返回，但应当把它理解为
 *   单精度浮点数的位级表示。
 *   允许的运算符：if else while for & | ~ + - >> << < > ! ==
 *   最多运算符个数：30
 *   难度：4
 */
unsigned float_i2f(int x) {
    unsigned sign = 0;
    unsigned a = x;
    unsigned frac;
    unsigned low;
    int e = 0;
    int exp;
    if (x < 0) {
        sign = 0x80000000;
        a = ~x;
        a = a + 1;
    }
    if (a == 0) {
        return 0;
    }
    while ((a >> 31) == 0) {
        a = a << 1;
        e = e + 1;
    }
    exp = 158 - e;
    frac = (a >> 8) & 0x7FFFFF;
    low = a & 0xFF;
    if (low > 0x80) {
        frac = frac + 1;
    }
    if (low == 0x80) {
        if (frac & 1) {
            frac = frac + 1;
        }
    }
    if (frac > 0x7FFFFF) {
        frac = frac - 0x800000;
        exp = exp + 1;
    }
    return sign | (exp << 23) | frac;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
/*
 * floatScale2 —— 对浮点参数 f，返回表达式 2*f 的位级等价形式。
 *   参数和结果都以 unsigned int 传递，但
 *   应当把它们理解为单精度浮点数的位级表示。
 *   当参数是 NaN 时，返回参数本身。
 *   允许的运算符：& >> << | if > < >= <= ! ~ else + ==
 *   最多运算符个数：30
 *   难度：4
 */
unsigned floatScale2(unsigned uf) {
    unsigned sign = uf & 0x80000000;
    unsigned exp = (uf >> 23) & 0xFF;
    if (exp == 0xFF) {
        return uf;
    }
    if (exp == 0) {
        return sign | (uf << 1);
    }
    if (exp == 0xFE) {
        return sign | 0x7F800000;
    }
    return uf + 0x00800000;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
/*
 * float64_f2i —— 把一个 64 位 IEEE 754 浮点数转换成 32 位有符号整数。
 *   转换向零舍入。
 *   注意：假定使用 IEEE 754 表示法和标准的补码整数格式。
 *   参数：
 *     uf1 - 64 位浮点数的低 32 位。
 *     uf2 - 64 位浮点数的高 32 位。
 *   返回值：
 *     转换后的整数值；上溢时返回 0x80000000，下溢时返回 0。
 *   允许的运算符：>> << | & ~ ! + - > < >= <= if else
 *   最多运算符个数：60
 *   难度：3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned sign = uf2 >> 31;
    unsigned exp = (uf2 >> 20) & 0x7FF;
    unsigned val = 0x80000000 | ((uf2 & 0xFFFFF) << 11) | (uf1 >> 21);
    if (exp < 1023) {
        return 0;
    }
    if (exp > 1054) {
        return ~0x7FFFFFFF;
    }
    val = val >> (1054 - exp);
    if (sign) {
        if (val > 0x7FFFFFFF) {
            return ~0x7FFFFFFF;
        }
        int r = val;
        return -r;
    }
    if (val > 0x7FFFFFFF) {
        return ~0x7FFFFFFF;
    }
    return val;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
/*
 * floatPower2 —— 对任意 32 位整数 x，返回表达式 2.0^x
 *   （2.0 的 x 次方）的位级等价形式。
 *
 *   返回的 unsigned 值应当与单精度浮点数 2.0^x
 *   具有完全相同的位模式。
 *   如果结果太小、连非规格化数（denorm）都无法表示，
 *   返回 0。如果太大，返回 +INF。
 *
 *   允许的运算符：< > <= >= << >> + - & | ~ ! if else &&
 *   最多运算符个数：30
 *   难度：4
 */
unsigned floatPower2(int x) {
    if (x > 127) {
        return 0x7F800000;
    }
    if (x < -126) {
        if (x < -149) {
            return 0;
        }
        return 1 << (x + 149);
    }
    return (x + 127) << 23;
}
