/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
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

// Take the name prefix into account.
#define yylex   dictionary_textlex

/* First part of user declarations.  */
/* Line 279 of lalr1.cc  */
#line 1 "bisonDictionaryTextParser.y"

	#include "base\usdsDictionary.h"
	#include "flexDictionaryTextScanner.h"
	#include <string>
	

/* Line 279 of lalr1.cc  */
#line 47 "bisonDictionaryTextParser.cc"


#include "bisonDictionaryTextParser.hh"

/* User implementation prologue.  */
/* Line 285 of lalr1.cc  */
#line 62 "bisonDictionaryTextParser.y"

#undef yylex
#define yylex scanner->scan

/* Line 285 of lalr1.cc  */
#line 60 "bisonDictionaryTextParser.cc"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if DICTIONARY_TEXTDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !DICTIONARY_TEXTDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !DICTIONARY_TEXTDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

/* Line 353 of lalr1.cc  */
#line 13 "bisonDictionaryTextParser.y"
namespace usds {
/* Line 353 of lalr1.cc  */
#line 156 "bisonDictionaryTextParser.cc"

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  BisonDictionaryTextParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  BisonDictionaryTextParser::BisonDictionaryTextParser (class Dictionary* dict_yyarg, class FlexDictionaryTextScanner* scanner_yyarg, std::stringstream* error_message_yyarg)
    :
#if DICTIONARY_TEXTDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      dict (dict_yyarg),
      scanner (scanner_yyarg),
      error_message (error_message_yyarg)
  {
  }

  BisonDictionaryTextParser::~BisonDictionaryTextParser ()
  {
  }

#if DICTIONARY_TEXTDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  BisonDictionaryTextParser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  BisonDictionaryTextParser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  BisonDictionaryTextParser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 16: /* "string" */
/* Line 455 of lalr1.cc  */
#line 53 "bisonDictionaryTextParser.y"
        { delete [] ((*yyvaluep).stringVal); };
/* Line 455 of lalr1.cc  */
#line 265 "bisonDictionaryTextParser.cc"
        break;

	default:
	  break;
      }
  }

  void
  BisonDictionaryTextParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if DICTIONARY_TEXTDEBUG
  std::ostream&
  BisonDictionaryTextParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  BisonDictionaryTextParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  BisonDictionaryTextParser::debug_level_type
  BisonDictionaryTextParser::debug_level () const
  {
    return yydebug_;
  }

  void
  BisonDictionaryTextParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  BisonDictionaryTextParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  BisonDictionaryTextParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  BisonDictionaryTextParser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval, &yylloc);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:
/* Line 670 of lalr1.cc  */
#line 72 "bisonDictionaryTextParser.y"
    {
		std::cout << "DictID = " << (yysemantic_stack_[(10) - (3)].intVal) << " Major = " << (yysemantic_stack_[(10) - (5)].intVal) << " Minor = " << (yysemantic_stack_[(10) - (7)].intVal) << "\n";
		dict->setID((yysemantic_stack_[(10) - (3)].intVal), (yysemantic_stack_[(10) - (5)].intVal), (yysemantic_stack_[(10) - (7)].intVal));
	}
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 82 "bisonDictionaryTextParser.y"
    {
		dict->addStructTag((yysemantic_stack_[(8) - (4)].stringVal), (yysemantic_stack_[(8) - (1)].intVal), false);
		delete [] (yysemantic_stack_[(8) - (4)].stringVal);
	}
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 87 "bisonDictionaryTextParser.y"
    {
		dict->addStructTag((yysemantic_stack_[(9) - (5)].stringVal), (yysemantic_stack_[(9) - (1)].intVal), true);
		delete [] (yysemantic_stack_[(9) - (5)].stringVal);
	}
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 102 "bisonDictionaryTextParser.y"
    {
		(yyval.fieldVal) = dict->addBooleanField((yysemantic_stack_[(5) - (4)].stringVal), (yysemantic_stack_[(5) - (1)].intVal), false);
		delete [] (yysemantic_stack_[(5) - (4)].stringVal);
	}
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 110 "bisonDictionaryTextParser.y"
    {
		(yyval.fieldVal) = dict->addIntField((yysemantic_stack_[(5) - (4)].stringVal), (yysemantic_stack_[(5) - (1)].intVal), false);
		delete [] (yysemantic_stack_[(5) - (4)].stringVal);
	}
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 118 "bisonDictionaryTextParser.y"
    {
		(yyval.fieldVal) = dict->addLongField((yysemantic_stack_[(5) - (4)].stringVal), (yysemantic_stack_[(5) - (1)].intVal), false);
		delete [] (yysemantic_stack_[(5) - (4)].stringVal);
	}
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 126 "bisonDictionaryTextParser.y"
    {
		(yyval.fieldVal) = dict->addDoubleField((yysemantic_stack_[(5) - (4)].stringVal), (yysemantic_stack_[(5) - (1)].intVal), false);
		delete [] (yysemantic_stack_[(5) - (4)].stringVal);
	}
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 134 "bisonDictionaryTextParser.y"
    {
		(yyval.fieldVal) = dict->addUVarintField((yysemantic_stack_[(5) - (4)].stringVal), (yysemantic_stack_[(5) - (1)].intVal), false);
		delete [] (yysemantic_stack_[(5) - (4)].stringVal);
	}
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 142 "bisonDictionaryTextParser.y"
    {
		(yyval.fieldVal) = dict->addArrayField((yysemantic_stack_[(8) - (7)].stringVal), (yysemantic_stack_[(8) - (1)].intVal), false, (yysemantic_stack_[(8) - (5)].stringVal));
		delete [] (yysemantic_stack_[(8) - (5)].stringVal);
		delete [] (yysemantic_stack_[(8) - (7)].stringVal);
	}
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 151 "bisonDictionaryTextParser.y"
    {
		(yyval.fieldVal) = dict->addStringField((yysemantic_stack_[(8) - (7)].stringVal), (yysemantic_stack_[(8) - (1)].intVal), false);
		//((DicStringField*)$$)->setEncode($5);
		delete [] (yysemantic_stack_[(8) - (7)].stringVal);
	}
    break;


