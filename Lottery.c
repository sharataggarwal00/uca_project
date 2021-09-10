#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Lottery
{
    int value;
    struct Lottery *previous;
    struct Lottery *next;
};

// Function to check whether or not the value entered is valid
// input: value in form of character
// output: if check is passed, it returns 1, else 0
int int_check(char check[])
{
    int length, i, num, count = 0;
    int flag;

    length = strlen (check);				// Assigns the string length to x

    for (i=0 ; i<length ; i++)				// To check if every character is a digit
    {
	if (! (check[i] >= 48 && check[i] <= 57))	// Checking with ASCII values of digits 0-9
        {
            count++;               
        }
    }

    if (count > 0)					// If count greater or equal to 1, then it means there was a non-digit
    {
	flag = 0;
    }
    else
    {
	num = atoi (check);				// If all charaters passed, then the array is converted to an integer

	if (num > 40)					// To determine if the value is between 1-40
        {
	    flag = 0;
	}
	else
	{
	    if (num <= 40 && num > 0)
	    {
		flag = 1;
	    }
	    else
	    {
		flag = 0;
	    }
	}
    }

    return flag;					// Returns either 1 or 0 for true or false
}

// Function to create a circular doubly linked list with 40 nodes numbered 1 to 40
// input: NA because it is creating
// output: linked list is returned and assigned to a pointer in main
// BUILDING A LINKED LIST.
struct Lottery *get_list()
{
    int i;
    struct Lottery *head, *current, *temp;

    head = malloc (sizeof (struct Lottery));			// A node is created at the 'head'
    current = head;						// 'head' is assigned to 'current'
    temp = head;						// 'head' is assigned to 'temp'

    for (i=1 ; i<=40 ; i++)					// creating the rest of the nodes
    {
	current->value = i;
	current->next = malloc (sizeof (struct Lottery));
	current = current->next;				// which is empty right now
	current->previous = temp;
	temp = current;
    }

    current->next = head;					//finishes the circular doubly linked list
    head->previous = current;

    return head;
}

// Function to traverse the list a specific amount of times
// input: start pointer of the linked list
// output: returns the pointer of the traversed node
// TRAVERSE THE LIST
struct Lottery *traverse(struct Lottery *start)
{
    int random_num, i;
    struct Lottery *current, *temp;

    srand (time (NULL));			// To set the seed according to the time lapsed from 00:00:00 UTC, January 1, 1970 (Unix timestamp) in seconds
    random_num = rand() % 40 + 1;		// to create a random number for the number of times to traverse the list

    if ((random_num % 2) == 0)			// if the random number obtained is even, the function traverses forward
    {
	for (i = 0 ; i < random_num ; i++)
	{
	    start = start->next;
	}

	temp = start->previous;
	current = start->next;
    }
    else
    {
	for (i = 0 ; i < random_num ; i++)	// if the random number obtained is odd, the function traverses backwards
	{
	    start = start->previous;
	}

	temp = start->previous;
	current = start->next;
    }

    return start;				// returns the node which was traversed to
}

// Function to return the value of the node
int return_value(struct Lottery *start)
{
	int x;
	x = start->value;

	return x;
}

//Function to delete the current node
//input: the pointer of the node with the selected value is passed.
//output: the pointer to the previous node is returned with the list
struct Lottery *delete_node(struct Lottery *start)
{
	struct Lottery *temp, *current;

	current = start->next;				//Once the node has been used once, it is deleted from the linked list.
	temp = start->previous;
	temp->next = current;
	current->previous = temp;
	free (start);
	start = current;

	return start;					//The new list is returned.
}

