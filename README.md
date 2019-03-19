# PSU_navy_2018 ![Travis Status](https://travis-ci.com/ColColty/PSU_navy_2018.svg?branch=master)

This Epitech project for the 1st year, consist in recreate the well known game of Battleship.

![Image of the Battleship game](https://static1.squarespace.com/static/57d4c42a1b631b0de889dfde/t/58f830f9ebbd1a0ecd27e223/1492660531809/?format=500w)

## The project

The project is based in a unique binary who can be run on two different terminals and represent the two players.

This project need two files that contain the boats positions composed in the following way:

     ----------- ------------------ ----------------
    | Boat size | Initial position | Final position |
               2:<Initial position>:<Final position>
               3:<Initial position>:<Final position>
               4:<Initial position>:<Final position>
               5:<Initial position>:<Final position>

    Example:
        2:C4:D4
        3:H1:H3
        4:E2:H6
        5:B1:F1

The file can't contain more than 4 boats and the positions need to match the size of the boats.
The sizes can't be different from the writed on the board.


### Execute the game

You need to open two terminals, one for the player 1 and the other one for the player 2.

**In the first terminal, so for the player one:**

You need to enter the following command:
```./navy [file with positions p1]```
The [file with positions p1] need to be replaced by the file we create before with the boats positions.

*For this example we will use pos1 for player 1 and pos2 for player 2.*

When the player 1 program start there was a line with:
```my_pid: <number>```
We need to remember this number for the player 2.

**Now for the player 2**

The command for player 2 is:
```./navy <pid of player 1> [file with positions p2]```
The pid of the player 1 refers to the number I told you to remember when the player 1 program start running.
And for the [file with positions p2], as for the player 1, it refers to the file where we enter the boat positions.
|
|
|
Now lets see how to play to the game.
First we see there is a first board with our boats and on the bottom we can see another board where the plays will appear simulating the board of the ennemy.

The player 1 will always start, so the player need to enter a position in the format of: ```<letter><number>``` for example: ```A4```

When the player will press ```Enter``` the position will be sent and recieve if he hit or missed a boat.

Next the player 2 will attack.

Once the two players has played the boards will be displayed a second time with the inputs printed in.
|Action|Printed|
|-----|:--:|
| hit | x |
| missed | o |

**A player win when he hit all the boats of the other player**

## Technical part

For this project we do CI with Travis CI.
We also do some unit tests using criterion, to know test our functions and have a well working game.
Finally, thanks to a script we do some basic functional tests that run script and test the error_handling.

## Contributors

- PaulTarGiest - [GitHub](https://github.com/PaulTarGeist) -
- ColColty - [GitHub](https://github.com/ColColty) -