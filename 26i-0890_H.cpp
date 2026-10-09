#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {

  int question;

  cout << "Enter the Question number ( 1 to 8 ) to play: ";
  cin >> question;

  switch (question) {

  case 1: {
    char type;
    int game, timeLeft, guardAlert, injuries, lightsOn, cameras, takeNeedles,
        needles, takeBandages, bandages, takeMarbles, marbles, takeRope, ropeM,
        packKg, stamina, playersLeft, bet, stake, favor, cash, debt, card, ally;

    int Needle = 150, Bandage = 350, Marble = 60, Rope = 120;
    int NeedleCost = 0, MarbleCost = 0, BandageCost = 0, RopeCost = 0;

    cout << "Enter the type of character you are ( A for Athlete, T for "
            "Thinker, G for Gambler ): ";
    cin >> type;
    (type == 'A') ? (Rope = 100)
                  : ((type == 'T') ? (Needle = 120) : (Marble = 45));
    cout << "Select the game \n 1 = Red Light Green Light\n 2 = Honeycomb\n 3 "
            "= Tug of War\n 4 = Marbles\n 5 = Glass Bridge\n ";
    cin >> game;
    cout << "Enter the time left until the starting of the game in minutes "
            "(0-120): ";
    cin >> timeLeft;
    cout << "Enter the guard alert (0-100): ";
    cin >> guardAlert;
    cout << "What are the injuries (0-3): ";
    cin >> injuries;
    cout << "Are the lights on: \n 1 for on \n 0 for off\n ";
    cin >> lightsOn;
    cout << "State of VIP cameras: \n 1 for active \n 0 for not active\n ";
    cin >> cameras;
    cout << "Will you take needles ( 0 for no , 1 for yes ): ";
    cin >> takeNeedles;
    cout << "What is the number of needles (0-40): ";
    cin >> needles;
    cout << "Will you take bandages ( 0 for no , 1 for yes ): ";
    cin >> takeBandages;
    cout << "Enter the number of bandages (0-30): ";
    cin >> bandages;
    cout << "Will you take marbles ( 0 for no , 1 for yes ): ";
    cin >> takeMarbles;
    cout << "Enter the number of marbles (0-100): ";
    cin >> marbles;
    cout << "Will you take the rope ( 0 for no , 1 for yes ): ";
    cin >> takeRope;
    cout << "Enter the length of the rope in metres (0-60): ";
    cin >> ropeM;
    cout << "What is the weight you carry in kg (0-150): ";
    cin >> packKg;
    cout << "Enter your stamina (0-100): ";
    cin >> stamina;
    cout << "Enter the players left (2-456): ";
    cin >> playersLeft;
    cout << "What do you bet \n 0 = No bet\n 1 = SAFE \n 2 = RISKY \n ";
    cin >> bet;
    (bet != 0) && (cout << "Enter your stake (0-2000): ", cin >> stake);
    cout << "Do you have a favor \n 0 = None\n 1 = INSIDER\n 2 = HUSH\n 3 = "
            "MEDPASS\n ";
    cin >> favor;
    cout << "Enter the cash you have (0-6000): ";
    cin >> cash;
    cout << "Enter your debt (0-3000): ";
    cin >> debt;
    cout << "Do you have an invitation card ( 0 for no , 1 for yes ): ";
    cin >> card;
    cout << "Do you have an ally ( 0 for no , 1 for yes ): ";
    cin >> ally;

    int discountedNeedlePrice = (Needle * 75) / 100;
    int discountedMarblePrice = (Marble * 50) / 100;
    takeNeedles ? (NeedleCost =
                       (10 * Needle) + ((needles - 10) * discountedNeedlePrice))
                : (NeedleCost = 0);
    takeMarbles ? (MarbleCost =
                       (50 * Marble) + ((marbles - 50) * discountedMarblePrice))
                : (MarbleCost = 0);
    takeBandages ? (BandageCost = Bandage * (bandages - bandages / 3))
                 : (BandageCost = 0);
    takeRope ? (RopeCost = ropeM * Rope) : (RopeCost = 0);

    int alertAdj = guardAlert;
    takeMarbles ? (alertAdj += marbles / 5) : 0;
    takeRope ? (alertAdj += ropeM / 3) : 0;
    lightsOn && (alertAdj += 10);
    cameras && (alertAdj += 5);
    (alertAdj > 100) && (alertAdj = 100);

    int dangerPoints = 0;
    (playersLeft > 300)
        ? (dangerPoints += 3)
        : ((playersLeft > 150)
               ? (dangerPoints += 2)
               : ((playersLeft > 50) ? (dangerPoints += 1) : 0));
    (alertAdj >= 70) ? (dangerPoints += 2)
                     : ((alertAdj >= 40) ? (dangerPoints += 1) : 0);
    (game >= 4) ? (dangerPoints += 2) : ((game >= 2) ? (dangerPoints += 1) : 0);
    cameras && (dangerPoints += 1);
    !lightsOn && (dangerPoints -= 1);
    (dangerPoints < 0) && (dangerPoints = 0);

    int SurchargePct;
    (dangerPoints >= 7)
        ? (SurchargePct = 50)
        : ((dangerPoints >= 5)
               ? (SurchargePct = 25)
               : ((dangerPoints >= 3) ? (SurchargePct = 10) : 0));
    int NeedleS = (NeedleCost * (100 + SurchargePct)) / 100;
    int BandageS = (BandageCost * (100 + SurchargePct)) / 100;
    int MarbleS = (MarbleCost * (100 + SurchargePct)) / 100;
    int RopeS = (RopeCost * (100 + SurchargePct)) / 100;
    int itemsAfterSurcharge = NeedleS + BandageS + MarbleS + RopeS;

    int LateFee = (timeLeft < 15) ? 250 : ((timeLeft < 45) ? 100 : 0);
    int GuardToll = (card && !cameras) ? 0 : (50 + (alertAdj / 10) * 5);
    int base = (type == 'A') ? 40 : ((type == 'T') ? 30 : 35);
    int carryCap = base + (ally ? 10 : 0);
    int weightPenalty = min(500, (25 * max(0, (packKg - carryCap))));
    int wager = bet ? stake : 0;

    int allyRebate = ally ? 60 : 0;
    int calmRebate = (!injuries && stamina >= 70) ? 40 : 0;
    int injuryTax = (injuries == 0)
                        ? 0
                        : ((injuries == 1) ? 30 : ((injuries == 2) ? 90 : 200));
    int FavorDiscount =
        (favor == 0)
            ? 0
            : ((favor == 1)
                   ? ((game == 2 || game == 4)
                          ? ((((NeedleS + MarbleS) * 15) / 100) > 500
                                 ? 500
                                 : (((NeedleS + MarbleS) * 15) / 100))
                          : 0)
                   : ((favor == 2)
                          ? ((alertAdj >= 60)
                                 ? ((((LateFee + GuardToll) * 50) / 100) > 250
                                        ? 250
                                        : (((LateFee + GuardToll) * 50) / 100))
                                 : 0)
                          : ((injuries >= 1) ? (((BandageS * 35) / 100) > 900
                                                    ? 900
                                                    : ((BandageS * 35) / 100))
                                             : 0)));

    int gross =
        itemsAfterSurcharge + LateFee + GuardToll + weightPenalty + wager;
    int net =
        max(0, gross + injuryTax - allyRebate - calmRebate - FavorDiscount);
    int DebtFee = (net > cash) ? (80 + debt / 20) : 0;
    int Total = net + DebtFee;
    (Total < 200) && (Total = 200);
    int Fees = LateFee + GuardToll + weightPenalty + injuryTax + DebtFee;
    int CashUsed = min(cash, Total);
    int Payable = Total - CashUsed;

    int SurvivalChance = 40;
    takeRope && (SurvivalChance += min(15, ropeM / 2));
    takeBandages && (SurvivalChance += min(12, 2 * bandages));
    SurvivalChance += stamina / 4;
    card ? (SurvivalChance += 8) : (SurvivalChance -= 25);
    ally && (SurvivalChance += 5);
    SurvivalChance -= max(0, packKg - carryCap) / 2;
    SurvivalChance -= 5 * (SurchargePct / 10);
    SurvivalChance -= 8 * injuries;
    SurvivalChance -= 4 * (game - 1);
    (DebtFee > 0) && (SurvivalChance -= 12);
    (game == 2)
        ? ((takeNeedles && (needles >= 5)) && (SurvivalChance += 10))
        : ((game == 4)
               ? ((takeMarbles && (marbles >= 20)) && (SurvivalChance += 10))
               : ((game == 5) &&
                  ((takeRope && (ropeM >= 10)) && (SurvivalChance += 10))));
    (SurvivalChance < 0) ? (SurvivalChance = 0)
                         : ((SurvivalChance > 100) && (SurvivalChance = 100));
    string Outcome = (SurvivalChance >= 55) ? "Survived" : "Eliminated";

    int prizePool = (456 - playersLeft) * 100;
    int PrizeShare = ((Outcome == "Survived") ? (prizePool / playersLeft) : 0);
    int BetPayout =
        ((Outcome == "Survived")
             ? ((bet == 1)
                    ? ((stake * 3) / 2)
                    : ((bet == 2) ? ((SurvivalChance >= 75) ? (stake * 4) : 0)
                                  : 0))
             : 0);
    int FinalBalance = cash - Total + PrizeShare + BetPayout;

    cout << "\nNeedleCost=" << NeedleCost;
    cout << "\nBandageCost=" << BandageCost;
    cout << "\nMarbleCost=" << MarbleCost;
    cout << "\nRopeCost=" << RopeCost;
    cout << "\nDangerPoints=" << dangerPoints;
    cout << "\nSurchargePct=" << SurchargePct << "%";
    cout << "\nLateFee=" << LateFee;
    cout << "\nGuardToll=" << GuardToll;
    cout << "\nWeightPenalty=" << weightPenalty;
    cout << "\nWager=" << wager;
    cout << "\nFavorDiscount=" << FavorDiscount;
    cout << "\nFees=" << Fees;
    cout << "\nTotal=" << Total;
    cout << "\nCashUsed=" << CashUsed;
    cout << "\nPayable=" << Payable;
    cout << "\nSurvivalChance=" << SurvivalChance;
    cout << "\nOutcome=" << Outcome;
    cout << "\nPrizeShare=" << PrizeShare;
    cout << "\nBetPayout=" << BetPayout;
    cout << "\nFinalBalance=" << FinalBalance;

    break;
  }
  case 2:

    break;

  case 3:

    break;

  case 4:

    break;

  case 5:

    break;

  case 6:

    break;

  case 7:

    break;

  case 8:

    break;

  default:

    cout << "Invalid question number!";
  }

  return 0;
}
