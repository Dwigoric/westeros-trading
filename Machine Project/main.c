/*
	Description: Machine Project for CCPROG1
	Programmed by: Joshua C. Permito  S17A
	Last modified: January 8, 2022 @ 12:56 PM
*/

#include "display.h"

/*
	The function used when the user wants to buy a trading partner's goods and wares.

	@param nTradingPartner - The trading partner.
	@param nCapacity - The capacity of the wheelhouse.
	@param pGD - Pointer to the memory address of the variable holding the amount of Golden Dragons the user has.
	@param pInventory - Pointer to the memory address of the variable holding the array of the player inventory.
*/
void buy(int nTradingPartner, unsigned int nCapacity, unsigned int* pGD, unsigned int (*pInventory)[8]) {
	unsigned int nCost;
	int nItem, nAmount;
	char cChoice = 'N';

	// Display goods, wares, and costs.
	displayWideDivider();
	displayPartnerSales(nTradingPartner);
	displayWideDivider();
	displayInventory(*pInventory, 0);
	displayWideDivider();

	// Ask user what they want to buy.
	do {
		printf("\nWhat would you like to buy?\n");
		printf("[0] Go Back [1-8] Buy Item: ");
		if (!scanf(" %d%*[^\n]", &nItem)) {
			nItem = 10;
			scanf(" %*s");
		}

		if (nItem > 8) printf("\tInvalid input.");
	} while (nItem > 8);

	// Ask user how many they want to buy.
	if (nItem >= 1 && nItem <= 8) do {
		printf("\nHow many would you like to buy?\n> ");
		if (!scanf(" %d%*[^\n]", &nAmount)) {
			nAmount = 0;
			scanf(" %*s");
		}

		if (nAmount < 1) printf("\tInvalid input.\n");
		else if (nAmount > nCapacity - (*pInventory)[nItem - 1]) printf("\tBuying %d of this item will exceed your wheelhouse's capacity.\n", nAmount);
	} while (nAmount < 1 || nAmount > nCapacity - (*pInventory)[nItem - 1]);

	if (nItem >= 1 && nItem <= 8) {
		nCost = getCost(nTradingPartner, nItem, nAmount);
		printf("\nThat item costs %u Golden Dragons.", nCost);
		if (*pGD < nCost) printf("\nYou do not have enough Golden Dragons.");
		else do {
			// Run this only when user has enough GDs.
			printf("\nAre you sure you want go through with the purchase? [Y]es/[N]o: ");
			scanf(" %c%*[^\n]", &cChoice);
	
			// Capitalize user input if lowercase.
			switch (cChoice) {
			case 'y': cChoice = 'Y'; break;
			case 'n': cChoice = 'N'; break;
			}

			if (cChoice != 'Y' && cChoice != 'N') printf("\tInvalid input.\n");
		} while (cChoice != 'Y' && cChoice != 'N');
	
		if (cChoice == 'N') {
			// Go back to "day" menu if user does not want to buy.
			printf("\nAborting transaction. Type anything to continue.");
			scanf(" %*s");
		}
		else {
			// Subtract the cost from the user GDs, and add 1 of the item they bought to the inventory array.
			*pGD -= nCost;
			(*pInventory)[nItem - 1] += nAmount;

			clearscr();
			printf("Bought item successfully!\n");
			displayWideDivider();
			displayInventory(*pInventory, 0);
			printf("\nType anything to continue.");
			scanf(" %*s");
		}
	}
}

