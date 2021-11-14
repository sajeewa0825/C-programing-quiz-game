#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char selection;
int startGame();
int addQuiz();
void addAnswer(char ans[20]);
int answercheck(char ans [50]);
int highscore ();
int highscoreview ();

int mark=0;
int count=0;
int number=0;

int main() {
    printf("\n-------------WELCOME TO THE C PROGRAMING GAME-------------\n\n");
    printf("----------------------------------------------------------\n");
    printf("Press S to start game\n");
    printf("Press V to view high score\n");
    printf("Press A Add quiz\n");
    printf("Press H for help\n");
    printf("Press Q to quit game\n");
    printf("----------------------------------------------------------\n");

    scanf("%s",&selection);

    switch (selection) {
        case 'S':
            startGame();
            break;
        case 'A':
            addQuiz();
            break;
        case 'V':
            highscoreview ();
            break;
        case 'H':
            printf("play game and help to improve\n");
            main();
            break;
        case 'Q':
            exit(0);
        default:
            printf("invalid ");
    }
    return 0;
}

int startGame() {
    char qu[100];
    char ans[50];
    int end;

    FILE *file;
    file = fopen("quiz.txt","r");

    if (file == NULL){
        printf("file open fail \n");
        exit(0);
    } else{
        printf("how many questions do you need \n");
        scanf("%d",&number);
        fgets(ans, 50, stdin);

        for (count=0;count<number;++count){
            fgets(qu,sizeof(qu),file);
            printf("----------------------------------------------------------\n");
            printf("%s",qu);
            printf("----------------------------\n");
            printf("Enter Answer \n");
            fgets(ans, 50, stdin);
            answercheck(ans);
            end = getc(file);
            if (end == EOF){
                printf("....end all questions questions..... %d \n",end);
                break;
            }
        }
        highscore ();
        mark=0;
        count=0;

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

int answercheck(char ans [50]){
    FILE *file;
    char answer[50];
    int value;
    int co =0;

    file = fopen("ans.txt","r");
    if(file==NULL){
        printf("open fail\n");
        exit(0);
    } else{
        for (int i = 0; i < number ; ++i) {
            fgets(answer,sizeof(answer),file);
            if (i == count){
                value = strcmp(answer,ans);
                if (value == 0){
                    mark = mark+2;
                } else{
                    printf("answer is wrong\n");
                }
            }
        }
    }
    fclose(file);
    printf("---mark is %d--- \n",mark);
    return 0;
}

int highscore (){
    FILE *file;
    int sco=0;
    file = fopen("score.txt","r");
    if(file==NULL){
        printf("open fail\n");
        exit(0);
    } else{
        fgets((int )sco,sizeof(sco),file);
        fclose(file);
        if(sco<mark){
            file = fopen("score.txt","w");
            fprintf(file,"%d",mark);
            fclose(file);
        }
    }

    return 0;

}

int highscoreview (){
    FILE *file;
    char scor[10];
    file = fopen("score.txt","r");
    if(file==NULL){
        printf("open fail\n");
        exit(0);
    } else{
        fgets(scor,sizeof(scor),file);
        printf("higher score is %s\n",scor);
    }
    fclose(file);
    main();
}

