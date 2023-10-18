// Benjamin Scoggins
#define ARRIVINGANIMALS "./arrivingAnimals.txt"
#define ANIMALNAMES "./animalNames.txt"
#define OUTPUT "./out.txt"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using std::string, std::vector;

enum Species
{
    HYENA, LION, TIGER, BEAR
};

// ----- CLASSES -----
class Animal
{
friend class HeadNode;

private: 
    string _species;
    string _name;
    string _uid;
    string _sex;
    string _color;
    string _origin;
    string _birthDate;

    int _age;
    int _weight;

    static inline int count = 0;

    Animal* next = nullptr;
    Animal* previous = nullptr;

public:
    static int getCount()
    {
        return count;
    }

    Animal(string species, string name, string uid, string sex, string color, 
        string origin, string birthDate, int age, int weight) :
        _species(species), _name(name), _uid(uid), _sex(sex), _color(color), _origin(origin),
        _birthDate(birthDate), _age(age), _weight(weight)
    {
        count++;
    }
};

class Hyena : public Animal{
private:
    static inline int count = 0;

public:
    static int getCount() 
    {
        return count;
    }

    Hyena(string species, string name, string uid, string sex, string color, 
        string origin, string birthDate, int age, int weight) : 
        Animal(species, name, uid, sex, color, origin, birthDate, age, weight)
    {
        count++;
    }
};

class Lion : public Animal{
private:
    static inline int count = 0;

public:
    static int getCount() {
        return count;
    }

    Lion(string species, string name, string uid, string sex, string color, 
        string origin, string birthDate, int age, int weight) : 
        Animal(species, name, uid, sex, color, origin, birthDate, age, weight)
        {
        count++;
        }
};

class Tiger : public Animal{
private:
    static inline int count = 0;

public:
    static int getCount() {
        return count;
    }

    Tiger(string species, string name, string uid, string sex, string color, 
        string origin, string birthDate, int age, int weight) : 
        Animal(species, name, uid, sex, color, origin, birthDate, age, weight) 
    {
        count++;
    }
};

class Bear : public Animal{
private:
    static inline int count = 0;

public:
    static int getCount() {
        return count;
    }

    Bear(string species, string name, string uid, string sex, string color, 
        string origin, string birthDate, int age, int weight) : 
        Animal(species, name, uid, sex, color, origin, birthDate, age, weight) 
    {
        count++;
    }
};

class HeadNode
{
private:
    string speciesName;

    // List Pointers
    Animal* head = nullptr;
    Animal* tail = nullptr;

public:
    Animal* addAnimal(HeadNode& list, Species c, string species, string name, string uid,
        string sex, string color, string origin, string birthDate, int age, int weight)
        {
        Animal* newAnimal;
        switch( c ) 
        {
            case HYENA:
                newAnimal = new Hyena(species, name, uid, sex, color, origin, birthDate, age, weight);
                break;
            case LION:
                newAnimal = new Lion(species, name, uid, sex, color, origin, birthDate, age, weight);
                break;
            case TIGER:
                newAnimal = new Tiger(species, name, uid, sex, color, origin, birthDate, age, weight);
                break;
            case BEAR:
                newAnimal = new Bear(species, name, uid, sex, color, origin, birthDate, age, weight);
                break;
            default:
                // ----- HANDLE DEFAULT CASE PLEASE -----
                break;
        }

        if (list.tail == nullptr)
        {
            list.tail = newAnimal;
            list.head = list.tail;
        } else {
            list.tail -> next = newAnimal;
            list.tail -> next -> previous = list.tail;
            list.tail = list.tail -> next;
        }

        return list.tail;
    }

    string getSpeciesName() {
        return speciesName;
    }

    vector<string> getAnimals()
    {   
        vector<string> animals;
        Animal* currentAnimal = head;
        string text;
        while (currentAnimal != nullptr)
        {
            text = currentAnimal -> _name + " - ";
            text += "UID: " + currentAnimal -> _uid + " - ";
            text += "Sex: " + currentAnimal -> _sex + " - ";
            text += "Color: " + currentAnimal -> _color + " - ";
            text += "Origin: " + currentAnimal -> _origin + " - ";
            text += "Birth Date: " + currentAnimal -> _birthDate + " - ";
            text += "Age: " + std::to_string(currentAnimal -> _age) + " years - ";
            text += "Weight: " + std::to_string(currentAnimal -> _weight) + " pounds";

            animals.emplace_back(text);
            currentAnimal = currentAnimal -> next;
        }
        return animals;
    }

    HeadNode(string speciesName) : speciesName(speciesName) {}
};

// ----- FUNCTIONS -----
string removeControlCharacters(string input)
{
    for (char i : input) 
    {
        if (std::iscntrl(i) != 0) {
            input.erase(input.find(i));        
        }
    }
    return input;
}

vector<string> splitString(string input, string delimiter = ", ")
{
    std::vector<string> result;
    size_t pos = 0;
    std::string token;

    while ((pos = input.find(delimiter)) != std::string::npos) 
    {
        token = input.substr(0, pos);
        // std::cout << token << std::endl;
        input.erase(0, pos + delimiter.length());
        result.emplace_back(token);
    }

    token = input.substr(0, pos);
    result.emplace_back(token);

    return result;
}