/*
	The function used when the user wants to sell their goods and wares to the trading partner.

	@param nTradingPartner - The trading partner.
	@param pGD - Pointer to the memory address of the variable holding the amount of Golden Dragons the user has.
	@param pInventory - Pointer to the memory address of the variable holding the array of the player inventory.
*/
void sell(int nTradingPartner, unsigned int* pGD, unsigned int (*pInventory)[8]) {
	unsigned int nCost;
	int nAmount, nItem;
	char cChoice = 'N';

	// Display goods, wares, and costs.
	displayWideDivider();
	displayPartnerSales(nTradingPartner);
	displayWideDivider();
	displayInventory(*pInventory, 1);
	displayWideDivider();

	// Ask user what they want to sell.
	do {
		printf("What would you like to sell?\n");
		printf("[0] Go Back [1-8] Sell Item: ");
		if (!scanf(" %d%*[^\n]", &nItem)) {
			nItem = 10;
			scanf(" %*s");
		}

		if (nItem > 8) printf("\tInvalid input.");
	} while (nItem > 8);

	// Ask user how many they want to buy.
	if (nItem >= 1 && nItem <= 8) do {
		printf("\nHow many would you like to sell?\n> ");
		if (!scanf(" %d%*[^\n]", &nAmount)) {
			nAmount = 0;
			scanf(" %*s");
		}

		if (nAmount < 1) printf("\tInvalid input.\n");
		else if (nAmount > (*pInventory)[nItem - 1]) printf("\tYou only have %u of that item.\n", (*pInventory)[nItem - 1]);
	} while (nAmount < 0 || nAmount > (*pInventory)[nItem - 1]);

	if (nItem >= 1 && nItem <= 8) {
		nCost = getCost(nTradingPartner, nItem, nAmount);
		printf("\nThe trading partner is willing to trade %u GDs for that item.", nCost);
		if ((*pInventory)[nItem - 1] == 0) printf("\nYou do not have that item in your wheelhouse.");
		else do {
			// Run this only if the user has that item in the wheelhouse.
			printf("\nAre you sure you want go through with the transaction? [Y]es/[N]o: ");
			scanf(" %c%*[^\n]", &cChoice);

			switch (cChoice) {
			case 'y': cChoice = 'Y'; break;
			case 'n': cChoice = 'N'; break;
			}

			if (cChoice != 'Y' && cChoice != 'N') printf("\tInvalid input.\n");
		} while (cChoice != 'Y' && cChoice != 'N');

		if (cChoice == 'N') {
			// Go back to "day" menu if user does not want to sell.
			printf("\nAborting transaction. Type anything to continue.");
			scanf(" %*s");
		}
		else {
			// Add the cost of the item to the user's GDs and remove 1 item from the inventory.
			*pGD += nCost;
			(*pInventory)[nItem - 1] -= nAmount;

			clearscr();
			printf("Sold item successfully!\n");
			displayWideDivider();
			displayInventory(*pInventory, 0);
			printf("\nType anything to continue.");
			scanf(" %*s");
		}
	}
}

/*
	The function used when the user wants to transact with the Iron Bank of Braavos.

	@param nGD - Pointer to the memory address of the variable holding the amount of Golden Dragons the user has.
	@param nSavings - Pointer to the memory address of the variable holding the user's savings.
	@param nDebt - Pointer to the memory address of the variable holding the user's debt to the bank.
*/
void transactWithBank(unsigned int* pGD, unsigned int* pDebt, unsigned int* pSavings) {
	char cAction;
	int nAmount;

	displayBankMenu(*pGD, *pSavings, *pDebt);

	// Ask user what they want to do in the bank until they give a valid input.
	do {
		printf("\nChoice: ");
		scanf(" %c%*[^\n]", &cAction);
		
		// Convert lowercase inputs to uppercase.
		switch (cAction) {
		case 'd': cAction = 'D'; break;
		case 'w': cAction = 'W'; break;
		case 'b': cAction = 'B'; break;
		case 'p': cAction = 'P'; break;
		case 'x': cAction = 'X';
		}

		if (!isValidBankAction(cAction)) printf("\tInvalid input.");
	} while (!isValidBankAction(cAction));

	switch (cAction) {
		// For depositing.
	case 'D':
		if (*pGD == 0) printf("You have no Golden Dragons.\n");
		else {
			printf("How much do you want to deposit?\n> ");
			if (!scanf(" %d%*[^\n]", &nAmount)) {
				nAmount = -1;
				scanf(" %*s");
			}
			if (nAmount < 0) printf("\tInvalid input: You either entered a negative number, a number too large, or a non-numerical input.\n");
			else if (nAmount > *pGD) printf("You do not have that amount of GDs.\n");
			else {
				*pSavings += nAmount;
				*pGD -= nAmount;
				printf("Transaction successful!\n");
			}
		}
		printf("Type anything to continue.");
		scanf(" %*s");
		break;
		// For withdrawing.
	case 'W':
		if (*pSavings == 0) printf("You have no Golden Dragons in your savings account.\n");
		else {
			printf("How much do you want to withdraw?\n> ");
			if (!scanf(" %d%*[^\n]", &nAmount)) {
				nAmount = -1;
				scanf(" %*s");
			}
			if (nAmount < 0) printf("\tInvalid input: You either entered a negative number, a number too large, or a non-numerical input.\n");
			else if (nAmount > *pSavings) printf("You do not have that amount of GDs in your savings account.\n");
			else {
				*pGD += nAmount;
				*pSavings -= nAmount;
				printf("Transaction successfull!\n> ");
			}
		}
		printf("Type anything to continue.");
		scanf(" %*s");
		break;
		// For borrowing.
	case 'B':
		printf("How much do you want to borrow?\n> ");
		if (!scanf(" %d%*[^\n]", &nAmount)) {
			nAmount = -1;
			scanf(" %*s");
		}
		if (nAmount < 0) printf("\tInvalid input: You either entered a negative number, a number too large, or a non-numerical input.\n");
		else {
			*pDebt += nAmount;
			*pGD += nAmount;
			printf("Transaction successful!\n");
		}
		printf("Type anything to continue.");
		scanf(" %*s");
		break;
	// For paying debt.
	case 'P':
		if (*pDebt == 0) printf("You have no outstanding debt.\n> ");
		else {
			printf("How much debt do you want to pay?\n");
			if (!scanf(" %d%*[^\n]", &nAmount)) {
				nAmount = -1;
				scanf(" %*s");
			}
			if (nAmount < 0) printf("\tInvalid input: You either entered a negative number, a number too large, or a non-numerical input.\n");
			else if (nAmount > *pGD) printf("You do not have that amount of money right now.\n");
			else if (nAmount > *pDebt) {
				printf("You only owe %u GDs to the bank. Your debt has been automatically paid in full.\n", *pDebt);
				*pGD -= *pDebt;
				*pDebt = 0;
			}
			else {
				*pDebt -= nAmount;
				*pGD -= nAmount;
				printf("Transaction successful!\n");
			}
		}
		printf("Type anything to continue.");
		scanf(" %*s");
	}
}

