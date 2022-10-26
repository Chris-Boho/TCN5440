#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrStr(char haystack[], char needle[], char buffer[]){
    //iterates though characters in haystack
    for (int i = 0; i < strlen(haystack); i++)
    {
        //checks for first letter matching to begin comparing
        if(haystack[i] == needle[0]){
            buffer[0] = haystack[i];
            //begin comparing every character in needle to characters in haystack
            for(int j = 1; j < strlen(needle); j++){
                if(needle[j] == haystack[i+j]){
                    buffer[j] = haystack[i+j];
                    buffer[j+1] = '\0';
                }
            }
            //compare needle to the word checked in haystack
            if(strcmp(needle, buffer) == 0){
                printf("MATCH FOUND\n");
                return 1;
            }
        }
    }
    printf("NO MATCH!!\n");
    return 0;
}

int main() {

    char* haystack = "apple";
    char* needle = "app";
    char* buf = (char*)malloc(sizeof(char)*strlen(needle));
    char* ptr_buf = buf;
    myStrStr(haystack, needle, buf);
    buf = (char*)malloc(sizeof(char)*strlen(needle));
    printf("Haystack: %s\nNeedle: %s\nBuffer: %s\n-------------\n", haystack, needle, ptr_buf);
    free(buf);

    haystack = "orange";
    needle = "ge";
    ptr_buf = buf;
    myStrStr(haystack, needle, buf);
    buf = (char*)malloc(sizeof(char)*strlen(needle));
    printf("Haystack: %s\nNeedle: %s\nBuffer: %s\n-------------\n", haystack, needle, ptr_buf);
    free(buf);

    haystack = "blueberry";
    needle = "ueber";
    ptr_buf = buf;
    myStrStr(haystack, needle, buf);
    buf = (char*)malloc(sizeof(char)*strlen(needle));
    printf("Haystack: %s\nNeedle: %s\nBuffer: %s\n-------------\n", haystack, needle, ptr_buf);
    free(buf);

    haystack = "grapefruit";
    needle = "terrible";
    ptr_buf = buf;
    myStrStr(haystack, needle, buf);
    buf = (char*)malloc(sizeof(char)*strlen(needle));
    printf("Haystack: %s\nNeedle: %s\nBuffer: %s\n-------------\n", haystack, needle, ptr_buf);
    free(buf);

    //I could not get the ptr_buf to print the whole string,
    //I don't know why it does not work
    //if you could help clear this up, that'd be great
    haystack = "strawberry";
    needle = "strawberry";
    ptr_buf = buf;
    myStrStr(haystack, needle, buf);
    buf = (char*)malloc(sizeof(char)*strlen(needle));
    printf("Haystack: %s\nNeedle: %s\nBuffer: %s\n-------------\n", haystack, needle, ptr_buf);
    free(buf);

    return 0;
}