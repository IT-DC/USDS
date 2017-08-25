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
#line 307 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 317 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 327 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 337 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 347 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 357 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 367 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 377 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 387 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 397 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 407 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 417 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 427 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 437 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 447 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 457 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 467 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 478 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 73:
#line 489 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
	
	}
#line 1226 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 76:
#line 501 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1234 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 77:
#line 505 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1242 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 78:
#line 509 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1250 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 79:
#line 513 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1258 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 80:
#line 517 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1266 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 81:
#line 521 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1274 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 82:
#line 525 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1282 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 83:
#line 529 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1290 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 84:
#line 533 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1298 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 85:
#line 537 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1306 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 86:
#line 541 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1314 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 87:
#line 545 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1322 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 88:
#line 549 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1330 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 89:
#line 553 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1338 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 90:
#line 557 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1346 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 91:
#line 561 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1354 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 92:
#line 565 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField((yystack_[5].value.typeVal), (yystack_[7].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)field)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 1363 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 93:
#line 570 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
	}
#line 1372 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 94:
#line 575 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = tag->getParent();
	}
#line 1380 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 95:
#line 581 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1393 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 96:
#line 590 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1406 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 97:
#line 599 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1419 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 98:
#line 608 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1432 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 99:
#line 617 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1445 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 100:
#line 626 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1458 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 101:
#line 635 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1471 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 102:
#line 644 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1484 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 103:
#line 653 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1497 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 104:
#line 662 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1510 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 105:
#line 671 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1523 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 106:
#line 680 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1536 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 107:
#line 689 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1549 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 108:
#line 698 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1562 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 109:
#line 707 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1575 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 110:
#line 716 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1588 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 111:
#line 725 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[8].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryString* element = (DictionaryString*)arr_field->setElementType((yystack_[6].value.typeVal));	
		element->setDefaultEncode((yystack_[4].value.encodeVal));
	}
#line 1602 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 112:
#line 735 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i <= (yystack_[3].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
	}
#line 1613 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 113:
#line 742 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryTagLink* element = (DictionaryTagLink*)arr_field->setElementType(usds::USDS_TAG);
		element->setTag(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
	}
#line 1627 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 114:
#line 755 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1636 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 115:
#line 760 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1645 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 116:
#line 765 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1654 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 117:
#line 770 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1663 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 118:
#line 775 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1672 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 119:
#line 780 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1681 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 120:
#line 785 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1690 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 121:
#line 790 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1699 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 122:
#line 795 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1708 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 123:
#line 800 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1717 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 124:
#line 805 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1726 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 125:
#line 810 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1735 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 126:
#line 815 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1744 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 127:
#line 820 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1753 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 128:
#line 825 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1762 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 129:
#line 830 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1771 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 130:
#line 835 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), (yystack_[9].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryString*)dict_field)->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setNullable(true);
	}
#line 1781 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 131:
#line 841 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[4].value.stringVal)[0], (yystack_[4].value.stringVal)[1]);
		field->setNullable(true);
	}
#line 1791 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 132:
#line 847 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 1800 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 133:
#line 854 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1814 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 134:
#line 864 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1828 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 135:
#line 874 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1842 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 136:
#line 884 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1856 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 137:
#line 894 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1870 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 138:
#line 904 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1884 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 139:
#line 914 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1898 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 140:
#line 924 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1912 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 141:
#line 934 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1926 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 142:
#line 944 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1940 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 143:
#line 954 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1954 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 144:
#line 964 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1968 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 145:
#line 974 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1982 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 146:
#line 984 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1996 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 147:
#line 994 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2010 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 148:
#line 1004 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2024 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 149:
#line 1014 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2039 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 150:
#line 1025 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i < (yystack_[5].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 2052 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 151:
#line 1034 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2067 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 152:
#line 1047 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBoolean* dict_field = (usds::DictionaryBoolean*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.boolVal));
	}
#line 2076 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 153:
#line 1052 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryByte* dict_field = (usds::DictionaryByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int8Val));
	}
#line 2085 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 154:
#line 1057 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUByte* dict_field = (usds::DictionaryUByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt8Val));
	}
#line 2094 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 155:
#line 1062 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryShort* dict_field = (usds::DictionaryShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int16Val));
	}
#line 2103 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 156:
#line 1067 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUShort* dict_field = (usds::DictionaryUShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt16Val));
	}
#line 2112 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 157:
#line 1072 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryInt* dict_field = (usds::DictionaryInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int32Val));
	}
#line 2121 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 158:
#line 1077 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUInt* dict_field = (usds::DictionaryUInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt32Val));
	}
#line 2130 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 159:
#line 1082 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryLong* dict_field = (usds::DictionaryLong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 2139 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 160:
#line 1087 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryULong* dict_field = (usds::DictionaryULong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 2148 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 161:
#line 1092 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryFloat* dict_field = (usds::DictionaryFloat*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((float)(yystack_[1].value.doubleVal));
	}
#line 2157 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 162:
#line 1097 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryDouble* dict_field = (usds::DictionaryDouble*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.doubleVal));
	}
#line 2166 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 163:
#line 1102 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 2175 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 164:
#line 1107 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 2184 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 165:
#line 1112 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2193 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 166:
#line 1117 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), (yystack_[9].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2203 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 167:
#line 1126 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, (yystack_[3].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2211 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 168:
#line 1133 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[4].value.int32Val), input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_STRUCT);
		(yylhs.value.uInt32Val) = (yystack_[1].value.uInt32Val);
	}
#line 2225 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 171:
#line 1151 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2233 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 172:
#line 1155 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2241 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 173:
#line 1159 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2249 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 174:
#line 1163 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2257 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 175:
#line 1167 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2265 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 176:
#line 1171 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2273 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 177:
#line 1175 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2281 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 178:
#line 1179 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2289 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 179:
#line 1183 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2297 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 180:
#line 1187 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2305 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 181:
#line 1191 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2313 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 182:
#line 1195 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2321 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 183:
#line 1199 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2329 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 184:
#line 1203 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2337 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 185:
#line 1207 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2345 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 186:
#line 1211 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2353 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 187:
#line 1215 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[5].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)tag)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 2362 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 188:
#line 1220 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_STRUCT, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2370 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 189:
#line 1224 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
	
	}
#line 2378 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 190:
#line 1230 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2392 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 191:
#line 1240 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2406 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 192:
#line 1250 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2420 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 193:
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
#line 2434 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 194:
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
#line 2448 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 195:
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
#line 2462 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 196:
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
#line 2476 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 197:
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
#line 2490 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 198:
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
#line 2504 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 199:
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
#line 2518 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 200:
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
#line 2532 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 201:
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
#line 2546 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 202:
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
#line 2560 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 203:
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
#line 2574 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 204:
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
#line 2588 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 205:
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
#line 2602 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 206:
#line 1390 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2617 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 207:
#line 1401 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2632 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 208:
#line 1412 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
	
	}
#line 2640 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 211:
#line 1424 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2648 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 212:
#line 1428 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2656 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 213:
#line 1432 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2664 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 214:
#line 1436 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2672 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 215:
#line 1440 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2680 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 216:
#line 1444 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2688 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 217:
#line 1448 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2696 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 218:
#line 1452 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2704 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 219:
#line 1456 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2712 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 220:
#line 1460 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2720 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 221:
#line 1464 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2728 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 222:
#line 1468 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2736 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 223:
#line 1472 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2744 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 224:
#line 1476 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2752 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 225:
#line 1480 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2760 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 226:
#line 1484 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2768 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 227:
#line 1488 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField((yystack_[5].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)field)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 2777 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 228:
#line 1493 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
	}
#line 2786 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 229:
#line 1498 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = tag->getParent();
	}
#line 2794 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 230:
#line 1504 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2807 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 231:
#line 1513 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2820 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 232:
#line 1522 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2833 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 233:
#line 1531 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2846 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 234:
#line 1540 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2859 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 235:
#line 1549 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2872 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 236:
#line 1558 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2885 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 237:
#line 1567 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2898 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 238:
#line 1576 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2911 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 239:
#line 1585 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2924 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 240:
#line 1594 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2937 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 241:
#line 1603 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2950 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 242:
#line 1612 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2963 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 243:
#line 1621 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2976 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 244:
#line 1630 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 2989 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 245:
#line 1639 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3002 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 246:
#line 1648 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryString* element = (DictionaryString*)arr_field->setElementType((yystack_[6].value.typeVal));	
		element->setDefaultEncode((yystack_[4].value.encodeVal));
	}
