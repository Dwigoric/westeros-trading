#include <stdlib.h>
#include <time.h>

/*
	This function determines whether a merchant shows up to prompt user to increase capacity of wheelhouse by 50.

	@return 1 if merchant shows up, otherwise 0.
*/
int allowWheelhouseUpgrade() {
	int willAllowUpgrade = 0;

	// To avoid predictability of results, the rand() function is seeded every run.
	srand(time(NULL));
	if (rand() % 100 <= 9) willAllowUpgrade = 1;

	return willAllowUpgrade;
}

/*
	Function to get summation of an integer array with 8 values.

	@param nArray - The array of integers with 8 values.
*/
int arraySummation(int nArray[8]) {
	int sum = 0;
	for (int n = 0; n < 8; n++) sum += nArray[n]; // Since arrays start at index 0, the array is looped from 0-7.
	return sum;
}

/*
	Determines whether the item is on sale.

	@param nIndex - The inventory array-based index of the item.
	@param nPrice - The price of the item.

	@return 1 if the item is in sale, otherwise 0 if not.
*/
int isSpecialPrice(int nIndex, int nPrice) {
	int nSale = 0;

	// Depending on the nIndex which corresponds to the item, determine if the price is in the special price range.
	switch (nIndex) {
	case 0:
		if (nPrice >= 100 && nPrice <= 150) nSale = 1;
		break;
	case 1:
		if (nPrice >= 200 && nPrice <= 250) nSale = 1;
		break;
	case 2:
		if (nPrice >= 300 && nPrice <= 350) nSale = 1;
		break;
	case 3:
		if (nPrice >= 400 && nPrice <= 450) nSale = 1;
		break;
	case 4:
		if (nPrice >= 500 && nPrice <= 550) nSale = 1;
		break;
	case 5:
		if (nPrice >= 600 && nPrice <= 650) nSale = 1;
		break;
	case 6:
		if (nPrice >= 700 && nPrice <= 750) nSale = 1;
		break;
	case 7:
		if (nPrice >= 800 && nPrice <= 850) nSale = 1;
		break;
	}

	return nSale;
}


/*
	A function that determines validity of the trading partner.

	@param nTradingPartner - The trading partner as numbered form.

	@return 1 if the trading partner is valid, otherwise 0.
*/
int isValidTradingPartner(int nTradingPartner) {
	int nValid = 0;

	if (nTradingPartner >= 1 && nTradingPartner <= 6 || nTradingPartner == 9) nValid = 1; // 1-6 are trading partners; 9 is quitting the game

	return nValid;
}

/*
	A function that determines the validity of the user's action.

	@param cAction - The action chose by the user.

	@return 1 if the action is valid, otherwise 0.
*/
int isValidAction(int cAction) {
	int nValid;

	// B = buy, S = sell, W = wheelhouse, I = bank, Q = quit
	switch (cAction) {
	case 'B':
	case 'S':
	case 'W':
	case 'I':
	case 'Q':
		nValid = 1;
		break;
	default:
		nValid = 0;
	}

	return nValid;
}

/*
	A function that determines the validity of the user's action in the Iron Bank of Braavos.

	@param cAction - The action chose by the user.

	@return 1 if the action is valid, otherwise 0.
*/
int isValidBankAction(char cAction) {
	int nValid;

	// D = deposit, W = withdraw, B = borrow, P = pay debt, X = go back
	switch (cAction) {
	case 'D':
	case 'W':
	case 'B':
	case 'P':
	case 'X':
		nValid = 1;
		break;
	default:
		nValid = 0;
	}

	return nValid;
}

/*
	Function for retrieving the cost of an item depending on the trading partner.

	@param nTradingPartner - The trading partner.
	@param nItem - The item to get the cost of.
	@param nAmount - Amount of items.

	@return The cost of the item. If one of the parameters is invalid, the returned value is 0.
*/
int getCost(int nTradingPartner, int nItem, int nAmount) {
	int nCost = 0;

	// Subtract 1 from nItem since it will be used as the array index.
	nItem -= 1;

	// Use arrays for easier reference.
	int
	nWinterfell[8] = {
		WINTERFELL_SWEET_BEET,
		WINTERFELL_TIMBER,
		WINTERFELL_INTRICATE_LACE,
		WINTERFELL_INTOXICATING_PERFUME,
		WINTERFELL_PALE_AMBER_WINE,
		WINTERFELL_MYRISH_EYE,
		WINTERFELL_QOHORIK_TAPESTRY,
		WINTERFELL_VALYRIAN_STEEL
	},
	nLys[8] = {
		LYS_SWEET_BEET,
		LYS_TIMBER,
		LYS_INTRICATE_LACE,
		LYS_INTOXICATING_PERFUME,
		LYS_PALE_AMBER_WINE,
		LYS_MYRISH_EYE,
		LYS_QOHORIK_TAPESTRY,
		LYS_VALYRIAN_STEEL
	},
	nMyr[8] = {
		MYR_SWEET_BEET,
		MYR_TIMBER,
		MYR_INTRICATE_LACE,
		MYR_INTOXICATING_PERFUME,
		MYR_PALE_AMBER_WINE,
		MYR_MYRISH_EYE,
		MYR_QOHORIK_TAPESTRY,
		MYR_VALYRIAN_STEEL
	},
	nPentos[8] = {
		PENTOS_SWEET_BEET,
		PENTOS_TIMBER,
		PENTOS_INTRICATE_LACE,
		PENTOS_INTOXICATING_PERFUME,
		PENTOS_PALE_AMBER_WINE,
		PENTOS_MYRISH_EYE,
		PENTOS_QOHORIK_TAPESTRY,
		PENTOS_VALYRIAN_STEEL
	},
	nQohor[8] = {
		QOHOR_SWEET_BEET,
		QOHOR_TIMBER,
		QOHOR_INTRICATE_LACE,
		QOHOR_INTOXICATING_PERFUME,
		QOHOR_PALE_AMBER_WINE,
		QOHOR_MYRISH_EYE,
		QOHOR_QOHORIK_TAPESTRY,
		QOHOR_VALYRIAN_STEEL
	},
	nVolantis[8] = {
		VOLANTIS_SWEET_BEET,
		VOLANTIS_TIMBER,
		VOLANTIS_INTRICATE_LACE,
		VOLANTIS_INTOXICATING_PERFUME,
		VOLANTIS_PALE_AMBER_WINE,
		VOLANTIS_MYRISH_EYE,
		VOLANTIS_QOHORIK_TAPESTRY,
		VOLANTIS_VALYRIAN_STEEL
	};

	switch (nTradingPartner) {
	case 1: nCost = nWinterfell[nItem]; break;
	case 2: nCost = nLys[nItem]; break;
	case 3: nCost = nMyr[nItem]; break;
	case 4: nCost = nPentos[nItem]; break;
	case 5: nCost = nQohor[nItem]; break;
	case 6: nCost = nVolantis[nItem]; break;
	}

	return nCost * nAmount;
}