#include <stdio.h>
#include <math.h>

int rad(double radians)
{
    return (radians * (180.0 / M_PI));
}

int main()
{
    int x = 0;
    int y;
    int angle =450;

    while( x <= 100)
    {
        y =0;
        while (y < 100)
        {
           printf("x = %d && y = %d\n", x * cos(angle) + 10 * sin(angle), y * sin(angle) + 10 * cos(angle));
           y++;
        }
        x++;
    }
}