#include <iostream>
using namespace std;
const int HEIGHT=6;
const int WIDTH=7;
const char BASE_ELEMENT ='*';
const char PLAYER1_TOKEN ='X';
const char PLAYER2_TOKEN ='O';
char arr[HEIGHT][WIDTH];
void drop_ball(char arr1[HEIGHT][WIDTH],int colno,char player_token)
{
 int temp = colno-1;
 int row =HEIGHT-1;
 while(arr1[row][temp]!=BASE_ELEMENT && row>=0)
 {
   row--;
 }
 if(row>=0)
 {
   arr1[row][temp]=player_token;
 }
 else
 {
   cout<<"-------COLUMN FULL!!!-------"<<endl;
 }
 }
bool check_win_horizontal_right(char arr[HEIGHT][WIDTH],int ele_row,int ele_col)
 {
   if((arr[ele_row][ele_col]==PLAYER1_TOKEN && arr[ele_row][ele_col+1]==PLAYER1_TOKEN && arr[ele_row][ele_col+2]==PLAYER1_TOKEN && arr[ele_row][ele_col+3]==PLAYER1_TOKEN)||(arr[ele_row][ele_col]==PLAYER2_TOKEN && arr[ele_row][ele_col+1]==PLAYER2_TOKEN && arr[ele_row][ele_col+2]==PLAYER2_TOKEN && arr[ele_row][ele_col+3]== PLAYER2_TOKEN))
  {
    cout<<"-------WIN!!-------"<<endl;
    return true;
  }
  else
  {
    return false;
  }
 }

bool check_win_vertical_top(char arr[HEIGHT][WIDTH],int ele_row,int ele_col)
 { 
   if((arr[ele_row][ele_col]==PLAYER1_TOKEN && arr[ele_row+1][ele_col]==PLAYER1_TOKEN && arr[ele_row+2][ele_col]==PLAYER1_TOKEN && arr[ele_row+3][ele_col]==PLAYER1_TOKEN)||(arr[ele_row][ele_col]==PLAYER2_TOKEN && arr[ele_row+1][ele_col]==PLAYER2_TOKEN && arr[ele_row+2][ele_col]==PLAYER2_TOKEN && arr[ele_row+3][ele_col]== PLAYER2_TOKEN))
  {
    cout<<"-------WIN!!-------"<<endl;
    return true;
  }
  else
  {
    return false;
  }
 }

bool check_win_diagnol_1(char arr[HEIGHT][WIDTH],int ele_row,int ele_col)
 {
   if((arr[ele_row][ele_col]==PLAYER1_TOKEN && arr[ele_row-1][ele_col-1]==1 && arr[ele_row-2][ele_col-2]==PLAYER1_TOKEN && arr[ele_row-3][ele_col-3]==PLAYER1_TOKEN)||(arr[ele_row][ele_col]==PLAYER2_TOKEN && arr[ele_row-1][ele_col-1]==PLAYER2_TOKEN && arr[ele_row-2][ele_col-2]==PLAYER2_TOKEN && arr[ele_row-3][ele_col-3]== PLAYER2_TOKEN))
  {
    cout<<"-------WIN!!-------"<<endl;
    return true;
  }
  else
  {
    return false;
  }
 }
bool check_win_diagnol_2(char arr[HEIGHT][WIDTH],int ele_row,int ele_col)
{
   if((arr[ele_row][ele_col]==PLAYER1_TOKEN && arr[ele_row+1][ele_col-1]==PLAYER1_TOKEN && arr[ele_row+2][ele_col-2]==PLAYER1_TOKEN && arr[ele_row+3][ele_col-3]==PLAYER1_TOKEN)||(arr[ele_row][ele_col]==PLAYER2_TOKEN && arr[ele_row+1][ele_col-1]==PLAYER2_TOKEN && arr[ele_row+2][ele_col-2]==PLAYER2_TOKEN && arr[ele_row+3][ele_col-3]== PLAYER2_TOKEN))
  {
    cout<<"-------WIN!!-------"<<endl;
    return true;
  }
  else
  {
    return false;
  }
}
bool check_win(char arr[HEIGHT][WIDTH])
{
  for(int i=0;i<HEIGHT;i++)
  {
    for(int j=0;j<WIDTH;j++)
    {
       if(check_win_horizontal_right(arr,i,j)||check_win_vertical_top(arr,i,j)||check_win_diagnol_1(arr,i,j)||check_win_diagnol_2(arr,i,j))
       {
         return true;
       }
    }
  }
  return false;
}
void create_board()
{
  for(int i=0;i<HEIGHT;i++)
  {
    for(int j=0;j<WIDTH;j++)
    {
       arr[i][j]=BASE_ELEMENT;
    }
  }
}
void draw_board()
{
  for(int i=0;i<HEIGHT;i++)
  {
    for(int j=0;j<WIDTH;j++)
    {
       cout<< "| " <<arr[i][j]<<" |";
    }
    cout<<endl<<endl;
  }
  cout<<"\n\n";
}

int get_user_input()
{
   int output=0;
   cin>>output;
   if(output>=1&&output<=7)
   {
     return output;
   }
   else
   {
     cout<<"-------INVALID INPUT-------"<<endl;
     cout<<"-------TURN WASTED!!-------"<<endl;
     return output=-100; 
   }
}
int main() {
  cout<<"----------CONNECT 4-2 PLAYER GAME--------------"<<endl;
  cout<<"---------P1 vs P2-------------"<<endl;
  create_board();
  draw_board();
  bool isGame = false;
  int turn_count=0;
  while(!isGame)
  {
    int temp=0;
    cout<<"-------PLAYER 1----TURN TO PLAY ---------"<<endl;
    cout<<"-------SELECT A NUMBER BETWEEN 1-7-------"<<endl;
    cout<<"-------|1|2|3|4|5|6|7|------"<<endl;
    temp=get_user_input();
    drop_ball(arr,temp,PLAYER1_TOKEN);
    draw_board();
    isGame=check_win(arr);
    
    if(!isGame){
    turn_count++;
    if(turn_count==HEIGHT*WIDTH)
    {
      cout<<"---------GAME DRAW!!!----------"<<endl;
      break;
    }
    cout<<"-----PLAYER 2 TURN TO PLAY-----"<<endl;
    cout<<"-----SELECT A NUMBER BETWEEN 1-7----"<<endl;
    cout<<"-----|1|2|3|4|5|6|7|----------"<<endl;
    temp=get_user_input();
    drop_ball(arr,temp,PLAYER2_TOKEN);
    draw_board();
    isGame=check_win(arr);
    turn_count++;
    if(isGame)
    {
      cout<<"------PLAYER 2 WINS !!-------"<<endl;
    }
    else
    {
      if(turn_count==HEIGHT*WIDTH)
     {
      cout<<"-------GAME DRAW!!!---------"<<endl;
      break;
     }
    }
    }
    else
    {
      cout<<"-------PLAYER 1 WINS!!-------"<<endl;
    }
  }
  //get_user_input();
  //drop_ball(arr[HEIGHT][WIDTH],3);
} 