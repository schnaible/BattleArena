#include <iostream>
#include <string>
#include <random>

 int main(){

     std::string name = "", choice = "";
     int hp = 0, mp = 0, maxHp = 0, maxMp = 0,
      healAmount = 0, killCount = 0, damageTaken = 0,
      level = 0;

     //Random Number Generator
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> dealDamage(0, 3); // define the range
    std::uniform_int_distribution<> restoreHp(3, 6); // define the range

    std::cout << "Welcome to Battle Arena!!!" << std::endl;
    std::cout << "Please enter your gladiator's name: ";
    std::cin >> name;
    std::cout << "Please select your class:" << std::endl;
    std::cout << "1: Warrior (10hp, 3mp) 2: Mage (7hp, 5mp)" << std::endl;
    std::cout << " >>";
    std::cin >> choice;
    if (choice == "1"){
        hp = 10;
        maxHp = 10;
        mp = 3;
        maxMp = 3;
    }
    else if (choice == "2"){
        hp = 7;
        maxHp = 7;
        mp = 5;
        maxMp = 5;
    }
    else if (choice == "9"){
        std::cout << "You found the secret BattleMage class! (20hp, 20mp)" << std::endl;
        hp = 20;
        mp = 20;
    }
    else {
        std::cout << "how pitiful... (2hp,0mp)" << std::endl;
        hp = 2;
        mp = 0;
    }

    std::cout << std::endl;

     while (hp > 0){
        choice = "";

        if (killCount % 5 == 0){
            level+=1;
            std::cout << "~~~ LEVEL " << std::to_string(level) << " ~~~" << std::endl;
        }

        std::cout << name << "'s HP: " << std::to_string(hp) <<  " MP: " << std::to_string(mp) << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1: Attack 2: Cure (1MP) 3: Flee" << std::endl;
        std::cout << " >>";
        std::cin >> choice;
        
        if (choice == "1"){
            //Kill the enemy, take a random amount of damage
            std::cout << "You swing your weapon, killing the enemy." << std::endl;
            damageTaken = dealDamage(gen);
            hp = hp - damageTaken;
            std::cout << "Damage Taken: " << std::to_string(damageTaken) << std::endl;
            if (hp > 0)
                killCount+=1;
        }
        else if (choice == "2"){
            //Heal yourself a random amount
            if (mp > 0){
                mp -= 1;
                healAmount = restoreHp(gen);
                if (hp+healAmount > maxHp){
                    healAmount = maxHp-hp;
                }
                hp = hp + healAmount;
                std::cout << "You healed yourself for " << std::to_string(healAmount) << "HP." << std::endl;
            }
            else{
                std::cout << "You failed to cast the spell!" << std::endl;
            }
            damageTaken = dealDamage(gen);
            hp = hp - damageTaken;
            std::cout << "Damage Taken: " << std::to_string(damageTaken) << std::endl;

        }
        else if (choice == "3"){
            //Take a random amount of damage
            std::cout << "You're trapped in the arena!" << std::endl;
            damageTaken = dealDamage(gen);
            hp = hp - damageTaken;
            std::cout << "Damage Taken: " << std::to_string(damageTaken) << std::endl;
        }
        else {
            std::cout << "Please enter a valid command" << std::endl;
        }
        std::cout << std::endl;

     }

    std::cout << name << " has died with " << std::to_string(killCount) << " kills." << std::endl;

     return 0;
 }