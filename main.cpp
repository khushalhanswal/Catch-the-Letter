#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
using namespace std;
bool gameOver = false;
int score = 0;
const int height = 15;
const int width = 40;
int x,y,fruitx,fruity;
int fruitx3[26],fruity3[26];
int xtail[50],ytail[50];
int ntail;
char s;

int mylevel;
char lev1[5] = {'S','N','A','I','L'};
char lev2[5] = {'E','W','O','R','M'};
char lev3[8] = {'A','N','A','C','O','N','D','A'};
int f;

enum instruct {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
}dir;

void setup()
{
    gameOver = false;
    score = 0;
    f=0;

    x = width/2;
    y = height/2;

    fruitx = rand()%width;
    fruity = rand()%height;

}
void setup3()
{
    gameOver = false;
    score = 0;
    f=0;

    x = width/2;
    y = height/2;

    fruitx = rand()%width;
    fruity = rand()%height;

    for(int i=0;i<26;i++)
    {

        fruitx3[i]=rand()%width;
        fruity3[i]=rand()%height;
    }
    s=97;
}

int check(int i,int j)
{
    for(int k=0;k<26;k++)
    {
        if(i==fruitx3[k] && j== fruity3[k])
        {
            return 1;
        }
    }
    return 0;
}

void draw3()
{
    system("cls");
    int i,j,k,print =0;

    cout<<"CHARACTERS COLLECTED :";
    for(i=0;i<f;i++)
    {
        cout<<lev3[i];
    }
    cout<<"\n";
    for(i=0;i<width;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for(i=0;i<height;i++)
    {
      for(j = 0;j<width+1;j++)
      {
          print = 0;
          if(j==0 || j == width -1)
          {
            cout<<"|";
          }
          else if(i == y && j == x)
          {
            cout<<"O";

          }
          else if(i%2==0 && j%7==0)
          {
              cout<<"@";
          }
          else if(i == fruity && j == fruitx)
          {
              if(f==8)
              {
                  gameOver = true;
              }
              cout<<lev3[f];
          }

          else
          {

              for(k=0;k<ntail;k++)
              {
                  if( xtail[k] == j && ytail[k] == i)
                  {
                      cout<<lev3[k];
                      print = 1;
                  }
              }
              if(print == 0)
              {
                  cout<<" ";
              }
          }
                    //Printing The Upper Border;
      }
      cout<<endl;
    }

    /*for(i=0;i<width+1;i++)
    {
        cout<<"#";
    }
     */
    cout<<"########################################";

    cout<<endl<<endl;

    cout<<"TOTAL SCORE : "<<score<<endl;
    cout<<"USE W,S,D,A TO PLAY"<<endl;
    cout<<"Made By Khushal Hanswal\n";
}


void logic3()
{
    int prevx = xtail[0];
    int prevy = ytail[0];
    int i;
    int prevx2,prevy2;

    xtail[0] = x;
    ytail[0] = y;

    for(i=1;i<ntail;i++)
    {
        prevx2 = xtail[i];
        prevy2 = ytail[i];
        xtail[i] = prevx;
        ytail[i] = prevy;
        prevx = prevx2;
        prevy = prevy2;
    }

    switch(dir)
    {
        case LEFT : x--;
                    break;
        case RIGHT : x++;
                     break;
        case UP : y--;
                  break;
        case DOWN : y++;
                   break;
    }


    if(x == width)
        gameOver=true;
    else if(x<0)
    {
        gameOver=true;
    }
    if(y == height)
        y=0;
    else if(y<0)
    {
        gameOver=true;
    }
    if(y%2==0 && x%7==0)
    {
        gameOver=true;

    }

    if(x == fruitx && y == fruity)
    {
        score ++;
        f++;

        ntail++;
        fruitx = rand() % width;
        fruity = rand() % height;
    }

    if(xtail[i] == x && ytail[i] == y)
    {
        gameOver = true;
    }

}





void draw()
{
    system("cls");
    int i,j,k,print =0;

    cout<<"CHARACTERS COLLECTED :";
    if(mylevel==1){
    for(i=0;i<f;i++) cout<<lev1[i]; cout<<"\n";}
    else
    {
     for(i=0;i<f;i++) cout<<lev2[i]; cout<<"\n";
    }
    for(i=0;i<width;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for(i=0;i<height;i++)
    {
      for(j = 0;j<width+1;j++)
      {
          print = 0;
          if(j==0 || j == width -1)
          {
            cout<<"|";
          }
          else if(i == y && j == x)
          {
            cout<<"O";

          }
          else if(i == fruity && j == fruitx)
          {
              if(f==5)
              {
                  gameOver = true;
              }
              if(mylevel==1)
                cout<<lev1[f];
              else
                cout<<lev2[f];
          }

          else
          {

              for(k=0;k<ntail;k++)
              {
                  if( xtail[k] == j && ytail[k] == i)
                  {
                      if(mylevel==1)
                      cout<<lev1[k];
                      else
                      {
                          cout<<lev2[k];
                      }
                      print = 1;
                  }
              }
              if(print == 0)
              {
                  cout<<" ";
              }
          }
                    //Printing The Upper Border;
      }
      cout<<endl;
    }

    /*for(i=0;i<width+1;i++)
    {
        cout<<"#";
    }
     */
    cout<<"########################################";

    cout<<endl<<endl;

    cout<<"TOTAL SCORE : "<<score<<endl;
    cout<<"USE W,S,D,A TO PLAY"<<endl;
    cout<<"Made By Khushal Hanswal\n";
}

void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'w' : dir = UP;
                       break;
            case 'a' : dir = LEFT;
                       break;
            case 's' : dir = DOWN;
                        break;
            case 'd' : dir = RIGHT;
                       break;
            case 'x' : gameOver = true;
                       break;
            break;
        }
    }
}

