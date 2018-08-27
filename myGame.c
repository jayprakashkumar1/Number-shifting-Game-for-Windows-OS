
//1. TO RUN FROM COMMAND LINE
//How to compile : gcc -o game myGame.c
// how to run: ./game

//2. TO RUN IN CODE BLOCKS OR SOME OTHER IDE
// GOT TO DEBUG SECTION AND
// compile & run

// shortcut in codeblocks to directly run
// F9

// header files
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<windows.h>


// create matrix 4*4
void  createMatrix(int arr[][4])
{
    int n=15;
    int num[n],i,j;
    for(i=0;i<15;i++)        // These 1-15 number will be in th matrix
    num[i]=i+1;

    srand(time(NULL));           // for random number generation

    int lastIndex=n-1,index;

    for(i=0;i<4;i++)
    for(j=0;j<4;j++)
  {
    if(lastIndex>=0)
    {  index=rand()%(lastIndex+1); // idea : performing % operation by (lastIndex+1)
       arr[i][j]=num[index];       // will give index , so put that num[index] number in matrix
       num[index]=num[lastIndex--]; // and replace last number with this indexed positioned number
    }                               // and finally lastIndex--
  }
       arr[i-1][j-1]=0;          // last number is zero

}

// showing matrix
void showMatrix(int arr[][4])
{
    int i,j;
    printf("--------------------\n");
    for(i=0;i<4;i++)
   { printf("|");
       for(j=0;j<4;j++)
    {   if(arr[i][j]!=0)
        printf("%-2d | ",arr[i][j]);
        else
        printf("   | ");
    }
    printf("\n");
   }

    printf("--------------------\n");
}

// winning check by this function
int winner(int arr[][4])
{
    int i,j,k=1;
    for(i=0;i<4;i++)
   { for(j=0;j<4;j++,k++)
        if(arr[i][j]!=k && k!=16)
        break;
    if(j<4)
    break;
   }
        if(j<4)
        return 0;
        return 1;
}

// swap function to swap two numbers
void swap(int *x,int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
    printf("");
}

// Reads the user input character and return ascii value of that
int readEnteredKey()
{
        char c;
            c=_getch();
            if(c==-32)
            c=_getch();

    return c;
}

// shift up function
int shiftUp(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(i==3)                 // shifting not possible
        return 0;
        swap(&arr[i][j],&arr[i+1][j]);
        return 1;               // shift up success
}

int shiftDown(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(i==0)                 // shifting not possible
        return 0;
         swap(&arr[i][j],&arr[i-1][j]);    // swap numbers

        return 1;               // shift up success
}

int shiftRight(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==0)                 // shifting not possible
        return 0;
             swap(&arr[i][j],&arr[i][j-1]);

        return 1;               // shift up success
}

int shiftLeft(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            if(arr[i][j]==0)
            break;
        if(j<4)
        break;
    }
      if(j==3)                 // shifting not possible
        return 0;
                swap(&arr[i][j],&arr[i][j+1]);
        return 1;               // shift up success
}

// Game rules
void gameRule(int arr[][4])
{
    system("cls");
 //   int x=readEnteredKey();
    int i,j,k=1;
    printf("                 RULE OF THIS GAME                 \n");
    printf("\n1.You can move only 1 step at a time by arrow key ");
    printf("\nMove Up   : by Up arrow key ");
    printf("\nMove Down : by Down arrow key");
    printf("\nMove Left : by Left arrow key");
    printf("\nMove Right: by Right arrow key");

    printf("\n2.You can move number at empty position only ");
    printf("\n");
    printf("\n3.For each valid move : your total number of move will decreased by 1 \n");
    printf("4.Wining situation : ");
    printf("number in a 4*4 matrix should be in order from 1 to 15 ");
    printf("\n\n            winning situation:         \n");

    printf("---------------------\n");
    for(i=0;i<4;i++)
   { printf("| ");
       for(j=0;j<4;j++)
    {   if(arr[i][j]!=0)
        printf("%-2d | ",4*i+j+1);
        else
        printf("   |");
    }
    printf("\n");
   }

    printf("---------------------\n");
    printf("\n5.You can exit the game at any time by pressing 'E' or 'e' ");


    printf("\nSo Try to win in minimum no of move \n");
    printf("\n         Happy gaming , Good Luck\n");

    printf("\nEnter any key to start.....   ");
   int x=readEnteredKey();
}

// main function
int main()
{
    int arr[4][4];        // matrix
    int maxTry=400;       // maximum move
    char name[20];
   system("cls");        // to clear screen

    printf("Enter Your Good Name: ");
    scanf("%s",name);

       while(1)
    {             createMatrix(arr);    // calling funcn to create  matrix
                  gameRule(arr);       // game rule function calling

          while(!winner(arr))     // checking for winning situation
        {
               system("cls");
               if(!maxTry)        // for remaing zero move
                break;

               printf("\n\n  welcome  %s  ,  Move remaining : %d\n\n",name,maxTry);

              showMatrix(arr);      // show matrix


            int key=readEnteredKey();   // this will return ascii code of user entered key

        switch(key)          // maping
        {
            case 69:                  // ascii of E

            case 101:                 // ascii of e
                        printf("\a\a\a\a\a\a\n     Thanks for Playing ! \n\a");
                        printf("\nHit 'Enter' to exit the game \n");
                        key=readEnteredKey();
                        exit(0);


            case 72:          // arrow up
                        if(shiftUp(arr))
                        maxTry--;
                        break;
            case 80:          // arrow down
                        if(shiftDown(arr))
                        maxTry--;
                        break;
            case 77:            // arrow  right
                        if(shiftRight(arr))
                        maxTry--;
                        break;
            case 75:             // arrow left
                        if(shiftLeft(arr))
                        maxTry--;
                        break;
            default:

                       printf("\n\n      \a\a Not Allowed \a");
                     //  delay(200);
        }

        }
        if(!maxTry)
         printf("\n\a          YOU LOSE !          \a\a\n");
         else
         { printf("\n\a!!!!!!!!!!!!!Congratualization !!!!!!!!!!!!!\n\a");
           printf("\a               You have Won      \a\a\a ");
         }
         char check;
        printf("\nwant to play again ? \n");
        printf("enter 'y' to play again:  ");
        scanf("%c",&check);
        if(check!='y' && check!='Y')
            break;
        maxTry=400;
    }
    return 0;
}
