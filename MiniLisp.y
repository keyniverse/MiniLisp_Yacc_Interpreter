%code requires{
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
}


%union {
    struct ASTNode* NODE;
}

%type   <NODE>  stmt
%type   <NODE>  stmts
%type   <NODE>  print_stmt

%type   <NODE>  exp
%type   <NODE>  exps

%type   <NODE>  num_op
%type   <NODE>  logical_op

%type   <NODE>  def_stmt
%type   <NODE>  variable

%type   <NODE>  function_exp
%type   <NODE>  ids
%type   <NODE>  function_call
%type   <NODE>  function_ids
%type   <NODE>  function_body
%type   <NODE>  function_name
%type   <NODE>  parameters

%type   <NODE>  if_exp
%type   <NODE>  test_exp
%type   <NODE>  then_exp
%type   <NODE>  else_exp

%token  <NODE>  NUMBER
%token  <NODE>  ID
%token  <NODE>  BOOL

%token  <NODE>  PRINT_NUM
%token  <NODE>  PRINT_BOOL

%token  <NODE>  ADD
%token  <NODE>  SUB
%token  <NODE>  MUL
%token  <NODE>  DIV
%token  <NODE>  MOD

%token  <NODE>  BIGGER_THAN
%token  <NODE>  SMALLER_THAN
%token  <NODE>  EQUAL

%token  <NODE>  AND
%token  <NODE>  OR
%token  <NODE>  NOT

%token  <NODE>  DEFINE
%token  <NODE>  FUNCTION
%token  <NODE>  IF
%%

program         :   stmts       {
                    root = $1;
                }

stmts           :   stmt stmts  {
                    $$ = newNode(emptyDynamic(), $1, $2);
                }
                |   stmt        {
                    $$ = $1;
                }

stmt            :   exp         {
                    $$ = $1;
                }
                |   def_stmt    {
                    $$ = $1;
                }
                |   print_stmt  {
                    $$ = $1;
                }
                ;

print_stmt      :   '(' PRINT_NUM   exp ')' {
                    $$ = newNode(newDynamic(print_num, NULL, 0, false), $3, NULL);
                }
                |   '(' PRINT_BOOL  exp ')' {
                    $$ = newNode(newDynamic(print_bool, NULL, 0, false), $3, NULL);
                }

exps            :   exp exps    {
                    $$ = newNode(newDynamic(equals_to_parent, NULL, 0, false), $1, $2);
                }
                |   exp         {
                    $$ = $1;
                }

exp             :   BOOL            {
                    $$ = $1;
                }
                |   NUMBER          {
                    $$ = $1;
                }
                |   variable        {
                    $$ = newNode(newDynamic(get_variable, $1->val->name, 0, false), NULL, NULL);
                }
                |   num_op          {
                    $$ = $1;
                }
                |   logical_op      {
                    $$ = $1;
                }
                |   function_exp    {                    
                    $$ = $1;
                }
                |   function_call   {                    
                    $$ = $1;
                }
                |   if_exp   {                    
                    $$ = $1;
                }
                ;

num_op          :   '(' ADD             exp exps    ')' {
                    $$ = newNode(newDynamic(add, NULL, 0, false), $3, $4);
                }
                |   '(' SUB             exp exp     ')' {
                    $$ = newNode(newDynamic(sub, NULL, 0, false), $3, $4);
                }
                |   '(' MUL             exp exps    ')' {
                    $$ = newNode(newDynamic(mul, NULL, 0, false), $3, $4);
                }
                |   '(' DIV             exp exp     ')' {
                    $$ = newNode(newDynamic(div, NULL, 0, false), $3, $4);
                }
                |   '(' MOD             exp exp     ')' {
                    $$ = newNode(newDynamic(mod, NULL, 0, false), $3, $4);
                }
                |   '(' BIGGER_THAN     exp exp     ')' {
                    $$ = newNode(newDynamic(bigger_than, NULL, 0, false), $3, $4);
                }
                |   '(' SMALLER_THAN    exp exp     ')' {
                    $$ = newNode(newDynamic(smaller_than, NULL, 0, false), $3, $4);
                }
                |   '(' EQUAL           exp exps    ')' {
                    $$ = newNode(newDynamic(equal, NULL, 0, false), $3, $4);
                }

logical_op      :   '(' AND     exp exps    ')' {
                    $$ = newNode(newDynamic(and, NULL, 0, false), $3, $4);
                }
                |   '(' OR      exp exps    ')' {
                    $$ = newNode(newDynamic(or, NULL, 0, false), $3, $4);
                }
                |   '(' NOT     exp         ')' {
                    $$ = newNode(newDynamic(not, NULL, 0, false), $3, NULL);
                }

