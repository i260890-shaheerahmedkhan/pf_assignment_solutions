#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(){

int question;

cout<<"Enter the Question number ( 1 to 8 ) to play: ";
cin>>question;

switch(question){

case 1:
	{
	char type;
	int game,timeLeft,guardAlert,injuries,lightsOn,cameras,takeNeedles,needles,takeBandages,bandages,takeMarbles,marbles,takeRope,ropeM,packKg,stamina,playersLeft,bet,stake,favor,cash,debt,card,ally;

	int Needle = 150, Bandage = 350, Marble = 60, Rope = 120;
	int NeedleCost = 0,MarbleCost = 0,BandageCost = 0,RopeCost = 0;

	cout<<"Enter the type of character you are ( A for Athlete, T for Thinker, G for Gambler ): ";
	cin>>type;
	(type == 'A')?(Rope = 100):((type == 'T')?(Needle = 120):(Marble = 45));
	cout<<"Select the game \n 1 = Red Light Green Light\n 2 = Honeycomb\n 3 = Tug of War\n 4 = Marbles\n 5 = Glass Bridge\n ";
	cin>>game;
	cout<<"Enter the time left until the starting of the game in minutes (0-120): ";
        cin>>timeLeft;
	cout<<"Enter the guard alert (0-100): ";
	cin>>guardAlert;
	cout<<"What are the injuries (0-3): ";
	cin>>injuries;
	cout<<"Are the lights on: \n 1 for on \n 0 for off\n ";
	cin>>lightsOn;
	cout<<"State of VIP cameras: \n 1 for active \n 0 for not active\n ";
	cin>>cameras;
	cout<<"Will you take needles ( 0 for no , 1 for yes ): ";
	cin>>takeNeedles;
	cout<<"What is the number of needles (0-40): ";
	cin>>needles;
	cout<<"Will you take bandages ( 0 for no , 1 for yes ): ";
	cin>>takeBandages;
	cout<<"Enter the number of bandages (0-30): ";
	cin>>bandages;
	cout<<"Will you take marbles ( 0 for no , 1 for yes ): ";
	cin>>takeMarbles;
	cout<<"Enter the number of marbles (0-100): ";
	cin>>marbles;
	cout<<"Will you take the rope ( 0 for no , 1 for yes ): ";
	cin>>takeRope;
	cout<<"Enter the length of the rope in metres (0-60): ";
	cin>>ropeM;
	cout<<"What is the weight you carry in kg (0-150): ";
	cin>>packKg;
	cout<<"Enter your stamina (0-100): ";
	cin>>stamina;
	cout<<"Enter the players left (2-456): ";
	cin>>playersLeft;
	cout<<"What do you bet \n 0 = No bet\n 1 = SAFE \n 2 = RISKY \n ";
	cin>>bet;
	(bet != 0) && (cout << "Enter your stake (0-2000): ", cin >> stake); 
	cout<<"Do you have a favor \n 0 = None\n 1 = INSIDER\n 2 = HUSH\n 3 = MEDPASS\n ";
	cin>>favor;
	cout<<"Enter the cash you have (0-6000): ";
	cin>>cash;
	cout<<"Enter your debt (0-3000): ";
	cin>>debt;
	cout<<"Do you have an invitation card ( 0 for no , 1 for yes ): ";
	cin>>card;
	cout<<"Do you have an ally ( 0 for no , 1 for yes ): ";
	cin>>ally;
	
	int discountedNeedlePrice = (Needle * 75)/100;
       	int discountedMarblePrice = (Marble * 50)/100;	
	takeNeedles ? (NeedleCost = (10 * Needle) + ((needles - 10) * discountedNeedlePrice)):(NeedleCost = 0);
       	takeMarbles ? (MarbleCost = (50 * Marble) + ((marbles - 50) * discountedMarblePrice)):(MarbleCost = 0);
	takeBandages ? (BandageCost = Bandage * (bandages - bandages/3)):(BandageCost = 0);
	takeRope ? (RopeCost = ropeM * Rope):(RopeCost = 0);

	int alertAdj = guardAlert;
	takeMarbles ? (alertAdj += marbles/5):0;
	takeRope ? (alertAdj += ropeM/3):0;
	lightsOn && (alertAdj += 10);
	cameras && (alertAdj += 5);
	(alertAdj > 100) && (alertAdj = 100);

	int dangerPoints = 0;
	(playersLeft > 300) ? (dangerPoints += 3):((playersLeft > 150) ? (dangerPoints += 2):((playersLeft > 50) ? (dangerPoints += 1):0));
	(alertAdj >= 70) ? (dangerPoints += 2):((alertAdj >= 40) ? (dangerPoints += 1):0);
	(game >= 4) ? (dangerPoints += 2):((game >= 2) ? (dangerPoints += 1):0);
	cameras && (dangerPoints += 1);
	!lightsOn && (dangerPoints -= 1);
	(dangerPoints < 0) && (dangerPoints = 0);
	
	int SurchargePct;
	(dangerPoints >= 7) ? (SurchargePct = 50):((dangerPoints >= 5) ? (SurchargePct = 25):((dangerPoints >= 3) ? (SurchargePct = 10):0));
	int NeedleS = (NeedleCost * (100 + SurchargePct))/100;
	int BandageS = (BandageCost * (100 + SurchargePct))/100;
	int MarbleS = (MarbleCost * (100 + SurchargePct))/100;
	int RopeS = (RopeCost * (100 + SurchargePct))/100;
	int itemsAfterSurcharge = NeedleS + BandageS + MarbleS + RopeS;

	int LateFee = (timeLeft < 15 ) ? 250 : ((timeLeft < 45) ? 100 : 0);
	int GuardToll = (card && !cameras) ? 0 : (50 + (alertAdj/10) * 5);
	int base = (type == 'A') ? 40 : ((type == 'T') ? 30 : 35); 
	int carryCap = ally && (base + 10);




break;
	}
case 2:
{
	double U,V,x,D;
	double Wo = 0.8, B = 0.12, Uo = 15.0, u = 3.4, Do = 0.5;

	cout<<"\nEnter the WindSpeed (in km/h): ";
	cin>>U;
	cout<<"Enter the Terrain slope (in radians): ";
	cin>>x;
	cout<<"Enter the vegetation fuel dryness index: ";
	cin>>D;

	V = (Wo * exp(B * U)) + (Uo * sin(x) * sin(x)) + (u * log((D + 1.0)/Do)) + sqrt(U * cos(x) + 1.0);

	cout<<"\nWildfire propagation velocity V = "<<setprecision(4)<<V;

	int Vint = V;
	int F1 = ((V - Vint) * 100.0);
	int F2 = ((((V - Vint) * 100.0 ) - F1) * 100.0);
	long long rollLast4 = 0890;
	int R = (rollLast4 % 89) + 10;
	int K = (Vint * pow(10,6)) + (F1 * pow(10,4)) + (F2 * pow(10,2)) + R;






break;
}

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

cout<<"Invalid question number!";

}


return 0;
}
