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
#line 1 "mondrian.y"

using namespace std;
#include <iostream>
#include "tablaSimbolos.h"
#include <cstring>
#include <typeinfo>



// Jesus Castaño Tato, Asier Serrano Martín			
extern int n_lineas;
extern   map<string, InformacionSimbolo> tablaSimbolos;
extern   map<string, InformacionSimbolo> tablaSimbolosLineas;
extern   map<string, InformacionSimbolo> tablaSimbolosRecuadros;
extern int yylex();

extern FILE* yyin ;
extern FILE* yyout ;

bool error = false;
void yyerror(const char* s){      
      // error = true;
      // if(strcmp(s,"syntax error") == 0){
      //       cout << "Error sintáctico en la instrucción " << n_lineas +1 <<endl;
            
      // }else{
      //       cout << "En la instrucción "<< n_lineas + 1<< " se ha dado un " << s <<endl;
      // }
      cout << "Error sintactico en la instruccion " << n_lineas+1 << endl;

} 

string impresionBool(bool a)
{
    return  (a==true) ? "True" : "False";
}   

string enteroOreal(bool enteroOreal)
{
      return (enteroOreal==true) ? "real" : "entero";
}

#line 114 "mondrian.c"

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

#include "mondrian.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PINTAR = 3,                     /* PINTAR  */
  YYSYMBOL_MENSAJE = 4,                    /* MENSAJE  */
  YYSYMBOL_PAUSA = 5,                      /* PAUSA  */
  YYSYMBOL_ASIGNACION = 6,                 /* ASIGNACION  */
  YYSYMBOL_IGUAL = 7,                      /* IGUAL  */
  YYSYMBOL_VARIABLES = 8,                  /* VARIABLES  */
  YYSYMBOL_RECUADROS = 9,                  /* RECUADROS  */
  YYSYMBOL_LINEAS = 10,                    /* LINEAS  */
  YYSYMBOL_DIV = 11,                       /* DIV  */
  YYSYMBOL_MENOS = 12,                     /* MENOS  */
  YYSYMBOL_SALTOLINEA = 13,                /* SALTOLINEA  */
  YYSYMBOL_PUNTOYCOMA = 14,                /* PUNTOYCOMA  */
  YYSYMBOL_COMA = 15,                      /* COMA  */
  YYSYMBOL_CUADRO = 16,                    /* CUADRO  */
  YYSYMBOL_FINCUADRO = 17,                 /* FINCUADRO  */
  YYSYMBOL_SI = 18,                        /* SI  */
  YYSYMBOL_SINO = 19,                      /* SINO  */
  YYSYMBOL_IDENTIFICADORMINUSCULA = 20,    /* IDENTIFICADORMINUSCULA  */
  YYSYMBOL_IDENTIFICADORMAYUSCULA = 21,    /* IDENTIFICADORMAYUSCULA  */
  YYSYMBOL_CADENA = 22,                    /* CADENA  */
  YYSYMBOL_TIPO = 23,                      /* TIPO  */
  YYSYMBOL_COLOR = 24,                     /* COLOR  */
  YYSYMBOL_ORIENTACION = 25,               /* ORIENTACION  */
  YYSYMBOL_ENTERO = 26,                    /* ENTERO  */
  YYSYMBOL_REAL = 27,                      /* REAL  */
  YYSYMBOL_BOOL = 28,                      /* BOOL  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_DISTINTO = 31,                  /* DISTINTO  */
  YYSYMBOL_MENOR = 32,                     /* MENOR  */
  YYSYMBOL_MENORIGUAL = 33,                /* MENORIGUAL  */
  YYSYMBOL_MAYORIGUAL = 34,                /* MAYORIGUAL  */
  YYSYMBOL_MAYOR = 35,                     /* MAYOR  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_40_ = 40,                       /* '%'  */
  YYSYMBOL_menos = 41,                     /* menos  */
  YYSYMBOL_NOT = 42,                       /* NOT  */
  YYSYMBOL_IF = 43,                        /* IF  */
  YYSYMBOL_44_ = 44,                       /* '<'  */
  YYSYMBOL_45_ = 45,                       /* '>'  */
  YYSYMBOL_46_ = 46,                       /* ':'  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_all = 52,                       /* all  */
  YYSYMBOL_zona_variables = 53,            /* zona_variables  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_inic_definicion = 55,           /* inic_definicion  */
  YYSYMBOL_definicion = 56,                /* definicion  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_secuencia_de_Identificadores = 60, /* secuencia_de_Identificadores  */
  YYSYMBOL_zona_recuadros = 61,            /* zona_recuadros  */
  YYSYMBOL_62_5 = 62,                      /* $@5  */
  YYSYMBOL_inic_definicion_recuadro = 63,  /* inic_definicion_recuadro  */
  YYSYMBOL_definicion_recuadro = 64,       /* definicion_recuadro  */
  YYSYMBOL_65_6 = 65,                      /* $@6  */
  YYSYMBOL_zona_lineas = 66,               /* zona_lineas  */
  YYSYMBOL_67_7 = 67,                      /* $@7  */
  YYSYMBOL_inic_definicion_linea = 68,     /* inic_definicion_linea  */
  YYSYMBOL_inic_creacion_cuadros_nombre = 69, /* inic_creacion_cuadros_nombre  */
  YYSYMBOL_creacion_cuadros_nombre = 70,   /* creacion_cuadros_nombre  */
  YYSYMBOL_71_8 = 71,                      /* $@8  */
  YYSYMBOL_inic_acciones_cuadros = 72,     /* inic_acciones_cuadros  */
  YYSYMBOL_acciones_cuadros = 73,          /* acciones_cuadros  */
  YYSYMBOL_74_9 = 74,                      /* $@9  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_76_11 = 76,                     /* $@11  */
  YYSYMBOL_77_12 = 77,                     /* $@12  */
  YYSYMBOL_78_13 = 78,                     /* $@13  */
  YYSYMBOL_condicional = 79,               /* condicional  */
  YYSYMBOL_salto = 80,                     /* salto  */
  YYSYMBOL_saltoOpcional = 81,             /* saltoOpcional  */
  YYSYMBOL_expr = 82,                      /* expr  */
  YYSYMBOL_logica = 83                     /* logica  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
       2,     2,     2,     2,     2,     2,     2,    40,     2,     2,
      47,    48,    38,    36,     2,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,     2,
      44,     2,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    85,    86,    86,    89,    90,    93,    93,
     124,   124,   128,   128,   165,   168,   176,   176,   178,   179,
     181,   181,   194,   194,   197,   198,   203,   204,   206,   207,
     207,   209,   210,   213,   213,   214,   214,   215,   215,   216,
     216,   259,   259,   260,   263,   264,   267,   268,   271,   272,
     275,   276,   277,   295,   296,   297,   298,   308,   323,   336,
     337,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352
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
  "\"end of file\"", "error", "\"invalid token\"", "PINTAR", "MENSAJE",
  "PAUSA", "ASIGNACION", "IGUAL", "VARIABLES", "RECUADROS", "LINEAS",
  "DIV", "MENOS", "SALTOLINEA", "PUNTOYCOMA", "COMA", "CUADRO",
  "FINCUADRO", "SI", "SINO", "IDENTIFICADORMINUSCULA",
  "IDENTIFICADORMAYUSCULA", "CADENA", "TIPO", "COLOR", "ORIENTACION",
  "ENTERO", "REAL", "BOOL", "OR", "AND", "DISTINTO", "MENOR", "MENORIGUAL",
  "MAYORIGUAL", "MAYOR", "'+'", "'-'", "'*'", "'/'", "'%'", "menos", "NOT",
  "IF", "'<'", "'>'", "':'", "'('", "')'", "'{'", "'}'", "$accept", "all",
  "zona_variables", "$@1", "inic_definicion", "definicion", "$@2", "$@3",
  "$@4", "secuencia_de_Identificadores", "zona_recuadros", "$@5",
  "inic_definicion_recuadro", "definicion_recuadro", "$@6", "zona_lineas",
  "$@7", "inic_definicion_linea", "inic_creacion_cuadros_nombre",
  "creacion_cuadros_nombre", "$@8", "inic_acciones_cuadros",
  "acciones_cuadros", "$@9", "$@10", "$@11", "$@12", "$@13", "condicional",
  "salto", "saltoOpcional", "expr", "logica", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,  -144,     9,     2,     4,  -144,  -144,    12,  -144,     5,
       4,  -144,  -144,  -144,   -16,     5,     4,     7,    32,    33,
    -144,    31,     5,    53,  -144,    41,    64,    69,    80,  -144,
      71,  -144,  -144,  -144,  -144,    41,    41,   134,    41,    73,
    -144,    47,   104,    66,  -144,    26,    41,  -144,    41,    41,
      41,    41,    41,   140,    99,  -144,     4,    41,    72,     4,
    -144,  -144,     4,    46,    46,  -144,  -144,  -144,  -144,     5,
    -144,   170,    41,   179,  -144,     4,    41,   175,    68,    78,
      79,    85,   111,   116,   220,     4,  -144,   180,   109,   119,
     120,    41,   110,    41,     4,  -144,  -144,   117,   131,   135,
     101,    70,  -144,   110,   110,   128,     3,   164,     5,   124,
     132,    41,  -144,  -144,  -144,     8,    29,    41,    41,    41,
      41,    41,    41,   110,   110,   110,   110,   106,     4,  -144,
     142,    65,     4,     4,  -144,   164,   164,   164,   164,   164,
     164,  -144,    42,    -6,  -144,   220,     5,     4,     4,    41,
    -144,     5,     5,   138,     5,     5,    83,     4,   174,  -144,
       5,   145,     4,   220,     5,   139,  -144
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     4,     0,     0,     0,     1,    16,     0,    46,     6,
       0,    22,    26,    47,     5,    18,     0,     2,     0,     0,
       7,    17,    24,     0,    27,     0,    14,     0,     0,    19,
      23,    29,    52,    50,    51,     0,     0,     0,     0,     0,
      10,     0,     0,     0,    59,     0,     0,    12,     0,     0,
       0,     0,     0,     0,    14,    15,    48,     0,     0,     0,
      60,    57,    48,    53,    54,    55,    56,    58,     8,    49,
      11,     0,     0,    31,    13,    48,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    48,     9,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    43,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,    39,    30,     0,
       0,     0,    41,    37,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,    73,    67,    65,    72,    69,    71,
      70,    68,    63,    62,    66,     0,    40,     0,     0,     0,
      35,    42,    38,     0,    21,    25,     0,     0,    44,    33,
      36,     0,     0,     0,    34,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,   157,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,   114,  -143,  -144,  -144,  -144,  -144,  -144,  -144,    -4,
     -54,   -22,   118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    14,    20,    75,    56,    62,    27,
       7,    10,    21,    29,   147,    12,    16,    30,    17,    24,
      43,    83,    84,   162,   157,   133,   128,   132,    85,    69,
      70,   105,   106
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       9,   123,   153,    37,    18,     1,    15,    19,    74,     5,
     123,     6,    22,    44,    45,   117,    53,     8,    13,    46,
     165,    86,    11,    23,    61,   126,    63,    64,    65,    66,
      67,    96,   124,   125,   126,    71,   123,    46,    25,   118,
     119,   120,   121,   122,    48,    49,    50,    51,    52,   123,
      77,   127,    28,    26,    87,    73,    60,    46,   124,   125,
     126,    32,    48,    49,    50,    51,    52,    33,    34,   101,
      38,   107,   125,   126,    60,    31,    46,   134,    35,    39,
     149,    46,   115,    40,    50,    51,    52,    41,    36,   131,
     108,    57,    42,    54,    46,   135,   136,   137,   138,   139,
     140,    48,    49,    50,    51,    52,    48,    49,    50,    51,
      52,    58,    59,   150,    39,    89,    72,    93,   113,    48,
      49,    50,    51,    52,   146,    90,    91,   156,   151,   152,
      32,   159,    92,    94,    98,   117,    33,    34,   102,    46,
      99,   109,   100,   154,   155,    46,   110,    35,    47,   112,
     111,    46,   103,   160,    68,   145,   130,   104,   164,   118,
     119,   120,   121,   122,    48,    49,    50,    51,    52,   129,
      48,    49,    50,    51,    52,    46,    48,    49,    50,    51,
      52,    46,    78,    79,    80,    76,    46,   148,   158,   166,
      88,    46,    13,   161,   163,    97,    55,    81,    95,    82,
      48,    49,    50,    51,    52,     0,    48,    49,    50,    51,
      52,    48,    49,    50,    51,    52,    48,    49,    50,    51,
      52,   114,   116,    78,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
      82,   141,   142,   143,   144
};

static const yytype_int16 yycheck[] =
{
       4,     7,   145,    25,    20,     8,    10,    23,    62,     0,
       7,     9,    16,    35,    36,     7,    38,    13,    13,    11,
     163,    75,    10,    16,    46,    31,    48,    49,    50,    51,
      52,    85,    29,    30,    31,    57,     7,    11,     6,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     7,
      72,    48,    21,    20,    76,    59,    48,    11,    29,    30,
      31,    20,    36,    37,    38,    39,    40,    26,    27,    91,
       6,    93,    30,    31,    48,    22,    11,    48,    37,    15,
      15,    11,   104,    14,    38,    39,    40,     7,    47,   111,
      94,    44,    21,    20,    11,   117,   118,   119,   120,   121,
     122,    36,    37,    38,    39,    40,    36,    37,    38,    39,
      40,     7,    46,    48,    15,    47,    44,     6,    48,    36,
      37,    38,    39,    40,   128,    47,    47,   149,   132,   133,
      20,    48,    47,    17,    25,     7,    26,    27,    28,    11,
      21,    24,    22,   147,   148,    11,    15,    37,    14,    48,
      15,    11,    42,   157,    14,    49,    24,    47,   162,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    45,
      36,    37,    38,    39,    40,    11,    36,    37,    38,    39,
      40,    11,     3,     4,     5,    15,    11,    45,    50,    50,
      15,    11,    13,    19,    49,    15,    39,    18,    84,    20,
      36,    37,    38,    39,    40,    -1,    36,    37,    38,    39,
      40,    36,    37,    38,    39,    40,    36,    37,    38,    39,
      40,   103,   104,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      20,   123,   124,   125,   126
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    52,    53,    54,     0,     9,    61,    13,    80,
      62,    10,    66,    13,    55,    80,    67,    69,    20,    23,
      56,    63,    80,    16,    70,     6,    20,    60,    21,    64,
      68,    22,    20,    26,    27,    37,    47,    82,     6,    15,
      14,     7,    21,    71,    82,    82,    11,    14,    36,    37,
      38,    39,    40,    82,    20,    60,    58,    44,     7,    46,
      48,    82,    59,    82,    82,    82,    82,    82,    14,    80,
      81,    82,    44,    80,    81,    57,    15,    82,     3,     4,
       5,    18,    20,    72,    73,    79,    81,    82,    15,    47,
      47,    47,    47,     6,    17,    72,    81,    15,    25,    21,
      22,    82,    28,    42,    47,    82,    83,    82,    80,    24,
      15,    15,    48,    48,    83,    82,    83,     7,    31,    32,
      33,    34,    35,     7,    29,    30,    31,    48,    77,    45,
      24,    82,    78,    76,    48,    82,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    49,    80,    65,    45,    15,
      48,    80,    80,    73,    80,    80,    82,    75,    50,    48,
      80,    19,    74,    49,    80,    73,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    54,    53,    55,    55,    57,    56,
      58,    56,    59,    56,    60,    60,    62,    61,    63,    63,
      65,    64,    67,    66,    68,    68,    69,    69,    70,    71,
      70,    72,    72,    74,    73,    75,    73,    76,    73,    77,
      73,    78,    73,    73,    79,    79,    80,    80,    81,    81,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     0,     4,     0,     2,     0,     7,
       0,     5,     0,     6,     1,     3,     0,     4,     0,     2,
       0,    11,     0,     4,     0,    11,     0,     2,     0,     0,
       8,     0,     2,     0,    10,     0,     8,     0,     6,     0,
       5,     0,     6,     2,     7,    11,     1,     2,     0,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     1,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3
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
  case 2: /* all: zona_variables zona_recuadros zona_lineas inic_creacion_cuadros_nombre  */
