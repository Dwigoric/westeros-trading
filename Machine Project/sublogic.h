#include <stdlib.h>
#include <time.h>

/*
	This function generates a random number within a given range.

	@param nNum1 - The first number of the range.
	@param nNum2 - The second number of the range.

	@return A random number between the two numbers, inclusively.
*/
int getRandomNumber(int nNum1, int nNum2) {
	int nDiff, nRandNum;

	if (nNum1 == nNum2) nRandNum = nNum1;
	// In case the range is from high to low, interchange the numbers.
	else if (nNum1 > nNum2) {
		nDiff = nNum1 - nNum2;
		nNum1 -= nDiff;
		nNum2 += nDiff;
	}
	else nDiff = nNum2 - nNum1;

	if (nNum1 != nNum2) nRandNum = rand() % (nDiff + 1) + nNum1;

	return nRandNum;
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

	@param nTradingPartner - The trading partner.
	@param nItem - The item index on the inventory array.

	@return 1 if the item is in sale, otherwise 0 if not.
*/
int isSpecialPrice(int nTradingPartner, int nItem) {
	int nSale = 0;

	// Depending on the trading partner, determine if the item is in the special price range.
	switch (nTradingPartner) {
	case 1:
		if (nItem == 1) nSale = 1;
		break;
	case 2:
		if (nItem == 3) nSale = 1;
		break;
	case 3:
		if (nItem == 2 || nItem == 5) nSale = 1;
		break;
	case 4:
		if (nItem == 4) nSale = 1;
		break;
	case 5:
		if (nItem >= 6 && nItem <= 7) nSale = 1;
		break;
	case 6:
		if (nItem == 0) nSale = 1;
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
	This function randomizes the costs for each item.

	@param nTradingPartner - The trading partner.
	@param pPrices - The pointer to the array of prices.
*/
void randomizeCosts(int nTradingPartner, int (*pPrices)[8]) {
	int nCounter = 0;

	while (nCounter < 8) {
		(*pPrices)[nCounter] = (nCounter + 1) * 100;
		if (isSpecialPrice(nTradingPartner, nCounter)) (*pPrices)[nCounter] += getRandomNumber(0, 50);
		else (*pPrices)[nCounter] += getRandomNumber(80, 100);
		nCounter++;
	}
}