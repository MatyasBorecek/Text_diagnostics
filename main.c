#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH_MAX_LENGTH 255
#define ACTION_MAX_LENGTH 100

#define ROW_ENDING "row-ends-with"
#define WORD_START "word-starts-with"

int main(void) {

    char inputPath[PATH_MAX_LENGTH], outputPath[PATH_MAX_LENGTH];
    scanf("%s", inputPath);
    scanf("%s", outputPath);

    FILE *input = fopen(inputPath, "r");

    int lines = 0, maxLength = 0, tempLength = 0;
    char chr = getc(input);

    //Get number of lines and max. length
    while (1) {
        if (chr == '\n') {
            if (tempLength > maxLength)
                maxLength = (tempLength + 1);
            lines++;
            tempLength = 0;
        } else {
            tempLength++;
        }
        chr = getc(input);

        if (chr == EOF) {
            if (tempLength > maxLength)
                maxLength = tempLength + 1;
            lines++;
            tempLength = 0;
            break;
        }
    }
    rewind(input);

    //Allocate memory and fill it with data
    char *data[lines];
    for (int i = 0; i < lines; i++) {
        data[i] = (char *) malloc(maxLength * sizeof(char));
        fgets(data[i], maxLength + 1, input);

        char *pos;
        if ((pos = strchr(data[i], '\n')) != NULL)
            *pos = '\0';
    }
    fclose(input);

    FILE *outputFile = fopen((char *) outputPath, "w+");
    for (int i = 0;; i++) {

        char action[ACTION_MAX_LENGTH];
        fgets(action, ACTION_MAX_LENGTH, stdin);

        // Program takes \n which was annoying for me so I made this quick hack.
        if (i == 0)
            continue;
        // When you type empty line, program will be exited.
        if (strcmp(action, "\n") == 0)
            break;

        char *arg = strtok(action, " ");
        int counter = 0;

        if (strcmp(arg, ROW_ENDING) == 0) {
            char searching = action[14];
            for (int j = 0; j < lines; j++) {
                if (data[j][strlen(data[j]) - 1] == searching) {
                    counter++;
                }
            }
        } else if (strcmp(arg, WORD_START) == 0) {
            char searching = action[17];
            for (int j = 0; j < lines; j++) {
                for (int z = 0; z < strlen(data[j]); z++) {
                    if ((z == 0 && data[j][z] == searching) || (data[j][z] == ' ' && data[j][z + 1] == searching)) {
                        counter++;
                    }
                }
            }
        }
        fputc(counter + '0', outputFile);
        fputc('\n', outputFile);
    }
    fclose(outputFile);
    free(data);
    return 0;
}