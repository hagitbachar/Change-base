//
// Created by hagitba on 11/5/17.
//

//answers:
//a) I write two function, one that converts the number from the original base to decimal base, and the second that
//convert from decimal to the input base.
//b)The run time of the first function is O(n) when n is the number of digits, and the second function is O(log n).
//so the run time of the algorithm is O(n).


#include <stdio.h>

/**
 * multiple the number himself accordingly the value in power
 * @param number the number to multiple
 * @param power the number to multiple
 * @return the new number after the multiplication
 */
int power(int number, int power)
{
    int powNumber = 1;

    for (int i = power; i > 0; i--)
    {
        powNumber *= number;
    }
    return powNumber;
}

/**
 * This function change the number from decimal to the input base
 * @param newBase the base that we want in the new number
 * @param number the number in the original base
 */
void changeToInputBase(int newBase, int number)
{

    int newNumber = 0;
    int reminder1 = 0;
    int i = 0;

    while (number >= 1)
    {
        reminder1 = number % newBase;
        number = number / newBase;
        newNumber += reminder1 * power(10, i);
        i++;
    }
    printf("%d\n", newNumber);

}

/**
 * This function change the number from the input base to the decimal number
 * @param originalBase the original base of the given number
 * @param number the number in the original base
 * @return the number in the new base
 */
int changeToTenBase(int originalBase, int number)
{

    int newNumber = 0;

    for (int i = 0; i < 6; i++)
    {
        int reminder = (int)number % 10;

        // that's mean that the given number isn't in the original base
        if (reminder >= originalBase)
        {
            fprintf(stderr, "%s", "invalid!!\n");
            return -1;
        }
        newNumber += reminder % 10 * power(originalBase, i);
        number = number / 10;
    }
    return newNumber;
}

int originalBase, newBase, numberInOriginalBase;

/**
 * the main function the convert the number from the original base to the
 * @return 0 if the code run smooth
 */
int main()
{
    scanf("%i%i%i", &originalBase, &newBase, &numberInOriginalBase);
    int number = changeToTenBase(originalBase, numberInOriginalBase);
    if (number >= 0)
    {
        changeToInputBase(newBase, number);
    }
    return 0;
}