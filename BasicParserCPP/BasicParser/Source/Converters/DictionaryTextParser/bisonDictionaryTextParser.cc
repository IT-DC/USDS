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
#line 128 "bisonDictionaryTextParser.y" // lalr1.cc:406

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
#line 138 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setID(input_text + (yystack_[5].value.stringVal)[0], (yystack_[5].value.stringVal)[1], (yystack_[4].value.uInt32Val), (yystack_[2].value.uInt8Val), (yystack_[0].value.uInt8Val));
	}
#line 627 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 3:
#line 142 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		// Finilize dictionary
		dict->finalizeDictionary();
	}
#line 636 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 6:
#line 155 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 644 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 7:
#line 159 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 652 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 8:
#line 163 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 660 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 9:
#line 167 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 668 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 10:
#line 171 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 676 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 11:
#line 175 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 684 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 12:
#line 179 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 692 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 13:
#line 183 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 700 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 14:
#line 187 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 708 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 15:
#line 191 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 716 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 16:
#line 195 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 724 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 17:
#line 199 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 732 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 18:
#line 203 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 740 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 19:
#line 207 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 748 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 20:
#line 211 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 756 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 21:
#line 215 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 764 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 22:
#line 219 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[5].value.typeVal), (yystack_[7].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)tag)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 773 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 23:
#line 224 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_STRUCT, (yystack_[3].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 781 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 24:
#line 228 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
	
	}
#line 789 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 25:
#line 234 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 803 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 26:
#line 244 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 817 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 27:
#line 254 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 831 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 28:
#line 264 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 845 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 29:
#line 274 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 859 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 30:
#line 284 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 873 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 31:
#line 294 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 887 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 32:
#line 304 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 901 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 33:
#line 314 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 915 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 34:
#line 324 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 929 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 35:
#line 334 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 943 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 36:
#line 344 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 957 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 37:
#line 354 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 971 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 38:
#line 364 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 985 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 39:
#line 374 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 999 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 40:
#line 384 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1013 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 41:
#line 394 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[8].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		usds::DictionaryString* string_element = (usds::DictionaryString*)arr_tag->setElementType((yystack_[6].value.typeVal));
		string_element->setDefaultEncode((yystack_[4].value.encodeVal));
	}
#line 1028 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 42:
#line 405 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[4].value.int32Val), input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		// for fields
		tag = arr_tag->setElementType(USDS_STRUCT);
	}
#line 1043 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 43:
#line 416 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
	
	}
#line 1051 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 46:
#line 428 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1059 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 47:
#line 432 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1067 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 48:
#line 436 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1075 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 49:
#line 440 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1083 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 50:
#line 444 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1091 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 51:
#line 448 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1099 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 52:
#line 452 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1107 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 53:
#line 456 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1115 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 54:
#line 460 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1123 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 55:
#line 464 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1131 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 56:
#line 468 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1139 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 57:
#line 472 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1147 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 58:
#line 476 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1155 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 59:
#line 480 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1163 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 60:
#line 484 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1171 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 61:
#line 488 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1179 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 62:
#line 492 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField((yystack_[5].value.typeVal), (yystack_[7].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)field)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 1188 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 63:
#line 497 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
	}
#line 1197 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 64:
#line 502 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = tag->getParent();
	}
#line 1205 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 65:
#line 508 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1218 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 66:
#line 517 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1231 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 67:
#line 526 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1244 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 68:
#line 535 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1257 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 69:
#line 544 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1270 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 70:
#line 553 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1283 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 71:
#line 562 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1296 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 72:
#line 571 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1309 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 73:
#line 580 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1322 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 74:
#line 589 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1335 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 75:
#line 598 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1348 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 76:
#line 607 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1361 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 77:
#line 616 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1374 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 78:
#line 625 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1387 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 79:
#line 634 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1400 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 80:
#line 643 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1413 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 81:
#line 652 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[8].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryString* element = (DictionaryString*)arr_field->setElementType((yystack_[6].value.typeVal));	
		element->setDefaultEncode((yystack_[4].value.encodeVal));
	}
#line 1427 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 82:
#line 662 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i <= (yystack_[3].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
	}
#line 1438 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 83:
#line 669 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryTagLink* element = (DictionaryTagLink*)arr_field->setElementType(usds::USDS_TAG);
		element->setTag(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
	}
#line 1452 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 84:
#line 682 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1461 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 85:
#line 687 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1470 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 86:
#line 692 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1479 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 87:
#line 697 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1488 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 88:
#line 702 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1497 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 89:
#line 707 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1506 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 90:
#line 712 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1515 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 91:
#line 717 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1524 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 92:
#line 722 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1533 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 93:
#line 727 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1542 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 94:
#line 732 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1551 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 95:
#line 737 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1560 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 96:
#line 742 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1569 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 97:
#line 747 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1578 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 98:
#line 752 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1587 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 99:
#line 757 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1596 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 100:
#line 762 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), (yystack_[9].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryString*)dict_field)->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setNullable(true);
	}
#line 1606 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 101:
#line 768 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[4].value.stringVal)[0], (yystack_[4].value.stringVal)[1]);
		field->setNullable(true);
	}
#line 1616 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 102:
#line 774 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 1625 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 103:
#line 781 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1639 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 104:
#line 791 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1653 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 105:
#line 801 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1667 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 106:
#line 811 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1681 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 107:
#line 821 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1695 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 108:
#line 831 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1709 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 109:
#line 841 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1723 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 110:
#line 851 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1737 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 111:
#line 861 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1751 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 112:
#line 871 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1765 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 113:
#line 881 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1779 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 114:
#line 891 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1793 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 115:
#line 901 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1807 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 116:
#line 911 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1821 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 117:
#line 921 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1835 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 118:
#line 931 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1849 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 119:
#line 941 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[10].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryString* element = (DictionaryString*)arr_field->setElementType((yystack_[8].value.typeVal));	
		element->setDefaultEncode((yystack_[6].value.encodeVal));
	}
#line 1864 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 120:
#line 952 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i < (yystack_[5].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 1877 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 121:
#line 961 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryTagLink* element = (DictionaryTagLink*)arr_field->setElementType(usds::USDS_TAG);
		element->setTag(input_text + (yystack_[5].value.stringVal)[0], (yystack_[5].value.stringVal)[1]);
	}
#line 1892 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 122:
#line 974 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBoolean* dict_field = (usds::DictionaryBoolean*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.boolVal));
	}
#line 1901 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 123:
#line 979 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryByte* dict_field = (usds::DictionaryByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int8Val));
	}
#line 1910 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 124:
#line 984 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUByte* dict_field = (usds::DictionaryUByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt8Val));
	}
#line 1919 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 125:
#line 989 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryShort* dict_field = (usds::DictionaryShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int16Val));
	}
#line 1928 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 126:
#line 994 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUShort* dict_field = (usds::DictionaryUShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt16Val));
	}
#line 1937 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 127:
#line 999 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryInt* dict_field = (usds::DictionaryInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int32Val));
	}
#line 1946 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 128:
#line 1004 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUInt* dict_field = (usds::DictionaryUInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt32Val));
	}
#line 1955 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 129:
#line 1009 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryLong* dict_field = (usds::DictionaryLong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 1964 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 130:
#line 1014 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryULong* dict_field = (usds::DictionaryULong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 1973 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 131:
#line 1019 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryFloat* dict_field = (usds::DictionaryFloat*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((float)(yystack_[1].value.doubleVal));
	}
