#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

//Definition Global Constant Values
#define TITLE " DECIMAL TO RADIX-i converter"
#define AUTHOR "DAKALO RATSHIFHETI"
#define YEAR 2022

void Dec2RadixI(int decNum,int radixNum)
{
    int numBits = ceil((log(decNum+1)/log(radixNum))) - 1;
    int quotient = 0; //Variable used to increment the quotient.
    int bitsCopy = numBits; //Variable used to store numBits.
    int decNumCopy =decNum; //Variable used to store a copy of decNum.
    int currentBit;

    printf("The radix-n value is "); //printing the output statement

    //function used to get the radix value
    do
    {
        quotient = trunc((decNumCopy)/pow(radixNum,bitsCopy));
        currentBit = quotient;

        if(currentBit < 10)
        {
            printf("%d", currentBit );
        }

        else
        {
            switch(quotient)
            {
                case 10:
                    printf("A");
                    break;

                case 11:
                    printf("B");
                    break;

                case 12:
                    printf("C");
                    break;

                case 13:
                    printf("D");
                    break;

                case 14:
                    printf("E");
                    break;

                case 15:
                    printf("F");
                    break;

            }

        }
        decNumCopy = decNumCopy - ((currentBit)*(pow(radixNum,bitsCopy)) );
        bitsCopy = bitsCopy - 1;


    }

    while(bitsCopy >= 0);

}

int main(void)
{
    printf("*****************************\n");
    printf("%s\n", TITLE); //Title of the code
    printf(" Written by: %s\n", AUTHOR); //Name of the authour
    printf(" Date: %d\n", YEAR); //Year
    printf("*****************************\n");

    int number; //Variable used to store a decimal number entered by user.
    int radix; //Variable used to store a radix entered by user.

    while (number >= 0) // Loop that prompts the user to enter a decimal number and radix and display it on the screen, until the user types in a number less than 0
    {
        printf("Enter a decimal number:");
        scanf("%d", &number);
        if (number < 0) //Terminates the program and displays the message EXIT on the screen when the user types in a number less than 0.
        {
            printf("EXIT"); //Terminate and displays 'EXIT'
            break;
        }
        printf("The decimal number you have entered is %d\n", number); //prints the decimal number entered by user.

        printf("Enter a radix for the converter between 2 and 16: "); //Prompting user to enter a radix between 2 and 16
        scanf("%d", &radix); //Gets input radix given by user.
        printf("The radix you have entered is %d\n", radix); //prints the radix entered by user.

        //Calculating the log2n of the entered decimal number and display the result to the screen.
        double log2 = (log(number))/log(2);
        printf("The log2 of the number is %.2f\n", log2);

        //Calculating the value of the decimal number divided by the radix and displaying the integer result.
        int intdiv = number/radix;
        printf("The intiger result of the number divided by %d is %d\n", radix, intdiv);

        //Calculating the remainder of the decimal number divided by radix and displaying the result.
        int remainder = number%radix;
        printf("The remainder is %d\n", remainder);

        Dec2RadixI(number, radix);
        printf("\n");

    }
return 0;
}
