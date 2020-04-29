#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;


class Stock {

private:
    // Member variables
    string ticker;
    int volume;
    double openingPrice;
    double closingPrice;
    double buyPrice;

public:
    // Member functions
    void setStockData(string sTicker, int sVolume, double sOpen, double sClose, double sBuy) {
        ticker = sTicker;
        volume = sVolume;
        openingPrice = sOpen;
        closingPrice = sClose;
        buyPrice = sBuy;
    }
    // Constructers
    Stock() {
        setTicker(" ");
        setVolume(1);
        setOpeningPrice(0.01);
        setClosingPrice(0.01);
        setBuyPrice(0.01);
    }

    Stock(string sTicker, int sVolume, double sOpen, double sClose, double sBuy) {
        ticker = sTicker;
        volume = sVolume;
        openingPrice = sOpen;
        closingPrice = sClose;
        buyPrice = sBuy;
    }
    // Mutators
    void setTicker(string sTicker) {
        if (sTicker.length() > 5) {
            cout << "ERROR: Symbol must be no more than 5 characters. TRY AGAIN" << endl;
            //ticker = " ";
            system("pause");
            exit(EXIT_FAILURE);
        }
        else {
            ticker = sTicker;
        }

    }
    void setVolume(int sVolume) {
        if (sVolume > 0) {
            volume = sVolume;
        }
        else {
            cout << "ERROR: Volume must be greater than 0. TRY AGAIN" << endl;
            //sVolume = 0;
            system("pause");
            exit(EXIT_FAILURE);

        }
    }
    void setOpeningPrice(double sOpen) {
        if (sOpen > 0) {
            openingPrice = sOpen;

        }
        else {
            cout << "ERROR: Opening Price must be greater than 0. TRY AGAIN" << endl;
            sOpen = 0;
            system("pause");
            exit(EXIT_FAILURE);
        }
    }
    void setClosingPrice(double sClose) {
        if (sClose > 0) {
            closingPrice = sClose;

        }
        else {
            cout << "ERROR: Closing Price must be greater than 0. TRY AGAIN" << endl;
            sClose = 0;
            system("pause");
            exit(EXIT_FAILURE);
        }
    }
    void setBuyPrice(double sBuy) {
        if (sBuy > 0) {
            buyPrice = sBuy;

        }
        else {
            cout << "ERROR: Buying Price must be greater than 0. TRY AGAIN" << endl;
            sBuy = 0;
            system("pause");
            exit(EXIT_FAILURE);
        }
    }

    // Accessors
    string getTicker() {
        return ticker;
    }
    int getVolume() {
        return volume;
    }

    double getOpeningPrice() {
        return openingPrice;
    }

    double getClosingPrice() {
        return closingPrice;
    }

    double getBuyPrice() {
        return buyPrice;
    }
    double getH() {
        return volume * buyPrice;
    }
    double getHMO() {
        return volume * openingPrice;
    }
    double getHMC() {
        return volume * closingPrice;
    }
};





int main()
{
    cout << "**********STOCK PORTFOLIO MANAGEMENT SYSTEM 2.0**********" << endl;

    // Stock Array
    const int Num_Stocks = 5;
    Stock stock[Num_Stocks];


    //Loop for entering data for 5 stocks
    for (int i = 0; i < Num_Stocks; i++) {

        string symbol;
        cout << "What is the Symbol? ";
        cin >> symbol;

        int volume;
        cout << "At what volume? ";
        cin >> volume;

        double openingPrice;
        cout << "What is the opening price? ";
        cin >> openingPrice;

        double closingPrice;
        cout << "What is the closing price? ";
        cin >> closingPrice;

        double buyPrice;
        cout << "What is the buying price? ";
        cin >> buyPrice;


        stock[i].setTicker(symbol);
        stock[i].setVolume(volume);
        stock[i].setOpeningPrice(openingPrice);
        stock[i].setClosingPrice(closingPrice);
        stock[i].setBuyPrice(buyPrice);
    }

    // Loop to calculate H,HMO,HMC
    for (int x = 0; x < 5; x++) {
        cout << "SYM = " << stock[x].getTicker() << ",";
        cout << " H = $" << stock[x].getH() << ",";
        cout << " HMO = $" << stock[x].getHMO() << ",";
        cout << " HMC = $" << stock[x].getHMC() << endl;
    }

    // Intializing Totals
    double totalH = 0.0;
    double totalMO = 0.0;
    double totalMC = 0.0;

    // Loop to calculate Total Holdings of all stocks
    for (int x = 0; x < 5; x++) {
        totalH += stock[x].getH();
        totalMO += stock[x].getHMO();
        totalMC += stock[x].getHMC();
    }
    cout << "Total H : $" << totalH << endl;
    cout << "Total HMO : $" << totalMO << endl;
    cout << "Total HMC : $" << totalMC << endl;

    system("pause");
    return 0;
}

