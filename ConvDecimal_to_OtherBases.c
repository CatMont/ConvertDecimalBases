/****************************************************************************
 *                                                                          *
 * File    : main.c                                                         *
 *                                                                          *
 * Purpose : Console mode (command line) program.                           *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>

/****************************************************************************
 *                                                                          *
 * Function: main                                                           *
 *                                                                          *
 * Purpose : Main entry point.                                              *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

/*  Student Name : Catherine Monteith
	Course		 : 472
	Semester 	 : Spring 2023 */


#include <stdio.h>

/* The function decimal Converter takes input from main
and creates three empty arrays for the maximum lengths that can be created
within the constraints of this program. By using the division method and storing 
the remainders in the formed arrays depending on the value of BaseConverter, 
the program is then able to print out the elements in the array in reverse order
using for-loops */ 


int decimalConverter(int q, int baseConverter) 
{
	int bin[21];
	int oct[7];
	char hex[6];
 	char hexadecimal[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', '\0'};
  
	int i = 0; 
	int r; 
	while (q > 0) // this loop will continue until the quotient is 0
    	{
      		r = q % baseConverter;
      		q = q / baseConverter;
      		if(baseConverter == 2)
      		{
        		bin[i] = r;
      		}
      		if(baseConverter == 8)
      		{
        		oct[i] = r;
      		}
      		if(baseConverter == 16) // this particular statement sets i in hex array to element in hexidecimal based on remainder
      		{
        		hex[i] = hexadecimal[r];
      		}
      		i++;
    	}
	if (baseConverter == 2) //these if statements will run depending on value of baseConverter
	{
    	if(i < 8)
		{
        	for(i; i <8; i++)// this statement will put zeroes as placeholders for numerical values < 255 to produce 8 digits
			{
        		bin[i] = 0;
     		}
      	}
		printf("Binary Output:");//prints elements in array backwards from i
      	for(i = i -1; i >= 0; i--)
		{
        	printf("%d", bin[i]);
    	}
    }

    else if(baseConverter == 8)
	{
    	if(i < 3)
		{
        	for(i; i < 3; i++)// 0 placeholders 
			{
          		oct[i] = 0;
        	}
      	}
      	printf("\nOctal Output:");
      	for(i = i -1; i >= 0; i--)//backwards from i
		{
        	printf("%d", oct[i]);
    	}
    }

    else if(baseConverter == 16)
	{
      	if(i == 0) //0 placeholder
	  	{
        	hex[i] = 0;
      	}
      	printf("\nHexadecimal Output:");
      	for(i = i -1; i >= 0; i--)//backwards from i
		{
        	printf("%c", hex[i]);
    	}
    }
}


/* The program will run as long as run = 0 and will only stop if user inserts '-1'
With each loop, the function takes user input and if possible turns it into an integer
As long as this integer is within bounds, the the decimalConverter function will be called. 
If the output is out of range, the program will produce an error message and restart the loop and
if -1 is inserted the program will end */



int main(int argc, char *argv[])
{
	int run = 0;
 	int verify;
	printf("Welcome! This program takes decimal input and converts it to binary, octal and hexidecimal\n");
	do
	{ 
		char input[9];// creates a character array that accepts user input
  		int decimalNumber;
  		printf("Please insert a number between 0 and 2,000,000 or type '-1' to exit the program: ");
  		fgets(input, 9, stdin);//reads from keyboard input into character array

		int result = sscanf(input, "%d", &decimalNumber);//if character array can be read as an int type, it will be stored at the memory location of decimalNumber


  		if(result == 1) //result will become 1 if sscanf receives valid input allowing the program to proceed
		{
    		if (decimalNumber >= 0 && decimalNumber <= 2000000)//values must satisfy both conditions
      		{
        		printf("Decimal Value: %i\n", decimalNumber);//baseconverter is hardcoded since it does not vary
        		int result = decimalConverter(decimalNumber,2);
        		int result2 = decimalConverter(decimalNumber,8);
        		int result3 = decimalConverter(decimalNumber,16);
        		printf("\n");
    		}
      		else if(decimalNumber == -1) //if input = 1, run will be set to -1 and the loop will end.
      		{
        		printf("Goodbye\n");
        		run = -1;
        
      		}
      		else
      		{
        		printf("Number out of accepted Range\n");//will print if x is not within above bounds
      		}
    	}
  		else // if invalid input, like a letter, is received, sscanf will not use it and the user will prompted again.(the loop will restart)
		{
    		printf("Invalid Input, Please insert a number\n");
  		}
    }while(run == 0);
}

