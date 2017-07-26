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
		usds::DictionaryBoolean* dict_field = (usds::DictionaryBoolean*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.boolVal));
	}
#line 1634 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 104:
#line 786 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryByte* dict_field = (usds::DictionaryByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int8Val));
	}
#line 1643 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 105:
#line 791 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUByte* dict_field = (usds::DictionaryUByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt8Val));
	}
#line 1652 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 106:
#line 796 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryShort* dict_field = (usds::DictionaryShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int16Val));
	}
#line 1661 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 107:
#line 801 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUShort* dict_field = (usds::DictionaryUShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt16Val));
	}
#line 1670 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 108:
#line 806 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryInt* dict_field = (usds::DictionaryInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int32Val));
	}
#line 1679 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 109:
#line 811 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUInt* dict_field = (usds::DictionaryUInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt32Val));
	}
#line 1688 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 110:
#line 816 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryLong* dict_field = (usds::DictionaryLong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 1697 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 111:
#line 821 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryULong* dict_field = (usds::DictionaryULong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 1706 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 112:
#line 826 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryFloat* dict_field = (usds::DictionaryFloat*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((float)(yystack_[1].value.doubleVal));
	}
#line 1715 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 113:
#line 831 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryDouble* dict_field = (usds::DictionaryDouble*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.doubleVal));
	}
#line 1724 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 114:
#line 836 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 1733 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 115:
#line 841 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 1742 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 116:
#line 846 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1751 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 117:
#line 851 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), (yystack_[9].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1761 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 118:
#line 860 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, (yystack_[3].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1769 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 119:
#line 867 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[4].value.int32Val), input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_STRUCT);
		(yylhs.value.uInt32Val) = (yystack_[1].value.uInt32Val);
	}
#line 1783 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 120:
#line 880 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 1;
	}
#line 1791 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 121:
#line 884 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (yylhs.value.uInt32Val) + 1;
	}
#line 1799 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 122:
#line 895 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[0].value.int8Val);
	}
#line 1807 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 123:
#line 899 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[0].value.int8Val);
	}
#line 1815 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 124:
#line 903 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val) * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
	}
#line 1823 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 125:
#line 907 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val) * (int8_t)10 - (int8_t)(yystack_[0].value.int8Val);
	}
#line 1831 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 126:
#line 911 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) > (int8_t)1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";

		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)1 && (yylhs.value.int8Val) >= (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";
		
		(yylhs.value.int8Val) = (int8_t)(yystack_[2].value.int8Val) * (int8_t)100 + (yylhs.value.int8Val);
		
	}
#line 1848 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 127:
#line 924 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) < (int8_t)-1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";

		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)-1 && (yylhs.value.int8Val) > (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";
		
		(yylhs.value.int8Val) = (int8_t)(yystack_[2].value.int8Val) * (int8_t)100 - (yylhs.value.int8Val);
		
	}
#line 1865 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 128:
#line 937 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int8_t: too big value";
	}
#line 1873 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 129:
#line 941 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int8_t: too big value";
	}
#line 1881 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 130:
#line 948 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[0].value.int8Val);
	}
#line 1889 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 131:
#line 952 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 1897 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 132:
#line 956 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[1].value.int8Val) * (uint8_t)10 + (uint8_t)(yystack_[0].value.int8Val);
	}
#line 1905 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 133:
#line 960 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 1913 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 134:
#line 964 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: too big value";

		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[1].value.int8Val)  * (uint8_t)10 + (uint8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)2 && (yylhs.value.uInt8Val) >= (uint8_t)56)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: too big value";
		
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[2].value.int8Val) * (uint8_t)100 + (yylhs.value.uInt8Val);
		
	}
#line 1930 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 135:
#line 977 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 1938 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 136:
#line 981 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint8_t: too big value";
	}
#line 1946 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 137:
#line 985 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint8_t: too big value";
	}
#line 1954 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 138:
#line 995 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = (int16_t)(yystack_[0].value.int8Val);
	}
#line 1962 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 139:
#line 999 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = (int16_t)(yystack_[0].value.int8Val);
	}
