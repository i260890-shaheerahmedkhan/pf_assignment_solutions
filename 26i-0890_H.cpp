
#include <cmath>
#include <iomanip>
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
    ((type != 'A') && (type != 'T') && (type != 'G')) &&
        (cout << "You entered the wrong character type!");
    (type == 'A') ? (Rope = 100)
                  : ((type == 'T') ? (Needle = 120) : (Marble = 45));
    cout << "Select the game \n 1 = Red Light Green Light\n 2 = Honeycomb\n 3 "
            "= Tug of War\n 4 = Marbles\n 5 = Glass Bridge\n ";
    cin >> game;
    ((game < 1) || (game > 5)) &&
        (cout << "The game you selected is not available!");
    cout << "Enter the time left until the starting of the game in minutes "
            "(0-120): ";
    cin >> timeLeft;
    ((timeLeft < 0) || (timeLeft > 120)) &&
        (cout << "The time left is not entered correctly!");
    cout << "Enter the guard alert (0-100): ";
    cin >> guardAlert;
    ((guardAlert < 0) || (guardAlert > 100)) &&
        (cout << "The guard alert value you entered is wrong!");
    cout << "What are the injuries (0-3): ";
    cin >> injuries;
    ((injuries < 0) || (injuries > 3)) &&
        (cout << "The injury level you entered is invalid!");
    cout << "Are the lights on: \n 1 for on \n 0 for off\n ";
    cin >> lightsOn;
    cout << "State of VIP cameras: \n 1 for active \n 0 for not active\n ";
    cin >> cameras;
    cout << "Will you take needles ( 0 for no , 1 for yes ): ";
    cin >> takeNeedles;
    cout << "What is the number of needles (0-40): ";
    cin >> needles;
    ((needles < 0) || (needles > 40)) &&
        (cout << "The number of needles you entered is incorrect!");
    cout << "Will you take bandages ( 0 for no , 1 for yes ): ";
    cin >> takeBandages;
    cout << "Enter the number of bandages (0-30): ";
    cin >> bandages;
    ((bandages < 0) || (bandages > 30)) &&
        (cout << "The number of bandages you entered is invalid!");
    cout << "Will you take marbles ( 0 for no , 1 for yes ): ";
    cin >> takeMarbles;
    cout << "Enter the number of marbles (0-100): ";
    cin >> marbles;
    ((marbles < 0) || (marbles > 100)) &&
        (cout << "The number of marbles you entered is invalid!");
    cout << "Will you take the rope ( 0 for no , 1 for yes ): ";
    cin >> takeRope;
    cout << "Enter the length of the rope in metres (0-60): ";
    cin >> ropeM;
    ((ropeM < 0) || (ropeM > 60)) &&
        (cout << "The length of the rope is incorrect!");
    cout << "What is the weight you carry in kg (0-150): ";
    cin >> packKg;
    ((packKg < 0) || (packKg > 150)) &&
        (cout << "The weight you entered is invalid!");
    cout << "Enter your stamina (0-100): ";
    cin >> stamina;
    ((stamina < 0) || (stamina > 100)) &&
        (cout << "The value of stamina you entered is invlaid!");
    cout << "Enter the players left (2-456): ";
    cin >> playersLeft;
    ((playersLeft < 2) || (playersLeft > 456)) &&
        (cout << "The number of players you entered is incorrect!");
    cout << "What do you bet \n 0 = No bet\n 1 = SAFE \n 2 = RISKY \n ";
    cin >> bet;
    ((bet != 0) && (bet != 1) && (bet != 2)) &&
        (cout << "You entered the wrong value for bet!");
    (bet != 0) && (cout << "Enter your stake (0-2000): ", cin >> stake);
    ((stake < 0) || (stake > 2000)) && (cout << "You stake is invlaid!");
    cout << "Do you have a favor \n 0 = None\n 1 = INSIDER\n 2 = HUSH\n 3 = "
            "MEDPASS\n ";
    cin >> favor;
    ((favor != 0) && (favor != 1) && (favor != 2) && (favor != 3)) &&
        (cout << "You entered an invalid favor!");
    cout << "Enter the cash you have (0-6000): ";
    cin >> cash;
    ((cash < 0) || (cash > 6000)) &&
        (cout << "The cash amount you entered is invalid!");
    cout << "Enter your debt (0-3000): ";
    cin >> debt;
    ((debt < 0) || (debt > 3000)) &&
        (cout << "The debt value you entered is invalid!");
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
  case 2: {

    double U, V, theta, D;
    double Wo = 0.8, B = 0.12, Uo = 15.0, u = 3.4, Do = 0.5;
    long long rollLast4;

    cout << "\nEnter the WindSpeed (in km/h): ";
    cin >> U;
    cout << "Enter the Terrain slope (in radians): ";
    cin >> theta;
    cout << "Enter the vegetation fuel dryness index: ";
    cin >> D;
    cout << "Enter the last four digits of your roll number: ";
    cin >> rollLast4;

    V = (Wo * exp(B * U)) + (Uo * sin(theta) * sin(theta)) +
        (u * log((D + 1.0) / Do)) + sqrt(U * cos(theta) + 1.0);

    cout << "\nWildfire propagation velocity delta V = " << fixed
         << setprecision(4) << V;

    int Vint = V;
    int F1 = ((V - Vint) * 100.0);
    int F2 = ((((V - Vint) * 100.0) - F1) * 100.0);
    int R = (rollLast4 % 89) + 10;
    long long K = (Vint * 1000000ll) + (F1 * 10000ll) + (F2 * 100ll) + R;

    int parsed_Vint = K / 1000000ll;
    int parsed_F1 = (K / 10000ll) % 100;
    int parsed_F2 = (K / 100ll) % 100;
    int retrieved_R = K % 100;
    char C1 = 65 + (Vint % 26);
    char C2 = 90 - (R % 26);

    float Vfloat = static_cast<float>(parsed_Vint) +
                   static_cast<float>(parsed_F1) / 100 +
                   static_cast<float>(parsed_F2) / 10000;
    double Vdouble = static_cast<double>(parsed_Vint) + parsed_F1 / 100.0 +
                     parsed_F2 / 10000.0;
    int is_exact = (Vfloat == Vdouble);

    int Penalty = (1 - is_exact) * 25;
    int Threat = R + Penalty + (1.5 * Vdouble);

    cout << "\nTelemetry Key K: " << K;
    cout << "\nStatus Tag: " << C1 << C2;
    cout << "\nPrecision Match Flag: " << is_exact;
    cout << "\nThreat Rating: " << Threat << "\n";

    break;
  }

  case 3: {

    int murVisitedBoilerRoom = 0, murVisitedCargoHold = 0,
        murVisitedThirdClass = 0, murVisitedDiningSaloon = 0,
        murVisitedPromenadeDeck = 0, murVisitedBridge = 0,
        murVisitedLifeboatDeck = 0, murVisitedCrowsNest = 0,
        maryVisitedBoilerRoom = 0, maryVisitedCargoHold = 0,
        maryVisitedThirdClass = 0, maryVisitedDiningSaloon = 0,
        maryVisitedPromenadeDeck = 0, maryVisitedBridge = 0,
        maryVisitedLifeboatDeck = 0, maryVisitedCrowsNest = 0;

    int murCurrent = 0, maryCurrent = 0;
    int boilerRoom = 0, cargoHold = 1, thirdClass = 2, diningSaloon = 3,
        promenadeDeck = 4, bridge = 5, lifeboatDeck = 6, crowsNest = 7;
    int murFrozen = 0, maryFrozen = 0;

    // Murdoch
    cout << "Murdoch path: Boiler Room";

    // Move 1
    switch (murFrozen) {
    case 0:
      switch (murCurrent) {
      case 0:
        murCurrent = cargoHold;
        murVisitedCargoHold = 1;
        cout << " -> Cargo Hold";
        break;
      }
      switch (murCurrent) {
      case 6:
        cout << " Rescued";
        murFrozen = 1;
        break;
      }
      break;
    }

    // Move 2
    switch (murFrozen) {
    case 0:
      switch (murCurrent) {
      case 1:
        switch (murVisitedBoilerRoom) {
        case 0:
          murCurrent = boilerRoom;
          murVisitedBoilerRoom = 1;
          cout << " -> Boiler Room";
          break;
        }
        break;
      }
      switch (murCurrent) {
      case 6:
        cout << " Rescued";
        murFrozen = 1;
        break;
      }
      break;
    }

    // Move 3
    switch (murFrozen) {
    case 0:
      switch (murCurrent) {
      case 0:
        switch (murVisitedThirdClass) {
        case 0:
          murCurrent = thirdClass;
          murVisitedThirdClass = 1;
          cout << " -> Third Class";
          break;
        }
        break;
      }
      switch (murCurrent) {
      case 6:
        cout << " Rescued";
        murFrozen = 1;
        break;
      }
      break;
    }

    // Move 4
    switch (murFrozen) {
    case 0:
      switch (murCurrent) {
      case 2:
        switch (murVisitedBridge) {
        case 0:
          cout << " WaterRising";
          murCurrent = bridge;
          murVisitedBridge = 1;
          cout << " -> Bridge";
          break;
        }
        break;
      }
      switch (murCurrent) {
      case 6:
        cout << " Rescued";
        murFrozen = 1;
        break;
      }
      break;
    }

    // Move 5
    switch (murFrozen) {
    case 0:
      switch (murCurrent) {
      case 5:
        switch (murVisitedLifeboatDeck) {
        case 0:
          murCurrent = lifeboatDeck;
          murVisitedLifeboatDeck = 1;
          cout << " -> Lifeboat Deck";
          break;
        }
        break;
      }
      switch (murCurrent) {
      case 6:
        cout << " Rescued";
        murFrozen = 1;
        break;
      }
      break;
    }

    // Move 6
    switch (murFrozen) {
    case 0:
      break;
    }

    // MARY
    cout << "\nMary path: Boiler Room";

    // Move 1
    switch (maryFrozen) {
    case 0:
      switch (maryCurrent) {
      case 0:
        maryCurrent = cargoHold;
        maryVisitedCargoHold = 1;
        cout << " -> Cargo Hold";
        break;
      }
      switch (maryCurrent) {
      case 6:
        cout << " Rescued";
        maryFrozen = 1;
        break;
      }
      break;
    }

    // Move 2
    switch (maryFrozen) {
    case 0:
      switch (maryCurrent) {
      case 1:
        switch (maryVisitedThirdClass) {
        case 0:
          maryCurrent = boilerRoom;
          maryVisitedBoilerRoom = 1;
          cout << " -> Boiler Room";
          break;
        }
        break;
      }
      switch (maryCurrent) {
      case 6:
        cout << " Rescued";
        maryFrozen = 1;
        break;
      }
      break;
    }

    // Move 3
    switch (maryFrozen) {
    case 0:
      switch (maryCurrent) {
      case 0:
        switch (maryVisitedThirdClass) {
        case 0:
          maryCurrent = thirdClass;
          maryVisitedThirdClass = 1;
          cout << " -> Third Class";
          break;
        }
        break;
      }
      switch (maryCurrent) {
      case 6:
        cout << " Rescued";
        maryFrozen = 1;
        break;
      }
      break;
    }

    // Move 4
    switch (maryFrozen) {
    case 0:
      switch (maryCurrent) {
      case 2:
        switch (maryVisitedBridge) {
        case 0:
          cout << " WaterRising";
          maryCurrent = bridge;
          maryVisitedBridge = 1;
          cout << " -> Bridge";
          break;
        }
        break;
      }
      switch (maryCurrent) {
      case 6:
        cout << " Rescued";
        maryFrozen = 1;
        break;
      }
      break;
    }

    // Move 5
    switch (maryFrozen) {
    case 0:
      switch (maryCurrent) {
      case 5:
        switch (maryVisitedLifeboatDeck) {
        case 0:
          maryCurrent = lifeboatDeck;
          maryVisitedLifeboatDeck = 1;
          cout << " -> Lifeboat Deck";
          break;
        }
        break;
      }
      switch (maryCurrent) {
      case 6:
        cout << " Rescued";
        maryFrozen = 1;
        break;
      }
      break;
    }

    // Move 6
    switch (maryFrozen) {
    case 0:
      break;
    }

    cout << "\n";

    break;
  }

  case 4: {

    int n;
    cout << "\nEnter a number: ";
    cin >> n;

    int median = (n + 1) / 2;
    int middle = ((((n - 2) / 2) % 2) == 1);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {

        int leftUpperSquare = (((i < median) && (i & 1) && (j <= i)) ||
                               ((j < median) && (j & 1) && (i <= j)));
        int rightLowerSquare = (((i > median) && (i & 1) && (i <= j)) ||
                                ((j > median) && (j & 1) && (j <= i)));
        int leftLowerSquare = ((i > median) && (i & 1) && (j <= n - i + 1)) ||
                              ((j < median) && (j & 1) && (i >= n - j + 1));
        int rightUpperSquare = ((i < median) && (i & 1) && (j >= n - i + 1)) ||
                               ((j > median) && (j & 1) && (i <= n - j + 1));

        if ((i == 1) || (i == n) || (j == 1) || (j == n) ||
            (((i == median) || (j == median)) && middle))
          cout << "* ";
        else if (leftUpperSquare || rightLowerSquare || leftLowerSquare ||
                 rightUpperSquare)
          cout << "* ";
        else
          cout << "  ";
      }
      cout << "\n";
    }

    break;
  }
  case 5: {

    int choice;
    cout << "1. The House\n";
    cout << "2. The train\n";
    cout << "Choose: ";
    cin >> choice;

    if ((choice != 1) && (choice != 2)) {
      cout << "Invalid choice\n";
      return 0;
    }

    // the house

    if (choice == 1) {
      int houseWidth, houseHeight;
      int doorWidth, doorHeight;
      int atticHeight, nChimneys, walkwayHeight;

      cout << "\nEnter the height of the house: ";
      cin >> houseHeight;

      cout << "Enter the width of the house: ";
      cin >> houseWidth;

      cout << "Enter the door width: ";
      cin >> doorWidth;

      cout << "Enter the door height: ";
      cin >> doorHeight;

      cout << "Enter the number of chimneys: ";
      cin >> nChimneys;

      cout << "Enter the height of the attic: ";
      cin >> atticHeight;

      cout << "Enter the walkway height: ";
      cin >> walkwayHeight;

      // Input Validation
      if ((houseWidth <= 0) || (houseHeight <= 0) || (doorWidth < 6) ||
          (doorHeight < 5) || (atticHeight < 6) || (nChimneys < 0) ||
          (walkwayHeight < 1)) {

        cout << "Invalid inputs, house cannot be printed correctly\n";
        return 0;
      }

      int bodyHeight = houseHeight - atticHeight - 1 - walkwayHeight;

      if (bodyHeight < 6 || doorHeight > bodyHeight ||
          houseWidth < doorWidth + 24 || houseWidth < 2 * atticHeight + 2 ||
          (houseWidth - doorWidth) % 2 != 0) {

        cout << "Invalid lengths, house cannot be printed\n";
        return 0;
      }

      // window positions and the door
      int windowsPerSide = (houseWidth - doorWidth - 6) / 18;

      int leftSideWidth = 9 * windowsPerSide + 1;
      int rightSideStart = houseWidth - leftSideWidth;
      int middleWidth = houseWidth - 2 * leftSideWidth;

      int doorLeft = leftSideWidth + (middleWidth - doorWidth) / 2;

      // the roof position
      int roofCenter = (houseWidth - 2) / 2;
      int atticBaseRow = atticHeight - 4;

      // these are the available chimney positions
      int availablePositions = roofCenter - atticBaseRow - 6;

      int leftChimneySlots =
          (availablePositions >= 0) ? availablePositions / 7 + 1 : 0;

      availablePositions = houseWidth - 6 - (roofCenter + atticBaseRow + 2);

      int rightChimneySlots =
          (availablePositions >= 0) ? (availablePositions / 7 + 1) : 0;

      if (doorLeft < (walkwayHeight + 2) ||
          nChimneys > (leftChimneySlots + rightChimneySlots)) {

        cout << "The door or chimneys do not fit.\n";
        return 0;
      }

      int totalRows = atticHeight + bodyHeight + 1 + walkwayHeight;

      // this prints the rows of the house
      for (int row = 0; row < totalRows; row++) {

        for (int column = 0; column < houseWidth; column++) {
          char character = ' ';

          // this is the prestigious roof
          if (row < atticHeight) {
            if (column == (roofCenter - row))
              character = '/';

            if (column == (roofCenter + 1 + row))
              character = '\\';
          }

          if (row == atticBaseRow) {
            character = '_';

            if (column == (roofCenter - atticBaseRow))
              character = '/';

            if (column == (roofCenter + 1 + atticBaseRow))
              character = '\\';
          }

          if ((row > atticBaseRow) && (row < atticHeight)) {
            if (column == 0 || column == (houseWidth - 1))
              character = '|';
            else if (column < (roofCenter - row))
              character = ':';
            else if ((column >= (roofCenter + row + 2)) &&
                     (column <= (houseWidth - 2)))
              character = ':';
          }

          if ((row == atticHeight - 1) &&
              (column >= (roofCenter - (atticHeight - 1) + 1)) &&
              (column <= (roofCenter + atticHeight - 1))) {
            character = '_';
          }

          // base of the attic
          if ((row == atticBaseRow) &&
              (column == roofCenter || column == roofCenter + 1))
            character = '_';

          if ((row == atticBaseRow + 1) &&
              (column == roofCenter - 1 || column == roofCenter + 2))
            character = '|';

          if ((row == atticBaseRow + 2) && (column >= roofCenter - 1) &&
              (column <= roofCenter + 2))
            character = '=';

          // this prints the chimneys
          for (int i = 0; i < nChimneys; i++) {

            int smallerSlotCount = (leftChimneySlots < rightChimneySlots)
                                       ? leftChimneySlots
                                       : rightChimneySlots;

            int chimneyStart;

            if (i < 2 * smallerSlotCount) {
              int slotIndex = i / 2;

              chimneyStart =
                  (i % 2 == 0)
                      ? (roofCenter - atticBaseRow - 6 - 7 * slotIndex)
                      : (roofCenter + atticBaseRow + 2 + 7 * slotIndex);
            } else {
              int extraSlot = i - 2 * smallerSlotCount;

              if (leftChimneySlots > rightChimneySlots)
                chimneyStart = roofCenter - atticBaseRow - 6 -
                               7 * (smallerSlotCount + extraSlot);
              else
                chimneyStart = roofCenter + atticBaseRow + 2 +
                               7 * (smallerSlotCount + extraSlot);
            }

            if (row == atticBaseRow - 2) {
              if ((column == chimneyStart + 2) || (column == chimneyStart + 4))
                character = ')';
            }

            if ((row == atticBaseRow - 1) && (column >= chimneyStart + 1) &&
                (column <= chimneyStart + 5))
              character = '=';

            if ((row == atticBaseRow) && (column >= chimneyStart) &&
                (column <= chimneyStart + 5)) {

              int chimneyColumn = column - chimneyStart;

              character = ((chimneyColumn == 0) ||
                           ((chimneyColumn >= 2) && (chimneyColumn <= 4)))
                              ? '_'
                              : '|';
            }
          }

          // now for the windows and walls of the house
          if ((row >= atticHeight) && (row < (atticHeight + bodyHeight))) {

            int bodyRow = row - atticHeight;

            if (column == 0 || (column == houseWidth - 1))
              character = '|';

            for (int k = 0; k < windowsPerSide; k++) {

              // this is the left window
              int leftWindowStart = 1 + 9 * k;

              if ((bodyRow < 5) && (column >= leftWindowStart) &&
                  (column < leftWindowStart + 8)) {

                int windowColumn = column - leftWindowStart;

                if (bodyRow == 0)
                  character = '_';
                else if (bodyRow == 1)
                  character =
                      ((windowColumn == 0) || (windowColumn == 7)) ? ' ' : '_';
                else if (bodyRow == 2)
                  character = (windowColumn == 0 || windowColumn == 3 ||
                               windowColumn == 7)
                                  ? '|'
                                  : ' ';
                else if (bodyRow == 3) {
                  if (windowColumn == 0 || windowColumn == 7)
                    character = '|';
                  else if (windowColumn == 3)
                    character = '+';
                  else
                    character = '-';
                } else if (bodyRow == 4) {
                  if (windowColumn == 0 || windowColumn == 3 ||
                      windowColumn == 7)
                    character = '|';
                  else
                    character = '_';
                }
              }

              if (column == leftWindowStart + 8)
                character = '|';

              // this gives the right window
              int rightWindowStart = rightSideStart + 9 * k;

              if (column == rightWindowStart)
                character = '|';

              if (bodyRow < 5 && column >= rightWindowStart + 1 &&
                  column <= rightWindowStart + 8) {

                int windowColumn = column - rightWindowStart - 1;

                if (bodyRow == 0)
                  character = '_';
                else if (bodyRow == 1)
                  character =
                      (windowColumn == 0 || windowColumn == 7) ? ' ' : '_';
                else if (bodyRow == 2)
                  character = (windowColumn == 0 || windowColumn == 4 ||
                               windowColumn == 7)
                                  ? '|'
                                  : ' ';
                else if (bodyRow == 3) {
                  if (windowColumn == 0 || windowColumn == 7)
                    character = '|';
                  else if (windowColumn == 4)
                    character = '+';
                  else
                    character = '-';
                } else if (bodyRow == 4) {
                  if (windowColumn == 0 || windowColumn == 4 ||
                      windowColumn == 7)
                    character = '|';
                  else
                    character = '_';
                }
              }
            }
          }

          // now for the front door
          int doorTopRow = atticHeight + bodyHeight - doorHeight;

          if ((row >= doorTopRow) && (row < atticHeight + bodyHeight) &&
              (column >= doorLeft) && (column < doorLeft + doorWidth)) {

            int doorRow = row - doorTopRow;
            int doorColumn = column - doorLeft;

            int doorCenter = (doorWidth - 4) / 2;

            if (doorRow == 0) {
              character = (doorColumn == 0 || (doorColumn == doorWidth - 1))
                              ? ' '
                              : '_';
            } else if (doorRow == 1) {
              if (doorColumn == 0)
                character = '/';
              else if (doorColumn == doorWidth - 1)
                character = '\\';
              else if ((doorColumn == doorCenter + 1) ||
                       (doorColumn == doorCenter + 2))
                character = '|';
            } else if (doorRow == 2) {
              character = '=';
            } else if (doorRow == doorHeight - 2) {
              if (doorColumn == 0 || doorColumn == doorWidth - 1)
                character = '|';
              else if (doorColumn == doorWidth - 2)
                character = 'o';
            } else if (doorRow == doorHeight - 1) {
              character = (doorColumn == 0 || (doorColumn == doorWidth - 1))
                              ? '|'
                              : '_';
            } else {
              character = (doorColumn == 0 || (doorColumn == doorWidth - 1))
                              ? '|'
                              : ' ';
            }
          }

          // finally the ground row
          int groundRow = atticHeight + bodyHeight;

          if (row == groundRow) {
            if (column == 0)
              character = '(';
            else if (column == houseWidth - 1)
              character = ')';
            else
              character = '-';

            if (column == doorLeft - 2 || column == doorLeft + doorWidth + 1)
              character = '|';

            if (column >= doorLeft - 1 && column <= doorLeft + doorWidth)
              character = '_';
          }

          // this is the last piece , the walkway
          if (row > groundRow) {
            int walkwayRow = row - groundRow - 1;

            if (column == 0)
              character = '(';

            if (column == houseWidth - 1)
              character = ')';

            if (walkwayRow == walkwayHeight - 1 && column >= 1 &&
                column <= houseWidth - 2)
              character = '_';

            if (column >= doorLeft - 1 - walkwayRow &&
                column <= doorLeft + doorWidth + walkwayRow)
              character = '_';

            if (column == doorLeft - 2 - walkwayRow)
              character = '/';

            if (column == doorLeft + doorWidth + 1 + walkwayRow)
              character = '\\';
          }

          cout << character;
        }

        cout << '\n';
      }
    }

    // the train

    else {
      int trainCode;

      cout << "\nEnter the four-digit train design (e.g. 1234): ";
      cin >> trainCode;

      // Exactly four digits are required.
      if (trainCode < 1000 || trainCode > 9999) {
        cout << "Invalid train code. Enter exactly four digits.\n";
        return 0;
      }

      int firstCompartment = trainCode / 1000;
      int secondCompartment = (trainCode / 100) % 10;
      int thirdCompartment = (trainCode / 10) % 10;
      int fourthCompartment = trainCode % 10;

      if (firstCompartment < 1 || firstCompartment > 4 ||
          secondCompartment < 1 || secondCompartment > 4 ||
          thirdCompartment < 1 || thirdCompartment > 4 ||
          fourthCompartment < 1 || fourthCompartment > 4) {

        cout << "Invalid train code. Every digit must be 1, 2, 3, or 4.\n";
        return 0;
      }

      // this prints six rows of the four compartments
      for (int row = 0; row < 6; row++) {
        for (int compartmentPosition = 0; compartmentPosition < 4;
             compartmentPosition++) {

          int compartmentType;

          if (compartmentPosition == 0)
            compartmentType = firstCompartment;
          else if (compartmentPosition == 1)
            compartmentType = secondCompartment;
          else if (compartmentPosition == 2)
            compartmentType = thirdCompartment;
          else
            compartmentType = fourthCompartment;

          // 1, The engine
          if (compartmentType == 1) {
            if (row == 0)
              cout << "      o O";
            else if (row == 1)
              cout << "   _[]_ ________";
            else if (row == 2)
              cout << "  |____|_|[] []|";
            else if (row == 3)
              cout << "  |_()_|_|______|";
            else if (row == 4)
              cout << "<==============]";
            else
              cout << "  (O)(O)         ";
          }

          // 2, The cabin
          else if (compartmentType == 2) {
            if (row == 0)
              cout << " ";
            else if (row == 1)
              cout << " ____________";
            else if (row == 2)
              cout << "|[] [] [] [] |";
            else if (row == 3)
              cout << "|[] [] [] [] |";
            else if (row == 4)
              cout << "--|____________|";
            else
              cout << " (O)(O)        ";
          }

          // 3, The cargo
          else if (compartmentType == 3) {
            if (row == 0)
              cout << " ";
            else if (row == 1)
              cout << " |============|";
            else if (row == 2)
              cout << " | | [] | |";
            else if (row == 3)
              cout << " | | || | |";
            else if (row == 4)
              cout << "-|__|__||__|__|--";
            else
              cout << " (O)  (O)  (O)   ";
          }

          // 4, Vip carriage
          else {
            if (row == 0)
              cout << " ";
            else if (row == 1)
              cout << " _[__]_";
            else if (row == 2)
              cout << " | .-========-.";
            else if (row == 3)
              cout << " | ( ~~~~~~~~ )";
            else if (row == 4)
              cout << "-- '-========-'";
            else
              cout << "   (O)  (O)     ";
          }
        }

        cout << '\n';
      }
    }

    break;
  }

  case 6:

    break;

  case 7:

    break;

  case 8: {

    // These are the characters
    char pacman = '@', blinky = 'B', pinky = 'P', inky = 'I', clyde = 'C';

    // Their x and y coordinates
    int pacmanX, pacmanY, blinkyX, blinkyY, pinkyX, pinkyY, inkyX, inkyY,
        clydeX, clydeY;

    bool gameOver = false; // a flag for checking the game's continuity
    bool pacmanWon = false;
    bool blinkyMovingRight = true; // a flag for tracing blinky's direction

    // the dimensions of the board
    const int BOARD_WIDTH = 20;
    const int BOARD_HEIGHT = 10;

    // the random number generator
    unsigned int seed;

    cout << "\nEnter a seed for a the random number generator: ";
    cin >> seed;

    seed = (seed * 1103515245u + 12345u) % 2147483648u;

    // now assigning the random coordinates for all characters

    // pacman coordinates
    pacmanX = seed % BOARD_WIDTH;

    seed = (seed * 1103515245u + 12345u) % 2147483648u;

    pacmanY = seed % BOARD_HEIGHT;

    // blinky coordinates
    seed = (seed * 1103515245u + 12345u) % 2147483648u;

    blinkyX = seed % BOARD_WIDTH;

    seed = (seed * 1103515245u + 12345u) % 2147483648u;

    blinkyY = 2;

    // pinky coordinates
    seed = (seed * 1103515245u + 12345u) % 2147483648u;

    pinkyX = seed % BOARD_WIDTH;

    seed = (seed * 1103515245u + 12345u) % 2147483648u;

    pinkyY = seed % BOARD_HEIGHT;

    // inky coordinates
    seed = (seed * 1103515245u + 12345u) % 2147483648u;

    inkyX = seed % BOARD_WIDTH;

    seed = (seed * 1103515245u + 12345u) % 2147483648u;

    inkyY = seed % BOARD_HEIGHT;

    // clyde coordinates
    seed = (seed * 1103515245u + 12345u) % 2147483648u;

    clydeX = seed % BOARD_WIDTH;

    seed = (seed * 1103515245u + 12345u) % 2147483648u;

    clydeY = seed % BOARD_HEIGHT;

    // now checking for colliding positions and adjusting them

    do {
      // blinky coordinates

      seed = (seed * 1103515245u + 12345u) % 2147483648u;

      blinkyX = seed % BOARD_WIDTH;

      seed = (seed * 1103515245u + 12345u) % 2147483648u;

      blinkyY = 2;

      // pinky coordinates
      seed = (seed * 1103515245u + 12345u) % 2147483648u;

      pinkyX = seed % BOARD_WIDTH;

      seed = (seed * 1103515245u + 12345u) % 2147483648u;

      pinkyY = seed % BOARD_HEIGHT;

      // inky coordinates
      seed = (seed * 1103515245u + 12345u) % 2147483648u;

      inkyX = seed % BOARD_WIDTH;

      seed = (seed * 1103515245u + 12345u) % 2147483648u;

      inkyY = seed % BOARD_HEIGHT;

      // clyde coordinates
      seed = (seed * 1103515245u + 12345u) % 2147483648u;

      clydeX = seed % BOARD_WIDTH;

      seed = (seed * 1103515245u + 12345u) % 2147483648u;

      clydeY = seed % BOARD_HEIGHT;

    } while (((pacmanX == blinkyX) && (pacmanY == blinkyY)) ||
             ((pacmanX == pinkyX) && (pacmanY == pinkyY)) ||
             ((pacmanX == inkyX) && (pacmanY == inkyY)) ||
             ((pacmanX == clydeX) && (pacmanY == clydeY)) ||
             ((blinkyX == pinkyX) && (blinkyY == pinkyY)) ||
             ((blinkyX == inkyX) && (blinkyY == inkyY)) ||
             ((blinkyX == clydeX) && (blinkyY == clydeY)) ||
             ((pinkyX == inkyX) && (pinkyY == inkyY)) ||
             ((pinkyX == clydeX) && (pinkyY == clydeY)) ||
             ((inkyX == clydeX) && (inkyY == clydeY)));

    // this will move pacman from the keyboard
    char moveDirection;

    while (!gameOver) {
      cout << "\nEnter a direction to move pacman (W A S D): ";
      cin >> moveDirection;

      // these are the switches, the main systems that control movement

      // this moves pacman
      switch (moveDirection) {

      case 'w':
      case 'W': {
        pacmanY--;

        (pacmanY > 0) ? 0 : (pacmanY = 0);

        break;
      }

      case 'a':
      case 'A': {
        pacmanX--;

        (pacmanX > 0) ? 0 : (pacmanX = 0);

        break;
      }

      case 's':
      case 'S': {
        pacmanY++;

        (pacmanY < BOARD_HEIGHT - 1) ? 0 : (pacmanY = BOARD_HEIGHT - 1);

        break;
      }

      case 'd':
      case 'D': {
        pacmanX++;

        (pacmanX < BOARD_WIDTH - 1) ? 0 : (pacmanX = BOARD_WIDTH - 1);

        break;
      }

      default:
        cout << "\nInvalid input, you pressed the wrong key, only \"w a s d\" "
                "move "
                "pacman";
        break;
      }

      // this moves clyde
      switch (moveDirection) {

      case 'w':
      case 'W': {
        clydeY--;

        (clydeY > 0) ? 0 : (clydeY = 0);

        break;
      }

      case 'a':
      case 'A': {
        clydeX--;

        (clydeX > 0) ? 0 : (clydeX = 0);

        break;
      }

      case 's':
      case 'S': {
        clydeY++;

        (clydeY < BOARD_HEIGHT - 1) ? 0 : (clydeY = BOARD_HEIGHT - 1);

        break;
      }

      case 'd':
      case 'D': {
        clydeX++;

        (clydeX < BOARD_WIDTH - 1) ? 0 : (clydeX = BOARD_WIDTH - 1);

        break;
      }

      default:
        cout << "\nInvalid input";
        break;
      }

      ((pacmanX == clydeX) && (pacmanY == clydeY))
          ? (gameOver = true, pacmanWon = true)
          : 0;

      switch (gameOver) {

      case 0: {

        // now i will calculate the distance of all characters from pacman

        double inkysDistance = sqrt(((inkyX - pacmanX) * (inkyX - pacmanX)) +
                                    ((inkyY - pacmanY) * (inkyY - pacmanY)));
        double pinkysDistance = sqrt(((pinkyX - pacmanX) * (pinkyX - pacmanX)) +
                                     ((pinkyY - pacmanY) * (pinkyY - pacmanY)));
        double blinkysDistance =
            sqrt(((blinkyX - pacmanX) * (blinkyX - pacmanX)) +
                 ((blinkyY - pacmanY) * (blinkyY - pacmanY)));
        double clydesDistance = sqrt(((clydeX - pacmanX) * (clydeX - pacmanX)) +
                                     ((clydeY - pacmanY) * (clydeY - pacmanY)));

        // this checks if inky is the closest one or not
        bool inkyIsClosest = 0;

        ((inkysDistance < pinkysDistance) &&
         (inkysDistance < blinkysDistance) && (inkysDistance < clydesDistance))
            ? (inkyIsClosest = 1)
            : 0;

        // this moves inky near to pacman if no other one is near
        switch (inkyIsClosest) {

        case 1: {

          // this checks if a cell is free near pacman
          bool cellFreeNearPacman = 0;

          // this checks the block above pacman

          int candidateX = pacmanX, candidateY = pacmanY - 1;

          ((!((blinkyX == candidateX) && (blinkyY == candidateY))) &&
           (!((pinkyX == candidateX) && (pinkyY == candidateY))) &&
           (!((clydeX == candidateX) && (clydeY == candidateY))) &&
           ((candidateX >= 0 && candidateX < BOARD_WIDTH) &&
            (candidateY >= 0 && (candidateY < BOARD_HEIGHT)))) &&
              (cellFreeNearPacman = 1);

          cellFreeNearPacman && (inkyX = candidateX, inkyY = candidateY);

          // this checks the block to the upper right corner of pacman
          (!cellFreeNearPacman) &&
              (candidateX = pacmanX + 1, candidateY = pacmanY - 1,

               ((!((blinkyX == candidateX) && (blinkyY == candidateY))) &&
                (!((pinkyX == candidateX) && (pinkyY == candidateY))) &&
                (!((clydeX == candidateX) && (clydeY == candidateY))) &&
                ((candidateX >= 0 && candidateX < BOARD_WIDTH) &&
                 (candidateY >= 0 && (candidateY < BOARD_HEIGHT)))) &&
                   (cellFreeNearPacman = 1),

               cellFreeNearPacman && (inkyX = candidateX, inkyY = candidateY));

          // this checks the block to the right of pacman

          (!cellFreeNearPacman) &&
              (candidateX = pacmanX + 1, candidateY = pacmanY,

               ((!((blinkyX == candidateX) && (blinkyY == candidateY))) &&
                (!((pinkyX == candidateX) && (pinkyY == candidateY))) &&
                (!((clydeX == candidateX) && (clydeY == candidateY))) &&
                ((candidateX >= 0 && candidateX < BOARD_WIDTH) &&
                 (candidateY >= 0 && (candidateY < BOARD_HEIGHT)))) &&
                   (cellFreeNearPacman = 1),

               cellFreeNearPacman && (inkyX = candidateX, inkyY = candidateY));

          // this checks the block to the right lower corner of pacman
          (!cellFreeNearPacman) &&
              (candidateX = pacmanX + 1, candidateY = pacmanY + 1,

               ((!((blinkyX == candidateX) && (blinkyY == candidateY))) &&
                (!((pinkyX == candidateX) && (pinkyY == candidateY))) &&
                (!((clydeX == candidateX) && (clydeY == candidateY))) &&
                ((candidateX >= 0 && candidateX < BOARD_WIDTH) &&
                 (candidateY >= 0 && (candidateY < BOARD_HEIGHT)))) &&
                   (cellFreeNearPacman = 1),
               cellFreeNearPacman && (inkyX = candidateX, inkyY = candidateY));

          // this checks the block below pacman
          (!cellFreeNearPacman) &&
              (candidateX = pacmanX, candidateY = pacmanY + 1,

               ((!((blinkyX == candidateX) && (blinkyY == candidateY))) &&
                (!((pinkyX == candidateX) && (pinkyY == candidateY))) &&
                (!((clydeX == candidateX) && (clydeY == candidateY))) &&
                ((candidateX >= 0 && candidateX < BOARD_WIDTH) &&
                 (candidateY >= 0 && (candidateY < BOARD_HEIGHT)))) &&
                   (cellFreeNearPacman = 1),
               cellFreeNearPacman && (inkyX = candidateX, inkyY = candidateY));

          // this checks the block to the lower left corner of pacman
          (!cellFreeNearPacman) &&
              (candidateX = pacmanX - 1, candidateY = pacmanY + 1,

               ((!((blinkyX == candidateX) && (blinkyY == candidateY))) &&
                (!((pinkyX == candidateX) && (pinkyY == candidateY))) &&
                (!((clydeX == candidateX) && (clydeY == candidateY))) &&
                ((candidateX >= 0 && candidateX < BOARD_WIDTH) &&
                 (candidateY >= 0 && (candidateY < BOARD_HEIGHT)))) &&
                   (cellFreeNearPacman = 1),

               cellFreeNearPacman && (inkyX = candidateX, inkyY = candidateY));

          // this checks the block to the left of pacman
          (!cellFreeNearPacman) &&
              (candidateX = pacmanX - 1, candidateY = pacmanY,

               ((!((blinkyX == candidateX) && (blinkyY == candidateY))) &&
                (!((pinkyX == candidateX) && (pinkyY == candidateY))) &&
                (!((clydeX == candidateX) && (clydeY == candidateY))) &&
                ((candidateX >= 0 && candidateX < BOARD_WIDTH) &&
                 (candidateY >= 0 && (candidateY < BOARD_HEIGHT)))) &&
                   (cellFreeNearPacman = 1),

               cellFreeNearPacman && (inkyX = candidateX, inkyY = candidateY));

          // this checks the block to the upper left corner of pacman
          (!cellFreeNearPacman) &&
              (candidateX = pacmanX - 1, candidateY = pacmanY - 1,

               ((!((blinkyX == candidateX) && (blinkyY == candidateY))) &&
                (!((pinkyX == candidateX) && (pinkyY == candidateY))) &&
                (!((clydeX == candidateX) && (clydeY == candidateY))) &&
                ((candidateX >= 0 && candidateX < BOARD_WIDTH) &&
                 (candidateY >= 0 && (candidateY < BOARD_HEIGHT)))) &&
                   (cellFreeNearPacman = 1),

               cellFreeNearPacman && (inkyX = candidateX, inkyY = candidateY));

          break;
        }
        case 0:
          break;
        }

        // check if inky is on the same block as pacman
        ((pacmanX == inkyX) && (pacmanY == inkyY))
            ? (gameOver = true, pacmanWon = false)
            : 0;

        break;
      }
      case 1:
        break;
      }

      switch (gameOver) {

      case 0: {

        // this moves pinky in the direction of pacman

        // this finds out the x and y distances of pinky from pacman

        int pinkyXDistanceFromPacman = abs(pinkyX - pacmanX),
            pinkyYDistanceFromPacman = abs(pinkyY - pacmanY);

        (pinkyXDistanceFromPacman > pinkyYDistanceFromPacman)
            ? ((pinkyX > pacmanX) ? (pinkyX--) : (pinkyX++))
            : ((pinkyXDistanceFromPacman < pinkyYDistanceFromPacman)
                   ? ((pinkyY > pacmanY) ? (pinkyY--) : (pinkyY++))
                   : (((pinkyX > pacmanX) ? (pinkyX--) : (pinkyX++)),
                      ((pinkyY > pacmanY) ? (pinkyY--) : (pinkyY++))));

        // check if pinky has caught pacman
        ((pacmanX == pinkyX) && (pacmanY == pinkyY))
            ? (gameOver = true, pacmanWon = false)
            : 0;

        break;
      }
      case 1:
        break;
      }

      switch (gameOver) {

      case 0: {

        // now for moving blinky

        blinkyMovingRight
            ? ((blinkyX == 19) ? (blinkyY = 7, blinkyMovingRight = false)
                               : (blinkyX++))
            : ((blinkyX == 0) ? (blinkyY = 2, blinkyMovingRight = true)
                              : (blinkyX--));

        // now check if blinky has caught pacman
        ((pacmanX == blinkyX) && (pacmanY == blinkyY))
            ? (gameOver = true, pacmanWon = false)
            : 0;

        break;
      }
      case 1:
        break;
      }

      // now the board shall come forth into existence
      cout << "\n";
      for (int j = 0; j < BOARD_HEIGHT; j++) {
        for (int i = 0; i < BOARD_WIDTH; i++) {
          cout << (((i == pacmanX) && (j == pacmanY))
                       ? pacman
                       : (((i == blinkyX) && (j == blinkyY))
                              ? blinky
                              : (((i == pinkyX) && (j == pinkyY))
                                     ? pinky
                                     : (((i == inkyX) && (j == inkyY))
                                            ? inky
                                            : (((i == clydeX) && (j == clydeY))
                                                   ? clyde
                                                   : '*')))));
        }

        cout << "\n";
      }
    }

    (pacmanWon) ? (cout << "\nPacman has Won!\n")
                : (cout << "\nThe ghostbusters have won!\n");

    break;
  }

  default:

    cout << "Invalid question number!";
  }

  return 0;
}
