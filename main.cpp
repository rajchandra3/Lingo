#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int main()
{
	cout<<"\n\n\t\t\t\t\t\t\t\t\tWelcome to Lingo\n\t\t\t\t\t\t\t\t**----------------------------**\n\n";
    int i,j,c,f,random,counts=0;
    char w[5],nw[5],t[15],word[5]="",correct[5],guessed[]={'_','_','_','_','_'};
    char s[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    srand(time(NULL));
    for(i=0;i<5;i++)
    {
		random=rand()%25+0;
       	word[i]=s[random];			
	}
    strcpy(w,word);
    strcpy(correct,"false");
    while(strcmpi(correct,"false")==0)
    {
    	counts++;
        cout<<"\t\t\t\t\t\t\tGuess the word : ";
        cin>>nw;
        strcpy(t,"");
        c=0,f=0;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(nw[i]==w[j])
                {
                    if(i==j) //if the character is found @ the same position
                    {
                        t[c]='[';
                        c++;
                        t[c]=nw[i];
                        c++;
                        t[c]=']';
                        c++;
                        guessed[i]=nw[i];
                    }
                    else //if the position is different
                    {
                        t[c]='(';
                        c++;
                        t[c]=nw[i];
                        c++;
                        t[c]=')';
                        c++;
                    }
                	break;
                }
                else if(j==4 && nw[i]!=w[j]) //if the character is not found
                {
                    t[c]=nw[i];
                    c++;
                }
                
            }
        }
        t[c]='\0';
        if((strcmpi(nw,w))==0)
        {
        	strcpy(correct,"true");
        	cout<<"\n\t\t\t\t\t\t\t\t\tCongratulaions !!"<<endl;
        	cout<<"\n\t\t\t\t\t\t\t\t\tLives used : "<<counts-1;
		}
		else if(strcmpi(nw,"1")==0)
		{
			counts--;
			cout<<"\n\t\t\t\t\t\t\t\t\t"<<w<<endl;
			getch();
			system("cls");
		}
		else
		{
			if(strlen(guessed)!=0)
				cout<<"\n\t\tYou have Guessed: "<<guessed;
			else
				cout<<"\n\t\tYou have Guessed: NONE";
			cout<<"\t-------------------------------------------------------------\tClue:"<<t<<endl;
		}
			 
    }
    getch();
}
