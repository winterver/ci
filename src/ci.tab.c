/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "src\\ci.y"


#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char* error, ...);

struct astnode;
struct astnode* root;
struct astnode* mknode(char* value,
                       struct astnode* inner,
                       struct astnode* next);
struct astnode* backof(struct astnode* node);


#line 88 "src\\ci.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "ci.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_CONSTANT = 5,                   /* CONSTANT  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_SHORT = 8,                      /* SHORT  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_LONG = 10,                      /* LONG  */
  YYSYMBOL_FLOAT = 11,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 12,                    /* DOUBLE  */
  YYSYMBOL_ENUM = 13,                      /* ENUM  */
  YYSYMBOL_STRUCT = 14,                    /* STRUCT  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_CONTINUE = 20,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 21,                     /* BREAK  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_SIZEOF = 23,                    /* SIZEOF  */
  YYSYMBOL_ADDA = 24,                      /* ADDA  */
  YYSYMBOL_SUBA = 25,                      /* SUBA  */
  YYSYMBOL_MULA = 26,                      /* MULA  */
  YYSYMBOL_DIVA = 27,                      /* DIVA  */
  YYSYMBOL_MODA = 28,                      /* MODA  */
  YYSYMBOL_ANDA = 29,                      /* ANDA  */
  YYSYMBOL_ORA = 30,                       /* ORA  */
  YYSYMBOL_XORA = 31,                      /* XORA  */
  YYSYMBOL_LE = 32,                        /* LE  */
  YYSYMBOL_GE = 33,                        /* GE  */
  YYSYMBOL_EQ = 34,                        /* EQ  */
  YYSYMBOL_NE = 35,                        /* NE  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_SHL = 38,                       /* SHL  */
  YYSYMBOL_SHR = 39,                       /* SHR  */
  YYSYMBOL_SHLA = 40,                      /* SHLA  */
  YYSYMBOL_SHRA = 41,                      /* SHRA  */
  YYSYMBOL_INC = 42,                       /* INC  */
  YYSYMBOL_DEC = 43,                       /* DEC  */
  YYSYMBOL_ELLIPSIS = 44,                  /* ELLIPSIS  */
  YYSYMBOL_UNCLOSED_BLOCK_COMMENT = 45,    /* UNCLOSED_BLOCK_COMMENT  */
  YYSYMBOL_UNKNOWN_CHARACTER = 46,         /* UNKNOWN_CHARACTER  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* '='  */
  YYSYMBOL_50_ = 50,                       /* '*'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* '['  */
  YYSYMBOL_54_ = 54,                       /* ']'  */
  YYSYMBOL_55_ = 55,                       /* '&'  */
  YYSYMBOL_56_ = 56,                       /* '+'  */
  YYSYMBOL_57_ = 57,                       /* '-'  */
  YYSYMBOL_58_ = 58,                       /* '~'  */
  YYSYMBOL_59_ = 59,                       /* '!'  */
  YYSYMBOL_60_ = 60,                       /* '/'  */
  YYSYMBOL_61_ = 61,                       /* '%'  */
  YYSYMBOL_62_ = 62,                       /* '<'  */
  YYSYMBOL_63_ = 63,                       /* '>'  */
  YYSYMBOL_64_ = 64,                       /* '^'  */
  YYSYMBOL_65_ = 65,                       /* '|'  */
  YYSYMBOL_66_ = 66,                       /* '?'  */
  YYSYMBOL_67_ = 67,                       /* ':'  */
  YYSYMBOL_68_ = 68,                       /* '{'  */
  YYSYMBOL_69_ = 69,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_start = 71,                     /* start  */
  YYSYMBOL_translation_unit = 72,          /* translation_unit  */
  YYSYMBOL_external_declaration = 73,      /* external_declaration  */
  YYSYMBOL_declaration = 74,               /* declaration  */
  YYSYMBOL_type_specifier = 75,            /* type_specifier  */
  YYSYMBOL_init_declarator_list = 76,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 77,           /* init_declarator  */
  YYSYMBOL_declarator = 78,                /* declarator  */
  YYSYMBOL_pointer = 79,                   /* pointer  */
  YYSYMBOL_function = 80,                  /* function  */
  YYSYMBOL_parameter_list = 81,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 82,     /* parameter_declaration  */
  YYSYMBOL_primary_expression = 83,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 84,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 85,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 86,          /* unary_expression  */
  YYSYMBOL_unary_operator = 87,            /* unary_operator  */
  YYSYMBOL_type_name = 88,                 /* type_name  */
  YYSYMBOL_cast_expression = 89,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 90, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 91,       /* additive_expression  */
  YYSYMBOL_shift_expression = 92,          /* shift_expression  */
  YYSYMBOL_relational_expression = 93,     /* relational_expression  */
  YYSYMBOL_equality_expression = 94,       /* equality_expression  */
  YYSYMBOL_and_expression = 95,            /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 96,   /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 97,   /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 98,    /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 99,     /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 100,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 101,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 102,      /* assignment_operator  */
  YYSYMBOL_expression = 103,               /* expression  */
  YYSYMBOL_statement = 104,                /* statement  */
  YYSYMBOL_compound_statement = 105,       /* compound_statement  */
  YYSYMBOL_block_item_list = 106,          /* block_item_list  */
  YYSYMBOL_block_item = 107,               /* block_item  */
  YYSYMBOL_expression_statement = 108,     /* expression_statement  */
  YYSYMBOL_selection_statement = 109,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 110,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 111            /* jump_statement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   548

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  216

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,     2,     2,    61,    55,     2,
      51,    52,    50,    56,    48,    57,     2,    60,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    47,
      62,    49,    63,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    65,    69,    58,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    55,    59,    61,    66,    67,    71,    73,
      81,    82,    83,    84,    85,    86,    87,    91,    93,    98,
     100,   108,   114,   125,   126,   130,   136,   142,   152,   154,
     159,   167,   168,   169,   170,   174,   175,   176,   177,   178,
     179,   183,   184,   188,   189,   190,   191,   192,   193,   197,
     198,   199,   200,   201,   202,   206,   207,   211,   212,   216,
     217,   218,   219,   223,   224,   225,   229,   230,   231,   235,
     236,   237,   238,   239,   243,   244,   245,   249,   250,   254,
     255,   259,   260,   264,   265,   269,   270,   274,   275,   279,
     280,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   298,   303,   304,   305,   306,   307,   311,   313,
     318,   319,   324,   325,   329,   330,   334,   339,   348,   353,
     358,   364,   371,   377,   387,   388,   389,   390
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "STRING",
  "CONSTANT", "VOID", "CHAR", "SHORT", "INT", "LONG", "FLOAT", "DOUBLE",
  "ENUM", "STRUCT", "IF", "ELSE", "DO", "WHILE", "FOR", "CONTINUE",
  "BREAK", "RETURN", "SIZEOF", "ADDA", "SUBA", "MULA", "DIVA", "MODA",
  "ANDA", "ORA", "XORA", "LE", "GE", "EQ", "NE", "AND", "OR", "SHL", "SHR",
  "SHLA", "SHRA", "INC", "DEC", "ELLIPSIS", "UNCLOSED_BLOCK_COMMENT",
  "UNKNOWN_CHARACTER", "';'", "','", "'='", "'*'", "'('", "')'", "'['",
  "']'", "'&'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'{'", "'}'", "$accept", "start",
  "translation_unit", "external_declaration", "declaration",
  "type_specifier", "init_declarator_list", "init_declarator",
  "declarator", "pointer", "function", "parameter_list",
  "parameter_declaration", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "type_name", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "statement", "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     177,  -166,  -166,  -166,  -166,  -166,  -166,  -166,     8,   177,
    -166,  -166,    46,  -166,  -166,  -166,  -166,  -166,  -166,     4,
    -166,   -27,    12,  -166,    20,   447,    97,  -166,  -166,  -166,
     -39,  -166,  -166,  -166,   468,   489,   489,  -166,   326,  -166,
    -166,  -166,  -166,  -166,  -166,    -7,   194,   447,  -166,   -41,
      54,    74,   -21,    82,   -30,   -25,   -20,    11,   -34,  -166,
    -166,     9,    -4,    20,   -15,  -166,   326,  -166,   447,  -166,
    -166,    45,    49,  -166,    62,  -166,  -166,   336,   447,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
     447,  -166,  -166,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,    -4,   123,  -166,  -166,   177,    -4,    68,    75,
     447,  -166,  -166,   -14,  -166,    70,  -166,  -166,  -166,  -166,
     -41,   -41,    54,    54,    74,    74,    74,    74,   -21,   -21,
      82,   -30,   -25,   -20,    11,     7,  -166,    85,   247,    99,
     102,   101,   107,   357,  -166,  -166,  -166,    46,   108,  -166,
    -166,   190,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,   447,  -166,  -166,   447,   447,   140,   447,   269,  -166,
    -166,  -166,   114,  -166,  -166,  -166,  -166,  -166,   110,   112,
     115,   398,   398,  -166,   247,   447,   247,   367,   424,   148,
     116,  -166,   247,   117,   247,   119,   247,   125,  -166,   247,
    -166,   247,  -166,  -166,  -166,  -166
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    10,    11,    12,    13,    14,    15,    16,     0,     3,
       4,     6,     0,     7,     1,     5,    21,     8,    23,     0,
      17,    19,     0,     9,     0,     0,     0,    22,    24,    18,
      19,    31,    32,    33,     0,     0,     0,    50,     0,    49,
      51,    52,    53,    54,    35,    43,    57,     0,    59,    63,
      66,    69,    74,    77,    79,    81,    83,    85,    87,    89,
      20,    10,     0,     0,     0,    28,     0,    47,     0,    44,
      45,    55,     0,   102,     0,    39,    40,     0,     0,    95,
      96,    92,    93,    94,    99,   101,   100,    97,    98,    91,
       0,    57,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    30,     0,     0,     0,    56,
       0,    34,    37,     0,    41,     0,    90,    60,    61,    62,
      64,    65,    67,    68,    72,    73,    70,    71,    75,    76,
      78,    80,    82,    84,    86,     0,    26,     0,     0,     0,
       0,     0,     0,     0,   114,   108,   112,     0,     0,   113,
     103,     0,   110,   104,   105,   106,   107,    29,    27,    48,
      58,     0,    38,    36,     0,     0,     0,     0,     0,   124,
     125,   126,     0,   115,   109,   111,    42,    88,     0,     0,
       0,     0,     0,   127,     0,     0,     0,     0,     0,   116,
       0,   118,     0,     0,     0,     0,     0,     0,   122,     0,
     120,     0,   117,   119,   123,   121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,   166,  -106,     5,  -166,   152,    -6,   106,
    -166,  -166,    87,  -166,  -166,  -166,   -18,  -166,   124,   -26,
      22,    24,    -3,    47,    98,   109,   118,   105,    96,  -166,
      41,   -24,  -166,   -38,  -146,   -58,  -166,    56,  -165,  -166,
    -166,  -166
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,   157,    19,    20,    30,    22,
      13,    64,    65,    44,    45,   123,    46,    47,    72,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    73,    90,   158,   159,   160,   161,   162,   163,   164,
     165,   166
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      74,    60,   176,   110,   114,    12,    21,   156,    14,    93,
      25,   100,   101,   192,    12,    27,    67,    69,    70,    94,
      95,    92,    25,    16,    26,   106,   197,   198,    74,    91,
      74,    63,   111,   116,   171,    75,    76,   117,   172,   107,
     125,   102,   103,    71,    77,   108,    78,   109,   199,    16,
     201,    23,    24,   124,   146,   156,   208,   115,   210,   168,
     212,   112,    28,   214,   113,   215,   126,   127,   128,   129,
      18,    71,   191,   145,   174,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    17,   170,    18,    18,   134,   135,   136,
     137,   120,    91,    61,     2,     3,     4,     5,     6,     7,
      96,    97,    98,    99,   121,   182,   104,   105,   130,   131,
     169,    63,   132,   133,   173,    28,    31,    32,    33,     1,
       2,     3,     4,     5,     6,     7,   175,   188,   147,   190,
     148,   149,   150,   151,   152,   153,    34,   186,   179,    62,
     177,   138,   139,   178,   180,   183,    91,   200,   189,   203,
     205,   193,   194,   195,   206,    35,    36,   196,   207,   209,
     154,   211,   213,    37,    38,    15,    29,   119,    39,    40,
      41,    42,    43,     1,     2,     3,     4,     5,     6,     7,
     118,   113,   155,    31,    32,    33,     1,     2,     3,     4,
       5,     6,     7,   167,   140,   147,   144,   148,   149,   150,
     151,   152,   153,    34,   143,   187,   141,   185,    79,    80,
      81,    82,    83,    84,    85,    86,   142,     0,     0,     0,
       0,     0,    35,    36,    87,    88,     0,   154,     0,     0,
      37,    38,     0,    89,     0,    39,    40,    41,    42,    43,
      31,    32,    33,     0,     0,     0,     0,     0,   113,   184,
       0,     0,   147,     0,   148,   149,   150,   151,   152,   153,
      34,     0,    31,    32,    33,     1,     2,     3,     4,     5,
       6,     7,     0,     0,     0,     0,     0,     0,     0,    35,
      36,     0,    34,     0,   154,     0,     0,    37,    38,     0,
       0,     0,    39,    40,    41,    42,    43,     0,     0,     0,
       0,    35,    36,     0,     0,   113,   154,     0,     0,    37,
      38,     0,     0,     0,    39,    40,    41,    42,    43,    31,
      32,    33,     1,     2,     3,     4,     5,     6,     7,    31,
      32,    33,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      31,    32,    33,     0,     0,     0,     0,     0,    35,    36,
      31,    32,    33,     0,     0,     0,    37,    38,    35,    36,
      34,    39,    40,    41,    42,    43,    37,    38,   122,     0,
      34,    39,    40,    41,    42,    43,     0,     0,     0,    35,
      36,    31,    32,    33,   181,     0,     0,    37,    38,    35,
      36,     0,    39,    40,    41,    42,    43,    37,    38,   202,
       0,    34,    39,    40,    41,    42,    43,    31,    32,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    36,     0,     0,     0,   154,     0,    34,    37,    38,
      31,    32,    33,    39,    40,    41,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    36,     0,     0,
      34,    31,    32,    33,    37,    38,   204,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,     0,     0,    35,
      36,    34,    31,    32,    33,     0,     0,    37,    38,     0,
       0,     0,    39,    40,    41,    42,    43,     0,     0,     0,
      35,    36,    34,     0,     0,     0,     0,     0,    37,    66,
       0,     0,     0,    39,    40,    41,    42,    43,     0,     0,
       0,    35,    36,     0,     0,     0,     0,     0,     0,    37,
      68,     0,     0,     0,    39,    40,    41,    42,    43
};

static const yytype_int16 yycheck[] =
{
      38,    25,   148,    37,    62,     0,    12,   113,     0,    50,
      49,    32,    33,   178,     9,     3,    34,    35,    36,    60,
      61,    47,    49,     3,    51,    55,   191,   192,    66,    47,
      68,    26,    66,    48,    48,    42,    43,    52,    52,    64,
      78,    62,    63,    38,    51,    65,    53,    36,   194,     3,
     196,    47,    48,    77,   112,   161,   202,    63,   204,   117,
     206,    52,    50,   209,    68,   211,    90,    93,    94,    95,
      50,    66,   178,   111,    67,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    47,   120,    50,    50,   100,   101,   102,
     103,    52,   120,     6,     7,     8,     9,    10,    11,    12,
      56,    57,    38,    39,    52,   153,    34,    35,    96,    97,
      52,   116,    98,    99,    54,    50,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    51,   175,    15,   177,
      17,    18,    19,    20,    21,    22,    23,   171,    47,    52,
      51,   104,   105,    51,    47,    47,   174,   195,    18,   197,
     198,    47,    52,    51,    16,    42,    43,    52,    52,    52,
      47,    52,    47,    50,    51,     9,    24,    71,    55,    56,
      57,    58,    59,     6,     7,     8,     9,    10,    11,    12,
      66,    68,    69,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   116,   106,    15,   110,    17,    18,    19,
      20,    21,    22,    23,   109,   174,   107,   161,    24,    25,
      26,    27,    28,    29,    30,    31,   108,    -1,    -1,    -1,
      -1,    -1,    42,    43,    40,    41,    -1,    47,    -1,    -1,
      50,    51,    -1,    49,    -1,    55,    56,    57,    58,    59,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    68,    69,
      -1,    -1,    15,    -1,    17,    18,    19,    20,    21,    22,
      23,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    23,    -1,    47,    -1,    -1,    50,    51,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    68,    47,    -1,    -1,    50,
      51,    -1,    -1,    -1,    55,    56,    57,    58,    59,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    42,    43,
       3,     4,     5,    -1,    -1,    -1,    50,    51,    42,    43,
      23,    55,    56,    57,    58,    59,    50,    51,    52,    -1,
      23,    55,    56,    57,    58,    59,    -1,    -1,    -1,    42,
      43,     3,     4,     5,    47,    -1,    -1,    50,    51,    42,
      43,    -1,    55,    56,    57,    58,    59,    50,    51,    52,
      -1,    23,    55,    56,    57,    58,    59,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    47,    -1,    23,    50,    51,
       3,     4,     5,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      23,     3,     4,     5,    50,    51,    52,    -1,    -1,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    42,
      43,    23,     3,     4,     5,    -1,    -1,    50,    51,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      42,    43,    23,    -1,    -1,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    55,    56,    57,    58,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    11,    12,    71,    72,
      73,    74,    75,    80,     0,    73,     3,    47,    50,    76,
      77,    78,    79,    47,    48,    49,    51,     3,    50,    77,
      78,     3,     4,     5,    23,    42,    43,    50,    51,    55,
      56,    57,    58,    59,    83,    84,    86,    87,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,     6,    52,    75,    81,    82,    51,    86,    51,    86,
      86,    75,    88,   101,   103,    42,    43,    51,    53,    24,
      25,    26,    27,    28,    29,    30,    31,    40,    41,    49,
     102,    86,    89,    50,    60,    61,    56,    57,    38,    39,
      32,    33,    62,    63,    34,    35,    55,    64,    65,    36,
      37,    66,    52,    68,   105,    78,    48,    52,    88,    79,
      52,    52,    52,    85,   101,   103,   101,    89,    89,    89,
      90,    90,    91,    91,    92,    92,    92,    92,    93,    93,
      94,    95,    96,    97,    98,   103,   105,    15,    17,    18,
      19,    20,    21,    22,    47,    69,    74,    75,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    82,   105,    52,
      89,    48,    52,    54,    67,    51,   104,    51,    51,    47,
      47,    47,   103,    47,    69,   107,   101,   100,   103,    18,
     103,    74,   108,    47,    52,    51,    52,   108,   108,   104,
     103,   104,    52,   103,    52,   103,    16,    52,   104,    52,
     104,    52,   104,    47,   104,   104
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    80,    81,    81,
      82,    83,    83,    83,    83,    84,    84,    84,    84,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    87,
      87,    87,    87,    87,    87,    88,    88,    89,    89,    90,
      90,    90,    90,    91,    91,    91,    92,    92,    92,    93,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   104,   104,   104,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   111,   111,   111,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     2,     1,     2,     5,     6,     6,     1,     3,
       2,     1,     1,     1,     3,     1,     4,     3,     4,     2,
       2,     1,     3,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     2,     1,     1,     1,     2,     5,     7,     5,     7,
       6,     7,     6,     7,     2,     2,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* start: %empty  */
