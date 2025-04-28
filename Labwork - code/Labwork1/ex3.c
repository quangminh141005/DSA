#include <stdio.h>

typedef struct
{
    int real_unit;
    int imagine_unit;
} comp_num;

comp_num add(comp_num a, comp_num b);
comp_num multiply(comp_num a, comp_num b);

int main(void)
{
    comp_num num1;
    comp_num num2;

    printf("Enter the real unit and imagin unit of the FIRST number: ");
    scanf("%d%d",&num1.real_unit, &num1.imagine_unit);
    
    printf("Enter the real unit and imagin unit of the SECOND number: ");
    scanf("%d%d",&num2.real_unit, &num2.imagine_unit);

    comp_num sum =  add(num1, num2);
    comp_num product = multiply(num1, num2);

    printf("The sum of two number is: %d + %di\n", sum.real_unit, sum.imagine_unit);
    printf("The accumulation of two number is:  %d + %di\n", product.real_unit, product.imagine_unit);  
    return 0; 
}

comp_num add(comp_num a, comp_num b)
{
    comp_num temp;
    temp.real_unit = a.real_unit + b.real_unit;
    temp.imagine_unit = a.imagine_unit + b.imagine_unit;

    return temp;
}

comp_num multiply(comp_num a, comp_num b)
{
    comp_num temp;
    temp.real_unit = a.real_unit * b.real_unit - a.imagine_unit * b.imagine_unit;
    temp.imagine_unit = a.real_unit * b.imagine_unit + a.imagine_unit + b.real_unit;

    return temp;
}