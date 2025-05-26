/*
Description: <  This program is a game called GILGAMESH'S MEGA GIL ADVENTURES, in which he must pay back his debt to retrieve 
				his Genji Equipment. He has 30 days to pay his debts by traveling to different worlds and buying and selling 
				items from shops. The program allows the user to buy and sell items and complete the quest, or else the user
				will inevitably lose the game, and Gilgamesh will not get his Genji Equipment back. >
				
NAME:	LIGNES, CYMBELINE ANNE B.
BLOCK:  S15B
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>//for background music
#include <MMsystem.h>//for background music

// This function displays the welcome message at the start of the program.
void displayWelcome()
{
    printf("\n\t\t===============================\n");
    printf("\n\t\t\t  WELCOME TO\n");
    printf("\n\t\tGILGAMESH'S MEGA GIL ADVENTURES\n\n");
    printf("\n\t\t===============================\n");
}

// This function ask the user its name and  after that, the function will display the players mission in the game.
void displayName()
{
    char name[10];

    printf("\n\t\tEnter your name: ");
    scanf("%s", name);
    printf("\n\t\tHello %s! Let's begin our travel!\n", name);
    printf("\n\t\t GOAL: You must help Gilgamesh\n\t\t get back his Genji equipment\n\t\t\twithin 30 days!\n");
    printf("\n\t\t   Press any key to continue.\n\n");
}

/* This function generates the random prices for each items that are going to be bought or sold.
   @param: min is the minimum price of each items.
   @param: max is the maximum price of each items.
   @param: special identifies if the item is special item or not.
   @return price if random is greater than 30 or less than 30 and special is 1, else it returns 0. */
int randomPrice(int min, int max, int special)
{
	int price, random;	

    price = (rand() % (max - min + 1) + min);
	random = (rand() % (100 - 1 + 1) + 1);

    if (random > 30)//random is not within 30%, so "sold out" will not be displayed in the next function
        return price;
	else if (random < 30 && special == 1)//random within 30% but it's not special item, so "sold out" will not be displayed in the next function.
	    return price;
	else//random is within 30% and price is equal to 0, "sold out" will be displayed in the next function
		return 0;
}

/* This function determines if the pointer parameter price is 0 or not. It will display "Sold Out"
   if it is 0 and if not it will display the price of the item.
   @param: *price is the pointer parameter that contains the price of each item. */
void soldOut(int *price)
{
	if (*price == 0)
	    printf("Sold Out");
	else
	    printf("%dG\t", *price);
}

/* This function displays the Main Rift and ask the user which shop to travel.
   @param: day is the number of day.
   @param: gil contains the value of how much money the user has.
   @param: debt contains the value of how much the user must pay.
   @param: *choice is the pointer parameter that stores the user's choice.
   @return the users choice. */
int mainRift(int day, int gil, int debt, int *choice)
{
    printf("\nGilgamesh: Where should my travels take me to?\n");
    printf("\n\t[1] Tycoon Meteor's Minerals                                Day %d\n",day);
    printf("\t[2] Pulsian Restoratives                                    Gil: %d\n",gil);
    printf("\t[3] Archadian Luxuries                                      Debt: %d\n",debt);
    printf("\t[4] Cid's Magical Escapades\n");
    printf("\t[5] Gaian Gratitudes                                        [8] Quit\n");
    printf("\t[6] Riches and Minerals of Spira\n");
    printf("\t[7] Go see the Merchant of the Rift\n");
    printf("\nYour Choice: ");
    scanf("%d", choice);
    return *choice;
}

/* This function displays the list of items in the shop and asks the user if it wants to buy items, 
   sell items or leave the shop.
   @param: *option is the pointer parameter the stores stores the user's choice from buying, selling or leaving
   @param: day is the number of day.
   @param: gil contains the value of how much money the user has.
   @param: debt contains the value of how much the user must pay.
   @param: *PD, *EE, *PI, *GM, *scar, *adam, *DM and *trap are pointer parameters of each items that 
   			contains the value of its prices.
   @param: *pdHand, *eeHand, *piHand, *gmHand, *scarHand, *adamHand, *dmHand and *trapHand are pointer parameters 
   			of each items that contains the value of how many on Hand items thte user has.
   @return the users choice. */
int displayShop(char *option, int day, int gil, int debt, 
				int *PD, int *EE, int *PI, int *GM, int *scar, int *adam, int *DM, int *trap,
				int *pdHand, int *eeHand, int *piHand, int *gmHand, int *scarHand, int *adamHand, int *dmHand, int *trapHand)
{
	printf("\n\tItem\t\tOn hand\t\tPrice\n");
	printf("\n\tPhoenix Down\t   %d\t\t ",*pdHand); 
   	soldOut(PD); 
    printf("\t\tDay %d\n",day);
	printf("\tElixir Essence\t   %d\t\t ",*eeHand); 
    soldOut(EE); 
    printf("\t\tGil: %d\n",gil);
	printf("\tPlatinum Ingot\t   %d\t\t ",*piHand); 
    soldOut(PI);
    printf("\t\tDebt: %d\n",debt);
	printf("\tGolden Materia\t   %d\t\t ",*gmHand); 
    soldOut(GM);
	printf("\n\tScarletite\t   %d\t\t ",*scarHand); 
    soldOut(scar);
	printf("\n\tAdamantite\t   %d\t\t ",*adamHand); 
    soldOut(adam);
	printf("\n\tDark Matter\t   %d\t\t ",*dmHand); 
    soldOut(DM);
	printf("\n\tTrapezehedron\t   %d\t\t ",*trapHand); 
    soldOut(trap);

	printf("\n\n\t[B]uy\t[S]ell\t[L]eave\n");
	printf("\n\tOption: ");
	scanf(" %c", option);

	return *option;
}