def_stmt        :   '(' DEFINE ID exp ')'   {
                    if($4->val->type == function) {
                        $$ = newNode(newDynamic(define_function, NULL, 0, false), $3, $4);
                    } else {
                        $$ = newNode(newDynamic(define_variable, NULL, 0, false), $3, $4);
                    }
                }
                ;

variable        :   ID  {
                    $$ = $1;
                }

function_exp    :   '(' FUNCTION function_ids function_body ')' {
                    $$ = newNode(newDynamic(function, NULL, 0, false), $3, $4); 
                }

ids             :   ID  ids     {
                    $$ = newNode(newDynamic(function_parameters, NULL, 0, false), $1, $2);
                }
                |               {
                    $$ = emptyNode();
                }
                ; 

function_ids    :   '(' ids ')' {
                    $$ = $2;
                }

function_body   :   def_stmt function_body  {
                    $$ = newNode(newDynamic(define_inside_function, NULL, 0, false), $1, $2);
                }
                |   exp                     {
                    $$ = $1;
                }

function_call   :   '(' function_exp    parameters ')'  {
                    $$ = newNode(newDynamic(call_function, NULL, 0, false), $2, $3);
                }
                |   '(' function_name   parameters ')'  {
                    $$ = newNode(newDynamic(call_function, NULL, 0, false), $2, $3);
                }

parameters      :   exp parameters  {
                    $$ = newNode(newDynamic(function_parameters, NULL, 0, false), $1, $2);
                }
                |                   {
                    $$ = emptyNode();
                }

function_name   :   ID  {
                    $$ = $1;
                }

if_exp          :   '(' IF test_exp then_exp else_exp ')'     {
                    struct ASTNode* ifStatements = newNode(newDynamic(if_stmts, NULL, 0, false), $4, $5);
                    $$ = newNode(newDynamic(if_else, NULL, 0, false), $3, ifStatements);
                }

test_exp        :   exp     {
                    $$ = $1;
                }

then_exp        :   exp     {
                    $$ = $1;
                }

else_exp        :   exp     {
                    $$ = $1;
                }

%%

struct Dynamic* newDynamic(int type, char* name, int intVal, bool boolVal) {  //當你看到 struct Dynamic* 作為函式返回類型時，這意味著這個函式將創建並返回一個指向 struct Dynamic 的動態分配的記憶體空間的指標。
    struct Dynamic* toCreate = (struct Dynamic *) malloc(sizeof(struct Dynamic));

    toCreate->type = type;
    toCreate->name = name;

    toCreate->intVal = intVal;
    toCreate->boolVal = boolVal;

    return toCreate;
}

struct Dynamic* emptyDynamic() {
    return newDynamic(no_type, NULL, 0, false);
}

struct ASTNode* newNode(struct Dynamic* val, struct ASTNode* leftChild, struct ASTNode* rightChild) {
    struct ASTNode* toCreate = (struct ASTNode *) malloc(sizeof(struct ASTNode));

    toCreate->val = val;
    toCreate->leftChild = leftChild;
    toCreate->rightChild = rightChild;

    return toCreate;
}

struct ASTNode* emptyNode() {
    return newNode(emptyDynamic(), NULL, NULL);
}

void addDefinedVariable(struct ASTNode* node) {
    definedVariables[++definedVariablesTop] = node;
}

struct ASTNode* getDefinedVariable(char* name) {
    for(int i = 0; i <= definedVariablesTop; i++) {
        if(strcmp(definedVariables[i]->val->name, name) == 0) {
            return cloneAST(definedVariables[i]);
        }
    }
}

struct ASTNode* cloneAST(struct ASTNode* node) {
    if(node == NULL) {
        return NULL;
    }
    
    struct ASTNode* toClone = emptyNode();

    toClone->val->type = node->val->type;
    toClone->val->name = node->val->name;

    toClone->val->intVal = node->val->intVal;
    toClone->val->boolVal = node->val->boolVal;

    toClone->leftChild = cloneAST(node->leftChild);
    toClone->rightChild = cloneAST(node->rightChild);

    return toClone;
}

void addFunction(char* functionName, struct ASTNode* functionToAdd) {
    struct Function* toAdd = (struct Function *) malloc(sizeof(struct Function));

    toAdd->functionName = functionName;
    toAdd->params = functionToAdd->leftChild;    // to remember params in func(left subtree)
    toAdd->task = functionToAdd->rightChild;     // to remember cal in func(right subtree)

    definedFunctions[++definedFunctionsTop] = toAdd;
}

