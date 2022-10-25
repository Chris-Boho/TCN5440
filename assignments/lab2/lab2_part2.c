#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "teams.h"

Team* game(Team* blue_team, Team* red_team){

    int blue_score = 0;
    int red_score = 0;
    
    for (int i = 0; i < 20; i++)
    {
        int rand_num = rand() % 10;
        if (rand_num % 2 == 0)
        {
            blue_score += rand_num;
        } else {
            red_score += rand_num;
        }
    }

    blue_score -= blue_team->handicap;
    red_score -= red_team->handicap;

    printf("%s Score: %d\n", blue_team->team_name, blue_score);
    printf("%s Score: %d\n", red_team->team_name, red_score);

    if (blue_score == red_score)
    {
        if (rand() % 2 == 0)
            blue_score++;
        else
            red_score++;
    }
    if (blue_score > red_score)
    {
        printf("%s Wins!\n", blue_team->team_name);
        return blue_team;
    } else {
        printf("%s Wins!\n", red_team->team_name);
        return red_team;
    }
}

Team* tournament(Team* league_arr[]){
    Team* round_1[4] = {
        game(league_arr[0], league_arr[1]),
        game(league_arr[2], league_arr[3]),
        game(league_arr[4], league_arr[5]),
        game(league_arr[6], league_arr[7]),
    };

    printf("----------------------\nWINNERS OF ROUND 1: \n");
    for (int i = 0; i < 4; i++)
        printf("%s\n", round_1[i]->team_name);

    printf("----------------------\n");
    Team* round_2[2] = {
        game(round_1[0], round_1[1]),
        game(round_1[2], round_1[3])
    };

    printf("----------------------\nWINNERS OF ROUND 2: \n");
    for (int i = 0; i < 2; i++)
        printf("%s\n", round_2[i]->team_name);

    printf("----------------------\n");
    Team* round_3[1] = {
        game(round_2[0],round_2[1])
    };

    printf("----------------------\nWINNER OF ROUND 3: \n");
        printf("%s\n", round_3[0]->team_name);


}

int main(){

    Team team0;
    strcpy(team0.team_name, "First_Team");
    team0.handicap = 1;
    Team* ptr_0 = &team0;

    Team team1;
    strcpy(team1.team_name, "Second_Team");
    team1.handicap = 2;
    Team* ptr_1 = &team1;

    Team team2;
    strcpy(team2.team_name, "Third_Team");
    team2.handicap = 3;
    Team* ptr_2 = &team2;

    Team team3;
    strcpy(team3.team_name, "Fourth_Team");
    team3.handicap = 4;
    Team* ptr_3 = &team3;

    Team team4;
    strcpy(team4.team_name, "Fifth_Team");
    team4.handicap = 5;
    Team* ptr_4 = &team4;

    Team team5;
    strcpy(team5.team_name, "Sixth_Team");
    team5.handicap = 6;
    Team* ptr_5 = &team5;

    Team team6;
    strcpy(team6.team_name, "Seventh_Team");
    team6.handicap = 7;
    Team* ptr_6 = &team6;

    Team team7;
    strcpy(team7.team_name, "Eight_Team");
    team7.handicap = 8;
    Team* ptr_7 = &team7;

    Team* league[8] = {ptr_0, ptr_1, ptr_2, ptr_3, ptr_4, ptr_5, ptr_6, ptr_7};

    srand(time(NULL));

    tournament(league);

    return 0;
}