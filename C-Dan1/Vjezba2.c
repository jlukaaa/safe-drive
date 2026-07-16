#include <stdio.h>
#include <stdarg.h>

double pronadji_max(int broj_arg, ...)
{
    if (broj_arg <= 0 )
        {
                return 0;
        }
    va_list args;
    va_start(args, broj_arg);

    double max = 0;
    for (int i = 0; i < broj_arg; i++)
        {
            double x = va_arg(args, double);
            if (x > max)
                {
                    max = x;
                }
        }

        va_end(args);
        return max;
}

int main()
{
    double a = 11;
    double b = 6;
    double c = 10;
    double max = pronadji_max(3,a,b,c);
    printf("%.2f", max);
    return 0;
}