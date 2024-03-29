/*
	Description: Machine Project for CCPROG1
	Programmed by: Joshua C. Permito  S17A
	Last modified: January 26, 2022 @ 8:05 AM
*/

#include <math.h>
#include <time.h>
#include "display.h"

/*
	The function used when the user wants to buy a trading partner's goods and wares.

	@param nDays - The amount of days left.
	@param nTradingPartner - The trading partner.
	@param nCapacity - The capacity of the wheelhouse.
	@param pGD - Pointer to the memory address of the variable holding the amount of Golden Dragons the user has.
	@param fDebt - How much the user owes to the bank.
	@param fSavings - Amount of GDs the user has in the bank.
	@param pInventory - Pointer to the memory address of the variable holding the array of the player inventory.

	@return 1 if user wants to go back, 0 if not.
*/
int buy(int nDays, int nTradingPartner, int nCapacity, float* pGD, float fDebt, float fSavings, int (*pInventory)[8], int nPrices[8]) {
	int nCost, nItem, nAmount, goBack = 0;
	char cChoice = 'N';

	// Display goods, wares, and costs.
	displayWideDivider();
	displayPartnerSales(nTradingPartner, *pInventory, nPrices);
	displayTrading(nDays, *pGD, fDebt, fSavings, nCapacity, *pInventory);

	// Ask user what they want to buy.
	do {
		printf("\nWhat would you like to buy?\n");
		printf("[0] Go Back [1-8] Buy Item\n> ");
		if (scanf(" %d%*[^\n]", &nItem) == 0) {
			nItem = 10;
			scanf(" %*s");
		}

		if (nItem < 0 || nItem > 8) printf("\tInvalid input.");
	} while (nItem < 0 || nItem > 8);

	// Ask user how many they want to buy.
	if (nItem >= 1 && nItem <= 8) do {
		printf("\nHow many would you like to buy?\n> ");
		if (scanf(" %d%*[^\n]", &nAmount) == 0) {
			nAmount = 0;
			scanf(" %*s");
		}

		if (!isnormal(nAmount)) nAmount = 0;

		// Validate user input.
		if (nAmount < 1) printf("\tInvalid input.\n");
		else if (nAmount > nCapacity - (*pInventory)[nItem - 1]) printf("\tBuying %d of this item will exceed your wheelhouse's capacity.\n", nAmount);
	} while (nAmount < 1 || nAmount > nCapacity - (*pInventory)[nItem - 1]);

	if (nItem >= 1 && nItem <= 8) {
		nCost = nPrices[nItem - 1] * nAmount;
		printf("\nThat item costs %d Golden Dragons.", nCost);
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
			printf("\nAborting transaction. Press ENTER to continue.");
			scanf("%*c%*[^\n]");
		}
		else {
			// Subtract the cost from the user GDs, and add 1 of the item they bought to the inventory array.
			*pGD -= nCost;
			(*pInventory)[nItem - 1] += nAmount;

			clearscr();
			printf("Bought item successfully!\n");
			displayWideDivider();
			displayInventory(*pInventory, 0);
			printf("\nPress ENTER to continue.");
			scanf("%*c%*[^\n]");
		}
	}
	else goBack = 1;

	return goBack;
}

