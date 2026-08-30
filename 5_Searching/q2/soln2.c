#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXP 100
#define BUFLEN 105

char *gems[] = {"NONE", "Garnet", "Amethyst", "Aquamarine", "Diamond", "Emerald", "Pearl", "Ruby", "Peridot", "Sapphire", "Tourmaline", "Topaz", "Lapis", 0};

char ponies[MAXP][BUFLEN];
int numPonies = 0;

// Function to find highest gemstone priority in a given string
int getGemPriority(const char *name)
{
    int maxPriority = 0;

    // Check each gemstone in the priority list (index 1 to 12)
    for (int i = 1; gems[i] != 0; i++)
    {
        const char *gem = gems[i];
        int gemLen = strlen(gem);
        const char *ptr = name;

        while ((ptr = strstr(ptr, gem)) != NULL)
        {
            // Check word boundaries: standalone or separated by spaces
            int validBefore = (ptr == name || *(ptr - 1) == ' ');
            int validAfter = (*(ptr + gemLen) == '\0' || *(ptr + gemLen) == ' ');

            if (validBefore && validAfter)
            {
                if (i > maxPriority)
                {
                    maxPriority = i;
                }
            }
            ptr += gemLen;
        }
    }
    return maxPriority;
}

// Case-insensitive string comparison for alphabetical sorting
int compareIgnoreCase(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        char c1 = tolower((unsigned char)*s1);
        char c2 = tolower((unsigned char)*s2);
        if (c1 != c2)
            return c1 - c2;
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

// Comparator function for qsort
int comparePonies(const void *a, const void *b)
{
    const char *p1 = (const char *)a;
    const char *p2 = (const char *)b;

    int priority1 = getGemPriority(p1);
    int priority2 = getGemPriority(p2);

    if (priority1 != priority2)
    {
        return priority2 - priority1; // Higher gemstone priority comes first
    }

    // If gemstone priorities are equal, sort alphabetically (case-insensitive)
    return compareIgnoreCase(p1, p2);
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    char line[BUFLEN];
    while (fgets(line, sizeof(line), stdin))
    {
        // Remove trailing newline character
        line[strcspn(line, "\r\n")] = '\0';
        if (strcmp(line, "END") == 0)
            break;
        if (strlen(line) > 0)
        {
            strcpy(ponies[numPonies++], line);
        }
    }

    qsort(ponies, numPonies, sizeof(ponies[0]), comparePonies);

    for (int i = 0; i < numPonies; i++)
    {
        printf("%s\n", ponies[i]);
    }

    return 0;
}
