# Monster-Fight
A text-based RPG game project

Follows a strict OO programming style



## Basic Game Play:
In this program, you will control a hero character. Your hero character will fight a series of monsters. By beating a monster you will earn extra stats and prize money. Eventually you will fight the grand boss monster. Beat the all the monsters and boss without dying and you will become the grand champion! The play will go as follows:
• You are the hero. You have a name (user defined), health (can be between 0 and 50, starts at 20), attack (starts at 3, max is 10), defence (starts at 3, max is 10), and special attack (starts at 2, max is 10). The hero also has an amount of prize money (starts at 0 and has no upper limit).
• In the game there are 5 monsters waiting to fight. They will fight in order. There are 4 regular monsters and finally one boss monster.
• The regular monsters have a name, health (can be between 0 and 100), attack (can be between 0 and 10), and defence (can be between 0 and 10). They do not have a special attack attribute.
• The boss monster has the same attributes as the regular monster but also has a special attack (can be between 0 and 10)
• You will then fight the monsters in order. The fighting process is described separately below.
• When you win a fight, you earn 20 health points, and a random amount of attack, defence, and special points. For each of these you could earn 0, 1 or 2 points. For example after one successful monster battle you might earn 1 attack, 1 defence and 2 special. You also earn prize money, which is how much health you have left at the end of a battle (before adding the 20 health points for winning). This means you earn more prize money if you get less
damage during the fight.
• If at any stage your health goes to 0 the game is over and the monsters win.
• If you defeat all monsters and the boss then you win and the game is over.

## Monster Stats:
Below are the stats for each monster (health, attack, defence and special for the boss):
• Monster 1: 10 health, 1 attack, 1 defence
• Monster 2: 20 health, 3 attack, 2 defence
• Monster 3: 30 health, 5 attack, 4 defence
• Monster 4: 40 health, 6 attack, 7 defence
• Boss: 50 health, 8 attack, 8 defence, 5 special

## Battle:
When you battle a monster, the logic is as follows:
1. The hero generates a random number between 1 and 6. It is added to the skill level.
2. Another random number 1-6 is generated for the monster and added to its defence level.
3. If the player’s attack total is higher than the monsters defence total, the monster loses the
difference between the two values in health. If the monsters total is equal or higher, no
health is lost.
4. Steps 1 to 3 then occur except with the Monster attacking and Hero defending.
5. Steps 1 to 4 keep continuing until either the player or monster runs out of health.
For example, here is a case with the Hero attacking and Monster defending:
• Hero generates a random number 1 to 6 and adds it to attack. For example, they get a 4 and add it to their attack, which is 3, giving them a total of 7.
• Monster generates a random number 1 to 6 and adds it to defence. For example, they get a 3 and add it to their defence, which is 1, giving them a total of 4.
• As the hero’s score is higher they win the round. They then take 7 – 4 = 3 points off the health of the monster.


## Special Attack:
• The hero may launch a special attack once per monster fight.
• If the player chooses to do a special attack, they can add their special attack value to their
overall attack score, giving them an advantage.
• The player must choose before the attack section of each fight if they wish to do a special
attack. They can then not choose to do it again for the rest of a monster fight.

## Extras
1. Boss Battle allows hero call pet to fight one boss. Boss attack one of the heroes randomly while hero and pet can attack boss togther. Pet class inherit Monster class.

2. For pet, they are different from hero. They can attack monster with ignoring monsters' defence but there is a probability they cannot hit the target. They defend the same way as hero.

3. I add the race type for hero, which use enum class. User can select race type through display list.
There are 5 types of hero. They are human, elf, orcish, dwraf and kamael.
Different race type has different attributes for health, attack, defence and special-attack.
Races are balance in attributes to keep the game equal.

4. Save and Load game.
With a menu, if user want to save game, it saves all data of hero and pet to "saves.txt" file.
if user want to load game from the beginning of the game, it loads all data of hero and pet to "saves.txt" file.
