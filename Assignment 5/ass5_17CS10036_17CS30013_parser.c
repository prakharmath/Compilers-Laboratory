#include <stdio.h>
#include "y.tab.h"

int main(int argc, char const *argv[])
{
  yyparse();
  return 0;
}