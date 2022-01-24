#include <stdio.h>
#include "constants.h"
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

	@param nSweetBeet - The price of sweet beet.
	@param nTimber - The price of timber.
	@param nIntricateLace - The price of intricate lace.
	@param nIntoxicatingPerfume - The price of intoxicating perfume.
	@param nPaleAmberWiner - The price of pale amber wine.
	@param nMyrishEye - The price of myrish eye.
	@param nQohorikTapestry - The price of qohorik tapestry.
	@param nValyrianSteel - The price of valyrian steel.
	@param nInventory - The array of the inventory.
*/
void displayWaresAndGoods(int nSweetBeet, int nTimber, int nIntricateLace, int nIntoxicatingPerfume,
						  int nPaleAmberWine, int nMyrishEye, int nQohorikTapestry, int nValyrianSteel,
						  int nInventory[8])
{
	displayWideDivider();
	printf("ITEM\t\tWARES AND GOODS\t\t\tSELLING/BUYING PRICE\t\tOWNED\n");
	displayWideDivider();
	printf("[1]\t\tSweet Beet\t\t\t%d\t\t\t\t%d\n", nSweetBeet, nInventory[0]);
	printf("[2]\t\tTimber\t\t\t\t%d\t\t\t\t%d\n", nTimber, nInventory[1]);
	printf("[3]\t\tIntricate Lace\t\t\t%d\t\t\t\t%d\n", nIntricateLace, nInventory[2]);
	printf("[4]\t\tIntoxicating Perfume\t\t%d\t\t\t\t%d\n", nIntoxicatingPerfume, nInventory[3]);
	printf("[5]\t\tPale Amber Wine\t\t\t%d\t\t\t\t%d\n", nPaleAmberWine, nInventory[4]);
	printf("[6]\t\tMyrish Eye\t\t\t%d\t\t\t\t%d\n", nMyrishEye, nInventory[5]);
	printf("[7]\t\tQohorik Tapestry\t\t%d\t\t\t\t%d\n", nQohorikTapestry, nInventory[6]);
	printf("[8]\t\tValyrian Steel\t\t\t%d\t\t\t\t%d\n", nValyrianSteel, nInventory[7]);
}

/*
	A function used to call displayWaresAndGoods() depending on the trading partner.

	@param nTradingPartner - The trading partner.
	@param nInventory - The array of the inventory.
*/
void displayPartnerSales(int nTradingPartner, int nInventory[8]) {
	switch (nTradingPartner) {
	case 1:
		printf("\t\t    __    __ _       _             __      _ _ \n");
		printf("\t\t   / / /\\ \\ (_)_ __ | |_ ___ _ __ / _| ___| | |\n");
		printf("\t\t   \\ \\/  \\/ / | '_ \\| __/ _ \\ '__| |_ / _ \\ | |\n");
		printf("\t\t    \\  /\\  /| | | | | ||  __/ |  |  _|  __/ | |\n");
		printf("\t\t     \\/  \\/ |_|_| |_|\\__\\___|_|  |_|  \\___|_|_|\n");
		displayWaresAndGoods(
			WINTERFELL_SWEET_BEET, WINTERFELL_TIMBER, WINTERFELL_INTRICATE_LACE, WINTERFELL_INTOXICATING_PERFUME,
			WINTERFELL_PALE_AMBER_WINE, WINTERFELL_MYRISH_EYE, WINTERFELL_QOHORIK_TAPESTRY, WINTERFELL_VALYRIAN_STEEL,
			nInventory
		);
		break;
	case 2:
		printf("   __           \n");
		printf("  / / _   _ ___ \n");
		printf(" / / | | | / __|\n");
		printf("/ /__| |_| \\__ \\\n");
		printf("\\____/\\__, |___/\n");
		printf("      |___/     \n");
		displayWaresAndGoods(
			LYS_SWEET_BEET, LYS_TIMBER, LYS_INTRICATE_LACE, LYS_INTOXICATING_PERFUME,
			LYS_PALE_AMBER_WINE, LYS_MYRISH_EYE, LYS_QOHORIK_TAPESTRY, LYS_VALYRIAN_STEEL,
			nInventory
		);
		break;
	case 3:
		printf("  /\\/\\  _   _ _ __ \n");
		printf(" /    \\| | | | '__|\n");
		printf("/ /\\/\\ \\ |_| | |   \n");
		printf("\\/    \\/\\__, |_|   \n");
		printf("        |___/      \n");
		displayWaresAndGoods(
			MYR_SWEET_BEET, MYR_TIMBER, MYR_INTRICATE_LACE, MYR_INTOXICATING_PERFUME,
			MYR_PALE_AMBER_WINE, MYR_MYRISH_EYE, MYR_QOHORIK_TAPESTRY, MYR_VALYRIAN_STEEL,
			nInventory
		);
		break;
	case 4:
		printf("   ___           _            \n");
		printf("  / _ \\___ _ __ | |_ ___  ___ \n");
		printf(" / /_)/ _ \\ '_ \\| __/ _ \\/ __|\n");
		printf("/ ___/  __/ | | | || (_) \\__ \\\n");
		printf("\\/    \\___|_| |_|\\__\\___/|___/\n");
		displayWaresAndGoods(
			PENTOS_SWEET_BEET, PENTOS_TIMBER, PENTOS_INTRICATE_LACE, PENTOS_INTOXICATING_PERFUME,
			PENTOS_PALE_AMBER_WINE, PENTOS_MYRISH_EYE, PENTOS_QOHORIK_TAPESTRY, PENTOS_VALYRIAN_STEEL,
			nInventory
		);
		break;
	case 5:
		printf("   ____      _                \n");
		printf("  /___ \\___ | |__   ___  _ __ \n");
		printf(" //  / / _ \\| '_ \\ / _ \\| '__|\n");
		printf("/ \\_/ / (_) | | | | (_) | |   \n");
		printf("\\___,_\\\\___/|_| |_|\\___/|_|   \n");
		displayWaresAndGoods(
			QOHOR_SWEET_BEET, QOHOR_TIMBER, QOHOR_INTRICATE_LACE, QOHOR_INTOXICATING_PERFUME,
			QOHOR_PALE_AMBER_WINE, QOHOR_MYRISH_EYE, QOHOR_QOHORIK_TAPESTRY, QOHOR_VALYRIAN_STEEL,
			nInventory
		);
		break;
	case 6:
		printf("             _             _   _     \n");
		printf(" /\\   /\\___ | | __ _ _ __ | |_(_)___ \n");
		printf(" \\ \\ / / _ \\| |/ _` | '_ \\| __| / __|\n");
		printf("  \\ V / (_) | | (_| | | | | |_| \\__ \\\n");
		printf("   \\_/ \\___/|_|\\__,_|_| |_|\\__|_|___/\n");
		displayWaresAndGoods(
			VOLANTIS_SWEET_BEET, VOLANTIS_TIMBER, VOLANTIS_INTRICATE_LACE, VOLANTIS_INTOXICATING_PERFUME,
			VOLANTIS_PALE_AMBER_WINE, VOLANTIS_MYRISH_EYE, VOLANTIS_QOHORIK_TAPESTRY, VOLANTIS_VALYRIAN_STEEL,
			nInventory
		);
	}
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
	printf("[D]eposit GDs\n[W]ithdraw GDs\n[B]orrow GDs\n[P]ay Debt\n\n[X] Go Back\n");
}