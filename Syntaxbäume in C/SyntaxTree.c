#include "SyntaxTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
Expr* newBinExpr(BinOp op,Expr* left, Expr* right){
    Expr* this = malloc(sizeof(Expr));
    BinExpr expr = {op,left,right};
    this->type = BIN_OP;
    this->expr.binExpr = expr;
    return this;
}
Expr* newAddExpr(Expr* left, Expr* right){
    return newBinExpr(ADD,left,right);
}
Expr* newSubExpr(Expr* left, Expr* right){
    return newBinExpr(SUB,left,right);
}
Expr* newMultExpr(Expr* left, Expr* right){
    return newBinExpr(MULT,left,right);
}
Expr* newDivExpr(Expr* left, Expr* right){
    return newBinExpr(DIV,left,right);
}
Expr* newModExpr(Expr* left, Expr* right){
    return newBinExpr(MOD,left,right);
}
Expr* newLtExpr(Expr* left, Expr* right){
    return newBinExpr(LT,left,right);
}
Expr* newGtExpr(Expr* left, Expr* right){
    return newBinExpr(GT,left,right);
}
Expr* newLeExpr(Expr* left, Expr* right){
    return newBinExpr(LE,left,right);
}
Expr* newGeExpr(Expr* left, Expr* right){
    return newBinExpr(GE,left,right);
}
Expr* newEqExpr(Expr* left, Expr* right){
    return newBinExpr(EQ,left,right);
}
Expr* newNeqExpr(Expr* left, Expr* right){
    return newBinExpr(NEQ,left,right);
}
Expr* newAndExpr(Expr* left, Expr* right){
    return newBinExpr(AND,left,right);
}
Expr* newOrExpr(Expr* left, Expr* right){
    return newBinExpr(OR,left,right);
}
Expr* newSeqExpr(Expr* left, Expr* right){
    return newBinExpr(SEQ,left,right);
}
Expr* newVariableExpr(unsigned int varNr){
    Expr *this = malloc(sizeof(Expr));
    VariableExpr e = {varNr};
    this->type = VAR;
    this->expr.variableExpr = e;
    return this;
}
Expr* newLiteralExpr(long int value){
    Expr *this = malloc(sizeof(Expr));
    LiteralExpr e = {value};
    this->type = LIT;
    this->expr.literalExpr = e;
    return this;
}
Expr* newAssignExpr(unsigned int varNr,Expr* rhs){
    Expr *this = malloc(sizeof(Expr));
    AssignExpr e = {varNr, rhs};
    this->type = ASSIGN;
    this->expr.assignExpr= e;
    return this;
}
Expr* newIfElseExpr(Expr* cond, Expr* ifCase, Expr* elseCase) {
    Expr *this = malloc(sizeof(Expr));
    IfElseExpr expr = {cond, ifCase, elseCase};
    this->type = IF_ELSE;
    this->expr.ifElseExpr = expr;
    return this;
}
Expr* newWhileExpr(Expr* cond, Expr* body){
    Expr *this = malloc(sizeof(Expr));
    WhileExpr e = {cond, body};
    this->type = WHILE;
    this->expr.whileExpr = e;
    return this;
}
Expr* newFunCallExpr(char* name, Expr** args, int argsNr){
    Expr *this = malloc(sizeof(Expr));
    FunCallExpr e = {name, -1,args, argsNr};
    this->type = FUN_CALL;
    this->expr.funCallExpr = e;
    return this;
}

void deleteExpr(Expr* this){
    switch (this->type){
        case BIN_OP: deleteBinExpr(this->expr.binExpr);break;
        case IF_ELSE: deleteIfElseExpr(this->expr.ifElseExpr);break;
        case WHILE: deleteWhileExpr(this->expr.whileExpr);break;
        case ASSIGN: deleteAssignExpr(this->expr.assignExpr);break;
        case FUN_CALL: deleteFunCallExpr(this->expr.funCallExpr);break;
        default:break;
    }
    free(this);
}

void deleteBinExpr(BinExpr binExpr){
    deleteExpr(binExpr.left);
    deleteExpr(binExpr.right);
}
void deleteIfElseExpr(IfElseExpr expr){
    deleteExpr(expr.cond);
    deleteExpr(expr.ifCase);
    deleteExpr(expr.elseCase);
}
void deleteWhileExpr(WhileExpr expr){
    deleteExpr(expr.cond);
    deleteExpr(expr.body);
}
void deleteAssignExpr(AssignExpr expr){
    deleteExpr(expr.rhs);
}
void deleteFunCallExpr(FunCallExpr funCallExpr){
    for (int i = 0; i < funCallExpr.argsNr; i++)  deleteExpr(funCallExpr.args[i]);

    free(funCallExpr.name);
    free(funCallExpr.args);
}

