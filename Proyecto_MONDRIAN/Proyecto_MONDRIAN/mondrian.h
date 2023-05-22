/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MONDRIAN_H_INCLUDED
# define YY_YY_MONDRIAN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PINTAR = 258,                  /* PINTAR  */
    MENSAJE = 259,                 /* MENSAJE  */
    PAUSA = 260,                   /* PAUSA  */
    ASIGNACION = 261,              /* ASIGNACION  */
    IGUAL = 262,                   /* IGUAL  */
    VARIABLES = 263,               /* VARIABLES  */
    RECUADROS = 264,               /* RECUADROS  */
    LINEAS = 265,                  /* LINEAS  */
    DIV = 266,                     /* DIV  */
    MENOS = 267,                   /* MENOS  */
    SALTOLINEA = 268,              /* SALTOLINEA  */
    PUNTOYCOMA = 269,              /* PUNTOYCOMA  */
    COMA = 270,                    /* COMA  */
    CUADRO = 271,                  /* CUADRO  */
    FINCUADRO = 272,               /* FINCUADRO  */
    SI = 273,                      /* SI  */
    SINO = 274,                    /* SINO  */
    IDENTIFICADORMINUSCULA = 275,  /* IDENTIFICADORMINUSCULA  */
    IDENTIFICADORMAYUSCULA = 276,  /* IDENTIFICADORMAYUSCULA  */
    CADENA = 277,                  /* CADENA  */
    TIPO = 278,                    /* TIPO  */
    COLOR = 279,                   /* COLOR  */
    ORIENTACION = 280,             /* ORIENTACION  */
    ENTERO = 281,                  /* ENTERO  */
    REAL = 282,                    /* REAL  */
    BOOL = 283,                    /* BOOL  */
    OR = 284,                      /* OR  */
    AND = 285,                     /* AND  */
    DISTINTO = 286,                /* DISTINTO  */
    MENOR = 287,                   /* MENOR  */
    MENORIGUAL = 288,              /* MENORIGUAL  */
    MAYORIGUAL = 289,              /* MAYORIGUAL  */
    MAYOR = 290,                   /* MAYOR  */
    menos = 291,                   /* menos  */
    NOT = 292,                     /* NOT  */
    IF = 293                       /* IF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "mondrian.y"

  int c_entero;
  char var[25];
  float c_real;
  bool c_bool;
  struct {
      float valor;
      bool esReal;
      bool esLogica;
      } c_expresion;

#line 114 "mondrian.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MONDRIAN_H_INCLUDED  */
