﻿#ifndef errfloat_h
#define errfloat_h

#include "header.h"

KAWAII_BEGIN

/*
由于浮点误差产生的错误一般会出现在ray与shape相交的计算中，由于浮点误差，计算出的交点
往往出现在shape的内部或者shape的外部，而不是正好在shape边缘上，如果是ray与shape的交点处的切线夹角很小
那么误差产生的错位会更加严重。为了解决这种误差，有两种方案
1.简单粗暴，用双精度浮点类型，double
这种方案的好处在于简单，不需要做额外任何处理，坏处显而易见，double类型占8个字节，float只占4个字节
首先内存占用大，可能导致cache miss的概率就高，内存对齐不灵活
其次，经过simd优化之后float的运算效率比double高一倍
所以在离线渲染中用到的降低误差的办法不是简单的使用double，而是接下来要介绍的一种方式
先简单介绍一下float的内存结构
float占4个字节，总共32位，从左边的高位开始排列，最高的一位是符号位，之后8位为指数位，最低的23为有效数字位
任何一个浮点数都可以写成科学计数法的形式，比如说
253 = 2.53 * 10 ^ 2，同样可以表示二进制的方式 a * 2 ^ b，a储存在的23个有效数字位中，b储存在8个指数位中
b的取值范围是 b∈[0, 255]，又因为指数必须可以取到小于零的数，所以指数的范围 e∈[-127, 128] e = b - 127
a总共23位，a是一个二进制整数，一个二进制非零整数的最高有效位一定是1，1不需要显式的表达，所以a有24位的精度
假设符号位为s，指数位为e，有效数字位为m，则一个浮点数可以表示为
s * 1.m * 2 ^ (e - 127)
例如 6.5 = 1.101(base2) * 2 ^ 2，内存分布为e = 129，m = 10100000000000000000000
众所周知，计算机储存的浮点数不是连续的，是离散的，计算机中可表示的浮点数之间是有间隔的，间隔是多少？
在[2 ^ e, 2 ^ (e + 1)]范围内，间隔为数值的变化量除以该范围内浮点数的个数
spacing = (2 ^ (e + 1) - 2 ^ e) / 2 ^ 23 = 2 ^ (e - 23)
假设a与b都是浮点数，浮点数相加就会导致误差，a + b的误差范围是多少？
我们用 + ‘表示计算机浮点加法
r = a + ’ b = round(a + b), r ∈[(a + b) * (1 - ε), (a + b) * (1 + ε)]
a + b 所在的浮点间隔为s
假设 a + b = c * 2 ^ e
s <= (c * 2 ^ (e + 1) - c * 2 ^ e) / 2 ^ 23 = (c * 2 ^ e) / 2 ^ 23 = (a + b) * 2 ^ -23
为何是小于等于？
s的最大值为(a + b) * 2 ^ -23，只可能比这个值小，不会超过这个值。
因为当指数位不变时，无论有效数字位如何变，spacing都不变，

*/

class EFloat {

public:

private:

};

KAWAII_END

#endif /* errfloat_h */