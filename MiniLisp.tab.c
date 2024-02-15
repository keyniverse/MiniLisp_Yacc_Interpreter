/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "MiniLisp.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "MiniLisp.tab.h".  */
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
#line 1 "MiniLisp.y" /* yacc.c:355  */

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

#line 194 "MiniLisp.tab.c" /* yacc.c:355  */

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
#line 99 "MiniLisp.y" /* yacc.c:355  */

    struct ASTNode* NODE;

#line 232 "MiniLisp.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINILISP_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 247 "MiniLisp.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      22,    23,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   155,   155,   159,   162,   166,   169,   172,   177,   180,
     184,   187,   191,   194,   197,   200,   203,   206,   209,   212,
     217,   220,   223,   226,   229,   232,   235,   238,   242,   245,
     248,   252,   261,   265,   269,   272,   277,   281,   284,   288,
     291,   295,   298,   302,   306,   311,   315,   319
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "BOOL", "PRINT_NUM",
  "PRINT_BOOL", "ADD", "SUB", "MUL", "DIV", "MOD", "BIGGER_THAN",
  "SMALLER_THAN", "EQUAL", "AND", "OR", "NOT", "DEFINE", "FUNCTION", "IF",
  "'('", "')'", "$accept", "program", "stmts", "stmt", "print_stmt",
  "exps", "exp", "num_op", "logical_op", "def_stmt", "variable",
  "function_exp", "ids", "function_ids", "function_body", "function_call",
  "parameters", "function_name", "if_exp", "test_exp", "then_exp",
  "else_exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    40,    41
};
# endif

#define YYPACT_NINF -50

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      46,   -50,   -50,   -50,    78,     1,   -50,    46,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    -1,   -18,    56,   -15,    56,    56,   -50,   -50,   116,
     -14,   -12,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,   -11,    56,     4,    59,   -50,    56,    56,    -9,
      -8,   -50,   -50,    -7,    56,    -6,    15,    19,    21,    29,
      33,    42,    43,    44,   -50,    47,     4,    48,    97,   -50,
      59,    49,   -50,    56,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,    50,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    32,    12,     0,     0,     2,     4,     7,     5,
      15,    16,     6,    14,    17,    18,    19,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    42,     1,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,     0,    45,     0,    42,     0,
       0,     8,     9,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,    35,     0,     0,    38,
       0,     0,    46,     0,    41,    39,    40,    20,    10,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    31,    34,
      36,    37,    33,    47,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,     6,   -50,   -50,   -10,     0,   -50,   -50,   -49,
     -50,    -2,     3,   -50,    -5,   -50,   -26,   -50,   -50,   -50,
     -50,   -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    63,    64,    10,    11,    12,
      13,    14,    77,    55,    81,    15,    59,    36,    16,    57,
      83,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       9,    37,    35,    53,    54,    32,    80,     9,    76,    61,
      60,    62,    74,    38,    85,    86,    87,    89,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    80,    84,    56,    66,    58,    58,    35,    90,    71,
      72,    73,    91,    65,    92,    67,    68,    69,    70,     1,
       2,     3,    93,    75,    88,    79,    94,    82,    58,     1,
       2,     3,     1,     2,     3,    95,    96,    97,     4,     0,
      98,   100,   102,   105,     0,   101,    35,     0,    39,    99,
      79,    78,    17,   103,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    17,     0,     0,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      17,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    32,    33,    34
};

