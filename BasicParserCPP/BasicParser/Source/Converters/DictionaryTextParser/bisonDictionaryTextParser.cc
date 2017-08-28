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
	#include "dictionary\dataTypes\dictionaryEnum.h"

	#include "usdsTypes.h"
	
	#include "flexDictionaryTextScanner.h"
	#include <string>
	

#line 69 "bisonDictionaryTextParser.cc" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "bisonDictionaryTextParser.hh"

// User implementation prologue.
#line 135 "bisonDictionaryTextParser.y" // lalr1.cc:406

#undef yylex
#define yylex scanner->scan

#line 87 "bisonDictionaryTextParser.cc" // lalr1.cc:406


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

#line 37 "bisonDictionaryTextParser.y" // lalr1.cc:473
namespace usds {
#line 173 "bisonDictionaryTextParser.cc" // lalr1.cc:473

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
#line 145 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->finalizeDictionary();
	}
#line 628 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 3:
#line 149 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->finalizeDictionary();
	}
#line 636 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 4:
#line 153 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->finalizeDictionary();
	}
#line 644 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 5:
#line 157 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->finalizeDictionary();
	}
#line 652 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 6:
#line 164 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setID(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1], (yystack_[5].value.uInt32Val), (yystack_[2].value.uInt8Val), (yystack_[0].value.uInt8Val));
	}
#line 660 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 7:
#line 168 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setID(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1], 0, (yystack_[2].value.uInt8Val), (yystack_[0].value.uInt8Val));
	}
#line 668 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 8:
#line 172 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setID(input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1], 0, 0, 0);
	}
#line 676 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 11:
#line 181 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setDefaultStringEncode((yystack_[0].value.encodeVal));
	}
#line 684 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 12:
#line 185 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setDefaultEnumSubtype((yystack_[0].value.typeVal), false);
	}
#line 692 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 13:
#line 191 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 698 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 14:
#line 192 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 704 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 15:
#line 193 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 710 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 16:
#line 194 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 716 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 17:
#line 195 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 722 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 18:
#line 196 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 728 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 19:
#line 197 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 734 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 20:
#line 198 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 740 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 21:
#line 199 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 746 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 22:
#line 200 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 752 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 23:
#line 201 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 758 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 24:
#line 202 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 764 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 25:
#line 203 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 770 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 26:
#line 204 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 776 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 27:
#line 205 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 782 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 28:
#line 206 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 788 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 29:
#line 207 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 794 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 32:
#line 216 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 802 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 33:
#line 220 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 810 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 34:
#line 224 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 818 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 35:
#line 228 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 826 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 36:
#line 232 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 834 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 37:
#line 236 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 842 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 38:
#line 240 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 850 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 39:
#line 244 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 858 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 40:
#line 248 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 866 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 41:
#line 252 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 874 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 42:
#line 256 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 882 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 43:
#line 260 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 890 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 44:
#line 264 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 898 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 45:
#line 268 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 906 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 46:
#line 272 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 914 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 47:
#line 276 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 922 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 48:
#line 280 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[5].value.typeVal), (yystack_[7].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)tag)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 931 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 49:
#line 285 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_STRUCT, (yystack_[3].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 939 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 50:
#line 289 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
	
	}
#line 947 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 51:
#line 293 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_ENUM, (yystack_[3].value.int32Val), input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
	}
#line 955 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 53:
#line 298 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_ENUM, (yystack_[6].value.int32Val), input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		((DictionaryEnum*)tag)->setSubtype((yystack_[2].value.typeVal), false);
	}
#line 964 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 55:
#line 306 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 978 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 56:
#line 316 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 992 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 57:
#line 326 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1006 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 58:
#line 336 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1020 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 59:
#line 346 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1034 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 60:
#line 356 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1048 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 61:
#line 366 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1062 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 62:
#line 376 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1076 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 63:
#line 386 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1090 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 64:
#line 396 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1104 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 65:
#line 406 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1118 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 66:
#line 416 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1132 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 67:
#line 426 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1146 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 68:
#line 436 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1160 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 69:
#line 446 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1174 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 70:
#line 456 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1188 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 71:
#line 466 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 1203 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 72:
#line 477 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 1218 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 74:
#line 489 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[4].value.int32Val), input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			tag = ((usds::DictionaryArray*)tag)->setElementType(usds::USDS_ARRAY);
		}
		// for enumerators
		tag = ((usds::DictionaryArray*)tag)->setElementType(USDS_ENUM);
	}
#line 1232 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 76:
#line 500 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			tag = ((usds::DictionaryArray*)tag)->setElementType(usds::USDS_ARRAY);
		}
		// for enumerators
		tag = ((usds::DictionaryArray*)tag)->setElementType(USDS_ENUM);
		((DictionaryEnum*)tag)->setSubtype((yystack_[3].value.typeVal), false);
	}
#line 1247 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 80:
#line 520 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1255 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 81:
#line 524 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1263 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 82:
#line 528 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1271 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 83:
#line 532 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1279 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 84:
#line 536 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1287 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 85:
#line 540 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1295 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 86:
#line 544 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1303 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 87:
#line 548 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1311 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 88:
#line 552 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1319 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 89:
#line 556 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1327 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 90:
#line 560 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1335 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 91:
#line 564 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1343 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 92:
#line 568 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1351 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 93:
#line 572 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1359 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 94:
#line 576 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1367 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 95:
#line 580 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1375 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 96:
#line 584 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField((yystack_[5].value.typeVal), (yystack_[7].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)field)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 1384 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 97:
#line 589 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
	}
#line 1393 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 98:
#line 594 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = tag->getParent();
	}
#line 1401 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 99:
#line 600 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1414 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 100:
#line 609 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1427 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 101:
#line 618 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1440 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 102:
#line 627 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1453 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 103:
#line 636 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1466 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 104:
#line 645 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1479 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 105:
#line 654 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1492 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 106:
#line 663 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1505 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 107:
#line 672 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1518 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 108:
#line 681 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1531 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 109:
#line 690 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1544 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 110:
#line 699 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1557 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 111:
#line 708 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1570 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 112:
#line 717 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1583 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 113:
#line 726 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1596 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 114:
#line 735 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1609 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 115:
#line 744 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[8].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryString* element = (DictionaryString*)arr_field->setElementType((yystack_[6].value.typeVal));	
		element->setDefaultEncode((yystack_[4].value.encodeVal));
	}
#line 1623 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 116:
#line 754 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i <= (yystack_[3].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
	}
#line 1634 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 117:
#line 761 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryTagLink* element = (DictionaryTagLink*)arr_field->setElementType(usds::USDS_TAG);
		element->setTag(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
	}
#line 1648 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 118:
#line 774 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1657 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 119:
#line 779 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1666 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 120:
#line 784 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1675 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 121:
#line 789 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1684 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 122:
#line 794 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1693 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 123:
#line 799 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1702 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 124:
#line 804 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1711 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 125:
#line 809 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1720 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 126:
#line 814 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1729 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 127:
#line 819 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1738 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 128:
#line 824 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1747 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 129:
#line 829 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1756 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 130:
#line 834 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1765 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 131:
#line 839 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1774 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 132:
#line 844 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1783 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 133:
#line 849 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1792 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 134:
#line 854 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), (yystack_[9].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryString*)dict_field)->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setNullable(true);
	}
#line 1802 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 135:
#line 860 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[4].value.stringVal)[0], (yystack_[4].value.stringVal)[1]);
		field->setNullable(true);
	}
#line 1812 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 136:
#line 866 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 1821 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 137:
#line 873 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 138:
#line 883 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 139:
#line 893 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1863 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 140:
#line 903 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1877 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 141:
#line 913 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1891 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 142:
#line 923 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1905 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 143:
#line 933 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1919 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 144:
#line 943 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1933 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 145:
#line 953 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1947 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 146:
#line 963 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1961 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 147:
#line 973 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1975 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 148:
#line 983 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1989 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 149:
#line 993 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2003 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 150:
#line 1003 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2017 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 151:
#line 1013 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2031 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 152:
#line 1023 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2045 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 153:
#line 1033 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2060 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 154:
#line 1044 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i < (yystack_[5].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 2073 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 155:
#line 1053 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2088 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 156:
#line 1066 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBoolean* dict_field = (usds::DictionaryBoolean*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.boolVal));
	}
#line 2097 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 157:
#line 1071 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryByte* dict_field = (usds::DictionaryByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int8Val));
	}
#line 2106 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 158:
#line 1076 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUByte* dict_field = (usds::DictionaryUByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt8Val));
	}
#line 2115 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 159:
#line 1081 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryShort* dict_field = (usds::DictionaryShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int16Val));
	}
#line 2124 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 160:
#line 1086 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUShort* dict_field = (usds::DictionaryUShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt16Val));
	}
#line 2133 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 161:
#line 1091 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryInt* dict_field = (usds::DictionaryInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int32Val));
	}
#line 2142 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 162:
#line 1096 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUInt* dict_field = (usds::DictionaryUInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt32Val));
	}
#line 2151 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 163:
#line 1101 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryLong* dict_field = (usds::DictionaryLong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 2160 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 164:
#line 1106 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryULong* dict_field = (usds::DictionaryULong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 2169 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 165:
#line 1111 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryFloat* dict_field = (usds::DictionaryFloat*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((float)(yystack_[1].value.doubleVal));
	}
#line 2178 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 166:
#line 1116 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryDouble* dict_field = (usds::DictionaryDouble*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.doubleVal));
	}
