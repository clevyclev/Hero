//
//  main.cpp
//  Hero Finale
//
//  Created by Clevis Necol Valentin Willrich on 3/11/17.
//  Copyright © 2017 Clevis Necol Valentin Willrich. All rights reserved.
//

//This code is largely an expanded version of my code from the Hero Caretaker program, with added functionality for an inventory.  Comments are included where edits and additions have been made.

#include <iostream>
#include <vector>

using namespace std;

//This is where I added in the necessary variables for the inventory function.
int numItems = 0;
int& currentStock = numItems;
const int MAX_ITEMS = 10;
string inventory[MAX_ITEMS];
string heroes[10];

class Hero
{
public:
    Hero(string name = "Bob", int health = 1, int morale = 1);
    void Tell_Story();
    void Tell_Vitality();
    void Eat(int food = 4);
    void Train(int toughness = 4);
    
    //The following two methods are necessary for displaying the inventory size and contents.
    void Show_Stock();
    void Show_Inventory();
    
    void Roll_Call(){
        cout << "The current heroes are as follows!\n";
        for (auto const& c : Heroes)
            std::cout << c << ' ';
    };
    vector<string> Heroes;
    
private:
    int m_Health;
    int m_Morale;
    string m_Name;
    
    string story = " wakes up alone in a barren field to the whispers of the sagebrush.\nHe knows nothing of his circumstances…where he came from, how he got here, but most importantly, WHO brought him here.\nUpon analysis of his situation…his tattered clothing and his aches and pains all over…he can tell one thing: he’s been beaten, and left for dead.\n\nHad he pissed someone off?  Did he owe someone something?\n\nWhat had they done to him…and why couldn’t he remember anything?\nUnable to navigate his mind through the throbbing head pain, he musters the strength to stand with the help of a nearby wooden plank.\nOff in the distance, he sees a small cottage.  Maybe someone is there?  Someone who could help?\nHe begins to limp off yonder, wondering what in the hell is going on.\nUpon arrival, he finds nobody, and in a moment of staggering pain collapses, knocking over a chest of drawers containing a set of newer clothes…and a note.\n\nHe reads the note…and makes a shocking discovery that immediately sets him on a quest for the truth…and revenge.'\n\n";
    
    int GetVitality() const;
    void PassTime(int time = 1);
    
};

Hero::Hero(string name, int health, int morale):
m_Health(health),
m_Morale(morale),
m_Name(name)
{
    Tell_Story();
    Tell_Vitality();
    Show_Stock();
    Show_Inventory();
    Heroes.push_back(m_Name);
}

inline int Hero::GetVitality() const
{
    return (m_Health + m_Morale);
}

void Hero::PassTime(int time)
{
    m_Health -= time;
    m_Morale -= time;
}

void Hero::Tell_Story()
{
    cout << "\n'" << m_Name << story;
    cout << "My name is " << m_Name <<".\n";
    cout << "I'm a hero and I feel ";
    
    int mood = GetVitality();
    if (mood > 15)
    {
        cout << "energized.\n";
    }
    else if (mood > 10)
    {
        cout << "capable.\n";
    }
    else if (mood > 5)
    {
        cout << "in pain.\n";
    }
    else
    {
        cout << "like I'm dying.\n";
    }
    
    PassTime();
}

void Hero::Tell_Vitality()
{
    cout << "My vitality is ";
    cout << GetVitality();
    cout <<".\n";
}

void Hero::Eat(int food)
{
    cout << "Burrppp.\n";
    
    m_Health += food;
    
    PassTime();
}

void Hero::Train(int toughness)
{
    cout << "Hiyah!\n";
    
    m_Morale += toughness;
    
    PassTime();
}

//The two methods mentioned above are defined next.
void Hero::Show_Stock(){
    cout << "\nYou have " << currentStock << " items!\n";
}

void Hero::Show_Inventory()
{
    cout << "\nYour items:\n";
    for (int i = 0; i < numItems; ++i)
    {
        cout << inventory[i] << endl;
    }
    
}


int main()
{
    //Here is where the inventory is populated.
    inventory[numItems++] = "steel-toe boots";
    inventory[numItems++] = "leather pants";
    inventory[numItems++] = "denim jacket";
    inventory[numItems++] = "dallas hat";
    inventory[numItems++] = "leather gloves";
    inventory[numItems++] = "alloyed rod";
    
    Hero Jack("Jack", 10, 10);
    Hero Bronson("Bronson", 15, 12);
    Hero Vincenzo("Vincenzo", 8, 7);
    
    Hero* pHero;
    
    int hero;
    int choice;
    do
    {
        cout << "\nHero Caretaker\n\n";
        cout << "Choose a hero for this game by entering his corresponding number.\n\n" << "1 - Jack\n" << "2 - Bronson\n" << "3 - Vincenzo\n\n";
        cin >> hero;
        while (hero < 1 || hero > 3 || cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "You must choose from the available options!  No letters, either!\nTry again!\n" << "Choose a hero for this game by entering his corresponding number.\n\n" << "1 - Jack\n" << "2 - Bronson\n" << "3 - Vincenzo\n\n";
            cin >> hero;
        }
        
        
        switch (hero)
        {
            case 1:
                pHero = &Jack;
                pHero->Tell_Story();
                break;
                
            case 2:
                pHero = &Bronson;
                pHero->Tell_Story();
                break;
                
            case 3:
                pHero = &Vincenzo;
                pHero->Tell_Story();
                break;
                
            default:
                cout << "\nSorry, but " << hero << " isn't a valid choice.\n";
        }
        
        cout << "Choose an action for this hero!\n\n";
        
        cout << "0 - Quit\n";
        cout << "1 - Listen to your hero\n";
        cout << "2 - Feed your hero\n";
        cout << "3 - Train your hero\n";
        cout << "4 - Call the roll\n";
        
        //I have added a 5th choice of action for the player, which will display the inventory count and contents.
        cout << "5 - Show the inventory\n\n";
        
        cout << "Choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 0:
                cout << "Good-bye.\n";
                break;
            case 1:
                pHero->Tell_Story();
                break;
            case 2:
                pHero->Eat();
                break;
            case 3:
                pHero->Train();
                break;
            case 4:
                pHero->Roll_Call();
                break;
                
            //Case 5 is the 5th choice described above.
            case 5:
                pHero->Show_Stock();
                pHero->Show_Inventory();
                break;
            default:
                cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
    } while (choice != 0);
    
    return 0;
}









