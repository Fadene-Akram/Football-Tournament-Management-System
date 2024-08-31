#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Team.h"

class Game
{

public:
    Game(Team &home_team, Team &away_team, Date date_time, std::string startTime, std::string referee, int home_team_score, int away_team_score, int duration_minutes);

    Team &get_home_team();

    Team &get_away_team();

    Date getGameDate() const;

    std::string get_refere() const;

    int get_duration() const;

    std::string get_start_time() const;

    void PrintGameInfo() const;
    bool operator<(const Game &game) const;

private:
    Team Home_team;
    int home_score;
    Team Away_team;
    int away_score;
    Date gameDate;
    std::string gameStartTime;
    std::string Referee;
    int Duration_minutes;
};
#endif