#line 2187 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 167:
#line 1121 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 2196 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 168:
#line 1126 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 2205 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 169:
#line 1131 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2214 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 170:
#line 1136 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), (yystack_[9].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2224 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 171:
#line 1145 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, (yystack_[3].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2232 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 172:
#line 1152 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[4].value.int32Val), input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_STRUCT);
		(yylhs.value.uInt32Val) = (yystack_[1].value.uInt32Val);
	}
#line 2246 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 175:
#line 1170 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2254 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 176:
#line 1174 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2262 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 177:
#line 1178 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2270 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 178:
#line 1182 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2278 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 179:
#line 1186 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2286 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 180:
#line 1190 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2294 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 181:
#line 1194 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2302 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 182:
#line 1198 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2310 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 183:
#line 1202 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2318 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 184:
#line 1206 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2326 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 185:
#line 1210 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2334 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 186:
#line 1214 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2342 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 187:
#line 1218 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2350 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 188:
#line 1222 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2358 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 189:
#line 1226 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2366 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 190:
#line 1230 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2374 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 191:
#line 1234 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[5].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)tag)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 2383 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 192:
#line 1239 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_STRUCT, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2391 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 193:
#line 1243 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
	
	}
#line 2399 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 194:
#line 1247 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_ENUM, input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
	}
#line 2407 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 196:
#line 1252 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_ENUM, input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		((DictionaryEnum*)tag)->setSubtype((yystack_[2].value.typeVal), false);
	}
#line 2416 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 198:
#line 1260 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2430 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 199:
#line 1270 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2444 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 200:
#line 1280 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2458 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 201:
#line 1290 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2472 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 202:
#line 1300 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2486 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 203:
#line 1310 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2500 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 204:
#line 1320 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2514 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 205:
#line 1330 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2528 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 206:
#line 1340 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2542 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 207:
#line 1350 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2556 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 208:
#line 1360 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2570 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 209:
#line 1370 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2584 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 210:
#line 1380 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2598 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 211:
#line 1390 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2612 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 212:
#line 1400 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2626 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 213:
#line 1410 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2640 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 214:
#line 1420 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		usds::DictionaryString* string_element = (usds::DictionaryString*)arr_tag->setElementType((yystack_[6].value.typeVal));
		string_element->setDefaultEncode((yystack_[4].value.encodeVal));
	}
#line 2655 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 215:
#line 1431 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		// for fields
		tag = arr_tag->setElementType(USDS_STRUCT);
	}
#line 2670 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 217:
#line 1443 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			tag = ((usds::DictionaryArray*)tag)->setElementType(usds::USDS_ARRAY);
		}
		// for enumerators
		tag = ((usds::DictionaryArray*)tag)->setElementType(USDS_ENUM);
	}
#line 2684 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 219:
#line 1454 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			tag = ((usds::DictionaryArray*)tag)->setElementType(usds::USDS_ARRAY);
		}
		// for enumerators
		tag = ((usds::DictionaryArray*)tag)->setElementType(USDS_ENUM);
		((DictionaryEnum*)tag)->setSubtype((yystack_[3].value.typeVal), false);
	}
#line 2699 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 223:
#line 1474 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2707 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 224:
#line 1478 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2715 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 225:
#line 1482 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2723 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 226:
#line 1486 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2731 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 227:
#line 1490 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2739 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 228:
#line 1494 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2747 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 229:
#line 1498 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2755 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 230:
#line 1502 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2763 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 231:
#line 1506 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2771 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 232:
#line 1510 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2779 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 233:
#line 1514 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2787 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 234:
#line 1518 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2795 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 235:
#line 1522 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2803 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 236:
#line 1526 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2811 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 237:
#line 1530 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2819 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 238:
#line 1534 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2827 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 239:
#line 1538 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField((yystack_[5].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)field)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 2836 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 240:
#line 1543 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
	}
#line 2845 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 241:
#line 1548 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = tag->getParent();
	}
#line 2853 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 242:
#line 1554 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2866 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 243:
#line 1563 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2879 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 244:
#line 1572 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2892 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 245:
#line 1581 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2905 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 246:
#line 1590 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2918 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 247:
#line 1599 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2931 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 248:
#line 1608 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2944 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 249:
#line 1617 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2957 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 250:
#line 1626 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2970 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 251:
#line 1635 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2983 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 252:
#line 1644 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2996 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 253:
#line 1653 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3009 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 254:
#line 1662 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3022 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 255:
#line 1671 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3035 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 256:
#line 1680 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3048 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 257:
#line 1689 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3061 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 258:
#line 1698 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryString* element = (DictionaryString*)arr_field->setElementType((yystack_[6].value.typeVal));	
		element->setDefaultEncode((yystack_[4].value.encodeVal));
	}
#line 3075 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 259:
#line 1708 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i <= (yystack_[3].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
	}
#line 3086 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 260:
#line 1715 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryTagLink* element = (DictionaryTagLink*)arr_field->setElementType(usds::USDS_TAG);
		element->setTag(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
	}
#line 3100 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 261:
#line 1728 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3109 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 262:
#line 1733 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3118 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 263:
#line 1738 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3127 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 264:
#line 1743 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3136 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 265:
#line 1748 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3145 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 266:
#line 1753 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3154 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 267:
#line 1758 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3163 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 268:
#line 1763 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3172 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 269:
#line 1768 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3181 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 270:
#line 1773 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3190 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 271:
#line 1778 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3199 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 272:
#line 1783 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3208 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 273:
#line 1788 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3217 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 274:
#line 1793 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3226 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 275:
#line 1798 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3235 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 276:
#line 1803 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3244 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 277:
#line 1808 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryString*)dict_field)->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setNullable(true);
	}
#line 3254 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 278:
#line 1814 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[4].value.stringVal)[0], (yystack_[4].value.stringVal)[1]);
		field->setNullable(true);
	}
#line 3264 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 279:
#line 1820 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 3273 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 280:
#line 1827 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3287 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 281:
#line 1837 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3301 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 282:
#line 1847 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3315 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 283:
#line 1857 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3329 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 284:
#line 1867 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3343 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 285:
#line 1877 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3357 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 286:
#line 1887 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3371 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 287:
#line 1897 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3385 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 288:
#line 1907 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3399 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 289:
#line 1917 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3413 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 290:
#line 1927 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3427 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 291:
#line 1937 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3441 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 292:
#line 1947 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3455 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 293:
#line 1957 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3469 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 294:
#line 1967 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3483 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 295:
#line 1977 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3497 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 296:
#line 1987 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryString* element = (DictionaryString*)arr_field->setElementType((yystack_[8].value.typeVal));	
		element->setDefaultEncode((yystack_[6].value.encodeVal));
	}
#line 3512 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 297:
#line 1998 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i < (yystack_[5].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 3525 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 298:
#line 2007 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryTagLink* element = (DictionaryTagLink*)arr_field->setElementType(usds::USDS_TAG);
		element->setTag(input_text + (yystack_[5].value.stringVal)[0], (yystack_[5].value.stringVal)[1]);
	}
#line 3540 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 299:
#line 2020 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBoolean* dict_field = (usds::DictionaryBoolean*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.boolVal));
	}
#line 3549 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 300:
#line 2025 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryByte* dict_field = (usds::DictionaryByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int8Val));
	}
#line 3558 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 301:
#line 2030 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUByte* dict_field = (usds::DictionaryUByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt8Val));
	}
#line 3567 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 302:
#line 2035 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryShort* dict_field = (usds::DictionaryShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int16Val));
	}
#line 3576 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 303:
#line 2040 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUShort* dict_field = (usds::DictionaryUShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt16Val));
	}
#line 3585 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 304:
#line 2045 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryInt* dict_field = (usds::DictionaryInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int32Val));
	}
#line 3594 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 305:
#line 2050 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUInt* dict_field = (usds::DictionaryUInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt32Val));
	}
#line 3603 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 306:
#line 2055 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryLong* dict_field = (usds::DictionaryLong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 3612 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 307:
#line 2060 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryULong* dict_field = (usds::DictionaryULong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 3621 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 308:
#line 2065 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryFloat* dict_field = (usds::DictionaryFloat*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((float)(yystack_[1].value.doubleVal));
	}
#line 3630 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 309:
#line 2070 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryDouble* dict_field = (usds::DictionaryDouble*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.doubleVal));
	}
#line 3639 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 310:
#line 2075 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 3648 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 311:
#line 2080 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 3657 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 312:
#line 2085 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3666 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 313:
#line 2090 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3676 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 314:
#line 2099 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3684 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 315:
#line 2106 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_STRUCT);
		(yylhs.value.uInt32Val) = (yystack_[1].value.uInt32Val);
	}
#line 3698 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 316:
#line 2122 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 1;
	}
#line 3706 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 317:
#line 2126 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (yylhs.value.uInt32Val) + 1;
	}
#line 3714 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 320:
#line 2138 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryEnum*)tag)->addEnumerator(input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
	}
#line 3722 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 321:
#line 2143 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryEnum*)tag)->addEnumerator((yystack_[0].value.int64Val), input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
	}
#line 3730 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 322:
#line 2154 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[0].value.int8Val);
	}
#line 3738 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 323:
#line 2158 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[0].value.int8Val);
	}
#line 3746 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 324:
#line 2162 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val) * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
	}
#line 3754 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 325:
#line 2166 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val) * (int8_t)10 - (int8_t)(yystack_[0].value.int8Val);
	}
#line 3762 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 326:
#line 2170 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) > (int8_t)1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";

		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)1 && (yylhs.value.int8Val) >= (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";
		
		(yylhs.value.int8Val) = (int8_t)(yystack_[2].value.int8Val) * (int8_t)100 + (yylhs.value.int8Val);
		
	}