/*
	The function used when the user wants to sell their goods and wares to the trading partner.

	@param nDays - The amount of days left.
	@param nTradingPartner - The trading partner.
	@param nCapacity - Capacity of the wheelhouse.
	@param pGD - Pointer to the memory address of the variable holding the amount of Golden Dragons the user has.
	@param fDebt - Debt to the Iron Bank.
	@param fSavings - GDs stored in the Iron Bank.
	@param pInventory - Pointer to the memory address of the variable holding the array of the player inventory.
	@param nPrices - The array of the prices.

	@return 1 if user wants to go back, 0 if not.
*/
int sell(int nDays, int nTradingPartner, int nCapacity, float* pGD, float fDebt, float fSavings, int (*pInventory)[8], int nPrices[8]) {
	int nCost, nAmount, nItem, goBack = 0;
	char cChoice = 'N';

	// Display goods, wares, and costs.
	displayWideDivider();
	displayPartnerSales(nTradingPartner, *pInventory, nPrices);
	displayTrading(nDays, *pGD, fDebt, fSavings, nCapacity, *pInventory);

	// Ask user what they want to sell.
	do {
		printf("What would you like to sell?\n");
		printf("[0] Go Back [1-8] Sell Item\n> ");
		if (scanf(" %d%*[^\n]", &nItem) == 0) {
			nItem = 10;
			scanf(" %*s");
		}

		if (nItem < 0 || nItem > 8) printf("\tInvalid input.\n");
	} while (nItem < 0 || nItem > 8);

	// Ask user how many they want to buy.
	if (nItem >= 1 && nItem <= 8) do {
		printf("\nHow many would you like to sell?\n> ");
		if (scanf(" %d%*[^\n]", &nAmount) == 0) {
			nAmount = 0;
			scanf(" %*s");
		}

		if (!isnormal(nAmount)) nAmount = 0;

		// Validate user input.
		if (nAmount < 1) printf("\tInvalid input.\n");
		else if (nAmount > (*pInventory)[nItem - 1]) printf("\tYou only have %d of that item.\n", (*pInventory)[nItem - 1]);
	} while (nAmount < 0 || nAmount > (*pInventory)[nItem - 1]);

	if (nItem >= 1 && nItem <= 8) {
		nCost = nPrices[nItem - 1] * nAmount;
		printf("\nThe trading partner is willing to trade %d GDs for that item.", nCost);
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
			printf("\nAborting transaction. Press ENTER to continue.");
			scanf("%*c%*[^\n]");
		}
		else {
			// Add the cost of the item to the user's GDs and remove 1 item from the inventory.
			*pGD += nCost;
			(*pInventory)[nItem - 1] -= nAmount;

			clearscr();
			printf("Sold item successfully!\n");
			displayWideDivider();
			displayInventory(*pInventory, 0);
			printf("\nPress ENTER to continue.");
			scanf("%*c%*[^\n]");
		}
	}
	else goBack = 1;

	return goBack;
}

