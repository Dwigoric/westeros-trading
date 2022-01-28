#include <stdio.h>
#include "sublogic.h"

/*
	A function to clear the console.
*/
void clearscr() {
#ifdef _WIN32
	// Run this system command on Windows systems.
	system("cls");
#else
	// On other systems, run this system command.
	system("clear");
#endif
}

/*
	A function used to display equal signs in order to form a divider.
*/
void displayWideDivider() {
	// A for-loop is used to print a divider using equal signs.
	for (char i = 1; i <= 85; i++) printf("=");

	printf("\n");
}

/*
	A function used to display the banner of Westeros.
*/
void displayWesterosBanner() {
	printf(" ___       __   _______   ________  _________  _______   ________  ________  ________  \n");
	printf("|\\  \\     |\\  \\|\\  ___ \\ |\\   ____\\|\\___   ___\\\\  ___ \\ |\\   __  \\|\\   __  \\|\\   ____\\ \n");
	printf("\\ \\  \\    \\ \\  \\ \\   __/|\\ \\  \\___|\\|___ \\  \\_\\ \\   __/|\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\___|_    \n");
	printf(" \\ \\  \\  __\\ \\  \\ \\  \\_|/_\\ \\_____  \\   \\ \\  \\ \\ \\  \\_|/_\\ \\   _  _\\ \\  \\\\\\  \\ \\_____  \\   \n");
	printf("  \\ \\  \\|\\__\\_\\  \\ \\  \\_|\\ \\|____|\\  \\   \\ \\  \\ \\ \\  \\_|\\ \\ \\  \\\\  \\\\ \\  \\\\\\  \\|____|\\  \\  \n");
	printf("   \\ \\____________\\ \\_______\\____\\_\\  \\   \\ \\__\\ \\ \\_______\\ \\__\\\\ _\\\\ \\_______\\____\\_\\  \\ \n");
	printf("    \\|____________|\\|_______|\\_________\\   \\|__|  \\|_______|\\|__|\\|__|\\|_______|\\_________\\\n");
	printf("                            \\|_________|                                       \\|_________|\n\n");
}

/*
	A function used to explain to the user how the game works.
*/
void displayInstructions() {
	displayWesterosBanner();
	printf("\nAfter being handed the Iron Throne, King Bran of House Stark, decided to devise a\n");
	printf("strategic plan to improve the economic growth of the Six Kingdoms. The Royal Treasury\n");
	printf("currently has 2,000 Golden Dragons (GDs) only. To accomplish this task, he instructed\n");
	printf("his Hand, Lord Tyrion Lannister, and his Master of Coin, Lord Bronn of the Blackwater\n");
	printf("to go to trade with other kingdoms in Westeros and other free cities in Essos. Various\n");
	printf("trading partners are shown in the sample opening screen of the game.\n\n");
	printf("Each trading partner in The Known World sells a common set of wares and goods. These\n");
	printf("items can be traded (bought or sold). When in another kingdom, you have the option to\n");
	printf("buy their wares and goods, or sell what you have. You can also access the Iron Bank of\n");
	printf("Braavos in any kingdom. The buying and selling of wares and goods in each trading partner\n");
	printf("varies. Each trading partner has a special item which they trade for a special price\n(lower).\n\n");
	printf("Lord Hand Tyrion and Lord Master Bronn (you) have only 15 days to go around and accumulate\n");
	printf("wealth for The Royal Treasury. Tyrion and Bronn can travel from place to place using the\n");
	printf("wheelhouse. Every time they travel using the wheelhouse, they lose 1 day.\n\n");
	printf("The wheelhouse also has enough storage to store up to 50 wares and goods. When they\n");
	printf("visit another trading partner, they may randomly meet a merchant to increase the capacity\n");
	printf("of the wheelhouse by 50 which costs 200 GD. The merchant appears in any trading partner\n");
	printf("10%% of the time.\n\n");
	printf("The Iron Bank of Braavos is the most powerful bank in The Known World. King Bran instructed\n");
	printf("Lord Hand Tyrion and Lord Master Bronn to transact with the Iron Bank of Braavos whenever\n");
	printf("needed. They may deposit GDs to gain interest. They may also get a loan to increase their\n");
	printf("trading power. The bank has a branch in every trading partner; thus, they can drop by anytime\n");
	printf("without missing a day. In the bank, they can:\n");
	printf("\t1. Deposit GDs\n\t2. Withdraw GDs.\n\t3. Get a loan\n\t4. Pay back debt\n");
	printf("The bank gives daily interest of 10%% to its clients. At the start, the account of The\n");
	printf("Royal Treasury has 0 GDs. Additionally, loans also have interests. For The Iron Bank\n");
	printf("of Braavos, the daily interest is 5%%.\n\n");
	printf("\t\t\t     vvvvvvvv\n");
	printf("\t\t\t>>> SCROLL UP! <<<\n");
	printf("\t\t\t     ^^^^^^^^");
}

