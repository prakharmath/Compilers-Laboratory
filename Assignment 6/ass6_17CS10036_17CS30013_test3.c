int printi(int num);
int prints(char * c);
int readi(int *eP);

int factorial(int n)
{
  //printi(n);
  //prints("\n");
  if (n == 0)
    return 1;
  else
  {
	int a;
	a = factorial(n-1);
  }
    return(n * a);
}

int fibonaci(int i) 
{

   if(i == 0)
   {
      return 0;
   }
	
   if(i == 1) 
   {
      return 1;
   }
   int a,b,c;
   a = fibonaci(i-1);
   b = fibonaci(i-2);
   c = a + b;
   return c;
}


int main()
{
	int num, fact, fib;
	prints("*****************Recursive Factorial**********************\n");
	prints("Enter a number(<=10) for finding factorial!\n");
	int p;
	num = readi(&p);
	if(num>10)
	{
		prints("Error!! Number is >10!!\n");
	}
	else
	{
		fact = factorial(num);
		prints("The factorial of ");
		printi(num);
		prints(" is : ");
		printi(fact);
		prints("\n");
	}
	prints("*****************Recursive Fibonacci*************************************\n");
	prints("Enter a number(<=10) for finding nth Fibonaci!\n");
	int p;
	num = readi(&p);
	if(num>10)
	{
		prints("Error!! Number is >10!!\n");
	}
	else
	{
		fib = fibonaci(num);
		prints("The ");
		printi(num);
		prints("th fibonacci is : ");
		printi(fib);
		prints("\n");
	}
	
	return 0;
}