#line 54 "src\\ci.y"
                        { root = NULL; }
#line 1413 "src\\ci.tab.c"
    break;

  case 3: /* start: translation_unit  */
#line 55 "src\\ci.y"
                        { root = (yyvsp[0].node); }
#line 1419 "src\\ci.tab.c"
    break;

  case 4: /* translation_unit: external_declaration  */
#line 60 "src\\ci.y"
        { (yyval.node) = mknode("translation_unit", (yyvsp[0].node), NULL); }
#line 1425 "src\\ci.tab.c"
    break;

  case 5: /* translation_unit: translation_unit external_declaration  */
#line 62 "src\\ci.y"
        { backof((yyvsp[-1].node)->inner)->next = (yyvsp[0].node); }
#line 1431 "src\\ci.tab.c"
    break;

  case 8: /* declaration: type_specifier ';'  */
#line 72 "src\\ci.y"
        { (yyval.node) = mknode("declaration", (yyvsp[-1].node), NULL); }
#line 1437 "src\\ci.tab.c"
    break;

  case 9: /* declaration: type_specifier init_declarator_list ';'  */
#line 74 "src\\ci.y"
        {
            (yyvsp[-2].node)->next = (yyvsp[-1].node);
            (yyval.node) = mknode("declaration", (yyvsp[-2].node), NULL);
        }
