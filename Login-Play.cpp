- 👋 Hi, I’m @Awdhesh9211
- 👀 I’m interested in ...Coding
- 🌱 I’m currently learning ...C++
/*
   $$ CREATOR $$
ANIL      PRAJAPATI      ----->ANIL.LOGIN
ANUP      POONHEN        ----->ANUP.LOGIN
AWDHESH   GAUND          ----->AWDHESH.GAME
BENNY     NADAR          ----->BENNY.GAME
*/




#include<iostream>
#include<stdlib.h> 
#include<conio.h>
#include<fstream>
#include<string.h>
#include<windows.h>
#include<time.h>
using namespace std;
//declaration of functions 
void login();
void reg();
void forgot();
void game();
void display_board();
void player_turn();
bool gameover();


int main(){
    system("color F4");
    system("cls");  
	char c;
	cout<<"\t\t\t____________________________________________________________________________\n\n";
	cout<<"\t\t\t               W       E       L       C       O       M       E            \n";
	cout<<"\t\t\t ________________________                          ________________________\n";
	cout<<"\t\t\t|                           ------- MENUE ------                           |\n";
	cout<<"\t\t\t|                                                                          |\n";
	cout<<"\t\t\t|                               1 - LOGIN                                  |\n";
  cout<<"\t\t\t|                               2 - REGISTER                               |\n";
	cout<<"\t\t\t|                               3 - FORGOT PASSWORD                        |\n";
	cout<<"\t\t\t|                               4 - EXIT                                   |\n";
	cout<<"\t\t\t|                                                                          |\n";
	cout<<"\t\t\t|__________________________________________________________________________|\n";
	
	cout<<"\n\t\t\t                             Enter your Choice :";
	cin>>c;
	cout<<"\n\t\t\t____________________________________________________________________________\n";
	
	cout<<endl;
	
	switch (c)
	{
		case '1':
			  system("cls");
		      login();
		      break;
		     
		case '2':
			  system("cls");
		      reg();
	          break;
	        
		case '3':
			  system("cls");
		      forgot();
		      break;
		
		case '4':
		      cout<<"\t\t\t T H A N K     Y O U! \n\n";
		      break;
		default:
		      cout<<"\t\t\t Invalid Option \n";
			  system("pause");
			  main();			
	}
	
		
}
void login()
{   system("color F4");
	int count=0;
	int i=1;
	string uid,pass,id,p;
	system("cls");
    
	while(i<=3)
	{   system("cls");
	    if(i>1){
		 cout<<"\n\t\t\t\tPlease Try again!";
		 cout<<"\n\n\t\t\t\t"<<(4-i)<<" "<<"Tries left";
	    }
    	cout<<"\n\n\n\t\t\t\t\t------------------ L O G I N ---------------------\n\n";
	    cout<<"\t\t\t\t\t    | Please Enter your user id & password |\n";
	    cout<<"\t\t\t\t\t__________________________________________________\n";
	    cout<<"\n\t\t\t\t\t            User ID   : ";
	    cin>>uid;
	    cout<<"\n\t\t\t\t\t            Password  : ";
	    cin>>pass;
	    fstream a;
        a.open("rec.txt",ios::app|ios::in);
	    while(a>>id>>p)
	    {
		    if (id==uid&&p==pass)
		       {
			    count=1;
		       }
	   }
    	a.close();
	 
	   if(count==1){
	   cout<<"\n\t\t\tLOGIN SUCCESSFULL";
	   for(int i=1;i<=3;i++){
        Sleep(500);
	 	cout<<"!";
	    }
	   
	   game();
	   }
       if(i==3&&count==0){
	   cout<<"\n\n\t\t\t\t\tLogin Error\n";
	   cout<<"\n\n\t\t\t\t\tRedirecting to forget page\n";
       for(int i=1;i<=3;i++){
        Sleep(500);
	 	cout<<".";
	   }
	   forgot();
	   }
	
    
      i++;
    }
	
}
void reg()
{   

	string ruid="0",rpass,rid,rp;
	string z,c;//used to check existing crediancial
	system("cls");
	cout<<"\n\n\n\t\t\t\t\t-------------R E G I S T R A T O N----------------\n\n";
	cout<<"\t\t\t\t\t      | Create your user name & password |\n";
	cout<<"\t\t\t\t\t__________________________________________________\n";
	    

	cout<<"\n\n\n\n\n\t\t\t\t\t\t Enter the User id  : ";
	cin>>ruid;
	cout<<"\n\n\t\t\t\t\t\t Enter the password : ";
	cin>>rpass;
		    
		fstream b;
        b.open("rec.txt",ios::app|ios::in);
	    while(b>>z>>c)
	    {
		    if (z==ruid)
		       {
			    cout<<"\n\t\t\t\t\tOh Sorry! This User id already exists :"<<ruid;
       	        cout<<"\n\n\t\t\t\t\tTRY AGAIN";
       	        for(int i=1;i<=6;i++){
                Sleep(500);
	 	        cout<<".";
	           }
       	       reg();
	           }
	
	    }
    	b.close();
    
    
	    fstream f1;
        f1.open("rec.txt",ios::app|ios::out);
	    f1<<ruid<<" "<<rpass<<endl;
	    system("cls");
	    f1.close();
	    cout<<"\n\n\n\n\n\n\t\t\t\t\tRegistrition is Successful\n";
    	cout<<"\n\n\n\t\t\t\t\tRedirecting to Login page";
	    for(int i=1;i<=3;i++){
        Sleep(500);
	 	cout<<".";
	   }
	   login();
}
void forgot()
{
	int count=0;
	string suid,sid,spass;
	system("cls");
	cout<<"\n\t\t\t Forgot the password ? No worries\n";
	cout<<"\n\t\t\t Enter userid To Get your Information : ";
	cin>>suid;
	fstream input; 
	input.open("rec.txt",ios::app|ios::in);
	while(input>>sid>>spass)
	{
		if (sid==suid)
		{
			count=1;
			
		}
		
	}
	input.close();
	if (count==1)
	{   
		cout<<"\n\n\n\t\t\t Your account has been found";
		cout<<"\n\n\n\t\t\t Your password is : "<<spass;
		getch();
		cout<<"\n\n\n\n\n\t\t\tRedirecting to Main page";
		for(int i=1;i<=3;i++){
        Sleep(500);
	 	cout<<".";
	   }
	    main();
		
	}
	else 
	{
		cout<<"\n\t\t\t Sorry with this user id no record is found in our data base";
		system("pause");
		cout<<"\n\n\n\n\n\t\t\tRedirecting to Main page";
		for(int i=1;i<=4;i++){
        Sleep(500);
	 	cout<<".";
	    }
	    main();
	}
	
	
}