#line 1982 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 132:
#line 1024 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryDouble* dict_field = (usds::DictionaryDouble*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.doubleVal));
	}
#line 1991 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 133:
#line 1029 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 2000 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 134:
#line 1034 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 2009 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 135:
#line 1039 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2018 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 136:
#line 1044 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), (yystack_[9].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2028 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 137:
#line 1053 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, (yystack_[3].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2036 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 138:
#line 1060 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[4].value.int32Val), input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_STRUCT);
		(yylhs.value.uInt32Val) = (yystack_[1].value.uInt32Val);
	}
#line 2050 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 139:
#line 1073 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 1;
	}
#line 2058 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 140:
#line 1077 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (yylhs.value.uInt32Val) + 1;
	}
#line 2066 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 141:
#line 1088 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[0].value.int8Val);
	}
#line 2074 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 142:
#line 1092 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[0].value.int8Val);
	}
#line 2082 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 143:
#line 1096 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val) * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
	}
#line 2090 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 144:
#line 1100 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val) * (int8_t)10 - (int8_t)(yystack_[0].value.int8Val);
	}
#line 2098 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 145:
#line 1104 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) > (int8_t)1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";

		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)1 && (yylhs.value.int8Val) >= (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";
		
		(yylhs.value.int8Val) = (int8_t)(yystack_[2].value.int8Val) * (int8_t)100 + (yylhs.value.int8Val);
		
	}
#line 2115 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 146:
#line 1117 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) < (int8_t)-1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";

		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)-1 && (yylhs.value.int8Val) > (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";
		
		(yylhs.value.int8Val) = (int8_t)(yystack_[2].value.int8Val) * (int8_t)100 - (yylhs.value.int8Val);
		
	}
#line 2132 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 147:
#line 1130 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int8_t: too big value";
	}
#line 2140 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 148:
#line 1134 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int8_t: too big value";
	}
#line 2148 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 149:
#line 1141 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[0].value.int8Val);
	}
#line 2156 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 150:
#line 1145 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 2164 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 151:
#line 1149 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[1].value.int8Val) * (uint8_t)10 + (uint8_t)(yystack_[0].value.int8Val);
	}
#line 2172 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 152:
#line 1153 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 2180 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 153:
#line 1157 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: too big value";

		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[1].value.int8Val)  * (uint8_t)10 + (uint8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)2 && (yylhs.value.uInt8Val) >= (uint8_t)56)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: too big value";
		
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[2].value.int8Val) * (uint8_t)100 + (yylhs.value.uInt8Val);
		
	}
#line 2197 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 154:
#line 1170 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 2205 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 155:
#line 1174 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint8_t: too big value";
	}
#line 2213 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 156:
#line 1178 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint8_t: too big value";
	}
#line 2221 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 157:
#line 1188 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = (int16_t)(yystack_[0].value.int8Val);
	}
#line 2229 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 158:
#line 1192 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = (int16_t)(yystack_[0].value.int8Val);
	}
#line 2237 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 159:
#line 1196 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 2247 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 160:
#line 1202 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 2257 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 161:
#line 1208 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 2268 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 162:
#line 1215 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 - 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 2279 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 163:
#line 1222 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 + 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 2291 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 164:
#line 1230 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 - 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 - 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 2303 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 165:
#line 1238 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[4].value.int8Val) > (int8_t)3)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int16_t: too big value";
		
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 + 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);

		if ((yystack_[4].value.int8Val) == (int8_t)3 && (yylhs.value.int16Val) >= (int16_t)2768)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int16_t: too big value";
			
		(yylhs.value.int16Val) = (yylhs.value.int16Val) + (int16_t)(yystack_[4].value.int8Val) * (int16_t)10000;
	}
#line 2323 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 166:
#line 1254 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[4].value.int8Val) < (int8_t)-3)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int16_t: too big value";
		
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 + 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);

		if ((yystack_[4].value.int8Val) == (int8_t)-3 && (yylhs.value.int16Val) > (int16_t)2768)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int16_t: too big value";
			
		(yylhs.value.int16Val) = (int16_t)(yystack_[4].value.int8Val) * (int16_t)10000 - (yylhs.value.int16Val);
	}
#line 2343 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 167:
#line 1270 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int16_t: too big value";
	}
#line 2351 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 168:
#line 1274 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int16_t: too big value";
	}
#line 2359 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 169:
#line 1281 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = (uint16_t)(yystack_[0].value.int8Val);
	}
#line 2367 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 170:
#line 1285 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 2375 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 171:
#line 1289 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 2385 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 172:
#line 1295 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 2393 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 173:
#line 1299 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[2].value.int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 2404 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 174:
#line 1306 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 2412 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 175:
#line 1310 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[3].value.int8Val) * (uint16_t)1000 + 
		(uint16_t)(yystack_[2].value.int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 2424 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 176:
#line 1318 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 2432 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 177:
#line 1322 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[4].value.int8Val) > (int8_t)6)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: too big value";
		
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[3].value.int8Val) * (uint16_t)1000 + 
		(uint16_t)(yystack_[2].value.int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);

		if ((yystack_[4].value.int8Val) == (int8_t)6 && (yylhs.value.uInt16Val) >= (uint16_t)5536)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: too big value";
			
		(yylhs.value.uInt16Val) = (yylhs.value.uInt16Val) + (uint16_t)(yystack_[4].value.int8Val) * (uint16_t)10000;
	}
#line 2452 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 178:
#line 1338 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 2460 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 179:
#line 1342 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint16_t: too big value";
	}
#line 2468 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 180:
#line 1346 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint16_t: too big value";
	}
#line 2476 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 181:
#line 1356 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = (int32_t)(yystack_[0].value.int8Val);
	}
#line 2484 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 182:
#line 1360 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = (int32_t)(yystack_[0].value.int8Val);
	}
#line 2492 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 183:
#line 1364 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2502 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 184:
#line 1370 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2512 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 185:
#line 1376 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2523 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 186:
#line 1383 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2534 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 187:
#line 1390 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2546 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 188:
#line 1398 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2558 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 189:
#line 1406 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2571 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 190:
#line 1415 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2584 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 191:
#line 1424 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2598 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 192:
#line 1434 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 - 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2612 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 193:
#line 1444 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[6].value.int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2627 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 194:
#line 1455 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[6].value.int8Val) * (int32_t)1000000 - 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 - 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2642 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 195:
#line 1466 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[7].value.int8Val) * (int32_t)10000000 + 
		(int32_t)(yystack_[6].value.int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2658 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 196:
#line 1478 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[7].value.int8Val) * (int32_t)10000000 - 
		(int32_t)(yystack_[6].value.int8Val) * (int32_t)1000000 - 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 - 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2674 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 197:
#line 1490 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[8].value.int8Val) * (int32_t)100000000 + 
		(int32_t)(yystack_[7].value.int8Val) * (int32_t)10000000 + 
		(int32_t)(yystack_[6].value.int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2691 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 198:
#line 1503 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[8].value.int8Val) * (int32_t)100000000 - 
		(int32_t)(yystack_[7].value.int8Val) * (int32_t)10000000 - 
		(int32_t)(yystack_[6].value.int8Val) * (int32_t)1000000 - 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 - 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2708 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 199:
#line 1516 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[9].value.int8Val) > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int32_t: too big value";
		
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[8].value.int8Val) * (int32_t)100000000 + 
		(int32_t)(yystack_[7].value.int8Val) * (int32_t)10000000 + 
		(int32_t)(yystack_[6].value.int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);

		if ((yystack_[9].value.int8Val) == (int8_t)2 && (yylhs.value.int32Val) >= (int32_t)147483648)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int32_t: too big value";
			
		(yylhs.value.int32Val) = (yylhs.value.int32Val) + (int32_t)(yystack_[9].value.int8Val) * (int32_t)1000000000;
	}
