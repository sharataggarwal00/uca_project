# L-O-T-T-E-R-Y - The Game

Ramesh is a college student persuing computer science and only has knowledge of programming in C language. In his summer holidays, he decides to use his skills and make some extra pocket money by setting up a shop in nearby fair (mela). 
The rules of the game are as follows :-
- the player will enter 6 numbers between 1-40.
- the system chooses 6 numbers of its own between 1-40.
- more the numbers of matches between the two sets of numbers, bigger the prize

## WORKING
>The program uses circular doubly linked list to store numbers 1-40 in increasing order.
>A number is drawn randomly, say 'n' and the list is traversed till n'th node and the number stored in that node is returned.
>This is done 6 times to draw 6 different numbers.
>Then the drawn set of numbers is compared to the user entered numbers and the number of matches occured are counted and prize dislpayed accordingly.

### SPECIAL FEATURES
- For selecting numbers randomly, **rand() function**.
- But for each run, it produces the **same result**, because it uses a mathematical algorithm that calculates these numbers based on a *starting value called **'seed'***.
- So, the program uses **srand(time(NULL))** function makes use of the computer's internal clock to control the choice of the seed. Since time is continually changing, the seed is forever changing.
- Therefore, for each run, **time() function provides a new seed** and thus, each times we get different result, *making the game fair*.

### GOALS
- The goal is to prepare a simple program to implement the concepts learned during the course
- A program easy to use and doesnt use much space or time

