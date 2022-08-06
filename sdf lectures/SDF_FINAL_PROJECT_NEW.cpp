#include <bits/stdc++.h>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
#include<windows.h>
#include<conio.h>

using namespace std;
//***FRUIT SNAKE**
class FRUIT_SNAKE{
private:
    int h = 20, w = 50;
    int game_check, score;
    int x, y, foodx_axis, foody_axis;
    int mov;
public:
    void FS_MAIN()
{
	system("color 2");
	system("cls");
            cout<<"============================================================\n";
            cout<<"                WELCOME TO FRUIT SNAKE GAME\n";
            cout<<"============================================================\n";
            //PlaySound(TEXT("C:\\Users\\user\\Downloads\\snakeopen.wav"),NULL,SND_SYNC);
            Sleep(500);
            for(int i=5;i>=1;i--)
            {
                cout<<"                       "<<i<<" SECONDS\n";
                //PlaySound(TEXT("C:\\Users\\user\\Downloads\\snakebeep.wav"),NULL,SND_SYNC);
                Sleep(500);
            }
	int your_score;

	// Generate boundary
	position();

	// Until the game is over
	while (!game_check)
    {
		system("color 2");
		your_score=draw_boundary();
		if(your_score>=150)
            break;
		control_keys();
		move_update();
	}
	cout<<"\n+---------------------+\n";
    cout<<"|  FINAL SCORE IS "<<your_score<<"  |\n";
    cout<<"+---------------------+";
    //PlaySound(TEXT("C:\\Users\\user\\Downloads\\snakelose.wav"),NULL,SND_SYNC);
    Sleep(500);
}

void position()
{
	game_check = 0;
	x = h / 2;
	y = w / 2;
g1:
	foodx_axis = rand() % 20;  //0 - 19
	if (foodx_axis == 0 || foodx_axis == 19)
		goto g1;
g2:
	foody_axis = rand() % 50;
	if (foody_axis == 0 || foody_axis == 49)
		goto g2;
	score = 0;
}

int draw_boundary()
{
	system("cls");
	for (int i = 0; i < h; i++)
	{
        for (int j = 0; j < w; j++)
        {
			if (i == 0 || j == 0 || j == w - 1 || i== h -1)
			{
				cout<<"#";
			}
			else
			{
				if (i == x && j == y)
					cout<<"0";        //snake
				else if (i == foodx_axis && j == foody_axis)
					cout<<"*";
				else
					cout<<" ";
			}
		}
		cout<<"\n";
	}

	// Print the score after the
	// game ends
    if(score<=50)
            cout<<"NOT BAD, KEEP GOING!\n";
    else if(score>50 && score<=100)
            cout<<"WELL, THAT'S A GOOD SCORE\n";
    else if(score < 150 && score>100)
    {
        cout<<"YOU'RE ABOUT TO WIN!\n";
    }
    else if(score >= 150)
        cout<<"\nCONGRATULATIONS, YOU WON THE GAME !!\n";
    return score;
}

void control_keys()
{
	if (kbhit())
    {
		switch (getch())
		{
		case 75:
        case 'A':
        case 'a':
			mov = 1;
			break;
		case 80:
        case 's':
        case 'S':
			mov = 2;
			break;
		case 77:
        case 'd':
        case 'D':
			mov = 3;
			break;
		case 72:
        case 'w':
        case 'W':
			mov = 4;
			break;
		case 27:
        //case 'ESC':
			game_check = 1;
			break;
		}
	}
}

void move_update()
{
	Sleep(0);
	switch (mov)
	{
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
}


	// If the game is over
	if(x < 0 || x >= h|| y < 0 || y >= w)
		game_check = 1;

	// If snake reaches the fruit
	// then update the score

	if (x == foodx_axis && y == foody_axis)
        {
        g3:
        foodx_axis = rand() % 20;
        if (foodx_axis == 0 || foodx_axis == 19)
            goto g3;
		//PlaySound(TEXT("C:\\Users\\user\\Downloads\\snakefood.wav"),NULL,SND_SYNC);
		fflush(stdin);
		g4:
		foody_axis = rand() % 50;
		if (foody_axis == 0 || foody_axis == 49)
			goto g4;
		score += 5;
	}
	cout<<"CURRENT SCORE = "<<score;
	cout<<"\n";
    cout<<"PRESS ESC TO QUIT THE GAME:   ";
}


};

//**R P S***
class ROCK_PAPER_SCISSORS_GAME{