#line 2733 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 200:
#line 1537 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[9].value.int8Val) < (int8_t)-2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int32_t: too big value";
		
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[8].value.int8Val) * (int32_t)100000000 + 
		(int32_t)(yystack_[7].value.int8Val) * (int32_t)10000000 + 
		(int32_t)(yystack_[6].value.int8Val) * (int32_t)1000000 + 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);

		if ((yystack_[9].value.int8Val) == (int8_t)-2 && (yylhs.value.int32Val) > (int32_t)147483648)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int32_t: too big value";
			
		(yylhs.value.int32Val) = (int32_t)(yystack_[9].value.int8Val) * (int32_t)1000000000 - (yylhs.value.int32Val);
	}
#line 2758 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 201:
#line 1558 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int32_t: too big value";
	}
#line 2766 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 202:
#line 1562 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int32_t: too big value";
	}
#line 2774 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 203:
#line 1569 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (uint32_t)(yystack_[0].value.int8Val);
	}
#line 2782 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 204:
#line 1573 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2790 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 205:
#line 1577 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2800 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 206:
#line 1583 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2808 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 207:
#line 1587 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2819 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 208:
#line 1594 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2827 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 209:
#line 1598 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2839 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 210:
#line 1606 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2847 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 211:
#line 1610 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2860 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 212:
#line 1619 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2868 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 213:
#line 1623 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[5].value.int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2882 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 214:
#line 1633 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2890 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 215:
#line 1637 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[6].value.int8Val) * (uint32_t)1000000 + 
		(uint32_t)(yystack_[5].value.int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2905 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 216:
#line 1648 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2913 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 217:
#line 1652 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[7].value.int8Val) * (uint32_t)10000000 + 
		(uint32_t)(yystack_[6].value.int8Val) * (uint32_t)1000000 + 
		(uint32_t)(yystack_[5].value.int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2929 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 218:
#line 1664 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2937 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 219:
#line 1668 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[8].value.int8Val) * (uint32_t)100000000 + 
		(uint32_t)(yystack_[7].value.int8Val) * (uint32_t)10000000 + 
		(uint32_t)(yystack_[6].value.int8Val) * (uint32_t)1000000 + 
		(uint32_t)(yystack_[5].value.int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2954 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 220:
#line 1681 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2962 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 221:
#line 1685 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[9].value.int8Val) > (int8_t)4)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: too big value";
		
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[8].value.int8Val) * (uint32_t)100000000 + 
		(uint32_t)(yystack_[7].value.int8Val) * (uint32_t)10000000 + 
		(uint32_t)(yystack_[6].value.int8Val) * (uint32_t)1000000 + 
		(uint32_t)(yystack_[5].value.int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);

		if ((yystack_[9].value.int8Val) == (int8_t)4 && (yylhs.value.uInt32Val) >= (uint32_t)294967296)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: too big value";
			
		(yylhs.value.uInt32Val) = (yylhs.value.uInt32Val) + (uint32_t)(yystack_[9].value.int8Val) * (uint32_t)1000000000;
	}
#line 2987 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 222:
#line 1706 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2995 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 223:
#line 1710 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint32_t: too big value";
	}
#line 3003 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 224:
#line 1714 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint32_t: negative value";
	}
#line 3011 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 225:
#line 1724 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = (int64_t)(yystack_[0].value.int8Val);
	}
#line 3019 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 226:
#line 1728 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = (int64_t)(yystack_[0].value.int8Val);
	}
#line 3027 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 227:
#line 1732 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3037 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 228:
#line 1738 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3047 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 229:
#line 1744 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3058 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 230:
#line 1751 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3069 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 231:
#line 1758 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3081 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 232:
#line 1766 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3093 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 233:
#line 1774 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3106 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 234:
#line 1783 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3119 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 235:
#line 1792 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3133 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 236:
#line 1802 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3147 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 237:
#line 1812 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3162 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 238:
#line 1823 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3177 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 239:
#line 1834 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3193 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 240:
#line 1846 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 - 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3209 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 241:
#line 1858 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3226 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 242:
#line 1871 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 - 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 - 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3243 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 243:
#line 1884 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3261 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 244:
#line 1898 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 - 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 - 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 - 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3279 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 245:
#line 1913 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3298 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 246:
#line 1929 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 - 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 - 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 - 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 - 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3317 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 247:
#line 1945 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3337 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 248:
#line 1962 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 - 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 - 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 - 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 - 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 - 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3357 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 249:
#line 1979 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3378 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 250:
#line 1997 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 - 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 - 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 - 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 - 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 - 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 - 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3399 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 251:
#line 2015 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3421 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 252:
#line 2034 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 - 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 - 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 - 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 - 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 - 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 - 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 - 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3443 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 253:
#line 2053 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[14].value.int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3466 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 254:
#line 2073 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[14].value.int8Val) * (int64_t)100000000000000 - 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 - 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 - 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 - 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 - 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 - 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 - 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 - 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3489 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 255:
#line 2093 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[15].value.int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3513 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 256:
#line 2114 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[15].value.int8Val) * (int64_t)1000000000000000 - 
		(int64_t)(yystack_[14].value.int8Val) * (int64_t)100000000000000 - 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 - 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 - 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 - 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 - 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 - 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 - 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 - 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3537 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 257:
#line 2135 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[16].value.int8Val) * (int64_t)10000000000000000 + 
		(int64_t)(yystack_[15].value.int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3562 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 258:
#line 2157 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[16].value.int8Val) * (int64_t)10000000000000000 - 
		(int64_t)(yystack_[15].value.int8Val) * (int64_t)1000000000000000 - 
		(int64_t)(yystack_[14].value.int8Val) * (int64_t)100000000000000 - 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 - 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 - 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 - 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 - 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 - 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 - 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 - 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3587 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 259:
#line 2179 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[17].value.int8Val) * (int64_t)100000000000000000 + 
		(int64_t)(yystack_[16].value.int8Val) * (int64_t)10000000000000000 + 
		(int64_t)(yystack_[15].value.int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3613 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 260:
#line 2202 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[17].value.int8Val) * (int64_t)100000000000000000 - 
		(int64_t)(yystack_[16].value.int8Val) * (int64_t)10000000000000000 - 
		(int64_t)(yystack_[15].value.int8Val) * (int64_t)1000000000000000 - 
		(int64_t)(yystack_[14].value.int8Val) * (int64_t)100000000000000 - 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 - 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 - 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 - 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 - 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 - 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 - 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 - 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 - 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 3639 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 261:
#line 2225 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[17].value.int8Val) * (int64_t)100000000000000000 + 
		(int64_t)(yystack_[16].value.int8Val) * (int64_t)10000000000000000 + 
		(int64_t)(yystack_[15].value.int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);

		if ((yystack_[18].value.int8Val) == (int8_t)9 && (yylhs.value.int64Val) >= (int64_t)223372036854775808)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int64_t: too big value";
			
		(yylhs.value.int64Val) = (yylhs.value.int64Val) + (int64_t)(yystack_[18].value.int8Val) * (int64_t)1000000000000000000;
	}
#line 3671 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 262:
#line 2254 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[17].value.int8Val) * (int64_t)100000000000000000 + 
		(int64_t)(yystack_[16].value.int8Val) * (int64_t)10000000000000000 + 
		(int64_t)(yystack_[15].value.int8Val) * (int64_t)1000000000000000 + 
		(int64_t)(yystack_[14].value.int8Val) * (int64_t)100000000000000 + 
		(int64_t)(yystack_[13].value.int8Val) * (int64_t)10000000000000 + 
		(int64_t)(yystack_[12].value.int8Val) * (int64_t)1000000000000 + 
		(int64_t)(yystack_[11].value.int8Val) * (int64_t)100000000000 + 
		(int64_t)(yystack_[10].value.int8Val) * (int64_t)10000000000 + 
		(int64_t)(yystack_[9].value.int8Val) * (int64_t)1000000000 + 
		(int64_t)(yystack_[8].value.int8Val) * (int64_t)100000000 + 
		(int64_t)(yystack_[7].value.int8Val) * (int64_t)10000000 + 
		(int64_t)(yystack_[6].value.int8Val) * (int64_t)1000000 + 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);

		if ((yystack_[18].value.int8Val) == (int8_t)-9 && (yylhs.value.int64Val) > (int64_t)223372036854775808)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int64_t: too big value";
			
		(yylhs.value.int64Val) = (int64_t)(yystack_[18].value.int8Val) * (int64_t)1000000000000000000 - (yylhs.value.int64Val);
	}
