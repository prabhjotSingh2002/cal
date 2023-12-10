#include<stdio.h>

int main()
{
    char s[100]="-9.8*7.88-88+67.765/78*100.67+55";
    printf("ENTER EXPRESSION:\n");
    scanf("%s",s);
    
    
    float arr[20];
    int j;
    char operator[20]={0},k;
    int i;
    float num;

    if(s[0]=='-'||s[0]=='+')
    {
            i=1;
    }
    else
    {
        i=0;
    }
    j=0;
    k=0;num=0;
    float decimal=1;
    float b=0;
    int flag=0;
    for(;s[i];i++)
    {
        
        if(s[i]>='0'&& s[i]<='9')
        {
            if(flag==0)
            {
                num=num*10+s[i]-'0';
            }
            else
            {
                b=b*10+(s[i]-'0');
                decimal*=0.1;
            }
            
            if(s[i+1]==0)
            {
                arr[j]=num+b*decimal;
            }
           
            continue;
        }
        if(s[i]=='.')
        {
            flag=1;
            continue;
        }
        
    

        
        if(s[0]=='-' && j==0)
        {
            arr[j]=-num-b*decimal;
        }
        else
        {
            arr[j]=num+b*decimal;
        }  
        j++;
        printf("%d\t",b);
        switch(s[i])
        {
            case '-':
            case '+':
            case '/':
            case '*':
                    decimal=1;
                    flag=0;
                    operator[k]=s[i];
                    k++;
                    break;                      
        }
        num=0;
        b=0;
    }


    int m=0;
    for(m=0;m<=j;m++)
    {
        printf("%f\t",arr[m]);
    }
    printf("\n%s\n",operator);

    m=0;
    int f=0;
    while(operator[m])
    {
        if(operator[m]=='/'||operator[m]=='*')
        {
            if(operator[m]=='/')
            {
                if(arr[m+1]==0)
                {
                    printf("NAN...");
                    return ;
                }
                arr[m]=arr[m]/arr[m+1];
            }
            else
            {
                 arr[m]=arr[m]*arr[m+1];
            }

            for(f=m+1;f<j;f++)
            {
                arr[f]=arr[f+1];
            }
            j--;

            for(f=m;operator[f];f++)
            {
                operator[f]=operator[f+1];
            }
            k--;
            
            //arr remains
            printf("arr num remains-->\n");
            for(int n=0;n<=j;n++)
            {
                printf("%f\t",arr[n]);
            }

            //print operator
            printf("\nRemaining --> %s\n",operator);
            m--;

        }
        m++;
    }

    m=0;
    while(operator[m])
    {
        if(operator[m]=='+'||operator[m]=='-')
        {
            if(operator[m]=='+')
            {
                arr[m]=arr[m]+arr[m+1];
            }
            else
            {
                 arr[m]=arr[m]-arr[m+1];
            }

            for(f=m+1;f<j;f++)
            {
                arr[f]=arr[f+1];
            }
            j--;

            for(f=m;operator[f];f++)
            {
                operator[f]=operator[f+1];
            }
            k--;
            
            //arr remains
            printf("arr num remains-->\n");
            for(int n=0;n<=j;n++)
            {
                printf("%f\t",arr[n]);
            }

            //print operator
            printf("\nRemaining --> %s\n",operator);
            m--;

        }
        m++;
    }

}