/* This function displays the list of items from the shop that the user will choose from and it returns the chosen item.
   @param: *chosenItem is pointer parameter the contains the value of the user's chosesn item.
   @param: day is the number of day.
   @param: gil contains the value of how much money the user has.
   @param: debt contains the value of how much the user must pay.
   @param: *PD, *EE, *PI, *GM, *scar, *adam, *DM and *trap are pointer parameters of each items that 
   			contains the value of its prices.
   @param: *pdHand, *eeHand, *piHand, *gmHand, *scarHand, *adamHand, *dmHand and *trapHand are pointer parameters 
   			of each items that contains the value of how many on Hand items thte user has.
   @return the users chosen item among the 8 items. */
int displayBuySellShop(int *chosenItem, int day, int gil, int debt,
					   int *PD, int *EE, int *PI, int *GM, int *scar, int *adam, int *DM, int *trap,
					   int *pdHand, int *eeHand, int *piHand, int *gmHand, int *scarHand, int *adamHand, int *dmHand, int *trapHand)
{
    printf("\n\tItem\t\t\tOn hand\t\tPrice\n");
	printf("\n\t[1] Phoenix Down\t   %d\t\t ",*pdHand); 
    soldOut(PD); 
    printf("\t\tDay %d\n",day);
	printf("\t[2] Elixir Essence\t   %d\t\t ",*eeHand); 
    soldOut(EE); 
    printf("\t\tGil: %d\n",gil);
	printf("\t[3] Platinum Ingot\t   %d\t\t ",*piHand); 
    soldOut(PI);
    printf("\t\tDebt: %d\n",debt);
	printf("\t[4] Golden Materia\t   %d\t\t ",*gmHand); 
    soldOut(GM);
	printf("\n\t[5] Scarletite\t\t   %d\t\t ",*scarHand); 
    soldOut(scar);
	printf("\n\t[6] Adamantite\t\t   %d\t\t ",*adamHand); 
    soldOut(adam);
	printf("\n\t[7] Dark Matter\t\t   %d\t\t ",*dmHand); 
    soldOut(DM);
	printf("\n\t[8] Trapezehedron\t   %d\t\t ",*trapHand); 
    soldOut(trap);

	printf("\n\n\tOption: ");
	scanf(" %d", chosenItem);

	return *chosenItem;
}

/* This function displays the Merchant Rift of the game which where the user can 
   deposit or withdraw Gil, pay debt, ask for a loan, views saving or leave the
   Merchant Rift.
   @param: day is the number of day.
   @param: gil is a pointer parameter that contains the value of how much money the user has.
   @param: debt is a pointer parameter that contains the value of how much the user must pay.
   @param: *choice is a pointer parameter that stores the user's choice.
   @param: *wallet is a pointer parameter that contains the value or amount of the user's 
			deposited/withdrawn gil.
   @return the users choice. */
int merchantRift(int *gil, int *debt, int day, int *choice, int *wallet)
{
	printf("\nMerchant of the Rift: Are you ready to pay your debt?\n");
	printf("\n\t  [1] Deposit Gil\t\t\t\t\tDay %d\n", day);
	printf("\t  [2] Withdraw Gil\t\t\t\t\tGil: %d\n",*gil);
	printf("\t  [3] Pay off Debt\t\t\t\t\tDebt: %d\n",*debt);
	printf("\t  [4] Ask for additional loan\n");
	printf("\t  [5] View Savings\n");
	printf("\t  [6] Leave\n");

	printf("\n  Your Choice: ");
	scanf("%d", choice);
	
	return *choice;
}

/* This function computes for the gil when the user decides to sell an item.
   @param: gil contains the value of how much money the user has.
   @param: items is how many the user sold an item.
   @param: price is the price of an item.
   @return the new value of gil after selling an item. */
int gilAdded(int gil, int items, int price)
{
	gil = gil + (items * price);

	return gil;
}

/* This function computes the remaining gil when the user decides to buy an item.
   @param: gil contains the value of how much money the user has.
   @param: items is how many the user bought an item.
   @param: price is the price of an item.
   @return the new value of gil after buying an item. */
int gilRemaining(int gil, int items, int price)
{
	gil = gil - (items * price);

	return gil;
}

/* This function computes the debt when the user leaves the shop and the debt increases by 15%.
   @param: *debt is a pointer parameter the contains the value of debt.
   @return the new value of *debt after it was increased. */
int computeDebt(int *debt)
{
	int increase;
	increase = (*debt + (*debt * 0.15));
	*debt = increase;

	return *debt;
}

/* This function has the the conditional statements that will let the user to choose on what 
   item to buy and will perform the necesary actions when buying like updating the gil and item 
   on hand after buying.
   @param: *gil is a pointer parameter that contains the value of how much money the user has.
   @param: nQuantity is the user inputted integer that indicates how many he/she will buy.
   @param: nChoice is the user's choice if he/she will buy again or not.
   @param: nItem is the item that the user wants to buy.
   @param: *PD, *EE, *PI, *GM, *scar, *adam, *DM and *trap are pointer parameters of each items that 
   			contains the value of its prices.
   @param: *pdHand, *eeHand, *piHand, *gmHand, *scarHand, *adamHand, *dmHand and *trapHand are pointer parameters 
   			of each items that contains the value of how many on Hand items thte user has.
   @return 0 if user didn't choose an item. */
