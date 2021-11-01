#include <stdio.h>
char selection;
int main() {
    printf("\n-------------WELCOME TO THE C PROGRAMING GAME-------------\n\n");
    printf("----------------------------------------------------------\n");
    printf("Press S to start game\n");
    printf("Press V to view high score\n");
    printf("Press H for help\n");
    printf("Press Q to quit game\n");
    printf("----------------------------------------------------------\n");

    scanf("%s",&selection);

    switch (selection) {
        case 'S':
            printf("s\n");
            break;
        case 'V':
            printf("v \n");
            break;
        case 'H':
            printf("h\n");
            break;
        case 'q':
            printf("q\n");
            break;
        default:
            printf("invalid ");
    }

    return 0;
}