// For Some Reason this is indexed at 1 and not at 0.
// When I try to fix it causes out of range errors
string nthWord(string line, int n)
{
    string result;
    std::istringstream stream (line);
    for (int i = 0; i < n; i++) 
    {
        stream >> result;
    }
    return result;
}

// ----- MAIN ----- 
int main()
{
    // List of lists
    HeadNode speciesLists[4] = {HeadNode("hyena"), HeadNode("lion"), HeadNode("tiger"), HeadNode("bear")};

    // Map Enums to Species Strings
    std::map<string, Species> enumMap;
    enumMap.insert(std::pair<string, Species>("hyena", HYENA));
    enumMap.insert(std::pair<string, Species>("lion", LION));
    enumMap.insert(std::pair<string, Species>("tiger", TIGER));
    enumMap.insert(std::pair<string, Species>("bear", BEAR));


    // Open animalNames.txt ifstream in input mode
    std::ifstream animalNames{ANIMALNAMES, std::ifstream::in};
    if (!animalNames) 
    {
        std::cerr << "Oepsie Woepsie! Animal Names could not be opened!" << std::endl;
        return 1;
    } else {
        std::cout << "Animal Names opened successfully." << std::endl;
    }
    

    // Open arrivingAnimals.txt ifstream in input mode
    std::ifstream arrivingAnimals{ARRIVINGANIMALS, std::ifstream::in};
    if (!arrivingAnimals) 
    {
        std::cerr << "Oepsie Woepsie! Incoming Animals could not be opened!" << std::endl;
        return 1;
    } else {
        std::cout << "Incoming Animals opened successfully." << std::endl;
    }


    // --- Parse Animal Names ---
    int namesLineNum = 0;
    vector<string> hyenaNames, lionNames, tigerNames, bearNames;
    for (string line; getline(animalNames, line);) 
    {
        // Remove Control Characters
        line = removeControlCharacters(line);

        switch (namesLineNum)
        {
            case 2:
                hyenaNames = splitString(line);
                break;
            case 6:
                lionNames = splitString(line);
                break;
            case 10:
                bearNames = splitString(line);
                break;
            case 14:
                tigerNames = splitString(line);
                break;
            default:
                // ----- HANDLE DEFAULT CASE PLEASE -----
                break;
        }
        namesLineNum++;
    }


    // --- Parse Arriving Animals
    for (string line; getline(arrivingAnimals, line);) 
    {
        // Remove Control Characters
        line = removeControlCharacters(line);

        vector<string> tokens = splitString(line);
        // --- Print vector of tokens (not necessary) ---
        for (auto i : tokens)
            std::cout << i << "; ";
        std::cout << "\n";
        

        // Find Species
        string species = nthWord(tokens[0], 5);
        // std::cout << "Species: " << species << "\n";

        // Choose Correct List
        int currentList = 0;
        while (speciesLists[currentList].getSpeciesName() != species) {
            currentList++;
        }

        Species c = enumMap.at(species);

        // Generate Name
        string name;
        switch ( c )
        {
            case HYENA:
                name = hyenaNames.back();
                hyenaNames.pop_back();
                break;
            case LION:
                name = lionNames.back();
                lionNames.pop_back();
                break;
            case TIGER:
                name = tigerNames.back();
                tigerNames.pop_back();
                break;
            case BEAR:
                name = bearNames.back();
                bearNames.pop_back();
                break;
            default:
                // ----- HANDLE DEFAULT CASE PLEASE -----
                break;
        }
        // std::cout << "Name: " << name << "\n";

        // Generate UID
        string uid = species.substr(0, 2);
        for (auto& i : uid) i = toupper(i);

        switch( c ) 
        {
            case HYENA:
                uid += std::to_string(Hyena::getCount());
                break;
            case LION:
                uid += std::to_string(Lion::getCount());
                break;
            case TIGER:
                uid += std::to_string(Tiger::getCount());
                break;
            case BEAR:
                uid += std::to_string(Bear::getCount());
                break;
            default:
                // ----- HANDLE DEFAULT CASE PLEASE -----
                break;
        }
        if (uid.length() < 4) {
            uid.insert(2, "0");
        }
        // std::cout << "UID: " << uid << "\n";

        // Find Sex
        string sex = nthWord(tokens[0], 4);
        // std::cout << "Sex: " << sex << "\n";

        // Find Color
        string color = tokens[2].substr(0, tokens[2].find("color") - 1);
        // std::cout << "Color: " << color << "\n";

        // Find Origin
        string origin = tokens[4].substr(5) + ", " + tokens[5];
        // std::cout << "Origin: " << origin << "\n";

        // ----- GENERATE BIRTH DATE HERE --------------------------------------
        string birthDate = "";

        // Find Age
        int age = std::stoi(nthWord(tokens[0], 1));
        // std::cout << "Age: " << age << "\n";

        // Find Weight
        int weight = std::stoi(nthWord(tokens[3], 1));
        // std::cout << "Weight: " << weight << "\n";

        // Instantiate Animal
        speciesLists[currentList].addAnimal(speciesLists[currentList], c, species, name, uid,
            sex, color, origin, birthDate, age, weight);

    }

    // Ofstream to write to txt
    std::ofstream out(OUTPUT);

    for (HeadNode i : speciesLists)
    {
        out << i.getSpeciesName() << "s:\n";
        for (string j : i.getAnimals())
        {
            // std::cout << j << "\n";
            out << j << "\n";
        }
    }

    return 0;
}
