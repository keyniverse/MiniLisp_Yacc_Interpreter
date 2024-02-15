/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_MINILISP_TAB_H_INCLUDED
# define YY_YY_MINILISP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "MiniLisp.y" /* yacc.c:1909  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define bool int
    #define true  1
    #define false 0

    #define MAX 500

    #define no_type                 1
    #define equals_to_parent        2
    #define print_num               3
    #define print_bool              4
    #define if_else                 5
    #define if_stmts                6
    #define define_variable         7
    #define get_variable            8
    #define define_function         9
    #define function                10
    #define function_parameters     11
    #define call_function           12
    #define define_inside_function  13
    #define integer                 14
    #define string                  15
    #define boolean                 16
    #define add                     17
    #define sub                     18
    #define mul                     19
    #define div                     20
    #define mod                     21
    #define bigger_than             22
    #define smaller_than            23
    #define equal                   24
    #define and                     25
    #define or                      26
    #define not                     27

    int yylex();
    void yyerror(const char *message);

    struct Dynamic {
        int   type;

        char*           name;
        int             intVal;
        bool            boolVal;
    };

    struct ASTNode {
        struct Dynamic* val;
        
        struct ASTNode* leftChild;
        struct ASTNode* rightChild;
    };

    struct Dynamic* newDynamic(int type, char* variableName, int intVal, bool boolVal);
    struct Dynamic* emptyDynamic();

    struct ASTNode* newNode(struct Dynamic* val, struct ASTNode* leftChild, struct ASTNode* rightChild);
    struct ASTNode* emptyNode();

    void traverse(struct ASTNode* node, int parent_type, bool insideFunction);

    struct ASTNode* root;

    struct ASTNode* definedVariables[MAX];
    int definedVariablesTop;

    void addDefinedVariable(struct ASTNode* node);
    struct ASTNode* getDefinedVariable(char* variableName);

    struct Function {
        char* functionName;
        
        struct ASTNode* params;
        struct ASTNode* task;
    };
    
    struct Function* definedFunctions[MAX];
    int definedFunctionsTop;

    struct ASTNode* cloneAST(struct ASTNode* node);

    void addFunction(char* functionName, struct ASTNode* functionToAdd);
    struct Function* getFunction(char* functionName);

    void assignParamsNameAndBind(struct ASTNode* parametersName, struct ASTNode* parametersToAssign, struct ASTNode* functionTask);
    void bindParams(struct ASTNode* taskNode, struct ASTNode* toReplace);

    char* getTypeName(int type);
    void typeChecking(struct ASTNode* node, int type);

    struct ASTNode* freeNode(struct ASTNode* node);

#line 141 "MiniLisp.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    ID = 259,
    BOOL = 260,
    PRINT_NUM = 261,
    PRINT_BOOL = 262,
    ADD = 263,
    SUB = 264,
    MUL = 265,
    DIV = 266,
    MOD = 267,
    BIGGER_THAN = 268,
    SMALLER_THAN = 269,
    EQUAL = 270,
    AND = 271,
    OR = 272,
    NOT = 273,
    DEFINE = 274,
    FUNCTION = 275,
    IF = 276
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 99 "MiniLisp.y" /* yacc.c:1909  */

    struct ASTNode* NODE;

#line 179 "MiniLisp.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINILISP_TAB_H_INCLUDED  */
