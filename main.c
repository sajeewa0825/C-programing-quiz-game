#include <stdio.h>
#include <stdlib.h>

char selection;
int startGame();
int addQuiz();

int main() {
    printf("\n-------------WELCOME TO THE C PROGRAMING GAME-------------\n\n");
    printf("----------------------------------------------------------\n");
    printf("Press S to start game\n");
    printf("Press V to view high score\n");
    printf("Press A Edit quiz\n");
    printf("Press H for help\n");
    printf("Press Q to quit game\n");
    printf("----------------------------------------------------------\n");

    scanf("%s",&selection);

    switch (selection) {
        case 's':
            startGame();
            break;
        case 'a':
            addQuiz();
            break;
        case 'V':
            printf("v \n");
            break;
        case 'H':
            printf("h\n");
            break;
        case 'q':
            exit(0);
        default:
            printf("invalid ");
    }
    return 0;
}

int startGame() {
    char qu[100];
    char ans[20];
    int number=0,count=0,end;

    FILE *file;
    file = fopen("quiz.txt","r");

    if (file == NULL){
        printf("file open fail \n");
        exit(0);
    } else{
        printf("how many questions do you need \n");
        scanf("%d",&number);

        while (count<number ){
            fgets(qu,sizeof(qu),file);
            printf("%s \n",qu);
            end = getc(file);
            if (end == EOF){
                printf("....end all questions questions..... %d \n",end);
                break;
            }
            count=count+1;
        }

    }





    main();
    return 0;
}

int addQuiz(){
    char qu[100];
    char ans[20];
    printf("Enter Questions\n");
    scanf("%s[^\n]",qu);
    printf("Enter Answer\n");
    scanf("%s[^\n]",ans);

    FILE *file;

    file = fopen("quiz.txt","a");
    if(file==NULL){
        printf("open fail\n");
        exit(0);
    } else{
        fprintf(file,"%s %s\n",qu,ans);
    }
    fclose(file);
    main();
    return 0;
}
