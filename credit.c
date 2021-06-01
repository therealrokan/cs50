#include <stdio.h>
#include <cs50.h>

long first2num(long n);
long removelastdigit(long m);
int main(void)
{
    long number = get_long("Enter your credit card number: ");
    //check length
    long length=0;
    long lengthchecker=number;
    while(lengthchecker>0)
    {
        lengthchecker=removelastdigit(lengthchecker);
        length++;
    }
    //checksum
    long luhnnum=number;
    long checksum=0;
    while (luhnnum>0)
    {
        luhnnum=removelastdigit(luhnnum);
        long a = (2*(luhnnum%10));
        while (a>0)
        {
            checksum+=(a%10);
            removelastdigit(a);
        }
        luhnnum=removelastdigit(luhnnum);
    }
    long luhnnum2=number;
    while (luhnnum>0)
    {
        checksum+=(luhnnum2%10);
        removelastdigit(luhnnum2);
        removelastdigit(luhnnum2);
    }
    //results
    if (checksum%10==0)
    {
        if (first2num(number)==34 || first2num(number)==37)
        {
            if (length==15)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (first2num(number)==51 || first2num(number)==52 || first2num(number)==53 || first2num(number)==54 || first2num(number)==55)
        {
            if (length==16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (removelastdigit(first2num(number))==4)
        {
            if (length==13 || length==16)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
long removelastdigit(long m)
{
    m-=(m%10);
    m/=10;
    return m;
}
long first2num(long n)
{
    while (n>99)
    {
        n=removelastdigit(n);
    }
    return n;
}
