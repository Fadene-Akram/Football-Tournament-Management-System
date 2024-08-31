#ifndef PLAYERSTATISTICS_H
#define PLAYERSTATISTICS_H

#include <iostream>
#include "Date.h"

class PlayerStatistics
{

public:
    PlayerStatistics(int goalscored, int yellowcards, int red_cards, double kilometersrun, int playing_time_start, int playing_time_end, Date date , const std::string& name,int Number) ;

    int Get_goals_scored() const;

    int Get_yellow_cards() const;

    int Get_red_cards() const;

    double Get_kilometers_run() const;

    int Get_time_start_game() const;

    int Get_time_end_game() const;

    std::string getPlayerName() const;

    Date Get_Date() const;

    void Set_goals_scored(int score);

    void Set_yellow_cards(int cards);

    void Set_red_cards(int cards);

    void Set_kilometers_run(double km);

    void printPlayerStat() const;


    bool operator<(const PlayerStatistics &playerstat);
    bool operator<(const PlayerStatistics& other) const ;


private:
    std::string playerName;
    int playerNumber;
    int goals_scored;
    int yellow_cards;
    int red_cards;
    double kilometers_run;  // Real number for kilometers run
    int playing_time_start; // Time in minutes when the player starts playing
    int playing_time_end;   // Time in minutes when the player is replaced or game ends
    Date Date;              // this is ID for the game
};
#endif