/*
	A function used to display the opening screen.
*/
void displayOpeningScreen() {
	printf("Where would you like to go?\n\n");
	printf("\t[1] Winterfell\n");
	printf("\t[2] Lys\n");
	printf("\t[3] Myr\n");
	printf("\t[4] Pentos\n");
	printf("\t[5] Qohor\n");
	printf("\t[6] Volantis\n");
	printf("\n\t[9] Quit\n");
}

/*
	A function used to display the wares, goods, and the prices of items for sale.

	@param nTradingPartner - The trading partner.
	@param nInventory - The array of the inventory.
	@param nPrices - The array of the prices.
*/
void displayWaresAndGoods(int nTradingPartner, int nInventory[8], int nPrices[8])
{
	displayWideDivider();
	printf("ITEM\t\tWARES AND GOODS\t\t\tSELLING/BUYING PRICE\t\tOWNED\n");
	displayWideDivider();

	char onSale[2][9] = { "\t", "[!] SALE" };

	// Display prices of each item and how much the user owns per item. Displays whether the item price is special.
	printf("[1]\t\tSweet Beet\t\t\t%d %s\t\t\t%d\n", nPrices[0], onSale[isSpecialPrice(nTradingPartner, 0)], nInventory[0]);
	printf("[2]\t\tTimber\t\t\t\t%d %s\t\t\t%d\n", nPrices[1], onSale[isSpecialPrice(nTradingPartner, 1)], nInventory[1]);
	printf("[3]\t\tIntricate Lace\t\t\t%d %s\t\t\t%d\n", nPrices[2], onSale[isSpecialPrice(nTradingPartner, 2)], nInventory[2]);
	printf("[4]\t\tIntoxicating Perfume\t\t%d %s\t\t\t%d\n", nPrices[3], onSale[isSpecialPrice(nTradingPartner, 3)], nInventory[3]);
	printf("[5]\t\tPale Amber Wine\t\t\t%d %s\t\t\t%d\n", nPrices[4], onSale[isSpecialPrice(nTradingPartner, 4)], nInventory[4]);
	printf("[6]\t\tMyrish Eye\t\t\t%d %s\t\t\t%d\n", nPrices[5], onSale[isSpecialPrice(nTradingPartner, 5)], nInventory[5]);
	printf("[7]\t\tQohorik Tapestry\t\t%d %s\t\t\t%d\n", nPrices[6], onSale[isSpecialPrice(nTradingPartner, 6)], nInventory[6]);
	printf("[8]\t\tValyrian Steel\t\t\t%d %s\t\t\t%d\n", nPrices[7], onSale[isSpecialPrice(nTradingPartner, 7)], nInventory[7]);
}

/*
	A function used to call displayWaresAndGoods() depending on the trading partner.

	@param nTradingPartner - The trading partner.
	@param nInventory - The array of the inventory.
	@param nPrices - The array of the prices.
*/
void displayPartnerSales(int nTradingPartner, int nInventory[8], int nPrices[8]) {
	switch (nTradingPartner) {
	case 1:
		printf("\t\t    __    __ _       _             __      _ _ \n");
		printf("\t\t   / / /\\ \\ (_)_ __ | |_ ___ _ __ / _| ___| | |\n");
		printf("\t\t   \\ \\/  \\/ / | '_ \\| __/ _ \\ '__| |_ / _ \\ | |\n");
		printf("\t\t    \\  /\\  /| | | | | ||  __/ |  |  _|  __/ | |\n");
		printf("\t\t     \\/  \\/ |_|_| |_|\\__\\___|_|  |_|  \\___|_|_|\n");
		break;
	case 2:
		printf("\t\t\t\t   __           \n");
		printf("\t\t\t\t  / / _   _ ___ \n");
		printf("\t\t\t\t / / | | | / __|\n");
		printf("\t\t\t\t/ /__| |_| \\__ \\\n");
		printf("\t\t\t\t\\____/\\__, |___/\n");
		printf("\t\t\t\t      |___/     \n");
		break;
	case 3:
		printf("\t\t\t\t  /\\/\\  _   _ _ __ \n");
		printf("\t\t\t\t /    \\| | | | '__|\n");
		printf("\t\t\t\t/ /\\/\\ \\ |_| | |   \n");
		printf("\t\t\t\t\\/    \\/\\__, |_|   \n");
		printf("\t\t\t\t        |___/      \n");
		break;
	case 4:
		printf("\t\t\t     ___           _            \n");
		printf("\t\t\t    / _ \\___ _ __ | |_ ___  ___ \n");
		printf("\t\t\t   / /_)/ _ \\ '_ \\| __/ _ \\/ __|\n");
		printf("\t\t\t  / ___/  __/ | | | || (_) \\__ \\\n");
		printf("\t\t\t  \\/    \\___|_| |_|\\__\\___/|___/\n");
		break;
	case 5:
		printf("\t\t\t     ____      _                \n");
		printf("\t\t\t    /___ \\___ | |__   ___  _ __ \n");
		printf("\t\t\t   //  / / _ \\| '_ \\ / _ \\| '__|\n");
		printf("\t\t\t  / \\_/ / (_) | | | | (_) | |   \n");
		printf("\t\t\t  \\___,_\\\\___/|_| |_|\\___/|_|   \n");
		break;
	case 6:
		printf("\t\t\t             _             _   _     \n");
		printf("\t\t\t /\\   /\\___ | | __ _ _ __ | |_(_)___ \n");
		printf("\t\t\t \\ \\ / / _ \\| |/ _` | '_ \\| __| / __|\n");
		printf("\t\t\t  \\ V / (_) | | (_| | | | | |_| \\__ \\\n");
		printf("\t\t\t   \\_/ \\___/|_|\\__,_|_| |_|\\__|_|___/\n");
	}

	displayWaresAndGoods(nTradingPartner, nInventory, nPrices);
}

