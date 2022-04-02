#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

//Δηλώσεις συναρτήσεων
void createRandomRatings(int MovieRatings[][COLS]);
void printMovieRatings(int MovieRatings[][COLS]);
int findBestRatedMovie(int MovieRatings[][COLS]);
int findWorstRatedMovie(int MovieRatings[][COLS]);
void printMovieRatingsAverage(int MovieRatings[][COLS], int j);
void sortFriendsRatings(int MovieRatings[][COLS]);
int generateRandomNumber(int lowBound, int highBound);


int main(){
    system("chcp 1253>nul");
    int MovieRatings[ROWS][COLS]={0};
    srand(time(NULL));
    createRandomRatings(MovieRatings);
    printMovieRatings(MovieRatings);
    printf("\n");

    printf("Print the average ratings of each movie\n");


    //Êþäéêáò ãéá ôçí åêôýðùóç ôïõ ÌÏ ôùí âáèìïëïãéþí êÜèå êéíçìáôïãñáöéêÞò ôáéíßáò
    printMovieRatingsAverage(MovieRatings, 0);
    //Êþäéêáò ãéá ôçí åìöÜíéóç ôçò óôÞëçò ìå ôïí õøçëüôåñï ÌÏ âáèìïëïãßáò
    printf("\nMax avg at position: %d\n", findBestRatedMovie(MovieRatings));
    //Êþäéêáò ãéá ôçí åìöÜíéóç ôçò óôÞëçò ìå ôïí ÷áìçëüôåñï ÌÏ âáèìïëïãßáò

    //Êþäéêáò ãéá ôçí åìöÜíéóç ôïõ ÌÏ ôùí âáèìïëïãéþí êÜèå åíüò áðü ôïõò äÝêá ößëïõò ãéá ôéò äÝêá êéíçìáôïãñáöéêÝò ôáéíßåò óå áýîïõóá óåéñÜ
    //Êþäéêáò ãéá ôçí åìöÜíéóç ôçò óåéñÜò ôïõ ðßíáêá üðïõ âñßóêïíôáé ïé âáèìïëïãßåò ôïõ ðéï áõóôçñïý êáé ôïõ ðéï åðéåéêïýò êñéôÞ

    system("PAUSE");
    return 0;
}

void createRandomRatings(int MovieRatings[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            MovieRatings[i][j] = generateRandomNumber(0, 10); //0 + rand() % 10;
        }
    }
}

//Print movie rating
void printMovieRatings(int MovieRatings[][COLS]){
    printf("The ratings of the movies are:\n");
    //Rows
    for (int i = 0; i < COLS; i++) {
        printf("   T%d", i + 1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        //Columns
        for (int j = 0; j < COLS; j++) {
            printf("    %d", MovieRatings[i][j]);
        }
        printf("\n");
    }
}

void printMovieRatingsAverage(int MovieRatings[][COLS], int j){
    int averages[COLS] = {0};
    for(int x=0; x<COLS; x++) {
        double sum = 0;
        for(int y=0; y<ROWS; y++) {
            sum += MovieRatings[y][x];
        }
        printf("The average of the %dst movie is:\t %.2f\n", x + 1, sum / ROWS);
    }
}

int findBestRatedMovie(int MovieRatings[][COLS]){
    float currentMaxAvg = 0;
    int position = -1;
    for(int x = 0;  x < COLS; x++) {
        float sum = 0;
        for(int y = 0; y < ROWS; y++) {
            sum += MovieRatings[y][x];
        }
        float currentAvg = sum / ROWS;
        if (currentAvg > currentMaxAvg) {
            position = x + 1;
            currentMaxAvg = currentAvg;
        }
    }
    return position;

}

int findWorstRatedMovie(int MovieRatings[][COLS]){

}


void sortFriendsRatings(int MovieRatings[][COLS]){

}

int generateRandomNumber(int lowBound, int highBound) {
    return (rand() % (highBound - lowBound + 1)) + lowBound;
}