/*
	The function used when the user wants to transact with the Iron Bank of Braavos.

	@param nGD - Pointer to the memory address of the variable holding the amount of Golden Dragons the user has.
	@param nSavings - Pointer to the memory address of the variable holding the user's savings.
	@param nDebt - Pointer to the memory address of the variable holding the user's debt to the bank.

	@return 1 if user wants to go back, 2 if the user wants to quit the game, 0 to continue.
*/
int transactWithBank(float* pGD, float* pDebt, float* pSavings) {
	int goBack = 0;
	char cAction;
	float fAmount;

	displayBankMenu(*pGD, *pSavings, *pDebt);

	// Ask user what they want to do in the bank until they give a valid input.
	do {
		printf("\n> ");
		scanf(" %c%*[^\n]", &cAction);
		
		// Convert lowercase inputs to uppercase.
		switch (cAction) {
		case 'd': cAction = 'D'; break;
		case 'w': cAction = 'W'; break;
		case 'b': cAction = 'B'; break;
		case 'p': cAction = 'P'; break;
		case 'x': cAction = 'X'; break;
		case 'q': cAction = 'Q';
		}

		if (!isValidBankAction(cAction)) printf("\tInvalid input.");

		// Prevent doing action if the user does not have the required resources.
		if (cAction == 'D' && *pGD == 0.0) {
			printf("\tYou have no Golden Dragons.");
			cAction = 0;
		}
		else if (cAction == 'W' && *pSavings == 0.0) {
			printf("\tYou have no Golden Dragons in your savings account.");
			cAction = 0;
		}
		else if (cAction == 'P' && (*pDebt == 0.0 || *pGD == 0.0)) {
			printf("\tYou have no outstanding debt or you have no GDs in your hand.");
			cAction = 0;
		}
	} while (!isValidBankAction(cAction));

	switch (cAction) {
		// For depositing GDs to the Iron Bank.
	case 'D':
		// Ask user how much they want to deposit.
		do {
			printf("\nHow much do you want to deposit?\n> ");
			if (scanf(" %f%*[^\n]", &fAmount) == 0) {
				fAmount = -1.0;
				scanf(" %*s");
			}

			if (!isnormal(fAmount)) fAmount = -1.0;

			// Validate user input.
			if (fAmount < 0.0) printf("\tInvalid input.\n");
			else if (fAmount > *pGD) printf("\tYou do not have that amount of GDs.\n");
		} while (fAmount < 0.0 || fAmount > *pGD);

		// Transfer in-hand GDs to savings account.
		*pSavings += fAmount;
		*pGD -= fAmount;
		printf("Transaction successful!\n");

		printf("\nPress ENTER to continue.");
		scanf("%*c%*[^\n]");
		break;
		// For withdrawing GDs from the Iron Bank.
	case 'W':
		// Ask user how much they want to withdraw.
		do {
			printf("\nHow much do you want to withdraw?\n> ");
			if (scanf(" %f%*[^\n]", &fAmount) == 0) {
				fAmount = -1.0;
				scanf(" %*s");
			}

			if (!isnormal(fAmount)) fAmount = -1.0;

			// Validate user input.
			if (fAmount < 0.0) printf("\tInvalid input.\n");
			else if (fAmount > *pSavings) printf("\tYou do not have that amount of GDs in your savings account.\n");
		} while (fAmount < 0.0 || fAmount > *pSavings);
		
		// Subtract amount from savings and add to in-hand GDs.
		*pGD += fAmount;
		*pSavings -= fAmount;
		printf("Transaction successfull!\n");

		printf("\nPress ENTER to continue.");
		scanf("%*c%*[^\n]");
		break;
		// For borrowing GDs from the Iron Bank.
	case 'B':
		// Ask user how much they want to borrow.
		do {
			printf("\nHow much do you want to borrow?\n> ");
			if (scanf(" %f%*[^\n]", &fAmount) == 0) {
				fAmount = -1.0;
				scanf(" %*s");
			}

			if (!isnormal(fAmount)) fAmount = -1.0;

			// Validate user input.
			if (fAmount < 0.0) printf("\tInvalid input.\n");
		} while (fAmount < 0.0);
		
		// Add the entered amount to their debt and give GDs.
		*pDebt += fAmount;
		*pGD += fAmount;
		printf("Transaction successful!\n");
		
		printf("\nPress ENTER to continue.");
		scanf("%*c%*[^\n]");
		break;
	// For paying debt to the Iron Bank.
	case 'P':
		// Ask user how much of the debt they want to pay.
		do {
			printf("\nHow much debt do you want to pay?\n> ");
			if (scanf(" %f%*[^\n]", &fAmount) == 0) {
				fAmount = -1.0;
				scanf(" %*s");
			}

			if (!isnormal(fAmount)) fAmount = -1.0;

			// Validate user input.
			if (fAmount < 0.0) printf("\tInvalid input.\n");
			else if (fAmount > *pGD) printf("\tYou do not have that amount of money right now.\n");
		} while (fAmount < 0.0 || fAmount > *pGD);

		// Pay all debt if user entered a larger number than their outstanding debt.
		if (fAmount > *pDebt) {
			printf("You only owe %.2f GDs to the bank. Your debt has been automatically paid in full.\n", *pDebt);
			*pGD -= *pDebt;
			*pDebt = 0.0;
		}
		// Pay specified amount of debt.
		else {
			*pDebt -= fAmount;
			*pGD -= fAmount;
			printf("Transaction successful!\n");
		}
		
		printf("\nPress ENTER to continue.");
		scanf("%*c%*[^\n]");
		break;
	case 'X':
		goBack = 1;
		break;
	case 'Q':
		goBack = 2;
	}

	return goBack;
}

