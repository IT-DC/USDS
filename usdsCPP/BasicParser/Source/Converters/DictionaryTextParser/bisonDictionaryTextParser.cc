// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   dictionary_textlex

// First part of user declarations.
#line 1 "bisonDictionaryTextParser.y" // lalr1.cc:398

	#include "usdsBasicParser.h"
	#include "dictionary\usdsDictionary.h"

	#include "dictionary\dictionaryBaseType.h"
	#include "dictionary\dataTypes\dictionaryTagLink.h"
	#include "dictionary\dataTypes\dictionaryBoolean.h"
	#include "dictionary\dataTypes\dictionaryByte.h"
	#include "dictionary\dataTypes\dictionaryUByte.h"
	#include "dictionary\dataTypes\dictionaryShort.h"
	#include "dictionary\dataTypes\dictionaryUShort.h"
	#include "dictionary\dataTypes\dictionaryInt.h"
	#include "dictionary\dataTypes\dictionaryUint.h"
	#include "dictionary\dataTypes\dictionaryLong.h"
	#include "dictionary\dataTypes\dictionaryULong.h"
	#include "dictionary\dataTypes\dictionaryFloat.h"
	#include "dictionary\dataTypes\dictionaryDouble.h"
	#include "dictionary\dataTypes\dictionaryVarint.h"
	#include "dictionary\dataTypes\dictionaryUVarint.h"
	#include "dictionary\dataTypes\dictionaryString.h"
	#include "dictionary\dataTypes\dictionaryArray.h"	
	#include "dictionary\dataTypes\dictionaryStruct.h"

	#include "usdsTypes.h"
	
	#include "flexDictionaryTextScanner.h"
	#include <string>
	

#line 68 "bisonDictionaryTextParser.cc" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "bisonDictionaryTextParser.hh"

// User implementation prologue.
#line 115 "bisonDictionaryTextParser.y" // lalr1.cc:406

#undef yylex
#define yylex scanner->scan

#line 86 "bisonDictionaryTextParser.cc" // lalr1.cc:406


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
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


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if DICTIONARY_TEXTDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !DICTIONARY_TEXTDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !DICTIONARY_TEXTDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 36 "bisonDictionaryTextParser.y" // lalr1.cc:473
namespace usds {
#line 172 "bisonDictionaryTextParser.cc" // lalr1.cc:473

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
              // Fall through.
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
  BisonDictionaryTextParser::BisonDictionaryTextParser (const char* input_text_yyarg, class Dictionary* dict_yyarg, class FlexDictionaryTextScanner* scanner_yyarg, class DictionaryBaseType* tag_yyarg, class DictionaryBaseType* field_yyarg)
    :
#if DICTIONARY_TEXTDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      input_text (input_text_yyarg),
      dict (dict_yyarg),
      scanner (scanner_yyarg),
      tag (tag_yyarg),
      field (field_yyarg)
  {}

  BisonDictionaryTextParser::~BisonDictionaryTextParser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  BisonDictionaryTextParser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  BisonDictionaryTextParser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  BisonDictionaryTextParser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  BisonDictionaryTextParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  BisonDictionaryTextParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  BisonDictionaryTextParser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  BisonDictionaryTextParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  BisonDictionaryTextParser::by_type::by_type ()
     : type (empty)
  {}

  inline
  BisonDictionaryTextParser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  BisonDictionaryTextParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  BisonDictionaryTextParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  BisonDictionaryTextParser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  BisonDictionaryTextParser::by_state::by_state ()
    : state (empty)
  {}

  inline
  BisonDictionaryTextParser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  BisonDictionaryTextParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  BisonDictionaryTextParser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  BisonDictionaryTextParser::symbol_number_type
  BisonDictionaryTextParser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  BisonDictionaryTextParser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  BisonDictionaryTextParser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  BisonDictionaryTextParser::stack_symbol_type&
  BisonDictionaryTextParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  BisonDictionaryTextParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if DICTIONARY_TEXTDEBUG
  template <typename Base>
  void
  BisonDictionaryTextParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  BisonDictionaryTextParser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  BisonDictionaryTextParser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  BisonDictionaryTextParser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
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
#endif // DICTIONARY_TEXTDEBUG