     public:
        void RPS_MAIN()
        {
            system("color E0");
            int pp = 0, cp = 0, p1choice, p2choice ,choice , rounds,rps_choice,p1_score=0,p2_score=0;   //cp-> comp points pp-> player points
            char playerChar, compChar,p1,p2;
            char elements[] = {'r', 'p', 's'}; // 1-1   2-1   3-1
            cout<<"\t\t\t\t\t\t\t\t          o--------------------o\n";
            cout<<"\t\t\t\t\t\t\t\t          |WELCOME TO ROCK PAPER SCISSORS|\n";
            cout<<"\t\t\t\t\t\t\t\t          o--------------------o";
            system("cls");
            cout<<"\t\t\t\t\t\t\t\t     ENTER THE NUMBER OF ROUNDS:   ";
            cin>>rounds;
            cout<<"\n\t\t\t\t\t\t\t\t          PLAYER v/s COMPUTER   ";
            //PlaySound(TEXT("C:\\Users\\user\\Downloads\\rpsopen.wav"),NULL,SND_SYNC);
            for (int i = 0; i < rounds; i++)
            {
                 cout<<"\n\t\t\t\t\t\t\t\t          Press 1 for ROCK\n\t\t\t\t\t\t\t\t          Press 2 for PAPER\n\t\t\t\t\t\t\t\t          Press 3 for SCISSORS\n\n";
                 cout<<"\t\t\t\t\t\t\t\t          Player's turn: ";
                 cin>>choice;
                 playerChar = elements[choice - 1];
                 cout<<"\t\t\t\t\t\t\t\t           -----------------\n";
                 cout<<"\t\t\t\t\t\t\t\t          | You chose: "<<playerChar<<"   |\n";
                 cout<<"\t\t\t\t\t\t\t\t           -----------------\n\n";
                 cout<<"\t\t\t\t\t\t\t\t          Computer's turn\n";
                 choice = compturn();
                     compChar = elements[choice - 1];
                 cout<<"\t\t\t\t\t\t\t\t           --------------------\n";
                 cout<<"\t\t\t\t\t\t\t\t          | Computer chose: "<<compChar<<" |\n";
                 cout<<"\t\t\t\t\t\t\t\t           --------------------\n\n";
                 if (condition1(compChar, playerChar) == 'c')
                 {
                     cp++;
                     cout<<"\t\t\t\t\t\t\t\t          You lost this round:\\n\n";
                 }
                 else if (condition1(compChar, playerChar) == 'd')
                 {
                     cout<<"\t\t\t\t\t\t\t\t          It's a draw :\\\n\n";
                 }
                 else
                 {
                     pp++;
                     cout<<"\t\t\t\t\t\t\t\t          You won this round :D\n\n";
                 }
                 cout<<"\t\t\t\t\t\t\t\t           -------------\n";
                 cout<<"\t\t\t\t\t\t\t\t          | You: "<<pp<<"      |\n";
                 cout<<"\t\t\t\t\t\t\t\t          | Computer: "<<cp<<" |\n";
                 cout<<"\t\t\t\t\t\t\t\t           -------------\n\n";
                 cout<<"\t\t\t\t\t\t     ===========================================================\n\n";
                 }
                 cout<<"\t\t\t\t\t\t\t\t          -----------------\n";
                 cout<<"\t\t\t\t\t\t\t\t         |   Final Score   |\n";
                 cout<<"\t\t\t\t\t\t\t\t          -----------------\n";
                 cout<<"\t\t\t\t\t\t\t\t         |  You | Computer |\n";
                 cout<<"\t\t\t\t\t\t\t\t         |------|----------|\n";
                 cout<<"\t\t\t\t\t\t\t\t         |   "<<pp<<"  |    "<<cp<<"     |\n";
                 cout<<"\t\t\t\t\t\t\t\t          -----------------\n\n";
                 if (pp > cp)
                 {
                Sleep(3500*1);
                system("cls");
                cout<<"\n\t\t\t\t\t\t\t\t           -------------------\n";
                cout<<"\t\t\t\t\t\t\t\t          | You Won the match |\n";
                cout<<"\t\t\t\t\t\t\t\t           -------------------\n";
                //PlaySound(TEXT("C:\\Users\\user\\Downloads\\rpswin.wav"),NULL,SND_SYNC);
            }
            else if (pp < cp)
            {
                Sleep(3500*1);
                system("cls");
                cout<<"\n\t\t\t\t\t\t\t\t           ------------------------\n";
                cout<<"\t\t\t\t\t\t\t\t          | Computer Won the match |\n";
                cout<<"\t\t\t\t\t\t\t\t           ------------------------\n";
                //PlaySound(TEXT("C:\\Users\\user\\Downloads\\rpslose.wav"),NULL,SND_SYNC);
            }
            else
            {
                Sleep(3500*1);
                system("cls");
                cout<<"\n\t\t\t\t\t\t\t\t           -------------\n";
                cout<<"\t\t\t\t\t\t\t\t          | It's a draw |\n";
                cout<<"\t\t\t\t\t\t\t\t           -------------\n";
                //PlaySound(TEXT("C:\\Users\\user\\Downloads\\rpsdraw.wav"),NULL,SND_SYNC);
            }
        }

