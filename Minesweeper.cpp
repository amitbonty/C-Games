#include <iostream>
using namespace std;
const int HEIGHT = 9;
const int WIDTH = 9;
char arr[HEIGHT][WIDTH];
void CreateBoard(char arr[HEIGHT][WIDTH])
{
 for(int i =0;i<HEIGHT;i++)
 {
   for(int j=0;j<WIDTH;j++)
   {
     arr[i][j]='-';   
     }
 }
}
void PrintHiddenBoard(char arr[HEIGHT][WIDTH])
{
  for(int i =0;i<HEIGHT;i++)
 {
   for(int j=0;j<WIDTH;j++)
   {
      if(arr[i][j]=='*')
      {
        cout<<"-"<<"  ";
      }
      else
      {
       cout<<arr[i][j]<<"  ";   
      }
     }
     cout<<endl;
 }
 cout<<endl;
}
void PrintBoard(char arr[HEIGHT][WIDTH])
{
  for(int i =0;i<HEIGHT;i++)
 {
   for(int j=0;j<WIDTH;j++)
   {
       cout<<arr[i][j]<<"  ";   
     }
     cout<<endl;
 }
 cout<<endl;
}
void PlaceMines(char arr[HEIGHT][WIDTH],int MineCount)
{
   for(int i =0;i<MineCount;i++)
 {
     int k = rand()%HEIGHT;  
     int l= rand()%WIDTH; 
     arr[k][l]='*';
}
}
bool isValid(char arr[HEIGHT][WIDTH],int r,int c)
{
  return (r<HEIGHT)&&(c<WIDTH)&&(r>=0)&&(c>=0);
}
int TakeUserInputRow()
{
  int r;
  cout<<"Enter row number-----"<<endl;
  cin>>r;
  return r;
}
int TakeUserInputCol()
{
  int c;
  cout<<"Enter col number-----"<<endl;
  cin>>c;
  return c;
}
bool CheckMines(char arr[HEIGHT][WIDTH],int r,int c)
{
  if(arr[r][c]=='*')
  {
    cout<<"Block has mine!!!"<<endl;
    cout<<"You lose!!"<<endl;
    PrintBoard(arr);
    cout<<"------------------------------------------"<<endl;
    return true;
  }
  else
  {
    return false;
  }
}
int CountMines(char arr[HEIGHT][WIDTH],int r,int c)
{ int count =48;
  if(arr[r+1][c]=='*')
  {
    count++;
  }
  if(arr[r][c-1]=='*')
  {
    count++;
  }
  if(arr[r-1][c]=='*')
  {
    count++;
  }
  if(arr[r][c+1]=='*')
  {
    count++;
  }
  if(arr[r+1][c-1]=='*')
  {
    count++;
  }
  if(arr[r+1][c+1]=='*')
  {
    count++;
  }
  if(arr[r-1][c-1]=='*')
  {
    count++;
  }
  if(arr[r-1][c+1]=='*')
  {
    count++;
  }
  return count;
}
void RevealCells(char arr[HEIGHT][WIDTH],int r,int c)
{
  
  if(arr[r+1][c]!='*' && isValid(arr,r+1,c))
  {
    arr[r+1][c]=CountMines(arr, r+1, c);
  }
   if(arr[r][c-1]!='*' && isValid(arr,r,c-1))
  {
    arr[r][c-1]=CountMines(arr, r, c-1);
  }
   if(arr[r-1][c]!='*' && isValid(arr,r-1,c))
  {
    arr[r-1][c]=CountMines(arr, r-1, c);
  }
   if(arr[r][c+1]!='*' && isValid(arr,r,c+1))
  {
    arr[r][c+1]=CountMines(arr, r, c+1);
  }
   if(arr[r+1][c-1]!='*' && isValid(arr,r+1,c-1))
  {
    arr[r+1][c-1]=CountMines(arr, r+1, c-1);
  }
   if(arr[r+1][c+1]!='*' && isValid(arr,r+1,c+1))
  {
    arr[r+1][c+1]=CountMines(arr, r+1, c+1);
  }
   if(arr[r-1][c-1]!='*' && isValid(arr,r-1,c-1))
  {
    arr[r-1][c-1]=CountMines(arr, r-1, c-1);
  }
   if(arr[r-1][c+1]!='*' && isValid(arr,r-1,c+1))
  {
    arr[r-1][c+1]=CountMines(arr, r-1, c+1);
  }
  
}
bool CheckBoard(char arr[HEIGHT][WIDTH])
{
   for(int i =0;i<HEIGHT;i++)
 {
   for(int j=0;j<WIDTH;j++)
   {
     if(arr[i][j]=='-')
     {
      return false;
    }
 }
}
 return true;
}
int main() {
  char arr1[HEIGHT][WIDTH];
  cout<<"------------WELCOME TO MINESWEEPER---------------"<<endl;
  cout<<"------------BOARD SIZE - 9X9---------------"<<endl;
  cout<<"------------NO OF MINES -- 10-----------------"<<endl;

  CreateBoard(arr1);
  PrintBoard(arr1);
  PlaceMines(arr1, 10);
  bool checkWin= false;
  //PrintBoard(arr1);
  while(!checkWin)
  {
  int r= TakeUserInputRow();
  int c= TakeUserInputCol();
  checkWin=CheckMines(arr1, r, c);
  if(!checkWin)
  {
     arr1[r][c]=CountMines(arr1,r,c);
     if(CountMines(arr1,r,c)==48)
  {
     RevealCells(arr1,r,c);
  }
     PrintHiddenBoard(arr1);
  }
   if(CheckBoard(arr1))
   {
     cout<<"You win!!"<<endl;
     PrintBoard(arr1);
     cout<<"------------------------------------------"<<endl;
   }
  }
} 
//Check for valid input.
//Check if cell is empty or not.
//Board randomizer.
