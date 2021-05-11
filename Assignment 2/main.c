#include "mylibrary.h"

int main()
{
	char ch[] = "Hello!\n";
	char endl[] = "\n";
	printStr(ch);
	printStr(endl);
	int x = 51564;
	printInt(x);
	printStr(endl);
	x -= 46431181;
	printInt(x);
	printStr(endl);
	if (readInt(&x)){
		printInt(x);
		printStr(endl);
	}
	else
	{
		char err[] = "error in input\n";
		printStr(err);
	}
	float f = 0;
	if (readFlt(&f)){
		printFlt(f);
		printStr(endl);
	}
	else
	{
		char err[] = "error in input\n";
		printStr(err);
	}
	printStr(endl);
	return 0;
}