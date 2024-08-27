/**
 * SimpleSection.c
 *
 * Linux:
 *   gcc -c SimpleSection.c
 *
 * Windows:
 *   cl SimpleSection.c /c /Za
 */

int printf(const char* format, ...);

int global_init_var = 84; // .data initialized global var
int global_uninit_var[1000000] = {0};    // .bss  uninitialized global var

void func1(int i)         // .text
{
    printf("%d\n", i);
}

int main(void)
{
    static int staitc_var = 85; // .data initialized local var
    static int staitc_var2;     // .bss  uninitialized local var
    int a = 1;
    int b;

    func1(staitc_var + staitc_var2 + a + b);

    return a;
}