#line 82 "mondrian.y"
                                                                              {;}
#line 1310 "mondrian.c"
    break;

  case 4: /* $@1: %empty  */
#line 86 "mondrian.y"
                          {fprintf(yyout,"VARIABLES");}
#line 1316 "mondrian.c"
    break;

  case 5: /* zona_variables: VARIABLES $@1 salto inic_definicion  */
#line 86 "mondrian.y"
                                                                             { cout << "VARIABLES"<<endl;}
#line 1322 "mondrian.c"
    break;

  case 8: /* $@2: %empty  */
#line 93 "mondrian.y"
                                                                      { 
                                                                        InformacionSimbolo info, auxComprobacion;
                                                                        if(buscarSimbolo(tablaSimbolos, (yyvsp[-3].var), auxComprobacion))
                                                                        {
                                                                              if((strcmp((yyvsp[-4].var),"Real") == 0) &&(!(yyvsp[-1].c_expresion).esReal)){
                                                                                    error = true;
                                                                                    //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                              }else if((strcmp((yyvsp[-4].var),"Entero") == 0) &&((yyvsp[-1].c_expresion).esReal))
                                                                              {
                                                                                    error = true;
                                                                                    //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                              }
                                                                        }


                                                                         if (!error){ 
                                                                        
                                                                              //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                              InformacionSimbolo info, aux;
                                                                              if((yyvsp[-1].c_expresion).esReal){
                                                                                    info.d = Real;
                                                                                    info.valor_float = (yyvsp[-1].c_expresion).valor;
                                                                              }else{
                                                                                    info.d = Entero;
                                                                                    info.valor_int = (yyvsp[-1].c_expresion).valor;
                                                                              }
                                                                              insertarSimbolo(tablaSimbolos, (yyvsp[-3].var), info);
                                                                        }    
                                                                        cout<<"Tipo Identificador";
                                                                        error = false;
                                                                  }
#line 1358 "mondrian.c"
    break;

  case 10: /* $@3: %empty  */
#line 124 "mondrian.y"
                                                             {
                                                                  fprintf(yyout,";"); 
                                                                  cout<<"Tipo secuencia_Identificadores ";
                                                            }
#line 1367 "mondrian.c"
    break;

  case 12: /* $@4: %empty  */
#line 128 "mondrian.y"
                                                                {

                                                                  InformacionSimbolo info, auxComprobacion;
                                                                  if(buscarSimbolo(tablaSimbolos, (yyvsp[-3].var), auxComprobacion))
                                                                  {
                                                                          
                                                                        if((auxComprobacion.d == Real) &&(!(yyvsp[-1].c_expresion).esReal)){
                                                                              error = true;
                                                                              //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                        }else if((auxComprobacion.d == Entero) &&((yyvsp[-1].c_expresion).esReal))
                                                                        {
                                                                              error = true;
                                                                              //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                        }
                                                                  }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                          cout<<endl<<"ENTRA "<< (yyvsp[-3].var) <<endl;
                                                                        error = true;
                                                                  }

                                                                  if (!error){ 
                                                                  //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                        InformacionSimbolo info, aux;
                                                                        if((yyvsp[-1].c_expresion).esReal){
                                                                              info.d = Real;
                                                                              info.valor_float = (yyvsp[-1].c_expresion).valor;
                                                                        }else{
                                                                              info.d = Entero;
                                                                              info.valor_int = (yyvsp[-1].c_expresion).valor;
                                                                        }
                                                                        insertarSimbolo(tablaSimbolos, (yyvsp[-3].var), info);
                                                                        }    
                                                                        cout<<"Tipo Identificador";
                                                                         error = false;
                                                                  }
#line 1407 "mondrian.c"
    break;

  case 14: /* secuencia_de_Identificadores: IDENTIFICADORMINUSCULA  */
#line 165 "mondrian.y"
                                                       {
                                                      fprintf(yyout,"%s;",(yyvsp[0].var)); cout<<"Identificador ";cout<<"PuntoYCOma ";
                                                      }
#line 1415 "mondrian.c"
    break;

  case 15: /* secuencia_de_Identificadores: IDENTIFICADORMINUSCULA COMA secuencia_de_Identificadores  */
#line 168 "mondrian.y"
                                                                                         {
                                                                                          fprintf(yyout,"%s, ",(yyvsp[-2].var)); cout<<"Identificador "; cout<<"Coma ";
                                                                                          }
#line 1423 "mondrian.c"
    break;

  case 16: /* $@5: %empty  */
#line 176 "mondrian.y"
                           {fprintf(yyout,"RECUADROS");}
#line 1429 "mondrian.c"
    break;

  case 17: /* zona_recuadros: RECUADROS $@5 salto inic_definicion_recuadro  */
#line 176 "mondrian.y"
                                                                                          {cout<<"RECUADROS"<<endl;}
#line 1435 "mondrian.c"
    break;

  case 20: /* $@6: %empty  */
#line 181 "mondrian.y"
                                                                                          { 
                                                                                          
                                                                              


                                                                                          fprintf(yyout,"%s = <%d, %d, %s>",(yyvsp[-8].var),(int)(yyvsp[-5].c_expresion).valor,(int)(yyvsp[-3].c_expresion).valor,(yyvsp[-1].var));  
                                                                                          cout << "Identificador_mayuscula = < Entero, Entero, Color>"<<endl;
                                                                                          }
#line 1448 "mondrian.c"
    break;

  case 22: /* $@7: %empty  */
#line 194 "mondrian.y"
                      {fprintf(yyout,"RECUADROS");}
#line 1454 "mondrian.c"
    break;

  case 23: /* zona_lineas: LINEAS $@7 salto inic_definicion_linea  */
#line 194 "mondrian.y"
                                                                                 {cout << "LINEAS"<<endl;}
#line 1460 "mondrian.c"
    break;

  case 25: /* inic_definicion_linea: inic_definicion_linea IDENTIFICADORMAYUSCULA IGUAL '<' expr COMA ORIENTACION COMA COLOR '>' salto  */
#line 198 "mondrian.y"
                                                                                                                              {fprintf(yyout,"%s = <%d, %s, %s>",(yyvsp[-9].var),(int)(yyvsp[-6].c_expresion).valor,(yyvsp[-4].var),(yyvsp[-2].var));   cout << "Identificador_mayuscula = < Entero, Orientacion, Color>"<<endl;}
#line 1466 "mondrian.c"
    break;

  case 27: /* inic_creacion_cuadros_nombre: inic_creacion_cuadros_nombre creacion_cuadros_nombre  */
#line 204 "mondrian.y"
                                                                                {}
#line 1472 "mondrian.c"
    break;

  case 29: /* $@8: %empty  */
#line 207 "mondrian.y"
                                         {fprintf(yyout,"CUADRO  %s",(yyvsp[0].var));}
#line 1478 "mondrian.c"
    break;

  case 30: /* creacion_cuadros_nombre: CUADRO CADENA $@8 ':' salto inic_acciones_cuadros FINCUADRO salto  */
#line 207 "mondrian.y"
                                                                                                                             { cout<<"Cuadro NombreCuadro :"<<endl;}
#line 1484 "mondrian.c"
    break;

  case 32: /* inic_acciones_cuadros: acciones_cuadros inic_acciones_cuadros  */
#line 210 "mondrian.y"
                                                                  {}
#line 1490 "mondrian.c"
    break;

  case 33: /* $@9: %empty  */
#line 213 "mondrian.y"
                                                                             {fprintf(yyout,"PINTAR (%s, %d, %d)",(yyvsp[-5].var),(int)(yyvsp[-3].c_expresion).valor,(int)(yyvsp[-1].c_expresion).valor); cout<<"Pintar (Identificador_mayuscula, Expr,Expr)"<<endl;}
#line 1496 "mondrian.c"
    break;

  case 35: /* $@10: %empty  */
#line 214 "mondrian.y"
                                                                    {fprintf(yyout,"PINTAR (%s, %d)",(yyvsp[-3].var),(int)(yyvsp[-1].c_expresion).valor); cout<<"Pintar (Identificador_mayuscula, Expr)"<<endl;}
#line 1502 "mondrian.c"
    break;

  case 37: /* $@11: %empty  */
#line 215 "mondrian.y"
                                      {fprintf(yyout,"PAUSA (%d)",(int)(yyvsp[-1].c_expresion).valor); cout<<"Pausa (expr)"<<endl;}
#line 1508 "mondrian.c"
    break;

  case 39: /* $@12: %empty  */
#line 216 "mondrian.y"
                                                          { 
                                                            error = false;
                                                            cout<<endl<<"ENTRA"<<endl;
                                                            InformacionSimbolo info, auxComprobacion;
                                                            if(buscarSimbolo(tablaSimbolos, (yyvsp[-2].var), auxComprobacion))
                                                            {    
                                                                  cout<<endl<<"ENTRA simbolo encontrado"<<endl;          
                                                                 if((auxComprobacion.d == Real) &&(!(yyvsp[0].c_expresion).esReal)){
                                                                  cout<<endl<<"ENTRA ERROR 1"<<endl;    
                                                                               error = true;
                                                                              //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                  }else if((auxComprobacion.d == Entero) &&((yyvsp[0].c_expresion).esReal))
                                                                  {
                                                                        cout<<endl<<"ENTRA ERROR 2"<<endl;    
                                                                        error = true;
                                                                        //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                  }
                                                                  }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                        cout<<endl<<"ENTRA "<< (yyvsp[-2].var) <<endl;
                                                                        error = true;
                                                            }

                                                            if (!error){ 
                                                                  //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                  cout<<endl<<"ENTRA ACTUALIZAR"<< (yyvsp[-2].var) <<endl;
                                                                  InformacionSimbolo info, aux;
                                                                  if((yyvsp[0].c_expresion).esReal){
                                                                        info.d = Real;
                                                                        info.valor_float = (yyvsp[0].c_expresion).valor;
                                                                  }else{
                                                                        info.d = Entero;
                                                                        info.valor_int = (yyvsp[0].c_expresion).valor;
                                                                  }
                                                            insertarSimbolo(tablaSimbolos, (yyvsp[-2].var), info);
                                                            }    
                                                            cout<<"Tipo Identificador";
                                                            error = false;
                                                          
                                                          fprintf(yyout,"%s := %d",(yyvsp[-2].var),(int)(yyvsp[0].c_expresion).valor);  
                                                          cout<<"Identificador_Minuscula Asignacion Expr"<<endl;
                                                          
                                                          }
#line 1556 "mondrian.c"
    break;

  case 41: /* $@13: %empty  */
#line 259 "mondrian.y"
                                         {fprintf(yyout,"MENSAJE (%s)",(yyvsp[-1].var)); cout<<"Mensaje (CADENA)"<<endl;}
#line 1562 "mondrian.c"
    break;

  case 44: /* condicional: SI '(' logica ')' '{' acciones_cuadros '}'  */
#line 263 "mondrian.y"
                                                                  {}
#line 1568 "mondrian.c"
    break;

  case 45: /* condicional: SI '(' logica ')' '{' acciones_cuadros '}' SINO '{' acciones_cuadros '}'  */
#line 264 "mondrian.y"
                                                                                      {}
#line 1574 "mondrian.c"
    break;

  case 46: /* salto: SALTOLINEA  */
#line 267 "mondrian.y"
                   {fprintf(yyout,"\n");}
#line 1580 "mondrian.c"
    break;

  case 47: /* salto: salto SALTOLINEA  */
#line 268 "mondrian.y"
                         {fprintf(yyout,"\n");}
#line 1586 "mondrian.c"
    break;

  case 50: /* expr: ENTERO  */
#line 275 "mondrian.y"
                           {(yyval.c_expresion).valor= (yyvsp[0].c_entero); (yyval.c_expresion).esReal = false;}
#line 1592 "mondrian.c"
    break;

  case 51: /* expr: REAL  */
#line 276 "mondrian.y"
                                 {(yyval.c_expresion).esReal = true ; (yyval.c_expresion).valor = (yyvsp[0].c_real);}
#line 1598 "mondrian.c"
    break;

  case 52: /* expr: IDENTIFICADORMINUSCULA  */
#line 277 "mondrian.y"
                             {
                              InformacionSimbolo info;
                              if(buscarSimbolo(tablaSimbolos, (yyvsp[0].var), info)){
                                    if(info.d == 0){// si es real
                                          (yyval.c_expresion).valor = info.valor_float;
                                          (yyval.c_expresion).esReal = true;
                                    } else if(info.d == 1){ // es entero
                                          (yyval.c_expresion).valor = info.valor_int;
                                          (yyval.c_expresion).esReal = false;
                                    } else{
                                          error = true;
                                      cout << "Error semantico en la instruccion "<< n_lineas+1 << ", no se pueden usar variables de tipo logico a la derecha de una asignacion"<<endl;
                                    }      
                              }else{
                                    error = true;
                                    cout << "Error en la instruccion "<< n_lineas+1 << ", la variable utilizada '"<< (yyvsp[0].var) << "' no existe"<<endl;
                              }
                              }
#line 1621 "mondrian.c"
    break;

  case 53: /* expr: expr '+' expr  */
#line 295 "mondrian.y"
                           {(yyval.c_expresion).valor = (yyvsp[-2].c_expresion).valor + (yyvsp[0].c_expresion).valor;  (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal ;}
#line 1627 "mondrian.c"
    break;

  case 54: /* expr: expr '-' expr  */
#line 296 "mondrian.y"
                           {(yyval.c_expresion).valor = (yyvsp[-2].c_expresion).valor - (yyvsp[0].c_expresion).valor; (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal ;}
#line 1633 "mondrian.c"
    break;

  case 55: /* expr: expr '*' expr  */
#line 297 "mondrian.y"
                           {(yyval.c_expresion).valor = (float) (yyvsp[-2].c_expresion).valor * (float) (yyvsp[0].c_expresion).valor; (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal ;}
#line 1639 "mondrian.c"
    break;

  case 56: /* expr: expr '/' expr  */
#line 298 "mondrian.y"
                           { 
                              (yyval.c_expresion).esReal = true;
                              if((yyvsp[0].c_expresion).valor != 0){
                                    (yyval.c_expresion).valor =  (float)(yyvsp[-2].c_expresion).valor / (float)(yyvsp[0].c_expresion).valor;
                              }else{
                                    error = true;
                                    cout << "Error semantico en la instruccion " << n_lineas+1 << ", division por cero"<< endl;
                              }
                              
                        }
#line 1654 "mondrian.c"
    break;

  case 57: /* expr: expr DIV expr  */
#line 308 "mondrian.y"
                            { 
                              (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal;
                              if((yyvsp[0].c_expresion).valor != 0){
                                    if((yyval.c_expresion).esReal) {
                                          error = true;
                                          cout << "Error semantico en la instruccion " << n_lineas+1 << ", ambos operandos deben ser enteros"<< endl;
                                     } else
                                          (yyval.c_expresion).valor =  (int) (yyvsp[-2].c_expresion).valor / (int) (yyvsp[0].c_expresion).valor;
                              }else{
                                    error = true;
                                    cout << "Error semantico en la instruccion " << n_lineas+1 << ", division por cero"<< endl;
                              }
                              
                        }
#line 1673 "mondrian.c"
    break;

  case 58: /* expr: expr '%' expr  */
#line 323 "mondrian.y"
                        {
                        (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal;
                              if((yyvsp[0].c_expresion).valor != 0){
                                    if((yyval.c_expresion).esReal){
                                          error = true;
                                          cout << "Error semantico en la instruccion " << n_lineas+1 << ", ambos operandos deben ser enteros"<< endl;
                                    }else
                                          (yyval.c_expresion).valor =  (int) (yyvsp[-2].c_expresion).valor % (int) (yyvsp[0].c_expresion).valor;
                              }else{ 
                                    error = true;
                                    cout << "Error semantico en la instruccion " << n_lineas+1 << ", division por cero"<< endl;
                              }
    }
#line 1691 "mondrian.c"
    break;

  case 59: /* expr: '-' expr  */
#line 336 "mondrian.y"
                           {(yyval.c_expresion).valor = - ((yyvsp[0].c_expresion).valor);  (yyval.c_expresion).esReal = (yyvsp[0].c_expresion).esReal;}
#line 1697 "mondrian.c"
    break;

  case 60: /* expr: '(' expr ')'  */
#line 337 "mondrian.y"
                           {(yyval.c_expresion).valor = (yyvsp[-1].c_expresion).valor; (yyval.c_expresion).esReal = (yyvsp[-1].c_expresion).esReal;}
#line 1703 "mondrian.c"
    break;

  case 61: /* logica: BOOL  */
#line 340 "mondrian.y"
             {(yyval.c_bool) = (yyvsp[0].c_bool);}
#line 1709 "mondrian.c"
    break;

  case 62: /* logica: logica AND logica  */
#line 341 "mondrian.y"
                          {(yyval.c_bool) = (yyvsp[-2].c_bool) && (yyvsp[0].c_bool);}
#line 1715 "mondrian.c"
    break;

  case 63: /* logica: logica OR logica  */
#line 342 "mondrian.y"
                         {(yyval.c_bool) = (yyvsp[-2].c_bool) || (yyvsp[0].c_bool);}
#line 1721 "mondrian.c"
    break;

  case 64: /* logica: NOT logica  */
#line 343 "mondrian.y"
                   {(yyval.c_bool) = ! ((yyvsp[0].c_bool));}
#line 1727 "mondrian.c"
    break;

  case 65: /* logica: expr DISTINTO expr  */
#line 344 "mondrian.y"
                           {(yyval.c_bool) = ((yyvsp[-2].c_expresion).valor != (yyvsp[0].c_expresion).valor);}
#line 1733 "mondrian.c"
    break;

  case 66: /* logica: logica DISTINTO logica  */
#line 345 "mondrian.y"
                               {(yyval.c_bool) = ((yyvsp[-2].c_bool) != (yyvsp[0].c_bool));}
#line 1739 "mondrian.c"
    break;

  case 67: /* logica: expr IGUAL expr  */
#line 346 "mondrian.y"
                        {(yyval.c_bool) =  ((yyvsp[-2].c_expresion).valor == (yyvsp[0].c_expresion).valor);}
#line 1745 "mondrian.c"
    break;

  case 68: /* logica: logica IGUAL logica  */
#line 347 "mondrian.y"
                            {(yyval.c_bool) =  ((yyvsp[-2].c_bool) == (yyvsp[0].c_bool));}
#line 1751 "mondrian.c"
    break;

  case 69: /* logica: expr MENORIGUAL expr  */
#line 348 "mondrian.y"
                             {(yyval.c_bool) =  ((yyvsp[-2].c_expresion).valor <= (yyvsp[0].c_expresion).valor);}
#line 1757 "mondrian.c"
    break;

  case 70: /* logica: expr MAYOR expr  */
#line 349 "mondrian.y"
                        {(yyval.c_bool) =  ((yyvsp[-2].c_expresion).valor > (yyvsp[0].c_expresion).valor);}
#line 1763 "mondrian.c"
    break;

  case 71: /* logica: expr MAYORIGUAL expr  */
#line 350 "mondrian.y"
                             {(yyval.c_bool) =  ((yyvsp[-2].c_expresion).valor >= (yyvsp[0].c_expresion).valor);}
#line 1769 "mondrian.c"
    break;

  case 72: /* logica: expr MENOR expr  */
#line 351 "mondrian.y"
                        {(yyval.c_bool) =  ((yyvsp[-2].c_expresion).valor < (yyvsp[0].c_expresion).valor);}
#line 1775 "mondrian.c"
    break;

  case 73: /* logica: '(' logica ')'  */
#line 352 "mondrian.y"
                        {(yyval.c_bool) =  (yyvsp[-1].c_bool);}
#line 1781 "mondrian.c"
    break;


#line 1785 "mondrian.c"

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

#line 355 "mondrian.y"


int main(int argc, char **argv){
     
     n_lineas = 0;
     yyin = fopen(argv[1],"rt");
     yyout = fopen("salida.txt","wt");
     fprintf(yyout, "#include mondrian.h \n" );
     fprintf(yyout,"#include <allegro5/allegro5.h> \n");
     fprintf(yyout,"using namespace std; \n");
     fprintf(yyout,"int main(int argc, char **argv){ \n");
      using namespace std;
     yyparse();
     fprintf(yyout,"}\n");
      mostrarTabla(tablaSimbolos, yyout);
     fclose(yyout);
     fclose(yyin);
     return 0;
}
