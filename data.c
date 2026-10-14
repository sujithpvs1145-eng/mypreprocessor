
#include <stdio.h>
#include <string.h>
#include "myheader.h"

#define MAX 1000000
#define PI 3.14
#define COUNT 10
#define ZERO 0

// TEST 1: Global variable
int count = ZERO;

/*
   TEST 2: Multiline comment
   This entire block should disappear.
*/

int add(int a, int b)
{
    // TEST 3: Inline comment
    int result = a + b;
    return result;
}

int main()
{
    // TEST 4: Basic macro replacement
    int size = MAX;
    float radius = PI;

    // TEST 5: Multiple macros in one line
    int total = MAX + COUNT + ZERO;

    // TEST 6: Repeated occurrences
    int repeated = MAX + MAX + MAX;

    // TEST 7: Macro next to operators and punctuation
    int calc = (MAX*2)+COUNT;

    // TEST 8: Normal identifiers containing macro-like text
    int MAXIMUM = 50;
    int COUNTDOWN = 20;

    // TEST 9: Comment-looking text inside strings
    printf("This contains // but is not a comment\n");
    printf("This contains /* and */ but is not a comment\n");

    char str1[] = "Hello // World";
    char str2[] = "Hello /* World */";

    // TEST 10: Macro name inside a string
    char str3[] = "MAX PI COUNT";

    // TEST 11: Normal C expression
    int a = 10;
    int b = 20;
    int sum = add(a, b);

    printf("%d %d %d\n", size, total, repeated);
    printf("%d\n", sum);

    return 0;
}

    /*
       Another multi-line comment
       printf("This should not appear\n");
    */

    for (int i = 0; i < 5; i++)
    {
        printf("Iteration %d\n", i); // loop
    }

    printf("a = %d // not a comment\n", a);
    printf("b = %d /* not a comment */\n", b);

    return 0;
}

/*
   End of program
   Final comment
*/
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
-- INSERT --                                                                                                                                                                                                                                                                                                                                                          30,37         All
