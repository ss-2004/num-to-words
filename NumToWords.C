#include <stdio.h>
#include <math.h>
#include <string.h>

void suffix1(int onedig);
void suffix2(int twodig);

static char wrd[256]="";

int ul = 9;
static int unit[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
static char U[9][7] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int spl = 10;
static int sp[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
static char S[10][11] = { "ten", "eleven", "twelwe", "thirteen", "fourteen",
                          "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

int tl = 8;
static int tens[] = { 20, 30, 40, 50, 60, 70, 80, 90 };
static char T[8][9] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
//referencing each word name to number

int main(void)
{
    int n, i=0, j=0, k=0, d;
    int onedig, twodig;
    char temp[128]="";

    printf("Enter number : ");
    scanf("%d", &n);
    for(;;) //checking correct number size
    {
        if(n>999999999)
        {
            printf("Enter smaller number : ");
            scanf("%d", &n);
        }
        else
            break;
    }
        
    int copy=n, copy2=n, c=0, c2=0;
    while(copy>0)
    {
        c2++;
        copy/=10;
    }
    c = c2;
        
    int num[10];
        
    //re-initialising for while loop
    while(copy2>0)
    {
        d = copy2%10;
        num[c2-1] = d*(int)pow(10, i);
        c2--; i++;
        copy2/=10;
    }
        
    //name starts
    for(i=c-1; i>=0; i--)
    {
        if(n==0)
        {
            strcpy(wrd, "zero");
            break;
        }
            
        if(c==1)
        {
            onedig = num[c-1]; k++; j=1;
            suffix1(onedig);

            if(c==k)
                break;
        }
            
        if(c>=2&&num[c-2]==0&&j==0)
        {
            onedig = num[c-1]; k++; j=1;
            suffix1(onedig);
        }
            
        if(i==c-2&&k<=c)
        {
            twodig=num[c-1]+num[c-2]; k++;
            suffix2(twodig);
            
            if(c==k)
                break;
        }
        
        if(i==c-3&&num[i]>0)
        {
            onedig = num[c-3]/100;
            strcpy(temp, "hundred ");
            strcat(temp, wrd);
            strcpy(wrd, temp);
            strcpy(temp, "");
        
            k++;
            suffix1(onedig);
            if(c==k)
                break;
        }
            
        if(i==c-4&&k<=c&&(c<5||num[c-5]==0)&&num[i]>0)
        {
            onedig = num[c-4]/1000;
            strcpy(temp, "thousand ");
            strcat(temp, wrd);
            strcpy(wrd, temp);
            strcpy(temp, "");
            
            k++;
            suffix1(onedig);
            if(c==k)
                break;
        }
        else if(i==c-5&&k<=c&&(num[i]+num[i+1])>=10000)
        {
            twodig = (num[c-4]+num[c-5])/1000;
            strcpy(temp, "thousand ");
            strcat(temp, wrd);
            strcpy(wrd, temp);
            strcpy(temp, "");
            
            k++;
            suffix2(twodig);
            if(c==k)
                break;
        }
        
        if(i==c-6&&k<=c&&(c<7||num[c-7]==0)&&num[i]>0)
        {
            onedig = num[c-6]/100000;
            strcpy(temp, "lakh ");
            strcat(temp, wrd);
            strcpy(wrd, temp);
            strcpy(temp, "");

            k++;
            suffix1(onedig);
            if(c==k)
                break;
        }
        else if(i==c-7&&k<=c&&(num[i]+num[i+1])>=1000000)
        {
            twodig = (num[c-6]+num[c-7])/100000;
            //wrd = "lakh " + wrd;
            strcpy(temp, "lakh ");
            strcat(temp, wrd);
            strcpy(wrd, temp);
            strcpy(temp, "");
            k++;
            suffix2(twodig);
            if(c==k)
                break;
        }
        
        if(i==c-8&&k<=c&&(c<9||num[c-9]==0)&&num[i]>0)
        {
            onedig = num[c-8]/10000000;
            //wrd = "crore " + wrd;
            strcpy(temp, "crore ");
            strcat(temp, wrd);
            strcpy(wrd, temp);
            strcpy(temp, "");
            k++;
            suffix1(onedig);
            if(c==k)
                break;
        }
        else if(i==c-9&&k<=c&&(num[i]+num[i+1])>=100000000)
        {
            twodig = (num[c-8]+num[c-9])/10000000;
            strcpy(temp, "crore ");
            strcat(temp, wrd);
            strcpy(wrd, temp);
            strcpy(temp, "");
            k++;
            suffix2(twodig);
            if(c==k)
                break;
        }
    }

    printf("Number in words : %s\n", wrd);
}
    
void suffix1(int onedig)
{
    int i;
    char str[128]="", t[128]="";
    for(i=0; i<ul; i++)
    {
        if(onedig == unit[i])
        {
            strcpy(t, U[i]);
            strcat(t, " ");
            strcat(t, str);
            strcpy(str, t);
            strcpy(t, "");
            break;
        }
    }
    strcat(str, wrd);
    strcpy(wrd, str);
}
    
void suffix2(int twodig)
{
    int i;
    char str[128]="", t[128]="";
    if(twodig>19)
    {
        for(i=0; i<ul; i++)
        {
            if(twodig%10==unit[i])
            {
                strcpy(t, U[i]);
                strcat(t, " ");
                strcat(t, str);
                strcpy(str, t);
                strcpy(t, "");
                break;
            }
            else if(twodig%10==0)
                break;
        }
        for(i=0; i<tl; i++)
        {
            if(10*(twodig/10)==tens[i])
            {
                strcpy(t, T[i]);
                strcat(t, " ");
                strcat(t, str);
                strcpy(str, t);
                strcpy(t, "");
                break;
            }
        }
    }
    else if(twodig<=19&&twodig>=10)
    {
        for(i=0; i<spl; i++)
        {
            if(twodig==sp[i])
            {
                strcpy(t, S[i]);
                strcat(t, " ");
                strcat(t, str);
                strcpy(str, t);
                strcpy(t, "");
                break;
            }
        }
    }
    strcat(str, wrd);
    strcpy(wrd, str);
}