#line 1970 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 140:
#line 1003 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 1980 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 141:
#line 1009 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 1990 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 142:
#line 1015 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 2001 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 143:
#line 1022 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 - 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 2012 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 144:
#line 1029 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 + 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 2024 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 145:
#line 1037 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 - 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 - 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 2036 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 146:
#line 1045 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2056 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 147:
#line 1061 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2076 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 148:
#line 1077 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int16_t: too big value";
	}
#line 2084 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 149:
#line 1081 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int16_t: too big value";
	}
#line 2092 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 150:
#line 1088 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = (uint16_t)(yystack_[0].value.int8Val);
	}
#line 2100 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 151:
#line 1092 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 2108 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 152:
#line 1096 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 2118 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 153:
#line 1102 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 2126 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 154:
#line 1106 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[2].value.int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 2137 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 155:
#line 1113 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 2145 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 156:
#line 1117 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[3].value.int8Val) * (uint16_t)1000 + 
		(uint16_t)(yystack_[2].value.int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 2157 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 157:
#line 1125 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 2165 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 158:
#line 1129 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2185 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 159:
#line 1145 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 2193 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 160:
#line 1149 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint16_t: too big value";
	}
#line 2201 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 161:
#line 1153 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint16_t: too big value";
	}
#line 2209 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 162:
#line 1163 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = (int32_t)(yystack_[0].value.int8Val);
	}
#line 2217 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 163:
#line 1167 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = (int32_t)(yystack_[0].value.int8Val);
	}
#line 2225 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 164:
#line 1171 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2235 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 165:
#line 1177 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2245 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 166:
#line 1183 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2256 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 167:
#line 1190 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2267 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 168:
#line 1197 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2279 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 169:
#line 1205 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2291 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 170:
#line 1213 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2304 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 171:
#line 1222 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2317 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 172:
#line 1231 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2331 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 173:
#line 1241 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 - 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 2345 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 174:
#line 1251 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2360 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 175:
#line 1262 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2375 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 176:
#line 1273 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2391 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 177:
#line 1285 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2407 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 178:
#line 1297 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2424 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 179:
#line 1310 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2441 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 180:
#line 1323 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2466 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 181:
#line 1344 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2491 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 182:
#line 1365 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int32_t: too big value";
	}
#line 2499 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 183:
#line 1369 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int32_t: too big value";
	}
#line 2507 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 184:
#line 1376 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (uint32_t)(yystack_[0].value.int8Val);
	}
#line 2515 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 185:
#line 1380 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2523 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 186:
#line 1384 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2533 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 187:
#line 1390 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2541 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 188:
#line 1394 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2552 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 189:
#line 1401 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2560 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 190:
#line 1405 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2572 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 191:
#line 1413 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2580 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 192:
#line 1417 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2593 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 193:
#line 1426 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2601 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 194:
#line 1430 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[5].value.int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 2615 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 195:
#line 1440 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2623 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 196:
#line 1444 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2638 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 197:
#line 1455 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2646 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 198:
#line 1459 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2662 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 199:
#line 1471 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2670 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 200:
#line 1475 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2687 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 201:
#line 1488 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2695 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 202:
#line 1492 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2720 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 203:
#line 1513 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 2728 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 204:
#line 1517 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint32_t: too big value";
	}
#line 2736 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 205:
#line 1521 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint32_t: negative value";
	}
#line 2744 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 206:
#line 1531 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = (int64_t)(yystack_[0].value.int8Val);
	}
#line 2752 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 207:
#line 1535 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = (int64_t)(yystack_[0].value.int8Val);
	}
