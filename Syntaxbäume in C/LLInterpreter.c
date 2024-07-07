#include "SyntaxTree.h"
#include "y.tab.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

extern long int evalString(char* str);
extern Program parseProgram(char* prog);
extern void finishProgram();

int main(int argc, char** args){
  Program p;
  if (argc>1){
    p = parseProgram(args[1]);
  }
  printf("Welcome. Type :? for help.\n");
  while (true){
    char *str = NULL;
    size_t size;
    printf(">: ");
    if (getline(&str, &size, stdin) != -1) {
      if(strcmp(str,":q\n")==0){
	free(str);
	break;
      } else if(strcmp(str,":l\n")==0){
	int i;
	for(i=0;i<p.funsNr;i++){
	  printf("%s \n",p.funs[i].name);
	}
      } else if(strcmp(str,":?\n")==0){
	printf("Commands:\n  :q   quit the programm\n  :l   list defined functions\n  :?   this help\n  1+1  evaluate expression\n");
      }else{
	printf("%ld\n",evalString(str));
	fflush(stdout);
      }
      
      free(str);
    }
  }
  if (argc>1){
    finishProgram();
  }
  return 0;
}
