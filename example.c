#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

float addNum(float addend1, float addend2);
float subtractNum(float minuend, float subtrahend);
float multiplyNum(float multiplicand, float multiplier);
float divideNum(float dividend, float divisor);

int maxValue();
int randomizing (int num1, int num2);

void delay(unsigned int secs);
void exit_loading();

int main()
{
    int operatorChoice, num1, num2, maxInput;
    float correctAnswer, answer; 
    char again;

    printf("\t\tWELCOME TO JASMIN'S MATH RANDOMIZER TUTOR!\n");

    do
    {
        printf("\n\t\t\t   MATH TUTOR MENU\n\t\t\t[1] ADDITION\n\t\t\t[2] SUBTRACTION\n\t\t\t[3] MULTIPLICATION\n\t\t\t[4] DIVISION\n\t\t\t[5] EXIT\n");

        do
        {
            printf("\n\t\tEnter your choice: ");
            scanf("%d", &operatorChoice);

            if (operatorChoice < 1 || operatorChoice > 5)
            {
                printf("\t\tInvalid. Please enter between 1 and 5 only.\n");
            }
        } while (operatorChoice < 1 || operatorChoice > 5);

        if (operatorChoice == 5)
        {
            exit_loading();
            delay(1000);
            return 0;
        }

        maxInput = maxValue();
        if (maxInput <= 0 || maxInput > 100)
        {
            printf("Invalid input. Please enter a value between 1 and 100.\n");
            continue;
        }

        srand(time(NULL));
        num1 = rand() % maxInput;
        num2 = rand() % maxInput;

        switch (operatorChoice)
        {
            case 1: 
                correctAnswer = addNum(num1, num2);
                printf("\n\t\tWhat is the sum of %d and %d: ", num1, num2);
                break;

            case 2: 
                if (num1 < num2)
                {
                    int swap = num1;
                    num1 = num2;
                    num2 = swap;
                }
                correctAnswer = subtractNum(num1, num2);
                printf("\n\t\tWhat is the difference of %d and %d: ", num1, num2);
                break;

            case 3: 
                correctAnswer = multiplyNum(num1, num2);
                printf("\n\t\tWhat is the product of %d and %d: ", num1, num2);
                break;

            case 4: 
                if (num2 == 0)
                {
                    num2 = 1;
                }
                correctAnswer = divideNum(num1, num2);
                printf("\n\t\tWhat is the quotient of %d and %d: ", num1, num2);
                break;
        }

        scanf("%f", &answer); 

        if (answer == correctAnswer)
        {
            printf("\t\tCorrect! Well done!\n");
        }
        else
        {
            printf("\t\tIncorrect. The correct answer is: %.2f\n", correctAnswer);
        }

        printf("\n\t\tWould you like to try another problem?\n\t\tPress [Y] if YES or Press [N] if NO: ");
        scanf(" %c", &again); 

    } while (again == 'y' || again == 'Y');  

    printf("\n\t\tTHANK YOU FOR VISITING JASMIN'S MATH RANDOMIZER TUTOR!");
    return 0;
}

int maxValue()
{
    int max_num;
    printf("\n\t\tWhat is the maximum value you'd like the random number to be?\n");
    printf("\t\tYour choice: ");
    scanf("%d", &max_num);
    return max_num;
}

float addNum(float addend1, float addend2)
{
    return addend1 + addend2;
}

float subtractNum(float minuend, float subtrahend)
{
    return minuend - subtrahend;
}

float multiplyNum(float multiplicand, float multiplier)
{
    return multiplicand * multiplier;
}

float divideNum(float dividend, float divisor)
{
    return dividend / divisor;
}

void delay(unsigned int secs)
{
    clock_t interval = clock() + secs;
    while (interval > clock());
}

void exit_loading()
{
    system("cls");
    printf("\n\n\n\n");
    printf("\n\n\t\t\tExiting the program... Please wait! ");
    for (int i = 1; i <= 25; i++)
    {
        Sleep(100);
        printf("%c", 219);
    }
    printf("\n\t\t\tProgram ended successfully!");
}