  inline BisonDictionaryTextParser::state_type
  BisonDictionaryTextParser::yy_lr_goto_state_ (state_type yystate, int yylhs)
  {
    int yyr = yypgoto_[yylhs - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yylhs - yyntokens_];
  }

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
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// $$ and @$.
    stack_symbol_type yylhs;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULL, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
    /* If YYLEN is nonzero, implement the default value of the action:
       '$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYLHS.VALUE to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yylhs.value = yystack_[yylen - 1].value;
    else
      yylhs.value = yystack_[0].value;

    // Compute the default @$.
    {
      slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
      YYLLOC_DEFAULT (yylhs.location, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    try
      {
        switch (yyn)
          {
  case 2:
#line 125 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setID(input_text + (yystack_[5].value.stringVal)[0], (yystack_[5].value.stringVal)[1], (yystack_[4].value.UInt32Val), (yystack_[2].value.UInt8Val), (yystack_[0].value.UInt8Val));
	}
#line 627 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 3:
#line 129 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		// Finilize dictionary
		dict->finalizeDictionary();
	}
#line 636 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 6:
#line 142 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 644 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 7:
#line 146 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 652 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 8:
#line 150 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 660 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 9:
#line 154 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 668 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 10:
#line 158 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 676 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 11:
#line 162 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 684 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 12:
#line 166 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 692 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 13:
#line 170 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 700 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 14:
#line 174 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 708 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 15:
#line 178 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 716 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 16:
#line 182 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 724 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 17:
#line 186 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 732 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 18:
#line 190 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 740 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 19:
#line 194 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 748 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 20:
#line 198 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 756 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 21:
#line 202 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 764 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 22:
#line 206 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[5].value.typeVal), (yystack_[7].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)tag)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 773 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 23:
#line 211 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_STRUCT, (yystack_[3].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 781 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 24:
#line 215 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
	
	}
#line 789 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 27:
#line 227 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 797 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 28:
#line 231 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 805 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 29:
#line 235 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 813 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 30:
#line 239 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 821 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 31:
#line 243 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 829 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 32:
#line 247 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 837 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 33:
#line 251 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 845 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 34:
#line 255 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 853 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 35:
#line 259 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 861 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 36:
#line 263 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 869 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 37:
#line 267 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 877 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 38:
#line 271 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 885 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 39:
#line 275 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 893 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 40:
#line 279 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 901 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 41:
#line 283 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 909 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 42:
#line 287 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 917 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 43:
#line 291 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField((yystack_[5].value.typeVal), (yystack_[7].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)field)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 926 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 44:
#line 296 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
	}
#line 935 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 45:
#line 301 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = tag->getParent();
	}
#line 943 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 46:
#line 308 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 952 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 47:
#line 313 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 961 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 48:
#line 318 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 970 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 49:
#line 323 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 979 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 50:
#line 328 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 988 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 51:
#line 333 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 997 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 52:
#line 338 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1006 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 53:
#line 343 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1015 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 54:
#line 348 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1024 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 55:
#line 353 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1033 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 56:
#line 358 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1042 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 57:
#line 363 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1051 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 58:
#line 368 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1060 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 59:
#line 373 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1069 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 60:
#line 378 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1078 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 61:
#line 383 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1087 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 62:
#line 388 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), (yystack_[9].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryString*)dict_field)->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setNullable(true);
	}
#line 1097 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 63:
#line 394 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[4].value.stringVal)[0], (yystack_[4].value.stringVal)[1]);
		field->setNullable(true);
	}
#line 1107 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 64:
#line 400 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 1116 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 65:
#line 407 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBoolean* dict_field = (usds::DictionaryBoolean*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.boolVal));
	}
#line 1125 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 66:
#line 412 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryByte* dict_field = (usds::DictionaryByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.UInt8Val));
	}
#line 1134 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 67:
#line 417 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUByte* dict_field = (usds::DictionaryUByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.UInt8Val));
	}
#line 1143 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 68:
#line 422 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryShort* dict_field = (usds::DictionaryShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.Int16Val));
	}
#line 1152 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 69:
#line 427 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUShort* dict_field = (usds::DictionaryUShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.UInt16Val));
	}
#line 1161 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 70:
#line 432 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryInt* dict_field = (usds::DictionaryInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.Int32Val));
	}
#line 1170 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 71:
#line 437 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUInt* dict_field = (usds::DictionaryUInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.UInt32Val));
	}
#line 1179 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 72:
#line 442 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryLong* dict_field = (usds::DictionaryLong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.Int64Val));
	}
#line 1188 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 73:
#line 447 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryULong* dict_field = (usds::DictionaryULong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.UInt64Val));
	}
#line 1197 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 74:
#line 455 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, (yystack_[3].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1205 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 75:
#line 465 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt8Val) = (int8_t)(yystack_[0].value.Int8Val);
	}
#line 1213 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 76:
#line 469 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt8Val) = (int8_t)(yystack_[0].value.Int8Val);
	}
#line 1221 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 77:
#line 473 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt8Val) = (int8_t)(yystack_[1].value.Int8Val) * (int8_t)10 + (int8_t)(yystack_[0].value.Int8Val);
	}
#line 1229 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 78:
#line 477 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt8Val) = (int8_t)(yystack_[1].value.Int8Val) * (int8_t)10 + (int8_t)(yystack_[0].value.Int8Val);
	}
#line 1237 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 79:
#line 481 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.Int8Val) > (int8_t)1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int8_t: too big value";

		(yylhs.value.UInt8Val) = (int8_t)(yystack_[1].value.Int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.Int8Val);
		
		if ((yystack_[2].value.Int8Val) == (int8_t)1 && (yylhs.value.UInt8Val) >= (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int8_t: too big value";
		
		(yylhs.value.UInt8Val) = (int8_t)(yystack_[2].value.Int8Val) * (int8_t)100 + (yylhs.value.UInt8Val);
		
	}
#line 1254 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 80:
#line 494 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.Int8Val) < (int8_t)-1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int8_t: too big value";

		(yylhs.value.UInt8Val) = (int8_t)(yystack_[1].value.Int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.Int8Val);
		
		if ((yystack_[2].value.Int8Val) == (int8_t)-1 && (yylhs.value.UInt8Val) > (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int8_t: too big value";
		
		(yylhs.value.UInt8Val) = (int8_t)(yystack_[2].value.Int8Val) * (int8_t)100 + (yylhs.value.UInt8Val);
		
	}
#line 1271 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 81:
#line 507 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to int8_t: too big value";
	}
#line 1279 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 82:
#line 511 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to int8_t: too big value";
	}
#line 1287 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 83:
#line 518 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt8Val) = (uint8_t)(yystack_[0].value.Int8Val);
	}
#line 1295 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 84:
#line 522 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt8Val) = (uint8_t)(yystack_[1].value.Int8Val) * (uint8_t)10 + (uint8_t)(yystack_[0].value.Int8Val);
	}
#line 1303 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 85:
#line 526 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.Int8Val) > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to uint8_t: too big value";

		(yylhs.value.UInt8Val) = (uint8_t)(yystack_[1].value.Int8Val)  * (uint8_t)10 + (uint8_t)(yystack_[0].value.Int8Val);
		
		if ((yystack_[2].value.Int8Val) == (int8_t)2 && (yylhs.value.UInt8Val) >= (uint8_t)56)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to uint8_t: too big value";
		
		(yylhs.value.UInt8Val) = (uint8_t)(yystack_[2].value.Int8Val) * (uint8_t)100 + (yylhs.value.UInt8Val);
		
	}
#line 1320 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 86:
#line 539 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to uint8_t: too big value";
	}
#line 1328 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 87:
#line 549 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int16Val) = (int16_t)(yystack_[0].value.Int8Val);
	}
#line 1336 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 88:
#line 553 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int16Val) = (int16_t)(yystack_[0].value.Int8Val);
	}
#line 1344 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 89:
#line 557 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int16Val) = 
		(int16_t)(yystack_[1].value.Int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.Int8Val);
	}
#line 1354 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 90:
#line 563 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int16Val) = 
		(int16_t)(yystack_[1].value.Int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.Int8Val);
	}
#line 1364 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 91:
#line 569 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int16Val) = 
		(int16_t)(yystack_[2].value.Int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.Int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.Int8Val);
	}
#line 1375 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 92:
#line 576 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int16Val) = 
		(int16_t)(yystack_[2].value.Int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.Int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.Int8Val);
	}
#line 1386 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 93:
#line 583 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int16Val) = 
		(int16_t)(yystack_[3].value.Int8Val) * (int16_t)1000 + 
		(int16_t)(yystack_[2].value.Int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.Int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.Int8Val);
	}
#line 1398 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 94:
#line 591 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int16Val) = 
		(int16_t)(yystack_[3].value.Int8Val) * (int16_t)1000 + 
		(int16_t)(yystack_[2].value.Int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.Int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.Int8Val);
	}
#line 1410 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 95:
#line 599 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[4].value.Int8Val) > (int8_t)3)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int16_t: too big value";
		
		(yylhs.value.Int16Val) = 
		(int16_t)(yystack_[3].value.Int8Val) * (int16_t)1000 + 
		(int16_t)(yystack_[2].value.Int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.Int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.Int8Val);

		if ((yystack_[4].value.Int8Val) == (int8_t)3 && (yylhs.value.Int16Val) >= (int16_t)2768)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int16_t: too big value";
			
		(yylhs.value.Int16Val) = (yylhs.value.Int16Val) + (int16_t)(yystack_[4].value.Int8Val) * (int16_t)10000;
	}
#line 1430 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 96:
#line 615 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[4].value.Int8Val) < (int8_t)-3)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int16_t: too big value";
		
		(yylhs.value.Int16Val) = 
		(int16_t)(yystack_[3].value.Int8Val) * (int16_t)1000 + 
		(int16_t)(yystack_[2].value.Int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.Int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.Int8Val);

		if ((yystack_[4].value.Int8Val) == (int8_t)-3 && (yylhs.value.Int16Val) > (int16_t)2768)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int16_t: too big value";
			
		(yylhs.value.Int16Val) = (yylhs.value.Int16Val) + (int16_t)(yystack_[4].value.Int8Val) * (int16_t)10000;
	}
#line 1450 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 97:
#line 631 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to int16_t: too big value";
	}
#line 1458 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 98:
#line 635 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to int16_t: too big value";
	}
#line 1466 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 99:
#line 642 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt16Val) = (uint16_t)(yystack_[0].value.Int8Val);
	}
#line 1474 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 100:
#line 646 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt16Val) = 
		(uint16_t)(yystack_[1].value.Int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.Int8Val);
	}
#line 1484 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 101:
#line 652 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt16Val) = 
		(uint16_t)(yystack_[2].value.Int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.Int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.Int8Val);
	}
#line 1495 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 102:
#line 659 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt16Val) = 
		(uint16_t)(yystack_[3].value.Int8Val) * (uint16_t)1000 + 
		(uint16_t)(yystack_[2].value.Int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.Int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.Int8Val);
	}
#line 1507 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 103:
#line 667 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[4].value.Int8Val) > (int8_t)6)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to uint16_t: too big value";
		
		(yylhs.value.UInt16Val) = 
		(uint16_t)(yystack_[3].value.Int8Val) * (uint16_t)1000 + 
		(uint16_t)(yystack_[2].value.Int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.Int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.Int8Val);

		if ((yystack_[4].value.Int8Val) == (int8_t)6 && (yylhs.value.UInt16Val) >= (uint16_t)5536)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to uint16_t: too big value";
			
		(yylhs.value.UInt16Val) = (yylhs.value.UInt16Val) + (uint16_t)(yystack_[4].value.Int8Val) * (uint16_t)10000;
	}
#line 1527 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 104:
#line 683 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to uint16_t: too big value";
	}
#line 1535 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 105:
#line 693 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = (int32_t)(yystack_[0].value.Int8Val);
	}
#line 1543 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 106:
#line 697 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = (int32_t)(yystack_[0].value.Int8Val);
	}
#line 1551 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 107:
#line 701 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1561 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 108:
#line 707 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1571 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 109:
#line 713 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1582 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 110:
#line 720 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1593 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 111:
#line 727 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1605 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 112:
#line 735 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1617 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 113:
#line 743 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1630 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 114:
#line 752 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1643 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 115:
#line 761 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[5].value.Int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1657 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 116:
#line 771 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[5].value.Int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1671 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 117:
#line 781 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[6].value.Int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.Int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1686 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 118:
#line 792 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[6].value.Int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.Int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1701 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 119:
#line 803 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[7].value.Int8Val) * (int32_t)10000000 + 
		(int32_t)(yystack_[6].value.Int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.Int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1717 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 120:
#line 815 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[7].value.Int8Val) * (int32_t)10000000 + 
		(int32_t)(yystack_[6].value.Int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.Int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1733 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 121:
#line 827 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[8].value.Int8Val) * (int32_t)100000000 + 
		(int32_t)(yystack_[7].value.Int8Val) * (int32_t)10000000 + 
		(int32_t)(yystack_[6].value.Int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.Int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1750 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 122:
#line 840 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[8].value.Int8Val) * (int32_t)100000000 + 
		(int32_t)(yystack_[7].value.Int8Val) * (int32_t)10000000 + 
		(int32_t)(yystack_[6].value.Int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.Int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1767 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 123:
#line 853 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[9].value.Int8Val) > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int32_t: too big value";
		
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[8].value.Int8Val) * (int32_t)100000000 + 
		(int32_t)(yystack_[7].value.Int8Val) * (int32_t)10000000 + 
		(int32_t)(yystack_[6].value.Int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.Int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);

		if ((yystack_[9].value.Int8Val) == (int8_t)2 && (yylhs.value.Int32Val) >= (int32_t)147483648)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int32_t: too big value";
			
		(yylhs.value.Int32Val) = (yylhs.value.Int32Val) + (int32_t)(yystack_[9].value.Int8Val) * (int32_t)1000000000;
	}
#line 1792 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 124:
#line 874 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[9].value.Int8Val) < (int8_t)-2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int32_t: too big value";
		
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[8].value.Int8Val) * (int32_t)100000000 + 
		(int32_t)(yystack_[7].value.Int8Val) * (int32_t)10000000 + 
		(int32_t)(yystack_[6].value.Int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.Int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);

		if ((yystack_[9].value.Int8Val) == (int8_t)-2 && (yylhs.value.Int32Val) > (int32_t)147483648)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int32_t: too big value";
			
		(yylhs.value.Int32Val) = (yylhs.value.Int32Val) + (int32_t)(yystack_[9].value.Int8Val) * (int32_t)1000000000;
	}
#line 1817 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 125:
#line 895 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to int32_t: too big value";
	}
#line 1825 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 126:
#line 899 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to int32_t: too big value";
	}
#line 1833 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 127:
#line 906 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = (uint32_t)(yystack_[0].value.Int8Val);
	}
#line 1841 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 128:
#line 910 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 1851 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 129:
#line 916 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 1862 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 130:
#line 923 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[3].value.Int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 1874 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 131:
#line 931 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[4].value.Int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.Int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 1887 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 132:
#line 940 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[5].value.Int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.Int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.Int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 1901 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 133:
#line 950 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[6].value.Int8Val) * (uint32_t)1000000 + 
		(uint32_t)(yystack_[5].value.Int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.Int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.Int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 1916 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 134:
#line 961 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[7].value.Int8Val) * (uint32_t)10000000 + 
		(uint32_t)(yystack_[6].value.Int8Val) * (uint32_t)1000000 + 
		(uint32_t)(yystack_[5].value.Int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.Int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.Int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 1932 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 135:
#line 973 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[8].value.Int8Val) * (uint32_t)100000000 + 
		(uint32_t)(yystack_[7].value.Int8Val) * (uint32_t)10000000 + 
		(uint32_t)(yystack_[6].value.Int8Val) * (uint32_t)1000000 + 
		(uint32_t)(yystack_[5].value.Int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.Int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.Int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 1949 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 136:
#line 986 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[9].value.Int8Val) > (int8_t)4)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to uint32_t: too big value";
		
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[8].value.Int8Val) * (uint32_t)100000000 + 
		(uint32_t)(yystack_[7].value.Int8Val) * (uint32_t)10000000 + 
		(uint32_t)(yystack_[6].value.Int8Val) * (uint32_t)1000000 + 
		(uint32_t)(yystack_[5].value.Int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.Int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.Int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);

		if ((yystack_[9].value.Int8Val) == (int8_t)4 && (yylhs.value.UInt32Val) >= (uint32_t)294967296)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to uint32_t: too big value";
			
		(yylhs.value.UInt32Val) = (yylhs.value.UInt32Val) + (uint32_t)(yystack_[9].value.Int8Val) * (uint32_t)1000000000;
	}
#line 1974 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 137:
#line 1007 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to uint32_t: too big value";
	}
#line 1982 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 138:
#line 1017 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = (int64_t)(yystack_[0].value.Int8Val);
	}
#line 1990 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 139:
#line 1021 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = (int64_t)(yystack_[0].value.Int8Val);
	}
#line 1998 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 140:
#line 1025 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2008 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 141:
#line 1031 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2018 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 142:
#line 1037 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2029 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 143:
#line 1044 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2040 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 144:
#line 1051 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2052 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 145:
#line 1059 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2064 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 146:
#line 1067 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2077 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 147:
#line 1076 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2090 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 148:
#line 1085 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2104 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 149:
#line 1095 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2118 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 150:
#line 1105 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2133 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 151:
#line 1116 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2148 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 152:
#line 1127 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2164 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 153:
#line 1139 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2180 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 154:
#line 1151 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2197 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 155:
#line 1164 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2214 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 156:
#line 1177 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2232 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 157:
#line 1191 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2250 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 158:
#line 1206 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2269 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 159:
#line 1222 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2288 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 160:
#line 1238 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2308 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 161:
#line 1255 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2328 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 162:
#line 1272 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2349 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 163:
#line 1290 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2370 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 164:
#line 1308 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2392 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 165:
#line 1327 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2414 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 166:
#line 1346 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[14].value.Int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2437 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 167:
#line 1366 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[14].value.Int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2460 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 168:
#line 1386 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[15].value.Int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.Int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2484 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 169:
#line 1407 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[15].value.Int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.Int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2508 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 170:
#line 1428 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[16].value.Int8Val) * (int64_t)10000000000000000 + 
		(int64_t)(yystack_[15].value.Int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.Int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2533 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 171:
#line 1450 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[16].value.Int8Val) * (int64_t)10000000000000000 + 
		(int64_t)(yystack_[15].value.Int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.Int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2558 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 172:
#line 1472 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[17].value.Int8Val) * (int64_t)100000000000000000 + 
		(int64_t)(yystack_[16].value.Int8Val) * (int64_t)10000000000000000 + 
		(int64_t)(yystack_[15].value.Int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.Int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2584 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 173:
#line 1495 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[17].value.Int8Val) * (int64_t)100000000000000000 + 
		(int64_t)(yystack_[16].value.Int8Val) * (int64_t)10000000000000000 + 
		(int64_t)(yystack_[15].value.Int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.Int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);
	}
#line 2610 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 174:
#line 1518 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[17].value.Int8Val) * (int64_t)100000000000000000 + 
		(int64_t)(yystack_[16].value.Int8Val) * (int64_t)10000000000000000 + 
		(int64_t)(yystack_[15].value.Int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.Int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);

		if ((yystack_[18].value.Int8Val) == (int8_t)9 && (yylhs.value.Int64Val) >= (int64_t)223372036854775808)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[18].value.Int8Val) << (yystack_[17].value.Int8Val) << (yystack_[16].value.Int8Val) << (yystack_[15].value.Int8Val) << (yystack_[14].value.Int8Val) << (yystack_[13].value.Int8Val) << (yystack_[12].value.Int8Val) << (yystack_[11].value.Int8Val) << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int64_t: too big value";
			
		(yylhs.value.Int64Val) = (yylhs.value.Int64Val) + (int64_t)(yystack_[18].value.Int8Val) * (int64_t)1000000000000000000;
	}
#line 2642 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 175:
#line 1547 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int64Val) = 
		(int64_t)(yystack_[17].value.Int8Val) * (int64_t)100000000000000000 + 
		(int64_t)(yystack_[16].value.Int8Val) * (int64_t)10000000000000000 + 
		(int64_t)(yystack_[15].value.Int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.Int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.Int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.Int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.Int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.Int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.Int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.Int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.Int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.Int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.Int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.Int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.Int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.Int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.Int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.Int8Val);

		if ((yystack_[18].value.Int8Val) == (int8_t)-9 && (yylhs.value.Int64Val) > (int64_t)223372036854775808)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[18].value.Int8Val) << (yystack_[17].value.Int8Val) << (yystack_[16].value.Int8Val) << (yystack_[15].value.Int8Val) << (yystack_[14].value.Int8Val) << (yystack_[13].value.Int8Val) << (yystack_[12].value.Int8Val) << (yystack_[11].value.Int8Val) << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to int64_t: too big value";
			
		(yylhs.value.Int64Val) = (yylhs.value.Int64Val) + (int64_t)(yystack_[18].value.Int8Val) * (int64_t)1000000000000000000;
	}
#line 2674 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 176:
#line 1576 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.Int8Val) << (yystack_[18].value.Int8Val) << (yystack_[17].value.Int8Val) << (yystack_[16].value.Int8Val) << (yystack_[15].value.Int8Val) << (yystack_[14].value.Int8Val) << (yystack_[13].value.Int8Val) << (yystack_[12].value.Int8Val) << (yystack_[11].value.Int8Val) << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to int64_t: too big value";
	}
#line 2683 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 177:
#line 1582 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.Int8Val) << (yystack_[18].value.Int8Val) << (yystack_[17].value.Int8Val) << (yystack_[16].value.Int8Val) << (yystack_[15].value.Int8Val) << (yystack_[14].value.Int8Val) << (yystack_[13].value.Int8Val) << (yystack_[12].value.Int8Val) << (yystack_[11].value.Int8Val) << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to int64_t: too big value";
	}
#line 2692 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 178:
#line 1590 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = (uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2700 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 179:
#line 1594 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2710 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 180:
#line 1600 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2721 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 181:
#line 1607 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2733 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 182:
#line 1615 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2746 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 183:
#line 1624 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2760 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 184:
#line 1634 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2775 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 185:
#line 1645 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2791 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 186:
#line 1657 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2808 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 187:
#line 1670 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[9].value.Int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2826 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 188:
#line 1685 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[10].value.Int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.Int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2845 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 189:
#line 1701 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[11].value.Int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.Int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.Int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2865 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 190:
#line 1718 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[12].value.Int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.Int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.Int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.Int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2886 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 191:
#line 1736 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[13].value.Int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.Int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.Int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.Int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.Int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2908 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 192:
#line 1755 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[14].value.Int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.Int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.Int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.Int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.Int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.Int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2931 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 193:
#line 1775 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[15].value.Int8Val) * (uint64_t)1000000000000000 + 
		(uint64_t)(yystack_[14].value.Int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.Int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.Int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.Int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.Int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.Int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2955 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 194:
#line 1796 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[16].value.Int8Val) * (uint64_t)10000000000000000 + 
		(uint64_t)(yystack_[15].value.Int8Val) * (uint64_t)1000000000000000 + 
		(uint64_t)(yystack_[14].value.Int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.Int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.Int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.Int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.Int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.Int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 2980 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 195:
#line 1818 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[17].value.Int8Val) * (uint64_t)100000000000000000 + 
		(uint64_t)(yystack_[16].value.Int8Val) * (uint64_t)10000000000000000 + 
		(uint64_t)(yystack_[15].value.Int8Val) * (uint64_t)1000000000000000 + 
		(uint64_t)(yystack_[14].value.Int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.Int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.Int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.Int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.Int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.Int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 3006 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 196:
#line 1841 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[18].value.Int8Val) * (uint64_t)1000000000000000000 + 
		(uint64_t)(yystack_[17].value.Int8Val) * (uint64_t)100000000000000000 + 
		(uint64_t)(yystack_[16].value.Int8Val) * (uint64_t)10000000000000000 + 
		(uint64_t)(yystack_[15].value.Int8Val) * (uint64_t)1000000000000000 + 
		(uint64_t)(yystack_[14].value.Int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.Int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.Int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.Int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.Int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.Int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);
	}
#line 3033 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 197:
#line 1865 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[19].value.Int8Val) > (int8_t)1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.Int8Val) << (yystack_[18].value.Int8Val) << (yystack_[17].value.Int8Val) << (yystack_[16].value.Int8Val) << (yystack_[15].value.Int8Val) << (yystack_[14].value.Int8Val) << (yystack_[13].value.Int8Val) << (yystack_[12].value.Int8Val) << (yystack_[11].value.Int8Val) << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to uint64_t: too big value";

		(yylhs.value.UInt64Val) = 
		(uint64_t)(yystack_[18].value.Int8Val) * (uint64_t)1000000000000000000 + 
		(uint64_t)(yystack_[17].value.Int8Val) * (uint64_t)100000000000000000 + 
		(uint64_t)(yystack_[16].value.Int8Val) * (uint64_t)10000000000000000 + 
		(uint64_t)(yystack_[15].value.Int8Val) * (uint64_t)1000000000000000 + 
		(uint64_t)(yystack_[14].value.Int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.Int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.Int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.Int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.Int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.Int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.Int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.Int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.Int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.Int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.Int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.Int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.Int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.Int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.Int8Val);

		if ((yystack_[19].value.Int8Val) == (int8_t)1 && (yylhs.value.UInt64Val) >= (uint64_t)8446744073709551616)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.Int8Val) << (yystack_[18].value.Int8Val) << (yystack_[17].value.Int8Val) << (yystack_[16].value.Int8Val) << (yystack_[15].value.Int8Val) << (yystack_[14].value.Int8Val) << (yystack_[13].value.Int8Val) << (yystack_[12].value.Int8Val) << (yystack_[11].value.Int8Val) << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to uint64_t: too big value";
			
		(yylhs.value.UInt64Val) = (yylhs.value.UInt64Val) + (uint64_t)(yystack_[19].value.Int8Val) * (uint64_t)10000000000000000000;
	}
#line 3070 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 198:
#line 1899 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[20].value.Int8Val) << (yystack_[19].value.Int8Val) << (yystack_[18].value.Int8Val) << (yystack_[17].value.Int8Val) << (yystack_[16].value.Int8Val) << (yystack_[15].value.Int8Val) << (yystack_[14].value.Int8Val) << (yystack_[13].value.Int8Val) << (yystack_[12].value.Int8Val) << (yystack_[11].value.Int8Val) << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to uint64_t: too big value";
	}
#line 3079 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;


#line 3083 "bisonDictionaryTextParser.cc" // lalr1.cc:846
          default:
            break;
          }
      }
    catch (const syntax_error& yyexc)
      {
        error (yyexc);
        YYERROR;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yylhs);
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    // Shift the result of the reduction.
    yypush_ (YY_NULL, yylhs);
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
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
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
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

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
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
        if (!yyempty)
          yy_destroy_ (YY_NULL, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULL, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  BisonDictionaryTextParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  BisonDictionaryTextParser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
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
         yyla.  (However, yyla is currently not documented for users.)
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
            // Stay within bounds of both yycheck and yytname.
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


  const signed char BisonDictionaryTextParser::yypact_ninf_ = -38;

  const signed char BisonDictionaryTextParser::yytable_ninf_ = -1;

  const short int
  BisonDictionaryTextParser::yypact_[] =
  {
      23,    46,     5,    88,   -38,    89,    -6,    90,    91,    92,
      93,    83,    95,    98,    91,    99,   100,   -38,   101,   -38,
     102,    97,   104,   -38,    27,   105,   106,   107,   103,    27,
     108,   109,   111,   112,   -38,   -38,     3,   100,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   123,   124,   126,
     127,   128,   129,   130,   131,   -23,   132,   102,   135,   136,
     133,   134,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   110,   -38,   160,   161,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,    94,    27,   162,   163,
     164,   157,    27,    27,   158,   165,   168,   166,   167,   -38,
     170,    26,   169,   171,   -38,   -38,    38,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   -24,   172,   173,   -38,   191,    41,    45,
      47,    49,    51,    53,    55,    57,    59,    61,    63,    65,
      67,    69,    71,    73,   196,    75,   -38,   100,   100,   190,
     -38,     2,   -38,    24,   -38,    39,   -38,    30,   -38,    40,
     -38,    33,   -38,    43,   -38,    36,   -38,    44,   -38,   193,
     -38,   194,   -38,   195,   -38,   198,   -38,   199,   -38,   200,
     -38,   201,    96,   -38,   202,   102,   102,   -38,   197,   203,
     174,   205,   204,   206,   207,   208,   209,   210,   211,   212,
     214,   213,   215,   216,   220,   221,   222,   218,   219,   223,
     224,   234,   226,   227,   228,   229,   230,   231,   232,   233,
     235,   240,   236,   -38,   -38,   246,   247,   -38,   -38,   -38,
     -38,   248,   249,   -38,   -38,   250,   -38,   -38,   -38,   -38,
     -38,   -38,   251,   252,   -38,   -38,   253,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,    77,   -38,   100,   100,
     254,   255,   256,   257,   258,   259,   -38,   260,   102,   102,
     261,   263,   264,   265,   266,   267,   262,   100,   100,   100,
     268,   269,   270,   -38,   102,   102,   102,   272,   273,   274,
     277,   278,   279,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   100,   100,   314,   102,
     102,   100,   102
  };

  const unsigned char
  BisonDictionaryTextParser::yydefact_[] =
  {
       0,     0,     0,     0,     1,   127,     0,   128,     0,   129,
      83,     0,   130,    84,     0,   131,    85,     2,   132,   199,
      86,     0,   133,   200,     0,   134,   105,   106,     0,     4,
       0,   135,   107,   108,     3,     5,     0,   136,   109,   110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,   113,   114,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,   115,   116,
       0,     0,    25,     0,     0,   117,   118,     0,     0,    26,
       0,     0,   119,   120,    22,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   122,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,   123,   124,     0,
      27,     0,    28,     0,    29,     0,    30,     0,    31,     0,
      32,     0,    33,     0,    34,     0,    35,     0,    36,     0,
      37,     0,    38,     0,    39,     0,    40,     0,    41,     0,
      42,     0,     0,    44,     0,   125,   126,    64,     0,     0,
      75,    76,     0,     0,     0,     0,    87,    88,     0,     0,
      99,     0,     0,     0,     0,     0,     0,   138,   139,     0,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    46,    77,    78,    47,    66,    48,
      67,    89,    90,    49,    68,   100,    50,    69,    51,    70,
      52,    71,   140,   141,    53,    72,   179,    54,    73,    55,
      56,    57,    58,    59,    60,    61,     0,    63,    79,    80,
      91,    92,   101,   142,   143,   180,    43,     0,    81,    82,
      93,    94,   102,   144,   145,   181,     0,    95,    96,   103,
     146,   147,   182,    62,    97,    98,   104,   148,   149,   183,
     150,   151,   184,   152,   153,   185,   154,   155,   186,   156,
     157,   187,   158,   159,   188,   160,   161,   189,   162,   163,
     190,   164,   165,   191,   166,   167,   192,   168,   169,   193,
     170,   171,   194,   172,   173,   195,   174,   175,   196,   176,
     177,   197,   198
  };

  const short int
  BisonDictionaryTextParser::yypgoto_[] =
  {
     -38,   -38,   -38,   315,   -38,   -38,   -26,   -38,   -38,   -38,
     -13,   -38,   -38,   -22,   -12,   -38,   -38,   -37
  };

  const short int
  BisonDictionaryTextParser::yydefgoto_[] =
  {
      -1,     2,    21,    28,    29,    97,   101,   102,   103,   203,
      11,   209,   212,   104,     6,   220,   223,    20
  };

  const unsigned short int
  BisonDictionaryTextParser::yytable_[] =
  {
      57,    17,    30,   155,    75,     4,   156,    30,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    76,    53,    54,    55,   198,     1,   153,   199,     8,
      56,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   154,   130,   131,   132,   200,   201,
     202,    26,    27,   133,   206,   207,   208,    26,    27,   213,
     217,   218,   219,    10,   210,   204,   211,     5,   221,   215,
     222,   136,   137,     3,   160,   161,   109,   110,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   193,   194,
     276,   277,     5,     7,     9,    10,    12,    13,    14,    15,
     195,   196,    16,    18,    19,    22,    23,    24,    25,    31,
      32,    33,    96,    37,    34,    38,    39,    58,    59,   100,
      36,   231,    60,    61,    62,    63,    64,    65,    66,   214,
      67,    68,   205,    69,    70,    71,    72,    73,    74,    78,
      79,   216,    77,     0,     0,     0,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    98,    99,   105,   106,   108,   112,
     111,   107,   113,   134,     0,   135,   157,   158,   235,   114,
     115,   116,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   159,   192,   224,
     225,   226,     0,   197,   227,   228,   229,   230,   232,   236,
     233,   278,   279,   241,   242,     0,   234,   237,   245,   238,
     239,   240,   252,   253,   243,   244,   246,     0,   247,   248,
     294,   295,   296,   249,   250,   251,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   266,   265,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   280,   281,
     282,   283,   284,   285,     0,   287,   286,   288,   289,   290,
     291,   292,   297,   298,   299,   293,   300,   301,   302,   339,
     340,   303,   304,   305,   342,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   341,     0,
       0,     0,     0,     0,    35
  };

  const short int
  BisonDictionaryTextParser::yycheck_[] =
  {
      37,    14,    24,    27,    27,     0,    30,    29,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    44,    19,    20,    21,    23,     3,    27,    26,    35,
      27,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    44,    19,    20,    21,    24,    25,
      26,    24,    25,    27,    24,    25,    26,    24,    25,    26,
      24,    25,    26,    24,    24,    26,    26,    24,    24,    26,
      26,    33,    34,    27,    33,    34,   102,   103,    33,    34,
      33,    34,    33,    34,    33,    34,    33,    34,    33,    34,
      33,    34,    33,    34,    33,    34,    33,    34,    33,    34,
      33,    34,    33,    34,    33,    34,    33,    34,    33,    34,
      33,    34,    24,    24,    24,    24,    24,    24,    35,    24,
     157,   158,    24,    24,    24,    24,    24,    30,    24,    24,
      24,    24,    22,    24,    31,    24,    24,    24,    24,    45,
      32,    45,    27,    27,    27,    27,    27,    27,    27,   171,
      27,    27,   165,    27,    27,    27,    27,    27,    27,    24,
      24,   173,    30,    -1,    -1,    -1,    33,    33,    -1,    -1,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    24,    24,    24,    24,    31,    24,
      32,    27,    24,    24,    -1,    24,    24,    24,    24,    33,
      33,    31,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    26,    22,    26,
      26,    26,    -1,    33,    26,    26,    26,    26,    26,    24,
      33,   268,   269,    24,    24,    -1,    33,    33,    24,    33,
      33,    33,    24,    24,    33,    33,    33,    -1,    33,    33,
     287,   288,   289,    33,    33,    33,    33,    33,    24,    33,
      33,    33,    33,    33,    33,    33,    33,    27,    33,    33,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    -1,    24,    26,    24,    24,    24,
      24,    24,    24,    24,    24,    33,    24,    24,    24,   336,
     337,    24,    24,    24,   341,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    -1,
      -1,    -1,    -1,    -1,    29
  };

  const unsigned char
  BisonDictionaryTextParser::yystos_[] =
  {
       0,     3,    47,    27,     0,    24,    60,    24,    35,    24,
      24,    56,    24,    24,    35,    24,    24,    56,    24,    24,
      63,    48,    24,    24,    30,    24,    24,    25,    49,    50,
      59,    24,    24,    24,    31,    49,    32,    24,    24,    24,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    19,    20,    21,    27,    63,    24,    24,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    44,    30,    24,    24,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    22,    51,    24,    24,
      45,    52,    53,    54,    59,    24,    24,    27,    31,    52,
      52,    32,    24,    24,    33,    33,    31,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      19,    20,    21,    27,    24,    24,    33,    34,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    44,    27,    30,    24,    24,    26,
      33,    34,    33,    34,    33,    34,    33,    34,    33,    34,
      33,    34,    33,    34,    33,    34,    33,    34,    33,    34,
      33,    34,    33,    34,    33,    34,    33,    34,    33,    34,
      33,    34,    22,    33,    34,    63,    63,    33,    23,    26,
      24,    25,    26,    55,    26,    56,    24,    25,    26,    57,
      24,    26,    58,    26,    59,    26,    60,    24,    25,    26,
      61,    24,    26,    62,    26,    26,    26,    26,    26,    26,
      26,    45,    26,    33,    33,    24,    24,    33,    33,    33,
      33,    24,    24,    33,    33,    24,    33,    33,    33,    33,
      33,    33,    24,    24,    33,    33,    24,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    27,    33,    24,    24,
      24,    24,    24,    24,    24,    24,    33,    34,    63,    63,
      24,    24,    24,    24,    24,    24,    26,    24,    24,    24,
      24,    24,    24,    33,    63,    63,    63,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    63,
      63,    24,    63
  };

  const unsigned char
  BisonDictionaryTextParser::yyr1_[] =
  {
       0,    46,    48,    47,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    50,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      58,    58,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63
  };

  const unsigned char
  BisonDictionaryTextParser::yyr2_[] =
  {
       0,     2,     0,    11,     1,     2,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     8,     0,     8,     1,     2,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     8,     5,     4,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,    10,     7,     6,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     4,     1,     1,     2,     2,     3,
       3,     4,     4,     1,     2,     3,     4,     1,     1,     2,
       2,     3,     3,     4,     4,     5,     5,     6,     6,     1,
       2,     3,     4,     5,     6,     1,     1,     2,     2,     3,
       3,     4,     4,     5,     5,     6,     6,     7,     7,     8,
       8,     9,     9,    10,    10,    11,    11,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     1,     1,
       2,     2,     3,     3,     4,     4,     5,     5,     6,     6,
       7,     7,     8,     8,     9,     9,    10,    10,    11,    11,
      12,    12,    13,    13,    14,    14,    15,    15,    16,    16,
      17,    17,    18,    18,    19,    19,    20,    20,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     1,
       2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const BisonDictionaryTextParser::yytname_[] =
  {
  "$end", "error", "$undefined", "USDS", "DICTIONARY_VERSION",
  "\"BOOLEAN\"", "\"BYTE\"", "\"UBYTE\"", "\"SHORT\"", "\"USHORT\"",
  "\"INT\"", "\"UINT\"", "\"LONG\"", "\"ULONG\"", "\"INT128\"",
  "\"UINT128\"", "\"FLOAT\"", "\"\"", "DOUBLE", "\"VARINT\"",
  "\"UVARINT\"", "\"STRING\"", "\"<Text encode>\"", "\"true or false\"",
  "\"Digit\"", "\"-Digit\"", "\"NULL\"", "\"object name\"",
  "USDS_RESTRICT", "\"notRoot\"", "'{'", "'}'", "':'", "';'", "'='", "'.'",
  "\"int8_t\"", "\"uint8_t\"", "\"int16_t\"", "\"uint16_t\"",
  "\"int32_t\"", "\"uint32_t\"", "\"int64_t\"", "\"uint64_t\"", "'<'",
  "'>'", "$accept", "dictionary", "$@1", "tags", "tag", "$@2", "fields",
  "field", "struct_begin", "INT8_T", "UINT8_T", "INT16_T", "UINT16_T",
  "INT32_T", "UINT32_T", "INT64_T", "UINT64_T", "digits", YY_NULL
  };

#if DICTIONARY_TEXTDEBUG
  const unsigned short int
  BisonDictionaryTextParser::yyrline_[] =
  {
       0,   125,   125,   124,   139,   139,   141,   145,   149,   153,
     157,   161,   165,   169,   173,   177,   181,   185,   189,   193,
     197,   201,   205,   211,   210,   223,   223,   226,   230,   234,
     238,   242,   246,   250,   254,   258,   262,   266,   270,   274,
     278,   282,   286,   290,   295,   300,   307,   312,   317,   322,
     327,   332,   337,   342,   347,   352,   357,   362,   367,   372,
     377,   382,   387,   393,   399,   406,   411,   416,   421,   426,
     431,   436,   441,   446,   454,   464,   468,   472,   476,   480,
     493,   506,   510,   517,   521,   525,   538,   548,   552,   556,
     562,   568,   575,   582,   590,   598,   614,   630,   634,   641,
     645,   651,   658,   666,   682,   692,   696,   700,   706,   712,
     719,   726,   734,   742,   751,   760,   770,   780,   791,   802,
     814,   826,   839,   852,   873,   894,   898,   905,   909,   915,
     922,   930,   939,   949,   960,   972,   985,  1006,  1016,  1020,
    1024,  1030,  1036,  1043,  1050,  1058,  1066,  1075,  1084,  1094,
    1104,  1115,  1126,  1138,  1150,  1163,  1176,  1190,  1204,  1220,
    1236,  1253,  1270,  1288,  1306,  1325,  1344,  1364,  1384,  1405,
    1426,  1448,  1470,  1493,  1516,  1545,  1574,  1580,  1589,  1593,
    1599,  1606,  1614,  1623,  1633,  1644,  1656,  1669,  1683,  1699,
    1716,  1734,  1753,  1773,  1794,  1816,  1839,  1863,  1897,  1905,
    1905
  };

  // Print the state stack on the debug stream.
  void
  BisonDictionaryTextParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  BisonDictionaryTextParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // DICTIONARY_TEXTDEBUG

  // Symbol number corresponding to token number t.
  inline
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
       2,     2,     2,     2,     2,     2,    35,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    33,
      44,    34,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    36,    37,    38,    39,    40,
      41,    42,    43
    };
    const unsigned int user_token_number_max_ = 292;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 36 "bisonDictionaryTextParser.y" // lalr1.cc:1156
} // usds
#line 3737 "bisonDictionaryTextParser.cc" // lalr1.cc:1156
#line 1907 "bisonDictionaryTextParser.y" // lalr1.cc:1157

//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

