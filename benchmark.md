# Benchmark

## Ntt benchmark

### Test Environment:

* OS:  Win10 Pro 1803
* CPU: i7-4790K (MMX, SSE, SSE2, SSE3, SSE4.1, SSE4.2, EM64T, VT-x, AES, AVX, AVX2, FMA3)
* Compiler: MinGW-x86_64-8.1.0-win32-seh-rt_v6-rev0
* Msys2: msys2-x86_64-20180531
* Test code: [Ntt test](https://github.com/baihacker/pe/blob/master/test/ntt_test.c)
* Build libbf:
  > gcc -Wall -O3 -mavx -mavx2 -mfma -mbmi2 -c -o libbf.avx2.o libbf.c
 
  > gcc -Wall -O3 -mavx -mavx2 -mfma -mbmi2 -c -o cutils.avx2.o cutils.c
 
  > gcc-ar crv libbf.avx2.a cutils.avx2.o libbf.avx2.o
* Build test target:
  > -o a.exe --std=c++11 -O3 -march=native -mtune=native -fopenmp -Wl,--stack,268435456 -lbf -lgmpxx -lflint -lgmp -lmpfr -lmpir

### Test result

#### Openmp enabled
```cpp
ntt test : data = random, size = 0, n = 1000000, mod = 100019
flint n  : 0.409
flint p  : 1.145
ntt32 s  : 1.002
ntt32 l  : 1.170
ntt64 s  : 1.581
ntt64 l  : 1.683
Min_25 s : 0.157
Min_25 l : 0.178
libbf    : 0.819
ntt test : data = random, size = 1, n = 1479725, mod = 100000000003
flint n  : 1.232
flint p  : 2.923
ntt32 l  : 2.378
ntt64 l  : 3.467
Min_25 l : 0.343
libbf    : 1.362
ntt test : data = random, size = 2, n = 1000000, mod = 316227766016779
flint n  : 0.840
flint p  : 2.081
ntt64 l  : 1.709
Min_25 l : 0.182
libbf    : 0.866
ntt test : data = max mod, size = 0, n = 999996, mod = 1000003
flint n  : 0.418
flint p  : 1.231
ntt32 s  : 1.011
ntt32 l  : 1.160
ntt64 s  : 1.568
ntt64 l  : 1.670
Min_25 s : 0.157
Min_25 l : 0.185
libbf    : 0.821
ntt test : data = max mod, size = 1, n = 1479725, mod = 100000000003
flint n  : 1.235
flint p  : 2.778
ntt32 l  : 2.373
ntt64 l  : 3.375
Min_25 l : 0.348
libbf    : 1.360
ntt test : data = max mod, size = 2, n = 1000000, mod = 316227766016779
flint n  : 0.843
flint p  : 2.086
ntt64 l  : 1.663
Min_25 l : 0.184
libbf    : 0.865

mod = 100019
log2(n)  10     11     12     13     14     15     16     17     18     19     20
flint n  0.000  0.000  0.000  0.000  0.000  0.016  0.015  0.047  0.094  0.219  0.422
flint p  0.000  0.000  0.016  0.000  0.015  0.031  0.078  0.140  0.281  0.578  1.203
ntt32 s  0.000  0.000  0.000  0.016  0.015  0.047  0.063  0.125  0.250  0.515  1.000
ntt32 l  0.000  0.000  0.000  0.016  0.016  0.031  0.063  0.141  0.297  0.578  1.156
ntt64 s  0.015  0.000  0.000  0.016  0.031  0.063  0.079  0.187  0.359  0.750  1.531
ntt64 l  0.000  0.000  0.016  0.016  0.031  0.062  0.078  0.188  0.422  0.812  1.671
Min_25 s 0.000  0.000  0.000  0.000  0.016  0.000  0.000  0.016  0.031  0.079  0.156
Min_25 l 0.000  0.000  0.000  0.000  0.000  0.000  0.000  0.015  0.047  0.094  0.172
libbf    0.000  0.000  0.000  0.015  0.000  0.016  0.078  0.094  0.203  0.406  0.828
mod = 100000000003
log2(n)  10     11     12     13     14     15     16     17     18     19     20
flint n  0.000  0.000  0.000  0.000  0.015  0.016  0.031  0.078  0.125  0.391  0.844
flint p  0.000  0.000  0.000  0.016  0.031  0.063  0.109  0.218  0.453  0.937  1.953
ntt32 l  0.000  0.000  0.000  0.016  0.015  0.031  0.062  0.156  0.281  0.562  1.156
ntt64 l  0.000  0.000  0.016  0.016  0.031  0.062  0.094  0.219  0.407  0.812  1.657
Min_25 l 0.015  0.000  0.000  0.000  0.000  0.000  0.016  0.031  0.047  0.093  0.172
libbf    0.000  0.000  0.000  0.000  0.016  0.031  0.047  0.109  0.203  0.421  0.859
mod = 316227766016779
log2(n)  10     11     12     13     14     15     16     17     18     19     20
flint n  0.000  0.000  0.000  0.000  0.000  0.000  0.047  0.093  0.203  0.391  0.844
flint p  0.000  0.015  0.000  0.016  0.031  0.063  0.125  0.235  0.484  1.015  2.125
ntt64 l  0.000  0.000  0.015  0.016  0.031  0.063  0.094  0.187  0.391  0.812  1.703
Min_25 l 0.000  0.000  0.000  0.000  0.000  0.015  0.016  0.032  0.047  0.094  0.171
libbf    0.000  0.000  0.000  0.000  0.016  0.031  0.047  0.110  0.203  0.422  0.859
```

#### Openmp disabled (option "-fopenmp" removed)
```cpp
ntt test : data = random, size = 0, n = 1000000, mod = 100019
flint n  : 0.405
flint p  : 1.159
ntt32 s  : 3.135
ntt32 l  : 4.723
ntt64 s  : 2.509
ntt64 l  : 5.001
Min_25 s : 0.168
Min_25 l : 0.360
libbf    : 0.818
ntt test : data = random, size = 1, n = 1479725, mod = 100000000003
flint n  : 1.236
flint p  : 2.956
ntt32 l  : 9.907
ntt64 l  : 10.506
Min_25 l : 0.744
libbf    : 1.361
ntt test : data = random, size = 2, n = 1000000, mod = 316227766016779
flint n  : 0.831
flint p  : 2.084
ntt64 l  : 5.077
Min_25 l : 0.422
libbf    : 0.860
ntt test : data = max mod, size = 0, n = 999996, mod = 1000003
flint n  : 0.421
flint p  : 1.224
ntt32 s  : 3.126
ntt32 l  : 4.723
ntt64 s  : 2.465
ntt64 l  : 4.992
Min_25 s : 0.174
Min_25 l : 0.355
libbf    : 0.825
ntt test : data = max mod, size = 1, n = 1479725, mod = 100000000003
flint n  : 1.229
flint p  : 2.760
ntt32 l  : 9.954
ntt64 l  : 10.497
Min_25 l : 0.728
libbf    : 1.368
ntt test : data = max mod, size = 2, n = 1000000, mod = 316227766016779
flint n  : 0.839
flint p  : 2.081
ntt64 l  : 5.037
Min_25 l : 0.428
libbf    : 0.862

mod = 100019
log2(n)  10     11     12     13     14     15     16     17     18     19     20
flint n  0.000  0.000  0.000  0.000  0.000  0.000  0.015  0.031  0.078  0.203  0.422
flint p  0.000  0.000  0.000  0.000  0.016  0.032  0.062  0.125  0.282  0.594  1.219
ntt32 s  0.000  0.016  0.000  0.015  0.047  0.063  0.156  0.313  0.672  1.484  3.124
ntt32 l  0.000  0.016  0.000  0.031  0.047  0.109  0.234  0.484  1.015  2.202  4.702
ntt64 s  0.000  0.000  0.016  0.016  0.031  0.062  0.125  0.250  0.546  1.171  2.531
ntt64 l  0.000  0.000  0.000  0.031  0.062  0.125  0.250  0.531  1.110  2.359  5.015
Min_25 s 0.000  0.000  0.000  0.000  0.000  0.000  0.016  0.016  0.031  0.078  0.172
Min_25 l 0.000  0.000  0.000  0.000  0.000  0.015  0.016  0.031  0.078  0.172  0.359
libbf    0.000  0.000  0.000  0.000  0.015  0.032  0.110  0.094  0.203  0.406  0.828
mod = 100000000003
log2(n)  10     11     12     13     14     15     16     17     18     19     20
flint n  0.000  0.000  0.000  0.000  0.000  0.015  0.032  0.063  0.141  0.406  0.859
flint p  0.000  0.000  0.016  0.000  0.015  0.047  0.109  0.218  0.453  0.922  1.938
ntt32 l  0.000  0.000  0.016  0.016  0.047  0.109  0.219  0.484  1.031  2.188  4.703
ntt64 l  0.000  0.000  0.000  0.031  0.062  0.125  0.250  0.531  1.125  2.406  5.093
Min_25 l 0.000  0.000  0.000  0.000  0.016  0.016  0.031  0.047  0.078  0.187  0.406
libbf    0.000  0.000  0.000  0.000  0.015  0.032  0.047  0.110  0.203  0.406  0.860
mod = 316227766016779
log2(n)  10     11     12     13     14     15     16     17     18     19     20
flint n  0.000  0.000  0.000  0.015  0.000  0.000  0.047  0.094  0.203  0.391  0.843
flint p  0.000  0.000  0.000  0.000  0.032  0.062  0.125  0.234  0.485  1.016  2.094
ntt64 l  0.000  0.016  0.015  0.016  0.047  0.125  0.250  0.531  1.125  2.391  5.093
Min_25 l 0.000  0.000  0.000  0.000  0.000  0.016  0.031  0.046  0.093  0.187  0.406
libbf    0.000  0.000  0.000  0.015  0.000  0.016  0.047  0.094  0.204  0.438  0.859
```