#line 1446 "src\\ci.tab.c"
    break;

  case 10: /* type_specifier: VOID  */
#line 81 "src\\ci.y"
                    { (yyval.node) = mknode("type_specifier", mknode("void", NULL, NULL), NULL); }
#line 1452 "src\\ci.tab.c"
    break;

  case 11: /* type_specifier: CHAR  */
#line 82 "src\\ci.y"
                    { (yyval.node) = mknode("type_specifier", mknode("char", NULL, NULL), NULL); }
#line 1458 "src\\ci.tab.c"
    break;

  case 12: /* type_specifier: SHORT  */
#line 83 "src\\ci.y"
                    { (yyval.node) = mknode("type_specifier", mknode("short", NULL, NULL), NULL); }
#line 1464 "src\\ci.tab.c"
    break;

  case 13: /* type_specifier: INT  */
#line 84 "src\\ci.y"
                    { (yyval.node) = mknode("type_specifier", mknode("int", NULL, NULL), NULL); }
#line 1470 "src\\ci.tab.c"
    break;

  case 14: /* type_specifier: LONG  */
#line 85 "src\\ci.y"
                    { (yyval.node) = mknode("type_specifier", mknode("long", NULL, NULL), NULL); }
#line 1476 "src\\ci.tab.c"
    break;

  case 15: /* type_specifier: FLOAT  */