#line 3779 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 327:
#line 2183 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) < (int8_t)-1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";

		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)-1 && (yylhs.value.int8Val) > (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";
		
		(yylhs.value.int8Val) = (int8_t)(yystack_[2].value.int8Val) * (int8_t)100 - (yylhs.value.int8Val);
		
	}
#line 3796 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 328:
#line 2196 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int8_t: too big value";
	}
#line 3804 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 329:
#line 2200 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int8_t: too big value";
	}
#line 3812 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 330:
#line 2207 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[0].value.int8Val);
	}
#line 3820 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 331:
#line 2211 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 3828 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 332:
#line 2215 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[1].value.int8Val) * (uint8_t)10 + (uint8_t)(yystack_[0].value.int8Val);
	}
#line 3836 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 333:
#line 2219 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 3844 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 334:
#line 2223 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: too big value";

		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[1].value.int8Val)  * (uint8_t)10 + (uint8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)2 && (yylhs.value.uInt8Val) >= (uint8_t)56)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: too big value";
		
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[2].value.int8Val) * (uint8_t)100 + (yylhs.value.uInt8Val);
		
	}
#line 3861 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 335:
#line 2236 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 3869 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 336:
#line 2240 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint8_t: too big value";
	}
#line 3877 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 337:
#line 2244 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint8_t: too big value";
	}
#line 3885 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 338:
#line 2254 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = (int16_t)(yystack_[0].value.int8Val);
	}
#line 3893 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 339:
#line 2258 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = (int16_t)(yystack_[0].value.int8Val);
	}
#line 3901 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 340:
#line 2262 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3911 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 341:
#line 2268 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3921 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 342:
#line 2274 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3932 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 343:
#line 2281 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 - 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3943 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 344:
#line 2288 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 + 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3955 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 345:
#line 2296 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 - 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 - 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3967 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 346:
#line 2304 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3987 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 347:
#line 2320 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4007 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 348:
#line 2336 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int16_t: too big value";
	}
#line 4015 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 349:
#line 2340 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int16_t: too big value";
	}
#line 4023 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 350:
#line 2347 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = (uint16_t)(yystack_[0].value.int8Val);
	}
#line 4031 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 351:
#line 2351 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4039 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 352:
#line 2355 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 4049 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 353:
#line 2361 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4057 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 354:
#line 2365 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[2].value.int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 4068 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 355:
#line 2372 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4076 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 356:
#line 2376 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[3].value.int8Val) * (uint16_t)1000 + 
		(uint16_t)(yystack_[2].value.int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 4088 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 357:
#line 2384 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4096 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 358:
#line 2388 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4116 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 359:
#line 2404 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4124 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 360:
#line 2408 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint16_t: too big value";
	}
#line 4132 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 361:
#line 2412 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint16_t: too big value";
	}
#line 4140 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 362:
#line 2422 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = (int32_t)(yystack_[0].value.int8Val);
	}
#line 4148 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 363:
#line 2426 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = (int32_t)(yystack_[0].value.int8Val);
	}
#line 4156 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 364:
#line 2430 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4166 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 365:
#line 2436 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4176 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 366:
#line 2442 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4187 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 367:
#line 2449 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4198 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 368:
#line 2456 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4210 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 369:
#line 2464 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4222 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 370:
#line 2472 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4235 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 371:
#line 2481 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4248 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 372:
#line 2490 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4262 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 373:
#line 2500 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 - 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4276 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 374:
#line 2510 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4291 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 375:
#line 2521 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4306 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 376:
#line 2532 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4322 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 377:
#line 2544 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4338 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 378:
#line 2556 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4355 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 379:
#line 2569 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4372 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 380:
#line 2582 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4397 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 381:
#line 2603 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4422 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 382:
#line 2624 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int32_t: too big value";
	}
#line 4430 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 383:
#line 2628 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int32_t: too big value";
	}
#line 4438 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 384:
#line 2635 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (uint32_t)(yystack_[0].value.int8Val);
	}
#line 4446 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 385:
#line 2639 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4454 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 386:
#line 2643 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4464 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 387:
#line 2649 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4472 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 388:
#line 2653 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4483 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 389:
#line 2660 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4491 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 390:
#line 2664 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4503 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 391:
#line 2672 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4511 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 392:
#line 2676 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4524 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 393:
#line 2685 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4532 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 394:
#line 2689 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[5].value.int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4546 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 395:
#line 2699 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4554 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 396:
#line 2703 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4569 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 397:
#line 2714 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4577 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 398:
#line 2718 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4593 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 399:
#line 2730 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4601 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 400:
#line 2734 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4618 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 401:
#line 2747 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4626 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 402:
#line 2751 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4651 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 403:
#line 2772 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4659 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 404:
#line 2776 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint32_t: too big value";
	}
#line 4667 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 405:
#line 2780 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint32_t: negative value";
	}
#line 4675 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 406:
#line 2790 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = (int64_t)(yystack_[0].value.int8Val);
	}
#line 4683 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 407:
#line 2794 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = (int64_t)(yystack_[0].value.int8Val);
	}
#line 4691 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 408:
#line 2798 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4701 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 409:
#line 2804 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4711 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 410:
#line 2810 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4722 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 411:
#line 2817 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4733 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 412:
#line 2824 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4745 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 413:
#line 2832 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4757 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 414:
#line 2840 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4770 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 415:
#line 2849 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4783 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 416:
#line 2858 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4797 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 417:
#line 2868 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4811 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 418:
#line 2878 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4826 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 419:
#line 2889 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4841 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 420:
#line 2900 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4857 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 421:
#line 2912 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4873 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 422:
#line 2924 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4890 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 423:
#line 2937 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4907 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 424:
#line 2950 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4925 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 425:
#line 2964 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4943 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 426:
#line 2979 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4962 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 427:
#line 2995 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4981 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 428:
#line 3011 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5001 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 429:
#line 3028 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5021 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 430:
#line 3045 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5042 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 431:
#line 3063 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5063 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 432:
#line 3081 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5085 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 433:
#line 3100 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5107 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 434:
#line 3119 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5130 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 435:
#line 3139 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5153 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 436:
#line 3159 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5177 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 437:
#line 3180 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5201 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 438:
#line 3201 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5226 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 439:
#line 3223 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5251 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 440:
#line 3245 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5277 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 441:
#line 3268 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5303 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 442:
#line 3291 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5335 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 443:
#line 3320 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5367 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 444:
#line 3349 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int64_t: too big value";
	}
#line 5376 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 445:
#line 3355 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int64_t: too big value";
	}
#line 5385 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 446:
#line 3363 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = (uint64_t)(yystack_[0].value.int8Val);
	}
