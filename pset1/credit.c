//JT Williams
//credit card authorization in C

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Credit Card Number: ");
    long long cardnumber = get_long_long();

    while (cardnumber > 0)
    {
        cardnumber = cardnumber / 10;
        len += 1;
    }

    int digit = cardnumber[len - 1];

    printf("%i", digit);

}