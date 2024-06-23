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

int global_init_var = 84;
int global_uninit_var;

void func1(int i)
{
    printf("%d\n", i);
}

int main(void)
{
    static int staitc_var = 85;
    static int staitc_var2;
    int a = 1;
    int b;

    func1(staitc_var + staitc_var2 + a + b);

    return a;
}