/*
	The function used to continue the day after doing an action or visiting a new trading partner.

	@param nTradingPartner - The trading partner.
	@param nDays - The amount of days left.
	@param pGD - Pointer to the golden dragons variable's memory address.
	@param pDebt - Pointer to the debt variable's memory address.
	@param pSavings - Pointer to the savings variable's memory address.
	@param pCapacity - Pointer to the memory address of the variable holding the wheelhouse capacity.
	@param pInventory - Pointer to the memory address of the variable holding the array of the player inventory.

	@return 'Y' if the user wants to quit the game, 'N' if the day continues, 'W' if the user wants to ride the wheelhouse.
*/
char continueDay(int nTradingPartner, unsigned int nDays, unsigned int* pGD, unsigned int* pDebt, unsigned int* pSavings, unsigned int* pCapacity, unsigned int (*pInventory)[8]) {
	char cAction, cQuitGame = 'N';

	clearscr();

	displayWideDivider();
	displayPartnerSales(nTradingPartner);
	displayTrading(nDays, *pGD, *pDebt, *pSavings, *pCapacity, *pInventory);

	printf("\n[B]uy\t[S]ell\t[W]heelhouse\t[I]ron Bank\t[Q]uit\n");

	// Ask for user input until user gives a valid input.
	do {
		printf("\nChoice: ");
		scanf(" %c%*[^\n]", &cAction);

		switch (cAction) {
		case 'b': cAction = 'B'; break;
		case 's': cAction = 'S'; break;
		case 'i': cAction = 'I'; break;
		case 'w': cAction = 'W'; break;
		case 'q': cAction = 'Q';
		}

		if (!isValidAction(cAction)) printf("\tInvalid input.");

		switch (cAction) {
		// Disallow buying if wheelhouse is full.
		case 'B':
			if (arraySummation(*pInventory) == *pCapacity) {
				printf("\tYour wheelhouse is already full!");
				cAction = 'x';
			}
			break;
		// Disallow selling if there is nothing in the wheelhouse.
		case 'S':
			if (arraySummation(*pInventory) == 0) {
				printf("\tYou have nothing to sell.");
				cAction = 'x';
			}
			break;
		}
	} while (!isValidAction(cAction));

	clearscr();

	switch (cAction) {
	case 'B':
		buy(nTradingPartner, *pCapacity, pGD, pInventory);
		break;
	case 'S':
		sell(nTradingPartner, pGD, pInventory);
		break;
	case 'I':
		transactWithBank(pGD, pDebt, pSavings);
		break;
	case 'W':
		cQuitGame = 'W';
		break;
	case 'Q':
		cQuitGame = 'Y';
	}

	return cQuitGame;
}

