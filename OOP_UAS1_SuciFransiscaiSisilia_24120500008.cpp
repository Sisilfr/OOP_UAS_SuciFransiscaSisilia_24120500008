#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Forward declaration
class Player;
class Coach;

class Club {
private:
    string name;
    vector<class Team*> teams;

public:
    Club(string name) : name(name) {}

    void addTeam(Team* team) {
        teams.push_back(team);
    }

    void showInfo();
};

class Team {
private:
    string name;
    Coach* headCoach;
    Coach* assistantCoach;
    vector<Player*> players;

public:
    Team(string name) : name(name), headCoach(nullptr), assistantCoach(nullptr) {}

    void setHeadCoach(Coach* coach) {
        headCoach = coach;
    }

    void setAssistantCoach(Coach* coach) {
        assistantCoach = coach;
    }

    void addPlayer(Player* player) {
        players.push_back(player);
    }

    void showInfo();
};

class Coach {
private:
    string name;
    string role; // Head Coach or Assistant Coach

public:
    Coach(string name, string role) : name(name), role(role) {}

    string getName() const {
        return name;
    }

    string getRole() const {
        return role;
    }
};

class Player {
private:
    string name;
    int age;
    string position;

public:
    Player(string name, int age, string position)
        : name(name), age(age), position(position) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getPosition() const {
        return position;
    }
};

// Implementasi fungsi-fungsi informasi
void Team::showInfo() {
    cout << "Team: " << name << endl;
    if (headCoach) {
        cout << "  Head Coach: " << headCoach->getName() << endl;
    }
    if (assistantCoach) {
        cout << "  Assistant Coach: " << assistantCoach->getName() << endl;
    }
    cout << "  Players: " << endl;
    for (auto player : players) {
        cout << "    - " << player->getName()
             << ", Age: " << player->getAge()
             << ", Position: " << player->getPosition() << endl;
    }
}

void Club::showInfo() {
    cout << "Club: " << name << endl;
    for (auto team : teams) {
        team->showInfo();
    }
}

// Main function untuk demo
int main() {
    // Membuat club
    Club club("FC Cakrawala");

    // Membuat team
    Team* teamU23 = new Team("FC Cakrawala Muda");

    // Membuat coach
    Coach* headCoach = new Coach("Coach Budi", "Head Coach");
    Coach* assistantCoach = new Coach("Coach Andi", "Assistant Coach");

    teamU23->setHeadCoach(headCoach);
    teamU23->setAssistantCoach(assistantCoach);

    // Tambah 15 player
    for (int i = 1; i <= 15; i++) {
        Player* p = new Player("Player " + to_string(i), 20 + (i % 3), "Midfielder");
        teamU23->addPlayer(p);
    }

    // Tambahkan team ke club
    club.addTeam(teamU23);

    // Tampilkan informasi club
    club.showInfo();

    return 0;
}