#line 2760 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 208:
#line 1539 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 2770 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 209:
#line 1545 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 2780 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 210:
#line 1551 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 2791 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 211:
#line 1558 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 2802 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 212:
#line 1565 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 2814 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 213:
#line 1573 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 2826 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 214:
#line 1581 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 2839 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 215:
#line 1590 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 2852 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 216:
#line 1599 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 2866 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 217:
#line 1609 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 2880 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 218:
#line 1619 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2895 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 219:
#line 1630 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2910 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 220:
#line 1641 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2926 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 221:
#line 1653 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2942 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 222:
#line 1665 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2959 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 223:
#line 1678 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2976 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 224:
#line 1691 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2994 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 225:
#line 1705 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3012 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 226:
#line 1720 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3031 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 227:
#line 1736 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3050 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 228:
#line 1752 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3070 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 229:
#line 1769 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3090 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 230:
#line 1786 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3111 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 231:
#line 1804 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3132 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 232:
#line 1822 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3154 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 233:
#line 1841 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3176 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 234:
#line 1860 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3199 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 235:
#line 1880 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3222 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 236:
#line 1900 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3246 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 237:
#line 1921 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3270 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 238:
#line 1942 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3295 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 239:
#line 1964 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3320 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 240:
#line 1986 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3346 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 241:
#line 2009 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3372 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 242:
#line 2032 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3404 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 243:
#line 2061 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3436 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 244:
#line 2090 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int64_t: too big value";
	}
#line 3445 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 245:
#line 2096 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int64_t: too big value";
	}
#line 3454 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 246:
#line 2104 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = (uint64_t)(yystack_[0].value.int8Val);
	}
