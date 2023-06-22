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
#line 1 "proyecto_mondrian.y"

using namespace std;
#include <iostream>
#include "tablaSimbolos.h"
#include <cstring>
#include <typeinfo>



// Jesus Castaño Tato, Asier Serrano Martín			
map<string, InformacionSimbolo> tablaSimbolos;
map<string, InformacionSimbolo> tablaSimbolosLineas;
map<string, InformacionSimbolo> tablaSimbolosRecuadros;
extern int n_lineas;
extern int yylex();

extern FILE* yyin ;
extern FILE* yyout ;

bool errorS = false;
bool condicionalVerdadero = true;
char Tipo_Secuencia[25];
void yyerror(const char* s){      
      // errorS = true;
      // if(strcmp(s,"syntax errorS") == 0){
      //       cout << "errorS sintáctico en la instrucción " << n_lineas +1 <<endl;
            
      // }else{
      //       cout << "En la instrucción "<< n_lineas + 1<< " se ha dado un " << s <<endl;
      // }
      cout << "Error sintactico en la instruccion " << n_lineas+1 << endl;

} 
int color (char *color)
{
      
      if(strcmp(color,"blanco") ==0)
            return 0;
      if(strcmp(color,"negro")==0)
            return 1;
      if(strcmp(color,"gris")==0)
            return 2;
      if(strcmp(color,"rojo")==0)
            return 3;
      if(strcmp(color,"azul")==0)
            return 4;
      if(strcmp(color,"amarillo")==0)
            return 5;
      if(strcmp(color,"verde")==0)
            return 6;
      return -1;
}
string impresionBool(bool a)
{
    return  (a==true) ? "True" : "False";
}   

string enteroOreal(bool enteroOreal)
{
      return (enteroOreal==true) ? "real" : "entero";
}

#line 134 "proyecto_mondrian.c"

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

