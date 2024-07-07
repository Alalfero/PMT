#ifndef LL__H
#define LL__H

typedef enum{
  ADD, SUB, MULT, DIV, MOD, LT, GT, LE, GE, EQ, NEQ, AND, OR, SEQ
  }  BinOp;


typedef enum {
  BIN_OP, VAR, LIT, IF_ELSE, WHILE, ASSIGN, FUN_CALL
} ExprType;


struct Ex;
typedef struct Ex Expr;    


typedef struct{
  BinOp op;
  Expr* left;
  Expr* right;
} BinExpr;


typedef struct {
  unsigned int varNr;
}VariableExpr;


typedef struct {
  long int value;
} LiteralExpr;


typedef struct {
  unsigned int varNr;
  Expr* rhs;
}AssignExpr;


typedef struct{
  Expr* cond;
  Expr* ifCase;
  Expr* elseCase;
} IfElseExpr;


typedef struct {
  Expr* cond;
  Expr* body;
} WhileExpr;


typedef struct{
  char* name;
  int compiledNr;
  Expr** args;
  int argsNr;
} FunCallExpr;


union ExprUnion{
  BinExpr binExpr;
  VariableExpr variableExpr;
  LiteralExpr literalExpr;
  AssignExpr assignExpr;
  IfElseExpr ifElseExpr;
  WhileExpr whileExpr;
  FunCallExpr funCallExpr;
};


struct Ex{
  ExprType type;
  union ExprUnion expr;
};



typedef struct{
  char* name;
  int* args;
  int argsNr;
  Expr* body;
} FunDef;

typedef struct{
  FunDef* funs;
  int funsNr;
}  Program;

typedef union {Program prog;Expr* expr;} ParseResult;


Expr* newBinExpr(BinOp op,Expr* left, Expr* right);
Expr* newVariableExpr(unsigned int varNr);
Expr* newLiteralExpr(long int value);
Expr* newIfElseExpr(Expr* cond, Expr* ifCase, Expr* elseCase);
Expr* newWhileExpr(Expr* cond, Expr* body);
Expr* newAssignExpr(unsigned int varNr,Expr* rhs);
Expr* newFunCallExpr(char* name, Expr** args, int argsNr);


Expr* newAddExpr(Expr* left, Expr* right);
Expr* newSubExpr(Expr* left, Expr* right);
Expr* newMultExpr(Expr* left, Expr* right);
Expr* newDivExpr(Expr* left, Expr* right);
Expr* newModExpr(Expr* left, Expr* right);
Expr* newLtExpr(Expr* left, Expr* right);
Expr* newGtExpr(Expr* left, Expr* right);
Expr* newLeExpr(Expr* left, Expr* right);
Expr* newGeExpr(Expr* left, Expr* right);
Expr* newEqExpr(Expr* left, Expr* right);
Expr* newNeqExpr(Expr* left, Expr* right);
Expr* newAndExpr(Expr* left, Expr* right);
Expr* newOrExpr(Expr* left, Expr* right);
Expr* newSeqExpr(Expr* left, Expr* right);


void deleteExpr(Expr* this);
void deleteBinExpr(BinExpr binExpr);
void deleteIfElseExpr(IfElseExpr expr);
void deleteWhileExpr(WhileExpr expr);
void deleteAssignExpr(AssignExpr expr);
void deleteFunCallExpr(FunCallExpr binExpr);



long int eval(Expr* this, long int* env, Program p);


long int evalBinOp(BinExpr expr, long int* env,Program p);
long int evalVariableExpr(VariableExpr expr, long int* env,Program p);
long int evalLiteralExpr(LiteralExpr expr, long int* env,Program p);
long int evalIfElseExpr(IfElseExpr expr, long int* env,Program p);
long int evalWhileExpr(WhileExpr expr, long int* env,Program p);
long int evalAssignExpr(AssignExpr expr, long int* env,Program p);
long int evalFunCallExpr(FunCallExpr* expr, long int* env,Program p);

#endif
  

