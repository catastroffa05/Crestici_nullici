#include <stdio.h>

char ch1[9] = "123456789";
char xy = 'x';

void showGame();
int endGame();
int winGame();

int main()
{
    while( endGame() && winGame() )
    {
        int number = 0;
        scanf("%d", &number);
        number -= 1;
        if( (number >= 0) && (number <= 8) )
        {
            if( (ch1[number] != 'x') || (ch1[number] != 'y') )
            {
                if(xy == 'x')
                {
                    ch1[number] = 'y';
                    xy = 'y';
                }    
                else
                {
                    ch1[number] = 'x';    
                    xy = 'x';
                }    
                system("clear");
                showGame();
            }
        }
    }
    return 0;
}

void showGame()
{
    for(int i=0; i<9; i++)
    {
        if( (ch1[i] == 'x') || (ch1[i] == 'y') )
        { 
            printf("%c", ch1[i]);
            if( (i == 2) || (i == 5) )
                puts(" ");
        }        
        else 
        {
            printf("%c", " ");
            if( (i == 2) || (i == 5) )
                puts(" ");
        }        
            
    }    
}

int endGame()
{
    int cntend = 0;
    for(int i=0; i<9; i++)
    {
        if( (ch1[i] == 'x') || (ch1[i] == 'y') )
            cntend++;
    }        
    if(cntend == 9)
        return 0;        
    return 1;    
}

int winGame()
{
    if( (ch1[0] == ch1[1]) && (ch1[0] == ch1[2]) )
        return 0;
    if( (ch1[3] == ch1[4]) && (ch1[3] == ch1[5]) )
        return 0;
    if( (ch1[6] == ch1[7]) && (ch1[6] == ch1[8]) )
        return 0;
    if( (ch1[0] == ch1[4]) && (ch1[0] == ch1[8]) )
        return 0;
    if( (ch1[2] == ch1[4]) && (ch1[2] == ch1[6]) )
        return 0;
    return 1;    
}