#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMDS 5
#define MAXWORDS 50
#define BUFLEN 256
#define TOKENS 4

int cl[CMDS] = {0};
char *lists[CMDS][MAXWORDS];
char *tokens[TOKENS] = {"[N]", "[AV]", "[V]", "[AJ]"};
char *cmds[CMDS] = {"NOUNS", "ADVERBS", "VERBS", "ADJECTIVES", "END"};

int getCategoryIndex(const char *cmd)
{
    for (int i = 0; i < CMDS; i++)
    {
        if (strcmp(cmd, cmds[i]) == 0)
            return i;
    }
    return -1;
}

void substituteAndPrint(const char *templateStr, int offset[4])
{
    char result[1024] = "";
    char temp[1024];
    strcpy(temp, templateStr);

    char *curr = temp;
    while (*curr != '\0')
    {
        int matched = 0;
        // Check placeholders: [N] -> 0, [AV] -> 1, [V] -> 2, [AJ] -> 3
        int tokenMap[4] = {0, 1, 2, 3};

        for (int t = 0; t < TOKENS; t++)
        {
            int tokIdx = tokenMap[t];
            int tokLen = strlen(tokens[tokIdx]);
            if (strncmp(curr, tokens[tokIdx], tokLen) == 0)
            {
                // Append corresponding unused word
                strcat(result, lists[tokIdx][offset[tokIdx]]);
                offset[tokIdx]++;
                curr += tokLen;
                matched = 1;
                break;
            }
        }

        if (!matched)
        {
            int len = strlen(result);
            result[len] = *curr;
            result[len + 1] = '\0';
            curr++;
        }
    }

    printf("%s\n", result);
}

int main()
{
    printf("Roll Number: CH.SC.U4CSE25173\n\n");

    char templateStr[BUFLEN];
    if (!fgets(templateStr, sizeof(templateStr), stdin))
        return 0;
    templateStr[strcspn(templateStr, "\r\n")] = '\0';

    char line[BUFLEN];
    int currentCat = -1;

    while (fgets(line, sizeof(line), stdin))
    {
        line[strcspn(line, "\r\n")] = '\0';
        if (strlen(line) == 0)
            continue;

        int catIdx = getCategoryIndex(line);
        if (catIdx == 4)
            break; // END

        if (catIdx != -1)
        {
            currentCat = catIdx;
        }
        else if (currentCat != -1)
        {
            lists[currentCat][cl[currentCat]] = strdup(line);
            cl[currentCat]++;
        }
    }

    int offset[4] = {0, 0, 0, 0};

    // First substitution
    substituteAndPrint(templateStr, offset);

    // Second substitution using remaining top-most unused words
    substituteAndPrint(templateStr, offset);

    return 0;
}