int main()
{
    struct Lottery *start;
    int num1, num2, num3, num4, num5, num6;		// variables for user entered values
    char check[10];					//temporary character array to check if it is valid
    int x, i, count_right = 0, int_array[6];

    start = get_list();					// head returned by get_list assigned to start

    printf ("\nHello, and welcome to the L-O-T-T-E-R-Y Game. You will be asked to enter 6 different");
    printf ("\nnumbers between the range of 1-40. Remember, each number can only be picked once.");
    printf ("\nGOOD LUCK!!");

    //----------------------FIRST NUMBER----------------------------------------------
    
    printf ("\n\nPlease enter your first number between 1-40:   ");
    scanf ("%s", check);

    if (int_check (check) == 0)
    {
	do
	{
	    printf ("\nYour number was INVALID, enter a number between 1-40:   ");
	    scanf ("%s", check);
	}while (int_check (check) == 0);
    }

    num1 = atoi (check);

    //----------------------SECOND NUMBER---------------------------------------------
    
    printf ("\n\nPlease enter your second number between 1-40:   ");
    scanf ("%s", check);

    if (int_check (check) == 0)
    {
        do
        {
            printf ("\nYour number was INVALID, enter a number between 1-40:   ");
            scanf ("%s", check);
        } while (int_check (check) == 0);
    }

    num2 = atoi (check);

    // To make sure a number is not repeated
    while (num2 == num1)
    {
        do
	{
	    printf ("\nYou already entered this number. Enter another number between 1-40:   ");
	    scanf ("%s", check);
        } while (int_check (check) == 0);

	num2 = atoi (check);
    }

    //----------------------THIRD NUMBER---------------------------------------------

    printf ("\n\nPlease enter your third number between 1-40:   ");
    scanf ("%s", check);

    if (int_check (check) == 0)
    {
        do
        {
            printf ("\nYour number was INVALID, enter a number between 1-40:   ");
            scanf ("%s", check);
        } while (int_check (check) == 0);
    }

    num3 = atoi (check);

    // To make sure a number is not repeated
    while (num3 == num1 || num3 == num2)
    {
        do
        {
            printf ("\nYou already entered this number. Enter another number between 1-40:   ");
            scanf ("%s", check);
        } while (int_check (check) == 0);

        num3 = atoi (check);
    }

    //----------------------FOURTH NUMBER---------------------------------------------

    printf ("\n\nPlease enter your fourth number between 1-40:   ");
    scanf ("%s", check);

    if (int_check (check) == 0)
    {
        do
        {
            printf ("\nYour number was INVALID, enter a number between 1-40:   ");
            scanf ("%s", check);
        } while (int_check (check) == 0);
    }

    num4 = atoi (check);

    // To make sure a number is not repeated
    while (num4 == num1 || num4 == num2 || num4 == num3)
    {
        do
        {
            printf ("\nYou already entered this number. Enter another number between 1-40:   ");
            scanf ("%s", check);
        } while (int_check (check) == 0);

        num4 = atoi (check);
    }

    //----------------------FIFTH NUMBER---------------------------------------------

    printf ("\n\nPlease enter your fifth number between 1-40:   ");
    scanf ("%s", check);

    if (int_check (check) == 0)
    {
        do
        {
            printf ("\nYour number was INVALID, enter a number between 1-40:   ");
            scanf ("%s", check);
        } while (int_check (check) == 0);
    }

    num5 = atoi (check);

    // To make sure a number is not repeated
    while (num5 == num1 || num5 == num2 || num5 == num3 || num5 == num4)
    {
        do
        {
            printf ("\nYou already entered this number. Enter another number between 1-40:   ");
            scanf ("%s", check);
        } while (int_check (check) == 0);

        num5 = atoi (check);
    }

    //----------------------SIXTH NUMBER---------------------------------------------

    printf ("\n\nPlease enter your sixth number between 1-40:   ");
    scanf ("%s", check);

    if (int_check (check) == 0)
    {
        do
        {
            printf ("\nYour number was INVALID, enter a number between 1-40:   ");
            scanf ("%s", check);
        } while (int_check (check) == 0);
    }

    num6 = atoi (check);

    // To make sure a number is not repeated
    while (num6 == num1 || num6 == num2 || num6 == num3 || num6 == num4 || num6 == num5)
    {
        do
        {
            printf ("\nYou already entered this number. Enter another number between 1-40:   ");
            scanf ("%s", check);
        } while (int_check (check) == 0);

        num6 = atoi (check);
    }

    //---------------------CHECKING AND TRAVERSING------------------------------------

    for (i = 0 ; i < 6 ; i++)								// To pick 6 numbers
    {
	start = traverse (start);							// The node returned by traverse() is assigned to start

	x = return_value (start);							// storing the value of the node returned by traverse()

	int_array[i] = x;								

	// If the value of the selected node is equal to the value entered, then 1 is added to count_right
	if (x == num1 || x == num2 || x == num3 || x == num4 || x == num5 || x == num6)
	{
	    count_right++;
	}

	start = delete_node (start);
    }

    printf("\nYour numbers were:       %d  %d  %d  %d  %d  %d", num1, num2, num3, num4, num5, num6);
    printf("\nThe numbers drawn were:  %d  %d  %d  %d  %d  %d", int_array[0], int_array[1], int_array[2], int_array[3], int_array[4], int_array[5]);

    // To determine how many numbers were matched.

    if(count_right==6)
	printf("\n\n'CONGRATULATIONS! You matched all 6 numbers. You've won $100 million.'");		
    
    if(count_right==5)
	printf("\n\n'You matched 5 numbers. You missed the jackpot by one. You've won $100,000.'");
    
    if(count_right==4)
	printf("\n\n'You matched 4 numbers. You've won $20,000.'");
    
    if(count_right==3)
	printf("\n\n'You matched 3 numbers. You've won $250.'");
    
    if(count_right==2)
	printf("\n\n'You matched 2 numbers. You've won $15.'");
    
    if(count_right==1)
	printf("\n\n'You only matched 1 number. You get your money back.'");
    
    if(count_right==0)
	printf("\n\n'You matched 0 numbers.' ---Better luck next time---");

    return 0;
}