int buyingItems(int *gil, int nQuantity, int nChoice, int nItem,
				int *PD, int *EE, int *PI, int *GM, int *scar, int *adam, int *DM, int *trap,
				int *pdHand, int *eeHand, int *piHand, int *gmHand, int *scarHand, int *adamHand, int *dmHand, int *trapHand)
{
	switch (nItem) 
	{
		case 1:
			if (*PD > *gil)
			{
				printf("\n\t\tYou don't have enough Gil!\n");
				printf("\t\tPress ENTER to [L]eave\n");
				getch();
			}
            else if(*PD == 0)
            {  
                printf("\n\t>>> You can't buy the item since it's out of stock. <<< \n");
                printf("\t\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can buy %d items <<<\n", *gil / *PD);
					printf("\tHow many items would you like to buy? ");
					scanf("%d", &nQuantity);

					while (nQuantity * *PD > *gil)
					{
						printf("\n\t>>> You can only buy %d items <<<\n", *gil / *PD);
						printf("\t\tInsufficient Gil.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to buy? ");
						scanf("%d", &nQuantity);
					}

					printf("\n\tYou bought %d items for %d Gil!\n", nQuantity, nQuantity * *PD);
					printf("\tThank you! Would you like to buy again?\n\t[1]Buy	[2]Leave\n\t");
					scanf("%d", &nChoice);
					
					*pdHand += nQuantity;
					*gil = gilRemaining(*gil,nQuantity,*PD);
					
					if(nChoice == 1 && *PD > *gil)
					{
						printf("\n\tYou don't have enough Gil!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && *PD < *gil);
			}
			break;
		case 2: 
			if (*EE > *gil)
			{
				printf("\n\tYou don't have enough Gil!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*EE == 0)
            { 
                printf("\n\t>>> You can't buy the item since it's out of stock. <<< \n");
                printf("\t\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can buy %d items <<<\n", *gil / *EE);
					printf("\tHow many items would you like to buy? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity * *EE > *gil)
					{
						printf("\n\t>>> You can only buy %d items <<<\n", *gil / *EE);
						printf("\t\tInsufficient Gil.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to buy? ");
						scanf("%d", &nQuantity);
					}

					printf("\n\tYou bought %d items for %d Gil!\n", nQuantity, nQuantity * *EE);
					printf("\tThank you! Would you like to buy again?\n\t[1]Buy	[2]Leave\n\t");
					scanf("%d", &nChoice);

					*eeHand += nQuantity;
					*gil = gilRemaining(*gil,nQuantity,*EE);
					
					if(nChoice == 1 && *EE > *gil)
					{
						printf("\n\tYou don't have enough Gil!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && *EE < *gil);
			}
			break;
		case 3:
			if (*PI > *gil)
			{
				printf("\n\tYou don't have enough Gil!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*PI == 0)
            { 
                printf("\n\t>>> You can't buy the item since it's out of stock. <<< \n");
                printf("\t\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can buy %d items <<<\n", *gil / *PI);
					printf("\tHow many items would you like to buy? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity * *PI > *gil)
					{
						printf("\n\t>>> You can only buy %d items <<<\n", *gil / *PI);
						printf("\t\tInsufficient Gil.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to buy? ");
						scanf("%d", &nQuantity);
					}
					
					printf("\n\tYou bought %d items for %d Gil!\n", nQuantity, nQuantity * *PI);
					printf("\tThank you! Would you like to buy again?\n\t[1]Buy	[2]Leave\n\t");
					scanf("%d", &nChoice);
				
					*piHand += nQuantity;
					*gil = gilRemaining(*gil,nQuantity,*PI);
				
					if(nChoice == 1 && *PI > *gil)
					{
						printf("\n\tYou don't have enough Gil!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && *PI < *gil);
			}
			break;
		case 4:
			if (*GM > *gil)
			{
				printf("\n\tYou don't have enough Gil!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*GM == 0)
            { 
                printf("\n\t>>> You can't buy the item since it's out of stock. <<< \n");
                printf("\t\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can buy %d items <<<\n", *gil / *GM);
					printf("\tHow many items would you like to buy? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity * *GM > *gil)
					{
						printf("\n\t>>> You can only buy %d items <<<\n", *gil / *GM);
						printf("\t\tInsufficient Gil.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to buy? ");
						scanf("%d", &nQuantity);
					}
					
					printf("\n\tYou bought %d items for %d Gil!\n", nQuantity, nQuantity * *GM);
					printf("\tThank you! Would you like to buy again?\n\t[1]Buy	[2]Leave\n\t");
					scanf("%d", &nChoice);
				
					*gmHand += nQuantity;
					*gil = gilRemaining(*gil,nQuantity,*GM);
				
					if(nChoice == 1 && *GM > *gil)
					{
						printf("\n\tYou don't have enough Gil!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && *GM < *gil);
			}
			break;
		case 5:
			if (*scar > *gil)
			{
				printf("\n\tYou don't have enough Gil!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*scar == 0)
            { 
                printf("\n\t>>> You can't buy the item since it's out of stock. <<< \n");
                printf("\t\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can buy %d items <<<\n", *gil / *scar);
					printf("\tHow many items would you like to buy? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity * *scar > *gil)
					{
						printf("\n\t>>> You can only buy %d items <<<\n", *gil / *scar);
						printf("\t\tInsufficient Gil.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to buy? ");
						scanf("%d", &nQuantity);
					}

					printf("\n\tYou bought %d items for %d Gil!\n", nQuantity, nQuantity * *scar);
					printf("\tThank you! Would you like to buy again?\n\t[1]Buy	[2]Leave\n\t");
					scanf("%d", &nChoice);
				
					*scarHand += nQuantity;
					*gil = gilRemaining(*gil,nQuantity,*scar);
				
					if(nChoice == 1 && *scar > *gil)
					{
						printf("\n\tYou don't have enough Gil!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && *scar < *gil);
			}
			break;
		case 6:
			if (*adam > *gil)
			{
				printf("\n\tYou don't have enough Gil!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*adam == 0)
            { 
                printf("\n\t>>> You can't buy the item since it's out of stock. <<< \n");
                printf("\t\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{	
				do{
					printf("\n\t>>> You can buy %d items <<<\n", *gil / *adam);
					printf("\tHow many items would you like to buy? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity * *adam > *gil)
					{
						printf("\n\t>>> You can only buy %d items <<<\n", *gil / *adam);
						printf("\t\tInsufficient Gil.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to buy? ");
						scanf("%d", &nQuantity);
					}
					
					printf("\n\tYou bought %d items for %d Gil!\n", nQuantity, nQuantity * *adam);
					printf("\tThank you! Would you like to buy again?\n\t[1]Buy	[2]Leave\n\t");
					scanf("%d", &nChoice);
				
					*adamHand += nQuantity;
					*gil = gilRemaining(*gil,nQuantity,*adam);
				
					if(nChoice == 1 && *adam > *gil)
					{
						printf("\n\tYou don't have enough Gil!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && *adam < *gil);
			}
			break;
		case 7:
			if (*DM > *gil)
			{
				printf("\n\tYou don't have enough Gil!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*DM == 0)
            { 
                printf("\n\t>>> You can't buy the item since it's out of stock. <<< \n");
                printf("\t\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can buy %d items <<<\n", *gil / *DM);
					printf("\tHow many items would you like to buy? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity * *DM > *gil)
					{
						printf("\n\t>>> You can only buy %d items <<<\n", *gil / *DM);
						printf("\t\tInsufficient Gil.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to buy? ");
						scanf("%d", &nQuantity);
					}
					
					printf("\n\tYou bought %d items for %d Gil!\n", nQuantity, nQuantity * *DM);
					printf("\tThank you! Would you like to buy again?\n\t[1]Buy	[2]Leave\n\t");
					scanf("%d", &nChoice);
				
					*dmHand += nQuantity;
					*gil = gilRemaining(*gil,nQuantity,*DM);
				
					if(nChoice == 1 && *DM > *gil)
					{
						printf("\n\tYou don't have enough Gil!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && *DM < *gil);
			}
			break;
		case 8:
				if (*trap > *gil)
				{
					printf("\n\tYou don't have enough Gil!\n");
					printf("\t\t[L]eave\n");
					getch();
				}
				else if(*trap == 0)
				{ 
					printf("\n\t>>> You can't buy the item since it's out of stock. <<< \n");
					printf("\t\t\tPress ENTER to [L]eave\n");
					getch();
				}
				else
				{
					do{
						printf("\n\t>>> You can buy %d items <<<\n", *gil / *trap);
						printf("\tHow many items would you like to buy? ");
						scanf("%d", &nQuantity);
						
						while (nQuantity * *trap > *gil)
						{
							printf("\n\t>>> You can only buy %d items <<<\n", *gil / *trap);
							printf("\t\tInsufficient Gil.\n\t\tPlease try again...\n");
							printf("\n\tHow many items would you like to buy? ");    
							scanf("%d", &nQuantity);
						}
						
						printf("\n\tYou bought %d items for %d Gil!\n", nQuantity, nQuantity * *trap);
						printf("\tThank you! Would you like to buy again?\n\t[1]Buy	[2]Leave\n\t");
						scanf("%d", &nChoice);
					
						*trapHand += nQuantity;
						*gil = gilRemaining(*gil,nQuantity,*trap);
					
					if(nChoice == 1 && *trap > *gil)
					{
						printf("\n\tYou don't have enough Gil!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && *trap < *gil);
				}
			break;
		default:
			printf("\n\tInvalid input!\n");
			printf("\tPress Enter to continue. ");
			getch();
			break;
	}
	
	return 0;
}

/* This function has the the conditional statements that will let the user to choose on what 
   item to sell and will perform the necesary actions when selling like updating the gil and item 
   on hand after selling.
   @param: *gil is a pointer parameter that contains the value of how much money the user has.
   @param: nQuantity is the user inputted integer that indicates how many he/she will buy.
   @param: nChoice is the user's choice if he/she will sell again or not.
   @param: nItem is the item that user wants to sell.
   @param: *PD, *EE, *PI, *GM, *scar, *adam, *DM and *trap are pointer parameters of each items that 
   			contains the value of its prices.
   @param: *pdHand, *eeHand, *piHand, *gmHand, *scarHand, *adamHand, *dmHand and *trapHand are pointer parameters 
   			of each items that contains the value of how many on Hand items thte user has.
   @return 0 if user didn't choose an item. */
int sellingItems(int *gil, int nQuantity, int nChoice, int nItem,
				int *PD, int *EE, int *PI, int *GM, int *scar, int *adam, int *DM, int *trap,
				int *pdHand, int *eeHand, int *piHand, int *gmHand, int *scarHand, int *adamHand, int *dmHand, int *trapHand)
{
	switch (nItem)
	{
		case 1:
			if(*pdHand == 0)
			{
				printf("\n\tYou don't have enough items to sell!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*PD == 0)
            { 
                printf("\n\t>>> You can't sell an item when it's sold out. <<< \n");
                printf("\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can sell %d items <<<\n", *pdHand);
					printf("\tHow many items would you like to sell? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity > *pdHand)
					{
						printf("\n\t>>> You can only sell %d items <<<\n", *pdHand);
						printf("\t\tInsufficient items.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to sell? ");
						scanf("%d", &nQuantity);
					}
					
					printf("\n\tYou sold %d items for %d Gil!\n", nQuantity, nQuantity * *PD);
					printf("\tThank you! Would you like to sell again?\n\t[1]Sell	[2]Leave\n\t");
					scanf("%d", &nChoice);
					
					*pdHand -= nQuantity;
					*gil = gilAdded(*gil,nQuantity,*PD);
					
					if(nChoice == 1 && nQuantity > *pdHand)
					{
						printf("\n\tYou don't have enough items to sell!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
					
				}while(nChoice != 2 && nQuantity < *pdHand);
			}
			break;
		case 2:
			if(*eeHand == 0)
			{
				printf("\n\tYou don't have enough items to sell!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*EE == 0)
            { 
                printf("\n\t>>> You can't sell an item when it's sold out. <<< \n");
                printf("\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can sell %d items <<<\n", *eeHand);
					printf("\tHow many items would you like to sell? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity > *eeHand)
					{
						printf("\n\t>>> You can only sell %d items <<<\n", *eeHand);
						printf("\t\tInsufficient items.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to sell? ");
						scanf("%d", &nQuantity);
					}

					printf("\n\tYou sold %d items for %d Gil!\n", nQuantity, nQuantity * *EE);
					printf("\tThank you! Would you like to sell again?\n\t[1]Sell	[2]Leave\n\t");
					scanf("%d", &nChoice);
					
					*eeHand -= nQuantity;
					*gil = gilAdded(*gil,nQuantity,*EE);
					
					if(nChoice == 1 && nQuantity > *eeHand)
					{
						printf("\n\tYou don't have enough items to sell!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && nQuantity < *eeHand);
			}
			break;
		case 3:
			if(*piHand == 0)
			{
				printf("\n\tYou don't have enough items to sell!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*PI == 0)
            { 
                printf("\n\t>>> You can't sell an item when it's sold out. <<< \n");
                printf("\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can sell %d items <<<\n", *piHand);
					printf("\tHow many items would you like to sell? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity > *piHand)
					{
						printf("\n\t>>> You can only sell %d items <<<\n", *piHand);
						printf("\t\tInsufficient items.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to sell? ");
						scanf("%d", &nQuantity);
					}

					printf("\n\tYou sold %d items for %d Gil!\n", nQuantity, nQuantity * *PI);
					printf("\tThank you! Would you like to sell again?\n\t[1]Sell	[2]Leave\n\t");
					scanf("%d", &nChoice);
					
					*piHand -= nQuantity;
					*gil = gilAdded(*gil,nQuantity,*PI);
					
					if(nChoice == 1 && nQuantity > *piHand)
					{
						printf("\n\tYou don't have enough items to sell!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && nQuantity < *piHand);
			}
			break;
		case 4:
			if(*gmHand == 0)
			{
				printf("\n\tYou don't have enough items to sell!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*GM == 0)
            { 
                printf("\n\t>>> You can't sell an item when it's sold out. <<< \n");
                printf("\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can sell %d items <<<\n", *gmHand);
					printf("\tHow many items would you like to sell? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity > *gmHand)
					{
						printf("\n\t>>> You can only sell %d items <<<\n", *gmHand);
						printf("\t\tInsufficient items.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to sell? ");
						scanf("%d", &nQuantity);
					}

					printf("\n\tYou sold %d items for %d Gil!\n", nQuantity, nQuantity * *GM);
					printf("\tThank you! Would you like to sell again?\n\t[1]Sell	[2]Leave\n\t");
					scanf("%d", &nChoice);
					
					*gmHand -= nQuantity;
					*gil = gilAdded(*gil,nQuantity,*GM);
					
					if(nChoice == 1 && nQuantity > *gmHand)
					{
						printf("\n\tYou don't have enough items to sell!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && nQuantity < *gmHand);
			}
			break;	
		case 5:
			if(*scarHand == 0)
			{
				printf("\n\tYou don't have enough items to sell!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*scar == 0)
            { 
                printf("\n\t>>> You can't sell an item when it's sold out. <<< \n");
                printf("\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can sell %d items <<<\n", *scarHand);
					printf("\tHow many items would you like to sell? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity > *scarHand)
					{
						printf("\n\t>>> You can only sell %d items <<<\n", *scarHand);
						printf("\t\tInsufficient items.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to sell? ");
						scanf("%d", &nQuantity);
					}

					printf("\n\tYou sold %d items for %d Gil!\n", nQuantity, nQuantity * *scar);
					printf("\tThank you! Would you like to sell again?\n\t[1]Sell	[2]Leave\n\t");
					scanf("%d", &nChoice);
					
					*scarHand -= nQuantity;
					*gil = gilAdded(*gil,nQuantity,*scar);
					
					if(nChoice == 1 && nQuantity > *scarHand)
					{
						printf("\n\tYou don't have enough items to sell!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && nQuantity < *scarHand);
			}
			break;
		case 6:
			if(*adamHand == 0)
			{
				printf("\n\tYou don't have enough items to sell!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*adam == 0)
            { 
                printf("\n\t>>> You can't sell an item when it's sold out. <<< \n");
                printf("\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can sell %d items <<<\n", *adamHand);
					printf("\tHow many items would you like to sell? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity > *adamHand)
					{
						printf("\n\t>>> You can only sell %d items <<<\n", *adamHand);
						printf("\t\tInsufficient items.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to sell? ");
						scanf("%d", &nQuantity);
					}

					printf("\n\tYou sold %d items for %d Gil!\n", nQuantity, nQuantity * *adam);
					printf("\tThank you! Would you like to sell again?\n\t[1]Sell	[2]Leave\n\t");
					scanf("%d", &nChoice);
					
					*adamHand -= nQuantity;
					*gil = gilAdded(*gil,nQuantity,*adam);
					
					if(nChoice == 1 && nQuantity > *adamHand)
					{
						printf("\n\tYou don't have enough items to sell!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && nQuantity < *adamHand);
			}
			break;
		case 7:
			if(*dmHand == 0)
			{
				printf("\n\tYou don't have enough items to sell!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*DM == 0)
            { 
                printf("\n\t>>> You can't sell an item when it's sold out. <<< \n");
                printf("\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can sell %d items <<<\n", *dmHand);
					printf("\tHow many items would you like to sell? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity > *dmHand)
					{
						printf("\n\t>>> You can only sell %d items <<<\n", *dmHand);
						printf("\t\tInsufficient items.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to sell? ");
						scanf("%d", &nQuantity);
					}

					printf("\n\tYou sold %d items for %d Gil!\n", nQuantity, nQuantity * *DM);
					printf("\tThank you! Would you like to sell again?\n\t[1]Sell	[2]Leave\n\t");
					scanf("%d", &nChoice);
					
					*dmHand -= nQuantity;
					*gil = gilAdded(*gil,nQuantity,*DM);
					
					if(nChoice == 1 && nQuantity > *dmHand)
					{
						printf("\n\tYou don't have enough items to sell!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && nQuantity < *dmHand);
			}
			break;
		case 8:
			if(*trapHand == 0)
			{
				printf("\n\tYou don't have enough items to sell!\n");
				printf("\t\t[L]eave\n");
				getch();
			}
			else if(*trap == 0)
            { 
                printf("\n\t>>> You can't sell an item when it's sold out. <<< \n");
                printf("\t\tPress ENTER to [L]eave\n");
				getch();
            }
			else
			{
				do{
					printf("\n\t>>> You can sell %d items <<<\n", *trapHand);
					printf("\tHow many items would you like to sell? ");
					scanf("%d", &nQuantity);
					
					while (nQuantity > *trapHand)
					{
						printf("\n\t>>> You can only sell %d items <<<\n", *trapHand);
						printf("\t\tInsufficient items.\n\t\tPlease try again...\n");
						printf("\n\tHow many items would you like to sell? ");
						scanf("%d", &nQuantity);
					}

					printf("\n\tYou sold %d items for %d Gil!\n", nQuantity, nQuantity * *trap);
					printf("\tThank you! Would you like to sell again?\n\t[1]Sell	[2]Leave\n\t");
					scanf("%d", &nChoice);
					
					*trapHand -= nQuantity;
					*gil = gilAdded(*gil,nQuantity,*trap);
					
					if(nChoice == 1 && nQuantity > *trapHand)
					{
						printf("\n\tYou don't have enough items to sell!\n");
						printf("\n\t[B]ack\n");
						getch();
					}
				}while(nChoice != 2 && nQuantity < *trapHand);
			}
			break;
	default:
		printf("\n\tInvalid input!\n");
		printf("\tPress Enter to continue. ");
		getch();
		break;
	}
	
	return 0;
}

int main()
{
	//PlaySound(TEXT("C:\\Users\\Cymbeline Anne\\Desktop\\Clash.wav"),NULL,SND_ASYNC); //code for background music
	srand(time(NULL));

	int nDay, nGil = 20000, nDebt = 50000, shop, end = 0, startGame, choice;
	int item, quantity = 0, nWallet = 0, loan, amount, profit = 0, minus;
	int phoenix, elixir, plat, gold, scarlet, adaman, dark, trapez;
	int phHand = 0, elHand = 0, plHand = 0, goHand = 0, scHand = 0, adHand = 0, dahand = 0, trHand = 0;
	char cOpt, playAgain;
	
	printf("\n\t\t\t  START GAME:\n");
	printf("\n\t\t\t[1] YES\t [2] NO\n\t\t\t");
	scanf("%d", &startGame);
	system("cls");

	do{
		if(startGame == 1)
		{
			do{
				system("cls");
				displayWelcome();
				displayName();
				getch();
				system("cls");
				
				for(nDay = 1; nDay <= 30; nDay++)
				{
					phoenix = randomPrice(500,1200,0);
					elixir = randomPrice(1500,2100,0);
					plat = randomPrice(5000,7000,0);
					gold = randomPrice(3500,5500,0);
					scarlet = randomPrice(8000,12000,0);
					adaman = randomPrice(15000,30000,0);
					dark = randomPrice(40000,70000,0);
					trapez = randomPrice(60000,90000,0);
					
					// The deposited gil will increase by 10% everyday.
					minus = nWallet * 0.10;
					nWallet = nWallet + (nWallet * 0.10) - minus ;
					
					mainRift(nDay,nGil,nDebt,&shop);
			
					do{
						switch(shop)
						{
							case 1:
								trapez = randomPrice(35000,65000,1);
								
								system("cls");
								printf("\n\t\t******************************\n");
								printf("\t\t   Tycoon Meteor's Minerals\n");
								printf("\t\t******************************\n");
								printf("\n\tShopkeeper: Welcome! How may I be of service?\n");
								
								displayShop(&cOpt,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
											&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
							
								if(cOpt == 'B' || cOpt == 'b')
								{
									system("cls");
									printf("\n\t\t******************************\n");
									printf("\t\t   Tycoon Meteor's Minerals\n");
									printf("\t\t******************************\n");
									printf("\n\tShopkeeper: Buying an item? Which one?\n");
						
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
									
									buyingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);	
								}
								else if(cOpt == 'S' || cOpt == 's')
								{
									system("cls");
									printf("\n\t\t******************************\n");
									printf("\t\t   Tycoon Meteor's Minerals\n");
									printf("\t\t******************************\n");
									printf("\n\tShopkeeper: Selling an item? Which one?\n");
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
									
									sellingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												 &phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
								}
								else if(cOpt == 'L' || cOpt == 'l')
								{
									system("cls");
									nDebt = computeDebt(&nDebt);
									nWallet = (nWallet + (nWallet * 0.10)); 
								}
								else
								{
									printf("\n\tInvalid input!\n");
									printf("\tPress Enter to continue. ");
									getch();
								}
								break;
							case 2:
								phoenix = randomPrice(300,800,1);
								elixir = randomPrice(1000,1700,1);

								system("cls");
								printf("\n\t\t**************************\n");
								printf("\t\t   Pulsian Restoratives\n");
								printf("\t\t**************************\n");
								printf("\n\tShopkeeper: Welcome! How may I be of service?\n");

								displayShop(&cOpt,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
											&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
			
								if(cOpt == 'B' || cOpt == 'b')
								{
									system("cls");
									printf("\n\t\t**************************\n");
									printf("\t\t   Pulsian Restoratives\n");
									printf("\t\t**************************\n");
									printf("\n\tShopkeeper: Buying an item? Which one?\n");
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													  &phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);

									buyingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);	
								}
								else if(cOpt == 'S' || cOpt == 's')
								{
									system("cls");
									printf("\n\t\t**************************\n");
									printf("\t\t   Pulsian Restoratives\n");
									printf("\t\t**************************\n");
									printf("\n\tShopkeeper: Selling an item? Which one?\n");
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);

									sellingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												 &phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
								}
								else if(cOpt == 'L' || cOpt == 'l')
								{
									system("cls");
									nDebt = computeDebt(&nDebt);
									nWallet = (nWallet + (nWallet * 0.10)); 
								}
								else
								{	
									printf("\n\tInvalid input!\n");
									printf("\tPress Enter to continue. ");
									getch();
								}
								break;
							case 3:
								plat = randomPrice(4500,6000,1);
								
								system("cls");
								printf("\n\t\t************************\n");
								printf("\t\t   Archadian Luxuries\n");
								printf("\t\t************************\n");
								printf("\n\tShopkeeper: Welcome! How may I be of service?\n");
								
								displayShop(&cOpt,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
											&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
			
								if(cOpt == 'B' || cOpt == 'b')
								{
									system("cls");
									printf("\n\t\t************************\n");
									printf("\t\t   Archadian Luxuries\n");
									printf("\t\t************************\n");
									printf("\n\tShopkeeper: Buying an item? Which one?\n");
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													  &phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
													  
									buyingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);	
								}
								else if(cOpt == 'S' || cOpt == 's')
								{
									system("cls");
									printf("\n\t\t************************\n");
									printf("\t\t   Archadian Luxuries\n");
									printf("\t\t************************\n");
									printf("\n\tShopkeeper: Selling an item? Which one?\n");
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);

									sellingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												 &phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
								}
								else if(cOpt == 'L' || cOpt == 'l')
								{
									system("cls");
									nDebt = computeDebt(&nDebt);
									nWallet = (nWallet + (nWallet * 0.10)); 
								}
								else
								{
									printf("\n\tInvalid input!\n");
									printf("\tPress Enter to continue. ");
									getch();
								}
								break;
							case 4:
								gold = randomPrice(3000,5000,1);
								
								system("cls");
								printf("\n\t\t******************************\n");
								printf("\t\t    Cid's Magical Escapades\n");
								printf("\t\t******************************\n");
								printf("\n\tShopkeeper: Welcome! How may I be of service?\n");

								displayShop(&cOpt,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
											&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
			
								if(cOpt == 'B' || cOpt == 'b')
								{
									system("cls");
									printf("\n\t\t******************************\n");
									printf("\t\t    Cid's Magical Escapades\n");
									printf("\t\t******************************\n");
									printf("\n\tShopkeeper: Buying an item? Which one?\n");
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													  &phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
													  
									buyingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);	
								}
								else if(cOpt == 'S' || cOpt == 's')
								{
									system("cls");
									printf("\n\t\t******************************\n");
									printf("\t\t    Cid's Magical Escapades\n");
									printf("\t\t******************************\n");
									printf("\n\tShopkeeper: Selling an item? Which one?\n");
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);

									sellingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												 &phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
								}
								else if(cOpt == 'L' || cOpt == 'l')
								{
									system("cls");
									nDebt = computeDebt(&nDebt);
									nWallet = (nWallet + (nWallet * 0.10)); 
								}
								else
								{
									printf("\n\tInvalid input!\n");
									printf("\tPress Enter to continue. ");
									getch();
								}
								break;
							case 5:
								scarlet = randomPrice(5000,10000,1);
								
								system("cls");
								printf("\n\t\t************************\n");
								printf("\t\t    Gaian Gratitudes\n");
								printf("\t\t************************\n");
								printf("\n\tShopkeeper: Welcome! How may I be of service?\n");

								displayShop(&cOpt,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
											&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
			
								if(cOpt == 'B' || cOpt == 'b')
								{
									system("cls");
									printf("\n\t\t************************\n");
									printf("\t\t    Gaian Gratitudes\n");
									printf("\t\t************************\n");
									printf("\n\tShopkeeper: Buying an item? Which one?\n");
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													  &phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
													  
									buyingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);	
								}
								else if(cOpt == 'S' || cOpt == 's')
								{
									system("cls");
									printf("\n\t\t************************\n");
									printf("\t\t    Gaian Gratitudes\n");
									printf("\t\t************************\n");
									printf("\n\tShopkeeper: Selling an item? Which one?\n");
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);

									sellingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												 &phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
								}
								else if(cOpt == 'L' || cOpt == 'l')
								{
									system("cls");
									nDebt = computeDebt(&nDebt);
									nWallet = (nWallet + (nWallet * 0.10)); 
								}
								else
								{
									printf("\n\tInvalid input!\n");
									printf("\tPress Enter to continue. ");
									getch();
								}
								break;
							case 6:
								adaman = randomPrice(9500,20000,1);
								dark = randomPrice(22000,50000,1);
								
								system("cls");
								printf("\n\t\t************************************\n");
								printf("\t\t    Riches and Minerals of Spira\n");
								printf("\t\t************************************\n");
								printf("\n\tShopkeeper: Welcome! How may I be of service?\n");
							
								displayShop(&cOpt,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
											&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
			
								if(cOpt == 'B' || cOpt == 'b')
								{
									system("cls");
									printf("\n\t\t************************************\n");
									printf("\t\t    Riches and Minerals of Spira\n");
									printf("\t\t************************************\n");
									printf("\n\tShopkeeper: Buying an item? Which one?\n");
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													  &phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
													  
									buyingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);	
								}
								else if(cOpt == 'S' || cOpt == 's')
								{
									system("cls");
									printf("\n\t\t************************************\n");
									printf("\t\t    Riches and Minerals of Spira\n");
									printf("\t\t************************************\n");
									printf("\n\tShopkeeper: Selling an item? Which one?\n");
									displayBuySellShop(&item,nDay,nGil,nDebt,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
													&phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);

									sellingItems(&nGil,quantity,choice,item,&phoenix,&elixir,&plat,&gold,&scarlet,&adaman,&dark,&trapez,
												 &phHand,&elHand,&plHand,&goHand,&scHand,&adHand,&dahand,&trHand);
								}
								else if(cOpt == 'L' || cOpt == 'l')
								{
									system("cls");
									nDebt = computeDebt(&nDebt);
									nWallet = (nWallet + (nWallet * 0.10)); 
								}
								else
								{
									printf("\n\tInvalid input!\n");
									printf("\tPress Enter to continue. ");
									getch();
								}
								break;
							case 7:

								do{ 
									system("cls");
									merchantRift(&nGil,&nDebt,nDay,&choice,&nWallet);

									if(choice == 1)
									{
										printf("\n\t ----------------------------------------------");
										printf("\n\t\tHow much Gil you want to deposit?");
										printf("\n\t ----------------------------------------------\n");
										printf("\n\t\tEnter amount: ");
										scanf("%d", &amount);

										while(amount > nGil)
										{
											printf("\n\t\tYou don't have enough gil to deposit.\n\t\tPlease try again...\n");
											printf("\n\t\tEnter amount: ");
											scanf("%d", &amount);
										}

										nGil = nGil - amount;
										nWallet = nWallet + amount;
										
										printf("\n\t\t====================\n");
										printf("\t\t    Gil: %d\n", nGil);
										printf("\t\t    Savings: %d\n", nWallet);
										printf("\t\t====================\n");
										printf("\n\t\tPress any key to continue. ");
										getch();
									}
									else if(choice == 2)
									{
										printf("\n\t -----------------------------------------------");
										printf("\n\t\tHow much Gil you want to withdraw?");
										printf("\n\t -----------------------------------------------\n");
										printf("\n\t\tEnter amount: ");
										scanf("%d", &amount);

										while(amount > nWallet)
										{
											printf("\n\t\tYou don't have enough gil to wwithdraw.\n\t\tPlease try again...\n");
											printf("\n\t\tEnter amount: ");
											scanf("%d", &amount);
										}

										nGil = nGil + amount;
										nWallet = nWallet - amount;

										printf("\n\t\t====================\n");
										printf("\t\t    Gil: %d\n", nGil);
										printf("\t\t    Savings: %d\n", nWallet);
										printf("\t\t====================\n");
										printf("\n\t\tPress Enter to continue. ");
										getch();
									}
									else if(choice == 3)
									{
										printf("\n\t --------------------------------------------------------------");
										printf("\n\t\tHow much debt you want to pay? (Full or Partial)");
										printf("\n\t --------------------------------------------------------------\n");
										printf("\n\t\tEnter amount: ");
										scanf("%d", &amount);
										
										while(amount > nGil)
										{
											printf("\n\t\tInsufficient gil.\n\t\tPlease try again...\n");
											printf("\n\t\tEnter amount: ");
											scanf("%d", &amount);
										}

										nDebt = nDebt - amount;
										nGil = nGil - amount;
										
										printf("\n\t\t===========================\n");
										printf("\t\t   Debt Remaining: %d\n", nDebt);
										printf("\t\t===========================\n");
										printf("\n\t\tPress Enter to continue. ");
										getch();
									}
									else if(choice == 4)
									{
										printf("\n\t --------------------------------------------------");
										printf("\n\t\tHow much Gil you want us to loan you?");
										printf("\n\t --------------------------------------------------\n");
										printf("\n\t\tEnter amount: ");
										scanf("%d", &loan);

										nGil = nGil + loan;
										nDebt = nDebt + loan;

										printf("\n\t\t===========================\n");
										printf("\t\t  Debt: %d\n", nDebt);
										printf("\t\t  Gil: %d\n", nGil);
										printf("\t\t===========================\n");
										printf("\n\t\tPress Enter to continue. ");
										getch();
									}
									else if(choice == 5)
									{
										printf("\n\t\t===========================\n");
										printf("\t\t      Savings: %d\n", nWallet);
										printf("\t\t===========================\n");
										printf("\n\t\tPress Enter to continue. ");
										getch();
									}
									else if(choice == 6)
									{
										system("cls");
										cOpt = 'l';
										nDay--;
									}
									else
									{
										printf("\n\tInvalid input!\n");
										printf("\tPress Enter to continue. ");
										getch();
									}
								}while(choice!=6);
								break;
							case 8: 
								system("cls");
								profit	= (nGil - nDebt) + nWallet;

								printf("\n\t ------------- QUIT GAME --------------\n");
								printf("\n\t\tTotal Gil Earned: %dG\n",nGil);
								printf("\t\tDebt Reamining: %dG\n",nDebt);
								printf("\t\tTotal Profit: %dG\n", profit);
								printf("\n\t --------------------------------------\n");

								if(nDebt > 0 && nGil > 0)
									printf("\n\t  ***** You have lost the game! *****\n\t");
								else 
									printf("\n\t  ***** You have won the game! *****\n\t");

								end = 1;

								return end;
								break;

							default:
								while(shop > 8 || shop < 1)
								{               
									printf("You entered an invalid choice.\n");
									printf("\tTry again\n");
									printf("\nYour Choice: ");
									scanf("%d", &shop);
								}
								break;
						}
					}while(cOpt != 'L' && cOpt != 'l');
				}	
				
			    system("cls");		
				profit	= (nGil - nDebt) + nWallet;
				
				printf("\n\n\t ========== END OF THE GAME! ==========\n");
				printf("\n\t\tTotal Gil Earned: %dG\n",nGil + nWallet);
				printf("\t\tDebt Reamining: %dG\n",nDebt);
				printf("\t\tTotal Profit: %dG\n", profit);
				printf("\n\t ======================================\n");

				if(nDebt == 0 && nGil > 0)
				{
					printf("\n\t  ***** You have won the game! *****\n");
					printf("\n    Merchant of the Rift: CONGRATULATIONS! YOU FINISHED\n\tYOUR QUEST! YOU CAN FINALLY BUY AN EXCALIPOOR!\n");
					printf("\n\t\tPlay again? [Y]es  [N]o  ");
					scanf(" %c", &playAgain);
					startGame = 0;
				}
				else if(nDebt > 0 || nDebt > 50000)
				{
					printf("\n\n\t   ***** You have lost the game! *****\n");
					printf("\n   Merchant of the Rift: REALLY? YOU COULDN'T EVEN EARN\n\t    ENOUGH TO BUY AN EXCALIPOOR!\n");
					printf("\n\t\t Play again? [Y]es  [N]o  ");
					scanf(" %c", &playAgain);
					startGame = 0;
				}
			}while(playAgain != 'N' && playAgain != 'n');
		}
	}while(startGame == 1);
	
	return 0;	
}