static const yytype_int8 yycheck[] =
{
       0,     0,     4,     4,    22,    20,    55,     7,     4,    23,
      36,    23,    23,     7,    23,    23,    23,    23,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    80,    58,    33,    44,    35,    36,    39,    23,    49,
      50,    51,    23,    43,    23,    45,    46,    47,    48,     3,
       4,     5,    23,    53,    64,    55,    23,    57,    58,     3,
       4,     5,     3,     4,     5,    23,    23,    23,    22,    -1,
      23,    23,    23,    23,    -1,    80,    78,    -1,    22,    76,
      80,    22,     4,    83,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     4,    -1,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       4,    -1,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    22,    25,    26,    27,    28,    30,
      31,    32,    33,    34,    35,    39,    42,     4,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    35,    41,     0,    26,    22,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,     4,    22,    37,    30,    43,    30,    40,
      40,    23,    23,    29,    30,    30,    29,    30,    30,    30,
      30,    29,    29,    29,    23,    30,     4,    36,    22,    30,
      33,    38,    30,    44,    40,    23,    23,    23,    29,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    36,
      23,    38,    23,    30,    45,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    25,    26,    26,    27,    27,    27,    28,    28,
      29,    29,    30,    30,    30,    30,    30,    30,    30,    30,
      31,    31,    31,    31,    31,    31,    31,    31,    32,    32,
      32,    33,    34,    35,    36,    36,    37,    38,    38,    39,
      39,    40,    40,    41,    42,    43,    44,    45
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       4,     5,     1,     5,     2,     0,     3,     2,     1,     4,
       4,     2,     0,     1,     6,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 155 "MiniLisp.y" /* yacc.c:1646  */
    {
                    root = (yyvsp[0].NODE);
                }
#line 1396 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 159 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(emptyDynamic(), (yyvsp[-1].NODE), (yyvsp[0].NODE));
                }
#line 1404 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 162 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1412 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 166 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1420 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 169 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1428 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 172 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1436 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 177 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(print_num, NULL, 0, false), (yyvsp[-1].NODE), NULL);
                }
#line 1444 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 180 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(print_bool, NULL, 0, false), (yyvsp[-1].NODE), NULL);
                }
#line 1452 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 184 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(equals_to_parent, NULL, 0, false), (yyvsp[-1].NODE), (yyvsp[0].NODE));
                }
#line 1460 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 187 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1468 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 191 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1476 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 194 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1484 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 197 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(get_variable, (yyvsp[0].NODE)->val->name, 0, false), NULL, NULL);
                }
#line 1492 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 200 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1500 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 203 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1508 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 206 "MiniLisp.y" /* yacc.c:1646  */
    {                    
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1516 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 209 "MiniLisp.y" /* yacc.c:1646  */
    {                    
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1524 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 212 "MiniLisp.y" /* yacc.c:1646  */
    {                    
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1532 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 217 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(add, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1540 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 220 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(sub, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1548 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 223 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(mul, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1556 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 226 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(div, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1564 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 229 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(mod, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1572 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 232 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(bigger_than, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1580 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 235 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(smaller_than, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1588 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 238 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(equal, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1596 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 242 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(and, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1604 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 245 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(or, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1612 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 248 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(not, NULL, 0, false), (yyvsp[-1].NODE), NULL);
                }
#line 1620 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 252 "MiniLisp.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-1].NODE)->val->type == function) {
                        (yyval.NODE) = newNode(newDynamic(define_function, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                    } else {
                        (yyval.NODE) = newNode(newDynamic(define_variable, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                    }
                }
#line 1632 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 261 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1640 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 265 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(function, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE)); 
                }
#line 1648 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 269 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(function_parameters, NULL, 0, false), (yyvsp[-1].NODE), (yyvsp[0].NODE));
                }
#line 1656 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 272 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = emptyNode();
                }
#line 1664 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 277 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[-1].NODE);
                }
#line 1672 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 281 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(define_inside_function, NULL, 0, false), (yyvsp[-1].NODE), (yyvsp[0].NODE));
                }
#line 1680 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 284 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1688 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 288 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(call_function, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1696 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 291 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(call_function, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                }
#line 1704 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 295 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = newNode(newDynamic(function_parameters, NULL, 0, false), (yyvsp[-1].NODE), (yyvsp[0].NODE));
                }
#line 1712 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 298 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = emptyNode();
                }
#line 1720 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 302 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1728 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 306 "MiniLisp.y" /* yacc.c:1646  */
    {
                    struct ASTNode* ifStatements = newNode(newDynamic(if_stmts, NULL, 0, false), (yyvsp[-2].NODE), (yyvsp[-1].NODE));
                    (yyval.NODE) = newNode(newDynamic(if_else, NULL, 0, false), (yyvsp[-3].NODE), ifStatements);
                }
#line 1737 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 311 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1745 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 315 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1753 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 319 "MiniLisp.y" /* yacc.c:1646  */
    {
                    (yyval.NODE) = (yyvsp[0].NODE);
                }
#line 1761 "MiniLisp.tab.c" /* yacc.c:1646  */
    break;


#line 1765 "MiniLisp.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 323 "MiniLisp.y" /* yacc.c:1906  */


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
