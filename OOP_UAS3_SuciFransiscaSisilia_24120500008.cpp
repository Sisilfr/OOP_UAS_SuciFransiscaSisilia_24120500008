#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ==== Abstract Base Class ====
class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    virtual void getInfo() const = 0;
    virtual ~Person() {}
};

// ==== Subclasses ====
class Player : public Person {
private:
    string position;

public:
    Player(string name, int age, string position)
        : Person(name, age), position(position) {}

    void getInfo() const override {
        cout << "Player - Name: " << name << ", Age: " << age
             << ", Position: " << position << endl;
    }
};

class Coach : public Person {
private:
    string role;

public:
    Coach(string name, int age, string role)
        : Person(name, age), role(role) {}

    string getRole() const { return role; }

    void getInfo() const override {
        cout << role << " - Name: " << name << ", Age: " << age << endl;
    }
};

// ==== Abstract Factory ====
class PersonFactory {
public:
    virtual Person* createPerson(string name, int age) = 0;
    virtual ~PersonFactory() {}
};

// ==== Concrete Factories ====
class PlayerFactory : public PersonFactory {
private:
    string position;

public:
    PlayerFactory(string position) : position(position) {}

    Person* createPerson(string name, int age) override {
        return new Player(name, age, position);
    }
};

class CoachFactory : public PersonFactory {
private:
    string role;

public:
    CoachFactory(string role) : role(role) {}

    Person* createPerson(string name, int age) override {
        return new Coach(name, age, role);
    }
};

// ==== Forward Declaration ====
class Coach; // handled by Person pointer now

// ==== Team Class ====
class Team {
private:
    string name;
    Person* headCoach;
    Person* assistantCoach;
    vector<Person*> players;

public:
    Team(string name) : name(name), headCoach(nullptr), assistantCoach(nullptr) {}

    void setHeadCoach(Person* coach) {
        headCoach = coach;
    }

    void setAssistantCoach(Person* coach) {
        assistantCoach = coach;
    }

    void addPlayer(Person* player) {
        players.push_back(player);
    }

    void showInfo() {
        cout << "Team: " << name << endl;
        if (headCoach) headCoach->getInfo();
        if (assistantCoach) assistantCoach->getInfo();
        cout << "Players:" << endl;
        for (auto p : players) {
            p->getInfo();
        }
    }

    ~Team() {
        delete headCoach;
        delete assistantCoach;
        for (auto p : players) delete p;
    }
};

// ==== Club Class ====
class Club {
private:
    string name;
    vector<Team*> teams;

public:
    Club(string name) : name(name) {}

    void addTeam(Team* team) {
        teams.push_back(team);
    }

    void showInfo() {
        cout << "Club: " << name << endl;
        for (auto team : teams) {
            team->showInfo();
        }
    }

    ~Club() {
        for (auto t : teams) delete t;
    }
};

// ==== Main ====
int main() {
    Club* club = new Club("FC Cakrawala");

    // Create team
    Team* teamU23 = new Team("FC Cakrawala Muda");

    // Coach factories
    CoachFactory headCoachFactory("Head Coach");
    CoachFactory assistantCoachFactory("Assistant Coach");

    // Create coaches
    Person* headCoach = headCoachFactory.createPerson("Pak Budi", 45);
    Person* assistantCoach = assistantCoachFactory.createPerson("Pak Andi", 40);

    teamU23->setHeadCoach(headCoach);
    teamU23->setAssistantCoach(assistantCoach);

    // Player factory
    PlayerFactory playerFactory("Midfielder");

    // Add 15 players
    for (int i = 1; i <= 15; ++i) {
        string playerName = "Player " + to_string(i);
        int age = 20 + (i % 3);
        Person* player = playerFactory.createPerson(playerName, age);
        teamU23->addPlayer(player);
    }

    club->addTeam(teamU23);
    club->showInfo();

    delete club;
    return 0;
}
