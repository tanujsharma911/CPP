// Author: Tanuj Sharma
// Section: B

#include <stdio.h>
#include <stdlib.h>

char songs[3][100] = {
    "Alice",
    "Bob",
    "Carol"
};
int currentPlaying = 0;

void addPlayNext(char songName[]);
char currentlyPlaying();
void fineshed();

int main() {
    // addToPlayNext("song one");
    // printf("%s", currentlyPlaying());
    // fineshed();

    
    

    return 0;
}

void addPlayNext(char songName[]){
    strcpy(songs, songName);
}
char currentlyPlaying(){

}
void fineshed();