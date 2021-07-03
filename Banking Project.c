#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
	system("color 1F");
	int pin = 1234, option, enterPin, count = 0, amount = 1;
	float balance = 5000;
	int con_Transaction = 1;
	
	time_t now;
	time(&now);
	printf("\n");
	printf("\t\t\t\t\t     %s", ctime(&now));
	printf("\n\t\t\t================*Welcome to Commercial Bank ATM*================");
	
	while(pin != enterPin)
	{
		printf("\nPlease enter your pin: ");;
		scanf("%d", &enterPin);
		if(enterPin != pin)
		{
			Beep(610,510);
			printf("Inavalid Pin. ");
		}
		count ++;
		if(count == 3 && pin != enterPin)
		{
			printf("Please Enter Valid PIN Number!");
			return -1;
		}
	}
	
	while(con_Transaction != 0)
	{
		printf("\n\t\t\t============*Availabel Transactions*============");
		printf("\n\n\t\t1.Withdrawal");
		printf("\n\t\t2.Deposit");
		printf("\n\t\t3.Check Balance");
		printf("\n\n\tPlease select the option : ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: 
			while(amount % 500 != 0)
			{
				printf("\n\t\tEnter the amount: ");
				scanf("%d", &amount);
				if (amount % 500 != 0)
				{
					printf("\n\t The amount should be multiple of 500");
				}
				if (amount > balance)
				{
					printf("\n\t Sorry insuffcient balance");
					amount = 1;
					break;
				}
				else 
				{
					balance -= amount;
					printf("\n\t\t You have withdrawn Rs.%d. Your new balance is %.2f", amount, balance);
					printf("\n\n\t\t\t============*Thank you for banking with Commercial Bank*============");
					amount = 1;
					break;
				}
			case 2:
				printf("\n\t\tPlease enter the amount : ");
				scanf("%d", &amount);
				balance += amount;
				printf("\n\t\tYou have deposited Rs.%d. Your new balance is %.2f", amount, balance);
				printf("\n\n\t\t\t============*Thank you for banking with Commercial Bank*============");
				amount = 1;
				break;
				
			case 3:
				printf("\n\t\tYour balance is Rs.%.2f", balance);
				printf("\n\n\t\t\t============*Thank you for banking with Commercial Bank*============");
				break;
				
			default:
				Beep(610,510);
				printf("\n\t\t\t\t====Inavalid Option!!====");
				return -1;
			}
			
			printf("\n\n\t\tDo you wish to perform another transaction? Press 1[Yes], 0[No]");
			scanf("%d", &con_Transaction);
			if (con_Transaction == 0)
			{
				printf("\n\t\t\t\t\t====Have a nice day!====");
			}
		}
	count ++;
	}
}
