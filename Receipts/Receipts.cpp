// Receipts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//variables
//NOAH
double noahTotal = 0;
double noahToLiz = 0;
double noahToChris = 0;

//CHRIS
double chrisTotal = 0;
double chrisToLiz = 0;
double chrisToNoah = 0;

//LIZ
double lizTotal = 0;
double lizToChris = 0;
double lizToNoah = 0;

//OTHER
bool moreReceipts = true;
char moreRec;
char whoPaid;

//function prototypes ???
int noahMath();
int lizMath();
int chrisMath();
double didSomeoneBuy(string name);

int main()
{
    //loops thru math until all receipts are finished with
    do {
        cout << "Who paid this time? (n/l/c) ";
        cin >> whoPaid;
        cout << endl;

        switch (whoPaid) {
        case 'n':
            noahMath();
            break;

        case 'c':
            chrisMath();
            break;

        case 'l':
            lizMath();
            break;

        default:
            cout << "idk who that is, try again" << endl;
            break;
        }

        //ask about more receipts
        cout << "Are there any more receipts? (y/n) ";
        cin >> moreRec;
        cout << endl;
        if (moreRec == 'n') {
            moreReceipts = false;
        }
    } while (moreReceipts);

    //NOAH OUTPUTS
    cout << "NOAH" << endl;
    cout << "Noah total: " << noahTotal << endl;
    cout << "Liz indv owes Noah: " << lizToNoah << endl;
    cout << "Chris indv owes Noah: " << chrisToNoah << endl;
    cout << "IN TOTAL " << endl;
    cout << "Chris owes Noah: " << noahTotal + chrisToNoah << endl;
    cout << "Liz owes Noah: " << noahTotal + lizToNoah << "\n\n" << endl;

    //CHRIS OUTPUTS
    cout << "CHRIS" << endl;
    cout << "Chris total: " << chrisTotal << endl;
    cout << "Liz indv owes Chris: " << lizToChris << endl;
    cout << "Noah indv owes Chris: " << noahToChris << endl;
    cout << "IN TOTAL " << endl;
    cout << "Liz owes Chris: " << chrisTotal + lizToChris << endl;
    cout << "Noah owes Chris: " << chrisTotal + noahToChris << "\n\n" << endl;

    //LIZ OUTPUTS
    cout << "LIZ" << endl;
    cout << "Liz total: " << lizTotal << endl;
    cout << "Noah indv owes Liz: " << noahToLiz << endl;
    cout << "Chris indv owes Liz: " << chrisToLiz << endl;
    cout << "IN TOTAL " << endl;
    cout << "Noah owes Liz: " << lizTotal + noahToLiz << endl;
    cout << "Chris owes Liz: " << lizTotal + chrisToLiz << "\n\n" << endl;

    system("pause");

    return 0;
}

//does math for a Noah receipt
int noahMath() {
    double tmpLizOwe;
    double tmpChrisOwe;
    double noahBought;

    cout << "What was the total for the receipt? ";
    double tmpTotal;
    cin  >> tmpTotal;
    cout << endl;

    //find out how much individual ppl bought
    tmpLizOwe = didSomeoneBuy("Liz");
    tmpChrisOwe = didSomeoneBuy("Chris");
    noahBought = didSomeoneBuy("Noah");

    lizToNoah += tmpLizOwe;
    chrisToNoah += tmpChrisOwe;
    noahTotal += ((tmpTotal - tmpLizOwe - tmpChrisOwe - noahBought) / 3); //add receipt to total after subtracting individual purchases

    return 0;
}


//does math for a Chris receipt
int chrisMath() {
    double tmpLizOwe;
    double tmpNoahOwe;
    double chrisBought;

    cout << "What was the total for the receipt? ";
    double tmpTotal;
    cin >> tmpTotal;
    cout << endl;

    //find out how much individual ppl bought
    tmpLizOwe = didSomeoneBuy("Liz");
    tmpNoahOwe = didSomeoneBuy("Noah");
    chrisBought = didSomeoneBuy("Chris");

    lizToChris += tmpLizOwe;
    noahToChris += tmpNoahOwe;
    chrisTotal += ((tmpTotal - tmpLizOwe - tmpNoahOwe - chrisBought) / 3); //add receipt to total after subtracting individual purchases

    return 0;
}

//does math for a Liz receipt
int lizMath() {
    double tmpChrisOwe;
    double tmpNoahOwe;
    double lizBought;

    cout << "What was the total for the receipt? ";
    double tmpTotal;
    cin >> tmpTotal;
    cout << endl;

    //find out how much individual ppl bought
    tmpChrisOwe = didSomeoneBuy("Chris");
    tmpNoahOwe = didSomeoneBuy("Noah");
    lizBought = didSomeoneBuy("Liz");

    chrisToLiz += tmpChrisOwe;
    noahToLiz += tmpNoahOwe;
    lizTotal += ((tmpTotal - tmpChrisOwe - tmpNoahOwe - lizBought) / 3); //add receipt to total after subtracting individual purchases


    return 0;
}

double didSomeoneBuy(string name) {
    double tmpTotal = 0.0;
    bool buy = false;

    cout << "Did " << name << " buy anything? (y/n) ";
    char yn;
    cin >> yn;
    cout << endl;
    if (yn == 'y') {
        buy = true;
    }
    while (buy) {
        cout << "How much was the thing? "; //get price of thing
        double price;
        cin  >> price;
        cout << endl;
        tmpTotal += price; //add price to total spent

        cout << "Did " << name << " buy anything else? (y/n) "; //check if they bought more shit
        cin >> yn;
        cout << endl;
        if (yn == 'n') {
            buy = false;
        }
    }

    tmpTotal += (tmpTotal * .078); //calculate tax

    return tmpTotal; 
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
