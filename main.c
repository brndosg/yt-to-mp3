#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFile(char inputLink[]);
int checkInputLink(char inputLink[]);
int mainInput();

// Function for creating file
void createFile(char inputLink[]){
    if(checkInputLink(inputLink)){
        int inputSize = strlen(inputLink) + 1;
        char *cmdInput = "yt-dlp -x --audio-format mp3 --no-playlist";
        char systemCmdInput[256];
        // "strlen(cmdInput) + strlen(inputLink) + 4" 4 added bytes for whitespace, quotation marks and \0.
        snprintf(systemCmdInput, strlen(cmdInput) + strlen(inputLink) + 4, "%s \"%s\"", cmdInput, inputLink);   
        system(systemCmdInput);
    } else {
        printf("Please input a youtube link!");
    }
}

// Check youtube link
int checkInputLink(char inputLink[]){
    char requiredString1[] = "https://www.youtube.com/watch?";
    char requiredString2[] = "https://www.youtu.be/";
    char *a = strstr(inputLink, requiredString1);
    char *b = strstr(inputLink, requiredString2);
    if (a || b){
        return 1;
    } else {
        return 0;
    }
}

// Function for main input
int mainInput(){
    char *inputLink;
    char userInputLink[100];    // TBD: Check if input exceeds 100
    printf("Brando's YT to MP3 converter\n---------------\n\nInput a youtube video link: ");
    scanf("%s", userInputLink);

    inputLink = calloc(strlen(userInputLink) + 1, sizeof(char));
    if (!inputLink) {
        printf("Error initializing memory... Exiting program");
        return 0;
    }
    strcpy(inputLink, userInputLink);
    createFile(inputLink);

}

int main(){
    int a;
    mainInput();
    scanf("%d", a);
    return 0;

}