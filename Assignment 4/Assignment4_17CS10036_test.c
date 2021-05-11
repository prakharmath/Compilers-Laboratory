

int main()
{
int n = 100;
float x = 4.21;
n+=32;
int i=0;
while(i<n)
{
	i++;
	if (n&1){
		int j = 0;
		int k = 5;
		do{
			k |= j;
			j++;
		}while (j <= 10);
	}
	else{
		n = (n <= 143) ? (n+123) : (n + 242);
	}

}
for (int i = 0 ; i < n ; i++)
{
	if (n&1){
		int j = 0;
		int k = 5;
		do{
			k &= j;
			j++;
		}while (j <= 10);
	}
	else{
		n = (n <= 143) ? (n+123) : (n + 242);
	}
}
i=0;
do
{
    i++;
    if (n&1){
		int j = 0;
		int k = 5;
		do{
			k ^= j;
			j++;
		}while (j <= 10);
	}
	else{
		n = (n <= 143) ? (n+123) : (n + 242);
	}

}while(i<n);
return 0;
}

