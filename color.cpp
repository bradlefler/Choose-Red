//Name: Brad Lefler
#include "color.h"

string chooseRed::scramble(string preScrambledColor)
{
  int scrambleMethod = randomBetween (1,2); //there are two methods so players cannot exploit the pattern
  string color = preScrambledColor;
  if (color.size()<6)
  {
    int letter1=color[0];
    int letter2=color[1];
    int letter3=color[2];
    int letter4=color[3];
    if (scrambleMethod==1)
    {
      color[0]=letter2;
      color[1]=letter4;
      color[2]=letter1;
      color[3]=letter3;
    }
    if (scrambleMethod==2)
    {
      color[0]=letter4;
      color[1]=letter3;
      color[2]=letter1;
      color[3]=letter2;
    }
  }
  if (color.size()>=6)
  {
    int letter1=color[0];
    int letter2=color[1];
    int letter3=color[2];
    int letter4=color[color.size()-1];
    int letter5=color[color.size()-2];
    int letter6=color[color.size()-3];
    if (scrambleMethod==1)
    {
      color[0]=letter2;
      color[1]=letter6;
      color[2]=letter4;
      color[color.size()-1]=letter1;
      color[color.size()-2]=letter3;
      color[color.size()-3]=letter5;
    }
    if (scrambleMethod==2)
    {
      color[0]=letter3;
      color[1]=letter2;
      color[2]=letter5;
      color[color.size()-1]=letter4;
      color[color.size()-2]=letter6;
      color[color.size()-3]=letter1;
    }
  }
  return color;
}

void chooseRed::showColors()
{
   for (int col = 0; col<colors[1].size(); col++)
   {
    for (int row = 0; row<colors.size(); row++)
      {
       cout<<colors[row][col]<<endl;
      }
   cout<<endl;
   }
}

void chooseRed::game()
{
  int winCounter = 0;
  bool playingGame = true;
  do
  {
    int col = randomBetween(0,3);
    int row = randomBetween(1,9);
    int correct = randomBetween (1,2);
    int col2 = randomBetween(0,3);
    int row2 = randomBetween(1,9);
    char choice2;
    string hint = colors[row][col];
    while (col==col2)
    {
      col2=randomBetween(0,3);
    }
    cout<<"Choose "<<colors[0][col]<<endl;
    if (correct == 1)
    {
      cout<<"A.) "<<scramble(colors[row][col])<<endl;
      cout<<"B.) "<<scramble(colors[row2][col2])<<endl;
      cout<<"C.) Quit"<<endl;
      cout<<"Need a hint? Press H."<<endl;
      do
      {
        cin>>choice2;
        if (choice2=='A'||choice2=='a')
        {

          cout<<"Correct!"<<endl;
          winCounter++;
        }
        else if (choice2=='B'||choice2=='b')
        {
          cout<<"Incorrect."<<endl<<"Game Over!"<<endl;
          cout<<"You won "<<winCounter<<" games!"<<endl;
          playingGame=false;
        }
        else if (choice2=='C'||choice2=='c')
        {
          cout<<"Thanks for playing! You won  "<<winCounter<<" games!"<<endl;
          playingGame=false;
        }
        else if (choice2=='H'||choice2=='h')
        {
          cout<<"The first letter is "<<hint[0]<<endl;
        }
        else
        {
          cout<<"Invalid entry."<<endl;
        }
      }while(choice2!='b'&&choice2!='B'&&choice2!='a'&&choice2!='A'&&choice2!='C'&&choice2!='c');
    }
    if (correct==2)
    {
      cout<<"A.) "<<scramble(colors[row2][col2])<<endl;
      cout<<"B.) "<<scramble(colors[row][col])<<endl;
      cout<<"C.) Quit"<<endl;
      cout<<"Need a hint? Press H."<<endl;
      do
      {
        cin>>choice2;
        if (choice2=='B'||choice2=='b')
        {
          cout<<"Correct!"<<endl;
          winCounter++;
        }
        else if (choice2=='A'||choice2=='a')
        {
          cout<<"Incorrect."<<endl<<"Game Over!"<<endl;
          cout<<"You won "<<winCounter<<" games!"<<endl;
          playingGame=false;
        }
        else if (choice2=='C'||choice2=='c')
        {
          playingGame=false;
          cout<< "Thanks for playing! You won "<<winCounter<<" games!"<<endl;
        }
        else if (choice2=='H'||choice2=='h')
        {
          cout<<"The first letter is "<<hint[0]<<endl;
        }
        else
        {
          cout<<"Invalid choice."<<endl;
        }

      }while (choice2!='b'&&choice2!='B'&&choice2!='a'&&choice2!='A'&&choice2!='C'&&choice2!='c');
   }
  }while (playingGame);
}