/*
	The function used to run the game's logic. This function recurses itself as long as the game is in progress.

	@param nDays - The amount of days left.
	@param pGD - Pointer to the golden dragons variable's memory address.
	@param pDebt - Pointer to the debt variable's memory address.
	@param pSavings - Pointer to the savings variable's memory address.
	@param pCapacity - Pointer to the memory address of the variable holding the wheelhouse capacity.
	@param pInventory - Pointer to the memory address of the variable holding the array of the player inventory.

	@return 'W' if the user rode the wheelhouse, 'Y' if the user wants to quit the game.
*/
char startDay(unsigned int nDays, unsigned int* pGD, unsigned int* pDebt, unsigned int* pSavings, unsigned int* pCapacity, unsigned int (*pInventory)[8]) {
	int nTradingPartner;
	char cAvailUpgrade,
		 cQuitGame = 'N'; // cQuitGame == 'N' means user has not quit the game (default), otherwise this is 'Y'

	clearscr();

	displayTrading(nDays, *pGD, *pDebt, *pSavings, *pCapacity, *pInventory);

	displayOpeningScreen();

	// Ask for user input once, then if the input is invalid, ask the user for their input again until they give a valid input.
	do {
		printf("\nChoice: ");
		if (!scanf(" %d%*[^\n]", &nTradingPartner)) {
			nTradingPartner = 10;
			scanf(" %*s");
		}

		if (!isValidTradingPartner(nTradingPartner)) printf("\tInvalid input.");
	} while (!isValidTradingPartner(nTradingPartner));

	// Since input 9 means quitting the game, assign the character 'Y' to cQuitGame to indicate that the user has quit the game.
	if (nTradingPartner == 9) cQuitGame = 'Y';

	clearscr();

	// If user has not yet quit the game and lucky to meet the merchant for wheelhouse upgrade.
	if (cQuitGame == 'N' && allowWheelhouseUpgrade()) {
		printf("A merchant has offered you to upgrade your wheelhouse's capacity by 50! This upgrade costs 200 GD.\n\nCurrent status:\n");
		displayTrading(nDays, *pGD, *pDebt, *pSavings, *pCapacity, *pInventory);

		// Prompt user if they want to upgrade wheelhouse. Keep asking until they input Y or N.
		do {
			printf("\nWould you like to purchase this upgrade?\n[Y]es / [N]o: ");
			scanf(" %c%*[^\n]", &cAvailUpgrade);

			// In case user inputs a lowercase letter, use its uppercase equivalent.
			switch (cAvailUpgrade) {
			case 'y': cAvailUpgrade = 'Y'; break;
			case 'n': cAvailUpgrade = 'N'; break;
			}

			// Check if user wants to upgrade and their balance is enough.
			if (cAvailUpgrade == 'Y' && *pGD <= 200) {
				printf("\tYou have insufficient balance. The merchant has already left.");
				cAvailUpgrade = 'N';
			}
		} while (cAvailUpgrade != 'Y' && cAvailUpgrade != 'N');

		// Run specific logics based on user's choice.
		switch (cAvailUpgrade) {
		case 'Y':
			*pGD -= 200;
			*pCapacity += 50;
			printf("\nSuccessfully upgraded your wheelhouse!\n");
			displayTrading(nDays, *pGD, *pDebt, *pSavings, *pCapacity, *pInventory);
			printf("\nType anything to continue.");
			scanf(" %*s");
			break;
		case 'N':
			printf("\nTransaction declined! Your wheelhouse's capacity remains the same.\n");
			displayTrading(nDays, *pGD, *pDebt, *pSavings, *pCapacity, *pInventory);
			printf("\nType anything to continue.");
			scanf(" %*s");
		}
	}

	// If user has not yet quit the game or ridden the Wheelhouse, continue the day.
	while (cQuitGame == 'N') cQuitGame = continueDay(nTradingPartner, nDays, pGD, pDebt, pSavings, pCapacity, pInventory);

	return cQuitGame;
}

/*
	The main function.
*/
int main() {
	char cQuitGame;
	unsigned int nDays = 15,
		nGD = 2000,
		nDebt = 0,
		nSavings = 0,
		nCapacity = 50,
		nInventory[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	// Display instructions and await user input.
	displayInstructions();
	printf("\n\nOnce you understand the game, please type anything to go to the first kingdom!\n> ");
	scanf(" %*s");

	clearscr();
	
	// Run the game logic. Call startDay() in a loop; 1 loop = 1 day.
	do {
		cQuitGame = startDay(nDays, &nGD, &nDebt, &nSavings, &nCapacity, &nInventory);
		if (cQuitGame != 'Y') {
			nDays--;
			// Run bank's daily interest
			nSavings += nSavings / 10;
			nDebt += nDebt / 20;
		}
	} while (nDays >= 1 && cQuitGame == 'W');

	// Once user quits the game or reaches the 15-day limit, display trading stats and inventory.
	printf("Thank you for playing! Here are your statistics after the game.\n");
	displayTrading(nDays, nGD, nDebt, nSavings, nCapacity, nInventory);
	printf("POST-GAME INVENTORY\n");
	displayWideDivider();
	displayInventory(nInventory, 0);
	printf("\nType anything to end the game.");
	scanf(" %*s");

	return 0;
}