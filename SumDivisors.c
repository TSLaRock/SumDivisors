#include <stdio.h>
int sum_divisors(int n);

int main(void)  
{ // START MAIN
   int n, cycles, lastNum, currNum;
   puts("Please enter a number less than or equal to 100: ");
   while((scanf("%d", &n)) != EOF)
   {
   // Make sure all variables are reset to 0
     cycles = lastNum = currNum = 0;
     // -- INPUT VALIDATION -- //
     if(n <= 100)
     {
       // print n
       printf("%d, ", n);
     // Set lastNum to the first sum
     lastNum = sum_divisors(n);
     printf("%d, " , lastNum);
     currNum = sum_divisors(lastNum);
     printf("%d, " , currNum);
     // the sum_divisors() function has been called twice
     cycles = 2;
     // While currNum does not equal lastNum
       while(currNum != lastNum)
       {
        // set lastNum = currNum
        lastNum = currNum;
        // set currNum to sum_divisors of lastNum
        currNum = sum_divisors(lastNum);
        // print currNum
        printf("%d, ", currNum);
        // increment cycles
        cycles++;
       }
     
     // print the number of cycles
     printf("\t %d cycles \n", cycles);
     }
     else
       {
	 printf("Number MUST be < 100 \n");
       }
   }
      return 0;
} // -- END MAIN -- //


   // -- BEGIN SUM_DIVISORS -- //
int sum_divisors(int n)
{ 

 int sum = 0; 
 int i;
 int k;  
   // if the number is less than or equal to 1, the sum is zero
 if(n <=1) return 0;
 else
 {
   i = n-1; 
   for(; i >0; i--)
   {
    if( (n % i) == 0)  // if i divides equally into n it is a divisor
    {
    sum += i;
    }
   }
  }
  return sum; 
    
} // -- END SUM_DIVISORS -- //