        int compturn()     //Generation of rand no. for comp's turn
        {
        srand(time(0));
		int ct = (rand() % 3) + 1;
        //PlaySound(TEXT("C:\\Users\\user\\Downloads\\rps.wav"),NULL,SND_SYNC);
        return ct;
        }

       char condition1(char comp, char you)     //CONDTIONS WILL CHECKED HERE
       {

          if (comp == you)       //DRAW CONDITION
          {
            return 'd';
          }
          else if(comp == 'r' && you == 's')
          {
            return 'c';
          }
          else if (you == 'r' && comp == 's')
          {
           return 'y';
          }
          else if (comp == 'p' && you == 'r')
          {
            return 'c';
          }
          else if (you == 'p' && comp == 'r')
          {
              return 'y';
          }
          else if (comp == 's' && you == 'p')
          {
              return 'c';
          }
          else if (you == 's' && comp == 'p')
          {
              return 'y';
          }
       }

       char condition2(char p1, char p2)     //CONDTIONS WILL CHECKED HERE
       {
           if (p1 == p2)       //DRAW CONDITION
           {
               return 'd';
           }
           else if (p1 == 'r' && p2 == 's')     // p1 wins return p     p2 wins return q
           {
               return 'p';
           }
           else if (p2 == 'r' && p1 == 's')
           {
               return 'q';
           }
           else if (p1 == 'p' && p2 == 'r')
           {
               return 'p';
           }
           else if (p2 == 'p' && p1 == 'r')
           {
               return 'q';
           }
           else if (p1 == 's' && p2 == 'p')
           {
               return 'p';
           }
           else if (p2 == 's' && p1 == 'p')
           {
               return 'q';
           }
       }
};
//**CASINO GAME***
class CASINO{
   public:
       string playerName;
       int balance; // stores player's balance
       int bettingAmount;
       int guess;
       int dice; // stores the random number
       char choice;

   void rules()
       {
       cout << "\t\t\t\t\t\t\t\t\t======CASINO NUMBER GUESSING RULES!======\n";
       cout << "\t\t\t\t\t\t\t\t\t1. CHOOSE A NUMBER BETWEEN 1-10\n";
       cout << "\t\t\t\t\t\t\t\t\t2. WINNER GETS 10 TIMES OF THE MONEY BET\n";
       cout << "\t\t\t\t\t\t\t\t\t3. WRONG BET, AND YOU LOST THE AMOUNT YOU BET\n\n";
       }
    void casino_main()
    {
    	system("color 75");
       srand(time(0));
       cout << "\t\t\t\t\t\t\t\t\t==============================\n\t\t\t\t\t\t\t\t\t|    WELCOME TO CASINO WORLD   |\n\t\t\t\t\t\t\t\t\t==============================\n\n";
       rules();
       cout << "\n\nPLEASE ENTER YOUR NAME : ";
       cin>>playerName;
       cout << "\n\nENTER THE STARTING BALANCE TO PLAY GAME : $";
       cin >> balance;
       do
       {
           cout << "\n\nYOUR CURRENT BALANCE : $ " << balance << "\n\n";
           do
           {
               cout << "HELLO, " << playerName<<endl;
               cout<<"\n================================================="<<endl;
               cout<<"ENTER AMOUNT TO BET : $ ";
               cin >> bettingAmount;
               cout<<"\n";
               if(bettingAmount > balance){
                   cout << "BETTING BALANCE CAN'T BE MORE THAN CURRENT BALANCE!\n"<<endl;
                   cout<<"================================================="<<endl;
                   cout<<"\nRE-ENTER BALANCE\n ";
               }
           }
           while(bettingAmount > balance);
           do
           {
               cout << "GUESS ANY BETTING BETWEEN 1-10:";
               cin >> guess;
               if(guess <= 0 || guess > 10)
               {
                   cout << "\n\nNUMBER SHOULD BE BETWEEN 1-10\n"<<endl;
                   cout<<"================================================="<<endl;
                   cout<<"RE-ENTER NUMBER:\n";
               }
           }
           while(guess <= 0 || guess > 10);
           dice = rand()%10 + 1;
           try{
           if(dice == guess)
           {
               cout<<"================================================="<<endl;
               cout << "\n\nWOOHOO! YOU'VE WON $ " << bettingAmount * 10;
               cout<<"================================================="<<endl;
               balance = balance + bettingAmount * 10;
           }
           else
           {
               cout<<"================================================="<<endl;
               cout <<"OOPS! BETTER LUCK NEXT TIME"<<endl<<endl;
               cout<<"YOU LOST $ "<< bettingAmount <<"\n";
               cout<<"================================================="<<endl;
               balance = balance - bettingAmount;
           }
           cout << "\nTHE WINNING NUMBER WAS: " << dice <<"\n";
           cout<<"\n================================================="<<endl;
           cout << "\n"<<playerName<<", YOU'VE BALANCE OF :$ " << balance << "\n";
           cout<<"\n================================================="<<endl;
           if(balance == 0)
           {
               throw "=================================================\nYOU'VE NO MONEY TO PLAY\n=================================================";
           }
           cout << "\n\n-->DO YOU WANNA PLAY AGAIN (Y/N)? ";
           cin >> choice;
       }
       catch(char const* a)
           {
               cout<<a;
           }
       }
       while(choice =='Y'|| choice=='y');
       cout << "\n\n\n";
       cout<<"================================================="<<endl;
       cout << "\n\nTHANKS FOR PLAYING THE GAME. YOUR CURRENT BALANCE IS : $ " << balance << "\n\n";
   }

};
//***DRUNK MAN GAME**
class drunk_game{
    public:

    void mechanism()
    {
    	system("color 55");
    	system("color 2");
       srand(time(0));
       const int size=60;
       string x;
       int position = size /2;
       cout << "Enter a name to begin \n ";
       cin>> x;
       int c = 0;
       while (true)
       {
        cout << "|START|" ;
        for (int i=0; i<size;i++)
        {
            if (i == position)
                cout << x;
            else
                cout << " ";
        }
        cout << "|FINISH|" << endl;
        int move= rand()%3 - 1;
        position = position + move;
        if (position <1) {
            cout << "You could not finish the race!" <<endl;
            break;

        }
        if (position >size-1) {
            cout << "Yay! You finished the race" << endl;
            break;

        }
        c++;
        }
        cout<<endl<<"STEPS TAKEN:   "<<c;
    }
};
//***TIC TAC TOE***
class TIC_TAC_TOE{
public:
    void TTT_MAIN()
{
    system("cls");
    int choice;
    cout<<"\t\t\t\t\t\t\t\t\t     =====================\n\t\t\t\t\t\t\t\t\t     \\    TIC TAC TOE    /\n\t\t\t\t\t\t\t\t\t     /                   \\\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\t\t\t\t\\t\t\t\t\t                 =====================\n\n";
    system("color F8");
    //PlaySound(TEXT("C:\\Users\\user\\Downloads\\tttopen.wav"),NULL,SND_SYNC);
    char cr;
    int a,c=1,b;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tPLAYER 1 - 'x'\n\t\t\t\t\t\t\t\t\t\tPLAYER 2 - 'o'\n";
    char g[3][3];
    for(int i=0;i<3;i++)        //Putting space on all the places
    {
        for(int j=0;j<3;j++)
        {
            g[i][j]=' ';
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(c%2!=0)  //odd pos
            {
               cout<<("\t\t\t\t\t\t\t\t\tPlayer 1 enter the position: ");
               a:
               cin>>a; cin>>b;
               //PlaySound(TEXT("C:\\Users\\user\\Downloads\\click.wav"),NULL,SND_SYNC);
                if(g[a][b]==' ')
                {
                    system("cls");
                    g[a][b]='x';
                    cout<<"\t\t\t\t\t\t\t\t\t\t      |   |   \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t    "<<g[0][0]<<" | "<<g[0][1]<<" | "<<g[0][2]<<" \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t   ___|___|___\n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t      |   |   \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t    "<<g[1][0]<<" | "<<g[1][1]<<" | "<<g[1][2]<<" \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t   ___|___|___\n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t      |   |   \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t    "<<g[2][0]<<" | "<<g[2][1]<<" | "<<g[2][2]<<" \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t      |   |   \n";
                    if(g[0][0]=='x' && g[0][1]=='x' && g[0][2]=='x')
                    {
                        cr=g[0][0];
                        break;
                    }
                    else if(g[0][0]=='x' && g[1][0]=='x' && g[2][0]=='x')
                    {
                        cr=g[0][0];
                        break;
                    }
                    else if(g[0][1]=='x' && g[1][1]=='x' && g[2][1]=='x')
                    {
                        cr=g[0][1];
                        break;
                    }
                    else if(g[0][2]=='x' && g[1][2]=='x' && g[2][2]=='x')
                    {
                        cr=g[0][2];
                        break;
                    }
                    else if(g[1][0]=='x' && g[1][1]=='x' && g[1][2]=='x')
                    {
                        cr=g[1][0];
                        break;
                    }
                    else if(g[2][0]=='x' && g[2][1]=='x' && g[2][2]=='x')
                    {
                        cr=g[2][0];
                        break;
                    }
                    else if(g[0][0]=='x' && g[1][1]=='x' && g[2][2]=='x')
                    {
                        cr=g[0][0];
                        break;
                    }
                    else if(g[0][2]=='x' && g[1][1]=='x' && g[2][0]=='x')
                    {
                        cr=g[0][2];
                        break;
                    }
                }
                else
                {
                   cout<<"\n\t\t\t\t\t\t\t\t\tSorry you can't draw here!\n";
                   cout<<"\t\t\t\t\t\t\t\t\tEnter again: ";
                   goto a;
                }
            }
            else
            {
               cout<<("\t\t\t\t\t\t\t\t\tPlayer 2 enter the position: ");
               a2:
               cin>>a; cin>>b;

                if(g[a][b]==' ')
                {
                    system("cls");
                    g[a][b]='o';
                    cout<<"\t\t\t\t\t\t\t\t\t\t      |   |   \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t    "<<g[0][0]<<" | "<<g[0][1]<<" | "<<g[0][2]<<" \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t   ___|___|___\n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t      |   |   \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t    "<<g[1][0]<<" | "<<g[1][1]<<" | "<<g[1][2]<<" \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t   ___|___|___\n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t      |   |   \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t    "<<g[2][0]<<" | "<<g[2][1]<<" | "<<g[2][2]<<" \n";
                    cout<<"\t\t\t\t\t\t\t\t\t\t      |   |   \n";
                    if(g[0][0]=='o' && g[0][1]=='o' && g[0][2]=='o')
                    {
                        cr=g[0][0];
                        break;
                    }
                    else if(g[0][0]=='o' && g[1][0]=='o' && g[2][0]=='o')
                    {
                        cr=g[0][0];
                        break;
                    }
                    else if(g[0][1]=='o' && g[1][1]=='o' && g[2][1]=='o')
                    {
                        cr=g[0][1];
                        break;
                    }
                    else if(g[0][2]=='o' && g[1][2]=='o' && g[2][2]=='o')
                    {
                        cr=g[0][2];
                        break;
                    }
                    else if(g[1][0]=='o' && g[1][1]=='o' && g[1][2]=='o')
                    {
                        cr=g[1][0];
                        break;
                    }
                    else if(g[2][0]=='o' && g[2][1]=='o' && g[2][2]=='o')
                    {
                        cr=g[2][0];
                        break;
                    }
                    else if(g[0][0]=='o' && g[1][1]=='o' && g[2][2]=='o')
                    {
                        cr=g[0][0];
                        break;
                    }
                    else if(g[0][2]=='o' && g[1][1]=='o' && g[2][0]=='o')
                    {
                        cr=g[0][2];
                        break;
                    }
                }
                else
                {
                    cout<<"\n\t\t\t\t\t\t\t\t\tSorry you can't draw here!\n";
                    cout<<"\t\t\t\t\t\t\t\t\tEnter again: ";
                    goto a2;
                }
            }
            c++; // 1 2 3 4
        }
        if(cr=='x'||cr=='o')
            break;
    }
    if(cr=='x')
    {
        cout<<"\t\t\t\t\t\t\t\t\t       ___________________\n\t\t\t\t\t\t\t\t\t      |   PLAYER 1 WON!   |\n\t\t\t\t\t\t\t\t\t      |___________________|\n";
        //PlaySound(TEXT("C:\\Users\\user\\Downloads\\win.wav"),NULL,SND_SYNC);
    }
    else if(cr=='o')
    {
        cout<<"\t\t\t\t\t\t\t\t\t       ___________________\n\t\t\t\t\t\t\t\t\t      |   PLAYER 2 WON!   |\n\t\t\t\t\t\t\t\t\t      |___________________|\n";
        //PlaySound(TEXT("C:\\Users\\user\\Downloads\\win.wav"),NULL,SND_SYNC);
    }
    else
    {
        cout<<"\t\t\t\t\t\t\t\t\t       ___________________\n\t\t\t\t\t\t\t\t\t      |       DRAW!       |\n\t\t\t\t\t\t\t\t\t      |___________________|\n";
        //PlaySound(TEXT("C:\\Users\\user\\Downloads\\lose.wav"),NULL,SND_SYNC);
    }
    Sleep(900);
    system("cls");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    SEE YOU IN NEXT GAME\n";
}
};
//**HAND CRICKET***
class HAND_CRICKET{
public:
    int run()
{
		srand(time(0));
		int num =(rand()%6)+1;
        return num;
}
void HC_MAIN()
{
    char player_choice;
    string player_name;
	int batsman_name;
	system("cls");
	system("color 6");
    cout<<"\t\t\t\t\t\t\t   ============================================================\n";
    cout<<"\t\t\t\t\t\t\t                   WELCOME TO HAND CRICKET GAME\n";
    cout<<"\t\t\t\t\t\t\t   ============================================================\n";
	top:
    fflush(stdin);
	cout<<"\n\t\t\t\t\t\t\t\t    DO YOU WANT TO PLAY USING YOUR OWN NAME?\n";
	cout<<"\t\t\t\t\t\t\t\t    IF YES,PRESS 'Y'. IF NO, PRESS 'N'\n";
	cin>>player_choice;
	system("cls");
	fflush(stdin);
	if(player_choice=='Y'||player_choice=='y')
    {
        cout<<"\n\t\t\t\t\t\t\t\t   OKAY CHAMP! ENTER YOUR NAME:   ";
        getline(cin,player_name);
        system("cls");
    }
    else if(player_choice == 'N'||player_choice=='n')
    {
        re_choose:
        cout<<"\n\t\t\t\t\t\t\t  PLEASE CHOOSE ONE OF THE PLAYER FROM THE BELOW LIST";
        cout<<"\n\t\t\t\t\t\t\t\t     1.  VIRAT KOHLI\n\t\t\t\t\t\t\t\t     2.  ROHIT SHARMA\n\t\t\t\t\t\t\t\t     3.  MS DHONI\n\t\t\t\t\t\t\t\t     4.  KL RAHUL\n\t\t\t\t\t\t\t\t     5.  HARDIK PANDYA\n\t\t\t\t\t\t\t\t     6.  RAVINDRA JADEJA\n\t\t\t\t\t\t\t\t     7.  RISHABH PANT\n\t\t\t\t\t\t\t\t     8.  JASPRIT BUMRAH\n\t\t\t\t\t\t\t\t     9.  MOHAMMED SHAMI\n\t\t\t\t\t\t\t\t     10. YUZVENDRA CHAHAL\n\t\t\t\t\t\t\t\t     11. BHUVNESHWAR KUMAR\n";
        cin>>batsman_name;
        system("cls");
        switch(batsman_name)
        {
        case 1:
            {
                player_name = "VIRAT KOHLI";
                break;
            }
        case 2:
            {
                player_name = "ROHIT SHARMA";
                break;
            }
        case 3:
            {
                player_name = "MS DHONI";
                break;
            }
        case 4:
            {
                player_name = "KL RAHUL";
                break;
            }
        case 5:
            {
                player_name = "HARDIK PANDYA";
                break;
            }
        case 6:
            {
                player_name = "RAVINDRA JADEJA";
                break;
            }
        case 7:
            {
                player_name = "RISHABH PANT";
                break;
            }
        case 8:
            {
                player_name = "JASPRIT BUMRAH";
                break;
            }
        case 9:
            {
                player_name = "MOHAMMED SHAMI";
                break;
            }
        case 10:
            {
                player_name = "YUZVENDRA CHAHAL";
                break;
            }
        case 11:
            {
                player_name = "BHUVNESHWAR KUMAR";
                break;
            }
        default:
            {
                cout<<"\t\t\t\t\t\t\t\t\t     INVALID CHOICE\n";
                goto re_choose;
                break;
            }
        }
    }
    else
    {
        cout<<"\t\t\t\t\t\t\t\t\t     Invalid choice !!";
        goto top;
    }
	int score=0, hit=NULL;
	srand(time(0));
	while(true)
	{
        try{

        if(hit<=6)
        {
            re_enter:
            cout<<"\n\n\t\t\t\t\t\t\t\t\t     HIT: ";
            cin>>hit;
            system("cls");
        }
	    if(run()== hit)
	    {
	        break;
	    }
	    else if(hit>6)
        {
            throw "\t\t\t\t\t\t\t\t\t     DEAD BALL\n";
            goto re_enter;
        }
        }
        catch(char const* b)
        {
            cout<<b;
        }
	    score+=hit;
	}
    cout<<"\n\n\t\t\t\t\t\t\t\t    +++++++++++++++++++++++++++++++++++++++++\n\t\t\t\t\t\t\t\t\t              OUT!!!"<<endl;
    cout<<"\t\t\t\t\t\t\t\t            "<<player_name<<" MADE "<<score<<" RUNS "<<endl;
    cout<<"\t\t\t\t\t\t\t\t    +++++++++++++++++++++++++++++++++++++++++"<<endl;
    getch();
    Sleep(1000);
}
};

