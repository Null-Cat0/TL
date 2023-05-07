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
    COMENTARIO = 261,              /* COMENTARIO  */
    ASIGNACION = 262,              /* ASIGNACION  */
    IGUAL = 263,                   /* IGUAL  */
    VARIABLES = 264,               /* VARIABLES  */
    RECUADROS = 265,               /* RECUADROS  */
    COLOR = 266,                   /* COLOR  */
    LINEAS = 267,                  /* LINEAS  */
    ORIENTACION = 268,             /* ORIENTACION  */
    DIV = 269,                     /* DIV  */
    MENOS = 270,                   /* MENOS  */
    SALTOLINEA = 271,              /* SALTOLINEA  */
    PUNTOYCOMA = 272,              /* PUNTOYCOMA  */
    TIPO = 273,                    /* TIPO  */
    COMA = 274,                    /* COMA  */
    CUADRO = 275,                  /* CUADRO  */
    FINCUADRO = 276,               /* FINCUADRO  */
    ENTERO = 277,                  /* ENTERO  */
    IDENTIFICADORMINUSCULA = 278,  /* IDENTIFICADORMINUSCULA  */
    IDENTIFICADORMAYUSCULA = 279,  /* IDENTIFICADORMAYUSCULA  */
    CADENA = 280,                  /* CADENA  */
    REAL = 281,                    /* REAL  */
    BOOL = 282,                    /* BOOL  */
    OR = 283,                      /* OR  */
    AND = 284,                     /* AND  */
    DISTINTO = 285,                /* DISTINTO  */
    MENOR = 286,                   /* MENOR  */
    MENORIGUAL = 287,              /* MENORIGUAL  */
    MAYORIGUAL = 288,              /* MAYORIGUAL  */
    MAYOR = 289,                   /* MAYOR  */
    menos = 290,                   /* menos  */
    NOT = 291                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "mondrian.y"

  int c_entero;
  char var[25];
  float c_real;
  bool c_bool;
  struct {
      float valor;
      bool esReal;
      bool esLogica;
      } c_expresion;

#line 112 "mondrian.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MONDRIAN_H_INCLUDED  */