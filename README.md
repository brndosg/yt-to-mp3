# YT-to-MP3 Converter
This project is a way for me to learn C programming, especially in the topics of string manipulations, advanced syntax, and exploring new built-in libraries.
I've always had trouble downloading a youtube video such as sound effects and song to be used in video editing. It's a hassle to open a new website everytime
that converts the video to mp3 for you. As a result, I thought that this project can provide both educational values and practical usage for me and for others
who share the same struggle.
<br></br>
The converter utilizes [yt-dlp](https://github.com/yt-dlp/yt-dlp) as the engine behind the converting. No, this project was not made from scratch. To put it simply,
this converter uses ```system()``` to use yt-dlp from the cmd terminal to download and convert youtube links.

## Usage
You can download the zip file containing the program [here](https://github.com/brndosg/yt-to-mp3/releases/tag/v1.0). Click on <ins>YT-to-MP3.rar</ins>
and extract the files.
<br><br>
Once file is extracted, open <ins>main.exe</ins> and input a youtube link. To exit from the program, simply press enter when prompt with an input. MP3 output is
placed in the *Downloads* folder.

## How it works
The program ```main()``` function runs in an infinite while loop so the user does not need to enter the program everytime they want to convert a youtube link.
In the ```mainInput()``` function, the input link from the user is obtained. The program will only exit if user does not input anything.
```c
char *inputLink;
char userInputLink[100];    // TBD: Check if input exceeds 100
printf("Input a youtube video link: ");
fgets(userInputLink, sizeof(userInputLink), stdin);
if (userInputLink[0] == '\n'){ 
    printf("Exiting program..");
    exit(EXIT_SUCCESS);
}
```
To make sure the link input by the user is a youtube link, ```checkInputLink()``` function is used by checking if the string input contains a youtube substring
using ```strstr()```. 
<br><br>
The engine of this program is the ```createFile()``` function. When the link check returns a success value, the function will run by using ```system()``` to 
run a command line and utilizing **yt-dlp**. 
```c
int inputSize = strlen(inputLink) + 1;
char *cmdInput = "yt-dlp -x --audio-format mp3 --no-playlist -P \"./Downloads\"";
char systemCmdInput[256];
// "strlen(cmdInput) + strlen(inputLink) + 4" 4 added bytes for whitespace, quotation marks and \0.
snprintf(systemCmdInput, strlen(cmdInput) + strlen(inputLink) + 4, "%s \"%s\"", cmdInput, inputLink);   
system(systemCmdInput);
```
