int printi(int num);
int prints(char * c);
int readi(int *eP);



int main()
{
	prints("******************element by element product of two arrays******************\n");
	int a[10];
	int b[10];
	int p, n, x, i, y, z;
	prints("Enter the number of elements of arrays a and b: ");	
	n = readi(&p);
	//prints("\n");
	prints("Enter the elements of array a:\n");
	for(i = 0; i < n; i++ )
	{
		x = readi(&p);
		a[i] = x;
	}
	//prints("\n");
	prints("Enter the elements of array b:\n");
	for(i = 0; i < n; i++ )
	{
		x = readi(&p);
		b[i] = x;
	}
	prints("The elements of the product array are:\n");
	for( i = 0; i < n; i++ )
	{
		x = a[i];	
		y = b[i];
		z = x * y;
		printi(z);
		prints(" ");
	}
	prints("\n");
	return 0;
}