#line 86 "src\\ci.y"
                    { (yyval.node) = mknode("type_specifier", mknode("float", NULL, NULL), NULL); }
#line 1482 "src\\ci.tab.c"
    break;

  case 16: /* type_specifier: DOUBLE  */
#line 87 "src\\ci.y"
                    { (yyval.node) = mknode("type_specifier", mknode("double", NULL, NULL), NULL); }
#line 1488 "src\\ci.tab.c"
    break;

  case 17: /* init_declarator_list: init_declarator  */
#line 92 "src\\ci.y"
        { (yyval.node) = mknode("init_declarator_list", (yyvsp[0].node), NULL); }
#line 1494 "src\\ci.tab.c"
    break;

  case 18: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 94 "src\\ci.y"
        { backof((yyvsp[-2].node)->inner)->next = (yyvsp[0].node); }
#line 1500 "src\\ci.tab.c"
    break;

  case 19: /* init_declarator: declarator  */
#line 99 "src\\ci.y"
        { (yyval.node) = mknode("init_declarator", (yyvsp[0].node), NULL); }
#line 1506 "src\\ci.tab.c"
    break;

  case 20: /* init_declarator: declarator '=' assignment_expression  */
#line 101 "src\\ci.y"
        {
            (yyvsp[-2].node)->next = mknode("initializer", NULL, NULL);
            (yyval.node) = mknode("init_declarator", (yyvsp[-2].node), NULL);
        }