#line 3016 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 247:
#line 1658 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i <= (yystack_[3].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
	}
#line 3027 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 248:
#line 1665 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryTagLink* element = (DictionaryTagLink*)arr_field->setElementType(usds::USDS_TAG);
		element->setTag(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
	}
#line 3041 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 249:
#line 1678 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3050 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 250:
#line 1683 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3059 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 251:
#line 1688 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3068 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 252:
#line 1693 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3077 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 253:
#line 1698 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3086 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 254:
#line 1703 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3095 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 255:
#line 1708 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3104 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 256:
#line 1713 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3113 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 257:
#line 1718 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3122 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 258:
#line 1723 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3131 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 259:
#line 1728 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3140 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 260:
#line 1733 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3149 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 261:
#line 1738 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3158 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 262:
#line 1743 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3167 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 263:
#line 1748 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3176 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 264:
#line 1753 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3185 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 265:
#line 1758 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryString*)dict_field)->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setNullable(true);
	}
#line 3195 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 266:
#line 1764 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[4].value.stringVal)[0], (yystack_[4].value.stringVal)[1]);
		field->setNullable(true);
	}
#line 3205 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 267:
#line 1770 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 3214 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 268:
#line 1777 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3228 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 269:
#line 1787 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3242 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 270:
#line 1797 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3256 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 271:
#line 1807 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3270 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 272:
#line 1817 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3284 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 273:
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
#line 3298 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 274:
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
#line 3312 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 275:
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
#line 3326 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 276:
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
#line 3340 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 277:
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
#line 3354 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 278:
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
#line 3368 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 279:
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
#line 3382 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 280:
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
#line 3396 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 281:
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
#line 3410 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 282:
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
#line 3424 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 283:
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
#line 3438 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 284:
#line 1937 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3453 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 285:
#line 1948 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i < (yystack_[5].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 3466 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 286:
#line 1957 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3481 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 287:
#line 1970 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBoolean* dict_field = (usds::DictionaryBoolean*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.boolVal));
	}
#line 3490 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 288:
#line 1975 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryByte* dict_field = (usds::DictionaryByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int8Val));
	}
#line 3499 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 289:
#line 1980 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUByte* dict_field = (usds::DictionaryUByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt8Val));
	}
#line 3508 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 290:
#line 1985 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryShort* dict_field = (usds::DictionaryShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int16Val));
	}
#line 3517 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 291:
#line 1990 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUShort* dict_field = (usds::DictionaryUShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt16Val));
	}
#line 3526 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 292:
#line 1995 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryInt* dict_field = (usds::DictionaryInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int32Val));
	}
#line 3535 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 293:
#line 2000 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUInt* dict_field = (usds::DictionaryUInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt32Val));
	}
#line 3544 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 294:
#line 2005 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryLong* dict_field = (usds::DictionaryLong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 3553 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 295:
#line 2010 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryULong* dict_field = (usds::DictionaryULong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 3562 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 296:
#line 2015 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryFloat* dict_field = (usds::DictionaryFloat*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((float)(yystack_[1].value.doubleVal));
	}
#line 3571 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 297:
#line 2020 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryDouble* dict_field = (usds::DictionaryDouble*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.doubleVal));
	}
#line 3580 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 298:
#line 2025 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 3589 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 299:
#line 2030 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 3598 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 300:
#line 2035 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3607 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 301:
#line 2040 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3617 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 302:
#line 2049 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3625 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 303:
#line 2056 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_STRUCT);
		(yylhs.value.uInt32Val) = (yystack_[1].value.uInt32Val);
	}
#line 3639 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 304:
#line 2072 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 1;
	}
#line 3647 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 305:
#line 2076 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (yylhs.value.uInt32Val) + 1;
	}
#line 3655 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 308:
#line 2088 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryEnum*)tag)->addEnumerator(input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
	}
#line 3663 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 309:
#line 2099 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[0].value.int8Val);
	}
#line 3671 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 310:
#line 2103 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[0].value.int8Val);
	}
#line 3679 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 311:
#line 2107 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val) * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
	}
#line 3687 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 312:
#line 2111 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val) * (int8_t)10 - (int8_t)(yystack_[0].value.int8Val);
	}
#line 3695 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 313:
#line 2115 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) > (int8_t)1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";

		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)1 && (yylhs.value.int8Val) >= (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";
		
		(yylhs.value.int8Val) = (int8_t)(yystack_[2].value.int8Val) * (int8_t)100 + (yylhs.value.int8Val);
		
	}
#line 3712 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 314:
#line 2128 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) < (int8_t)-1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";

		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)-1 && (yylhs.value.int8Val) > (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";
		
		(yylhs.value.int8Val) = (int8_t)(yystack_[2].value.int8Val) * (int8_t)100 - (yylhs.value.int8Val);
		
	}
#line 3729 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 315:
#line 2141 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int8_t: too big value";
	}
#line 3737 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 316:
#line 2145 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int8_t: too big value";
	}
#line 3745 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 317:
#line 2152 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[0].value.int8Val);
	}
#line 3753 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 318:
#line 2156 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 3761 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 319:
#line 2160 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[1].value.int8Val) * (uint8_t)10 + (uint8_t)(yystack_[0].value.int8Val);
	}
#line 3769 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 320:
#line 2164 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 3777 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 321:
#line 2168 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: too big value";

		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[1].value.int8Val)  * (uint8_t)10 + (uint8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)2 && (yylhs.value.uInt8Val) >= (uint8_t)56)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: too big value";
		
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[2].value.int8Val) * (uint8_t)100 + (yylhs.value.uInt8Val);
		
	}
#line 3794 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 322:
#line 2181 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 3802 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 323:
#line 2185 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint8_t: too big value";
	}
#line 3810 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 324:
#line 2189 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint8_t: too big value";
	}
#line 3818 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 325:
#line 2199 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = (int16_t)(yystack_[0].value.int8Val);
	}
#line 3826 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 326:
#line 2203 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = (int16_t)(yystack_[0].value.int8Val);
	}
#line 3834 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 327:
#line 2207 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3844 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 328:
#line 2213 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3854 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 329:
#line 2219 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3865 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 330:
#line 2226 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 - 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3876 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 331:
#line 2233 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 + 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3888 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 332:
#line 2241 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 - 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 - 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 3900 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 333:
#line 2249 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3920 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 334:
#line 2265 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3940 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 335:
#line 2281 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int16_t: too big value";
	}
#line 3948 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 336:
#line 2285 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int16_t: too big value";
	}
#line 3956 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 337:
#line 2292 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = (uint16_t)(yystack_[0].value.int8Val);
	}
#line 3964 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 338:
#line 2296 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 3972 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 339:
#line 2300 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 3982 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 340:
#line 2306 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 3990 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 341:
#line 2310 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[2].value.int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 4001 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 342:
#line 2317 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4009 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 343:
#line 2321 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[3].value.int8Val) * (uint16_t)1000 + 
		(uint16_t)(yystack_[2].value.int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 4021 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 344:
#line 2329 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4029 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 345:
#line 2333 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4049 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 346:
#line 2349 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4057 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 347:
#line 2353 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint16_t: too big value";
	}
#line 4065 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 348:
#line 2357 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint16_t: too big value";
	}
#line 4073 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 349:
#line 2367 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = (int32_t)(yystack_[0].value.int8Val);
	}
#line 4081 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 350:
#line 2371 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = (int32_t)(yystack_[0].value.int8Val);
	}
#line 4089 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 351:
#line 2375 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4099 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 352:
#line 2381 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4109 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 353:
#line 2387 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4120 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 354:
#line 2394 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4131 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 355:
#line 2401 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4143 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 356:
#line 2409 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4155 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 357:
#line 2417 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4168 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 358:
#line 2426 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4181 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 359:
#line 2435 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4195 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 360:
#line 2445 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 - 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4209 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 361:
#line 2455 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4224 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 362:
#line 2466 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4239 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 363:
#line 2477 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4255 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 364:
#line 2489 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4271 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 365:
#line 2501 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4288 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 366:
#line 2514 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4305 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 367:
#line 2527 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4330 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 368:
#line 2548 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4355 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 369:
#line 2569 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int32_t: too big value";
	}
