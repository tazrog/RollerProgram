//Written by tazrog
//C Program that rolls dice and see how long it takes to roll all matches of a single number.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
	start:
   	setlocale(LC_NUMERIC, "");//To place commas in the count
	system("clear");
    short int dice, i, c, count, x, dierange, t, select, win, go, catch;
    unsigned long long int rolls, limit;
    srand(time(0));
    x=0;
    rolls=0;
	win=0;
	select=0;
	go=0;
	dierange=0;
	dice=0;	
	catch=0;
	limit=10000000;
	printf ("Welcome to Rogers random dice roller\n");
    printf("Pick the number of sides: ");
	scanf("%hd",&dierange);
    printf ("Pick number of Dice (max 10) :");
	scanf("%hd",&dice);
	sides:		
	printf("Rolling %hd - %hd sided dice \n", dice, dierange);
	printf("Rolling... \n");
	int n[dice];
	clock_t begin = clock();
   //loop
   while (x<1)
   {     	   
    count=0;
    rolls++;     
 	for (i = 1; i < dice+1; ++i)
     {
		n[i] = rand() % dierange + 1;
		select=n[1];
		if (n[i] ==  select)
		{
		win=win+1;
   		//Check to see if all dice match
   		if (win == dice)
   			count=count + n[i];
		}
		else {
		win=0;
		}   		
     }     
     if (win == dice) {
     	x=1;//exits loop
	 }
	if (rolls > limit){
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		if(time_spent >60){
	    printf("Rolled are over %'llu at time %3.3f minutes\n",limit, (time_spent)/60);
		if (catch <2){
			limit=limit+1000000000;
			catch++;
		}
		if (catch > 1) {
			limit=limit+5000000000;
			catch++;
		}
	}
	else{	
	    printf("Rolled are over %'llu at time %3.3f seconds\n",limit, time_spent);
		}  
		if (catch <2) {
			limit=limit+1000000000;
			catch++;
		}
		if (catch > 1) {
			limit=limit+5000000000;
			catch++;
		}
   	}
   }
	system("clear");
	printf("Rolled %hd - %hd sided dice.\nMatched %hd's on the %'lluth role!\n", dice, dierange, select, rolls);
	printf ("Rolls %'llu\n", rolls);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    if(time_spent >60){
	    printf("Time %3.3f minutes to find the number.\n", (time_spent)/60);
	}
	else{	
	    printf("Time %3.3f seconds to find the number.\n", time_spent);
		}
    for (t = 1; t <= dice; ++t)
		{
   		printf("Dice# %hd = %hd\n", t, n[t]);
    	}
	printf("Go again,  1 to go\n");
	scanf("%d", &go);
	if (go == 1)
	{
		goto start;
	}
	else{
		end;
	}
return 0;
}   
 
