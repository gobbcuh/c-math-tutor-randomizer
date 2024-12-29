#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

float addNum(float addend1, float addend2);
float subtractNum(float minuend, float subtrahend);
float multiplyNum(float multiplicand, float multiplier);
float divideNum(float dividend, float divisor);

int maxQuestions();
int maxValue();
int randomizing(int maxInput);

void delay(unsigned int secs);
void intro_loading();
void exit_loading(int overallScore, int overallQuestions);

int main()
{
    int operatorChoice, num1, num2, maxValueInput, maxQuestionInput;
    int score = 0, totalQuestions = 0, overallScore = 0, overallQuestions = 0;
    char continueChoice, again;

    printf("\n\n\n\n\n\n\t\t\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t  WELCOME TO JASMIN'S MATH RANDOMIZER TUTOR!\n");
    printf("\t\t\t\t\t---------------------------------------------------------------\n");

    printf("\n\t\t\t\t\t\t\t\t INTRODUCTION\n");
    printf("\n\t\t\t\t\t        Hello, young learner! Let's play a fun Math game!\n");
    printf("\t\t\t\t\t    You will answer fun Math questions that pop up randomly!\n");
    printf("\t\t\t\t\tJust type your answer and let's see how many you can get right!\n");

    printf("\n\t\t\t\t\t---------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tWould you like to continue?\n\t\t\t\t\tPress [Y] if YES and [N] if NO\n");

    do
    {
        printf("\n\t\t\t\t\tEnter your choice: ");
        scanf(" %c", &continueChoice);

        if (continueChoice != 'Y' && continueChoice != 'y' && continueChoice != 'N' && continueChoice != 'n')
        {
            printf("\t\t\t\t\tOops! Choose between [Y] and [N] only.\n");
        }

    } while (continueChoice != 'Y' && continueChoice != 'y' && continueChoice != 'N' && continueChoice != 'n');

    if (continueChoice == 'Y' || continueChoice == 'y')
    {
        intro_loading();
        delay(1000);
    }
    else if (continueChoice == 'N' || continueChoice == 'n')
    {
        exit_loading(overallScore, overallQuestions);
        delay(1000);
        return 0;
    }

    do
    {
        score = 0;
        totalQuestions = 0;

        printf("\n\n\t\t\t\t\t--------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t   MATH TUTOR MENU");
        printf("\n\t\t\t\t\t--------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t  [1] ADDITION\n\t\t\t\t\t\t\t\t  [2] SUBTRACTION\n\t\t\t\t\t\t\t\t  [3] MULTIPLICATION\n\t\t\t\t\t\t\t\t  [4] DIVISION\n\t\t\t\t\t\t\t\t  [5] EXIT");
        printf("\n\t\t\t\t\t--------------------------------------------------------------------------\n");

        printf("\t\t\t\t\tNow, pick a type of Math question.\n");
        printf("\t\t\t\t\tYou can choose between addition, subtraction, multiplication, or division!\n");

        do
        {
            printf("\n\t\t\t\t\tPick a Math game: ");
            scanf("%d", &operatorChoice);

            if (operatorChoice < 1 || operatorChoice > 5)
            {
                printf("\t\t\t\t\tOops! Choose a number between 1 and 5 only.\n");
            }

        } while (operatorChoice < 1 || operatorChoice > 5);

        if (operatorChoice == 5)
        {
            exit_loading(overallScore, overallQuestions);
            delay(1000);
            return 0;
        }

        do
        {
            maxQuestionInput = maxQuestions();
            float correctAnswers[maxQuestionInput];
            float userAnswers[maxQuestionInput];

            maxValueInput = maxValue();

            srand(time(NULL));
            totalQuestions = 0;

            while (totalQuestions < maxQuestionInput)
            {
                num1 = randomizing(maxValueInput);
                num2 = randomizing(maxValueInput);

                switch (operatorChoice)
                {
                    case 1:
                        correctAnswers[totalQuestions] = addNum(num1, num2);
                        printf("\n\t\t\t\t\tWhat is the sum of %d and %d: ", num1, num2);
                        break;

                    case 2:
                        if (num1 < num2)
                        {
                            int swap = num1;
                            num1 = num2;
                            num2 = swap;
                        }
                        correctAnswers[totalQuestions] = subtractNum(num1, num2);
                        printf("\n\t\t\t\t\tWhat is the difference of %d and %d: ", num1, num2);
                        break;

                    case 3:
                        correctAnswers[totalQuestions] = multiplyNum(num1, num2);
                        printf("\n\t\t\t\t\tWhat is the product of %d and %d: ", num1, num2);
                        break;

                    case 4:
                        if (num2 == 0)
                        {
                            num2 = 1;
                        }
                        correctAnswers[totalQuestions] = divideNum(num1, num2);
                        printf("\n\t\t\t\t\tWhat is the quotient of %d and %d: ", num1, num2);
                        break;
                }

                scanf("%f", &userAnswers[totalQuestions]);
                totalQuestions++;
                overallQuestions++;

                if (userAnswers[totalQuestions - 1] == correctAnswers[totalQuestions - 1])
                {
                    printf("\t\t\t\t\tGreat Job! Your answer is correct!\n");
                    score++;
                    overallScore++;
                }
                else
                {
                    printf("\t\t\t\t\tNice Try! The correct answer is %.2f.\n", correctAnswers[totalQuestions - 1]);
                }
            }

            printf("\n\t\t\t\t\tCONGRATULATIONS! You've completed the questions!\n");
            printf("\t\t\t\t\tYour final score: %d/%d\n", score, totalQuestions);

            printf("\n\t\t\t\t\tDo you want to try another problem?\n\t\t\t\t\tPress [Y] if YES or Press [N] if NO\n");
            printf("\t\t\t\t\tEnter your choice: ");
            scanf(" %c", &again);

            if (again == 'n' || again == 'N')
            {
                system("cls");
                delay(1000);
                break;
            }

            score = 0;

        } while (again == 'y' || again == 'Y');

    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}

int maxQuestions()
{
    int max_questions;
    printf("\t\t\t\t\t--------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tHow many questions would you like to answer for this operation? ");
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &max_questions);

    while (max_questions <= 0 || max_questions > 10)
    {
        printf("\t\t\t\t\tOops! Choose a number between 1 and 10 only.\n");
        printf("\n\t\t\t\t\tEnter your choice: ");
        scanf("%d", &max_questions);
    }

    return max_questions;
}

int maxValue()
{
    int max_value;
    printf("\n\t\t\t\t\tWhat is the biggest number you'd like to use in the game?\n");
    printf("\t\t\t\t\tEnter your choice: ");
    scanf("%d", &max_value);

    while (max_value <= 0 || max_value > 100)
    {
        printf("\t\t\t\t\tOops! Choose a number between 1 and 100 only.\n");
        printf("\n\t\t\t\t\tEnter your choice: ");
        scanf("%d", &max_value);
    }

    return max_value;
}

int randomizing(int maxInput)
{
    return rand() % maxInput;
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

void intro_loading()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\tStarting the program... Please wait! ");
    for (int i = 1; i <= 25; i++)
    {
        Sleep(100);
        printf("%c", 219);
    }
    system("cls");
}

void exit_loading(int overallScore, int overallQuestions)
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\tExiting the program... Please wait! ");
    for (int i = 1; i <= 25; i++)
    {
        Sleep(100);
        printf("%c", 219);
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\tTHANK YOU FOR VISITING JASMIN'S MATH RANDOMIZER TUTOR!\n");
    printf("\t\t\t\t\t\t\t\tOverall Score: %d/%d\n\n\n\n\n", overallScore, overallQuestions);
}