struct Function* getFunction(char* functionName) {
    for(int i = 0; i <= definedFunctionsTop; i++) {
        if(strcmp(definedFunctions[i]->functionName, functionName) == 0) {
            struct Function* result = (struct Function *) malloc(sizeof(struct Function));

            result->functionName = strdup(definedFunctions[i]->functionName);
            result->params = cloneAST(definedFunctions[i]->params);
            result->task = cloneAST(definedFunctions[i]->task);

            return result;
        }
    }

    return NULL;
}

void assignParamsNameAndBind(struct ASTNode* parametersName, struct ASTNode* parametersToAssign, struct ASTNode* functionTask) {
    /* sleep(1); */
    switch(parametersName->val->type) {
        case no_type:
            return;
        case string:
            parametersToAssign->val->name = parametersName->val->name;
            

            bindParams(functionTask, cloneAST(parametersToAssign));

            break;
        case function_parameters:
            parametersToAssign->leftChild->val->name = parametersName->leftChild->val->name;
            

            bindParams(functionTask, cloneAST(parametersToAssign->leftChild));

            assignParamsNameAndBind(parametersName->rightChild, parametersToAssign->rightChild, functionTask);  // 7-1 no use
            break;
    }
}

void bindParams(struct ASTNode* taskNode, struct ASTNode* toReplace) {
    if(taskNode == NULL || taskNode->val->type == define_function) {
        return;
    }

    if(taskNode->val->type == string && toReplace->val->type == function) {

        taskNode->val->type = toReplace->val->type;

        taskNode->val->intVal = toReplace->val->intVal;
        taskNode->val->boolVal = toReplace->val->boolVal;

        taskNode->leftChild = cloneAST(toReplace->leftChild);
        taskNode->rightChild = cloneAST(toReplace->rightChild);


        return;
    } else if(taskNode->val->type == get_variable) {
        if(strcmp(taskNode->val->name, toReplace->val->name) == 0) {


            taskNode->val->type = toReplace->val->type;

            taskNode->val->intVal = toReplace->val->intVal;
            taskNode->val->boolVal = toReplace->val->boolVal;

            taskNode->leftChild = cloneAST(toReplace->leftChild);
            taskNode->rightChild = cloneAST(toReplace->rightChild);


            return;
        }
    }

    bindParams(taskNode->leftChild, toReplace);
    bindParams(taskNode->rightChild, toReplace);
}

char* getTypeName(int type) {
    if(type == integer) {
        return strdup("number");
    } else if(type == boolean) {
        return strdup("boolean");
    } else if(type == function) {
        return strdup("function");
    }
}

void typeChecking(struct ASTNode* node, int type) {
    if(node->val->type != type) {
        char errMsg[MAX];
        sprintf(errMsg, "Type Error");
        // sprintf(errMsg, "Type Error: Expecting '%s', but got '%s'.", getTypeName(type), getTypeName(node->val->type));

        yyerror(errMsg);
    }
}

struct ASTNode* freeNode(struct ASTNode* node) {
    if(node == NULL) {
        return NULL;
    }

    freeNode(node->leftChild);
    freeNode(node->rightChild);

    free(node);

    return NULL;
}