#line 4363 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 370:
#line 2573 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int32_t: too big value";
	}
#line 4371 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 371:
#line 2580 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (uint32_t)(yystack_[0].value.int8Val);
	}
#line 4379 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 372:
#line 2584 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4387 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 373:
#line 2588 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4397 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 374:
#line 2594 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4405 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 375:
#line 2598 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4416 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 376:
#line 2605 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4424 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 377:
#line 2609 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4436 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 378:
#line 2617 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4444 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 379:
#line 2621 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4457 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 380:
#line 2630 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4465 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 381:
#line 2634 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[5].value.int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4479 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 382:
#line 2644 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4487 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 383:
#line 2648 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4502 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 384:
#line 2659 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4510 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 385:
#line 2663 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4526 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 386:
#line 2675 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4534 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 387:
#line 2679 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4551 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 388:
#line 2692 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4559 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 389:
#line 2696 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4584 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 390:
#line 2717 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4592 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 391:
#line 2721 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint32_t: too big value";
	}
#line 4600 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 392:
#line 2725 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint32_t: negative value";
	}
#line 4608 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 393:
#line 2735 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = (int64_t)(yystack_[0].value.int8Val);
	}
#line 4616 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 394:
#line 2739 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = (int64_t)(yystack_[0].value.int8Val);
	}
#line 4624 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 395:
#line 2743 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4634 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 396:
#line 2749 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4644 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 397:
#line 2755 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4655 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 398:
#line 2762 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4666 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 399:
#line 2769 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4678 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 400:
#line 2777 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4690 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 401:
#line 2785 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4703 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 402:
#line 2794 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4716 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 403:
#line 2803 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4730 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 404:
#line 2813 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 4744 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 405:
#line 2823 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4759 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 406:
#line 2834 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4774 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 407:
#line 2845 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4790 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 408:
#line 2857 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4806 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 409:
#line 2869 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4823 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 410:
#line 2882 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4840 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 411:
#line 2895 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4858 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 412:
#line 2909 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4876 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 413:
#line 2924 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4895 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 414:
#line 2940 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4914 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 415:
#line 2956 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4934 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 416:
#line 2973 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4954 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 417:
#line 2990 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4975 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 418:
#line 3008 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4996 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 419:
#line 3026 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5018 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 420:
#line 3045 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5040 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 421:
#line 3064 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5063 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 422:
#line 3084 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5086 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 423:
#line 3104 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5110 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 424:
#line 3125 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5134 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 425:
#line 3146 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5159 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 426:
#line 3168 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5184 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 427:
#line 3190 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5210 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 428:
#line 3213 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5236 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 429:
#line 3236 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5268 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 430:
#line 3265 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5300 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 431:
#line 3294 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int64_t: too big value";
	}
#line 5309 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 432:
#line 3300 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int64_t: too big value";
	}
#line 5318 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 433:
#line 3308 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = (uint64_t)(yystack_[0].value.int8Val);
	}
