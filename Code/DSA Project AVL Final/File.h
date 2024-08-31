#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Player.h"
#include "Team.h"
#include "Game.h"
#include <cstring>
#include <algorithm>
#include "Tournament.h"

class File
{
public:
    void readPlayersFromCSV(const std::string &filename, Team &t1);

    void readTeamsFromCSV(const std::string &filename, Tournament &t1);

    void readPlayerStatisticsFromCSV(const std::string &filename, Player &p1);

    void readTeamStatisticsFromCSV(const std::string &filename, Team &t1);

    void readGamesFromCSV(const std::string &filename, Tournament &t1);
};

#endif