#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define lotmax 69
#define lotmin 1
#define lotNoPerSet 7
#define maxset 5

/*if user input not between 1 to 5, return 0
else return user input number*/
int howmanyset()
{
    char a;
    int set;
    
    while ((a = getchar()) != '\n' && a != EOF)
    {
        if('1'<=a && a<='5')
        {
            set = a - '0';
            return set;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

/*input lotto array, if any number is the same, return 1
else return 0*/
int anySame(int *allNo)
{
    int x,y;
    for(x=0;x<lotNoPerSet;x++)
        for(y=x+1;y<lotNoPerSet;y++)
            if (allNo[x] == allNo[y])
                return 1;
    return 0;
}

int main()
{
    int set,i,j;
    int lotto[lotNoPerSet]={0};
    time_t t; 
    char date[128];
    FILE *lottofile;
    
    lottofile = fopen("D:\\cTest\\lotto.txt", "w");
    time(&t);
    strftime(date, sizeof(date), "%a %b %d %T %Y", localtime(&t));
	
    printf("歡迎光臨長庚樂透彩機台\n請問您要購買幾組樂透彩: ");
    while (1)
    {
        set = howmanyset();
        if (set != 0)
            break;
        printf("\r 請重新輸入(1-5): ");
    }
    
    printf(" ============= lotto649 =============\n");
	fprintf(lottofile, " ============= lotto649 =============\n");
    printf(" ====  %s  ====\n", date);
    fprintf(lottofile, " ====  %s  ====\n", date);
	srand(time(NULL));
    for (i=0;i< maxset;i++)
    {
        printf("[%d] ",i+1);
		fprintf(lottofile, "[%d] ",i+1);
		//reset lotto array to save new number
        memset(lotto,0,lotNoPerSet);
		
		//rand lotto number
        for (j=0;j< lotNoPerSet;j++)
            lotto[j] = rand()%lotmax+1;
        while(1)
        {
			// if any same number, re-generate number
            if (anySame(lotto))
                for (j=0;j< lotNoPerSet;j++)
                    lotto[j] = rand()%lotmax+1;
            else //no same number, break
                break;
        }
		
		//print 7 lotto number
        for(int k=0;k<lotNoPerSet;k++)
            if (i<set)
			{
                printf("%02d ",lotto[k]);
				fprintf(lottofile, "%02d ",lotto[k]);
			}
			else //over user request set, just print --
			{
                printf("-- ");
				fprintf(lottofile,"-- ");
			}

        printf("\n");
		fprintf(lottofile,"\n");
		
    }
    fprintf(lottofile,"========csie@CGU========");
    fclose(lottofile);
    printf("已為您將您購買的 %d組樂透組合輸出至 lotto.txt",set);
    
    return 0;
}
