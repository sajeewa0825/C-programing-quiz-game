#include <stdio.h>
#include <stdlib.h>

char selection;
int startGame();
int addQuiz();
void addAnswer(char ans[20]);

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
    char ans[50];
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
            printf("----------------------------------------------------------\n");
            printf("%s",qu);
            printf("Enter Answer \n");
            scanf("%s",&ans);
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
    fgets(qu, 100, stdin);
    printf("Enter Questions\n");
    fgets(qu, 100, stdin);
    printf("Enter Answer\n");
    fgets(ans, 20, stdin);

    FILE *file;

    file = fopen("quiz.txt","a");
    if(file==NULL){
        printf("open fail\n");
        exit(0);
    } else{
        fprintf(file,"%s",qu);
        addAnswer(ans);
    }
    fclose(file);
    main();
    return 0;
}

void addAnswer(char ans[20]) {
    printf("%s",ans);
    FILE *file;

    file = fopen("ans.txt","a");
    if(file==NULL){
        printf("open fail\n");
        exit(0);
    } else{
        fprintf(file,"%s",ans);
    }
    fclose(file);

}

