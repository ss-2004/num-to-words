import java.util.*;
class NumToWords
{
    static int unit[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    static String U[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    static int sp[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    static String S[] = { "ten", "eleven", "twelwe", "thirteen", "fourteen", 
                          "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    static int tens[] = { 20, 30, 40, 50, 60, 70, 80, 90 };
    static String T[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    //referencing each word name to number
    
    public static void main(String args[])
    {
        Scanner ss = new Scanner(System.in);
        NumToWords fn = new NumToWords();
        
        int n, i=0, j=0, k=0, d, onedig, twodig;
        System.out.println("Enter number");
        n = ss.nextInt();
        for(;;) //checking correct number size
        {
            if(n>999999999)
            {
                System.out.println("Enter smaller number");
                n = ss.nextInt();
            }
            else
                break;
        }
        
        int copy=n, copy2=n, c=0, c2=0;
        String wrd="";
        while(copy>0)
        {
            c2++;
            copy/=10;
        }
        c = c2;
        
        int num[] = new int[9];
        
        //re-initialising for while loop
        while(copy2>0)
        {
            d = copy2%10;
            num[c2-1] = d*(int)Math.pow(10, i);
            c2--; i++;
            copy2/=10;
        }
        
        //name starts
        for(i=c-1; i>=0; i--)
        {
            if(n==0)
            {
                wrd = "zero"; 
                break;
            }
            
            if(c==1)
            {
                onedig = num[c-1]; k++; j=1; 
                wrd = fn.suffix1(onedig) + wrd;
                if(c==k)
                    break;
            }
            
            if(c>=2&&num[c-2]==0&&j==0)
            {
                onedig = num[c-1]; k++; j=1; 
                wrd = fn.suffix1(onedig) + wrd;
            }
            
            if(i==c-2&&k<=c)
            {
                twodig=num[c-1]+num[c-2]; k++;
                wrd = fn.suffix2(twodig) + wrd;
                if(c==k)
                    break;
            }
        
            if(i==c-3&&num[i]>0)
            {
                onedig = num[c-3]/100;
                wrd = "hundred " + wrd; k++;
                wrd = fn.suffix1(onedig) + wrd;
                if(c==k)
                    break;
            }
            
            if(i==c-4&&k<=c&&(c<5||num[c-5]==0)&&num[i]>0)
            {
                onedig = num[c-4]/1000;
                wrd = "thousand " + wrd; k++;
                wrd = fn.suffix1(onedig)+ wrd;
                if(c==k)
                    break;
            }
            else if(i==c-5&&k<=c&&(num[i]+num[i+1])>=10000)
            {
                twodig = (num[c-4]+num[c-5])/1000; 
                wrd = "thousand " + wrd; k++;
                wrd = fn.suffix2(twodig) + wrd;
                if(c==k)
                    break;
            }
        
            if(i==c-6&&k<=c&&(c<7||num[c-7]==0)&&num[i]>0)
            {
                onedig = num[c-6]/100000;
                wrd = "lakh " + wrd; k++;
                wrd = fn.suffix1(onedig) + wrd;
                if(c==k)
                    break;
            }
            else if(i==c-7&&k<=c&&(num[i]+num[i+1])>=1000000)
            {
                twodig = (num[c-6]+num[c-7])/100000;
                wrd = "lakh " + wrd; k++;
                wrd = fn.suffix2(twodig) + wrd;
                if(c==k)
                    break;
            }
        
            if(i==c-8&&k<=c&&(c<9||num[c-9]==0)&&num[i]>0)
            {
                onedig = num[c-8]/10000000;
                wrd = "crore " + wrd; k++;
                wrd = fn.suffix1(onedig) + wrd;
                if(c==k)
                    break;
            }
            else if(i==c-9&&k<=c&&(num[i]+num[i+1])>=100000000)
            {
                twodig = (num[c-8]+num[c-9])/10000000;
                wrd = "crore " + wrd; k++;
                wrd = fn.suffix2(twodig) + wrd;
                if(c==k)
                    break;
            }
        }
        System.out.println("Number in words :\n"+wrd);
    }
    
    String suffix1(int onedig)
    {
        int i;
        String str="";
        for(i=0; i<unit.length; i++)
        {
            if(onedig == unit[i])
            {
                str = U[i] + " " +str; 
                break;
            }
        }
        return str;
    }
    
    String suffix2(int twodig)
    {
        int i;
        String str="";
        if(twodig>19)
        {
            for(i=0; i<unit.length; i++)
            {
                if(twodig%10==unit[i])
                {
                    str = U[i] + " " + str; 
                    break;
                }
                else if(twodig%10==0)
                    break;
            }
            for(i=0; i<tens.length; i++)
            {
                if(10*(twodig/10)==tens[i])
                {
                    str = T[i] + " " + str; 
                    break;
                }
            }
        }
        else if(twodig<=19&&twodig>=10)
        {
            for(i=0; i<sp.length; i++)
            {
                if(twodig==sp[i])
                {
                    str = S[i] + " " + str; 
                    break;
                }
            }
        }
        return str;
    }
}