void logic()
{
    int prevx = xtail[0];
    int prevy = ytail[0];
    int i;
    int prevx2,prevy2;

    xtail[0] = x;
    ytail[0] = y;

    for(i=1;i<ntail;i++)
    {
        prevx2 = xtail[i];
        prevy2 = ytail[i];
        xtail[i] = prevx;
        ytail[i] = prevy;
        prevx = prevx2;
        prevy = prevy2;
    }

    switch(dir)
    {
        case LEFT : x--;
                    break;
        case RIGHT : x++;
                     break;
        case UP : y--;
                  break;
        case DOWN : y++;
                   break;
    }
    if(mylevel==1){

    if(x == width)
        x = 0;
    else if(x<0)
    {
        x= width-1;
    }
    if(y == height)
        y=0;
    else if(y<0)
    {
        y = height -1;
    }

    }
    else
    {
        if(x == width)
        gameOver = true;
    else if(x<0)
    {
        gameOver = true;
    }
    if(y == height)
        gameOver = true;
    else if(y<0)
    {
        gameOver = true;
    }

    }




    if(x == fruitx && y == fruity)
    {
        score ++;
        f++;

        ntail++;
        fruitx = rand() % width;
        fruity = rand() % height;
    }

    if(xtail[i] == x && ytail[i] == y)
    {
        gameOver = true;
    }

}

void level_select()
{
    system("cls");
    cout<<"Select your Level\n1 - EWorm\n";
    cout<<"2 - Snail\n";
    cout<<"3 - Snake\n";
    cout<<"4 - Quiet\n";
    cin>>mylevel;
    return;

}

void level_1_func()
{
    setup();
    while(!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(80);
    }

}

void level_2_func()
{
    setup();
    while(!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(60);
    }

}

void level_3_func()
{
    setup3();
    while(!gameOver)
    {
        draw3();
        input();
        logic3();
        Sleep(40);
    }

}

int main()
{
    level_select();
    while(mylevel!=4){
    switch(mylevel)
    {
        case 1 : level_1_func();
                 break;
        case 2 : level_2_func();
                 break;
        case 3 : level_3_func();
                 break;
        break;
    }
    level_select();
    }


  return 0;
}