#include "proyecto_mondrian.h"
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
  YYSYMBOL_TIPO = 22,                      /* TIPO  */
  YYSYMBOL_COLOR = 23,                     /* COLOR  */
  YYSYMBOL_ORIENTACION = 24,               /* ORIENTACION  */
  YYSYMBOL_CADENA = 25,                    /* CADENA  */
  YYSYMBOL_ENTERO = 26,                    /* ENTERO  */
  YYSYMBOL_REAL = 27,                      /* REAL  */
  YYSYMBOL_BOOL = 28,                      /* BOOL  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_DISTINTO = 31,                  /* DISTINTO  */
  YYSYMBOL_MENORIGUAL = 32,                /* MENORIGUAL  */
  YYSYMBOL_MAYORIGUAL = 33,                /* MAYORIGUAL  */
  YYSYMBOL_34_ = 34,                       /* '+'  */
  YYSYMBOL_35_ = 35,                       /* '-'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_38_ = 38,                       /* '%'  */
  YYSYMBOL_menos = 39,                     /* menos  */
  YYSYMBOL_NOT = 40,                       /* NOT  */
  YYSYMBOL_si_simple = 41,                 /* si_simple  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_43_ = 43,                       /* '>'  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_47_ = 47,                       /* '{'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_all = 50,                       /* all  */
  YYSYMBOL_zona_variables = 51,            /* zona_variables  */
  YYSYMBOL_inic_definicion = 52,           /* inic_definicion  */
  YYSYMBOL_definicion = 53,                /* definicion  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_secuencia_de_Identificadores = 59, /* secuencia_de_Identificadores  */
  YYSYMBOL_zona_recuadros = 60,            /* zona_recuadros  */
  YYSYMBOL_61_6 = 61,                      /* $@6  */
  YYSYMBOL_inic_definicion_recuadro = 62,  /* inic_definicion_recuadro  */
  YYSYMBOL_definicion_recuadro = 63,       /* definicion_recuadro  */
  YYSYMBOL_64_7 = 64,                      /* $@7  */
  YYSYMBOL_zona_lineas = 65,               /* zona_lineas  */
  YYSYMBOL_inic_definicion_linea = 66,     /* inic_definicion_linea  */
  YYSYMBOL_definicion_linea = 67,          /* definicion_linea  */
  YYSYMBOL_inic_creacion_cuadros_nombre = 68, /* inic_creacion_cuadros_nombre  */
  YYSYMBOL_creacion_cuadros_nombre = 69,   /* creacion_cuadros_nombre  */
  YYSYMBOL_70_8 = 70,                      /* $@8  */
  YYSYMBOL_inic_acciones_cuadros = 71,     /* inic_acciones_cuadros  */
  YYSYMBOL_acciones_cuadros = 72,          /* acciones_cuadros  */
  YYSYMBOL_73_9 = 73,                      /* $@9  */
  YYSYMBOL_74_10 = 74,                     /* $@10  */
  YYSYMBOL_75_11 = 75,                     /* $@11  */
  YYSYMBOL_76_12 = 76,                     /* $@12  */
  YYSYMBOL_77_13 = 77,                     /* $@13  */
  YYSYMBOL_78_14 = 78,                     /* $@14  */
  YYSYMBOL_condicional = 79,               /* condicional  */
  YYSYMBOL_parteSi = 80,                   /* parteSi  */
  YYSYMBOL_81_15 = 81,                     /* $@15  */
  YYSYMBOL_parteSiNo = 82,                 /* parteSiNo  */
  YYSYMBOL_83_16 = 83,                     /* $@16  */
  YYSYMBOL_bloque = 84,                    /* bloque  */
  YYSYMBOL_salto = 85,                     /* salto  */
  YYSYMBOL_saltoOpcional = 86,             /* saltoOpcional  */
  YYSYMBOL_expr = 87,                      /* expr  */
  YYSYMBOL_logica = 88                     /* logica  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
       2,     2,     2,     2,     2,     2,     2,    38,     2,     2,
      45,    46,    36,    34,     2,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,     2,
      42,     2,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    39,
      40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   109,   110,   113,   114,   117,   117,   169,
     169,   207,   207,   231,   231,   273,   273,   305,   308,   322,
     339,   339,   341,   342,   344,   344,   367,   374,   377,   378,
     383,   404,   409,   410,   412,   412,   414,   415,   418,   418,
     445,   445,   473,   473,   481,   481,   528,   528,   563,   563,
     569,   570,   572,   575,   575,   578,   579,   579,   581,   583,
     584,   587,   588,   591,   592,   593,   614,   615,   616,   617,
     627,   642,   655,   656,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671
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
  "IDENTIFICADORMAYUSCULA", "TIPO", "COLOR", "ORIENTACION", "CADENA",
  "ENTERO", "REAL", "BOOL", "OR", "AND", "DISTINTO", "MENORIGUAL",
  "MAYORIGUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "menos", "NOT",
  "si_simple", "'<'", "'>'", "':'", "'('", "')'", "'{'", "'}'", "$accept",
  "all", "zona_variables", "inic_definicion", "definicion", "$@1", "$@2",
  "$@3", "$@4", "$@5", "secuencia_de_Identificadores", "zona_recuadros",
  "$@6", "inic_definicion_recuadro", "definicion_recuadro", "$@7",
  "zona_lineas", "inic_definicion_linea", "definicion_linea",
  "inic_creacion_cuadros_nombre", "creacion_cuadros_nombre", "$@8",
  "inic_acciones_cuadros", "acciones_cuadros", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "condicional", "parteSi", "$@15", "parteSiNo",
  "$@16", "bloque", "salto", "saltoOpcional", "expr", "logica", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-118)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-37)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,    -9,     5,  -118,     2,  -118,  -118,    -9,     6,  -118,
    -118,    10,   176,    -9,    -9,  -118,  -118,    16,     7,  -118,
    -118,  -118,    32,   274,    63,    42,   129,   143,    45,  -118,
    -118,  -118,  -118,  -118,   121,   274,   274,   138,    -6,   274,
      55,  -118,  -118,    66,  -118,  -118,    69,  -118,  -118,   121,
    -118,   188,  -118,    57,    89,   121,   121,  -118,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   274,  -118,
     274,   274,   274,   175,    98,    64,  -118,    -9,    35,    39,
      60,   156,  -118,  -118,   255,  -118,    -9,   255,   255,   255,
     100,   100,  -118,  -118,  -118,   255,   255,  -118,    -9,    53,
      -5,  -118,  -118,  -118,  -118,   121,   121,    -9,  -118,  -118,
      -9,    -9,    -4,   235,   303,  -118,  -118,   121,    74,  -118,
      76,    77,    81,    88,   101,    92,    54,  -118,    95,   250,
     119,   125,   117,   121,   274,   274,    -9,  -118,  -118,  -118,
     130,   131,   146,   112,   203,    94,   188,   267,  -118,   118,
     136,   141,   121,  -118,  -118,  -118,    -9,    -9,    -9,  -118,
    -118,    -9,   217,    -9,    -9,   118,  -118,  -118,    62,    -9,
    -118,   121,  -118,  -118,  -118,  -118,   139,  -118,   222,    -9,
      -9,  -118,  -118,  -118,    -9,  -118
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      61,    59,     0,    62,     3,    60,     1,     0,     0,     5,
      20,     0,     0,     0,     0,    32,    17,     0,     0,     6,
      22,    28,     2,     0,    18,     0,     0,     0,     0,    33,
      65,    63,    64,    74,     0,     0,     0,     0,     0,     0,
       0,    11,    26,     0,    23,    31,     0,    29,    34,     0,
      72,     0,    77,     0,     0,     0,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,    18,    19,    61,     0,     0,
       0,     0,    73,    86,    80,    70,    61,    78,    82,    84,
      66,    67,    68,    69,    71,    85,    83,    81,    61,    76,
      75,    79,     7,     9,    12,     0,     0,     0,    14,    16,
      61,    61,     0,     0,     0,     8,    10,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,    50,    55,     0,
       0,     0,     0,     0,     0,     0,    61,    37,    56,    52,
       0,     0,     0,     0,     0,     0,    44,    46,    35,     0,
       0,     0,     0,    48,    42,    53,     0,    61,     0,    57,
      24,     0,     0,     0,     0,     0,    45,    47,     0,     0,
      30,     0,    40,    49,    43,    54,     0,    25,     0,     0,
      61,    38,    41,    58,     0,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
     148,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -117,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,    36,    -1,   -49,   -20,   -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,    12,    19,   110,   111,    77,    86,    98,
      25,    11,    13,    26,    44,   169,    15,    27,    47,    22,
      29,    80,   125,   126,   184,   179,   164,   156,   157,   163,
     127,   128,   165,   139,   149,   159,     3,     4,    51,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,    68,    68,    37,     1,     6,     9,    56,    69,   137,
       7,   117,    20,    21,    50,    10,    53,    52,    54,    73,
      14,    74,    23,    70,    71,    72,    72,    24,   104,    81,
      61,    62,    63,    64,    65,    84,    85,   108,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    28,   109,
      97,   176,    99,   100,   101,   119,    41,   120,   121,   122,
      68,   115,   116,   119,    55,   120,   121,   122,    56,    39,
      48,   -36,   123,    78,   124,    75,    79,   105,    40,    40,
     123,   106,   124,    71,    72,   112,   113,   148,    58,    59,
      60,    61,    62,    63,    64,    65,    68,   129,   130,    66,
      67,    68,   -36,    82,   107,    68,   114,   135,   167,   136,
     -36,    56,   103,   144,   138,   146,   145,   147,    70,    71,
      72,   131,   132,    70,    71,    72,   133,    70,    71,    72,
      42,   183,   162,   134,   141,    83,    63,    64,    65,   -21,
     155,    30,   143,   -27,    45,    55,   142,    31,    32,    56,
      43,   178,    57,   150,   151,   166,    34,   168,   153,   -27,
     170,   152,   173,   174,    46,   158,    49,    56,   177,    58,
      59,    60,    61,    62,    63,    64,    65,    16,   182,   160,
      66,    67,    55,   185,   161,    -4,    56,   180,    76,   102,
      61,    62,    63,    64,    65,    55,    17,     0,    18,    56,
       0,   175,    82,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    56,     0,     0,    66,    67,    58,
      59,    60,    61,    62,    63,    64,    65,     0,    56,     0,
      66,    67,   171,    56,     0,     0,     0,    61,    62,    63,
      64,    65,     0,     0,     0,     0,    56,     0,     0,   154,
     118,    61,    62,    63,    64,    65,    61,    62,    63,    64,
      65,    56,     0,   172,     0,   140,    56,     0,   181,    61,
      62,    63,    64,    65,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,    61,
      62,    63,    64,    65,    30,     0,    70,    71,    72,     0,
      31,    32,    33,     0,   119,     0,   120,   121,   122,    34,
       0,     0,     0,     0,    35,     0,     0,     0,     0,    36,
     -36,   123,     0,   124
};

static const yytype_int16 yycheck[] =
{
       1,     7,     7,    23,    13,     0,     7,    11,    14,   126,
       8,    15,    13,    14,    34,     9,    36,    35,    36,    39,
      10,    39,     6,    29,    30,    31,    31,    20,    77,    49,
      34,    35,    36,    37,    38,    55,    56,    86,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    16,    98,
      68,   168,    70,    71,    72,     1,    14,     3,     4,     5,
       7,   110,   111,     1,     7,     3,     4,     5,    11,     6,
      25,    17,    18,     7,    20,    20,     7,    42,    15,    15,
      18,    42,    20,    30,    31,   105,   106,   136,    31,    32,
      33,    34,    35,    36,    37,    38,     7,   117,    24,    42,
      43,     7,    48,    46,    44,     7,   107,     6,   157,    17,
      48,    11,    14,   133,    19,   135,   134,   135,    29,    30,
      31,    45,    45,    29,    30,    31,    45,    29,    30,    31,
       1,   180,   152,    45,    15,    46,    36,    37,    38,    10,
      46,    20,    25,     0,     1,     7,    21,    26,    27,    11,
      21,   171,    14,    23,    23,   156,    35,   158,    46,    16,
     161,    15,   163,   164,    21,    47,    45,    11,   169,    31,
      32,    33,    34,    35,    36,    37,    38,     1,   179,    43,
      42,    43,     7,   184,    43,     9,    11,    48,    40,    14,
      34,    35,    36,    37,    38,     7,    20,    -1,    22,    11,
      -1,   165,    46,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    11,    -1,    -1,    42,    43,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    11,    -1,
      42,    43,    15,    11,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    11,    -1,    -1,    46,
      15,    34,    35,    36,    37,    38,    34,    35,    36,    37,
      38,    11,    -1,    46,    -1,    15,    11,    -1,    46,    34,
      35,    36,    37,    38,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    34,
      35,    36,    37,    38,    20,    -1,    29,    30,    31,    -1,
      26,    27,    28,    -1,     1,    -1,     3,     4,     5,    35,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    45,
      17,    18,    -1,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    50,    85,    86,    85,     0,     8,    51,    85,
       9,    60,    52,    61,    10,    65,     1,    20,    22,    53,
      85,    85,    68,     6,    20,    59,    62,    66,    16,    69,
      20,    26,    27,    28,    35,    40,    45,    87,    88,     6,
      15,    14,     1,    21,    63,     1,    21,    67,    25,    45,
      87,    87,    88,    87,    88,     7,    11,    14,    31,    32,
      33,    34,    35,    36,    37,    38,    42,    43,     7,    14,
      29,    30,    31,    87,    88,    20,    59,    56,     7,     7,
      70,    87,    46,    46,    87,    87,    57,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    58,    88,
      88,    88,    14,    14,    86,    42,    42,    44,    86,    86,
      54,    55,    87,    87,    85,    86,    86,    15,    15,     1,
       3,     4,     5,    18,    20,    71,    72,    79,    80,    87,
      24,    45,    45,    45,    45,     6,    17,    71,    19,    82,
      15,    15,    21,    25,    87,    88,    87,    88,    86,    83,
      23,    23,    15,    46,    46,    46,    76,    77,    47,    84,
      43,    43,    87,    78,    75,    81,    85,    86,    85,    64,
      85,    15,    46,    85,    85,    84,    71,    85,    87,    74,
      48,    46,    85,    86,    73,    85
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    54,    53,    55,
      53,    56,    53,    57,    53,    58,    53,    53,    59,    59,
      61,    60,    62,    62,    64,    63,    63,    65,    66,    66,
      67,    67,    68,    68,    70,    69,    71,    71,    73,    72,
      74,    72,    75,    72,    76,    72,    77,    72,    78,    72,
      72,    72,    79,    81,    80,    82,    83,    82,    84,    85,
      85,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     3,     0,     2,     0,     7,     0,
       7,     0,     5,     0,     6,     0,     6,     1,     1,     3,
       0,     4,     0,     2,     0,    11,     1,     3,     0,     2,
      10,     1,     0,     2,     0,     8,     0,     2,     0,    10,
       0,     8,     0,     6,     0,     5,     0,     5,     0,     6,
       1,     1,     2,     0,     6,     0,     0,     3,     5,     1,
       2,     0,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     3,     1,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3
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
  case 2: /* all: saltoOpcional zona_variables zona_recuadros zona_lineas inic_creacion_cuadros_nombre  */