/*
	A function to prompt the user to upgrade the wheelhouse.

	@param nDays - The amount of days left.
	@param pGD - Pointer to the golden dragons variable's memory address.
	@param pDebt - Pointer to the debt variable's memory address.
	@param pSavings - Pointer to the savings variable's memory address.
	@param pCapacity - Pointer to the memory address of the variable holding the wheelhouse capacity.
	@param pInventory - Pointer to the memory address of the variable holding the array of the player inventory.
*/
void promptWheelhouseUpgrade(int nDays, float* pGD, float* pDebt, float* pSavings, int* pCapacity, int (*pInventory)[8]) {
	char cAvailUpgrade;

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
		if (cAvailUpgrade == 'Y' && *pGD <= 200.0) {
			printf("\tYou have insufficient balance. The merchant has already left.");
			cAvailUpgrade = 'N';
		}
	} while (cAvailUpgrade != 'Y' && cAvailUpgrade != 'N');

	// Run specific logics based on user's choice.
	switch (cAvailUpgrade) {
	case 'Y':
		*pGD -= 200.0;
		*pCapacity += 50;
		printf("\nSuccessfully upgraded your wheelhouse!\n");
		displayTrading(nDays, *pGD, *pDebt, *pSavings, *pCapacity, *pInventory);
		printf("\nPress ENTER to continue.");
		scanf("%*c%*[^\n]");
		break;
	case 'N':
		printf("\nTransaction declined! Your wheelhouse's capacity remains the same.\n");
		displayTrading(nDays, *pGD, *pDebt, *pSavings, *pCapacity, *pInventory);
		printf("\nPress ENTER to continue.");
		scanf("%*c%*[^\n]");
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
	@param nPrices - The array of the prices of each item.

	@return 'Y' if the user wants to quit the game, 'N' if the day continues, 'W' if the user wants to ride the wheelhouse.
*/
char continueDay(int nTradingPartner, int nDays, float* pGD, float* pDebt, float* pSavings, int* pCapacity, int (*pInventory)[8], int nPrices[8]) {
	int goBack;
	char cAction, cQuitGame = 'N';

	clearscr();

	displayWideDivider();
	displayPartnerSales(nTradingPartner, *pInventory, nPrices);
	displayTrading(nDays, *pGD, *pDebt, *pSavings, *pCapacity, *pInventory);

	printf("What would you like to do?\n");
	printf("\n[B]uy\t[S]ell\t[W]heelhouse\t[I]ron Bank\t[Q]uit\n");

	// Ask for user input until user gives a valid input.
	do {
		printf("\n> ");
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

	// Run specific logics based on the action that want to be done by the user.
	switch (cAction) {
		// Buying items.
	case 'B':
		do {
			clearscr();
			goBack = buy(nDays, nTradingPartner, *pCapacity, pGD, *pDebt, *pSavings, pInventory, nPrices);
		} while (goBack == 0 && arraySummation(*pInventory) < *pCapacity);
		break;
		// Selling items.
	case 'S':
		do {
			clearscr();
			goBack = sell(nDays, nTradingPartner, *pCapacity, pGD, *pDebt, *pSavings, pInventory, nPrices);
		} while (goBack == 0 && arraySummation(*pInventory) > 0);
		break;
		// Going to the iron bank.
	case 'I':
		do {
			clearscr();
			goBack = transactWithBank(pGD, pDebt, pSavings);
		} while (goBack == 0);
		if (goBack == 2) cQuitGame = 'Y';
		break;
		// Riding the wheelhouse.
	case 'W':
		cQuitGame = 'W';
		break;
		// Quitting the game.
	case 'Q':
		cQuitGame = 'Y';
	}

	return cQuitGame;
}

/*
	The function used to start a day in the game. This function runs the continueDay() function as long as the game is in progress.

	@param nDays - The amount of days left.
	@param pGD - Pointer to the golden dragons variable's memory address.
	@param pDebt - Pointer to the debt variable's memory address.
	@param pSavings - Pointer to the savings variable's memory address.
	@param pCapacity - Pointer to the memory address of the variable holding the wheelhouse capacity.
	@param pInventory - Pointer to the memory address of the variable holding the array of the player inventory.

	@return 'W' if the user rode the wheelhouse, 'Y' if the user wants to quit the game.
*/
char startDay(int nDays, float* pGD, float* pDebt, float* pSavings, int* pCapacity, int (*pInventory)[8]) {
	int nTradingPartner,
		nPrices[8];
	char cQuitGame = 'N'; // cQuitGame == 'N' means user has not quit the game (default), otherwise this is 'Y'

	clearscr();

	displayWesterosBanner();
	displayTrading(nDays, *pGD, *pDebt, *pSavings, *pCapacity, *pInventory);
	displayOpeningScreen();

	// Ask for user input once, then if the input is invalid, ask the user for their input again until they give a valid input.
	do {
		printf("\nTyrion and Bronn will go to: ");
		if (scanf(" %d%*[^\n]", &nTradingPartner) == 0) {
			nTradingPartner = 10;
			scanf(" %*s");
		}

		if (!isValidTradingPartner(nTradingPartner)) printf("\tInvalid input.");
	} while (!isValidTradingPartner(nTradingPartner));

	// Since input 9 means quitting the game, assign the character 'Y' to cQuitGame to indicate that the user has quit the game.
	if (nTradingPartner == 9) cQuitGame = 'Y';

	clearscr();

	// If user has not yet quit the game and lucky to meet the merchant for wheelhouse upgrade.
	if (cQuitGame == 'N' && getRandomNumber(1, 100) <= 10) promptWheelhouseUpgrade(nDays, pGD, pDebt, pSavings, pCapacity, pInventory);

	if (cQuitGame == 'N') randomizeCosts(nTradingPartner, &nPrices);

	// If user has not yet quit the game or ridden the Wheelhouse, continue the day.
	while (cQuitGame == 'N') cQuitGame = continueDay(nTradingPartner, nDays, pGD, pDebt, pSavings, pCapacity, pInventory, nPrices);

	return cQuitGame;
}

/*
	A function used to run the game's logic.

	@return 'Y' or 'y' if the user wants to play another game.
*/
char startGame() {
	char cAnotherGame, cQuitGame;
	float fGD = 2000.0,
		fDebt = 0.0,
		fSavings = 0.0;
	int nDays = 15,
		nCapacity = 50,
		nInventory[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	clearscr();

	// Run the game logic. Call startDay() in a loop; 1 loop = 1 day.
	do {
		cQuitGame = startDay(nDays, &fGD, &fDebt, &fSavings, &nCapacity, &nInventory);
		if (cQuitGame != 'Y') {
			nDays--;
			// Run bank's daily interest
			fSavings += fSavings / 10;
			fDebt += fDebt / 20;
		}
	} while (nDays >= 1 && cQuitGame == 'W');

	// Once user quits the game or reaches the 15-day limit, display trading stats and inventory.
	clearscr();
	displayWideDivider();
	printf("\t\t\t _____ _              __          _ \n");
	printf("\t\t\t/__   \\ |__   ___    /__\\ __   __| |\n");
	printf("\t\t\t  / /\\/ '_ \\ / _ \\  /_\\| '_ \\ / _` |\n");
	printf("\t\t\t / /  | | | |  __/ //__| | | | (_| |\n");
	printf("\t\t\t \\/   |_| |_|\\___| \\__/|_| |_|\\__,_|\n");
	displayTrading(nDays, fGD, fDebt, fSavings, nCapacity, nInventory);
	displayInventory(nInventory, 0);
	displayWideDivider();
	printf("\nWell done! Type [Y] if you wish to start another game.\n> ");
	scanf(" %c%*[^\n]", &cAnotherGame);

	return cAnotherGame;
}

/*
	The main function.
*/
int main() {
	char cAnotherGame;

	// Seed the rand() function at program start.
	srand(time(NULL));

	// Display instructions and await user input.
	displayInstructions();
	printf("\n\nOnce you understand the game, press ENTER to go to the first kingdom!");
	scanf("%*[^\n]");
	
	// Start a game. 1 loop = 1 game.
	do cAnotherGame = startGame(); while (cAnotherGame == 'Y' || cAnotherGame == 'y');

	return 0;
}