// GAME 
//Array for the board 
char board[3][3] = {{'0','1','2'},{'3','4','5'},{'6','7','8'}}; 
 
    
//Variable Declaration 
int count=0; 
int choice;
int row,column; 
char turn = 'X'; 
bool draw = false; 
//Function to show the current status of the gaming board 
void display_board(){ 
 //Game Board LAYOUT 

system("cls");

system("color F4");
cout<<"\n\n\t\t\t\t T I C  -- T A C -- T O E -- G A M E  \n\n\n";
if(count==0){
 cout<<"\t\t| Enter only Integer | YOU ARE PLAYING WITH COMPUTER | Enter 10 to Exit |\n\n";	
}
else{
 cout<<"\t\t| Enter only Integer | YOU ARE PLAYING WITH PLAYER 2 | Enter 10 to Exit |\n\n";	
}
cout<<"\t\t\t\t\t _____ _____ _____\n";
cout<<"\t\t\t\t\t|     |     |     |\n"; 
cout<<"\t\t\t\t\t| " <<" "<<board[0][0]<<"  | " <<" "<<board[0][1]<<"  | " <<" "<<board[0][2]<<"  |\n"; 
cout<<"\t\t\t\t\t|_____|_____|_____|\n"; 
cout<<"\t\t\t\t\t|     |     |     |\n"; 
cout<<"\t\t\t\t\t| " <<" "<<board[1][0]<<"  | " <<" "<<board[1][1]<<"  | " <<" "<<board[1][2]<<"  |\n"; 
cout<<"\t\t\t\t\t|_____|_____|_____|\n"; 
cout<<"\t\t\t\t\t|     |     |     |\n"; 
cout<<"\t\t\t\t\t| " <<" "<<board[2][0]<<"  | "<<" "<<board[2][1]<<"  | "<<" "<<board[2][2]<<"  |\n"; 
cout<<"\t\t\t\t\t|_____|_____|_____|\n"; 
}