#line 5326 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 434:
#line 3312 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5334 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 435:
#line 3316 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5344 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 436:
#line 3322 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5352 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 437:
#line 3326 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5363 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 438:
#line 3333 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5371 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 439:
#line 3337 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5383 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 440:
#line 3345 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5391 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 441:
#line 3349 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5404 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 442:
#line 3358 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5412 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 443:
#line 3362 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5426 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 444:
#line 3372 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5434 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 445:
#line 3376 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5449 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 446:
#line 3387 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5457 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 447:
#line 3391 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5473 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 448:
#line 3403 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5481 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 449:
#line 3407 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5498 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 450:
#line 3420 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5506 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 451:
#line 3424 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5524 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 452:
#line 3438 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5532 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 453:
#line 3443 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5551 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 454:
#line 3459 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) 
			<< (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5560 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 455:
#line 3465 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5580 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 456:
#line 3482 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) 
			<< (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5589 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 457:
#line 3488 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5610 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 458:
#line 3506 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) 
			<< (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5619 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 459:
#line 3512 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5641 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 460:
#line 3531 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) 
			<< (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5650 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 461:
#line 3537 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5673 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 462:
#line 3557 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) 
			<< (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5682 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 463:
#line 3563 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5706 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 464:
#line 3584 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) 
			<< (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5715 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 465:
#line 3590 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5740 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 466:
#line 3612 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) 
			<< (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5749 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 467:
#line 3618 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5775 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 468:
#line 3641 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) 
			<< (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5784 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 469:
#line 3647 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5811 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 470:
#line 3671 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) 
			<< (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5820 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 471:
#line 3677 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5857 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 472:
#line 3711 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) 
			<< (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5866 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 473:
#line 3717 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[20].value.int8Val) << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint64_t: too big value";
	}
#line 5875 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 474:
#line 3723 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[20].value.int8Val) << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) 
			<< (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint64_t: negative value";
	}
#line 5884 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 477:
#line 3737 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.doubleVal);
	}
#line 5892 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 478:
#line 3741 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.doubleVal);
	}
#line 5900 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 479:
#line 3745 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[2].value.doubleVal) + (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 5908 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 480:
#line 3749 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[2].value.doubleVal) - (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 5916 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 481:
#line 3753 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = - (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;	
	}
#line 5924 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 482:
#line 3757 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 5932 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 483:
#line 3761 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[3].value.doubleVal) + (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 5940 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 484:
#line 3765 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[3].value.doubleVal) - (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 5948 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 485:
#line 3769 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (- (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));	
	}
#line 5956 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 486:
#line 3773 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 5964 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 487:
#line 3780 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 5972 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 488:
#line 3784 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yylhs.value.doubleVal) * 10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 5980 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 489:
#line 3791 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 5988 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 490:
#line 3795 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yylhs.value.doubleVal) * 10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 5996 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 491:
#line 3802 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.floatDigits).value = (double)(yystack_[0].value.int8Val);
		(yylhs.value.floatDigits).digits = 10.0;
	}
#line 6005 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 492:
#line 3807 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.floatDigits).value = (yylhs.value.floatDigits).value * 10.0 + (double)(yystack_[0].value.int8Val);
		(yylhs.value.floatDigits).digits = (yylhs.value.floatDigits).digits * 10.0;
	}
#line 6014 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 493:
#line 3815 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 6022 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 494:
#line 3819 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 6030 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 495:
#line 3823 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[1].value.int8Val) * (double)10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 6038 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 496:
#line 3827 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[1].value.int8Val) * (double)10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 6046 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 497:
#line 3831 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[2].value.int8Val) * (double)100.0 + (double)(yystack_[1].value.int8Val) * (double)10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 6054 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 498:
#line 3835 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[2].value.int8Val) * (double)100.0 - (double)(yystack_[1].value.int8Val) * (double)10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 6062 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;


#line 6066 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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


  const short int BisonDictionaryTextParser::yypact_ninf_ = -601;

  const signed char BisonDictionaryTextParser::yytable_ninf_ = -1;

  const short int
  BisonDictionaryTextParser::yypact_[] =
  {
      44,   122,    36,    38,    34,   368,   406,    72,  -601,   459,
     610,   429,   394,   149,   425,   627,   666,   703,   349,   475,
    -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,
    -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,    24,
      28,    37,    40,    42,    50,    54,    55,    56,    60,    61,
      81,    82,    86,    87,    -2,   777,   778,   338,   602,   427,
     772,   479,   680,   429,  -601,   779,   781,   782,   783,   406,
     406,   774,   752,    88,   775,    91,   780,   126,   784,   127,
     785,   128,   786,   129,   787,   130,   788,   131,   789,   132,
     790,   133,   791,   135,   792,   136,   793,   137,   794,   163,
     795,   167,   796,   809,   168,   808,   810,  -601,   366,  -601,
    -601,  -601,  -601,   454,   801,   803,   812,   813,   814,   814,
    -601,   776,  -601,  -601,   805,   755,  -601,   806,  -601,   807,
    -601,   811,  -601,   815,  -601,   816,  -601,   817,  -601,   818,
    -601,   819,  -601,   820,  -601,   821,  -601,   822,  -601,   823,
    -601,   824,  -601,   825,  -601,   760,   826,   837,   838,   525,
    -601,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    16,   363,   375,  -601,
    -601,   839,   840,  -601,   841,   841,   406,  -601,  -601,  -601,
    -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,
    -601,  -601,  -601,   184,  -601,   842,   843,   185,   186,   187,
     188,   189,   190,   191,   193,   194,   195,   221,   225,   226,
     227,   228,    19,    18,   836,   525,   525,   525,   525,   835,
     229,   844,   230,   845,   231,   846,   232,   847,   233,   848,
     234,   849,   235,   850,   236,   851,   237,   852,   238,   853,
     239,   854,   240,   855,   241,   856,   242,   857,   243,   858,
     871,   244,  -601,   610,  -601,   393,   870,   872,  -601,  -601,
     861,   245,   873,   874,   421,   246,   444,   247,   486,   248,
     517,   249,   542,   251,   548,   252,   576,   253,   613,   279,
     615,   283,   618,   284,   620,   285,   622,   286,   624,   288,
     626,   289,   628,   290,   630,   877,   291,   632,  -601,    23,
     866,  -601,   869,   875,   876,  -601,   868,  -601,   878,  -601,
     879,  -601,   880,  -601,   883,  -601,   884,  -601,   885,  -601,
     886,  -601,   887,  -601,   888,  -601,   889,  -601,   890,  -601,
     891,  -601,   892,  -601,   893,  -601,   881,   894,   898,   882,
     427,  -601,   906,   907,  -601,   899,   908,   910,  -601,    69,
     634,  -601,   116,   636,  -601,   451,   638,  -601,   480,   640,
    -601,   484,   642,  -601,   487,   644,  -601,   490,   646,  -601,
     493,   648,  -601,   500,   650,  -601,   909,   652,  -601,   913,
     654,  -601,    -1,   661,  -601,     3,   663,  -601,   521,   665,
    -601,   524,   667,  -601,   361,   895,   669,  -601,   914,   671,
    -601,  -601,   673,   675,   902,  -601,  -601,  -601,  -601,  -601,
    -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,
     292,  -601,   915,   916,   917,   427,   427,   427,   912,   427,
     918,   922,  -601,   923,   924,   919,   920,  -601,   926,   931,
     932,   925,   927,  -601,   934,   928,   929,  -601,   938,   933,
     941,   935,   936,  -601,   940,   943,   944,   937,   939,  -601,
     946,   942,   945,  -601,   948,   947,   949,  -601,   951,   954,
     956,   950,   952,  -601,   959,   958,   963,   955,   957,  -601,
     962,   960,  -601,   964,   961,  -601,   966,  -601,  -601,   965,
     969,   834,   967,     6,    67,  -601,   970,   968,   971,  -601,
     972,   973,   974,  -601,   977,   975,   976,  -601,   978,   979,
     980,   293,  -601,   985,   981,  -601,   986,  -601,   990,  -601,
     991,  -601,   984,   294,  -601,   987,   756,  -601,   988,  -601,
     989,   992,   550,   993,   982,   996,   999,  1002,  -601,  -601,
     994,  1003,  1005,  -601,  -601,   997,  -601,  -601,   998,  1006,
    1009,  -601,  -601,  1000,  1011,  1012,  -601,  -601,  1004,  -601,
    -601,  1007,  -601,  -601,  1008,  1013,  1015,  -601,  -601,  1010,
    1016,  1019,  -601,  -601,  1014,  -601,  1017,  -601,  1018,  -601,
    -601,   378,   969,  -601,  -601,   969,  -601,   969,  1020,  -601,
    -601,  1021,  -601,  -601,  1022,  -601,  -601,  1023,  -601,  -601,
     677,   295,  1024,  -601,  1025,  1026,  1027,  -601,  1028,  1029,
     915,  1033,  -601,   681,   683,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   309,   310,   311,
      22,    29,  1031,   814,   814,  1042,  1043,  -601,   814,   814,
    -601,  -601,  1044,  1045,  -601,  1046,  1047,  -601,  -601,  -601,
    1048,  1049,  -601,  1050,  1051,  -601,  -601,  -601,  -601,  1052,
    1053,  -601,   378,   378,   378,  -601,  -601,  -601,  -601,  -601,
     693,   687,  -601,  -601,  -601,  -601,  -601,  -601,  -601,   915,
    -601,  1054,  -601,  1055,   689,   316,   691,   337,   694,   342,
     696,   343,   698,   344,   700,   346,   702,   347,   704,   348,
     706,   350,   708,   351,   710,   352,   712,   353,   714,   354,
     716,   355,   718,   356,   720,   953,   358,   722,  -601,    33,
    -601,   841,   841,   814,   814,   841,   841,  1058,  1059,  1060,
    1061,  1062,  1063,  1064,  1065,  1066,  1067,  -601,  -601,  -601,
    1068,  1069,  -601,  1070,  1072,  1071,  1073,  -601,   403,   724,
    -601,   546,   726,  -601,   549,   728,  -601,   555,   730,  -601,
     577,   732,  -601,   580,   734,  -601,   583,   736,  -601,   607,
     738,  -601,   611,   740,  -601,  1074,   743,  -601,  1075,   745,
    -601,     7,   747,  -601,    12,   749,  -601,   614,   751,  -601,
     617,   753,  -601,   763,  1036,   757,  -601,  1080,   759,  -601,
     841,   841,   814,   814,   814,   814,  1084,  1085,  1086,  1087,
    -601,  -601,  -601,  -601,  1078,  1079,  -601,  -601,  1081,  1082,
    -601,  1088,  1083,  1089,  -601,  1092,  1090,  1091,  -601,  1093,
    1094,  1095,  -601,  1096,  1097,  1098,  -601,  1100,  1099,  1101,
    -601,  1104,  1102,  1103,  -601,  1108,  1105,  1106,  -601,  1112,
    1107,  1109,  -601,  1116,  1110,  -601,  1119,  1113,  -601,  1120,
    1114,  1115,  -601,  1124,  1117,  1118,  -601,  1127,  1121,  1122,
    -601,  1128,  1123,  1125,  -601,  1132,  1126,  1129,   362,  -601,
    1135,  1130,  -601,  1136,   841,   841,   841,   841,  1141,  1142,
    1143,  1144,  -601,  -601,  -601,  -601,  1137,  -601,  -601,  1138,
    -601,  -601,  1139,  -601,  -601,  1140,  -601,  -601,  1145,  -601,
    -601,  1146,  -601,  -601,  1147,  -601,  -601,  1148,  -601,  -601,
    1149,  -601,  1150,  -601,  1151,  -601,  -601,  1152,  -601,  -601,
    1153,  -601,  -601,  1154,  -601,  -601,  1155,  -601,  -601,   761,
     365,  1156,  -601,  1157,  1168,  1169,  1170,  1171,  -601,  -601,
    -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,
    -601,  -601,  -601,  -601,   771,   765,  -601,  -601,  1172,  1173,
    1174,  1175,  1166,  1167,  -601,  1176,  1179,  1180,  1181,  1182,
    -601,  -601,  1177,  1183,  1184,  1185,  1186,  -601,  1188,  1189,
    1190,  1191,  1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,
    1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,
    1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,
     814,   814,  1220,  1221,   841,   841,   814,   814,   841,   841
  };

  const unsigned short int
  BisonDictionaryTextParser::yydefact_[] =
  {
       0,     0,     0,     0,   371,   372,     8,     0,     1,     0,
       0,     0,     0,     9,   373,   374,   317,   318,     0,     0,
      11,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   349,   350,     0,     0,    30,
       0,   169,     0,     0,    10,   375,   376,   319,   320,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   351,   352,   188,     0,     2,
      31,     4,   170,     0,     0,     0,   377,   378,   321,   322,
       7,     0,   171,   304,     0,     0,   172,     0,   173,     0,
     174,     0,   175,     0,   176,     0,   177,     0,   178,     0,
     179,     0,   180,     0,   181,     0,   182,     0,   183,     0,
     184,     0,   185,     0,   186,     0,     0,   353,   354,     0,
     207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       5,   379,   380,   475,   323,   324,     0,   190,   305,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,     0,   205,   355,   356,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   209,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,    49,     0,   381,   382,   476,     6,
       0,     0,   357,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,     0,
       0,   210,     0,     0,     0,    32,     0,    33,     0,    34,
       0,    35,     0,    36,     0,    37,     0,    38,     0,    39,
       0,    40,     0,    41,     0,    42,     0,    43,     0,    44,
       0,    45,     0,    46,     0,    47,     0,     0,     0,     0,
       0,    72,   383,   384,   187,     0,   359,   360,   211,     0,
       0,   212,     0,     0,   213,     0,     0,   214,     0,     0,
     215,     0,     0,   216,     0,     0,   217,     0,     0,   218,
       0,     0,   219,     0,     0,   220,     0,     0,   221,     0,
       0,   222,     0,     0,   223,     0,     0,   224,     0,     0,
     225,     0,     0,   226,     0,     0,     0,   228,     0,     0,
     303,   189,     0,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,    70,     0,     0,     0,    74,     0,     0,     0,     0,
     385,   386,   206,   361,   362,     0,     0,   230,     0,   309,
     310,     0,     0,   231,     0,     0,     0,   232,     0,   325,
     326,     0,     0,   233,     0,   337,   338,     0,     0,   234,
       0,     0,     0,   235,     0,     0,     0,   236,     0,   393,
     394,     0,     0,   237,     0,   433,   434,     0,     0,   238,
       0,     0,   239,     0,     0,   240,     0,   487,   489,     0,
       0,     0,     0,   477,   478,   241,     0,     0,     0,   242,
       0,     0,     0,   243,     0,     0,     0,   244,     0,     0,
       0,     0,   245,     0,     0,   248,     0,   229,     0,   247,
       0,   208,     0,     0,   308,     0,   306,    53,     0,    75,
       0,     0,     0,     0,   387,   388,   363,   364,   287,   249,
       0,   311,   312,   250,   288,     0,   251,   289,     0,   327,
     328,   252,   290,     0,   339,   340,   253,   291,     0,   254,
     292,     0,   255,   293,     0,   395,   396,   256,   294,     0,
     435,   436,   257,   295,     0,   258,     0,   259,     0,   260,
     491,   482,     0,   296,   488,     0,   490,     0,     0,   261,
     297,     0,   262,   298,     0,   263,   299,     0,   264,   300,
       0,     0,     0,   266,     0,     0,     0,    48,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   389,   390,   365,   366,   268,   313,   314,
     269,   270,   329,   330,   271,   341,   342,   272,   273,   274,
     397,   398,   275,   437,   438,   276,   277,   278,   492,   493,
     494,   486,   481,   479,   480,   279,   280,   281,   282,   227,
       0,     0,   283,   286,   267,   285,    71,    52,   307,     0,
      94,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,     0,
      73,   391,   392,   367,   368,   315,   316,   331,   332,   343,
     344,   399,   400,   439,   440,   495,   496,   485,   483,   484,
       0,     0,   246,     0,     0,     0,     0,    76,     0,     0,
      77,     0,     0,    78,     0,     0,    79,     0,     0,    80,
       0,     0,    81,     0,     0,    82,     0,     0,    83,     0,
       0,    84,     0,     0,    85,     0,     0,    86,     0,     0,
      87,     0,     0,    88,     0,     0,    89,     0,     0,    90,
       0,     0,    91,     0,     0,     0,    93,     0,     0,   168,
     369,   370,   333,   334,   345,   346,   401,   402,   441,   442,
     497,   498,   265,   301,     0,     0,   132,   150,     0,     0,
      95,     0,     0,     0,    96,     0,     0,     0,    97,     0,
       0,     0,    98,     0,     0,     0,    99,     0,     0,     0,
     100,     0,     0,     0,   101,     0,     0,     0,   102,     0,
       0,     0,   103,     0,     0,   104,     0,     0,   105,     0,
       0,     0,   106,     0,     0,     0,   107,     0,     0,     0,
     108,     0,     0,     0,   109,     0,     0,     0,     0,   110,
       0,     0,   113,     0,   335,   336,   347,   348,   403,   404,
     443,   444,   284,    54,   152,   114,     0,   115,   153,     0,
     116,   154,     0,   117,   155,     0,   118,   156,     0,   119,
     157,     0,   120,   158,     0,   121,   159,     0,   122,   160,
       0,   123,     0,   124,     0,   125,   161,     0,   126,   162,
       0,   127,   163,     0,   128,   164,     0,   129,   165,     0,
       0,     0,   131,     0,   405,   406,   445,   446,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    92,     0,     0,   148,   151,   407,   408,
     447,   448,     0,     0,   111,     0,   409,   410,   449,   450,
     130,   166,     0,   411,   412,   451,   452,   149,   413,   414,
     453,   454,   415,   416,   455,   456,   417,   418,   457,   458,
     419,   420,   459,   460,   421,   422,   461,   462,   423,   424,
     463,   464,   425,   426,   465,   466,   427,   428,   467,   468,
     429,   430,   469,   470,   431,   432,   471,   472,   473,   474
  };

  const short int
  BisonDictionaryTextParser::yypgoto_[] =
  {
    -601,  -601,  -601,   800,  -601,   556,    92,  -601,  -601,  -601,
    -601,  -601,  -333,  -601,  -601,  -601,    47,  -601,  -601,  -601,
     276,  -601,  -601,  -601,   -39,  -600,  -601,    83,   -48,    78,
      76,     5,  -353,  -381,  -382,  -119,  -372,  -601,  -601,  -497,
     -26
  };

  const short int
  BisonDictionaryTextParser::yydefgoto_[] =
  {
      -1,     2,     3,    12,    13,    38,    58,    59,   350,   348,
     621,   439,   434,   435,   436,   437,    60,    61,   159,   228,
     224,   225,   226,   227,    73,   535,   536,   452,    18,   462,
     468,   438,     7,   482,   488,   184,   502,   503,   504,   591,
     671
  };

  const unsigned short int
  BisonDictionaryTextParser::yytable_[] =
  {
     185,    75,    77,    79,    81,    83,    85,    87,    89,    91,
      93,    95,    97,    99,   101,   104,    62,   512,   108,   516,
     688,   120,   121,   508,   476,   497,   498,   499,   102,   497,
     498,   507,   594,   497,   498,   870,     8,   500,   497,   498,
     874,   500,     9,    10,   595,   500,   259,     1,   307,   304,
     500,   308,   724,   409,    71,   103,   410,    72,    74,   727,
      14,   501,   728,   808,    62,   501,   809,    76,    62,   501,
      78,    11,    80,   260,   501,    72,   305,    72,    72,   725,
      82,    72,   125,    72,    84,    86,    88,    72,    72,   754,
      90,    92,   125,   596,   445,   672,    72,   446,   673,    72,
     674,    72,   539,   540,   541,   597,   543,    19,   112,    72,
     115,    94,    96,    72,    72,    72,    98,   100,   124,    72,
      72,   127,   230,   232,   234,   236,   238,   240,   242,   244,
     246,   248,   250,   252,   254,   256,   258,   261,   269,   265,
      72,    72,   449,   450,   451,    72,    72,   125,     4,     5,
     125,   110,     6,     9,    10,   114,   129,   131,   133,   135,
     137,   139,   141,   143,   271,   145,   147,   149,   275,   277,
     279,   281,   283,   285,   287,   289,   291,   293,   295,   297,
     299,   301,   303,   306,   309,   125,   125,   125,   125,   125,
     125,   125,   125,   151,   125,   125,   125,   153,   156,   229,
     231,   233,   235,   237,   239,   241,   243,   245,   247,   249,
     251,   253,   255,   257,   270,   274,   276,   278,   280,   282,
     284,   286,   125,   288,   290,   292,   125,   125,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,   294,    72,    72,    72,   296,   298,   300,   302,   316,
     318,   320,   322,   324,   326,   328,   330,   332,   334,   336,
     338,   340,   342,   344,   347,   355,   360,   363,   366,   369,
      72,   372,   375,   378,    72,    72,    72,    72,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   381,
     125,   125,   125,   384,   387,   390,   393,   456,   396,   399,
     402,   406,   532,   610,   618,   681,   694,   696,   698,   700,
     702,   704,   706,   708,   710,   712,   714,   716,   125,   718,
     720,   722,   125,   125,   125,   125,   759,   125,   125,   125,
     125,    72,    72,   125,   125,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,   762,    72,    72,
      72,   107,   765,   768,   771,   125,   774,   777,   780,   472,
     783,   786,   789,   792,   795,   798,   801,    69,   805,   519,
     520,   533,   949,   262,    15,   975,   125,    72,   857,   160,
     861,   125,   125,   125,   668,   125,   125,   125,   264,   125,
     125,   125,   125,   125,   125,   125,   879,   125,   883,   871,
     263,    72,   875,   853,   125,   125,   351,    63,   828,   669,
     670,   829,    16,    17,    72,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    65,   125,    55,    56,    55,    56,   358,   359,    57,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    16,    17,   455,
     361,   362,   611,    20,   178,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,   311,   312,   313,   314,    70,   459,   460,   461,    57,
     465,   466,   467,    55,    56,   471,     4,     5,   475,   479,
     480,   481,   364,   365,   731,   732,   485,   486,   487,   735,
     736,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   479,   480,   511,
     485,   486,   515,   367,   368,   223,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   449,   450,   832,    16,    17,   836,   370,   371,
     641,   459,   460,   840,   373,   374,   695,   697,   699,   701,
     703,   705,   707,   709,   711,   713,   715,   717,   719,   721,
     723,   726,   729,   465,   466,   844,    55,    56,   848,     4,
       5,   852,   376,   377,   810,   811,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,   479,   480,   856,   109,   485,   486,   860,
     479,   480,   878,   485,   486,   882,   747,   748,   749,   379,
     380,   382,   383,    66,   385,   386,   388,   389,   391,   392,
     394,   395,   397,   398,   400,   401,   403,   404,   407,   408,
     447,   448,   453,   454,   457,   458,   463,   464,   469,   470,
     473,   474,   477,   478,   483,   484,   489,   490,   492,   493,
     495,   496,    67,   894,   895,   896,   897,   505,   506,   509,
     510,   513,   514,   517,   518,   522,   523,   525,   526,   527,
     528,   529,   530,   679,   680,   113,   837,   690,   691,   692,
     693,   750,   751,   752,   753,   757,   758,   760,   761,    68,
     763,   764,   766,   767,   769,   770,   772,   773,   775,   776,
     778,   779,   781,   782,   784,   785,   787,   788,   790,   791,
     793,   794,   796,   797,   799,   800,   802,   803,   806,   807,
     830,   831,   834,   835,   838,   839,   842,   843,   846,   847,
     850,   851,   854,   855,   858,   859,   862,   863,   849,   865,
     866,   868,   869,   872,   873,   876,   877,   880,   881,   884,
     885,   886,   887,   889,   890,   892,   893,   973,   974,   982,
     983,   984,   985,   105,   106,   116,   111,   117,   118,   119,
     122,   126,   123,    64,   186,   188,   128,   620,   203,   349,
     130,   132,   134,   136,   138,   140,   142,   144,   146,   148,
     150,   152,   154,   155,   157,   179,   158,   180,   181,   182,
     183,   187,   189,   190,   833,   841,   845,   191,     0,   950,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   204,   205,   206,   266,   267,   268,   272,   273,
     310,   315,   592,     0,     0,     0,     0,     0,     0,     0,
     317,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   339,   341,   343,   345,   346,   352,   354,   353,   356,
     357,   405,   411,   412,   415,     0,     0,     0,     0,   413,
     414,  1034,  1035,     0,   416,   417,   418,  1038,  1039,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     431,   432,   440,   441,   443,   442,   444,   491,   531,   430,
     433,   494,   524,     0,   544,   534,   537,   542,   545,   546,
     547,   538,     0,   521,   550,   548,   549,   551,   552,   559,
       0,   553,   555,   554,   556,   557,   558,   560,   563,   564,
     565,   561,   562,   566,   568,   567,   571,   804,   569,   574,
     575,   570,   576,   572,   580,   573,   577,   579,   578,   581,
     584,   582,   586,   583,   588,   590,   585,   587,   598,     0,
     601,   589,     0,   593,   599,   604,   607,   600,   643,   602,
     603,   605,   606,   612,   614,   608,   609,   613,   615,   616,
     617,   619,   644,   623,   622,   645,   624,   642,   646,   648,
     647,   649,   652,   650,   651,   653,   654,   655,   656,   660,
     657,   661,   663,   658,   659,   664,   662,     0,     0,     0,
     665,     0,     0,   666,   667,     0,   675,   676,   677,   678,
     682,   683,   684,   685,   686,   687,   689,   730,   733,   734,
     737,   738,   739,   740,   741,   742,   743,   744,   745,   746,
       0,     0,   755,   756,   812,   813,   814,   815,   816,   817,
     818,   819,   820,   821,   888,     0,     0,     0,   824,     0,
       0,     0,   864,   867,   822,   823,   825,   826,   891,   827,
     898,   899,   900,   901,   902,   903,   906,   904,   905,   907,
     909,   912,     0,     0,   915,   908,   910,   911,   918,     0,
     913,   914,   921,   916,   917,   919,   924,   920,   922,   923,
     927,   925,   926,   928,   930,   929,   931,   932,   934,   933,
     935,   936,   937,   938,   939,   940,   943,   941,   942,   944,
     946,   945,   947,   951,   953,   948,   952,   954,   955,   956,
     957,     0,     0,   958,   959,   960,   961,     0,     0,     0,
       0,   962,   963,   964,   965,   966,   967,   968,   969,   970,
     971,   972,   976,   977,   978,   979,   980,   981,   986,   987,
     988,   989,   990,   991,   992,   993,   994,   995,   996,   998,
     999,  1000,  1001,   997,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1036,  1037
  };

  const short int
  BisonDictionaryTextParser::yycheck_[] =
  {
     119,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    11,   398,    57,   401,
     620,    69,    70,   395,   377,    26,    27,    28,    30,    26,
      27,    28,    26,    26,    27,    28,     0,    38,    26,    27,
      28,    38,     4,     5,    38,    38,    30,     3,    30,    30,
      38,    33,    30,    30,    30,    57,    33,    59,    30,    30,
      26,    62,    33,    30,    59,    62,    33,    30,    63,    62,
      30,    33,    30,    57,    62,    59,    57,    59,    59,    57,
      30,    59,    59,    59,    30,    30,    30,    59,    59,   689,
      30,    30,    59,    26,    25,   592,    59,    28,   595,    59,
     597,    59,   435,   436,   437,    38,   439,    35,    61,    59,
      63,    30,    30,    59,    59,    59,    30,    30,    30,    59,
      59,    30,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   186,   178,
      59,    59,    26,    27,    28,    59,    59,    59,    26,    27,
      59,    59,    30,     4,     5,    63,    30,    30,    30,    30,
      30,    30,    30,    30,   203,    30,    30,    30,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    59,    59,    59,    59,    59,
      59,    59,    59,    30,    59,    59,    59,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    59,    30,    30,    30,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    30,    59,    59,    59,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      59,    30,    30,    30,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    30,
      59,    59,    59,    30,    30,    30,    30,   365,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    59,    30,
      30,    30,    59,    59,    59,    59,    30,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    30,    59,    59,
      59,    33,    30,    30,    30,    59,    30,    30,    30,   374,
      30,    30,    30,    30,    30,    30,    30,    38,    30,    28,
      29,   430,    30,    30,    26,    30,    59,    59,   779,    33,
     782,    59,    59,    59,    26,    59,    59,    59,    33,    59,
      59,    59,    59,    59,    59,    59,   797,    59,   800,   791,
      57,    59,   794,   776,    59,    59,    33,    33,    25,    51,
      52,    28,    26,    27,    59,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    26,    59,    26,    27,    26,    27,    36,    37,    30,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    26,    27,    28,
      36,    37,   521,    24,    30,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   225,   226,   227,   228,    30,    26,    27,    28,    30,
      26,    27,    28,    26,    27,    28,    26,    27,    28,    26,
      27,    28,    36,    37,   643,   644,    26,    27,    28,   648,
     649,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    26,    27,    28,
      26,    27,    28,    36,    37,    30,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    26,    27,    28,    26,    27,    28,    36,    37,
      30,    26,    27,    28,    36,    37,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,    26,    27,    28,    26,    27,    28,    26,
      27,    28,    36,    37,   733,   734,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    26,    27,    28,    34,    26,    27,    28,
      26,    27,    28,    26,    27,    28,   672,   673,   674,    36,
      37,    36,    37,    26,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    26,   812,   813,   814,   815,    36,    37,    36,
      37,    36,    37,    36,    37,    36,    37,    36,    37,    36,
      37,    36,    37,    36,    37,    35,   764,    36,    37,    36,
      37,    28,    29,    36,    37,    36,    37,    36,    37,    26,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,   773,    36,
      37,    36,    37,    36,    37,    36,    37,    36,    37,    36,
      37,    28,    29,    36,    37,    36,    37,    36,    37,    28,
      29,    36,    37,    26,    26,    26,    34,    26,    26,    26,
      36,    36,    60,    13,    38,    60,    36,    61,    58,   263,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    24,    26,    34,    26,    34,    26,    26,
      26,    36,    36,    36,   761,   767,   770,    36,    -1,   888,
      -1,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    26,    26,    26,    26,    26,    26,    26,
      34,    36,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    24,    26,    36,    26,    26,
      26,    24,    36,    34,    36,    -1,    -1,    -1,    -1,    34,
      34,  1030,  1031,    -1,    36,    36,    36,  1036,  1037,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    33,    26,    26,    26,    36,    26,    28,    36,    58,
      58,    28,    28,    -1,    26,    30,    30,    35,    26,    26,
      26,    34,    -1,    58,    28,    36,    36,    26,    26,    26,
      -1,    36,    28,    36,    36,    36,    28,    26,    28,    26,
      26,    36,    36,    36,    28,    36,    28,    24,    36,    28,
      26,    36,    26,    36,    26,    36,    36,    28,    36,    26,
      28,    36,    28,    36,    28,    26,    36,    36,    28,    -1,
      28,    36,    -1,    36,    36,    28,    28,    36,    26,    36,
      36,    36,    36,    28,    28,    36,    36,    36,    28,    28,
      36,    34,    26,    34,    36,    26,    34,    34,    26,    26,
      36,    26,    26,    36,    36,    26,    36,    26,    26,    26,
      36,    26,    26,    36,    36,    26,    36,    -1,    -1,    -1,
      36,    -1,    -1,    36,    36,    -1,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    33,    36,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      -1,    -1,    28,    28,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    58,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    28,    28,    36,    36,    34,    36,    28,    36,
      26,    26,    26,    26,    36,    36,    28,    36,    36,    36,
      28,    28,    -1,    -1,    28,    36,    36,    36,    28,    -1,
      36,    36,    28,    36,    36,    36,    28,    36,    36,    36,
      28,    36,    36,    36,    28,    36,    36,    28,    28,    36,
      36,    36,    28,    36,    36,    28,    28,    36,    36,    36,
      28,    36,    36,    28,    28,    36,    36,    26,    26,    26,
      26,    -1,    -1,    36,    36,    36,    36,    -1,    -1,    -1,
      -1,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    26,    26,    26,    26,    26,    26,
      26,    26,    36,    36,    28,    26,    26,    26,    26,    26,
      26,    26,    26,    36,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26
  };

  const unsigned char
  BisonDictionaryTextParser::yystos_[] =
  {
       0,     3,    64,    65,    26,    27,    30,    95,     0,     4,
       5,    33,    66,    67,    26,    26,    26,    27,    91,    35,
      24,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    68,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    26,    27,    30,    69,    70,
      79,    80,    94,    33,    66,    26,    26,    26,    26,    38,
      30,    30,    59,    87,    30,    87,    30,    87,    30,    87,
      30,    87,    30,    87,    30,    87,    30,    87,    30,    87,
      30,    87,    30,    87,    30,    87,    30,    87,    30,    87,
      30,    87,    30,    57,    87,    26,    26,    33,    87,    34,
      69,    34,    79,    35,    69,    79,    26,    26,    26,    26,
      91,    91,    36,    60,    30,    59,    36,    30,    36,    30,
      36,    30,    36,    30,    36,    30,    36,    30,    36,    30,
      36,    30,    36,    30,    36,    30,    36,    30,    36,    30,
      36,    30,    36,    30,    36,    24,    30,    26,    26,    81,
      33,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    30,    34,
      34,    26,    26,    26,    98,    98,    38,    36,    60,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    58,    36,    26,    26,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    30,    83,    84,    85,    86,    82,    30,
      87,    30,    87,    30,    87,    30,    87,    30,    87,    30,
      87,    30,    87,    30,    87,    30,    87,    30,    87,    30,
      87,    30,    87,    30,    87,    30,    87,    30,    87,    30,
      57,    87,    30,    57,    33,    87,    26,    26,    26,    91,
      30,    87,    26,    26,    30,    87,    30,    87,    30,    87,
      30,    87,    30,    87,    30,    87,    30,    87,    30,    87,
      30,    87,    30,    87,    30,    87,    30,    87,    30,    87,
      30,    87,    30,    87,    30,    57,    87,    30,    33,    87,
      34,    83,    83,    83,    83,    36,    30,    36,    30,    36,
      30,    36,    30,    36,    30,    36,    30,    36,    30,    36,
      30,    36,    30,    36,    30,    36,    30,    36,    30,    36,
      30,    36,    30,    36,    30,    36,    24,    30,    72,    68,
      71,    33,    26,    26,    36,    30,    26,    26,    36,    37,
      30,    36,    37,    30,    36,    37,    30,    36,    37,    30,
      36,    37,    30,    36,    37,    30,    36,    37,    30,    36,
      37,    30,    36,    37,    30,    36,    37,    30,    36,    37,
      30,    36,    37,    30,    36,    37,    30,    36,    37,    30,
      36,    37,    30,    36,    37,    24,    30,    36,    37,    30,
      33,    36,    34,    34,    34,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      58,    36,    33,    58,    75,    76,    77,    78,    94,    74,
      26,    26,    36,    26,    26,    25,    28,    36,    37,    26,
      27,    28,    90,    36,    37,    28,    91,    36,    37,    26,
      27,    28,    92,    36,    37,    26,    27,    28,    93,    36,
      37,    28,    94,    36,    37,    28,    95,    36,    37,    26,
      27,    28,    96,    36,    37,    26,    27,    28,    97,    36,
      37,    28,    36,    37,    28,    36,    37,    26,    27,    28,
      38,    62,    99,   100,   101,    36,    37,    28,    99,    36,
      37,    28,    96,    36,    37,    28,    97,    36,    37,    28,
      29,    58,    36,    37,    28,    36,    37,    36,    37,    36,
      37,    36,    30,    87,    30,    88,    89,    30,    34,    75,
      75,    75,    35,    75,    26,    26,    26,    26,    36,    36,
      28,    26,    26,    36,    36,    28,    36,    36,    28,    26,
      26,    36,    36,    28,    26,    26,    36,    36,    28,    36,
      36,    28,    36,    36,    28,    26,    26,    36,    36,    28,
      26,    26,    36,    36,    28,    36,    28,    36,    28,    36,
      26,   102,    38,    36,    26,    38,    26,    38,    28,    36,
      36,    28,    36,    36,    28,    36,    36,    28,    36,    36,
      30,    87,    28,    36,    28,    28,    28,    36,    30,    34,
      61,    73,    36,    34,    34,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    30,    34,    26,    26,    26,    26,    36,    26,    26,
      36,    36,    26,    26,    36,    26,    26,    36,    36,    36,
      26,    26,    36,    26,    26,    36,    36,    36,    26,    51,
      52,   103,   102,   102,   102,    36,    36,    36,    36,    36,
      37,    30,    36,    36,    36,    36,    36,    36,    88,    33,
      36,    37,    36,    37,    30,    87,    30,    87,    30,    87,
      30,    87,    30,    87,    30,    87,    30,    87,    30,    87,
      30,    87,    30,    87,    30,    87,    30,    87,    30,    87,
      30,    87,    30,    87,    30,    57,    87,    30,    33,    87,
      36,    98,    98,    26,    26,    98,    98,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,   103,   103,   103,
      28,    29,    36,    37,    88,    28,    28,    36,    37,    30,
      36,    37,    30,    36,    37,    30,    36,    37,    30,    36,
      37,    30,    36,    37,    30,    36,    37,    30,    36,    37,
      30,    36,    37,    30,    36,    37,    30,    36,    37,    30,
      36,    37,    30,    36,    37,    30,    36,    37,    30,    36,
      37,    30,    36,    37,    24,    30,    36,    37,    30,    33,
      98,    98,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    36,    36,    28,    34,    36,    36,    25,    28,
      36,    37,    28,    90,    36,    37,    28,    91,    36,    37,
      28,    92,    36,    37,    28,    93,    36,    37,    28,    94,
      36,    37,    28,    95,    36,    37,    28,    96,    36,    37,
      28,    97,    36,    37,    28,    36,    37,    28,    36,    37,
      28,    99,    36,    37,    28,    99,    36,    37,    28,    96,
      36,    37,    28,    97,    36,    37,    28,    29,    58,    36,
      37,    28,    36,    37,    98,    98,    98,    98,    26,    26,
      26,    26,    36,    36,    36,    36,    28,    36,    36,    28,
      36,    36,    28,    36,    36,    28,    36,    36,    28,    36,
      36,    28,    36,    36,    28,    36,    36,    28,    36,    36,
      28,    36,    28,    36,    28,    36,    36,    28,    36,    36,
      28,    36,    36,    28,    36,    36,    28,    36,    36,    30,
      87,    28,    36,    28,    26,    26,    26,    26,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    37,    30,    36,    36,    26,    26,
      26,    26,    28,    29,    36,    37,    26,    26,    26,    26,
      36,    36,    28,    26,    26,    26,    26,    36,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    98,    98,    26,    26,    98,    98
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
      70,    70,    74,    70,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    82,    80,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    86,    87,    87,    88,    88,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,   100,   100,   101,
     101,   102,   102,   103,   103,   103,   103,   103,   103
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
       6,     9,     0,     9,     1,     2,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     8,     5,     4,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     9,     4,     6,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
      10,     7,     6,     8,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,    11,
       6,     8,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,    10,     4,     5,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     6,     0,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     7,     0,     7,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     6,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     7,     4,     4,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     8,     5,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     9,     6,     6,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     8,     2,     3,     2,     3,     1,     3,     1,     1,
       1,     2,     2,     3,     3,     4,     4,     1,     1,     2,
       2,     3,     3,     4,     4,     1,     1,     2,     2,     3,
       3,     4,     4,     5,     5,     6,     6,     1,     1,     2,
       2,     3,     3,     4,     4,     5,     5,     6,     6,     1,
       1,     2,     2,     3,     3,     4,     4,     5,     5,     6,
       6,     7,     7,     8,     8,     9,     9,    10,    10,    11,
      11,     1,     1,     2,     2,     3,     3,     4,     4,     5,
       5,     6,     6,     7,     7,     8,     8,     9,     9,    10,
      10,    11,    11,     1,     1,     2,     2,     3,     3,     4,
       4,     5,     5,     6,     6,     7,     7,     8,     8,     9,
       9,    10,    10,    11,    11,    12,    12,    13,    13,    14,
      14,    15,    15,    16,    16,    17,    17,    18,    18,    19,
      19,    20,    20,     1,     1,     2,     2,     3,     3,     4,
       4,     5,     5,     6,     6,     7,     7,     8,     8,     9,
       9,    10,    10,    11,    11,    12,    12,    13,    13,    14,
      14,    15,    15,    16,    16,    17,    17,    18,    18,    19,
      19,    20,    20,    21,    21,     1,     2,     1,     1,     3,
       3,     3,     2,     4,     4,     4,     3,     1,     2,     1,
       2,     1,     2,     1,     1,     2,     2,     3,     3
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
  "fields", "field", "struct_begin", "array_of_struct_begin",
  "tags_auto_id", "tag_auto_id", "$@5", "$@6", "fields_auto_id",
  "field_auto_id", "struct_begin_auto_id", "array_of_struct_begin_auto_id",
  "array_dimension", "enumerators", "enumerator", "INT8_T", "UINT8_T",
  "INT16_T", "UINT16_T", "INT32_T", "UINT32_T", "INT64_T", "UINT64_T",
  "digits", "FLOAT_VALUE", "positive_major_float_digits",
  "negative_major_float_digits", "minor_float_digits", "float_exponent", YY_NULL
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
     284,   293,   292,   298,   297,   306,   316,   326,   336,   346,
     356,   366,   376,   386,   396,   406,   416,   426,   436,   446,
     456,   466,   478,   477,   497,   497,   500,   504,   508,   512,
     516,   520,   524,   528,   532,   536,   540,   544,   548,   552,
     556,   560,   564,   569,   574,   580,   589,   598,   607,   616,
     625,   634,   643,   652,   661,   670,   679,   688,   697,   706,
     715,   724,   734,   741,   754,   759,   764,   769,   774,   779,
     784,   789,   794,   799,   804,   809,   814,   819,   824,   829,
     834,   840,   846,   853,   863,   873,   883,   893,   903,   913,
     923,   933,   943,   953,   963,   973,   983,   993,  1003,  1013,
    1024,  1033,  1046,  1051,  1056,  1061,  1066,  1071,  1076,  1081,
    1086,  1091,  1096,  1101,  1106,  1111,  1116,  1125,  1132,  1147,
    1147,  1150,  1154,  1158,  1162,  1166,  1170,  1174,  1178,  1182,
    1186,  1190,  1194,  1198,  1202,  1206,  1210,  1214,  1220,  1219,
    1229,  1239,  1249,  1259,  1269,  1279,  1289,  1299,  1309,  1319,
    1329,  1339,  1349,  1359,  1369,  1379,  1389,  1401,  1400,  1420,
    1420,  1423,  1427,  1431,  1435,  1439,  1443,  1447,  1451,  1455,
    1459,  1463,  1467,  1471,  1475,  1479,  1483,  1487,  1492,  1497,
    1503,  1512,  1521,  1530,  1539,  1548,  1557,  1566,  1575,  1584,
    1593,  1602,  1611,  1620,  1629,  1638,  1647,  1657,  1664,  1677,
    1682,  1687,  1692,  1697,  1702,  1707,  1712,  1717,  1722,  1727,
    1732,  1737,  1742,  1747,  1752,  1757,  1763,  1769,  1776,  1786,
    1796,  1806,  1816,  1826,  1836,  1846,  1856,  1866,  1876,  1886,
    1896,  1906,  1916,  1926,  1936,  1947,  1956,  1969,  1974,  1979,
    1984,  1989,  1994,  1999,  2004,  2009,  2014,  2019,  2024,  2029,
    2034,  2039,  2048,  2055,  2071,  2075,  2084,  2084,  2087,  2098,
    2102,  2106,  2110,  2114,  2127,  2140,  2144,  2151,  2155,  2159,
    2163,  2167,  2180,  2184,  2188,  2198,  2202,  2206,  2212,  2218,
    2225,  2232,  2240,  2248,  2264,  2280,  2284,  2291,  2295,  2299,
    2305,  2309,  2316,  2320,  2328,  2332,  2348,  2352,  2356,  2366,
    2370,  2374,  2380,  2386,  2393,  2400,  2408,  2416,  2425,  2434,
    2444,  2454,  2465,  2476,  2488,  2500,  2513,  2526,  2547,  2568,
    2572,  2579,  2583,  2587,  2593,  2597,  2604,  2608,  2616,  2620,
    2629,  2633,  2643,  2647,  2658,  2662,  2674,  2678,  2691,  2695,
    2716,  2720,  2724,  2734,  2738,  2742,  2748,  2754,  2761,  2768,
    2776,  2784,  2793,  2802,  2812,  2822,  2833,  2844,  2856,  2868,
    2881,  2894,  2908,  2922,  2938,  2954,  2971,  2988,  3006,  3024,
    3043,  3062,  3082,  3102,  3123,  3144,  3166,  3188,  3211,  3234,
    3263,  3292,  3298,  3307,  3311,  3315,  3321,  3325,  3332,  3336,
    3344,  3348,  3357,  3361,  3371,  3375,  3386,  3390,  3402,  3406,
    3419,  3423,  3437,  3441,  3457,  3463,  3480,  3486,  3504,  3510,
    3529,  3535,  3555,  3561,  3582,  3588,  3610,  3616,  3639,  3645,
    3669,  3675,  3709,  3715,  3721,  3729,  3729,  3736,  3740,  3744,
    3748,  3752,  3756,  3760,  3764,  3768,  3772,  3779,  3783,  3790,
    3794,  3801,  3806,  3814,  3818,  3822,  3826,  3830,  3834
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
#line 7213 "bisonDictionaryTextParser.cc" // lalr1.cc:1156
#line 3841 "bisonDictionaryTextParser.y" // lalr1.cc:1157

//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