int main()
{
    system("cls");
    int menu_choice;
    Sleep(2000*1);
    cout<<"\n\t\t\t\t\t\t  =============================WECLCOME============================\n";
    cout<<"\t\t\t\t\t\t\t              WELCOME TO OUR ARCADE GAME\n";
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    Sleep(3000*1);
    system("cls");
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    cout<<"\t\t\t\t\t\t\t        HERE YOU CAN PLAY ANY GAME CREATED BY US\n";
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    Sleep(3000*1);
    system("cls");
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    cout<<"\t\t\t\t\t\t\t          YOU SEE THE GAME MENU SHORTLY :)\n";
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    Sleep(3000*1);
    system("cls");
    invalid:
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    cout<<"\t\t\t\t\t\t\t     PLEASE SELECT THE GAME WHICH YOU WANNA PLAY\n";
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    Sleep(1000*1);
    cout<<"\t\t\t\t\t\t\t                  o-----------------o\n";
    cout<<"\t\t\t\t\t\t\t                  | 1. TIC-TAC-TOE  |\n";
    cout<<"\t\t\t\t\t\t\t                  o-----------------o";
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    system("color 2");
    Sleep(1000*1);
    cout<<"\t\t\t\t\t\t\t               o------------------------o\n";
    cout<<"\t\t\t\t\t\t\t               | 2. ROCK-PAPER-SCISSOR  |\n";
    cout<<"\t\t\t\t\t\t\t               o------------------------o";
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    system("color 3");
    Sleep(1000*1);
    cout<<"\t\t\t\t\t\t\t                  o-----------------o\n";
    cout<<"\t\t\t\t\t\t\t                  | 3. HAND CRICKET |\n";
    cout<<"\t\t\t\t\t\t\t                  o-----------------o";
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    system("color 4");
    Sleep(1000*1);
    cout<<"\t\t\t\t\t\t\t                  o-----------------o\n";
    cout<<"\t\t\t\t\t\t\t                  | 4. FRUIT SNAKE  |\n";
    cout<<"\t\t\t\t\t\t\t                  o-----------------o";
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    system("color 5");
    Sleep(1000*1);
    cout<<"\t\t\t\t\t\t\t                 o-------------------o\n";
    cout<<"\t\t\t\t\t\t\t                 | 5.DRUNK MAN RACE  |\n";
    cout<<"\t\t\t\t\t\t\t                 o---------=---------o";
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    system("color 6");
    Sleep(1000*1);
    cout<<"\t\t\t\t\t\t\t             o--------------------------o\n";
    cout<<"\t\t\t\t\t\t\t             | 6.CASINO NUMBER GUESSING |\n";
    cout<<"\t\t\t\t\t\t\t             o--------------------------o";
    cout<<"\n\t\t\t\t\t\t  =================================================================\n";
    system("color 8");
    Sleep(1000*1);
    cout<<"\t\t\t\t\t\t\t                     o----------o\n";
    cout<<"\t\t\t\t\t\t\t                     | 7. EXIT  |\n";
    cout<<"\t\t\t\t\t\t\t                     o----------o";
    cout<<"\n\t\t\t\t\t\t  =================================X==============================\n";
    system("color 7");
    cin>>menu_choice;
    switch(menu_choice)
    {
    case 1:
        {
            //tic tac toe
            system("cls");
            TIC_TAC_TOE ob1;
            ob1.TTT_MAIN();
            break;
        }
    case 2:
        {
            system("cls");
            // rps
            ROCK_PAPER_SCISSORS_GAME ob3;
            ob3.RPS_MAIN();
            ob3.compturn();
            ob3.condition1('a','b');
            ob3.condition2('m','n');
            break;
        }
    case 3:
        {
            system("cls");
            //hand cricket
            HAND_CRICKET ob6;
            ob6.HC_MAIN();
            break;
        }
    case 4:
        {
            system("cls");
            //fruit snake
            FRUIT_SNAKE ob2;
            ob2.FS_MAIN();
            break;
        }
    case 5:
        {
            system("cls");
            //DRUNK MAN RACE
            drunk_game ob5;
            ob5.mechanism();
            break;
        }
    case 6:
        {
            system("cls");
            //CASINO
            CASINO ob4;
            ob4.casino_main();
            break;
        }
    case 7:
        {
           system("cls");
           cout<<"\t\t\t\t\t\t          ============================================================\n";
           cout<<"\t\t\t\t\t\t                      WE HOPE THAT YOU ENJOYED OUR GAME\n";
           cout<<"\n\t\t\t\t\t\t          ============================================================\n";
           cout<<"\t\t\t\t\t\t                                   CREATED BY\n";
           cout<<"\n\t\t\t\t\t\t          ============================================================\n";
           cout<<"\t\t\t\t\t\t                                  SRIYUT SRIVAS\n";
           cout<<"\n\t\t\t\t\t\t          ============================================================\n";

            Sleep(3000*1);
            system("cls");
            cout<<"\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                      WE HOPE THAT YOU ENJOYED OUR GAME\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                   CREATED BY\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                   NITIN KUMAR\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";

            Sleep(3000*1);
            system("cls");
            cout<<"\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                      WE HOPE THAT YOU ENJOYED OUR GAME\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                   CREATED BY\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                   KHYATI DUA\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            
            Sleep(3000*1);
            system("cls");
            cout<<"\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                      WE HOPE THAT YOU ENJOYED OUR GAME\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                   CREATED BY\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                   RIYA ARORA\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            Sleep(3000*1);


            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                               UNDER THE GUIDANCE OF\n";
            cout<<"\t\t\t\t\t\t          ============================================================\n";
            cout<<"\n\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                 DR. ARTI JAIN\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            Sleep(3000*1);
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                               UNDER THE GUIDANCE OF\n";
            cout<<"\t\t\t\t\t\t          ============================================================\n";
            cout<<"\n\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                              MRS. AMBALIKA SARKAR\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";

            Sleep(3000*1);
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                SPECIAL THANKS TO";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<("color 3");
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                 STACK OVERFLOW\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";

            Sleep(3000*1);
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                SPECIAL THANKS TO\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            system("color 2");
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                 GEEKS FOR GEEKS\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";

            Sleep(3000*1);
            system("cls");
            cout<<"\t\t\t\t\t\t                                SPECIAL THANKS TO";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ============================================================\n";
            system("color 5");
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                   JAVATPOINT\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";

            Sleep(3000*1);
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                SPECIAL THANKS TO";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            system("color 1");
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                     GITHUB\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";

            Sleep(3000*1);
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                SPECIAL THANKS TO";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            system("color 4");
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                    YOUTUBE\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";

            Sleep(3000*1);
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                SPECIAL THANKS TO";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            system("color 3");
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                     MIXKIT\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";

            Sleep(3000*1);
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                SPECIAL THANKS TO";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            system("color 4");
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                      QUORA\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";

            Sleep(3000*1);
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                SPECIAL THANKS TO";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            system("color 6");
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            cout<<"\t\t\t\t\t\t                                    CREATELY\n";
            cout<<"\n\t\t\t\t\t\t          ============================================================\n";
            Sleep(3000*1);
            system("cls");
            system("color 1"); 


            cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t          ============================================================\n\t\t\t\t\t\t\t  #\t\t\t\t\t\t\t     #\n\t\t\t\t\t\t\t  #";
            cout<<"                        THANK YOU <3                      #\n";
            cout<<"\t\t\t\t\t\t\t  #\t\t\t\t\t\t\t     #\n\t\t\t\t\t\t\t  ============================================================\n\n\n\n\n\n\n\n\n\n\n";
            exit(0);
        }
    default:
        {
            //DO NOTHING
            system("cls");
        }
    }
    try{
    if(menu_choice>7){
        throw "\n\t\t\t\t\t          ============================================================\n\t\t\t\t\t\t         PLEASE ENTER AGAIN YOU PRESSED THE WRONG KEY\n\t\t\t\t\t          ============================================================\n";
    }
    }
    
            //wrong choice
            catch(char const* c)
            {

                cout<<c;
                Sleep(2000);
                system("cls");
                goto invalid;
            }
}
