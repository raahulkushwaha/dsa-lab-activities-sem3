#include <stdio.h>
#include <string.h>

const char *words[13] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
    "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "ELEVEN", "TWELVE"};

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    int nums[100];
    int count = 0;
    int letter_present[26] = {0};

    while (scanf("%d", &nums[count]) == 1)
    {
        if (nums[count] == 999)
        {
            count++;
            break;
        }
        count++;
    }

    // Print original sequence ending with a period
    for (int i = 0; i < count; i++)
    {
        if (nums[i] < 10)
        {
            printf("%d ", nums[i]);
        }
        else if (nums[i] == 999)
        {
            printf("0999. ");
        }
        else
        {
            printf("%d ", nums[i]);
        }

        // Collect distinct letters for numbers between 0 and 12
        if (nums[i] >= 0 && nums[i] <= 12)
        {
            const char *word = words[nums[i]];
            for (int j = 0; word[j] != '\0'; j++)
            {
                letter_present[word[j] - 'A'] = 1;
            }
        }
    }

    // Print unique letters in alphabetical order
    for (int n = 0; n < 26; n++)
    {
        if (letter_present[n])
        {
            printf("%c", 'A' + n);
        }
    }
    printf("\n");

    return 0;
}
