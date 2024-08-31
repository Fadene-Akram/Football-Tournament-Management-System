#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <iostream>
#include "Team.h"
#include "Date.h"
#include "BinarySearchTree.h"
#include "Game.h"



class Tournament
{

public:
    Tournament(std::string gender, int age, std::string season);

    void SetTournamentTeams(const std::vector<Team> &TournamentTeams);

    void SetTournamentGames(BinarySearchTree<Game>& games);

    void PrintTeamsRanking(const Date &Date) const;

    void TournamentBestScorersList(const Date &date);

    Team& FindTeam(const std::string &teamName);

    void TeamsKmRun(const std::string &teamName, const Date &date);

    void TeamBestScorersList(const std::string &teamName);

    void TournamentBestScorersList();

private:
    std::string Gender;
    int Age;
    std::string Season;
    std::vector<Team> TournamentTeams;
    BinarySearchTree<Game> Games;
};
#endif