/* Line 670 of lalr1.cc  */
#line 568 "bisonDictionaryTextParser.cc"
      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
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
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  BisonDictionaryTextParser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char BisonDictionaryTextParser::yypact_ninf_ = -15;
  const signed char
  BisonDictionaryTextParser::yypact_[] =
  {
         5,   -11,    13,    -1,   -15,    11,     1,    -5,     3,     2,
       6,     4,     7,     6,     0,   -15,   -15,     9,     8,    10,
      12,    14,    15,    15,    16,    18,    15,   -15,   -15,   -15,
     -15,   -15,   -15,   -15,    19,    -6,    20,   -15,    21,    17,
      22,    23,    26,    27,    24,    -3,   -15,   -15,    25,    28,
      29,    30,    31,    36,    32,   -15,   -15,   -15,   -15,   -15,
      33,    34,    37,    38,    35,    39,   -15,   -15
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  BisonDictionaryTextParser::yydefact_[] =
  {
         0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     2,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     0,     0,     0,     0,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,     0,    21,    22
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  BisonDictionaryTextParser::yypgoto_[] =
  {
       -15,   -15,    43,   -15,   -14,   -15,   -15,   -15,   -15,   -15,
     -15,   -15,   -15
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  BisonDictionaryTextParser::yydefgoto_[] =
  {
        -1,     2,    12,    13,    25,    26,    27,    28,    29,    30,
      31,    32,    33
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char BisonDictionaryTextParser::yytable_ninf_ = -1;
  const unsigned char
  BisonDictionaryTextParser::yytable_[] =
  {
        39,    40,    41,    42,    43,    17,    44,    45,     1,    34,
       3,    18,    37,     4,     5,     6,     7,     8,     9,    10,
      19,    11,    54,    14,    20,    15,    21,     0,     0,    22,
      24,    23,     0,    48,     0,    35,    36,    38,    49,    50,
      46,    47,    51,    52,     0,    55,    61,    53,    56,    57,
      58,    59,    60,    64,    65,    66,    16,    62,     0,    67,
      63
  };

  /* YYCHECK.  */
  const signed char
  BisonDictionaryTextParser::yycheck_[] =
  {
         6,     7,     8,     9,    10,     5,    12,    13,     3,    23,
      21,    11,    26,     0,    15,     4,    15,    22,    15,    17,
      11,    15,    25,    19,    16,    18,    16,    -1,    -1,    17,
      15,    17,    -1,    16,    -1,    19,    18,    18,    16,    16,
      20,    20,    16,    16,    -1,    20,    14,    23,    20,    20,
      20,    20,    16,    16,    16,    20,    13,    24,    -1,    20,
      26
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  BisonDictionaryTextParser::yystos_[] =
  {
         0,     3,    28,    21,     0,    15,     4,    15,    22,    15,
      17,    15,    29,    30,    19,    18,    29,     5,    11,    11,
      16,    16,    17,    17,    15,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    31,    19,    18,    31,    18,     6,
       7,     8,     9,    10,    12,    13,    20,    20,    16,    16,
      16,    16,    16,    23,    25,    20,    20,    20,    20,    20,
      16,    14,    24,    26,    16,    16,    20,    20
  };

#if DICTIONARY_TEXTDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  BisonDictionaryTextParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   123,   125,    58,
      59,    61,    46,    60,    62,    40,    41
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  BisonDictionaryTextParser::yyr1_[] =
  {
         0,    27,    28,    29,    29,    30,    30,    31,    31,    32,
      32,    32,    32,    32,    32,    32,    33,    34,    35,    36,
      37,    38,    39
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  BisonDictionaryTextParser::yyr2_[] =
  {
         0,     2,    10,     1,     2,     8,     9,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     5,     5,
       5,     8,     8
  };


  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const BisonDictionaryTextParser::yytname_[] =
  {
    "$end", "error", "$undefined", "USDS_Dictionary_ID",
  "DICTIONARY_VERSION", "ROOT_TAG", "TYPE_BOOLEAN", "TYPE_INT",
  "TYPE_LONG", "TYPE_DOUBLE", "TYPE_VARINT", "TYPE_STRUCT", "TYPE_ARRAY",
  "TYPE_STRING", "\"utf-8\"", "\"integer\"", "\"string\"", "'{'", "'}'",
  "':'", "';'", "'='", "'.'", "'<'", "'>'", "'('", "')'", "$accept",
  "dictionary", "tags", "tag", "fields", "field", "field_boolean",
  "field_int", "field_long", "field_double", "field_varint", "field_array",
  "field_string", YY_NULL
  };

#if DICTIONARY_TEXTDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const BisonDictionaryTextParser::rhs_number_type
  BisonDictionaryTextParser::yyrhs_[] =
  {
        28,     0,    -1,     3,    21,    15,     4,    15,    22,    15,
      17,    29,    18,    -1,    30,    -1,    30,    29,    -1,    15,
      19,    11,    16,    17,    31,    18,    20,    -1,    15,    19,
       5,    11,    16,    17,    31,    18,    20,    -1,    32,    -1,
      32,    31,    -1,    33,    -1,    34,    -1,    35,    -1,    36,
      -1,    37,    -1,    38,    -1,    39,    -1,    15,    19,     6,
      16,    20,    -1,    15,    19,     7,    16,    20,    -1,    15,
      19,     8,    16,    20,    -1,    15,    19,     9,    16,    20,
      -1,    15,    19,    10,    16,    20,    -1,    15,    19,    12,
      23,    16,    24,    16,    20,    -1,    15,    19,    13,    25,
      14,    26,    16,    20,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  BisonDictionaryTextParser::yyprhs_[] =
  {
         0,     0,     3,    14,    16,    19,    28,    38,    40,    43,
      45,    47,    49,    51,    53,    55,    57,    63,    69,    75,
      81,    87,    96
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  BisonDictionaryTextParser::yyrline_[] =
  {
         0,    71,    71,    78,    78,    81,    86,    96,    96,    98,
      98,    98,    98,    98,    98,    98,   101,   109,   117,   125,
     133,   141,   150
  };

  // Print the state stack on the debug stream.
  void
  BisonDictionaryTextParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  BisonDictionaryTextParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // DICTIONARY_TEXTDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  BisonDictionaryTextParser::token_number_type
  BisonDictionaryTextParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      25,    26,     2,     2,     2,     2,    22,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    19,    20,
      23,    21,    24,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,    18,     2,     2,     2,     2,
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
      15,    16
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int BisonDictionaryTextParser::yyeof_ = 0;
  const int BisonDictionaryTextParser::yylast_ = 60;
  const int BisonDictionaryTextParser::yynnts_ = 13;
  const int BisonDictionaryTextParser::yyempty_ = -2;
  const int BisonDictionaryTextParser::yyfinal_ = 4;
  const int BisonDictionaryTextParser::yyterror_ = 1;
  const int BisonDictionaryTextParser::yyerrcode_ = 256;
  const int BisonDictionaryTextParser::yyntokens_ = 27;

  const unsigned int BisonDictionaryTextParser::yyuser_token_number_max_ = 271;
  const BisonDictionaryTextParser::token_number_type BisonDictionaryTextParser::yyundef_token_ = 2;

/* Line 1141 of lalr1.cc  */
#line 13 "bisonDictionaryTextParser.y"
} // usds
/* Line 1141 of lalr1.cc  */
#line 1126 "bisonDictionaryTextParser.cc"
/* Line 1142 of lalr1.cc  */
#line 161 "bisonDictionaryTextParser.y"

//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	*error_message << "Error in Text Dictionary!\n";
	*error_message << loc.begin.line;
	*error_message << ".";
	*error_message << loc.begin.column;
	*error_message << ": ";
	*error_message << msg;
}