#line 5393 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 447:
#line 3367 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5401 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 448:
#line 3371 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5411 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 449:
#line 3377 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5419 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 450:
#line 3381 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5430 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 451:
#line 3388 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5438 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 452:
#line 3392 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5450 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 453:
#line 3400 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5458 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 454:
#line 3404 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5471 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 455:
#line 3413 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5479 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 456:
#line 3417 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5493 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 457:
#line 3427 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5501 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 458:
#line 3431 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5516 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 459:
#line 3442 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5524 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 460:
#line 3446 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5540 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 461:
#line 3458 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5548 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 462:
#line 3462 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5565 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 463:
#line 3475 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5573 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 464:
#line 3479 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5591 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 465:
#line 3493 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5599 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 466:
#line 3498 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5618 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 467:
#line 3514 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) 
			<< (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5627 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 468:
#line 3520 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5647 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 469:
#line 3537 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) 
			<< (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5656 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 470:
#line 3543 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5677 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 471:
#line 3561 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) 
			<< (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5686 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 472:
#line 3567 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5708 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 473:
#line 3586 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) 
			<< (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5717 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 474:
#line 3592 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5740 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 475:
#line 3612 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) 
			<< (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5749 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 476:
#line 3618 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5773 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 477:
#line 3639 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) 
			<< (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5782 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 478:
#line 3645 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5807 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 479:
#line 3667 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) 
			<< (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5816 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 480:
#line 3673 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5842 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 481:
#line 3696 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) 
			<< (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5851 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 482:
#line 3702 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5878 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 483:
#line 3726 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) 
			<< (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5887 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 484:
#line 3732 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5924 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 485:
#line 3766 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) 
			<< (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5933 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 486:
#line 3772 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[20].value.int8Val) << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint64_t: too big value";
	}
#line 5942 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 487:
#line 3778 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[20].value.int8Val) << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) 
			<< (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint64_t: negative value";
	}
#line 5951 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 490:
#line 3792 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.doubleVal);
	}
#line 5959 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 491:
#line 3796 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.doubleVal);
	}
#line 5967 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 492:
#line 3800 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[2].value.doubleVal) + (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 5975 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 493:
#line 3804 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[2].value.doubleVal) - (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 5983 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 494:
#line 3808 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = - (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;	
	}
#line 5991 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 495:
#line 3812 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 5999 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 496:
#line 3816 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[3].value.doubleVal) + (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 6007 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 497:
#line 3820 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[3].value.doubleVal) - (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 6015 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 498:
#line 3824 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (- (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));	
	}
#line 6023 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 499:
#line 3828 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 6031 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 500:
#line 3835 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 6039 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 501:
#line 3839 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yylhs.value.doubleVal) * 10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 6047 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 502:
#line 3846 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 6055 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 503:
#line 3850 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yylhs.value.doubleVal) * 10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 6063 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 504:
#line 3857 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.floatDigits).value = (double)(yystack_[0].value.int8Val);
		(yylhs.value.floatDigits).digits = 10.0;
	}
#line 6072 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 505:
#line 3862 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.floatDigits).value = (yylhs.value.floatDigits).value * 10.0 + (double)(yystack_[0].value.int8Val);
		(yylhs.value.floatDigits).digits = (yylhs.value.floatDigits).digits * 10.0;
	}
#line 6081 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 506:
#line 3870 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 6089 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 507:
#line 3874 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 6097 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 508:
#line 3878 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[1].value.int8Val) * (double)10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 6105 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 509:
#line 3882 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[1].value.int8Val) * (double)10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 6113 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 510:
#line 3886 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[2].value.int8Val) * (double)100.0 + (double)(yystack_[1].value.int8Val) * (double)10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 6121 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 511:
#line 3890 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[2].value.int8Val) * (double)100.0 - (double)(yystack_[1].value.int8Val) * (double)10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 6129 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;


#line 6133 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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


  const short int BisonDictionaryTextParser::yypact_ninf_ = -594;

  const signed char BisonDictionaryTextParser::yytable_ninf_ = -1;

  const short int
  BisonDictionaryTextParser::yypact_[] =
  {
      51,    21,   152,    24,   134,   421,   431,   425,  -594,   444,
     648,   473,   356,   162,   437,   683,   714,   733,   240,   360,
    -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,
    -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,    30,
      34,    44,    52,    53,    54,    60,    62,    64,    65,    69,
      90,    92,    95,    96,    -4,     4,   735,   812,   416,   552,
     475,   805,   508,   785,   473,  -594,   814,   815,   816,   817,
     431,   431,   409,   784,    97,   809,   118,   810,   138,   811,
     139,   813,   140,   818,   142,   819,   143,   820,   145,   821,
     146,   822,   170,   823,   173,   824,   176,   825,   177,   826,
     178,   827,   179,   828,   829,   180,  -594,   648,   181,   839,
     840,  -594,   417,  -594,  -594,  -594,  -594,   560,   833,   834,
     843,   844,   845,   845,  -594,   835,  -594,  -594,   836,   790,
    -594,   838,  -594,   841,  -594,   842,  -594,   846,  -594,   847,
    -594,   848,  -594,   849,  -594,   850,  -594,   851,  -594,   852,
    -594,   853,  -594,   854,  -594,   855,  -594,   856,  -594,   793,
     858,   862,   857,  -594,   870,   871,   533,  -594,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,    20,    28,   418,  -594,  -594,   872,   873,
    -594,   874,   874,   431,  -594,  -594,  -594,  -594,  -594,  -594,
    -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,
     198,  -594,   875,   200,   868,   876,   877,   201,   203,   204,
     211,   228,   231,   234,   235,   236,   237,   238,   239,   241,
     242,   243,    29,    32,   878,   533,   533,   533,   533,   880,
     244,   881,   245,   882,   246,   883,   247,   884,   249,   885,
     250,   886,   251,   887,   252,   888,   253,   889,   254,   890,
     255,   891,   256,   892,   258,   893,   259,   894,   261,   895,
     908,   262,  -594,   648,   269,  -594,   419,   907,   909,  -594,
    -594,   898,   286,   867,   879,   787,  -594,   292,   875,   910,
     911,   577,   293,   583,   294,   614,   295,   635,   296,   637,
     297,   639,   299,   641,   300,   643,   301,   645,   302,   647,
     303,   649,   304,   651,   305,   653,   306,   655,   307,   657,
     308,   659,   914,   309,   661,  -594,    38,   903,  -594,   906,
     912,   913,  -594,   905,  -594,   915,  -594,   916,  -594,   919,
    -594,   920,  -594,   921,  -594,   922,  -594,   925,  -594,   926,
    -594,   927,  -594,   928,  -594,   929,  -594,   930,  -594,   931,
    -594,   932,  -594,   917,   933,   937,   918,  -594,   475,  -594,
     923,   924,  -594,   935,   673,   936,   875,   940,  -594,   943,
     948,   952,  -594,    81,   665,  -594,   380,   667,  -594,   428,
     669,  -594,   439,   671,  -594,   470,   674,  -594,   478,   676,
    -594,   481,   678,  -594,   484,   680,  -594,   505,   682,  -594,
     951,   684,  -594,   953,   686,  -594,     5,   688,  -594,    11,
     690,  -594,   509,   692,  -594,   531,   694,  -594,   704,   934,
     702,  -594,   954,   705,  -594,  -594,   707,   709,   944,  -594,
    -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,
    -594,  -594,  -594,  -594,   310,  -594,   875,   311,   950,   955,
     475,   475,   475,   949,   475,   959,   960,  -594,   961,   962,
    -594,  -594,  -594,   875,   957,   958,   965,   967,   963,   964,
    -594,   968,   969,   971,   966,   970,  -594,   973,   972,   974,
    -594,   975,   978,   979,   976,   977,  -594,   981,   985,   988,
     980,   982,  -594,   987,   983,   984,  -594,   989,   986,   990,
    -594,   993,   991,   992,  -594,   995,   998,   999,   994,   996,
    -594,  1001,   997,  -594,  1003,  1000,  -594,  1006,  -594,  -594,
    1002,  1009,   837,  1004,    -3,    76,  -594,  1011,  1005,  1007,
    -594,  1014,  1008,  1010,  -594,  1017,  1012,  1013,  -594,  1019,
    1015,  1016,   312,  -594,  1022,  1018,  -594,  1025,  -594,  1027,
    -594,  1028,  -594,  1021,   314,  1024,  -594,   316,   875,  1023,
    -594,  1026,  1029,   585,  1030,  1035,  1036,  1039,  1040,  1033,
     875,  -594,  1042,  1043,  -594,  -594,  1034,  1045,  1046,  -594,
    -594,  1037,  -594,  -594,  1038,  1049,  1050,  -594,  -594,  1041,
    1052,  1053,  -594,  -594,  1044,  -594,  -594,  1047,  -594,  -594,
    1048,  -594,  -594,  1051,  1055,  1056,  -594,  -594,  1054,  -594,
    1057,  -594,  1058,  -594,  -594,   422,  1009,  -594,  -594,  1009,
    -594,  1009,  1059,  -594,  -594,  1060,  -594,  -594,  1061,  -594,
    -594,  1062,  -594,  -594,   711,   317,  1063,  -594,  1064,  1065,
    1066,  -594,  1067,  1068,  1072,  -594,  1073,  -594,   713,   715,
     318,   319,   320,   327,   342,   344,   350,   351,   352,   353,
     354,   355,   357,   358,   361,    39,    42,  1070,   845,   845,
    1082,  1083,  1074,  1077,  1086,  1087,  -594,   845,   845,  -594,
    -594,  1088,  1089,  -594,  1090,  1091,  -594,  -594,  -594,  -594,
    1092,  1093,  -594,  -594,  -594,  -594,  1094,  1095,  -594,   422,
     422,   422,  -594,  -594,  -594,  -594,  -594,   725,   719,  -594,
    -594,  -594,  -594,  -594,  -594,   875,  1096,  1097,  -594,  1098,
    -594,  1099,   721,   362,   726,   363,   728,   364,   730,   365,
     732,   366,   734,   367,   736,   368,   738,   369,   740,   370,
     742,   372,   744,   375,   746,   400,   748,   402,   750,   403,
     752,   410,   754,  1100,   411,   756,  -594,    48,  -594,   874,
     874,  1102,  1104,  -594,  1101,   845,   845,   874,   874,  1105,
    1106,  1108,  1109,  1110,  1112,  1113,  1114,  -594,  -594,  -594,
    1107,  1111,  -594,  1116,  1115,   875,  -594,  1117,  1118,  -594,
     125,   758,  -594,   534,   760,  -594,   557,   762,  -594,   561,
     764,  -594,   581,   766,  -594,   584,   768,  -594,   590,   770,
    -594,   612,   772,  -594,   615,   774,  -594,  1120,   776,  -594,
    1122,   778,  -594,    14,   780,  -594,    18,   782,  -594,   618,
     786,  -594,   621,   788,  -594,   798,  1031,   792,  -594,  1123,
     794,  -594,  1119,  1126,  -594,   874,   874,   845,   845,   845,
     845,  1129,  1130,  -594,  -594,  -594,  -594,  1121,  1124,  1125,
    -594,  -594,  1127,  1128,  -594,  1133,  1131,  1132,  -594,  1134,
    1135,  1136,  -594,  1137,  1138,  1139,  -594,  1141,  1140,  1142,
    -594,  1145,  1143,  1144,  -594,  1149,  1146,  1147,  -594,  1153,
    1148,  1150,  -594,  1157,  1151,  1152,  -594,  1161,  1154,  -594,
    1163,  1156,  -594,  1165,  1158,  1159,  -594,  1168,  1162,  1164,
    -594,  1169,  1166,  1167,  -594,  1171,  1170,  1172,  -594,  1173,
    1174,  1175,   412,  -594,  1176,  1177,  -594,  1179,  1183,  1186,
     874,   874,   874,   874,  1188,  1189,  -594,  -594,  1180,  -594,
    -594,  1181,  -594,  -594,  1182,  -594,  -594,  1184,  -594,  -594,
    1185,  -594,  -594,  1187,  -594,  -594,  1190,  -594,  -594,  1191,
    -594,  -594,  1192,  -594,  -594,  1193,  -594,  1194,  -594,  1195,
    -594,  -594,  1196,  -594,  -594,  1197,  -594,  -594,  1198,  -594,
    -594,  1199,  -594,  -594,   796,   413,  1200,  -594,  1201,  1212,
    1213,  1214,  1215,  -594,  -594,  -594,  -594,  -594,  -594,  -594,
    -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,
     806,   800,  -594,  -594,  1216,  1217,  1218,  1219,  1210,  1211,
    -594,  1220,  1223,  1224,  1225,  1226,  -594,  -594,  1221,  1227,
    1228,  1229,  1230,  -594,  1232,  1233,  1234,  1235,  1236,  1237,
    1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,  1247,
    1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,
    1258,  1259,  1260,  1261,  1262,  1263,   845,   845,  1264,  1265,
     874,   874,   845,   845,   874,   874
  };

  const unsigned short int
  BisonDictionaryTextParser::yydefact_[] =
  {
       0,     0,     0,     0,   384,   385,     8,     0,     1,     0,
       0,     0,     0,     9,   386,   387,   330,   331,     0,     0,
      11,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   362,   363,     0,     0,
      30,     0,   173,     0,     0,    10,   388,   389,   332,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   194,     0,     0,   364,
     365,   192,     0,     2,    31,     4,   174,     0,     0,     0,
     390,   391,   334,   335,     7,     0,   175,   316,     0,     0,
     176,     0,   177,     0,   178,     0,   179,     0,   180,     0,
     181,     0,   182,     0,   183,     0,   184,     0,   185,     0,
     186,     0,   187,     0,   188,     0,   189,     0,   190,     0,
       0,     0,     0,   217,   366,   367,     0,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     5,   392,   393,
     488,   336,   337,     0,   198,   317,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,   213,     0,     0,     0,   368,   369,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,    49,     0,   394,   395,   489,
       6,     0,     0,   320,     0,   318,   196,     0,     0,   370,
     371,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   314,     0,     0,   222,     0,
       0,     0,    32,     0,    33,     0,    34,     0,    35,     0,
      36,     0,    37,     0,    38,     0,    39,     0,    40,     0,
      41,     0,    42,     0,    43,     0,    44,     0,    45,     0,
      46,     0,    47,     0,     0,     0,     0,    74,     0,    72,
     396,   397,   191,     0,     0,     0,     0,     0,   219,     0,
     372,   373,   223,     0,     0,   224,     0,     0,   225,     0,
       0,   226,     0,     0,   227,     0,     0,   228,     0,     0,
     229,     0,     0,   230,     0,     0,   231,     0,     0,   232,
       0,     0,   233,     0,     0,   234,     0,     0,   235,     0,
       0,   236,     0,     0,   237,     0,     0,   238,     0,     0,
       0,   240,     0,     0,   315,   193,     0,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    70,     0,     0,     0,     0,
      78,     0,     0,     0,     0,   398,   399,   214,   406,   407,
     321,   195,   319,     0,     0,     0,   374,   375,     0,     0,
     242,     0,   322,   323,     0,     0,   243,     0,     0,     0,
     244,     0,   338,   339,     0,     0,   245,     0,   350,   351,
       0,     0,   246,     0,     0,     0,   247,     0,     0,     0,
     248,     0,     0,     0,   249,     0,   446,   447,     0,     0,
     250,     0,     0,   251,     0,     0,   252,     0,   500,   502,
       0,     0,     0,     0,   490,   491,   253,     0,     0,     0,
     254,     0,     0,     0,   255,     0,     0,     0,   256,     0,
       0,     0,     0,   257,     0,     0,   260,     0,   241,     0,
     259,     0,   216,     0,     0,     0,    53,     0,     0,     0,
      79,     0,     0,     0,     0,   400,   401,   408,   409,     0,
       0,   218,   376,   377,   299,   261,     0,   324,   325,   262,
     300,     0,   263,   301,     0,   340,   341,   264,   302,     0,
     352,   353,   265,   303,     0,   266,   304,     0,   267,   305,
       0,   268,   306,     0,   448,   449,   269,   307,     0,   270,
       0,   271,     0,   272,   504,   495,     0,   308,   501,     0,
     503,     0,     0,   273,   309,     0,   274,   310,     0,   275,
     311,     0,   276,   312,     0,     0,     0,   278,     0,     0,
       0,    48,     0,     0,     0,    76,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   402,   403,
     410,   411,     0,     0,   378,   379,   280,   326,   327,   281,
     282,   342,   343,   283,   354,   355,   284,   285,   286,   287,
     450,   451,   288,   289,   290,   505,   506,   507,   499,   494,
     492,   493,   291,   292,   293,   294,   239,     0,     0,   295,
     298,   279,   297,    71,    52,     0,     0,     0,    98,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,     0,    73,   404,
     405,   412,   413,   197,     0,   380,   381,   328,   329,   344,
     345,   356,   357,   452,   453,   508,   509,   498,   496,   497,
       0,     0,   258,     0,     0,     0,    75,     0,     0,    80,
       0,     0,    81,     0,     0,    82,     0,     0,    83,     0,
       0,    84,     0,     0,    85,     0,     0,    86,     0,     0,
      87,     0,     0,    88,     0,     0,    89,     0,     0,    90,
       0,     0,    91,     0,     0,    92,     0,     0,    93,     0,
       0,    94,     0,     0,    95,     0,     0,     0,    97,     0,
       0,   172,   414,   415,   220,   382,   383,   346,   347,   358,
     359,   454,   455,   510,   511,   277,   313,     0,     0,     0,
     136,   154,     0,     0,    99,     0,     0,     0,   100,     0,
       0,     0,   101,     0,     0,     0,   102,     0,     0,     0,
     103,     0,     0,     0,   104,     0,     0,     0,   105,     0,
       0,     0,   106,     0,     0,     0,   107,     0,     0,   108,
       0,     0,   109,     0,     0,     0,   110,     0,     0,     0,
     111,     0,     0,     0,   112,     0,     0,     0,   113,     0,
       0,     0,     0,   114,     0,     0,   117,     0,   416,   417,
     348,   349,   360,   361,   456,   457,   296,    54,     0,   156,
     118,     0,   119,   157,     0,   120,   158,     0,   121,   159,
       0,   122,   160,     0,   123,   161,     0,   124,   162,     0,
     125,   163,     0,   126,   164,     0,   127,     0,   128,     0,
     129,   165,     0,   130,   166,     0,   131,   167,     0,   132,
     168,     0,   133,   169,     0,     0,     0,   135,     0,   418,
     419,   458,   459,    77,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    96,
       0,     0,   152,   155,   420,   421,   460,   461,     0,     0,
     115,     0,   422,   423,   462,   463,   134,   170,     0,   424,
     425,   464,   465,   153,   426,   427,   466,   467,   428,   429,
     468,   469,   430,   431,   470,   471,   432,   433,   472,   473,
     434,   435,   474,   475,   436,   437,   476,   477,   438,   439,
     478,   479,   440,   441,   480,   481,   442,   443,   482,   483,
     444,   445,   484,   485,   486,   487
  };

  const short int
  BisonDictionaryTextParser::yypgoto_[] =
  {
    -594,  -594,  -594,   863,  -594,   -77,    40,  -594,  -594,  -594,
    -594,  -594,  -594,  -594,  -303,  -594,  -594,  -594,   382,  -594,
    -594,  -594,  -594,  -594,  -594,  -594,   -73,  -594,  -594,  -594,
     -39,  -261,  -594,    49,   -46,    70,    68,     6,  -380,  -386,
    -405,  -123,  -397,  -594,  -594,  -521,  -593
  };

  const short int
  BisonDictionaryTextParser::yydefgoto_[] =
  {
      -1,     2,     3,    12,    13,    38,    59,    60,   368,   365,
     654,   464,   458,   726,   459,   460,   461,   462,    61,    62,
     166,   161,   377,   238,   214,   474,   234,   235,   236,   237,
      74,   284,   285,   485,    18,   495,   501,   463,     7,   470,
     519,   191,   533,   534,   535,   625,   708
  };

  const unsigned short int
  BisonDictionaryTextParser::yytable_[] =
  {
     192,    76,    78,    80,    82,    84,    86,    88,    90,    92,
      94,    96,    98,   100,   102,   105,   108,    63,   513,   112,
     547,   509,   539,   628,   124,   125,   103,   379,     9,    10,
     162,   528,   529,   530,   106,   629,   543,   528,   529,   538,
     528,   529,   914,   531,   528,   529,   918,     4,     5,   531,
     269,     6,   531,   104,     1,    73,   531,    11,   272,   321,
      72,   107,   324,    73,    75,   325,    63,   532,   433,   762,
      63,   434,   765,   532,    77,   766,   532,   270,   850,    73,
     532,   851,    79,    81,    83,   273,   322,    73,    73,    73,
      85,    73,    87,    73,    89,    91,   763,   129,    73,    93,
     114,    73,   630,    73,   118,   709,   478,   129,   710,   479,
     711,    73,    73,    73,   631,   472,   787,   788,   789,    73,
      95,    73,    97,    73,    73,    99,   101,   128,    73,   240,
     242,   244,   246,   248,   250,   252,   254,   256,   258,   260,
     262,   264,   266,   268,   271,   274,   276,   280,   131,    73,
     872,    73,     8,   873,    73,    73,   129,   570,   571,   572,
      14,   574,   328,   329,   330,   331,     9,    10,   133,   135,
     137,   282,   139,   141,   287,   143,   145,   129,   292,   294,
     296,   298,   300,   302,   304,   306,   308,   310,   312,   314,
     316,   318,   320,   323,   326,   565,   366,   129,   129,   129,
     147,   129,   129,   149,   129,   129,   151,   153,   155,   157,
     160,   163,   579,   239,   241,   243,   245,   247,   249,   251,
     253,   255,   257,   259,   261,   263,   265,   267,   281,   129,
     286,   291,   129,   293,   295,   129,   129,   129,   129,   129,
     129,   297,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,   299,    73,
      73,   301,    73,    73,   303,   305,   307,   309,   311,   313,
      73,   315,   317,   319,   333,   335,   337,   339,    70,   341,
     343,   345,   347,   349,   351,   353,   355,    73,   357,   359,
      73,   361,   364,    73,    73,    73,    73,    73,    73,   367,
      73,    73,    73,   129,   129,   129,   129,   656,   129,   129,
     129,   129,   129,   129,   129,   129,   373,   129,   129,   683,
     129,   129,   378,   384,   387,   390,   393,   396,   129,   399,
     402,   405,   408,   411,   414,   417,   420,   423,   426,   430,
     563,   566,   644,   489,   652,   129,   655,   718,   732,   734,
     736,   129,   129,   129,   129,   129,   129,   738,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,    73,
      73,    73,   740,   129,   742,   129,   129,    73,    73,    73,
     744,   746,   748,   750,   752,   754,    73,   756,   758,    64,
      71,   760,   801,   804,   807,   810,   813,   816,   819,   822,
     825,    73,   828,    73,   505,   831,   482,   483,   484,    73,
      73,    73,    73,    73,    73,   564,    73,    73,   567,   905,
      73,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     834,   129,   837,   840,   129,   901,   915,   927,   897,   919,
     843,   847,   994,  1021,   116,   126,   119,    15,   705,   111,
     167,   275,   369,   923,    16,    17,   488,    16,    17,   129,
      19,   129,   129,    66,   794,   492,   493,   494,    20,   129,
     129,    73,   129,   706,   707,    73,   129,    73,   129,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,   498,   499,   500,    56,
      57,    56,    57,    58,    56,    57,   504,     4,     5,   508,
     468,   469,   512,   645,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,   516,   517,   518,   869,   468,   469,   542,    58,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   769,   770,   516,   517,   546,
     482,   483,   876,   233,   777,   778,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,    16,    17,   880,   113,   492,   493,   884,
     185,   660,   661,   662,   663,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,   674,   675,   498,   499,   888,
      56,    57,   892,   382,   383,   676,     4,     5,   896,   385,
     386,   733,   735,   737,   739,   741,   743,   745,   747,   749,
     751,   753,   755,   757,   759,   761,   764,   767,   468,   469,
     900,   516,   517,   904,   468,   469,   922,   516,   517,   926,
     388,   389,   855,   856,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,   391,   392,   394,   395,   397,   398,   400,   401,   403,
     404,   406,   407,   409,   410,   412,   413,   415,   416,   418,
     419,   421,   422,   424,   425,   427,   428,   431,   432,   468,
     469,   480,   481,   486,   487,   490,   491,   496,   497,    67,
     502,   503,   506,   507,   510,   511,   514,   515,   520,   521,
     523,   524,   526,   527,   536,   537,   540,   541,   544,   545,
     548,   549,   550,   551,   940,   941,   942,   943,   553,   554,
      68,   556,   557,   558,   559,   560,   561,   716,   717,   728,
     729,   730,   731,   790,   791,   792,   793,   799,   800,    69,
     881,   109,   802,   803,   805,   806,   808,   809,   811,   812,
     814,   815,   817,   818,   820,   821,   823,   824,   826,   827,
     829,   830,   832,   833,   835,   836,   838,   839,   841,   842,
     844,   845,   848,   849,   874,   875,   878,   879,   882,   883,
     886,   887,   890,   891,   894,   895,   898,   899,   902,   903,
     906,   907,   909,   910,   912,   913,   916,   917,   920,   921,
     117,   893,   924,   925,   928,   929,   930,   931,   933,   934,
     936,   937,  1019,  1020,  1028,  1029,  1030,  1031,   110,   115,
     120,   121,   122,   123,   127,   130,   132,   134,   376,   136,
     195,   210,   877,   159,   138,   140,   142,   144,   146,   148,
     150,   152,   154,   156,   158,   164,   165,   186,   187,   188,
     189,   190,   194,   193,   196,   626,    65,   197,   198,   885,
     889,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   995,   211,   212,   215,   216,   277,   278,
     279,   288,   289,   290,   374,   283,     0,     0,     0,     0,
       0,     0,   327,   375,     0,   213,   332,   334,   336,   338,
     340,   342,   344,   346,   348,   350,   352,   354,   356,   358,
     360,   362,   363,   370,   372,   371,   380,   381,   429,   435,
     436,   439,     0,     0,     0,     0,   437,   438,     0,   465,
     466,   440,   441,  1080,  1081,   442,   443,   444,   445,  1084,
    1085,   446,   447,   448,   449,   450,   451,   452,   453,   455,
     456,   467,   471,   473,   476,   454,   457,   475,   477,   522,
     562,   525,   555,   568,   573,   575,   576,   577,   578,   569,
     580,   582,   552,   583,   581,   587,   586,   588,     0,   584,
     585,   591,   589,   594,   595,   596,   590,     0,   592,   599,
     593,   600,   597,   598,   601,   604,   602,   607,   603,   605,
     606,   610,   608,   613,   614,   615,   609,   611,   612,   618,
     616,   620,   617,   619,   622,   624,   621,     0,   623,   632,
     627,   633,   635,   634,   636,   638,   637,   641,   639,   640,
     646,   642,   643,   648,   647,   649,   650,   651,   653,   657,
     658,   678,   679,   659,   677,   680,   681,   682,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   700,   701,   697,   698,     0,     0,   699,     0,   932,
     702,     0,     0,   703,   704,   712,   713,   714,   715,   719,
     720,   721,   722,   723,   724,   725,   768,   727,   771,   772,
     773,   774,   775,   776,   779,   780,   781,   782,   783,   784,
     785,   786,     0,     0,   846,     0,   797,   798,   852,   795,
     853,   857,   858,   796,   859,   860,   861,   854,   862,   863,
     864,     0,     0,   865,   867,   938,     0,   866,   908,   868,
     911,   935,   939,   870,   871,   944,   945,   946,     0,   948,
     947,   951,   954,   949,   950,   957,     0,   952,   953,   960,
       0,   955,   956,   963,   958,   959,   961,   966,   962,   964,
     965,   969,   967,   968,   970,   972,   971,   973,   974,   975,
     976,   977,   978,   979,   980,   981,   982,   985,   983,   988,
     984,   991,   986,   987,   996,     0,   989,   998,   990,   999,
     992,   993,  1000,   997,  1001,  1002,  1003,  1004,  1005,     0,
    1006,  1007,     0,  1008,     0,     0,  1009,  1010,  1011,  1012,
    1013,  1014,  1015,  1016,  1017,  1018,  1022,  1023,  1024,  1025,
    1026,  1027,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,
    1040,  1041,  1042,  1044,  1045,  1046,  1047,  1043,  1048,  1049,
    1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1082,  1083
  };

  const short int
  BisonDictionaryTextParser::yycheck_[] =
  {
     123,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    11,   404,    58,
     425,   401,   419,    26,    70,    71,    30,   288,     4,     5,
     107,    26,    27,    28,    30,    38,   422,    26,    27,    28,
      26,    27,    28,    38,    26,    27,    28,    26,    27,    38,
      30,    30,    38,    57,     3,    59,    38,    33,    30,    30,
      30,    57,    30,    59,    30,    33,    60,    62,    30,    30,
      64,    33,    30,    62,    30,    33,    62,    57,    30,    59,
      62,    33,    30,    30,    30,    57,    57,    59,    59,    59,
      30,    59,    30,    59,    30,    30,    57,    59,    59,    30,
      60,    59,    26,    59,    64,   626,    25,    59,   629,    28,
     631,    59,    59,    59,    38,   376,   709,   710,   711,    59,
      30,    59,    30,    59,    59,    30,    30,    30,    59,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   193,    30,    59,
      25,    59,     0,    28,    59,    59,    59,   460,   461,   462,
      26,   464,   235,   236,   237,   238,     4,     5,    30,    30,
      30,   210,    30,    30,   213,    30,    30,    59,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   456,   273,    59,    59,    59,
      30,    59,    59,    30,    59,    59,    30,    30,    30,    30,
      30,    30,   473,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    59,
      30,    30,    59,    30,    30,    59,    59,    59,    59,    59,
      59,    30,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    30,    59,
      59,    30,    59,    59,    30,    30,    30,    30,    30,    30,
      59,    30,    30,    30,    30,    30,    30,    30,    38,    30,
      30,    30,    30,    30,    30,    30,    30,    59,    30,    30,
      59,    30,    30,    59,    59,    59,    59,    59,    59,    30,
      59,    59,    59,    59,    59,    59,    59,   568,    59,    59,
      59,    59,    59,    59,    59,    59,    30,    59,    59,   580,
      59,    59,    30,    30,    30,    30,    30,    30,    59,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,   389,    30,    59,    30,    30,    30,    30,
      30,    59,    59,    59,    59,    59,    59,    30,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    30,    59,    30,    59,    59,    59,    59,    59,
      30,    30,    30,    30,    30,    30,    59,    30,    30,    33,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    59,    30,    59,   398,    30,    26,    27,    28,    59,
      59,    59,    59,    59,    59,   454,    59,    59,   457,   824,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      30,    59,    30,    30,    59,   821,   833,   842,   818,   836,
      30,    30,    30,    30,    62,    36,    64,    26,    26,    33,
      33,    33,    33,   839,    26,    27,    28,    26,    27,    59,
      35,    59,    59,    26,   725,    26,    27,    28,    24,    59,
      59,    59,    59,    51,    52,    59,    59,    59,    59,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    26,    27,    28,    26,
      27,    26,    27,    30,    26,    27,    28,    26,    27,    28,
      26,    27,    28,   552,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    26,    27,    28,   795,    26,    27,    28,    30,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   678,   679,    26,    27,    28,
      26,    27,    28,    30,   687,   688,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    26,    27,    28,    34,    26,    27,    28,
      30,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    26,    27,    28,
      26,    27,    28,    36,    37,    30,    26,    27,    28,    36,
      37,   660,   661,   662,   663,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,   674,   675,   676,    26,    27,
      28,    26,    27,    28,    26,    27,    28,    26,    27,    28,
      36,    37,   775,   776,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    36,    37,    36,    37,    36,    37,    36,    37,    36,
      37,    36,    37,    36,    37,    36,    37,    36,    37,    36,
      37,    36,    37,    36,    37,    36,    37,    36,    37,    26,
      27,    36,    37,    36,    37,    36,    37,    36,    37,    26,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    28,    29,   857,   858,   859,   860,    36,    37,
      26,    36,    37,    36,    37,    36,    37,    36,    37,    36,
      37,    36,    37,    28,    29,    36,    37,    36,    37,    26,
     806,    26,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      35,   815,    36,    37,    36,    37,    28,    29,    36,    37,
      36,    37,    36,    37,    28,    29,    36,    37,    26,    34,
      26,    26,    26,    26,    60,    36,    36,    36,    61,    36,
      60,    58,   803,    24,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    26,    26,    34,    34,    26,
      26,    26,    36,    38,    36,    38,    13,    36,    36,   809,
     812,    -1,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,   932,    36,    33,    26,    26,    26,    26,
      26,    33,    26,    26,    37,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    34,    -1,    58,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    24,    26,    36,    26,    26,    26,    24,    36,
      34,    36,    -1,    -1,    -1,    -1,    34,    34,    -1,    26,
      26,    36,    36,  1076,  1077,    36,    36,    36,    36,  1082,
    1083,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      33,    36,    36,    33,    26,    58,    58,    34,    26,    28,
      36,    28,    28,    33,    35,    26,    26,    26,    26,    34,
      33,    26,    58,    26,    36,    26,    28,    26,    -1,    36,
      36,    28,    36,    28,    26,    26,    36,    -1,    36,    28,
      36,    26,    36,    36,    26,    28,    36,    28,    36,    36,
      36,    28,    36,    28,    26,    26,    36,    36,    36,    28,
      36,    28,    36,    36,    28,    26,    36,    -1,    36,    28,
      36,    36,    28,    36,    36,    28,    36,    28,    36,    36,
      28,    36,    36,    28,    36,    28,    28,    36,    34,    36,
      34,    26,    26,    34,    34,    26,    26,    34,    26,    26,
      36,    26,    26,    36,    36,    26,    26,    36,    26,    26,
      36,    26,    26,    36,    36,    -1,    -1,    36,    -1,    58,
      36,    -1,    -1,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    33,    36,    34,    26,    26,
      36,    34,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    -1,    -1,    24,    -1,    28,    28,    26,    33,
      26,    26,    26,    36,    26,    26,    26,    36,    26,    26,
      26,    -1,    -1,    36,    28,    26,    -1,    36,    28,    34,
      28,    28,    26,    36,    36,    26,    26,    36,    -1,    34,
      36,    28,    28,    36,    36,    28,    -1,    36,    36,    28,
      -1,    36,    36,    28,    36,    36,    36,    28,    36,    36,
      36,    28,    36,    36,    36,    28,    36,    36,    36,    28,
      36,    28,    36,    28,    36,    36,    28,    28,    36,    28,
      36,    28,    36,    36,    28,    -1,    36,    28,    36,    26,
      36,    36,    26,    36,    26,    26,    36,    36,    36,    -1,
      36,    36,    -1,    36,    -1,    -1,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    26,    26,
      26,    26,    26,    26,    26,    26,    36,    36,    28,    26,
      26,    26,    26,    26,    26,    26,    26,    36,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26
  };

  const unsigned char
  BisonDictionaryTextParser::yystos_[] =
  {
       0,     3,    64,    65,    26,    27,    30,   101,     0,     4,
       5,    33,    66,    67,    26,    26,    26,    27,    97,    35,
      24,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    68,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    26,    27,    30,    69,
      70,    81,    82,   100,    33,    66,    26,    26,    26,    26,
      38,    30,    30,    59,    93,    30,    93,    30,    93,    30,
      93,    30,    93,    30,    93,    30,    93,    30,    93,    30,
      93,    30,    93,    30,    93,    30,    93,    30,    93,    30,
      93,    30,    93,    30,    57,    93,    30,    57,    93,    26,
      26,    33,    93,    34,    69,    34,    81,    35,    69,    81,
      26,    26,    26,    26,    97,    97,    36,    60,    30,    59,
      36,    30,    36,    30,    36,    30,    36,    30,    36,    30,
      36,    30,    36,    30,    36,    30,    36,    30,    36,    30,
      36,    30,    36,    30,    36,    30,    36,    30,    36,    24,
      30,    84,    68,    30,    26,    26,    83,    33,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    30,    34,    34,    26,    26,
      26,   104,   104,    38,    36,    60,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      58,    36,    33,    58,    87,    26,    26,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    30,    89,    90,    91,    92,    86,    30,
      93,    30,    93,    30,    93,    30,    93,    30,    93,    30,
      93,    30,    93,    30,    93,    30,    93,    30,    93,    30,
      93,    30,    93,    30,    93,    30,    93,    30,    93,    30,
      57,    93,    30,    57,    93,    33,    93,    26,    26,    26,
      97,    30,    93,    30,    94,    95,    30,    93,    33,    26,
      26,    30,    93,    30,    93,    30,    93,    30,    93,    30,
      93,    30,    93,    30,    93,    30,    93,    30,    93,    30,
      93,    30,    93,    30,    93,    30,    93,    30,    93,    30,
      93,    30,    57,    93,    30,    33,    93,    34,    89,    89,
      89,    89,    36,    30,    36,    30,    36,    30,    36,    30,
      36,    30,    36,    30,    36,    30,    36,    30,    36,    30,
      36,    30,    36,    30,    36,    30,    36,    30,    36,    30,
      36,    30,    36,    24,    30,    72,    68,    30,    71,    33,
      26,    26,    36,    30,    37,    34,    61,    85,    30,    94,
      26,    26,    36,    37,    30,    36,    37,    30,    36,    37,
      30,    36,    37,    30,    36,    37,    30,    36,    37,    30,
      36,    37,    30,    36,    37,    30,    36,    37,    30,    36,
      37,    30,    36,    37,    30,    36,    37,    30,    36,    37,
      30,    36,    37,    30,    36,    37,    30,    36,    37,    24,
      30,    36,    37,    30,    33,    36,    34,    34,    34,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    58,    36,    33,    58,    75,    77,
      78,    79,    80,   100,    74,    26,    26,    36,    26,    27,
     102,    36,    94,    33,    88,    34,    26,    26,    25,    28,
      36,    37,    26,    27,    28,    96,    36,    37,    28,    97,
      36,    37,    26,    27,    28,    98,    36,    37,    26,    27,
      28,    99,    36,    37,    28,   100,    36,    37,    28,   101,
      36,    37,    28,   102,    36,    37,    26,    27,    28,   103,
      36,    37,    28,    36,    37,    28,    36,    37,    26,    27,
      28,    38,    62,   105,   106,   107,    36,    37,    28,   105,
      36,    37,    28,   102,    36,    37,    28,   103,    36,    37,
      28,    29,    58,    36,    37,    28,    36,    37,    36,    37,
      36,    37,    36,    30,    93,    94,    30,    93,    33,    34,
      77,    77,    77,    35,    77,    26,    26,    26,    26,    94,
      33,    36,    26,    26,    36,    36,    28,    26,    26,    36,
      36,    28,    36,    36,    28,    26,    26,    36,    36,    28,
      26,    26,    36,    36,    28,    36,    36,    28,    36,    36,
      28,    36,    36,    28,    26,    26,    36,    36,    28,    36,
      28,    36,    28,    36,    26,   108,    38,    36,    26,    38,
      26,    38,    28,    36,    36,    28,    36,    36,    28,    36,
      36,    28,    36,    36,    30,    93,    28,    36,    28,    28,
      28,    36,    30,    34,    73,    30,    94,    36,    34,    34,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    30,    34,    26,    26,
      26,    26,    34,    94,    26,    26,    36,    26,    26,    36,
      36,    26,    26,    36,    26,    26,    36,    36,    36,    36,
      26,    26,    36,    36,    36,    26,    51,    52,   109,   108,
     108,   108,    36,    36,    36,    36,    36,    37,    30,    36,
      36,    36,    36,    36,    36,    33,    76,    34,    36,    37,
      36,    37,    30,    93,    30,    93,    30,    93,    30,    93,
      30,    93,    30,    93,    30,    93,    30,    93,    30,    93,
      30,    93,    30,    93,    30,    93,    30,    93,    30,    93,
      30,    93,    30,    57,    93,    30,    33,    93,    36,   104,
     104,    26,    26,    36,    34,    26,    26,   104,   104,    26,
      26,    26,    26,    26,    26,    26,    26,   109,   109,   109,
      28,    29,    36,    37,    94,    33,    36,    28,    28,    36,
      37,    30,    36,    37,    30,    36,    37,    30,    36,    37,
      30,    36,    37,    30,    36,    37,    30,    36,    37,    30,
      36,    37,    30,    36,    37,    30,    36,    37,    30,    36,
      37,    30,    36,    37,    30,    36,    37,    30,    36,    37,
      30,    36,    37,    30,    36,    37,    24,    30,    36,    37,
      30,    33,    26,    26,    36,   104,   104,    26,    26,    26,
      26,    26,    26,    26,    26,    36,    36,    28,    34,    94,
      36,    36,    25,    28,    36,    37,    28,    96,    36,    37,
      28,    97,    36,    37,    28,    98,    36,    37,    28,    99,
      36,    37,    28,   100,    36,    37,    28,   101,    36,    37,
      28,   102,    36,    37,    28,   103,    36,    37,    28,    36,
      37,    28,    36,    37,    28,   105,    36,    37,    28,   105,
      36,    37,    28,   102,    36,    37,    28,   103,    36,    37,
      28,    29,    58,    36,    37,    28,    36,    37,    26,    26,
     104,   104,   104,   104,    26,    26,    36,    36,    34,    36,
      36,    28,    36,    36,    28,    36,    36,    28,    36,    36,
      28,    36,    36,    28,    36,    36,    28,    36,    36,    28,
      36,    36,    28,    36,    36,    28,    36,    28,    36,    28,
      36,    36,    28,    36,    36,    28,    36,    36,    28,    36,
      36,    28,    36,    36,    30,    93,    28,    36,    28,    26,
      26,    26,    26,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      37,    30,    36,    36,    26,    26,    26,    26,    28,    29,
      36,    37,    26,    26,    26,    26,    36,    36,    28,    26,
      26,    26,    26,    36,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
     104,   104,    26,    26,   104,   104
  };

  const unsigned char
  BisonDictionaryTextParser::yyr1_[] =
  {
       0,    63,    64,    64,    64,    64,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      70,    72,    70,    73,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    74,    70,    75,    70,    76,    70,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    82,    84,    82,    85,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    86,    82,    87,    82,    88,
      82,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   109,   109,
     109,   109
  };

  const unsigned char
  BisonDictionaryTextParser::yyr2_[] =
  {
       0,     2,     4,     5,     4,     5,     7,     5,     2,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     8,     0,
       8,     0,     9,     0,    12,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     9,     0,     9,     0,    10,     0,    13,     1,     2,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     8,     5,     4,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     9,     4,     6,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,    10,     7,     6,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       8,     8,     8,    11,     6,     8,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
      10,     4,     5,     1,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     6,     0,     6,     0,     7,     0,    10,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     7,     0,     7,     0,     8,     0,
      11,     1,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     6,
       3,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     7,     4,
       4,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     8,     5,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     9,     6,     6,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     8,     2,     3,     2,     3,     1,     3,
       1,     3,     1,     1,     2,     2,     3,     3,     4,     4,
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
  "$end", "error", "$undefined", "USDS", "ENCODE", "ENUMERATOR",
  "\"BOOLEAN\"", "\"BYTE\"", "\"UBYTE\"", "\"SHORT\"", "\"USHORT\"",
  "\"INT\"", "\"UINT\"", "\"LONG\"", "\"ULONG\"", "\"INT128\"",
  "\"UINT128\"", "\"FLOAT\"", "\"DOUBLE\"", "\"VARINT\"", "\"UVARINT\"",
  "\"STRING\"", "\"ENUM\"", "\"USDS type\"", "\"<Text encode>\"",
  "\"true or false\"", "\"Digit\"", "\"-Digit\"", "\"NULL\"",
  "\"Text string\"", "\"Object name\"", "USDS_RESTRICT", "\"notRoot\"",
  "'{'", "'}'", "':'", "';'", "'='", "'.'", "\"int8_t\"", "\"uint8_t\"",
  "\"int16_t\"", "\"uint16_t\"", "\"int32_t\"", "\"uint32_t\"",
  "\"int64_t\"", "\"uint64_t\"", "\"Float value\"",
  "\"Positive major float value\"", "\"Negative major float value\"",
  "\"Minor float value\"", "\"Positive float exponent digit\"",
  "\"Negative float exponent digit\"", "\"Float exponent\"",
  "\"Array declaration\"", "\"Array of struct declaration\"",
  "\"Array of struct declaration (auto id)\"", "'<'", "'>'", "'['", "']'",
  "','", "'-'", "$accept", "dictionary", "head", "dict_attributes",
  "dict_attribute", "USDS_TYPE", "tags", "tag", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "fields", "field", "struct_begin", "array_of_struct_begin",
  "tags_auto_id", "tag_auto_id", "$@7", "$@8", "$@9", "$@10", "$@11",
  "$@12", "fields_auto_id", "field_auto_id", "struct_begin_auto_id",
  "array_of_struct_begin_auto_id", "array_dimension", "enumerators",
  "enumerator", "INT8_T", "UINT8_T", "INT16_T", "UINT16_T", "INT32_T",
  "UINT32_T", "INT64_T", "UINT64_T", "digits", "FLOAT_VALUE",
  "positive_major_float_digits", "negative_major_float_digits",
  "minor_float_digits", "float_exponent", YY_NULL
  };

#if DICTIONARY_TEXTDEBUG
  const unsigned short int
  BisonDictionaryTextParser::yyrline_[] =
  {
       0,   144,   144,   148,   152,   156,   163,   167,   171,   177,
     177,   180,   184,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     213,   213,   215,   219,   223,   227,   231,   235,   239,   243,
     247,   251,   255,   259,   263,   267,   271,   275,   279,   285,
     284,   293,   292,   298,   297,   305,   315,   325,   335,   345,
     355,   365,   375,   385,   395,   405,   415,   425,   435,   445,
     455,   465,   477,   476,   489,   488,   500,   499,   516,   516,
     519,   523,   527,   531,   535,   539,   543,   547,   551,   555,
     559,   563,   567,   571,   575,   579,   583,   588,   593,   599,
     608,   617,   626,   635,   644,   653,   662,   671,   680,   689,
     698,   707,   716,   725,   734,   743,   753,   760,   773,   778,
     783,   788,   793,   798,   803,   808,   813,   818,   823,   828,
     833,   838,   843,   848,   853,   859,   865,   872,   882,   892,
     902,   912,   922,   932,   942,   952,   962,   972,   982,   992,
    1002,  1012,  1022,  1032,  1043,  1052,  1065,  1070,  1075,  1080,
    1085,  1090,  1095,  1100,  1105,  1110,  1115,  1120,  1125,  1130,
    1135,  1144,  1151,  1166,  1166,  1169,  1173,  1177,  1181,  1185,
    1189,  1193,  1197,  1201,  1205,  1209,  1213,  1217,  1221,  1225,
    1229,  1233,  1239,  1238,  1247,  1246,  1252,  1251,  1259,  1269,
    1279,  1289,  1299,  1309,  1319,  1329,  1339,  1349,  1359,  1369,
    1379,  1389,  1399,  1409,  1419,  1431,  1430,  1443,  1442,  1454,
    1453,  1470,  1470,  1473,  1477,  1481,  1485,  1489,  1493,  1497,
    1501,  1505,  1509,  1513,  1517,  1521,  1525,  1529,  1533,  1537,
    1542,  1547,  1553,  1562,  1571,  1580,  1589,  1598,  1607,  1616,
    1625,  1634,  1643,  1652,  1661,  1670,  1679,  1688,  1697,  1707,
    1714,  1727,  1732,  1737,  1742,  1747,  1752,  1757,  1762,  1767,
    1772,  1777,  1782,  1787,  1792,  1797,  1802,  1807,  1813,  1819,
    1826,  1836,  1846,  1856,  1866,  1876,  1886,  1896,  1906,  1916,
    1926,  1936,  1946,  1956,  1966,  1976,  1986,  1997,  2006,  2019,
    2024,  2029,  2034,  2039,  2044,  2049,  2054,  2059,  2064,  2069,
    2074,  2079,  2084,  2089,  2098,  2105,  2121,  2125,  2134,  2134,
    2137,  2142,  2153,  2157,  2161,  2165,  2169,  2182,  2195,  2199,
    2206,  2210,  2214,  2218,  2222,  2235,  2239,  2243,  2253,  2257,
    2261,  2267,  2273,  2280,  2287,  2295,  2303,  2319,  2335,  2339,
    2346,  2350,  2354,  2360,  2364,  2371,  2375,  2383,  2387,  2403,
    2407,  2411,  2421,  2425,  2429,  2435,  2441,  2448,  2455,  2463,
    2471,  2480,  2489,  2499,  2509,  2520,  2531,  2543,  2555,  2568,
    2581,  2602,  2623,  2627,  2634,  2638,  2642,  2648,  2652,  2659,
    2663,  2671,  2675,  2684,  2688,  2698,  2702,  2713,  2717,  2729,
    2733,  2746,  2750,  2771,  2775,  2779,  2789,  2793,  2797,  2803,
    2809,  2816,  2823,  2831,  2839,  2848,  2857,  2867,  2877,  2888,
    2899,  2911,  2923,  2936,  2949,  2963,  2977,  2993,  3009,  3026,
    3043,  3061,  3079,  3098,  3117,  3137,  3157,  3178,  3199,  3221,
    3243,  3266,  3289,  3318,  3347,  3353,  3362,  3366,  3370,  3376,
    3380,  3387,  3391,  3399,  3403,  3412,  3416,  3426,  3430,  3441,
    3445,  3457,  3461,  3474,  3478,  3492,  3496,  3512,  3518,  3535,
    3541,  3559,  3565,  3584,  3590,  3610,  3616,  3637,  3643,  3665,
    3671,  3694,  3700,  3724,  3730,  3764,  3770,  3776,  3784,  3784,
    3791,  3795,  3799,  3803,  3807,  3811,  3815,  3819,  3823,  3827,
    3834,  3838,  3845,  3849,  3856,  3861,  3869,  3873,  3877,  3881,
    3885,  3889
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
       2,     2,     2,     2,    61,    62,    38,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    36,
      57,    37,    58,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56
    };
    const unsigned int user_token_number_max_ = 305;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 37 "bisonDictionaryTextParser.y" // lalr1.cc:1156
} // usds
#line 7312 "bisonDictionaryTextParser.cc" // lalr1.cc:1156
#line 3896 "bisonDictionaryTextParser.y" // lalr1.cc:1157

//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