long int eval(Expr* this, long int* env,Program p){
    switch (this->type){
        case LIT: return evalLiteralExpr(this->expr.literalExpr,env, p);
        case BIN_OP: return evalBinOp(this->expr.binExpr,env, p);
        case ASSIGN: return evalAssignExpr(this->expr.assignExpr,env, p);
        case VAR: return evalVariableExpr(this->expr.variableExpr,env, p);
        case WHILE: return evalWhileExpr(this->expr.whileExpr,env, p);
        case IF_ELSE: return evalIfElseExpr(this->expr.ifElseExpr,env, p);
        case FUN_CALL: return evalFunCallExpr(&(this->expr.funCallExpr),env, p);
        default: return -1;
    }
}
long int evalLiteralExpr(LiteralExpr expr, long int* env,Program p){
    return expr.value;
}
long int evalVariableExpr(VariableExpr expr, long int* env,Program p){
    return env[expr.varNr];
}
long int evalIfElseExpr(IfElseExpr expr, long int* env,Program p){
    return eval(expr.cond,env, p)
           ?eval(expr.ifCase,env, p)
           :eval(expr.elseCase,env, p);
}
long int evalBinOp(BinExpr expr, long int* env, Program p){
    if(expr.op == AND)
        return eval(expr.left, env, p) == 1 && eval(expr.right, env, p) == 1;
    if(expr.op == OR)
        return eval(expr.left, env, p) == 1 || eval(expr.right, env, p) == 1;
    long int leftRes = eval(expr.left, env, p);
    long int rightRes = eval(expr.right, env, p);

    switch (expr.op)
    {
        case ADD:
            return leftRes + rightRes;
        case SUB:
            return leftRes - rightRes;
        case MULT:
            return leftRes * rightRes;
        case DIV:
            return leftRes / rightRes;
        case MOD:
            return leftRes % rightRes;
        case LT:
            return leftRes< rightRes ? 1 : 0;
        case GT:
            return leftRes > rightRes ? 1 : 0;
        case LE:
            return leftRes <= rightRes ? 1 : 0;
        case GE:
            return leftRes >= rightRes ? 1 : 0;
        case EQ:
            return leftRes == rightRes ? 1 : 0;
        case NEQ:
            return leftRes != rightRes? 1 : 0;
        default:
            return rightRes;
    }
}
long int evalAssignExpr(AssignExpr expr, long int* env, Program p){
    long int result = eval(expr.rhs, env, p);
    env[expr.varNr] = result;
    return result;
}
long int evalWhileExpr(WhileExpr expr, long int* env, Program p){
    long int result = 0;
    while(eval(expr.cond, env,p)) result = eval(expr.body, env, p);
    return result;
}
long int evalFunCallExpr(FunCallExpr* expr, long int* env, Program p){
    //Schleifenvariable
    int i;

    //weiß ich noch nicht die Nummer der Funktion?
    if (expr->compiledNr<0){
        //durchlaufe die Funktionsdefinitionen
        for (i=0;i<p.funsNr;i++){
            //habe ich die aufgerufene Funktion gefunden?
            if (strcmp(expr->name, p.funs[i].name)==0){
                //dann merke ich mir die Nummer
                expr->compiledNr = i;
                break;
            }
        }
        // ich habe keine Funktion gefunden.
        if (i>=p.funsNr){
            fprintf(stderr,"unknown function: %s\n",expr->name);
            return -1;
        }
    }
    // ich hole die Definition der aufgerufenen Funktion
    FunDef* fun = p.funs+(expr->compiledNr);

    //falsche Argumentanzahl!
    if (fun->argsNr != expr->argsNr){
        fprintf( stderr
                ,"wrong nr of arguments for function %s: expected %d but found %d\n"
                , expr->name
                , fun->argsNr
                , expr->argsNr);
        return -1;
    }else {

        //Erzeugen Sie eine neue Umgebung für 100 long int.
        long int *environment = malloc(100 * sizeof(long int));
        //Iterieren Sie über die args von fun.
        // Setzen Sie darin für jedes Argument, das Ergenis seiner Auswertung am passenden Index in der neuen Umgebung
        for (i = 0; i < fun->argsNr; i++){
            environment[fun->args[i]] = eval((expr->args)[i], env, p);
        }
        //Werten Sie den Funktionsrumpf in der neuen Umgebung aus.
        long int res = eval(fun->body, environment, p);

       // Löschen Sie die neue Umgebung.
        free(environment);

        // Geben Sie das Ergebnis der Auswertung des Rumpfs als Ergebnis zurück.
        return res;

    }

}