#line 106 "proyecto_mondrian.y"
                                                                                                 {;}
#line 1361 "proyecto_mondrian.c"
    break;

  case 4: /* zona_variables: VARIABLES salto inic_definicion  */
#line 110 "proyecto_mondrian.y"
                                                { /*cout << "VARIABLES"<<endl;*/}
#line 1367 "proyecto_mondrian.c"
    break;

  case 7: /* $@1: %empty  */
#line 117 "proyecto_mondrian.y"
                                                                      { 
                                                                        InformacionSimbolo info, auxComprobacion;
                                                                         if((strcmp((yyvsp[-4].var),"Real") == 0) &&(!(yyvsp[-1].c_expresion).esReal)){
                                                                                    errorS = true;
                                                                                    cout<<"La variable "<< (yyvsp[-3].var) <<" no es tipo real y no se le puede asignar un valor entero, Linea: "<< n_lineas + 1 <<endl;
                                                                                    //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                              }else if((strcmp((yyvsp[-4].var),"Entero") == 0) &&((yyvsp[-1].c_expresion).esReal))
                                                                              {
                                                                                    errorS = true;
                                                                                    cout<<"La variable "<< (yyvsp[-3].var) <<" es de tipo entero y no se le puede asignar un valor real, Linea: "<< n_lineas + 1 <<endl;
                                                                                    //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                              }else if((strcmp((yyvsp[-4].var),"Logico") == 0))
                                                                              {
                                                                                    errorS = true;
                                                                                    cout<<"La variable "<< (yyvsp[-3].var) <<" es de tipo logico y no se le puede asignar un valor entero o real, Linea: "<< n_lineas + 1<<endl;
                                                                              }

                                                                        if(buscarSimbolo(tablaSimbolos, (yyvsp[-3].var), auxComprobacion))
                                                                        {
                                                                           
                                                                              if((strcmp((yyvsp[-4].var),"Entero") == 0) && auxComprobacion.d==Real){
                                                                                    errorS = true;
                                                                                   cout<<"La variable "<< (yyvsp[-3].var) <<" ha sido definida anteriormente como Real  y no se puede volver a declarar como Entero, Linea: "<< n_lineas + 1<<endl;
                                                                                    //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                              }else if((strcmp((yyvsp[-4].var),"Real") == 0) && auxComprobacion.d==Entero)
                                                                              {
                                                                                    errorS = true;
                                                                                    cout<<"La variable "<< (yyvsp[-3].var)<<" ha sido definida anteriormente como Entero y no se puede volver a declarar como Real, Linea: "<< n_lineas + 1<<endl;
                                                                                    //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                              }else if(auxComprobacion.d==Bool)
                                                                              {
                                                                                    cout<<"La variable "<< (yyvsp[-3].var)<<" ha sido definida anteriormente como Logica y no se puede volver a declarar como Real o Entero, Linea: "<< n_lineas + 1<<endl;
                                                                              }
                                                                        }


                                                                         if (!errorS){
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
                                                                        //cout<<"Tipo Identificador";
                                                                        errorS = false;
                                                                  }
#line 1423 "proyecto_mondrian.c"
    break;

  case 9: /* $@2: %empty  */
#line 169 "proyecto_mondrian.y"
                                                                        { 
                                                                        InformacionSimbolo info, auxComprobacion;
                                                                        
                                                                      
                                                                              if((strcmp((yyvsp[-4].var),"Real") == 0)){
                                                                                    errorS = true;
                                                                                    cout<<"A una variable de tipo real no se le puede asignar un valor logico, Linea: "<< n_lineas + 1<<endl;
                                                                                    
                                                                              }else if((strcmp((yyvsp[-4].var),"Entero") == 0) )
                                                                              {
                                                                                    errorS = true;
                                                                                   cout<<"A una variable de tipo entero no se le puede asignar un valor logico, Linea: "<< n_lineas + 1<<endl;
                                                                                   
                                                                              }
                                                                        if(buscarSimbolo(tablaSimbolos, (yyvsp[-3].var), auxComprobacion))
                                                                        {
                                                                              if((auxComprobacion.d == Real)){
                                                                                    errorS = true;
                                                                                   cout<<"La variable "<< (yyvsp[-3].var)<<" ha sido definida anteriormente como Real y no se puede volver a declarar como Logico , Linea: "<< n_lineas + 1<<endl;
                                                                                    
                                                                              }else if(auxComprobacion.d==Entero) 
                                                                              {
                                                                                    errorS = true;
                                                                                  cout<<"La variable "<< (yyvsp[-3].var)<<" ha sido definida anteriormente como Entero y no se puede volver a declarar como Logico, Linea: "<< n_lineas + 1<<endl;
                                                                                   
                                                                              }          
                                                                        }
                                                                         if (!errorS){
                                                                              //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                              InformacionSimbolo info, aux;
                                                                                    info.d = Bool;
                                                                                    info.valor_bool = (yyvsp[-1].c_bool);
                                                                              insertarSimbolo(tablaSimbolos, (yyvsp[-3].var), info);
                                                                        }    
                                                                        //cout<<"Tipo Identificador";
                                                                        errorS = false;
                                                                  }
#line 1465 "proyecto_mondrian.c"
    break;

  case 11: /* $@3: %empty  */
#line 207 "proyecto_mondrian.y"
                                                             {
                                                                  
                                                                  InformacionSimbolo info, tipoSec;
                                                                   if((strcmp((yyvsp[-2].var),"Real") == 0)){
                                                                              info.d = Real;
                                                                              info.valor_float = 0;
                                                                        }else if((strcmp((yyvsp[-2].var),"Entero") == 0))
                                                                        {
                                                                              info.d = Entero;
                                                                              info.valor_int = 0;
                                                                        }else 
                                                                        {
                                                                              info.d = Bool;
                                                                              info.valor_bool = false; //Todos por defecto estan a falso
                                                                              
                                                                        }
                                                                  list<string> l = buscarSimbolosNoIdentificados(tablaSimbolos); 
                                                                  while (!l.empty()) {
                                                                        string aux = l.front();
                                                                        tablaSimbolos[aux] = info;
                                                                        l.pop_front();
                                                                  }     
                                                                 // cout<<"Tipo secuencia_Identificadores ";
                                                            }
#line 1494 "proyecto_mondrian.c"
    break;

  case 13: /* $@4: %empty  */
#line 231 "proyecto_mondrian.y"
                                                                {

                                                                  InformacionSimbolo info, auxComprobacion;
                                                                  if(buscarSimbolo(tablaSimbolos, (yyvsp[-3].var), auxComprobacion))
                                                                  {
                                                                          
                                                                        if((auxComprobacion.d == Real) &&(!(yyvsp[-1].c_expresion).esReal)){
                                                                              errorS = true;
                                                                               cout<<"La variable "<< (yyvsp[-3].var) << " no es tipo real y no se le puede asignar un valor real, Linea: "<< n_lineas + 1<<endl;
                                                                              //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                        }else if((auxComprobacion.d == Entero) &&((yyvsp[-1].c_expresion).esReal))
                                                                        {
                                                                              errorS = true;
                                                                              cout<<"La variable "<< (yyvsp[-3].var) <<" es de tipo real y no se le puede asignar un valor entero, Linea: "<< n_lineas + 1<<endl;
                                                                              //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                        }else if (auxComprobacion.d == Bool)
                                                                        {
                                                                              errorS = true;
                                                                              cout<<"La variable "<< (yyvsp[-3].var) <<" es de tipo logico y no se le puede asignar un valor entero o real, Linea: "<< n_lineas + 1<<endl;
                                                                        }
                                                                  }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                         cout<<"La variable "<< (yyvsp[-3].var)<<" no ha sido definida con anterioridad, Linea: "<< n_lineas + 1<<endl;
                                                                        //cout<<endl<<"ENTRA "<< $1 <<endl;
                                                                        errorS = true;
                                                                  }

                                                                  if (!errorS){ 
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
                                                                        //cout<<"Tipo Identificador";
                                                                         errorS = false;
                                                                  }
#line 1541 "proyecto_mondrian.c"
    break;

  case 15: /* $@5: %empty  */
#line 273 "proyecto_mondrian.y"
                                                                   {

                                                                  InformacionSimbolo info, auxComprobacion;
                                                                  if(buscarSimbolo(tablaSimbolos, (yyvsp[-3].var), auxComprobacion))
                                                                        {
                                                                              if((auxComprobacion.d == Real)){
                                                                                   errorS = true;
                                                                                   cout<<"La variable "<< (yyvsp[-3].var)<<" ha sido definida anteriormente como Real y no se puede volver a declarar como Logico, Linea: "<< n_lineas + 1<<endl;
                                                                                    
                                                                              }else if(auxComprobacion.d==Entero) 
                                                                              {
                                                                                  errorS = true;
                                                                                  cout<<"La variable "<< (yyvsp[-3].var)<<" ha sido definida anteriormente como Entero y no se puede volver a declarar como Logico, Linea: "<< n_lineas + 1<<endl;
                                                                                   
                                                                              }          
                                                                        }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                        cout<<"La variable "<< (yyvsp[-3].var)<<" no ha sido definida con anterioridad, Linea: "<< n_lineas + 1<<endl;
                                                                        //cout<<endl<<"ENTRA "<< $1 <<endl;
                                                                        errorS = true;
                                                                  }

                                                                  if (!errorS){ 
                                                                  //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                        InformacionSimbolo info, aux;
                                                                        info.d=Bool;
                                                                        info.valor_bool = (yyvsp[-1].c_bool);
                                                                        insertarSimbolo(tablaSimbolos, (yyvsp[-3].var), info);
                                                                        }    
                                                                        //cout<<"Tipo Identificador";
                                                                         errorS = false;
                                                                  }
#line 1578 "proyecto_mondrian.c"
    break;

  case 17: /* definicion: error  */
#line 305 "proyecto_mondrian.y"
                     {}
#line 1584 "proyecto_mondrian.c"
    break;

  case 18: /* secuencia_de_Identificadores: IDENTIFICADORMINUSCULA  */
#line 308 "proyecto_mondrian.y"
                                                       {
                                                                  
                                                                  InformacionSimbolo info;

                                                                  if(!buscarSimbolo(tablaSimbolos, (yyvsp[0].var), info))
                                                                  {
                                                                        info.d=NoIdentificado;
                                                                        insertarSimbolo(tablaSimbolos, (yyvsp[0].var), info);
                                                                  }else
                                                                  {
                                                                        cout<<"La variable "<< (yyvsp[0].var) << " ha sido definida anteriormente y no puede volver a ser definida, Linea: "<< n_lineas + 1<<endl;
                                                                  }
                                                                  //cout<<"Identificador PuntYComa ";
                                                      }
#line 1603 "proyecto_mondrian.c"
    break;

  case 19: /* secuencia_de_Identificadores: IDENTIFICADORMINUSCULA COMA secuencia_de_Identificadores  */
#line 322 "proyecto_mondrian.y"
                                                                                         {
                                                                                          InformacionSimbolo info;
                                                                                         if(!buscarSimbolo(tablaSimbolos, (yyvsp[-2].var), info))
                                                                                          {
                                                                                                info.d=NoIdentificado;
                                                                                                insertarSimbolo(tablaSimbolos, (yyvsp[-2].var), info);
                                                                                          }else
                                                                                          {
                                                                                                  cout<<"La variable "<< (yyvsp[-2].var) << " ha sido definida anteriormente y no puede volver a ser definida, Linea: "<< n_lineas + 1<<endl;
                                                                                          }
                                                                                          //cout<<"Identificador  ";
                                                                                          }
#line 1620 "proyecto_mondrian.c"
    break;

  case 20: /* $@6: %empty  */
#line 339 "proyecto_mondrian.y"
                           {}
#line 1626 "proyecto_mondrian.c"
    break;

  case 21: /* zona_recuadros: RECUADROS $@6 salto inic_definicion_recuadro  */
#line 339 "proyecto_mondrian.y"
                                                               {/*cout<<"RECUADROS"<<endl;*/}
#line 1632 "proyecto_mondrian.c"
    break;

  case 24: /* $@7: %empty  */
#line 344 "proyecto_mondrian.y"
                                                                                          { 
                                                                                          errorS = false;
                                                                                          InformacionSimbolo info, auxComprobacion; 
                                                                                          if((yyvsp[-5].c_expresion).esReal | (yyvsp[-3].c_expresion).esReal){  
                                                                                                errorS = true;
                                                                                                //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                                                cout<<"La creaciøn de un recuadro necesita dos operandos enteros, Linea: "<< n_lineas + 1<<endl;
                                                                                          }
                                                                                          if (!errorS){ 
                                                                                                //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 

                                                                                                InformacionSimbolo info;
                                                                                                info.d = Recuadro;
                                                                                                info.valores_recuadro.alto = (yyvsp[-5].c_expresion).valor;
                                                                                                info.valores_recuadro.ancho = (yyvsp[-3].c_expresion).valor;
                                                                                                info.valores_recuadro.color = color((yyvsp[-1].var));
                                                                                                insertarSimbolo(tablaSimbolosRecuadros, (yyvsp[-8].var), info);
                                                                                          }    
                                                                                          errorS = false;
                                                                                    
                                                                                          //fprintf(yyout,"\t %s = <%d, %d, %s>",$1,(int)$4.valor,(int)$6.valor,$8);  
                                                                                          //cout << "Identificador_mayuscula = < Entero, Entero, Color>"<<endl;
                                                                                          }
#line 1660 "proyecto_mondrian.c"
    break;

  case 26: /* definicion_recuadro: error  */
#line 367 "proyecto_mondrian.y"
                            {}
#line 1666 "proyecto_mondrian.c"
    break;

  case 27: /* zona_lineas: LINEAS salto inic_definicion_linea  */
#line 374 "proyecto_mondrian.y"
                                                  {/*cout << "LINEAS"<<endl;*/}
#line 1672 "proyecto_mondrian.c"
    break;

  case 29: /* inic_definicion_linea: inic_definicion_linea definicion_linea  */
#line 378 "proyecto_mondrian.y"
                                                                {}
#line 1678 "proyecto_mondrian.c"
    break;

  case 30: /* definicion_linea: IDENTIFICADORMAYUSCULA IGUAL '<' expr COMA ORIENTACION COMA COLOR '>' salto  */
#line 383 "proyecto_mondrian.y"
                                                                                                   {
                                                                                                errorS = false;
                                                                                                InformacionSimbolo info, auxComprobacion; 
                                                                                                if((yyvsp[-6].c_expresion).esReal){  
                                                                                                      errorS = true;
                                                                                                      //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                                                }
                                                                                                if (!errorS){ 
                                                                                                      //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl;          
                                                                                                      InformacionSimbolo info;
                                                                                                      info.d = Linea;
                                                                                                      info.valores_linea.grosor = (yyvsp[-6].c_expresion).valor;
                                                                                                      info.valores_linea.esHorizontal = (strcmp((yyvsp[-4].var),"horizontal")==0)? true : false  ;
                                                                                                      info.valores_linea.color =  color((yyvsp[-2].var));
                                                                                                      insertarSimbolo(tablaSimbolosLineas, (yyvsp[-9].var), info);
                                                                                                }    
                                                                                                errorS = false; 
                                                                                                //fprintf(yyout,"\t %s = <%d, %s, %s>",$1,(int)$4.valor,$6,$8);   
                                                                                                //cout << "\t Identificador_mayuscula = < Entero, Orientacion, Color>"<<endl;
                                                                                                                              
                                                                                                }
#line 1704 "proyecto_mondrian.c"
    break;

  case 31: /* definicion_linea: error  */
#line 404 "proyecto_mondrian.y"
                      {}
#line 1710 "proyecto_mondrian.c"
    break;

  case 33: /* inic_creacion_cuadros_nombre: inic_creacion_cuadros_nombre creacion_cuadros_nombre  */
#line 410 "proyecto_mondrian.y"
                                                                                {}
#line 1716 "proyecto_mondrian.c"
    break;

  case 34: /* $@8: %empty  */
#line 412 "proyecto_mondrian.y"
                                         {fprintf(yyout,"\t nuevoCuadroM(%s); \n ",(yyvsp[0].text));}
#line 1722 "proyecto_mondrian.c"
    break;

  case 35: /* creacion_cuadros_nombre: CUADRO CADENA $@8 ':' salto inic_acciones_cuadros FINCUADRO saltoOpcional  */
#line 412 "proyecto_mondrian.y"
                                                                                                                                                   { /* cout<<"Cuadro NombreCuadro :"<<endl; */ }
#line 1728 "proyecto_mondrian.c"
    break;

  case 37: /* inic_acciones_cuadros: acciones_cuadros inic_acciones_cuadros  */
#line 415 "proyecto_mondrian.y"
                                                                  {}
#line 1734 "proyecto_mondrian.c"
    break;

  case 38: /* $@9: %empty  */
#line 418 "proyecto_mondrian.y"
                                                                             {
                                                                         if(condicionalVerdadero){
                                                                              if(!(yyvsp[-3].c_expresion).esReal && !(yyvsp[-1].c_expresion).esReal){  
                                                                                    InformacionSimbolo info;
                                                                                    int filaRecuadro =(yyvsp[-3].c_expresion).valor ,columnaRecuadro=(yyvsp[-1].c_expresion).valor,altoRecuadro=0,anchoRecuadro=0, color=0;
                                                                                    if(buscarSimbolo(tablaSimbolosRecuadros,(yyvsp[-5].var),info))
                                                                                    {     
                                                                                          altoRecuadro = info.valores_recuadro.alto;
                                                                                          anchoRecuadro = info.valores_recuadro.ancho;
                                                                                          color = info.valores_recuadro.color; 
                                                                                    }else
                                                                                    {
                                                                                          errorS = true;
                                                                                          cout<<"El recuadro indicado no ha sido creado con anterioridad, Linea: "<< n_lineas + 1<<endl;
                                                                                    }
                                                                                    if(!errorS)
                                                                                          fprintf(yyout,"\t rectanguloM(%d, %d, %d, %d, %d); \n",filaRecuadro,columnaRecuadro,altoRecuadro,anchoRecuadro,color); 
                                                                              }else
                                                                              {
                                                                                    cout<<"El valor introducido es real y la funcion pintar precisa de dos valores enteros, Linea: "<< n_lineas + 1<<endl;
                                                                              }                                                                         
                                                                              
                                                                              //cout<<"Pintar (Identificador_mayuscula, Expr,Expr)"<<endl;
                                                                        
                                                                        
                                                                        }
                                                                        }
#line 1766 "proyecto_mondrian.c"
    break;

  case 40: /* $@10: %empty  */
#line 445 "proyecto_mondrian.y"
                                                                    {
                                                                  if(condicionalVerdadero){
                                                                        if(!(yyvsp[-1].c_expresion).esReal){  
                                                                              InformacionSimbolo info;
                                                                              int origen=(yyvsp[-1].c_expresion).valor,grosor=0, color;
                                                                              bool esHorizontal;
                                                                             
                                                                              if(buscarSimbolo(tablaSimbolosLineas,(yyvsp[-3].var),info))
                                                                              {     
                                                                                    grosor = info.valores_linea.grosor;
                                                                                    esHorizontal = info.valores_linea.esHorizontal;
                                                                                    color = info.valores_linea.color; 
                                                                                    fprintf(yyout,"\t lineaM(%d, %d, %s, %d); \n",origen,info.valores_linea.grosor,(esHorizontal)? "true" : "false",color); 
                                                                              }else{
                                                                                                errorS = true;
                                                                                                cout<<"El recuadro indicado no ha sido creado con anterioridad, Linea: "<< n_lineas + 1<<endl;
                                                                              }
                                                                                    
                                                                             
                                                                        }else
                                                                        {
                                                                              cout<<"El valor introducido es real y la funcion pintar precisa de un valor entero, Linea: "<< n_lineas + 1<<endl;
                                                                        }                                                                             
                                                                              
                                                                  }     
                                                                        //cout<<"Pintar (Identificador_mayuscula, Expr)"<<endl;
                                                                  }
#line 1798 "proyecto_mondrian.c"
    break;

  case 42: /* $@11: %empty  */
#line 473 "proyecto_mondrian.y"
                                      {
                                    if(condicionalVerdadero && !errorS){
                                         
                                                fprintf(yyout,"\t pausaM(%.2f); \n",(yyvsp[-1].c_expresion).valor); 
                                         // cout<<"Pausa (expr)"<<endl;
                                    }
                                    errorS = false;
                                    }
#line 1811 "proyecto_mondrian.c"
    break;

  case 44: /* $@12: %empty  */
#line 481 "proyecto_mondrian.y"
                                                          { 

                                                            if(condicionalVerdadero){
                                                                  errorS = false;
                                                                  
                                                                  InformacionSimbolo info, auxComprobacion;
                                                                  if(buscarSimbolo(tablaSimbolos, (yyvsp[-2].var), auxComprobacion))
                                                                  {
                                                                          
                                                                        if((auxComprobacion.d == Real) &&(!(yyvsp[0].c_expresion).esReal)){
                                                                              errorS = true;
                                                                               cout<<"La variable "<< (yyvsp[-2].var) << " no es tipo real y no se le puede asignar un valor real, Linea: "<< n_lineas + 1<<endl;
                                                                              //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                        }else if((auxComprobacion.d == Entero) &&((yyvsp[0].c_expresion).esReal))
                                                                        {
                                                                              errorS = true;
                                                                              cout<<"La variable "<< (yyvsp[-2].var) <<" es de tipo real y no se le puede asignar un valor entero, Linea: "<< n_lineas + 1<<endl;
                                                                              //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                        }else if (auxComprobacion.d == Bool)
                                                                        {
                                                                              errorS = true;
                                                                              cout<<"La variable "<< (yyvsp[-2].var) <<" es de tipo logico y no se le puede asignar un valor entero o real, Linea: "<< n_lineas + 1<<endl;
                                                                        }
                                                                  }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                        cout<<"La variable "<< (yyvsp[-2].var)<<" no ha sido definida con anterioridad, Linea: "<< n_lineas + 1<<endl;
                                                                        //cout<<endl<<"ENTRA "<< $1 <<endl;
                                                                        errorS = true;
                                                                  }

                                                                  if (!errorS){ 
                                                                        //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                  
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
                                                                  errorS = false;
                                                            }
                                                          }
#line 1862 "proyecto_mondrian.c"
    break;

  case 46: /* $@13: %empty  */
#line 528 "proyecto_mondrian.y"
                                                              {
                                                             if(condicionalVerdadero){
                                                                  errorS = false;
                                                                  
                                                                  InformacionSimbolo info, auxComprobacion;
                                                                  if(buscarSimbolo(tablaSimbolos, (yyvsp[-2].var), auxComprobacion))
                                                                        {
                                                                              if((auxComprobacion.d == Real)){
                                                                                   errorS = true;
                                                                                   cout<<"La variable "<< (yyvsp[-2].var)<<" ha sido definida anteriormente como Real y no se puede volver a declarar como Logico , Linea: "<< n_lineas + 1<<endl;
                                                                                    
                                                                              }else if(auxComprobacion.d==Entero) 
                                                                              {
                                                                                  errorS = true;
                                                                                  cout<<"La variable "<< (yyvsp[-2].var)<<" ha sido definida anteriormente como Entero y no se puede volver a declarar como Logico, Linea: "<< n_lineas + 1<<endl;
                                                                                   
                                                                              }          
                                                                        }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                        cout<<"La variable "<< (yyvsp[-2].var)<<" no ha sido definida con anterioridad, Linea: "<< n_lineas + 1<<endl;
                                                                        //cout<<endl<<"ENTRA "<< $1 <<endl;
                                                                        errorS = true;
                                                                  }

                                                                  if (!errorS){ 
                                                                  //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                        InformacionSimbolo info, aux;
                                                                        info.d=Bool;
                                                                        info.valor_bool = (yyvsp[0].c_bool);
                                                                        insertarSimbolo(tablaSimbolos, (yyvsp[-2].var), info);
                                                                        }    
                                                                        //cout<<"Tipo Identificador";
                                                                         errorS = false;
                                                             }
                                                                  }
#line 1902 "proyecto_mondrian.c"
    break;

  case 48: /* $@14: %empty  */
#line 563 "proyecto_mondrian.y"
                                         { 
                                           if(condicionalVerdadero && !errorS){
                                                fprintf(yyout,"\t // %s \n",(yyvsp[-1].text)); 
                                           }
                                          errorS = false;
                                          }
#line 1913 "proyecto_mondrian.c"
    break;

  case 51: /* acciones_cuadros: error  */
#line 570 "proyecto_mondrian.y"
                         {}
#line 1919 "proyecto_mondrian.c"
    break;

  case 52: /* condicional: parteSi parteSiNo  */
#line 572 "proyecto_mondrian.y"
                                 {condicionalVerdadero=true;}
#line 1925 "proyecto_mondrian.c"
    break;

  case 53: /* $@15: %empty  */
#line 575 "proyecto_mondrian.y"
                            {condicionalVerdadero=(yyvsp[-1].c_bool) ; cout <<endl<< condicionalVerdadero<<endl;}
#line 1931 "proyecto_mondrian.c"
    break;

  case 56: /* $@16: %empty  */
#line 579 "proyecto_mondrian.y"
              {condicionalVerdadero = !condicionalVerdadero; }
#line 1937 "proyecto_mondrian.c"
    break;

  case 59: /* salto: SALTOLINEA  */
#line 583 "proyecto_mondrian.y"
                   {}
#line 1943 "proyecto_mondrian.c"
    break;

  case 60: /* salto: SALTOLINEA salto  */
#line 584 "proyecto_mondrian.y"
                          {}
#line 1949 "proyecto_mondrian.c"
    break;

  case 62: /* saltoOpcional: salto  */
#line 588 "proyecto_mondrian.y"
                {}
#line 1955 "proyecto_mondrian.c"
    break;

  case 63: /* expr: ENTERO  */
#line 591 "proyecto_mondrian.y"
                           {(yyval.c_expresion).valor= (yyvsp[0].c_entero); (yyval.c_expresion).esReal = false;}
#line 1961 "proyecto_mondrian.c"
    break;

  case 64: /* expr: REAL  */
#line 592 "proyecto_mondrian.y"
                                 {(yyval.c_expresion).esReal = true ; (yyval.c_expresion).valor = (yyvsp[0].c_real);}
#line 1967 "proyecto_mondrian.c"
    break;

  case 65: /* expr: IDENTIFICADORMINUSCULA  */
#line 593 "proyecto_mondrian.y"
                             {
                              InformacionSimbolo info;
                              if(buscarSimbolo(tablaSimbolos, (yyvsp[0].var), info)){
                                    if(info.d == 0){// si es real
                                          (yyval.c_expresion).valor = info.valor_float;
                                          (yyval.c_expresion).esReal = true;
                                    } else if(info.d == 1){ // es entero
                                          (yyval.c_expresion).valor = info.valor_int;
                                          (yyval.c_expresion).esReal = false;
                                    } else if (info.d = NoIdentificado){
                                          errorS = true;
                                          cout << "Error semantico en la instruccion "<< n_lineas+1 << ", no se pueden utilizar variables sin valor asignado, Linea: "<< n_lineas + 1<<endl;
                                    }  else{
                                          errorS = true;
                                          cout << "Error semantico en la instruccion "<< n_lineas+1 << ", no se pueden usar variables de tipo logico a la derecha de una asignacion, Linea: "<< n_lineas + 1<<endl;
                                    }      
                              }else{
                                    errorS = true;
                                    cout << "Error en la instruccion "<< n_lineas+1 << ", la variable utilizada '"<< (yyvsp[0].var) << "' no existe, Linea: "<< n_lineas + 1<<endl;
                              }
                              }
#line 1993 "proyecto_mondrian.c"
    break;

  case 66: /* expr: expr '+' expr  */
#line 614 "proyecto_mondrian.y"
                           {(yyval.c_expresion).valor = (yyvsp[-2].c_expresion).valor + (yyvsp[0].c_expresion).valor;  (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal ;}
#line 1999 "proyecto_mondrian.c"
    break;

  case 67: /* expr: expr '-' expr  */
#line 615 "proyecto_mondrian.y"
                           {(yyval.c_expresion).valor = (yyvsp[-2].c_expresion).valor - (yyvsp[0].c_expresion).valor; (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal ;}
#line 2005 "proyecto_mondrian.c"
    break;

  case 68: /* expr: expr '*' expr  */
#line 616 "proyecto_mondrian.y"
                           {(yyval.c_expresion).valor = (float) (yyvsp[-2].c_expresion).valor * (float) (yyvsp[0].c_expresion).valor; (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal ;}
#line 2011 "proyecto_mondrian.c"
    break;

  case 69: /* expr: expr '/' expr  */
#line 617 "proyecto_mondrian.y"
                           { 
                              (yyval.c_expresion).esReal = true;
                              if((yyvsp[0].c_expresion).valor != 0){
                                    (yyval.c_expresion).valor =  (float)(yyvsp[-2].c_expresion).valor / (float)(yyvsp[0].c_expresion).valor;
                              }else{
                                    errorS = true;
                                    cout << "Error semantico en la instruccion " << n_lineas+1 << ", division por cero, Linea: "<< n_lineas + 1<<endl;
                              }
                              
                        }
#line 2026 "proyecto_mondrian.c"
    break;

  case 70: /* expr: expr DIV expr  */
#line 627 "proyecto_mondrian.y"
                            { 
                              (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal;
                              if((yyvsp[0].c_expresion).valor != 0){
                                    if((yyval.c_expresion).esReal) {
                                          errorS = true;
                                          cout << "errorS semantico en la instruccion " << n_lineas+1 << ", ambos operandos deben ser enteros, Linea: "<< n_lineas + 1<<endl;
                                     } else
                                          (yyval.c_expresion).valor =  (int) (yyvsp[-2].c_expresion).valor / (int) (yyvsp[0].c_expresion).valor;
                              }else{
                                    errorS = true;
                                    cout << "errorS semantico en la instruccion " << n_lineas+1 << ", division por cero, Linea: "<< n_lineas + 1<<endl;
                              }
                              
                        }
#line 2045 "proyecto_mondrian.c"
    break;

  case 71: /* expr: expr '%' expr  */
#line 642 "proyecto_mondrian.y"
                        {
                        (yyval.c_expresion).esReal = (yyvsp[-2].c_expresion).esReal || (yyvsp[0].c_expresion).esReal;
                              if((yyvsp[0].c_expresion).valor != 0){
                                    if((yyval.c_expresion).esReal){
                                          errorS = true;
                                          cout << "errorS semantico en la instruccion " << n_lineas+1 << ", ambos operandos deben ser enteros, Linea: "<< n_lineas + 1<<endl;
                                    }else
                                          (yyval.c_expresion).valor =  (int) (yyvsp[-2].c_expresion).valor % (int) (yyvsp[0].c_expresion).valor;
                              }else{ 
                                    errorS = true;
                                    cout << "errorS semantico en la instruccion " << n_lineas+1 << ", division por cero, Linea: "<< n_lineas + 1<<endl;
                              }
    }
#line 2063 "proyecto_mondrian.c"
    break;

  case 72: /* expr: '-' expr  */
#line 655 "proyecto_mondrian.y"
                           {(yyval.c_expresion).valor = - ((yyvsp[0].c_expresion).valor);  (yyval.c_expresion).esReal = (yyvsp[0].c_expresion).esReal;}
#line 2069 "proyecto_mondrian.c"
    break;

  case 73: /* expr: '(' expr ')'  */
#line 656 "proyecto_mondrian.y"
                           {(yyval.c_expresion).valor = (yyvsp[-1].c_expresion).valor; (yyval.c_expresion).esReal = (yyvsp[-1].c_expresion).esReal;}
#line 2075 "proyecto_mondrian.c"
    break;

  case 74: /* logica: BOOL  */
#line 659 "proyecto_mondrian.y"
             {(yyval.c_bool) = (yyvsp[0].c_bool);}
#line 2081 "proyecto_mondrian.c"
    break;

  case 75: /* logica: logica AND logica  */
#line 660 "proyecto_mondrian.y"
                          {(yyval.c_bool) = (yyvsp[-2].c_bool) && (yyvsp[0].c_bool);}
#line 2087 "proyecto_mondrian.c"
    break;

  case 76: /* logica: logica OR logica  */
#line 661 "proyecto_mondrian.y"
                         {(yyval.c_bool) = (yyvsp[-2].c_bool) || (yyvsp[0].c_bool);}
#line 2093 "proyecto_mondrian.c"
    break;

  case 77: /* logica: NOT logica  */
#line 662 "proyecto_mondrian.y"
                   {(yyval.c_bool) = ! ((yyvsp[0].c_bool));}
#line 2099 "proyecto_mondrian.c"
    break;

  case 78: /* logica: expr DISTINTO expr  */
#line 663 "proyecto_mondrian.y"
                           {(yyval.c_bool) = ((yyvsp[-2].c_expresion).valor != (yyvsp[0].c_expresion).valor);}
#line 2105 "proyecto_mondrian.c"
    break;

  case 79: /* logica: logica DISTINTO logica  */
#line 664 "proyecto_mondrian.y"
                               {(yyval.c_bool) = ((yyvsp[-2].c_bool) != (yyvsp[0].c_bool));}
#line 2111 "proyecto_mondrian.c"
    break;

  case 80: /* logica: expr IGUAL expr  */
#line 665 "proyecto_mondrian.y"
                        {(yyval.c_bool) =  ((yyvsp[-2].c_expresion).valor == (yyvsp[0].c_expresion).valor);}
#line 2117 "proyecto_mondrian.c"
    break;

  case 81: /* logica: logica IGUAL logica  */
#line 666 "proyecto_mondrian.y"
                            {(yyval.c_bool) =  ((yyvsp[-2].c_bool) == (yyvsp[0].c_bool));}
#line 2123 "proyecto_mondrian.c"
    break;

  case 82: /* logica: expr MENORIGUAL expr  */
#line 667 "proyecto_mondrian.y"
                             {(yyval.c_bool) =  ((yyvsp[-2].c_expresion).valor <= (yyvsp[0].c_expresion).valor);}
#line 2129 "proyecto_mondrian.c"
    break;

  case 83: /* logica: expr '>' expr  */
#line 668 "proyecto_mondrian.y"
                      {(yyval.c_bool) =  ((yyvsp[-2].c_expresion).valor > (yyvsp[0].c_expresion).valor);}
#line 2135 "proyecto_mondrian.c"
    break;

  case 84: /* logica: expr MAYORIGUAL expr  */
#line 669 "proyecto_mondrian.y"
                             {(yyval.c_bool) =  ((yyvsp[-2].c_expresion).valor >= (yyvsp[0].c_expresion).valor);}
#line 2141 "proyecto_mondrian.c"
    break;

  case 85: /* logica: expr '<' expr  */
#line 670 "proyecto_mondrian.y"
                      {(yyval.c_bool) =  ((yyvsp[-2].c_expresion).valor < (yyvsp[0].c_expresion).valor);}
#line 2147 "proyecto_mondrian.c"
    break;

  case 86: /* logica: '(' logica ')'  */
#line 671 "proyecto_mondrian.y"
                        {(yyval.c_bool) =  (yyvsp[-1].c_bool);}
#line 2153 "proyecto_mondrian.c"
    break;


#line 2157 "proyecto_mondrian.c"

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

#line 674 "proyecto_mondrian.y"


int main(int argc, char **argv){
      
      n_lineas = 0;
      yyin = fopen(argv[1],"rt");

      char ficheroSalida[100];
      strcpy(ficheroSalida,argv[1]);
      strcpy(ficheroSalida + strlen(ficheroSalida) -4,".cpp");
      yyout = fopen(ficheroSalida ,"wt");
      fprintf(yyout,"#include \"mondrian.h\" \n");
      fprintf(yyout,"#include <allegro5/allegro5.h> \n");
      fprintf(yyout,"using namespace std; \n");
      fprintf(yyout,"int main(int argc, char **argv){ \n \n");
      
      fprintf(yyout,"\t// Se inicia el entorno gráfico\n");
      fprintf(yyout,"\tiniciarM();\n");
      using namespace std;
      yyparse();
     
      fprintf(yyout,"\t// Se liberan los recursos del entorno gráfico\n");
      fprintf(yyout,"\tterminarM();\n");
      fprintf(yyout,"\n}\n");

      //Descomentar para mostrar los maps de Variables, 
     fprintf(yyout,"\n // Tabla de Simbolos\n");
     mostrarTabla(tablaSimbolos, yyout);
     fprintf(yyout,"\n // Tabla de Simbolos Recuadros \n");
     mostrarTabla(tablaSimbolosRecuadros, yyout);
     fprintf(yyout,"\n // Tabla de Simbolo de Lineas \n");
     mostrarTabla(tablaSimbolosLineas, yyout);
      
      
      fclose(yyout);
      fclose(yyin);
     return 0;
}