#line 3462 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 247:
#line 2108 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3470 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 248:
#line 2112 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3480 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 249:
#line 2118 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3488 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 250:
#line 2122 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3499 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 251:
#line 2129 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3507 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 252:
#line 2133 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3519 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 253:
#line 2141 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3527 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 254:
#line 2145 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3540 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 255:
#line 2154 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3548 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 256:
#line 2158 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 3562 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 257:
#line 2168 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3570 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 258:
#line 2172 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3585 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 259:
#line 2183 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3593 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 260:
#line 2187 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3609 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 261:
#line 2199 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3617 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 262:
#line 2203 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3634 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 263:
#line 2216 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3642 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 264:
#line 2220 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3660 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 265:
#line 2234 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3668 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 266:
#line 2239 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3687 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 267:
#line 2255 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) 
			<< (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3696 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 268:
#line 2261 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3716 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 269:
#line 2278 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) 
			<< (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3725 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 270:
#line 2284 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3746 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 271:
#line 2302 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) 
			<< (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3755 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 272:
#line 2308 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3777 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 273:
#line 2327 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) 
			<< (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3786 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 274:
#line 2333 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3809 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 275:
#line 2353 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) 
			<< (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3818 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 276:
#line 2359 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3842 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 277:
#line 2380 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) 
			<< (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3851 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 278:
#line 2386 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3876 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 279:
#line 2408 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) 
			<< (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3885 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 280:
#line 2414 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3911 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 281:
#line 2437 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) 
			<< (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3920 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 282:
#line 2443 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3947 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 283:
#line 2467 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) 
			<< (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 3956 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 284:
#line 2473 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3993 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 285:
#line 2507 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) 
			<< (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 4002 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 286:
#line 2513 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[20].value.int8Val) << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint64_t: too big value";
	}
#line 4011 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 287:
#line 2519 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[20].value.int8Val) << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) 
			<< (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint64_t: negative value";
	}
#line 4020 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 290:
#line 2533 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.doubleVal);
	}
#line 4028 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 291:
#line 2537 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.doubleVal);
	}
#line 4036 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 292:
#line 2541 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[2].value.doubleVal) + (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 4044 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 293:
#line 2545 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[2].value.doubleVal) - (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 4052 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 294:
#line 2549 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = - (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;	
	}
#line 4060 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 295:
#line 2553 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 4068 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 296:
#line 2557 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[3].value.doubleVal) + (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 4076 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 297:
#line 2561 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[3].value.doubleVal) - (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 4084 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 298:
#line 2565 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (- (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));	
	}
#line 4092 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 299:
#line 2569 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 4100 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 300:
#line 2576 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 4108 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 301:
#line 2580 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yylhs.value.doubleVal) * 10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 4116 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 302:
#line 2587 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 4124 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 303:
#line 2591 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yylhs.value.doubleVal) * 10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 4132 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 304:
#line 2598 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.floatDigits).value = (double)(yystack_[0].value.int8Val);
		(yylhs.value.floatDigits).digits = 10.0;
	}
#line 4141 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 305:
#line 2603 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.floatDigits).value = (yylhs.value.floatDigits).value * 10.0 + (double)(yystack_[0].value.int8Val);
		(yylhs.value.floatDigits).digits = (yylhs.value.floatDigits).digits * 10.0;
	}
#line 4150 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 306:
#line 2611 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 4158 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 307:
#line 2615 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 4166 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 308:
#line 2619 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[1].value.int8Val) * (double)10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 4174 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 309:
#line 2623 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[1].value.int8Val) * (double)10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 4182 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 310:
#line 2627 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[2].value.int8Val) * (double)100.0 + (double)(yystack_[1].value.int8Val) * (double)10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 4190 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 311:
#line 2631 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[2].value.int8Val) * (double)100.0 - (double)(yystack_[1].value.int8Val) * (double)10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 4198 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;


#line 4202 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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


  const short int BisonDictionaryTextParser::yypact_ninf_ = -196;

  const signed char BisonDictionaryTextParser::yytable_ninf_ = -1;

  const short int
  BisonDictionaryTextParser::yypact_[] =
  {
     119,    -2,    23,   159,  -196,    11,   194,   185,   199,   203,
     205,   232,   237,   281,   324,   313,   326,   327,   328,   329,
     205,   330,   331,   332,   332,  -196,   333,   334,  -196,   335,
     335,     2,   336,   337,  -196,   277,   338,   339,   340,   341,
     342,   277,   287,   343,   344,   345,   346,  -196,  -196,   227,
     332,   332,   347,   348,    10,    14,    15,    16,    17,    18,
      19,    20,    22,    24,    25,    27,    28,    29,    30,    -5,
     160,   335,   335,   349,   351,   350,   309,    31,   352,    33,
     353,    39,   354,    40,   355,    41,   356,    49,   357,    51,
     358,    54,   359,    60,   360,    62,   361,    63,   362,    64,
     363,    65,   364,    66,   365,    70,   366,   379,    71,  -196,
     163,   378,   380,  -196,  -196,   369,   319,  -196,   373,  -196,
     374,  -196,   375,  -196,   376,  -196,   377,  -196,   381,  -196,
     382,  -196,   383,  -196,   384,  -196,   385,  -196,   386,  -196,
     387,  -196,   388,  -196,   389,  -196,   322,   390,   277,  -196,
     401,   402,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,    72,  -196,
     395,   277,   277,   277,   396,   277,   404,   406,   397,    73,
     398,  -196,   403,   405,   257,   407,   409,   410,  -196,   408,
    -196,   269,   413,    74,    75,    76,    78,    80,    81,    83,
     105,   107,   110,   129,   130,   131,   132,   134,     6,     8,
     414,   412,   416,  -196,  -196,   415,  -196,   272,   136,   274,
     137,   276,   139,   278,   140,   280,   141,   282,   142,   284,
     143,   288,   144,   290,   145,   292,   146,   294,   147,   296,
     148,   298,   149,   300,   150,   302,   151,   304,   391,   152,
     306,  -196,     9,  -196,   332,   332,   417,  -196,    91,   418,
    -196,   187,   419,  -196,   225,   420,  -196,   228,   421,  -196,
     234,   422,  -196,   255,   423,  -196,   258,   424,  -196,   262,
     425,  -196,   265,   426,  -196,   435,   428,  -196,   437,   430,
    -196,    -4,   431,  -196,     5,   432,  -196,   268,   433,  -196,
     271,   434,  -196,   316,   323,   436,  -196,   443,   438,  -196,
     335,   335,  -196,   439,   440,  -196,   447,   451,   442,   444,
    -196,   445,   446,  -196,   453,   457,   448,   449,  -196,   460,
     461,   452,   454,  -196,   455,   456,  -196,   458,   459,  -196,
     463,   467,   462,   464,  -196,   470,   471,   465,   466,  -196,
     468,  -196,   469,  -196,  -196,  -196,   472,   473,   474,   475,
      88,    89,  -196,   479,   480,  -196,   481,   482,  -196,   485,
     486,  -196,   487,   488,   153,  -196,   489,  -196,  -196,  -196,
     477,   483,  -196,  -196,  -196,  -196,   484,   500,  -196,  -196,
     501,   502,  -196,  -196,  -196,  -196,  -196,  -196,   503,   504,
    -196,  -196,   505,   506,  -196,  -196,  -196,  -196,  -196,  -196,
     165,   473,  -196,  -196,   473,  -196,   473,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,   310,   154,  -196,   332,   332,
     507,   508,   509,   510,   511,   512,   513,   514,  -196,   515,
     516,  -196,   165,   165,   165,  -196,   320,   517,   335,   335,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   528,
    -196,  -196,  -196,   527,   529,  -196,   332,   332,   332,   332,
     530,   531,   532,   533,  -196,  -196,  -196,  -196,   335,   335,
     335,   335,   534,   535,   536,   538,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   332,   332,   588,   589,   335,   335,
     332,   332,   335,   335
  };

  const unsigned short int
  BisonDictionaryTextParser::yydefact_[] =
  {
       0,     0,     0,     0,     1,   184,   185,     0,   186,   187,
       0,   188,   189,   130,   131,     0,   190,   191,   132,   133,
       0,   192,   193,   134,   135,     2,   194,   195,   288,   136,
     137,     0,   196,   197,   289,     0,   198,   199,   162,   163,
       0,     4,     0,   200,   201,   164,   165,     3,     5,     0,
     202,   203,   166,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   205,   168,   169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,   170,   171,     6,   120,     0,     0,     7,     0,     8,
       0,     9,     0,    10,     0,    11,     0,    12,     0,    13,
       0,    14,     0,    15,     0,    16,     0,    17,     0,    18,
       0,    19,     0,    20,     0,    21,     0,     0,     0,    42,
     172,   173,    25,   121,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    40,
       0,    44,     0,     0,     0,     0,   174,   175,     0,     0,
       0,    45,     0,     0,     0,     0,   176,   177,    22,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   178,   179,    41,    64,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,     0,    43,   180,   181,     0,    46,     0,     0,
      47,     0,     0,    48,     0,     0,    49,     0,     0,    50,
       0,     0,    51,     0,     0,    52,     0,     0,    53,     0,
       0,    54,     0,     0,    55,     0,     0,    56,     0,     0,
      57,     0,     0,    58,     0,     0,    59,     0,     0,    60,
       0,     0,    61,     0,     0,     0,    63,     0,     0,   119,
     182,   183,   102,     0,     0,    65,   122,   123,     0,     0,
      66,     0,     0,    67,   138,   139,     0,     0,    68,   150,
     151,     0,     0,    69,     0,     0,    70,     0,     0,    71,
     206,   207,     0,     0,    72,   246,   247,     0,     0,    73,
       0,    74,     0,    75,   300,   302,     0,     0,     0,     0,
     290,   291,    76,     0,     0,    77,     0,     0,    78,     0,
       0,    79,     0,     0,     0,    80,     0,    83,   103,    84,
     124,   125,    85,   104,    86,   105,   140,   141,    87,   106,
     152,   153,    88,   107,    89,   108,    90,   109,   208,   209,
      91,   110,   248,   249,    92,   111,    93,    94,    95,   304,
     295,     0,   112,   301,     0,   303,     0,    96,   113,    97,
     114,    98,   115,    99,   116,     0,     0,   101,   126,   127,
     142,   143,   154,   155,   210,   211,   250,   251,   305,   306,
     307,   299,   294,   292,   293,    62,     0,     0,   128,   129,
     144,   145,   156,   157,   212,   213,   252,   253,   308,   309,
     298,   296,   297,     0,     0,    81,   146,   147,   158,   159,
     214,   215,   254,   255,   310,   311,   100,   117,   148,   149,
     160,   161,   216,   217,   256,   257,   218,   219,   258,   259,
     220,   221,   260,   261,   222,   223,   262,   263,   224,   225,
     264,   265,   226,   227,   266,   267,   228,   229,   268,   269,
     230,   231,   270,   271,   232,   233,   272,   273,   234,   235,
     274,   275,   236,   237,   276,   277,   238,   239,   278,   279,
     240,   241,   280,   281,   242,   243,   282,   283,   244,   245,
     284,   285,   286,   287
  };

  const short int
  BisonDictionaryTextParser::yypgoto_[] =
  {
    -196,  -196,  -196,   370,  -196,  -196,  -196,    52,  -196,  -196,
    -196,   -54,  -196,    -3,  -196,  -196,   -17,   102,    82,    84,
     -24,    86,  -196,  -196,  -195,  -145
  };

  const short int
  BisonDictionaryTextParser::yydefgoto_[] =
  {
      -1,     2,    31,    40,    41,   148,   175,   170,   171,   172,
     173,    77,   319,    15,   327,   332,   174,     7,   343,   348,
      29,   359,   360,   361,   410,   441
  };

  const unsigned short int
  BisonDictionaryTextParser::yytable_[] =
  {
      30,    79,    81,    83,    85,    87,    89,    91,    93,    95,
      97,    99,   101,   103,   105,   108,   110,    25,    42,   354,
     355,   356,   106,     4,    42,     3,    71,    72,   354,   355,
     363,   357,    35,   247,     8,   250,   308,    75,   251,   309,
     357,    78,    80,    82,    84,    86,    88,    90,   107,    92,
      76,    94,    96,   358,    98,   100,   102,   104,   115,   248,
     118,    76,   358,    76,   116,    76,   120,   122,   124,    76,
      76,    76,    76,    76,    76,    76,   126,    76,   128,    76,
      76,   130,    76,    76,    76,    76,   116,   132,   116,   134,
     136,   138,   140,   142,   116,   116,   116,   144,   147,   178,
     189,   217,   219,   221,   116,   223,   116,   225,   227,   116,
     229,   413,   415,   313,   179,   116,   314,   116,   116,   116,
     116,   116,     1,   414,   416,   116,   116,    76,   116,    76,
      76,    76,   231,    76,   233,    76,    76,   235,    76,   218,
     220,   222,   224,   226,   228,   230,   232,   234,   236,   238,
     240,   242,   244,   246,   249,   252,   237,   239,   241,   243,
      76,   245,    76,   259,   262,    76,   265,   268,   271,   274,
     277,   280,   283,   286,   289,   292,   295,   298,   301,   305,
     425,   447,     5,     6,    76,    76,    76,    76,   438,    76,
     109,   116,   116,   149,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,    76,   116,
     316,   317,   318,   439,   440,    76,   442,     9,   116,   443,
      10,   444,    11,   181,   182,   183,    12,   185,    13,    14,
     310,   311,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    13,    14,
     321,   324,   325,   326,    70,    16,   335,   329,   330,   331,
      17,   322,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    38,    39,
     334,     5,     6,   337,   209,   340,   341,   342,   345,   346,
     347,   340,   341,   366,   345,   346,   369,   460,   461,   462,
      38,    39,   214,   215,    18,   257,   258,   260,   261,   263,
     264,   266,   267,   269,   270,   272,   273,   275,   276,    49,
     426,   278,   279,   281,   282,   284,   285,   287,   288,   290,
     291,   293,   294,   296,   297,   299,   300,   302,   303,   306,
     307,   372,   373,   445,   446,   463,   464,    19,    20,    21,
      22,    23,    24,    26,    27,    28,    32,    33,    34,    36,
      37,    43,    44,    45,    46,   114,    50,    51,    52,    53,
      73,    74,   111,    47,   112,   153,   168,   374,   338,   367,
     364,     0,     0,   113,   370,   117,   119,   121,   123,   125,
     127,   129,   131,   133,   135,   137,   139,   141,   143,   145,
     146,   150,   152,   151,   448,   449,   154,   155,   156,   157,
     158,    48,   304,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   169,   176,   177,   180,   186,   184,   187,
     188,   190,   211,   212,   191,   254,   192,     0,   210,   255,
     256,   213,   478,   479,   480,   481,   216,   253,     0,     0,
     312,   315,   320,   323,   328,   333,   336,   339,   344,   349,
     350,   351,   352,   353,   362,   365,   368,   371,   376,   375,
     380,   377,   378,   379,   381,   382,   386,   383,   384,   385,
     387,   388,   389,   390,   391,   392,   398,   393,   394,   395,
     399,   396,   397,   402,   403,   400,   409,   401,   404,   405,
     428,   406,   407,     0,     0,   408,   429,   430,   412,   411,
     538,   539,   417,   418,   419,   420,   542,   543,   421,   422,
     423,   424,   427,   431,   432,   433,   434,   435,   436,   437,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
       0,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     465,   475,     0,   482,   483,   484,   485,   486,   487,   488,
     476,   489,   477,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   540,   541
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
      23,    24,    25,    48,    49,    55,   411,    23,    55,   414,
      35,   416,    23,   171,   172,   173,    23,   175,    23,    24,
     254,   255,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    23,    24,
      25,    23,    24,    25,    27,    23,   273,    23,    24,    25,
      23,   264,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    23,    24,
      25,    23,    24,    25,    27,    23,    24,    25,    23,    24,
      25,    23,    24,    25,    23,    24,    25,   442,   443,   444,
      23,    24,    33,    34,    23,    33,    34,    33,    34,    33,
      34,    33,    34,    33,    34,    33,    34,    33,    34,    32,
     374,    33,    34,    33,    34,    33,    34,    33,    34,    33,
      34,    33,    34,    33,    34,    33,    34,    33,    34,    33,
      34,    25,    26,    33,    34,    25,    26,    23,    35,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    56,    23,    23,    23,    23,
      23,    23,    23,    31,    23,    56,    54,    54,   276,   297,
     294,    -1,    -1,    33,   300,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      21,    23,    33,    23,   428,   429,    33,    33,    33,    33,
      33,    41,    21,    -1,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    23,    23,    31,    23,    32,    23,
      33,    33,    23,    23,    31,    23,    31,    -1,    31,    23,
      25,    33,   466,   467,   468,   469,    33,    33,    -1,    -1,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      25,    33,    25,    33,    33,    33,    33,    33,    25,    33,
      23,    33,    33,    33,    23,    33,    23,    33,    33,    33,
      23,    33,    33,    23,    23,    33,    23,    33,    33,    33,
      23,    33,    33,    23,    23,    33,    23,    33,    33,    33,
      23,    33,    33,    -1,    -1,    33,    23,    23,    33,    35,
     534,   535,    33,    33,    33,    33,   540,   541,    33,    33,
      33,    33,    33,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      -1,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      33,    23,    -1,    23,    23,    23,    23,    23,    23,    23,
      33,    23,    33,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23
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
      31,    23,    23,    33,    33,    34,    33,    27,    69,    27,
      69,    27,    69,    27,    69,    27,    69,    27,    69,    27,
      69,    27,    69,    27,    69,    27,    69,    27,    69,    27,
      69,    27,    69,    27,    69,    27,    69,    27,    53,    69,
      27,    30,    69,    33,    23,    23,    25,    33,    34,    27,
      33,    34,    27,    33,    34,    27,    33,    34,    27,    33,
      34,    27,    33,    34,    27,    33,    34,    27,    33,    34,
      27,    33,    34,    27,    33,    34,    27,    33,    34,    27,
      33,    34,    27,    33,    34,    27,    33,    34,    27,    33,
      34,    27,    33,    34,    21,    27,    33,    34,    27,    30,
      78,    78,    33,    22,    25,    33,    23,    24,    25,    70,
      33,    25,    71,    33,    23,    24,    25,    72,    33,    23,
      24,    25,    73,    33,    25,    74,    33,    25,    75,    33,
      23,    24,    25,    76,    33,    23,    24,    25,    77,    33,
      25,    33,    25,    33,    23,    24,    25,    35,    57,    79,
      80,    81,    33,    25,    79,    33,    25,    76,    33,    25,
      77,    33,    25,    26,    54,    33,    25,    33,    33,    33,
      23,    23,    33,    33,    33,    33,    23,    23,    33,    33,
      23,    23,    33,    33,    33,    33,    33,    33,    23,    23,
      33,    33,    23,    23,    33,    33,    33,    33,    33,    23,
      82,    35,    33,    23,    35,    23,    35,    33,    33,    33,
      33,    33,    33,    33,    33,    27,    69,    33,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    48,
      49,    83,    82,    82,    82,    33,    34,    27,    78,    78,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      83,    83,    83,    25,    26,    33,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    33,    33,    78,    78,
      78,    78,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    78,    78,
      23,    23,    78,    78
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
      66,    66,    66,    66,    66,    66,    66,    66,    67,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    83,    83,
      83,    83
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
      10,     7,     6,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,    10,     4,     5,
       2,     3,     1,     1,     2,     2,     3,     3,     4,     4,
       1,     1,     2,     2,     3,     3,     4,     4,     1,     1,
       2,     2,     3,     3,     4,     4,     5,     5,     6,     6,
       1,     1,     2,     2,     3,     3,     4,     4,     5,     5,
       6,     6,     1,     1,     2,     2,     3,     3,     4,     4,
       5,     5,     6,     6,     7,     7,     8,     8,     9,     9,
      10,    10,    11,    11,     1,     1,     2,     2,     3,     3,
       4,     4,     5,     5,     6,     6,     7,     7,     8,     8,
       9,     9,    10,    10,    11,    11,     1,     1,     2,     2,
       3,     3,     4,     4,     5,     5,     6,     6,     7,     7,
       8,     8,     9,     9,    10,    10,    11,    11,    12,    12,
      13,    13,    14,    14,    15,    15,    16,    16,    17,    17,
      18,    18,    19,    19,    20,    20,     1,     1,     2,     2,
       3,     3,     4,     4,     5,     5,     6,     6,     7,     7,
       8,     8,     9,     9,    10,    10,    11,    11,    12,    12,
      13,    13,    14,    14,    15,    15,    16,    16,    17,    17,
      18,    18,    19,    19,    20,    20,    21,    21,     1,     2,
       1,     1,     3,     3,     3,     2,     4,     4,     4,     3,
       1,     2,     1,     2,     1,     2,     1,     1,     2,     2,
       3,     3
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
     761,   767,   773,   780,   785,   790,   795,   800,   805,   810,
     815,   820,   825,   830,   835,   840,   845,   850,   859,   866,
     879,   883,   894,   898,   902,   906,   910,   923,   936,   940,
     947,   951,   955,   959,   963,   976,   980,   984,   994,   998,
    1002,  1008,  1014,  1021,  1028,  1036,  1044,  1060,  1076,  1080,
    1087,  1091,  1095,  1101,  1105,  1112,  1116,  1124,  1128,  1144,
    1148,  1152,  1162,  1166,  1170,  1176,  1182,  1189,  1196,  1204,
    1212,  1221,  1230,  1240,  1250,  1261,  1272,  1284,  1296,  1309,
    1322,  1343,  1364,  1368,  1375,  1379,  1383,  1389,  1393,  1400,
    1404,  1412,  1416,  1425,  1429,  1439,  1443,  1454,  1458,  1470,
    1474,  1487,  1491,  1512,  1516,  1520,  1530,  1534,  1538,  1544,
    1550,  1557,  1564,  1572,  1580,  1589,  1598,  1608,  1618,  1629,
    1640,  1652,  1664,  1677,  1690,  1704,  1718,  1734,  1750,  1767,
    1784,  1802,  1820,  1839,  1858,  1878,  1898,  1919,  1940,  1962,
    1984,  2007,  2030,  2059,  2088,  2094,  2103,  2107,  2111,  2117,
    2121,  2128,  2132,  2140,  2144,  2153,  2157,  2167,  2171,  2182,
    2186,  2198,  2202,  2215,  2219,  2233,  2237,  2253,  2259,  2276,
    2282,  2300,  2306,  2325,  2331,  2351,  2357,  2378,  2384,  2406,
    2412,  2435,  2441,  2465,  2471,  2505,  2511,  2517,  2525,  2525,
    2532,  2536,  2540,  2544,  2548,  2552,  2556,  2560,  2564,  2568,
    2575,  2579,  2586,  2590,  2597,  2602,  2610,  2614,  2618,  2622,
    2626,  2630
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
#line 5014 "bisonDictionaryTextParser.cc" // lalr1.cc:1156
#line 2637 "bisonDictionaryTextParser.y" // lalr1.cc:1157

//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

