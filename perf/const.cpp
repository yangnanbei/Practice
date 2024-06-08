#include <iostream>
using namespace std;

typedef struct val_
{
    int a;
    int b;
    int c;
}val;

/**
    we can use strace -c to see the cost of each function
    here param is val& v: cost 1.9s
    here param is const val& v: cost 2.9s
    why?

1. val& v
root@VM-8-9-ubuntu:# strace -c ./a.out 
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 37.42    0.000171           7        22           mmap
 21.01    0.000096          13         7           mprotect
  8.32    0.000038           7         5           close
  7.00    0.000032           6         5           openat
  6.35    0.000029           7         4           read
  6.13    0.000028           9         3           brk
  5.69    0.000026           5         5           fstat
  5.25    0.000024          24         1           munmap
  2.84    0.000013           6         2         1 arch_prctl
  0.00    0.000000           0         6           pread64
  0.00    0.000000           0         1         1 access
  0.00    0.000000           0         1           execve
------ ----------- ----------- --------- --------- ----------------
100.00    0.000457                    62         2 total
root@VM-8-9-ubuntu:# g++ const.cpp -g

2. const val& v
root@VM-8-9-ubuntu:# strace -c ./a.out 
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 34.23    0.000331          15        22           mmap
 16.96    0.000164         164         1           execve
 11.48    0.000111          15         7           mprotect
  8.17    0.000079          13         6           pread64
  7.45    0.000072          14         5           openat
  5.69    0.000055          13         4           read
  5.58    0.000054          10         5           fstat
  4.96    0.000048           9         5           close
  2.28    0.000022          22         1           munmap
  1.55    0.000015           7         2         1 arch_prctl
  1.03    0.000010           3         3           brk
  0.62    0.000006           6         1         1 access
------ ----------- ----------- --------- --------- ----------------
100.00    0.000967                    62         2 total

*/
int pass_val(const val& v) {

    //v.c += 1;
    return 0;
}

int main()
{
    val v;
    int i = {0};
    v.a = 1;
    v.b = 2;
    v.c = 3;
    while (i++ < 1000000000)  {
        pass_val(v);
    }
    return 0;
}