#line 1515 "src\\ci.tab.c"
    break;

  case 21: /* declarator: IDENTIFIER  */
#line 109 "src\\ci.y"
        {
            struct astnode* value = mknode((yyvsp[0].string), NULL, NULL);
            struct astnode* identifier = mknode("IDENTIFIER", value, NULL);
            (yyval.node) = mknode("declarator", identifier, NULL);
        }
#line 1525 "src\\ci.tab.c"
    break;

  case 22: /* declarator: pointer IDENTIFIER  */
#line 115 "src\\ci.y"
        {
            struct astnode* value = mknode((yyvsp[0].string), NULL, NULL);
            struct astnode* identifier = mknode("IDENTIFIER", value, NULL);
            backof((yyvsp[-1].node))->next = identifier;
            (yyval.node) = mknode("declarator", (yyvsp[-1].node), NULL);
        }
#line 1536 "src\\ci.tab.c"
    break;

  case 23: /* pointer: '*'  */
#line 125 "src\\ci.y"
                        { (yyval.node) = mknode("pointer", NULL, NULL); }
#line 1542 "src\\ci.tab.c"
    break;

  case 24: /* pointer: pointer '*'  */
#line 126 "src\\ci.y"
                        { (yyval.node) = mknode("pointer", NULL, (yyvsp[-1].node)); }
