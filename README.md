# APUEAssignment

北邮【Unix环境高级编程】大作业：文本计算器

## 运行程序

Linux下执行：
```
make clean
make mybc
./mybc
```

## 示例
```
-> 1+2-3*4/5
0.600000
-> (1+2-3)*4/5
0.000000
-> (1+2-4)*4/5
-0.800000
-> pi
3.141593
-> e
2.718282
-> SET_PRECISION 1000
Error. Precision unchanged.
-> SET_PRECISION 12
OK.
-> pi
3.141592653590
-> sqrt(-1.)
Computation error when compute sqrt(x), x should be >= 0.
-> sqrt(.01)
0.100000000000
-> ln(-1.0)
Computation error when compute ln(x), x should be > 0.
-> 1 / 0
Computation error, divided by zero.
-> cos(pi)
-1.000000000000
-> cos(pi / 2)
0.000000000000
-> cos(pi / 4)
0.707106781187
-> ln(e)
1.000000000000
-> exp(1)
2.718281828459
-> 
-> 
-> hello
Error. Invalid tokens.
-> (1+3/4
Invalid expression, too much tokens.
-> 2312312 * 334234
772853289008.000000000000
-> (((2+3)*4+sin(pi)-exp(e))*(3-2+fabs(-1.0)))
9.691475517041
-> (((2+3)*4+sin(pi)-exp(e))*(3-2+fabs(-1.0))) * 10
96.914755170415
-> EXIT
Bye.
```