//Function to get the player input and update the board 
void player_turn(){
	int d,e;
    srand(time(0));
    d=rand()%8;
    if (count==1)
	{
    if(turn == 'X'){ 
        cout<<"\n\t\tPLAYER - 1 [X] turn : "; 
        cin>>choice;
        } 
    else if(turn == 'O'){ 
        cout<<"\n\t\tPLAYER - 2 [O] turn : "; 
        cin>>choice;
        }
    }
    if (count==0)
    {
    if(turn == 'X'){ 
        cout<<"\n\t\tPLAYER - 1 [X] turn : ";
		cin>>choice; 
        } 
    else if(turn == 'O'){ 
        cout<<"\n\t\tCOMPUTER - 2 [O] turn : "; 
        choice=d;
        cout<<choice;
        Sleep(100);
        }
    }
   
        //Taking input from user 
        //updating the board according to choice and reassigning the turn Start 
		
       //if else ladder to get which row and column will be update 
     
    if(choice==0)
		  {
		   row=0; column=0;
	      }
    else if(choice==1)
		  {
		   row=0; column=1;
	      }
	else if(choice==2)
		  {
		   row=0; column=2;
	      } 
	else if(choice==3)
		  {
		   row=1; column=0;
	      } 
	else if(choice==4)
		  {
		   row=1; column=1;
	      } 
	else if(choice==5)
		  {
		   row=1; column=2;
	      }
    else if(choice==6)
		  {
		   row=2; column=0;
	      } 
    else if(choice==7)
		  {
		   row=2; column=1;
	      } 
    else if(choice==8)
		  {
		   row=2; column=2;
	      }
	else if(choice==10)
	      {
		  
	            char w;
	            cout<<"Are you Sure you want to Exit?\n Y - Exit \n N - Continue\n";
	            cin>>w;
	            if(w=='Y'||w=='y')
	              {
	  	           main();
	              }
	            else if(w=='N'|| w=='n')
	              {
	  	           player_turn();
	              }
	            else
	              {
	  	           cout<<"Invalid Input";
	              }
          }
    else
        {
        	cout<<"invalid input";
        	player_turn();
		}
    	
   if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){ 
    //updating the position for 'X' symbol if 
    //it is not already occupied 
    board[row][column] = 'X'; 
    turn = 'O'; 
    }
   else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){ 
    //updating the position for 'O' symbol if //it is not already occupied 
    board[row][column] = 'O'; 
    turn = 'X'; 
    }
   else { 
   //if input position already filled 
   cout<<"\nBox already filled!n Please choose another!!\n\n"; 
   player_turn(); 
     } 
    /* Ends */ 
    display_board(); 
} 


   //Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE 
bool gameover(){ 
  //checking the win for Rows and Column 
  for(int i=0; i<3; i++){
     if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) 
     return false; 
     }
  //checking the win for both diagonal 
  if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) 
    {
	 return false; 
     }
  //Checking the game is in continue mode or not 
  for(int i=0; i<3; i++)
   for(int j=0; j<3; j++)
      if(board[i][j] != 'X' && board[i][j] != 'O')
      return true; 
  //Checking  if the game already draw 
      draw = true; 
      return false; 

} 

//game function 
void game(){
	
	 board[0][0] = '0';
     board[0][1] = '1';
     board[0][2] = '2';
     board[1][0] = '3';
     board[1][1] = '4';
     board[1][2] = '5';
     board[2][0] = '6';
     board[2][1] = '7';
     board[2][2] = '8';

     count=0; 
     choice;
     row,column; 
     turn = 'X'; 
     draw = false; 

    system("cls");                    
	char v;
    cout<<"\n\n\n\t\t\t\t\t_______________________________";
    
	cout<<"\n\n\n\n\n\t\t\t\t\t\tTIC TAC TOE";
    cout<<"\n\n\n\t\t\t\t\t_______________________________";
    
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\tLET'S START";
	for(int i=1;i<=4;i++){
	 
        Sleep(500);
	 	cout<<".";
	}
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t_______________________________";
	cout<<"\n\n\n\t\t\t\t\t\t\t1.Two player\n";
	cout<<"\n\n\t\t\t\t\t\t\t2.With computer\n";
	cout<<"\n\t\t\t\t\t\t_______________________________";

	cout<<"\n\n\n\n\n\n\t\t\t\tEnter your Choice :";
	cin>>v;
	if (v=='1')
	{
		count=1;
	}
	else if (v=='2')
	{
		count=0;
	}
	else
	{
		cout<<"invalid input";
		game();
	}
    while(gameover()){ 
    display_board(); 
    player_turn(); 
    gameover(); 
    } 
    if(turn == 'O' && draw == false){ 
    cout<<"\n\nCongratulations!Player 1 [X] has won the game"; 
    getch();
    main();
	} 
    else if(turn == 'X' && draw == false){ 
    if(count==0){
	cout<<"\n\nCongratulations!Computer [O] has won the game"; 
	getch();
	}else{
		cout<<"\n\nCongratulations!Player 2 [O] has won the game"; 
	getch();
	}
    main();
	} 
    else{
	cout<<"\n\nGAME DRAW!!!\n\n";
	getch();
	main();
	
	}
}


<!---
Awdhesh9211/Awdhesh9211 is a ✨ special ✨ repository because its `Login-Play.cpp` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->