void traverse(struct ASTNode* node, int parent_type, bool insideFunction) {
    if(node == NULL) {
        return;
    }

    switch(node->val->type) {
        case no_type:
            traverse(node->leftChild, node->leftChild->val->type, insideFunction);
            traverse(node->rightChild, node->rightChild->val->type, insideFunction);
            
            break;
        case equals_to_parent:
            node->val->type = parent_type;
            traverse(node, node->val->type, insideFunction);

            break;
        case print_num:
            traverse(node->leftChild, node->leftChild->val->type, insideFunction);

            typeChecking(node->leftChild, integer);


            printf("%d\n", node->leftChild->val->intVal);

            break;
        case print_bool:
            traverse(node->leftChild, node->leftChild->val->type, insideFunction);

            typeChecking(node->leftChild, boolean);

            printf("%s\n", node->leftChild->val->boolVal ? "#t" : "#f");

            break;
        case add:
            traverse(node->leftChild, node->val->type, insideFunction);
            traverse(node->rightChild, node->val->type, insideFunction);

            typeChecking(node->leftChild, integer);
            typeChecking(node->rightChild, integer);

            node->val->type = integer;
            node->val->intVal = node->leftChild->val->intVal + node->rightChild->val->intVal;


            node->leftChild = freeNode(node->leftChild);
            node->rightChild = freeNode(node->rightChild);

            break;
        case sub:
            traverse(node->leftChild, node->val->type, insideFunction);
            traverse(node->rightChild, node->val->type, insideFunction);

            typeChecking(node->leftChild, integer);
            typeChecking(node->rightChild, integer);

            node->val->type = integer;
            node->val->intVal = node->leftChild->val->intVal - node->rightChild->val->intVal;


            node->leftChild = freeNode(node->leftChild);
            node->rightChild = freeNode(node->rightChild);
            
            break;
        case mul:
            traverse(node->leftChild, node->val->type, insideFunction);
            traverse(node->rightChild, node->val->type, insideFunction);

            typeChecking(node->leftChild, integer);
            typeChecking(node->rightChild, integer);

            node->val->type = integer;
            node->val->intVal = node->leftChild->val->intVal * node->rightChild->val->intVal;


            node->leftChild = freeNode(node->leftChild);
            node->rightChild = freeNode(node->rightChild);
            
            break;
        case div:
            traverse(node->leftChild, node->val->type, insideFunction);
            traverse(node->rightChild, node->val->type, insideFunction);

            typeChecking(node->leftChild, integer);
            typeChecking(node->rightChild, integer);

            node->val->type = integer;
            node->val->intVal = node->leftChild->val->intVal / node->rightChild->val->intVal;


            node->leftChild = freeNode(node->leftChild);
            node->rightChild = freeNode(node->rightChild);
            
            break;
        case mod:
            traverse(node->leftChild, node->val->type, insideFunction);
            traverse(node->rightChild, node->val->type, insideFunction);

            typeChecking(node->leftChild, integer);
            typeChecking(node->rightChild, integer);

            node->val->type = integer;
            node->val->intVal = node->leftChild->val->intVal % node->rightChild->val->intVal;


            node->leftChild = freeNode(node->leftChild);
            node->rightChild = freeNode(node->rightChild);
            
            break;
        case bigger_than:
            traverse(node->leftChild, node->val->type, insideFunction);
            traverse(node->rightChild, node->val->type, insideFunction);

            typeChecking(node->leftChild, integer);
            typeChecking(node->rightChild, integer);

            node->val->type = boolean;
            node->val->boolVal = node->leftChild->val->intVal > node->rightChild->val->intVal ? true : false;

            node->leftChild = freeNode(node->leftChild);
            node->rightChild = freeNode(node->rightChild);
                       
            break;
        case smaller_than:
            traverse(node->leftChild, node->val->type, insideFunction);
            traverse(node->rightChild, node->val->type, insideFunction);

            typeChecking(node->leftChild, integer);
            typeChecking(node->rightChild, integer);

            node->val->type = boolean;
            node->val->boolVal = node->leftChild->val->intVal < node->rightChild->val->intVal ? true : false;
            

            node->leftChild = freeNode(node->leftChild);
            node->rightChild = freeNode(node->rightChild);
            
            break;
        case equal:
            if(node->rightChild->val->type != equal || node->rightChild->val->type != equals_to_parent) {
                traverse(node->rightChild, node->val->type, insideFunction);
                typeChecking(node->rightChild, integer);

                node->rightChild->val->boolVal = 1;
            }

            traverse(node->leftChild, node->val->type, insideFunction);
            traverse(node->rightChild, node->val->type, insideFunction);

            typeChecking(node->leftChild, integer);
            if(node->rightChild->val->type != boolean) {
                typeChecking(node->rightChild, integer);
            }
            
            node->val->type = boolean;
            node->val->intVal = node->leftChild->val->intVal;
            node->val->boolVal = (node->leftChild->val->intVal == node->rightChild->val->intVal)*node->rightChild->val->boolVal ? true : false;

            node->leftChild = freeNode(node->leftChild);
            node->rightChild = freeNode(node->rightChild);
            
            break;
        case and:
            traverse(node->leftChild, node->val->type, insideFunction);
            traverse(node->rightChild, node->val->type, insideFunction);

            typeChecking(node->leftChild, boolean);
            typeChecking(node->rightChild, boolean);
            
            node->val->type = boolean;
            node->val->boolVal = node->leftChild->val->boolVal && node->rightChild->val->boolVal;


            node->leftChild = freeNode(node->leftChild);
            node->rightChild = freeNode(node->rightChild);
            
            break;
        case or:
            traverse(node->leftChild, node->val->type, insideFunction);
            traverse(node->rightChild, node->val->type, insideFunction);

            typeChecking(node->leftChild, boolean);
            typeChecking(node->rightChild, boolean);

            node->val->type = boolean;
            node->val->boolVal = node->leftChild->val->boolVal || node->rightChild->val->boolVal;


            node->leftChild = freeNode(node->leftChild);
            node->rightChild = freeNode(node->rightChild);
            
            break;
        case not:
            traverse(node->leftChild, node->val->type, insideFunction);

            typeChecking(node->leftChild, boolean);

            node->val->type = boolean;
            node->val->boolVal = !node->leftChild->val->boolVal;
            

            node->leftChild = freeNode(node->leftChild);
            
            break;
        case define_variable:
            node->rightChild->val->name = node->leftChild->val->name;
            addDefinedVariable(node->rightChild);

            break;
        case get_variable: {
            /* If we use variable declartion in a case, we must use curly brackets {} in that case. */
            if(!insideFunction) {
                struct ASTNode* result = getDefinedVariable(node->val->name);

                node->val->type = result->val->type;

                node->val->intVal = result->val->intVal;
                node->val->boolVal = result->val->boolVal;

                node->leftChild = cloneAST(result->leftChild);
                node->rightChild = cloneAST(result->rightChild);
                
                traverse(node, node->val->type, insideFunction);

            }
            break;
        }
        case define_function:
            addFunction(node->leftChild->val->name, node->rightChild);

            break;
        case define_inside_function:
            traverse(node->leftChild, node->val->type, insideFunction);
            traverse(node->rightChild, node->val->type, insideFunction);

            node->val->type = node->rightChild->val->type;

            node->val->intVal = node->rightChild->val->intVal;
            node->val->boolVal = node->rightChild->val->boolVal;

            break;
        case call_function:
            if(node->leftChild->val->type == function) {  // define_func
                assignParamsNameAndBind(node->leftChild->leftChild, node->rightChild, node->leftChild->rightChild);

                traverse(node->leftChild->rightChild, node->leftChild->val->type, true);

                node->val->type = node->leftChild->rightChild->val->type;

                node->val->intVal = node->leftChild->rightChild->val->intVal;
                node->val->boolVal = node->leftChild->rightChild->val->boolVal;

                struct ASTNode* temp = cloneAST(node->leftChild);
                node->leftChild = cloneAST(node->leftChild->rightChild->leftChild);
                node->rightChild = cloneAST(temp->rightChild->rightChild);
            } else if(node->leftChild->val->type == string) {    // func_name : strng come from ID, later call
                struct Function* functionToCall = getFunction(node->leftChild->val->name);

                if(functionToCall != NULL) {
                    assignParamsNameAndBind(functionToCall->params, node->rightChild, functionToCall->task);

                    traverse(functionToCall->task, functionToCall->task->val->type, true);

                    node->val->type = functionToCall->task->val->type;

                    node->val->intVal = functionToCall->task->val->intVal;
                    node->val->boolVal = functionToCall->task->val->boolVal;

                    node->leftChild = cloneAST(functionToCall->task->leftChild);
                    node->rightChild = cloneAST(functionToCall->task->rightChild);
                } else {
                    struct ASTNode* result = getDefinedVariable(node->leftChild->val->name);

                    node->leftChild->val->type = result->val->type;
                    /* node->leftChild->val->type == call_function */

                    node->leftChild->val->intVal = result->val->intVal;
                    node->leftChild->val->boolVal = result->val->boolVal;

                    node->leftChild->leftChild = cloneAST(result->leftChild);
                    node->leftChild->rightChild = cloneAST(result->rightChild);

                    traverse(node->leftChild, node->leftChild->val->type, true);
                    /* node->leftChild->val->type == function */

                    traverse(node, node->val->type, true);
                }
            }

            break;
        case if_else:
            traverse(node->leftChild, node->val->type, insideFunction);

            if(node->leftChild->val->boolVal) {
                traverse(node->rightChild->leftChild, node->rightChild->leftChild->val->type, insideFunction);

                node->val->type = node->rightChild->leftChild->val->type;
                
                node->val->intVal = node->rightChild->leftChild->val->intVal;
                node->val->boolVal = node->rightChild->leftChild->val->boolVal;
            } else {
                traverse(node->rightChild->rightChild, node->rightChild->rightChild->val->type, insideFunction);

                node->val->type = node->rightChild->rightChild->val->type;
                
                node->val->intVal = node->rightChild->rightChild->val->intVal;
                node->val->boolVal = node->rightChild->rightChild->val->boolVal;
            }

            break;

    }
}

void yyerror(const char *message) {
    fprintf(stderr, "%s\n", message);

    exit(0);
}

void init() {
    definedVariablesTop = -1;
    definedFunctionsTop = -1;

    root = emptyNode();
}

int main() {
    init();

    yyparse();

    traverse(root, root->val->type, false);

    return 0;
}