#line 3703 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 263:
#line 2283 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int64_t: too big value";
	}
#line 3712 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 264:
#line 2289 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int64_t: too big value";
	}
#line 3721 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 265:
#line 2297 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = (uint64_t)(yystack_[0].value.int8Val);
	}
#line 3729 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 266:
#line 2301 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3737 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 267:
#line 2305 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3747 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 268:
#line 2311 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3755 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 269:
#line 2315 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3766 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 270:
#line 2322 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3774 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 271:
#line 2326 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3786 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 272:
#line 2334 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3794 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 273:
#line 2338 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3807 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 274:
#line 2347 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3815 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 275:
#line 2351 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3829 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 276:
#line 2361 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3837 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 277:
#line 2365 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3852 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 278:
#line 2376 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3860 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 279:
#line 2380 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3876 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 280:
#line 2392 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3884 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 281:
#line 2396 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3901 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 282:
#line 2409 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3909 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 283:
#line 2413 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[9].value.int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3927 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 284:
#line 2427 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3935 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 285:
#line 2432 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[10].value.int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3954 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 286:
#line 2448 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) 
			<< (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3963 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 287:
#line 2454 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[11].value.int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3983 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 288:
#line 2471 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) 
			<< (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3992 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 289:
#line 2477 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[12].value.int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 4013 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 290:
#line 2495 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) 
			<< (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 4022 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 291:
#line 2501 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[13].value.int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 4044 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 292:
#line 2520 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) 
			<< (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 4053 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 293:
#line 2526 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[14].value.int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 4076 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 294:
#line 2546 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) 
			<< (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 4085 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 295:
#line 2552 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[15].value.int8Val) * (uint64_t)1000000000000000 + 
		(uint64_t)(yystack_[14].value.int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 4109 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 296:
#line 2573 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) 
			<< (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 4118 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 297:
#line 2579 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[16].value.int8Val) * (uint64_t)10000000000000000 + 
		(uint64_t)(yystack_[15].value.int8Val) * (uint64_t)1000000000000000 + 
		(uint64_t)(yystack_[14].value.int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 4143 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 298:
#line 2601 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) 
			<< (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 4152 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 299:
#line 2607 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[17].value.int8Val) * (uint64_t)100000000000000000 + 
		(uint64_t)(yystack_[16].value.int8Val) * (uint64_t)10000000000000000 + 
		(uint64_t)(yystack_[15].value.int8Val) * (uint64_t)1000000000000000 + 
		(uint64_t)(yystack_[14].value.int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 4178 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 300:
#line 2630 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) 
			<< (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 4187 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 301:
#line 2636 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[18].value.int8Val) * (uint64_t)1000000000000000000 + 
		(uint64_t)(yystack_[17].value.int8Val) * (uint64_t)100000000000000000 + 
		(uint64_t)(yystack_[16].value.int8Val) * (uint64_t)10000000000000000 + 
		(uint64_t)(yystack_[15].value.int8Val) * (uint64_t)1000000000000000 + 
		(uint64_t)(yystack_[14].value.int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 4214 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 302:
#line 2660 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) 
			<< (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 4223 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 303:
#line 2666 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[19].value.int8Val) > (int8_t)1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: too big value";

		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[18].value.int8Val) * (uint64_t)1000000000000000000 + 
		(uint64_t)(yystack_[17].value.int8Val) * (uint64_t)100000000000000000 + 
		(uint64_t)(yystack_[16].value.int8Val) * (uint64_t)10000000000000000 + 
		(uint64_t)(yystack_[15].value.int8Val) * (uint64_t)1000000000000000 + 
		(uint64_t)(yystack_[14].value.int8Val) * (uint64_t)100000000000000 + 
		(uint64_t)(yystack_[13].value.int8Val) * (uint64_t)10000000000000 + 
		(uint64_t)(yystack_[12].value.int8Val) * (uint64_t)1000000000000 + 
		(uint64_t)(yystack_[11].value.int8Val) * (uint64_t)100000000000 + 
		(uint64_t)(yystack_[10].value.int8Val) * (uint64_t)10000000000 + 
		(uint64_t)(yystack_[9].value.int8Val) * (uint64_t)1000000000 + 
		(uint64_t)(yystack_[8].value.int8Val) * (uint64_t)100000000 + 
		(uint64_t)(yystack_[7].value.int8Val) * (uint64_t)10000000 + 
		(uint64_t)(yystack_[6].value.int8Val) * (uint64_t)1000000 + 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);

		if ((yystack_[19].value.int8Val) == (int8_t)1 && (yylhs.value.uInt64Val) >= (uint64_t)8446744073709551616)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: too big value";
			
		(yylhs.value.uInt64Val) = (yylhs.value.uInt64Val) + (uint64_t)(yystack_[19].value.int8Val) * (uint64_t)10000000000000000000;
	}
#line 4260 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 304:
#line 2700 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) 
			<< (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 4269 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 305:
#line 2706 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[20].value.int8Val) << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint64_t: too big value";
	}
#line 4278 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 306:
#line 2712 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[20].value.int8Val) << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) 
			<< (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint64_t: negative value";
	}
#line 4287 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 309:
#line 2726 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.doubleVal);
	}
#line 4295 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 310:
#line 2730 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.doubleVal);
	}
#line 4303 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 311:
#line 2734 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[2].value.doubleVal) + (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 4311 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 312:
#line 2738 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[2].value.doubleVal) - (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 4319 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 313:
#line 2742 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = - (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;	
	}
#line 4327 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 314:
#line 2746 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 4335 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 315:
#line 2750 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[3].value.doubleVal) + (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 4343 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 316:
#line 2754 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[3].value.doubleVal) - (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 4351 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 317:
#line 2758 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (- (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));	
	}
#line 4359 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 318:
#line 2762 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 4367 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 319:
#line 2769 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 4375 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 320:
#line 2773 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yylhs.value.doubleVal) * 10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 4383 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 321:
#line 2780 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 4391 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 322:
#line 2784 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yylhs.value.doubleVal) * 10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 4399 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 323:
#line 2791 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.floatDigits).value = (double)(yystack_[0].value.int8Val);
		(yylhs.value.floatDigits).digits = 10.0;
	}
#line 4408 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 324:
#line 2796 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.floatDigits).value = (yylhs.value.floatDigits).value * 10.0 + (double)(yystack_[0].value.int8Val);
		(yylhs.value.floatDigits).digits = (yylhs.value.floatDigits).digits * 10.0;
	}
#line 4417 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 325:
#line 2804 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 4425 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 326:
#line 2808 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 4433 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 327:
#line 2812 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[1].value.int8Val) * (double)10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 4441 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 328:
#line 2816 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[1].value.int8Val) * (double)10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 4449 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 329:
#line 2820 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[2].value.int8Val) * (double)100.0 + (double)(yystack_[1].value.int8Val) * (double)10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 4457 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 330:
#line 2824 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[2].value.int8Val) * (double)100.0 - (double)(yystack_[1].value.int8Val) * (double)10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 4465 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;


#line 4469 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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


  const short int BisonDictionaryTextParser::yypact_ninf_ = -227;

  const signed char BisonDictionaryTextParser::yytable_ninf_ = -1;

  const short int
  BisonDictionaryTextParser::yypact_[] =
  {
     119,    -2,    23,   159,  -227,    11,   194,   185,   199,   203,
     233,   239,   280,   360,   361,   350,   363,   364,   365,   366,
     233,   367,   368,   369,   369,  -227,   370,   371,  -227,   372,
     372,     2,   373,   374,  -227,   276,   375,   376,   377,   378,
     379,   276,   380,   381,   382,   383,   384,  -227,  -227,   228,
     369,   369,   385,   386,    10,    14,    15,    16,    17,    18,
      19,    20,    22,    24,    25,    27,    28,    29,    30,    -5,
     160,   372,   372,   388,   390,   387,   347,    31,   389,    33,
     391,    39,   392,    40,   393,    41,   394,    49,   395,    51,
     396,    54,   397,    60,   398,    62,   399,    63,   400,    64,
     401,    65,   402,    66,   403,    70,   404,   417,    71,  -227,
     163,   416,   418,  -227,  -227,   407,   358,  -227,   411,  -227,
     412,  -227,   413,  -227,   414,  -227,   415,  -227,   419,  -227,
     420,  -227,   421,  -227,   422,  -227,   423,  -227,   424,  -227,
     425,  -227,   426,  -227,   427,  -227,   362,   428,   276,  -227,
     439,   440,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,    72,  -227,
     433,   276,   276,   276,   434,   276,   442,   444,   435,    73,
     436,  -227,   441,   443,   259,   445,   447,   448,  -227,   446,
    -227,   268,   271,    74,    75,    76,    78,    80,    81,    83,
     105,   107,   110,   129,   130,   131,   132,   134,     6,     8,
     449,   450,   452,  -227,  -227,   453,  -227,   455,   273,   136,
     275,   137,   277,   139,   279,   140,   281,   141,   283,   142,
     285,   143,   287,   144,   289,   145,   291,   146,   293,   147,
     295,   148,   297,   149,   299,   150,   301,   151,   303,   429,
     152,   306,  -227,     9,  -227,   369,   369,   451,   454,  -227,
      91,   308,  -227,   187,   310,  -227,   205,   312,  -227,   226,
     314,  -227,   229,   316,  -227,   236,   318,  -227,   257,   320,
    -227,   260,   322,  -227,   264,   324,  -227,   456,   326,  -227,
     458,   328,  -227,    -4,   330,  -227,     5,   332,  -227,   267,
     334,  -227,   270,   336,  -227,   346,   431,   340,  -227,   461,
     342,  -227,   372,   372,  -227,  -227,   457,   459,  -227,   463,
     466,   468,   460,   462,  -227,   469,   470,   471,  -227,   476,
     473,   479,   472,   474,  -227,   481,   485,   486,   477,   478,
    -227,   487,   480,   482,  -227,   489,   483,   484,  -227,   493,
     496,   497,   488,   490,  -227,   499,   502,   503,   494,   495,
    -227,   504,   498,  -227,   505,   500,  -227,   507,  -227,  -227,
     501,   512,   506,   509,    88,    89,  -227,   511,   510,   513,
    -227,   514,   515,   516,  -227,   519,   517,   518,  -227,   520,
     521,   522,   153,  -227,   527,   523,  -227,   528,  -227,  -227,
     524,   535,   536,  -227,  -227,   529,  -227,  -227,   530,   537,
     538,  -227,  -227,   531,   542,   543,  -227,  -227,   539,  -227,
    -227,   544,  -227,  -227,   545,   546,   547,  -227,  -227,   548,
     552,   553,  -227,  -227,   549,  -227,   550,  -227,   551,  -227,
    -227,   165,   512,  -227,  -227,   512,  -227,   512,   554,  -227,
    -227,   555,  -227,  -227,   556,  -227,  -227,   557,  -227,  -227,
     344,   154,   558,  -227,   559,  -227,   369,   369,  -227,  -227,
     562,   563,  -227,   570,   571,  -227,  -227,  -227,   572,   573,
    -227,   574,   575,  -227,  -227,  -227,  -227,   576,   577,  -227,
     165,   165,   165,  -227,  -227,  -227,  -227,  -227,   354,   348,
    -227,  -227,   372,   372,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,  -227,  -227,  -227,   588,   589,  -227,
     590,   369,   369,   369,   369,   591,   593,   594,   595,  -227,
    -227,  -227,  -227,   592,   372,   372,   372,   372,   596,   597,
     600,   601,  -227,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   643,   644,   645,   646,   647,   648,   649,
     650,   369,   369,   651,   652,   372,   372,   369,   369,   372,
     372
  };

  const unsigned short int
  BisonDictionaryTextParser::yydefact_[] =
  {
       0,     0,     0,     0,     1,   203,   204,     0,   205,   206,
       0,   207,   208,   149,   150,     0,   209,   210,   151,   152,
       0,   211,   212,   153,   154,     2,   213,   214,   307,   155,
     156,     0,   215,   216,   308,     0,   217,   218,   181,   182,
       0,     4,     0,   219,   220,   183,   184,     3,     5,     0,
     221,   222,   185,   186,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   223,   224,   187,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,   189,   190,     6,   139,     0,     0,     7,     0,     8,
       0,     9,     0,    10,     0,    11,     0,    12,     0,    13,
       0,    14,     0,    15,     0,    16,     0,    17,     0,    18,
       0,    19,     0,    20,     0,    21,     0,     0,     0,    42,
     191,   192,    25,   140,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    40,
       0,    44,     0,     0,     0,     0,   193,   194,     0,     0,
       0,    45,     0,     0,     0,     0,   195,   196,    22,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   197,   198,    41,    64,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,    43,   199,   200,     0,     0,    46,
       0,     0,    47,     0,     0,    48,     0,     0,    49,     0,
       0,    50,     0,     0,    51,     0,     0,    52,     0,     0,
      53,     0,     0,    54,     0,     0,    55,     0,     0,    56,
       0,     0,    57,     0,     0,    58,     0,     0,    59,     0,
       0,    60,     0,     0,    61,     0,     0,     0,    63,     0,
       0,   138,   201,   202,   102,   120,     0,     0,    65,     0,
     141,   142,     0,     0,    66,     0,     0,     0,    67,     0,
     157,   158,     0,     0,    68,     0,   169,   170,     0,     0,
      69,     0,     0,     0,    70,     0,     0,     0,    71,     0,
     225,   226,     0,     0,    72,     0,   265,   266,     0,     0,
      73,     0,     0,    74,     0,     0,    75,     0,   319,   321,
       0,     0,     0,     0,   309,   310,    76,     0,     0,     0,
      77,     0,     0,     0,    78,     0,     0,     0,    79,     0,
       0,     0,     0,    80,     0,     0,    83,     0,   122,    84,
       0,   143,   144,    85,   123,     0,    86,   124,     0,   159,
     160,    87,   125,     0,   171,   172,    88,   126,     0,    89,
     127,     0,    90,   128,     0,   227,   228,    91,   129,     0,
     267,   268,    92,   130,     0,    93,     0,    94,     0,    95,
     323,   314,     0,   131,   320,     0,   322,     0,     0,    96,
     132,     0,    97,   133,     0,    98,   134,     0,    99,   135,
       0,     0,     0,   101,     0,   103,   145,   146,   104,   105,
     161,   162,   106,   173,   174,   107,   108,   109,   229,   230,
     110,   269,   270,   111,   112,   113,   324,   325,   326,   318,
     313,   311,   312,   114,   115,   116,   117,    62,     0,     0,
     118,   121,   147,   148,   163,   164,   175,   176,   231,   232,
     271,   272,   327,   328,   317,   315,   316,     0,     0,    81,
       0,   165,   166,   177,   178,   233,   234,   273,   274,   329,
     330,   100,   136,     0,   167,   168,   179,   180,   235,   236,
     275,   276,   119,   237,   238,   277,   278,   239,   240,   279,
     280,   241,   242,   281,   282,   243,   244,   283,   284,   245,
     246,   285,   286,   247,   248,   287,   288,   249,   250,   289,
     290,   251,   252,   291,   292,   253,   254,   293,   294,   255,
     256,   295,   296,   257,   258,   297,   298,   259,   260,   299,
     300,   261,   262,   301,   302,   263,   264,   303,   304,   305,
     306
  };

  const short int
  BisonDictionaryTextParser::yypgoto_[] =
  {
    -227,  -227,  -227,   408,  -227,  -227,  -227,    52,  -227,  -227,
    -227,   -54,  -227,    -3,  -227,  -227,   -17,   124,   116,   115,
     -24,   122,  -227,  -227,  -226,  -194
  };

  const short int
  BisonDictionaryTextParser::yydefgoto_[] =
  {
      -1,     2,    31,    40,    41,   148,   175,   170,   171,   172,
     173,    77,   323,    15,   333,   339,   174,     7,   353,   359,
      29,   373,   374,   375,   441,   489
  };

  const unsigned short int
  BisonDictionaryTextParser::yytable_[] =
  {
      30,    79,    81,    83,    85,    87,    89,    91,    93,    95,
      97,    99,   101,   103,   105,   108,   110,    25,    42,   368,
     369,   370,   106,     4,    42,     3,    71,    72,   368,   369,
     378,   371,    35,   248,     8,   251,   310,    75,   252,   311,
     371,    78,    80,    82,    84,    86,    88,    90,   107,    92,
      76,    94,    96,   372,    98,   100,   102,   104,   115,   249,
     118,    76,   372,    76,   116,    76,   120,   122,   124,    76,
      76,    76,    76,    76,    76,    76,   126,    76,   128,    76,
      76,   130,    76,    76,    76,    76,   116,   132,   116,   134,
     136,   138,   140,   142,   116,   116,   116,   144,   147,   178,
     189,   218,   220,   222,   116,   224,   116,   226,   228,   116,
     230,   444,   446,   316,   179,   116,   317,   116,   116,   116,
     116,   116,     1,   445,   447,   116,   116,    76,   116,    76,
      76,    76,   232,    76,   234,    76,    76,   236,    76,   219,
     221,   223,   225,   227,   229,   231,   233,   235,   237,   239,
     241,   243,   245,   247,   250,   253,   238,   240,   242,   244,
      76,   246,    76,   261,   264,    76,   267,   270,   273,   276,
     279,   282,   285,   288,   291,   294,   297,   300,   303,   307,
     460,   499,     5,     6,    76,    76,    76,    76,   486,    76,
     109,   116,   116,   149,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,    76,   116,
     320,   321,   322,   487,   488,    76,   490,     9,   116,   491,
      10,   492,    11,   181,   182,   183,    12,   185,    13,    14,
     326,   312,   313,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,   330,
     331,   332,   336,   337,   338,    70,    13,    14,   343,    38,
      39,   342,    16,   327,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       5,     6,   346,   350,   351,   352,   209,   356,   357,   358,
     350,   351,   382,   356,   357,   386,   514,   515,   516,    38,
      39,   214,   215,    17,   216,   217,   259,   260,   262,   263,
     265,   266,   268,   269,   271,   272,   274,   275,   277,   278,
     280,   281,   283,   284,   286,   287,   289,   290,   292,   293,
     295,   296,   298,   299,   301,   302,   304,   305,   461,   308,
     309,   318,   319,   324,   325,   328,   329,   334,   335,   340,
     341,   344,   345,   348,   349,   354,   355,   360,   361,   363,
     364,   366,   367,   376,   377,   380,   381,   384,   385,   388,
     389,   390,   391,   393,   394,   396,   397,   497,   498,   517,
     518,   519,   520,    18,    19,    20,    21,    22,    23,    24,
      26,    27,    28,    32,    33,    34,    36,    37,    43,    44,
      45,    46,   347,   114,    50,    51,    52,    53,    73,    74,
      47,   111,    49,   112,   153,   383,   168,   387,   379,     0,
     113,     0,   117,     0,   119,   121,   123,   125,   127,   129,
     131,   133,   135,   137,   139,   141,   143,   145,   146,   150,
     152,   151,   502,   503,   154,   155,   156,   157,   158,    48,
     306,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   169,   176,   177,   180,   186,   184,   187,   188,   190,
     211,   212,   191,   255,   192,   256,   210,     0,   257,   213,
     258,   362,   254,   365,   314,   392,   395,   315,   400,   401,
     398,   402,   399,   403,   405,   404,   409,   534,   535,   536,
     537,   408,   410,   406,   407,   411,   413,   412,   414,   415,
     416,   417,   418,   419,   421,   420,   422,   423,   424,   425,
     426,   427,     0,   428,   429,   430,   431,   432,   433,   434,
     436,   435,   438,   437,   439,   440,   448,     0,     0,   451,
       0,   442,   443,   449,   454,   457,   450,     0,   452,   453,
     455,   456,   462,   464,   458,   459,   463,   465,   466,   467,
     470,   471,   468,   469,   472,   473,   474,   595,   596,   478,
     479,     0,   475,   599,   600,   481,   482,   476,   477,     0,
       0,   480,   483,   484,   485,   504,   505,   493,   494,   495,
     496,   500,   501,   506,   507,   508,   509,   510,   511,   512,
     513,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,     0,     0,     0,   538,   533,   539,   540,   541,   543,
     544,   531,   532,   545,   546,   542,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   597,   598
  };

  const short int
  BisonDictionaryTextParser::yycheck_[] =
  {
      24,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    20,    35,    23,
      24,    25,    27,     0,    41,    27,    50,    51,    23,    24,
      25,    35,    30,    27,    23,    27,    27,    27,    30,    30,
      35,    27,    27,    27,    27,    27,    27,    27,    53,    27,
      55,    27,    27,    57,    27,    27,    27,    27,    27,    53,
      27,    55,    57,    55,    55,    55,    27,    27,    27,    55,
      55,    55,    55,    55,    55,    55,    27,    55,    27,    55,
      55,    27,    55,    55,    55,    55,    55,    27,    55,    27,
      27,    27,    27,    27,    55,    55,    55,    27,    27,    27,
      27,    27,    27,    27,    55,    27,    55,    27,    27,    55,
      27,    23,    23,    22,   168,    55,    25,    55,    55,    55,
      55,    55,     3,    35,    35,    55,    55,    55,    55,    55,
      55,    55,    27,    55,    27,    55,    55,    27,    55,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    27,    27,    27,    27,
      55,    27,    55,    27,    27,    55,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    23,    24,    55,    55,    55,    55,    23,    55,
      30,    55,    55,    30,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      23,    24,    25,    48,    49,    55,   442,    23,    55,   445,
      35,   447,    23,   171,   172,   173,    23,   175,    23,    24,
      25,   255,   256,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    23,
      24,    25,    23,    24,    25,    27,    23,    24,   275,    23,
      24,    25,    23,   266,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      23,    24,    25,    23,    24,    25,    27,    23,    24,    25,
      23,    24,    25,    23,    24,    25,   490,   491,   492,    23,
      24,    33,    34,    23,    33,    34,    33,    34,    33,    34,
      33,    34,    33,    34,    33,    34,    33,    34,    33,    34,
      33,    34,    33,    34,    33,    34,    33,    34,    33,    34,
      33,    34,    33,    34,    33,    34,    33,    34,   392,    33,
      34,    33,    34,    33,    34,    33,    34,    33,    34,    33,
      34,    33,    34,    33,    34,    33,    34,    33,    34,    33,
      34,    33,    34,    33,    34,    33,    34,    33,    34,    33,
      34,    25,    26,    33,    34,    33,    34,    33,    34,    25,
      26,    33,    34,    23,    23,    35,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,   278,    56,    23,    23,    23,    23,    23,    23,
      31,    23,    32,    23,    56,   299,    54,   302,   296,    -1,
      33,    -1,    33,    -1,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    21,    23,
      33,    23,   466,   467,    33,    33,    33,    33,    33,    41,
      21,    -1,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    23,    23,    31,    23,    32,    23,    33,    33,
      23,    23,    31,    23,    31,    23,    31,    -1,    25,    33,
      25,    25,    33,    25,    33,    54,    25,    33,    25,    23,
      33,    23,    33,    33,    25,    33,    23,   521,   522,   523,
     524,    25,    23,    33,    33,    33,    25,    33,    23,    23,
      33,    33,    25,    33,    25,    33,    33,    33,    25,    23,
      23,    33,    -1,    33,    25,    23,    23,    33,    33,    25,
      25,    33,    25,    33,    33,    23,    25,    -1,    -1,    25,
      -1,    35,    33,    33,    25,    25,    33,    -1,    33,    33,
      33,    33,    25,    25,    33,    33,    33,    33,    23,    23,
      23,    23,    33,    33,    33,    23,    23,   591,   592,    23,
      23,    -1,    33,   597,   598,    23,    23,    33,    33,    -1,
      -1,    33,    33,    33,    33,    23,    23,    33,    33,    33,
      33,    33,    33,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    -1,    -1,    -1,    23,    25,    23,    23,    23,    23,
      23,    33,    33,    23,    23,    33,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23
  };

  const unsigned char
  BisonDictionaryTextParser::yystos_[] =
  {
       0,     3,    59,    27,     0,    23,    24,    75,    23,    23,
      35,    23,    23,    23,    24,    71,    23,    23,    23,    23,
      35,    23,    23,    23,    23,    71,    23,    23,    23,    78,
      78,    60,    23,    23,    23,    30,    23,    23,    23,    24,
      61,    62,    74,    23,    23,    23,    23,    31,    61,    32,
      23,    23,    23,    23,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      27,    78,    78,    23,    23,    27,    55,    69,    27,    69,
      27,    69,    27,    69,    27,    69,    27,    69,    27,    69,
      27,    69,    27,    69,    27,    69,    27,    69,    27,    69,
      27,    69,    27,    69,    27,    69,    27,    53,    69,    30,
      69,    23,    23,    33,    56,    27,    55,    33,    27,    33,
      27,    33,    27,    33,    27,    33,    27,    33,    27,    33,
      27,    33,    27,    33,    27,    33,    27,    33,    27,    33,
      27,    33,    27,    33,    27,    33,    21,    27,    63,    30,
      23,    23,    33,    56,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    54,    33,
      65,    66,    67,    68,    74,    64,    23,    23,    27,    69,
      31,    65,    65,    65,    32,    65,    23,    23,    33,    27,
      33,    31,    31,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    27,
      31,    23,    23,    33,    33,    34,    33,    34,    27,    69,
      27,    69,    27,    69,    27,    69,    27,    69,    27,    69,
      27,    69,    27,    69,    27,    69,    27,    69,    27,    69,
      27,    69,    27,    69,    27,    69,    27,    69,    27,    53,
      69,    27,    30,    69,    33,    23,    23,    25,    25,    33,
      34,    27,    33,    34,    27,    33,    34,    27,    33,    34,
      27,    33,    34,    27,    33,    34,    27,    33,    34,    27,
      33,    34,    27,    33,    34,    27,    33,    34,    27,    33,
      34,    27,    33,    34,    27,    33,    34,    27,    33,    34,
      27,    33,    34,    27,    33,    34,    21,    27,    33,    34,
      27,    30,    78,    78,    33,    33,    22,    25,    33,    34,
      23,    24,    25,    70,    33,    34,    25,    71,    33,    34,
      23,    24,    25,    72,    33,    34,    23,    24,    25,    73,
      33,    34,    25,    74,    33,    34,    25,    75,    33,    34,
      23,    24,    25,    76,    33,    34,    23,    24,    25,    77,
      33,    34,    25,    33,    34,    25,    33,    34,    23,    24,
      25,    35,    57,    79,    80,    81,    33,    34,    25,    79,
      33,    34,    25,    76,    33,    34,    25,    77,    33,    34,
      25,    26,    54,    33,    34,    25,    33,    34,    33,    33,
      25,    23,    23,    33,    33,    25,    33,    33,    25,    23,
      23,    33,    33,    25,    23,    23,    33,    33,    25,    33,
      33,    25,    33,    33,    25,    23,    23,    33,    33,    25,
      23,    23,    33,    33,    25,    33,    25,    33,    25,    33,
      23,    82,    35,    33,    23,    35,    23,    35,    25,    33,
      33,    25,    33,    33,    25,    33,    33,    25,    33,    33,
      27,    69,    25,    33,    25,    33,    23,    23,    33,    33,
      23,    23,    33,    23,    23,    33,    33,    33,    23,    23,
      33,    23,    23,    33,    33,    33,    23,    48,    49,    83,
      82,    82,    82,    33,    33,    33,    33,    33,    34,    27,
      33,    33,    78,    78,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    83,    83,    83,    25,    26,    33,
      34,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    33,    33,    25,    78,    78,    78,    78,    23,    23,
      23,    23,    33,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    78,    78,    23,    23,    78,
      78
  };

  const unsigned char
  BisonDictionaryTextParser::yyr1_[] =
  {
       0,    58,    60,    59,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    64,    62,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    83,    83,    83,
      83
  };

  const unsigned char
  BisonDictionaryTextParser::yyr2_[] =
  {
       0,     2,     0,    11,     1,     2,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     8,     0,     8,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     9,     0,     9,     1,     2,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     8,     5,     4,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     9,     4,     6,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
      10,     7,     6,     8,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,    11,
       6,     8,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,    10,     4,     5,     2,
       3,     1,     1,     2,     2,     3,     3,     4,     4,     1,
       1,     2,     2,     3,     3,     4,     4,     1,     1,     2,
       2,     3,     3,     4,     4,     5,     5,     6,     6,     1,
       1,     2,     2,     3,     3,     4,     4,     5,     5,     6,
       6,     1,     1,     2,     2,     3,     3,     4,     4,     5,
       5,     6,     6,     7,     7,     8,     8,     9,     9,    10,
      10,    11,    11,     1,     1,     2,     2,     3,     3,     4,
       4,     5,     5,     6,     6,     7,     7,     8,     8,     9,
       9,    10,    10,    11,    11,     1,     1,     2,     2,     3,
       3,     4,     4,     5,     5,     6,     6,     7,     7,     8,
       8,     9,     9,    10,    10,    11,    11,    12,    12,    13,
      13,    14,    14,    15,    15,    16,    16,    17,    17,    18,
      18,    19,    19,    20,    20,     1,     1,     2,     2,     3,
       3,     4,     4,     5,     5,     6,     6,     7,     7,     8,
       8,     9,     9,    10,    10,    11,    11,    12,    12,    13,
      13,    14,    14,    15,    15,    16,    16,    17,    17,    18,
      18,    19,    19,    20,    20,    21,    21,     1,     2,     1,
       1,     3,     3,     3,     2,     4,     4,     4,     3,     1,
       2,     1,     2,     1,     2,     1,     1,     2,     2,     3,
       3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const BisonDictionaryTextParser::yytname_[] =
  {
  "$end", "error", "$undefined", "USDS", "DICTIONARY_VERSION",
  "\"BOOLEAN\"", "\"BYTE\"", "\"UBYTE\"", "\"SHORT\"", "\"USHORT\"",
  "\"INT\"", "\"UINT\"", "\"LONG\"", "\"ULONG\"", "\"INT128\"",
  "\"UINT128\"", "\"FLOAT\"", "\"DOUBLE\"", "\"VARINT\"", "\"UVARINT\"",
  "\"STRING\"", "\"<Text encode>\"", "\"true or false\"", "\"Digit\"",
  "\"-Digit\"", "\"NULL\"", "\"Text string\"", "\"Object name\"",
  "USDS_RESTRICT", "\"notRoot\"", "'{'", "'}'", "':'", "';'", "'='", "'.'",
  "\"int8_t\"", "\"uint8_t\"", "\"int16_t\"", "\"uint16_t\"",
  "\"int32_t\"", "\"uint32_t\"", "\"int64_t\"", "\"uint64_t\"",
  "\"Float value\"", "\"Positive major float value\"",
  "\"Negative major float value\"", "\"Minor float value\"",
  "\"Positive float exponent digit\"", "\"Negative float exponent digit\"",
  "\"Float exponent\"", "\"Array declaration\"",
  "\"Array of struct declaration\"", "'<'", "'>'", "'['", "']'", "'-'",
  "$accept", "dictionary", "$@1", "tags", "tag", "$@2", "$@3", "fields",
  "field", "struct_begin", "array_of_struct_begin", "array_dimension",
  "INT8_T", "UINT8_T", "INT16_T", "UINT16_T", "INT32_T", "UINT32_T",
  "INT64_T", "UINT64_T", "digits", "FLOAT_VALUE",
  "positive_major_float_digits", "negative_major_float_digits",
  "minor_float_digits", "float_exponent", YY_NULL
  };

#if DICTIONARY_TEXTDEBUG
  const unsigned short int
  BisonDictionaryTextParser::yyrline_[] =
  {
       0,   138,   138,   137,   152,   152,   154,   158,   162,   166,
     170,   174,   178,   182,   186,   190,   194,   198,   202,   206,
     210,   214,   218,   224,   223,   233,   243,   253,   263,   273,
     283,   293,   303,   313,   323,   333,   343,   353,   363,   373,
     383,   393,   405,   404,   424,   424,   427,   431,   435,   439,
     443,   447,   451,   455,   459,   463,   467,   471,   475,   479,
     483,   487,   491,   496,   501,   507,   516,   525,   534,   543,
     552,   561,   570,   579,   588,   597,   606,   615,   624,   633,
     642,   651,   661,   668,   681,   686,   691,   696,   701,   706,
     711,   716,   721,   726,   731,   736,   741,   746,   751,   756,
     761,   767,   773,   780,   790,   800,   810,   820,   830,   840,
     850,   860,   870,   880,   890,   900,   910,   920,   930,   940,
     951,   960,   973,   978,   983,   988,   993,   998,  1003,  1008,
    1013,  1018,  1023,  1028,  1033,  1038,  1043,  1052,  1059,  1072,
    1076,  1087,  1091,  1095,  1099,  1103,  1116,  1129,  1133,  1140,
    1144,  1148,  1152,  1156,  1169,  1173,  1177,  1187,  1191,  1195,
    1201,  1207,  1214,  1221,  1229,  1237,  1253,  1269,  1273,  1280,
    1284,  1288,  1294,  1298,  1305,  1309,  1317,  1321,  1337,  1341,
    1345,  1355,  1359,  1363,  1369,  1375,  1382,  1389,  1397,  1405,
    1414,  1423,  1433,  1443,  1454,  1465,  1477,  1489,  1502,  1515,
    1536,  1557,  1561,  1568,  1572,  1576,  1582,  1586,  1593,  1597,
    1605,  1609,  1618,  1622,  1632,  1636,  1647,  1651,  1663,  1667,
    1680,  1684,  1705,  1709,  1713,  1723,  1727,  1731,  1737,  1743,
    1750,  1757,  1765,  1773,  1782,  1791,  1801,  1811,  1822,  1833,
    1845,  1857,  1870,  1883,  1897,  1911,  1927,  1943,  1960,  1977,
    1995,  2013,  2032,  2051,  2071,  2091,  2112,  2133,  2155,  2177,
    2200,  2223,  2252,  2281,  2287,  2296,  2300,  2304,  2310,  2314,
    2321,  2325,  2333,  2337,  2346,  2350,  2360,  2364,  2375,  2379,
    2391,  2395,  2408,  2412,  2426,  2430,  2446,  2452,  2469,  2475,
    2493,  2499,  2518,  2524,  2544,  2550,  2571,  2577,  2599,  2605,
    2628,  2634,  2658,  2664,  2698,  2704,  2710,  2718,  2718,  2725,
    2729,  2733,  2737,  2741,  2745,  2749,  2753,  2757,  2761,  2768,
    2772,  2779,  2783,  2790,  2795,  2803,  2807,  2811,  2815,  2819,
    2823
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
       2,     2,     2,     2,     2,    57,    35,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    33,
      53,    34,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
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
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52
    };
    const unsigned int user_token_number_max_ = 301;
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
#line 5317 "bisonDictionaryTextParser.cc" // lalr1.cc:1156
#line 2830 "bisonDictionaryTextParser.y" // lalr1.cc:1157

//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

