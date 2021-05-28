#include "color.h"

int main()
{
  char choice;
  bool playing = true;
  chooseRed redGame;
  srand( (int) time(0) );
  redGame.setColors();
  do
  {
    do
    {
      cout<<endl<<"Thank you for playing Choose Red!"<<endl;
      cout<<"(P)lay Game"<<endl<<"(T)utorial"<<endl<<"(Q)uit"<<endl<<"(S)how Colors"<<endl;
      cin>>choice;

      if (choice!='P'&& choice!='p'&& choice!='t'&& choice!='T'&& choice!='q'&&choice!='Q'&&choice!='s'&&choice!='S')
      {
        cout<<"Invalid Choice."<<endl;
      }
    } while (choice!='P'&& choice!='p'&& choice!='t'&& choice!='T'&& choice!='Q'&& choice!='q'&&choice!='s'&&choice!='S');

    if(choice=='T'||choice=='t')
    {
      redGame.tutorial();
    }
    if (choice=='P'||choice=='p')
    {
      redGame.game();
    }

    if (choice=='Q'||choice=='q')
    {
      playing = false;
    }
    if (choice=='S'||choice=='s')
    {
      cout<<"Here are the colors: "<<endl<<endl;
      redGame.showColors();
    }
  }while (playing);
  return 0;
}