#line 1548 "src\\ci.tab.c"
    break;

  case 25: /* function: type_specifier declarator '(' ')' compound_statement  */
#line 131 "src\\ci.y"
        {
            (yyvsp[-3].node)->next = mknode("parameter_list", NULL, (yyvsp[0].node));
            (yyvsp[-4].node)->next = (yyvsp[-3].node);
            (yyval.node) = mknode("function", (yyvsp[-4].node), NULL);
        }
#line 1558 "src\\ci.tab.c"
    break;

  case 26: /* function: type_specifier declarator '(' VOID ')' compound_statement  */
#line 137 "src\\ci.y"
        {
            (yyvsp[-4].node)->next = mknode("parameter_list", NULL, (yyvsp[0].node));
            (yyvsp[-5].node)->next = (yyvsp[-4].node);
            (yyval.node) = mknode("function", (yyvsp[-5].node), NULL);
        }
#line 1568 "src\\ci.tab.c"
    break;

  case 27: /* function: type_specifier declarator '(' parameter_list ')' compound_statement  */
#line 143 "src\\ci.y"
        {
            (yyvsp[-2].node)->next = (yyvsp[0].node);
            (yyvsp[-4].node)->next = (yyvsp[-2].node);
            (yyvsp[-5].node)->next = (yyvsp[-4].node);
            (yyval.node) = mknode("function", (yyvsp[-5].node), NULL);
        }