/*
	Displays the current status of trading of the user.

	@param nDays - The amount of days left.
	@param fGD - The amount of golden dragons the user has.
	@param fDebt - The amount of debt, in GD, to the Iron Bank of Braavos.
	@param fSavings - Savings, in GD, in the Iron Bank of Braavos.
	@param nCapacity - Maximum capacity of the wheelhouse.
	@param nInventory - The array of goods in the wheelhouse.
*/
void displayTrading(int nDays, float fGD, float fDebt, float fSavings, int nCapacity, int nInventory[8]) {
	displayWideDivider();
	printf("Days Remaining:\t\t%d Days\n", nDays);
	printf("GD:\t\t\t%.2f\n", fGD);
	printf("Debt:\t\t\t%.2f\n", fDebt);
	printf("Savings:\t\t%.2f\n", fSavings);
	printf("Capacity:\t\t%d / %d\n", arraySummation(nInventory), nCapacity);
	displayWideDivider();
}

/*
	Used to display the inventory of the goods and wares stored in the wheelhouse.

	@param nInventory - The array holding the player inventory.
	@param nFilter - Whether to filter to list what the wheelhouse contains.
*/
void displayInventory(int nInventory[8], int nFilter) {
	printf("\t\t\t\tWHEELHOUSE INVENTORY\n");
	displayWideDivider();
	if (!nFilter || nInventory[0] > 0) printf("[1] Sweet Beet\t\t\t%d\n", nInventory[0]);
	if (!nFilter || nInventory[1] > 0) printf("[2] Timber\t\t\t%d\n", nInventory[1]);
	if (!nFilter || nInventory[2] > 0) printf("[3] Intricate Lace\t\t%d\n", nInventory[2]);
	if (!nFilter || nInventory[3] > 0) printf("[4] Intoxicating Perfume\t%d\n", nInventory[3]);
	if (!nFilter || nInventory[4] > 0) printf("[5] Pale Amber Wine\t\t%d\n", nInventory[4]);
	if (!nFilter || nInventory[5] > 0) printf("[6] Myrish Eye\t\t\t%d\n", nInventory[5]);
	if (!nFilter || nInventory[6] > 0) printf("[7] Qohorik Tapestry\t\t%d\n", nInventory[6]);
	if (!nFilter || nInventory[7] > 0) printf("[8] Valyrian Steel\t\t%d\n", nInventory[7]);
}

/*
	Function used to display the menu screen of the Iron Bank of Braavos.

	@param fGD - Amount of GDs user has.
	@param fSavings - Amount of GDs in user's savings account.
	@param fDebt - How much GDs user owes the Bank.
*/
void displayBankMenu(float fGD, float fSavings, float fDebt) {
	displayWideDivider();
	printf("\t\t  _____                     ___             _    \n");
	printf("\t\t  \\_   \\_ __ ___  _ __     / __\\ __ _ _ __ | | __\n");
	printf("\t\t   / /\\/ '__/ _ \\| '_ \\   /__\\/// _` | '_ \\| |/ /\n");
	printf("\t\t/\\/ /_ | | | (_) | | | | / \\/  \\ (_| | | | |   < \n");
	printf("\t\t\\____/ |_|  \\___/|_| |_| \\_____/\\__,_|_| |_|_|\\_\\\n");
	displayWideDivider();
	printf("Welcome to the Iron Bank of Braavos! How can we help you today?\n");
	displayWideDivider();
	printf("You have the following financial status:\n\n");
	printf("Golden Dragons\t\t%.2f\n", fGD);
	printf("Savings\t\t\t%.2f\n", fSavings);
	printf("Debt\t\t\t%.2f\n", fDebt);
	displayWideDivider();
	printf("[D]eposit GDs\n[W]ithdraw GDs\n[B]orrow GDs\n[P]ay Debt\n[Q]uit Game\n\n[X] Go Back\n");
}