void chooseRed::tutorial()
{
  cout<<"==TUTORIAL=="<<endl;
  char choice2;
  bool question1Wrong;
    do
    {
      cout<<"The game will ask you to choose a color. Pay attention because it is not always red."<<endl;
      cout<<"Choose Red:"<<endl;
      cout<<"A.) Red"<<endl<<"B.) Blue"<<endl;
      cin>>choice2;
      if (choice2=='a'||choice2=='A')
      {
        cout<<"Correct!"<<endl;
        question1Wrong=false;
      }
      else
      {
        cout<<"Try Again!"<<endl;
      }
    } while (question1Wrong);

    cout<<"It's never that easy though! The real game doesn't use basic colors."<<endl;
    bool question2Wrong = true;
    do
    {
      cout<<"Choose Blue:"<<endl;
      cout<<"A.) Scarlet"<<endl<<"B.) Lapis"<<endl;
      char choice2;
      cin>>choice2;
      if (choice2=='A'||choice2=='a')
      {
        cout<<"Be careful, this question is asking for blue, not red!"<<endl;
      }
      else if (choice2=='B'||choice2=='b')
      {
        cout<<"Correct!"<<endl;
        question2Wrong=false;
      }
    } while (question2Wrong);

    cout<<"Lastly, the game will also scramble the answers. These are the same answers as last time to help you get used to the game."<<endl;
    bool question3Wrong=true;
    do
    {
      cout<<"Choose Red:"<<endl;
      cout<<"A.) "<<scramble("scarlet")<<endl<<"B.) "<<scramble("lapis")<<endl;
      cin>>choice2;
      if (choice2=='A'||choice2=='a')
      {
        cout<<"Correct!"<<endl;
        question3Wrong=false;
      }
      else if (choice2=='B'||choice2=='b')
      {
        cout<<"Incorrect. Try again!"<<endl;
      }

    } while (question3Wrong);
    cout<<"Thanks for playing, and good luck! If you are having trouble and need refresh your memory for shades of each color, use the 'Show Colors' option in the main menu."<<endl;
}

int chooseRed::randomBetween (int x, int y)
{
  int first = x;
  int second = y;
  if (first>second)
  {
    return second + rand()%(first-second+1);
  }
  else
  {
    return first + rand()%(second-first+1);
  }
}

void chooseRed::setColors()
{
  colors.resize(10);
  for (int row = 0; row <colors.size(); row++)
  {
    colors[row].resize(4);
  }
  //it pains me to do it, but the non-primary colors have to have their first letters non-uppercase.
  colors[0][0]="Red:";
  colors[1][0]="rose";
  colors[2][0]="crimson";
  colors[3][0]="ruby";
  colors[4][0]="carmine";
  colors[5][0]="garnet";
  colors[6][0]="maroon";
  colors[7][0]="brick";
  colors[8][0]="burgundy";
  colors[9][0]="cherry";
  colors[0][1]="Blue:";
  colors[1][1]="cerulean";
  colors[2][1]="indigo";
  colors[3][1]="sapphire";
  colors[4][1]="turquoise";
  colors[5][1]="cobalt";
  colors[6][1]="teal";
  colors[7][1]="azure";
  colors[8][1]="cyan";
  colors[9][1]="denim";
  colors[0][2]="Yellow:";
  colors[1][2]="gold";
  colors[2][2]="ivory";
  colors[3][2]="blonde";
  colors[4][2]="goldenrod";
  colors[5][2]="cream";
  colors[6][2]="khaki";
  colors[7][2]="lemon";
  colors[8][2]="amber";
  colors[9][2]="citrine";
  colors[0][3]="Green:";
  colors[1][3]="emerald";
  colors[2][3]="viridian";
  colors[3][3]="olive";
  colors[4][3]="mint";
  colors[5][3]="pistachio";
  colors[6][3]="jade";
  colors[7][3]="malachite";
  colors[8][3]="lime";
  colors[9][3]="seafoam";
}