#line 1579 "src\\ci.tab.c"
    break;

  case 28: /* parameter_list: parameter_declaration  */
#line 153 "src\\ci.y"
        { (yyval.node) = mknode("paramter_list", (yyvsp[0].node), NULL); }
#line 1585 "src\\ci.tab.c"
    break;

  case 29: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 155 "src\\ci.y"
        { backof((yyvsp[-2].node)->inner)->next = (yyvsp[0].node); }
#line 1591 "src\\ci.tab.c"
    break;

  case 30: /* parameter_declaration: type_specifier declarator  */
#line 160 "src\\ci.y"
        {
            (yyvsp[-1].node)->next = (yyvsp[0].node);
            (yyval.node) = mknode("parameter_declaration", (yyvsp[-1].node), NULL);
        }
#line 1600 "src\\ci.tab.c"
    break;

  case 102: /* expression: assignment_expression  */
#line 299 "src\\ci.y"
        { (yyval.node) = mknode("expression", NULL, NULL); }
#line 1606 "src\\ci.tab.c"
    break;

  case 108: /* compound_statement: '{' '}'  */
#line 312 "src\\ci.y"
        { (yyval.node) = mknode("compound_statement", NULL, NULL); }
#line 1612 "src\\ci.tab.c"
    break;

  case 109: /* compound_statement: '{' block_item_list '}'  */
#line 314 "src\\ci.y"
        { (yyval.node) = mknode("compound_statement", (yyvsp[-1].node), NULL); }
#line 1618 "src\\ci.tab.c"
    break;

  case 111: /* block_item_list: block_item_list block_item  */
#line 320 "src\\ci.y"
        { backof((yyvsp[-1].node))->next = (yyvsp[0].node); }
#line 1624 "src\\ci.tab.c"
    break;

  case 114: /* expression_statement: ';'  */
#line 329 "src\\ci.y"
                            { /* TODO */ }
#line 1630 "src\\ci.tab.c"
    break;

  case 116: /* selection_statement: IF '(' expression ')' statement  */
#line 335 "src\\ci.y"
        {
            (yyvsp[-2].node)->next = (yyvsp[0].node);
            (yyval.node) = mknode("if", (yyvsp[-2].node), NULL);
        }
#line 1639 "src\\ci.tab.c"
    break;

  case 117: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 340 "src\\ci.y"
        {
            (yyvsp[-2].node)->next = (yyvsp[0].node);
            (yyvsp[-4].node)->next = (yyvsp[-2].node);
            (yyval.node) = mknode("if", (yyvsp[-4].node), NULL);
        }
#line 1649 "src\\ci.tab.c"
    break;

  case 118: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 349 "src\\ci.y"
        {
            (yyvsp[-2].node)->next = (yyvsp[0].node);
            (yyval.node) = mknode("while", (yyvsp[-2].node), NULL);
        }
#line 1658 "src\\ci.tab.c"
    break;

  case 119: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 354 "src\\ci.y"
        {
            (yyvsp[-5].node)->next = (yyvsp[-2].node);
            (yyval.node) = mknode("do_while", (yyvsp[-5].node), NULL);
        }
#line 1667 "src\\ci.tab.c"
    break;

  case 120: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 359 "src\\ci.y"
        {
            struct astnode* cond = mknode("condition", (yyvsp[-2].node), (yyvsp[0].node));
            struct astnode* init = mknode("initial", (yyvsp[-3].node), cond);
            (yyval.node) = mknode("for", init, NULL);
        }
#line 1677 "src\\ci.tab.c"
    break;

  case 121: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 365 "src\\ci.y"
        {
            struct astnode* iter = mknode("iteration", (yyvsp[-2].node), (yyvsp[0].node));
            struct astnode* cond = mknode("condition", (yyvsp[-3].node), iter);
            struct astnode* init = mknode("initial", (yyvsp[-4].node), cond);
            (yyval.node) = mknode("for", init, NULL);
        }
#line 1688 "src\\ci.tab.c"
    break;

  case 122: /* iteration_statement: FOR '(' declaration expression_statement ')' statement  */
#line 372 "src\\ci.y"
        {
            struct astnode* cond = mknode("condition", (yyvsp[-2].node), (yyvsp[0].node));
            struct astnode* init = mknode("initial", (yyvsp[-3].node), cond);
            (yyval.node) = mknode("for", init, NULL);
        }
#line 1698 "src\\ci.tab.c"
    break;

  case 123: /* iteration_statement: FOR '(' declaration expression_statement expression ')' statement  */
#line 378 "src\\ci.y"
        {
            struct astnode* iter = mknode("iteration", (yyvsp[-2].node), (yyvsp[0].node));
            struct astnode* cond = mknode("condition", (yyvsp[-3].node), iter);
            struct astnode* init = mknode("initial", (yyvsp[-4].node), cond);
            (yyval.node) = mknode("for", init, NULL);
        }
#line 1709 "src\\ci.tab.c"
    break;

  case 124: /* jump_statement: CONTINUE ';'  */
#line 387 "src\\ci.y"
                                    { (yyval.node) = mknode("continue", NULL, NULL); }
#line 1715 "src\\ci.tab.c"
    break;

  case 125: /* jump_statement: BREAK ';'  */
#line 388 "src\\ci.y"
                                    { (yyval.node) = mknode("break", NULL, NULL); }
#line 1721 "src\\ci.tab.c"
    break;

  case 126: /* jump_statement: RETURN ';'  */
#line 389 "src\\ci.y"
                                    { (yyval.node) = mknode("return", NULL, NULL); }
#line 1727 "src\\ci.tab.c"
    break;

  case 127: /* jump_statement: RETURN expression ';'  */
#line 390 "src\\ci.y"
                                    { (yyval.node) = mknode("return", (yyvsp[-1].node), NULL); }
#line 1733 "src\\ci.tab.c"
    break;


#line 1737 "src\\ci.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 393 "src\\ci.y"


struct astnode* mknode(char* value,
                       struct astnode* inner,
                       struct astnode* next)
{
    struct astnode* an = malloc(sizeof(struct astnode));
    an->value = value;
    an->inner = inner;
    an->next = next;
    return an;
}


struct astnode* backof(struct astnode* node)
{
    if (node == NULL || node->next == NULL)
    {
        return node;
    }
    return backof(node->next);
}

void print_astnode(struct astnode* node)
{
    static int indent = 0;
    if (node == NULL)
    {
        indent--;
        return;
    }
    for (int i = 0; i < indent; i++)
    {
        putchar(' ');
    }

    puts(node->value);
    indent++;
    print_astnode(node->inner);
    print_astnode(node->next);
}

int main()
{
    yyparse();
    print_astnode(root);
    return 0;
}
