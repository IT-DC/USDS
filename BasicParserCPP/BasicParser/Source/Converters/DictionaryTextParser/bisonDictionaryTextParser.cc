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
	#include "dictionary\dataTypes\dictionaryPolymorph.h"
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
#line 140 "bisonDictionaryTextParser.y" // lalr1.cc:406

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
#line 150 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->finalizeDictionary();
	}
#line 628 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 3:
#line 154 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->finalizeDictionary();
	}
#line 636 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 4:
#line 158 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->finalizeDictionary();
	}
#line 644 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 5:
#line 162 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->finalizeDictionary();
	}
#line 652 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 6:
#line 169 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setID(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1], (yystack_[5].value.uInt32Val), (yystack_[2].value.uInt8Val), (yystack_[0].value.uInt8Val));
	}
#line 660 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 7:
#line 173 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setID(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1], 0, (yystack_[2].value.uInt8Val), (yystack_[0].value.uInt8Val));
	}
#line 668 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 8:
#line 177 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setID(input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1], 0, 0, 0);
	}
#line 676 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 11:
#line 186 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setDefaultStringEncode((yystack_[0].value.encodeVal));
	}
#line 684 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 12:
#line 190 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setDefaultEnumSubtype((yystack_[0].value.typeVal), false);
	}
#line 692 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 13:
#line 196 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 698 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 14:
#line 197 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 704 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 15:
#line 198 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 710 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 16:
#line 199 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 716 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 17:
#line 200 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 722 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 18:
#line 201 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 728 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 19:
#line 202 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 734 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 20:
#line 203 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 740 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 21:
#line 204 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 746 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 22:
#line 205 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 752 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 23:
#line 206 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 758 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 24:
#line 207 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 764 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 25:
#line 208 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 770 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 26:
#line 209 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 776 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 27:
#line 210 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 782 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 28:
#line 211 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 788 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 29:
#line 212 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {(yylhs.value.typeVal) = (yystack_[0].value.typeVal);}
#line 794 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 32:
#line 221 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 802 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 33:
#line 225 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 810 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 34:
#line 229 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 818 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 35:
#line 233 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 826 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 36:
#line 237 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 834 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 37:
#line 241 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 842 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 38:
#line 245 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 850 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 39:
#line 249 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 858 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 40:
#line 253 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 866 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 41:
#line 257 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 874 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 42:
#line 261 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 882 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 43:
#line 265 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 890 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 44:
#line 269 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 898 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 45:
#line 273 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 906 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 46:
#line 277 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 914 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 47:
#line 281 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 922 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 48:
#line 285 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[5].value.typeVal), (yystack_[7].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)tag)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 931 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 49:
#line 290 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_STRUCT, (yystack_[3].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 939 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 50:
#line 294 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
	
	}
#line 947 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 51:
#line 298 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_ENUM, (yystack_[3].value.int32Val), input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
	}
#line 955 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 53:
#line 303 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_ENUM, (yystack_[6].value.int32Val), input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		((DictionaryEnum*)tag)->setSubtype((yystack_[2].value.typeVal), false);
	}
#line 964 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 55:
#line 309 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_POLYMORPH, (yystack_[6].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryPolymorph*)tag)->setTags((yystack_[3].value.tagLink));
	}
#line 973 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 987 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1001 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1015 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1029 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1043 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1057 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1071 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1085 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1099 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1113 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1127 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1141 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1155 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1169 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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
#line 1183 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 71:
#line 466 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 1197 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 72:
#line 476 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 1212 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 73:
#line 487 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 1227 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 75:
#line 499 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[4].value.int32Val), input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			tag = ((usds::DictionaryArray*)tag)->setElementType(usds::USDS_ARRAY);
		}
		// for enumerators
		tag = ((usds::DictionaryArray*)tag)->setElementType(USDS_ENUM);
	}
#line 1241 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 77:
#line 510 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 1256 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 79:
#line 522 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			tag = ((usds::DictionaryArray*)tag)->setElementType(usds::USDS_ARRAY);
		}
		((DictionaryPolymorph*)((usds::DictionaryArray*)tag)->setElementType(usds::USDS_POLYMORPH))->setTags((yystack_[4].value.tagLink));
	}
#line 1269 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 82:
#line 539 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1277 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 83:
#line 543 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1285 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 84:
#line 547 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1293 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 85:
#line 551 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1301 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 86:
#line 555 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1309 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 87:
#line 559 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1317 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 88:
#line 563 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1325 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 89:
#line 567 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1333 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 90:
#line 571 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1341 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 91:
#line 575 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1349 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 92:
#line 579 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1357 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 93:
#line 583 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1365 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 94:
#line 587 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1373 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 95:
#line 591 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1381 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 96:
#line 595 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1389 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 97:
#line 599 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 1397 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 98:
#line 603 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField((yystack_[5].value.typeVal), (yystack_[7].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)field)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 1406 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 99:
#line 608 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[4].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
	}
#line 1415 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 100:
#line 613 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = tag->getParent();
	}
#line 1423 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 101:
#line 617 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = tag->getParent();
	}
#line 1431 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 102:
#line 621 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_POLYMORPH, (yystack_[6].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryPolymorph*)field)->setTags((yystack_[3].value.tagLink));
	}
#line 1440 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 103:
#line 628 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 104:
#line 637 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 105:
#line 646 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 106:
#line 655 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 107:
#line 664 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 108:
#line 673 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 109:
#line 682 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 110:
#line 691 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 111:
#line 700 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 112:
#line 709 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 113:
#line 718 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 114:
#line 727 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 115:
#line 736 "bisonDictionaryTextParser.y" // lalr1.cc:846
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

  case 116:
#line 745 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1622 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 117:
#line 754 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1635 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 118:
#line 763 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 1648 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 119:
#line 772 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[8].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryString* element = (DictionaryString*)arr_field->setElementType((yystack_[6].value.typeVal));	
		element->setDefaultEncode((yystack_[4].value.encodeVal));
	}
#line 1662 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 120:
#line 782 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i <= (yystack_[3].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
	}
#line 1673 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 121:
#line 789 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[5].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryTagLink* element = (DictionaryTagLink*)arr_field->setElementType(usds::USDS_TAG);
		element->setTag(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
	}
#line 1687 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 122:
#line 799 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i <= (yystack_[1].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
	}
#line 1698 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 123:
#line 806 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			field = ((usds::DictionaryArray*)field)->setElementType(usds::USDS_ARRAY);
		}
		((DictionaryPolymorph*)((usds::DictionaryArray*)field)->setElementType(usds::USDS_POLYMORPH))->setTags((yystack_[4].value.tagLink));
	}
#line 1711 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 124:
#line 817 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1720 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 125:
#line 822 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1729 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 126:
#line 827 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1738 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 127:
#line 832 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1747 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 128:
#line 837 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1756 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 129:
#line 842 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1765 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 130:
#line 847 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1774 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 131:
#line 852 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1783 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 132:
#line 857 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1792 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 133:
#line 862 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1801 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 134:
#line 867 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1810 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 135:
#line 872 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1819 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 136:
#line 877 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1828 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 137:
#line 882 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1837 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 138:
#line 887 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1846 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 139:
#line 892 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 1855 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 140:
#line 897 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), (yystack_[9].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryString*)dict_field)->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setNullable(true);
	}
#line 1865 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 141:
#line 903 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[4].value.stringVal)[0], (yystack_[4].value.stringVal)[1]);
		field->setNullable(true);
	}
#line 1875 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 142:
#line 909 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 1884 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 143:
#line 914 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 1893 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 144:
#line 919 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_POLYMORPH, (yystack_[8].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryPolymorph*)field)->setTags((yystack_[5].value.tagLink));
		field->setNullable(true);
	}
#line 1903 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 145:
#line 927 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1917 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 146:
#line 937 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1931 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 147:
#line 947 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1945 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 148:
#line 957 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1959 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 149:
#line 967 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1973 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 150:
#line 977 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 1987 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 151:
#line 987 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2001 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 152:
#line 997 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2015 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 153:
#line 1007 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2029 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 154:
#line 1017 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2043 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 155:
#line 1027 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2057 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 156:
#line 1037 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2071 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 157:
#line 1047 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2085 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 158:
#line 1057 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2099 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 159:
#line 1067 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2113 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 160:
#line 1077 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 2127 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 161:
#line 1087 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2142 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 162:
#line 1098 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i < (yystack_[5].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 2155 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 163:
#line 1107 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2170 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 164:
#line 1118 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i < (yystack_[3].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 2183 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 165:
#line 1127 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[9].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			field = ((usds::DictionaryArray*)field)->setElementType(usds::USDS_ARRAY);
		}
		((DictionaryPolymorph*)((usds::DictionaryArray*)field)->setElementType(usds::USDS_POLYMORPH))->setTags((yystack_[6].value.tagLink));
	}
#line 2197 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 166:
#line 1139 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBoolean* dict_field = (usds::DictionaryBoolean*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.boolVal));
	}
#line 2206 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 167:
#line 1144 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryByte* dict_field = (usds::DictionaryByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int8Val));
	}
#line 2215 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 168:
#line 1149 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUByte* dict_field = (usds::DictionaryUByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt8Val));
	}
#line 2224 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 169:
#line 1154 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryShort* dict_field = (usds::DictionaryShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int16Val));
	}
#line 2233 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 170:
#line 1159 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUShort* dict_field = (usds::DictionaryUShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt16Val));
	}
#line 2242 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 171:
#line 1164 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryInt* dict_field = (usds::DictionaryInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int32Val));
	}
#line 2251 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 172:
#line 1169 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUInt* dict_field = (usds::DictionaryUInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt32Val));
	}
#line 2260 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 173:
#line 1174 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryLong* dict_field = (usds::DictionaryLong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 2269 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 174:
#line 1179 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryULong* dict_field = (usds::DictionaryULong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 2278 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 175:
#line 1184 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryFloat* dict_field = (usds::DictionaryFloat*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((float)(yystack_[1].value.doubleVal));
	}
#line 2287 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 176:
#line 1189 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryDouble* dict_field = (usds::DictionaryDouble*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.doubleVal));
	}
#line 2296 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 177:
#line 1194 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 2305 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 178:
#line 1199 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 2314 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 179:
#line 1204 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2323 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 180:
#line 1209 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), (yystack_[9].value.int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2333 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 181:
#line 1215 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((usds::DictionaryEnum*)tag)->setDefaultValue((yystack_[1].value.int64Val));
		tag = tag->getParent();
	}
#line 2342 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 182:
#line 1220 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((usds::DictionaryEnum*)tag)->setDefaultFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		tag = tag->getParent();
	}
#line 2351 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 183:
#line 1228 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, (yystack_[3].value.int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2359 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 184:
#line 1235 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[4].value.int32Val), input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_STRUCT);
		(yylhs.value.uInt32Val) = (yystack_[1].value.uInt32Val);
	}
#line 2373 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 185:
#line 1248 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_ENUM, (yystack_[3].value.int32Val), input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
	}
#line 2381 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 187:
#line 1253 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_ENUM, (yystack_[6].value.int32Val), input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		((DictionaryEnum*)tag)->setSubtype((yystack_[2].value.typeVal), false);
	}
#line 2390 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 189:
#line 1262 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[4].value.int32Val), input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_ENUM);
	}
#line 2403 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 190:
#line 1271 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (yystack_[5].value.uInt32Val);
	}
#line 2411 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 191:
#line 1275 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, (yystack_[7].value.int32Val), input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_ENUM);
		((DictionaryEnum*)tag)->setSubtype((yystack_[3].value.typeVal), false);
	}
#line 2425 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 192:
#line 1285 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (yystack_[5].value.uInt32Val);
	}
#line 2433 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 193:
#line 1292 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.tagLink) = (usds::DictionaryTagLink*)dict->addField(USDS_TAG, 0, 1, "subTag", 6);
		(yylhs.value.tagLink)->setTag(input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
	}
#line 2442 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 194:
#line 1297 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.tagLink) = (usds::DictionaryTagLink*)dict->addField(USDS_TAG, 0, 1, "subTag", 6);
		(yylhs.value.tagLink)->setTag(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		(yylhs.value.tagLink)->setNext((yystack_[0].value.tagLink));
	}
#line 2452 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 197:
#line 1311 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2460 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 198:
#line 1315 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2468 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 199:
#line 1319 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2476 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 200:
#line 1323 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2484 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 201:
#line 1327 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2492 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 202:
#line 1331 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2500 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 203:
#line 1335 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2508 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 204:
#line 1339 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2516 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 205:
#line 1343 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2524 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 206:
#line 1347 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2532 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 207:
#line 1351 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2540 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 208:
#line 1355 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2548 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 209:
#line 1359 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2556 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 210:
#line 1363 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2564 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 211:
#line 1367 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2572 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 212:
#line 1371 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2580 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 213:
#line 1375 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[5].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)tag)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 2589 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 214:
#line 1380 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_STRUCT, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2597 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 215:
#line 1384 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
	
	}
#line 2605 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 216:
#line 1388 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_ENUM, input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
	}
#line 2613 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 218:
#line 1393 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_ENUM, input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		((DictionaryEnum*)tag)->setSubtype((yystack_[2].value.typeVal), false);
	}
#line 2622 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 220:
#line 1399 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_POLYMORPH, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryPolymorph*)tag)->setTags((yystack_[3].value.tagLink));
	}
#line 2631 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 221:
#line 1406 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2645 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 222:
#line 1416 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2659 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 223:
#line 1426 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2673 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 224:
#line 1436 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2687 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 225:
#line 1446 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2701 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 226:
#line 1456 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2715 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 227:
#line 1466 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2729 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 228:
#line 1476 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2743 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 229:
#line 1486 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2757 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 230:
#line 1496 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2771 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 231:
#line 1506 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2785 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 232:
#line 1516 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2799 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 233:
#line 1526 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2813 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 234:
#line 1536 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2827 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 235:
#line 1546 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2841 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 236:
#line 1556 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		usds::DictionaryArray* arr_tag = (usds::DictionaryArray*)tag;
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_tag = (usds::DictionaryArray*)arr_tag->setElementType(usds::USDS_ARRAY);
		}
		arr_tag->setElementType((yystack_[3].value.typeVal));
	}
#line 2855 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 237:
#line 1566 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2870 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 238:
#line 1577 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2885 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 240:
#line 1589 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			tag = ((usds::DictionaryArray*)tag)->setElementType(usds::USDS_ARRAY);
		}
		// for enumerators
		tag = ((usds::DictionaryArray*)tag)->setElementType(USDS_ENUM);
	}
#line 2899 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 242:
#line 1600 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 2914 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 244:
#line 1612 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			tag = ((usds::DictionaryArray*)tag)->setElementType(usds::USDS_ARRAY);
		}
		((DictionaryPolymorph*)((usds::DictionaryArray*)tag)->setElementType(usds::USDS_POLYMORPH))->setTags((yystack_[4].value.tagLink));
	}
#line 2927 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 247:
#line 1630 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2935 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 248:
#line 1634 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2943 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 249:
#line 1638 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2951 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 250:
#line 1642 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2959 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 251:
#line 1646 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2967 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 252:
#line 1650 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2975 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 253:
#line 1654 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2983 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 254:
#line 1658 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2991 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 255:
#line 1662 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 2999 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 256:
#line 1666 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3007 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 257:
#line 1670 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3015 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 258:
#line 1674 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3023 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 259:
#line 1678 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3031 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 260:
#line 1682 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3039 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 261:
#line 1686 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3047 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 262:
#line 1690 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3055 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 263:
#line 1694 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField((yystack_[5].value.typeVal), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)field)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 3064 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 264:
#line 1699 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
	}
#line 3073 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 265:
#line 1704 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = tag->getParent();
	}
#line 3081 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 266:
#line 1708 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = tag->getParent();
	}
#line 3089 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 267:
#line 1712 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_POLYMORPH, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryPolymorph*)field)->setTags((yystack_[3].value.tagLink));
	}
#line 3098 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 268:
#line 1719 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3111 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 269:
#line 1728 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3124 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 270:
#line 1737 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3137 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 271:
#line 1746 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3150 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 272:
#line 1755 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3163 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 273:
#line 1764 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3176 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 274:
#line 1773 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3189 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 275:
#line 1782 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3202 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 276:
#line 1791 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3215 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 277:
#line 1800 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3228 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 278:
#line 1809 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3241 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 279:
#line 1818 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3254 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 280:
#line 1827 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3267 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 281:
#line 1836 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3280 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 282:
#line 1845 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3293 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 283:
#line 1854 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[3].value.typeVal));
	}
#line 3306 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 284:
#line 1863 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryString* element = (DictionaryString*)arr_field->setElementType((yystack_[6].value.typeVal));	
		element->setDefaultEncode((yystack_[4].value.encodeVal));
	}
#line 3320 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 285:
#line 1873 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i <= (yystack_[3].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
	}
#line 3331 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 286:
#line 1880 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		DictionaryTagLink* element = (DictionaryTagLink*)arr_field->setElementType(usds::USDS_TAG);
		element->setTag(input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
	}
#line 3345 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 287:
#line 1890 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i <= (yystack_[1].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
	}
#line 3356 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 288:
#line 1897 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[2].value.uInt32Val); i++)
		{
			field = ((usds::DictionaryArray*)field)->setElementType(usds::USDS_ARRAY);
		}
		((DictionaryPolymorph*)((usds::DictionaryArray*)field)->setElementType(usds::USDS_POLYMORPH))->setTags((yystack_[4].value.tagLink));
	}
#line 3369 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 289:
#line 1908 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3378 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 290:
#line 1913 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3387 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 291:
#line 1918 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3396 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 292:
#line 1923 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3405 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 293:
#line 1928 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3414 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 294:
#line 1933 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3423 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 295:
#line 1938 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3432 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 296:
#line 1943 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3441 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 297:
#line 1948 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3450 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 298:
#line 1953 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3459 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 299:
#line 1958 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3468 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 300:
#line 1963 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3477 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 301:
#line 1968 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3486 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 302:
#line 1973 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3495 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 303:
#line 1978 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3504 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 304:
#line 1983 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 3513 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 305:
#line 1988 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryString*)dict_field)->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setNullable(true);
	}
#line 3523 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 306:
#line 1994 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[4].value.stringVal)[0], (yystack_[4].value.stringVal)[1]);
		field->setNullable(true);
	}
#line 3533 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 307:
#line 2000 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 3542 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 308:
#line 2005 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 3551 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 309:
#line 2010 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_POLYMORPH, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryPolymorph*)field)->setTags((yystack_[5].value.tagLink));
		field->setNullable(true);
	}
#line 3561 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 310:
#line 2018 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3575 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 311:
#line 2028 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3589 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 312:
#line 2038 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3603 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 313:
#line 2048 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3617 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 314:
#line 2058 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3631 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 315:
#line 2068 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3645 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 316:
#line 2078 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3659 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 317:
#line 2088 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3673 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 318:
#line 2098 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3687 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 319:
#line 2108 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3701 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 320:
#line 2118 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3715 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 321:
#line 2128 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3729 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 322:
#line 2138 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3743 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 323:
#line 2148 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3757 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 324:
#line 2158 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3771 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 325:
#line 2168 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		arr_field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		arr_field->setElementType((yystack_[5].value.typeVal));
	}
#line 3785 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 326:
#line 2178 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3800 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 327:
#line 2189 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i < (yystack_[5].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 3813 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 328:
#line 2198 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 3828 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 329:
#line 2209 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		for (uint32_t i = 0; i < (yystack_[3].value.uInt32Val); i++)
		{
			tag = tag->getParent();
		}
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 3841 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 330:
#line 2218 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		field->setNullable(true);
		for (uint32_t i = 1; i < (yystack_[4].value.uInt32Val); i++)
		{
			field = ((usds::DictionaryArray*)field)->setElementType(usds::USDS_ARRAY);
		}
		((DictionaryPolymorph*)((usds::DictionaryArray*)field)->setElementType(usds::USDS_POLYMORPH))->setTags((yystack_[6].value.tagLink));
	}
#line 3855 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 331:
#line 2231 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBoolean* dict_field = (usds::DictionaryBoolean*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.boolVal));
	}
#line 3864 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 332:
#line 2236 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryByte* dict_field = (usds::DictionaryByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int8Val));
	}
#line 3873 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 333:
#line 2241 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUByte* dict_field = (usds::DictionaryUByte*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt8Val));
	}
#line 3882 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 334:
#line 2246 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryShort* dict_field = (usds::DictionaryShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int16Val));
	}
#line 3891 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 335:
#line 2251 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUShort* dict_field = (usds::DictionaryUShort*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt16Val));
	}
#line 3900 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 336:
#line 2256 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryInt* dict_field = (usds::DictionaryInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int32Val));
	}
#line 3909 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 337:
#line 2261 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryUInt* dict_field = (usds::DictionaryUInt*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt32Val));
	}
#line 3918 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 338:
#line 2266 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryLong* dict_field = (usds::DictionaryLong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 3927 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 339:
#line 2271 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryULong* dict_field = (usds::DictionaryULong*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 3936 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 340:
#line 2276 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryFloat* dict_field = (usds::DictionaryFloat*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((float)(yystack_[1].value.doubleVal));
	}
#line 3945 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 341:
#line 2281 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryDouble* dict_field = (usds::DictionaryDouble*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.doubleVal));
	}
#line 3954 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 342:
#line 2286 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.int64Val));
	}
#line 3963 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 343:
#line 2291 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryVarint* dict_field = (usds::DictionaryVarint*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValue((yystack_[1].value.uInt64Val));
	}
#line 3972 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 344:
#line 2296 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3981 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 345:
#line 2301 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryString* dict_field = (usds::DictionaryString*)(((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]));
		dict_field->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setDefaultValueFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 3991 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 346:
#line 2307 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((usds::DictionaryEnum*)tag)->setDefaultValue((yystack_[1].value.int64Val));
		tag = tag->getParent();
	}
#line 4000 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 347:
#line 2312 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((usds::DictionaryEnum*)tag)->setDefaultFromUTF8(input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		tag = tag->getParent();
	}
#line 4009 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 348:
#line 2320 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 4017 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 349:
#line 2327 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_STRUCT);
		(yylhs.value.uInt32Val) = (yystack_[1].value.uInt32Val);
	}
#line 4031 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 350:
#line 2340 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_ENUM, input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
	}
#line 4039 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 352:
#line 2345 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_ENUM, input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		((DictionaryEnum*)tag)->setSubtype((yystack_[2].value.typeVal), false);
	}
#line 4048 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 354:
#line 2354 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_ENUM);
	}
#line 4061 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 355:
#line 2363 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (yystack_[5].value.uInt32Val);
	}
#line 4069 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 356:
#line 2367 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryArray* arr_field = (usds::DictionaryArray*)((DictionaryStruct*)tag)->addField(usds::USDS_ARRAY, input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
		for (uint32_t i = 1; i < (yystack_[1].value.uInt32Val); i++)
		{
			arr_field = (usds::DictionaryArray*)arr_field->setElementType(usds::USDS_ARRAY);
		}
		tag = arr_field->setElementType(usds::USDS_ENUM);
		((DictionaryEnum*)tag)->setSubtype((yystack_[3].value.typeVal), false);
	}
#line 4083 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 357:
#line 2377 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (yystack_[5].value.uInt32Val);
	}
#line 4091 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 358:
#line 2387 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 1;
	}
#line 4099 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 359:
#line 2391 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (yylhs.value.uInt32Val) + 1;
	}
#line 4107 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 362:
#line 2403 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryEnum*)tag)->addEnumerator(input_text + (yystack_[0].value.stringVal)[0], (yystack_[0].value.stringVal)[1]);
	}
#line 4115 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 363:
#line 2408 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryEnum*)tag)->addEnumerator((yystack_[0].value.int64Val), input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
	}
#line 4123 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 364:
#line 2419 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[0].value.int8Val);
	}
#line 4131 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 365:
#line 2423 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[0].value.int8Val);
	}
#line 4139 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 366:
#line 2427 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val) * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
	}
#line 4147 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 367:
#line 2431 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val) * (int8_t)10 - (int8_t)(yystack_[0].value.int8Val);
	}
#line 4155 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 368:
#line 2435 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) > (int8_t)1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";

		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)1 && (yylhs.value.int8Val) >= (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";
		
		(yylhs.value.int8Val) = (int8_t)(yystack_[2].value.int8Val) * (int8_t)100 + (yylhs.value.int8Val);
		
	}
#line 4172 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 369:
#line 2448 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) < (int8_t)-1)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";

		(yylhs.value.int8Val) = (int8_t)(yystack_[1].value.int8Val)  * (int8_t)10 + (int8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)-1 && (yylhs.value.int8Val) > (int8_t)28)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to int8_t: too big value";
		
		(yylhs.value.int8Val) = (int8_t)(yystack_[2].value.int8Val) * (int8_t)100 - (yylhs.value.int8Val);
		
	}
#line 4189 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 370:
#line 2461 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int8_t: too big value";
	}
#line 4197 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 371:
#line 2465 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int8_t: too big value";
	}
#line 4205 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 372:
#line 2472 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[0].value.int8Val);
	}
#line 4213 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 373:
#line 2476 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 4221 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 374:
#line 2480 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[1].value.int8Val) * (uint8_t)10 + (uint8_t)(yystack_[0].value.int8Val);
	}
#line 4229 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 375:
#line 2484 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 4237 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 376:
#line 2488 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.int8Val) > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: too big value";

		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[1].value.int8Val)  * (uint8_t)10 + (uint8_t)(yystack_[0].value.int8Val);
		
		if ((yystack_[2].value.int8Val) == (int8_t)2 && (yylhs.value.uInt8Val) >= (uint8_t)56)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: too big value";
		
		(yylhs.value.uInt8Val) = (uint8_t)(yystack_[2].value.int8Val) * (uint8_t)100 + (yylhs.value.uInt8Val);
		
	}
#line 4254 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 377:
#line 2501 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint8_t: negative value";
	}
#line 4262 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 378:
#line 2505 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint8_t: too big value";
	}
#line 4270 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 379:
#line 2509 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint8_t: too big value";
	}
#line 4278 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 380:
#line 2519 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = (int16_t)(yystack_[0].value.int8Val);
	}
#line 4286 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 381:
#line 2523 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = (int16_t)(yystack_[0].value.int8Val);
	}
#line 4294 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 382:
#line 2527 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 4304 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 383:
#line 2533 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 4314 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 384:
#line 2539 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 4325 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 385:
#line 2546 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 - 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 4336 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 386:
#line 2553 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 + 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 + 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 + 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 4348 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 387:
#line 2561 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int16Val) = 
		(int16_t)(yystack_[3].value.int8Val) * (int16_t)1000 - 
		(int16_t)(yystack_[2].value.int8Val) * (int16_t)100 - 
		(int16_t)(yystack_[1].value.int8Val) * (int16_t)10 - 
		(int16_t)(yystack_[0].value.int8Val);
	}
#line 4360 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 388:
#line 2569 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4380 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 389:
#line 2585 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4400 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 390:
#line 2601 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int16_t: too big value";
	}
#line 4408 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 391:
#line 2605 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int16_t: too big value";
	}
#line 4416 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 392:
#line 2612 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = (uint16_t)(yystack_[0].value.int8Val);
	}
#line 4424 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 393:
#line 2616 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4432 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 394:
#line 2620 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 4442 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 395:
#line 2626 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4450 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 396:
#line 2630 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[2].value.int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 4461 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 397:
#line 2637 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4469 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 398:
#line 2641 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt16Val) = 
		(uint16_t)(yystack_[3].value.int8Val) * (uint16_t)1000 + 
		(uint16_t)(yystack_[2].value.int8Val) * (uint16_t)100 + 
		(uint16_t)(yystack_[1].value.int8Val) * (uint16_t)10 + 
		(uint16_t)(yystack_[0].value.int8Val);
	}
#line 4481 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 399:
#line 2649 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4489 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 400:
#line 2653 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4509 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 401:
#line 2669 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint16_t: negative value";
	}
#line 4517 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 402:
#line 2673 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint16_t: too big value";
	}
#line 4525 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 403:
#line 2677 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint16_t: too big value";
	}
#line 4533 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 404:
#line 2687 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = (int32_t)(yystack_[0].value.int8Val);
	}
#line 4541 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 405:
#line 2691 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = (int32_t)(yystack_[0].value.int8Val);
	}
#line 4549 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 406:
#line 2695 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4559 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 407:
#line 2701 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4569 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 408:
#line 2707 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4580 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 409:
#line 2714 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4591 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 410:
#line 2721 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4603 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 411:
#line 2729 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4615 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 412:
#line 2737 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4628 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 413:
#line 2746 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4641 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 414:
#line 2755 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4655 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 415:
#line 2765 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int32Val) = 
		(int32_t)(yystack_[5].value.int8Val) * (int32_t)100000 - 
		(int32_t)(yystack_[4].value.int8Val) * (int32_t)10000 - 
		(int32_t)(yystack_[3].value.int8Val) * (int32_t)1000 - 
		(int32_t)(yystack_[2].value.int8Val) * (int32_t)100 - 
		(int32_t)(yystack_[1].value.int8Val) * (int32_t)10 - 
		(int32_t)(yystack_[0].value.int8Val);
	}
#line 4669 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 416:
#line 2775 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4684 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 417:
#line 2786 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4699 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 418:
#line 2797 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4715 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 419:
#line 2809 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4731 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 420:
#line 2821 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4748 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 421:
#line 2834 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4765 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 422:
#line 2847 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4790 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 423:
#line 2868 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4815 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 424:
#line 2889 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int32_t: too big value";
	}
#line 4823 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 425:
#line 2893 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int32_t: too big value";
	}
#line 4831 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 426:
#line 2900 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = (uint32_t)(yystack_[0].value.int8Val);
	}
#line 4839 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 427:
#line 2904 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4847 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 428:
#line 2908 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4857 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 429:
#line 2914 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4865 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 430:
#line 2918 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4876 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 431:
#line 2925 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4884 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 432:
#line 2929 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4896 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 433:
#line 2937 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4904 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 434:
#line 2941 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4917 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 435:
#line 2950 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4925 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 436:
#line 2954 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt32Val) = 
		(uint32_t)(yystack_[5].value.int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.int8Val);
	}
#line 4939 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 437:
#line 2964 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4947 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 438:
#line 2968 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4962 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 439:
#line 2979 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4970 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 440:
#line 2983 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 4986 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 441:
#line 2995 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 4994 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 442:
#line 2999 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5011 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 443:
#line 3012 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 5019 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 444:
#line 3016 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5044 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 445:
#line 3037 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint32_t: negative value";
	}
#line 5052 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 446:
#line 3041 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint32_t: too big value";
	}
#line 5060 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 447:
#line 3045 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint32_t: negative value";
	}
#line 5068 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 448:
#line 3055 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = (int64_t)(yystack_[0].value.int8Val);
	}
#line 5076 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 449:
#line 3059 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = (int64_t)(yystack_[0].value.int8Val);
	}
#line 5084 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 450:
#line 3063 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 5094 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 451:
#line 3069 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 5104 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 452:
#line 3075 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 5115 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 453:
#line 3082 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 5126 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 454:
#line 3089 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 5138 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 455:
#line 3097 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 5150 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 456:
#line 3105 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 5163 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 457:
#line 3114 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 5176 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 458:
#line 3123 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 + 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 + 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 + 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 + 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 + 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 5190 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 459:
#line 3133 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.int64Val) = 
		(int64_t)(yystack_[5].value.int8Val) * (int64_t)100000 - 
		(int64_t)(yystack_[4].value.int8Val) * (int64_t)10000 - 
		(int64_t)(yystack_[3].value.int8Val) * (int64_t)1000 - 
		(int64_t)(yystack_[2].value.int8Val) * (int64_t)100 - 
		(int64_t)(yystack_[1].value.int8Val) * (int64_t)10 - 
		(int64_t)(yystack_[0].value.int8Val);
	}
#line 5204 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 460:
#line 3143 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5219 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 461:
#line 3154 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5234 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 462:
#line 3165 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5250 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 463:
#line 3177 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5266 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 464:
#line 3189 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5283 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 465:
#line 3202 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5300 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 466:
#line 3215 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5318 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 467:
#line 3229 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5336 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 468:
#line 3244 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5355 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 469:
#line 3260 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5374 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 470:
#line 3276 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5394 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 471:
#line 3293 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5414 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 472:
#line 3310 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5435 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 473:
#line 3328 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5456 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 474:
#line 3346 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5478 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 475:
#line 3365 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5500 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 476:
#line 3384 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5523 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 477:
#line 3404 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5546 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 478:
#line 3424 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5570 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 479:
#line 3445 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5594 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 480:
#line 3466 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5619 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 481:
#line 3488 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5644 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 482:
#line 3510 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5670 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 483:
#line 3533 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5696 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 484:
#line 3556 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5728 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 485:
#line 3585 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5760 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 486:
#line 3614 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int64_t: too big value";
	}
#line 5769 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 487:
#line 3620 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to int64_t: too big value";
	}
#line 5778 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 488:
#line 3628 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = (uint64_t)(yystack_[0].value.int8Val);
	}
#line 5786 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 489:
#line 3632 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5794 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 490:
#line 3636 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5804 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 491:
#line 3642 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5812 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 492:
#line 3646 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5823 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 493:
#line 3653 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5831 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 494:
#line 3657 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5843 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 495:
#line 3665 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5851 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 496:
#line 3669 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5864 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 497:
#line 3678 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5872 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 498:
#line 3682 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.uInt64Val) = 
		(uint64_t)(yystack_[5].value.int8Val) * (uint64_t)100000 + 
		(uint64_t)(yystack_[4].value.int8Val) * (uint64_t)10000 + 
		(uint64_t)(yystack_[3].value.int8Val) * (uint64_t)1000 + 
		(uint64_t)(yystack_[2].value.int8Val) * (uint64_t)100 + 
		(uint64_t)(yystack_[1].value.int8Val) * (uint64_t)10 + 
		(uint64_t)(yystack_[0].value.int8Val);
	}
#line 5886 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 499:
#line 3692 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5894 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 500:
#line 3696 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5909 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 501:
#line 3707 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5917 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 502:
#line 3711 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5933 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 503:
#line 3723 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5941 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 504:
#line 3727 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5958 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 505:
#line 3740 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5966 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 506:
#line 3744 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 5984 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 507:
#line 3758 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 5992 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 508:
#line 3763 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 6011 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 509:
#line 3779 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) 
			<< (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 6020 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 510:
#line 3785 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 6040 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 511:
#line 3802 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) 
			<< (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 6049 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 512:
#line 3808 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 6070 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 513:
#line 3826 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) 
			<< (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 6079 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 514:
#line 3832 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 6101 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 515:
#line 3851 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) 
			<< (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 6110 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 516:
#line 3857 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 6133 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 517:
#line 3877 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) 
			<< (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 6142 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 518:
#line 3883 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 6166 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 519:
#line 3904 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) 
			<< (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 6175 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 520:
#line 3910 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 6200 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 521:
#line 3932 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) 
			<< (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 6209 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 522:
#line 3938 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 6235 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 523:
#line 3961 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) 
			<< (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 6244 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 524:
#line 3967 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 6271 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 525:
#line 3991 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) 
			<< (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 6280 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 526:
#line 3997 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 6317 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 527:
#line 4031 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) 
			<< (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << (yystack_[0].value.int8Val) << " to uint64_t: negative value";
	}
#line 6326 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 528:
#line 4037 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << 
				(yystack_[20].value.int8Val) << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) << (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint64_t: too big value";
	}
#line 6335 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 529:
#line 4043 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[20].value.int8Val) << (yystack_[19].value.int8Val) << (yystack_[18].value.int8Val) << (yystack_[17].value.int8Val) << (yystack_[16].value.int8Val) << (yystack_[15].value.int8Val) << (yystack_[14].value.int8Val) << (yystack_[13].value.int8Val) << (yystack_[12].value.int8Val) << (yystack_[11].value.int8Val) 
			<< (yystack_[10].value.int8Val) << (yystack_[9].value.int8Val) << (yystack_[8].value.int8Val) << (yystack_[7].value.int8Val) << (yystack_[6].value.int8Val) << (yystack_[5].value.int8Val) << (yystack_[4].value.int8Val) << (yystack_[3].value.int8Val) << (yystack_[2].value.int8Val) << (yystack_[1].value.int8Val) << "... to uint64_t: negative value";
	}
#line 6344 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 532:
#line 4057 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.doubleVal);
	}
#line 6352 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 533:
#line 4061 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.doubleVal);
	}
#line 6360 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 534:
#line 4065 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[2].value.doubleVal) + (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 6368 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 535:
#line 4069 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[2].value.doubleVal) - (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 6376 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 536:
#line 4073 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = - (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;	
	}
#line 6384 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 537:
#line 4077 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yystack_[0].value.floatDigits).value/(yystack_[0].value.floatDigits).digits;
	}
#line 6392 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 538:
#line 4081 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[3].value.doubleVal) + (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 6400 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 539:
#line 4085 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[3].value.doubleVal) - (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 6408 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 540:
#line 4089 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (- (yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));	
	}
#line 6416 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 541:
#line 4093 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = ((yystack_[1].value.floatDigits).value/(yystack_[1].value.floatDigits).digits) * pow(10.0, (yystack_[0].value.doubleVal));
	}
#line 6424 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 542:
#line 4100 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 6432 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 543:
#line 4104 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yylhs.value.doubleVal) * 10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 6440 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 544:
#line 4111 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 6448 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 545:
#line 4115 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (yylhs.value.doubleVal) * 10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 6456 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 546:
#line 4122 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.floatDigits).value = (double)(yystack_[0].value.int8Val);
		(yylhs.value.floatDigits).digits = 10.0;
	}
#line 6465 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 547:
#line 4127 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.floatDigits).value = (yylhs.value.floatDigits).value * 10.0 + (double)(yystack_[0].value.int8Val);
		(yylhs.value.floatDigits).digits = (yylhs.value.floatDigits).digits * 10.0;
	}
#line 6474 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 548:
#line 4135 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 6482 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 549:
#line 4139 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[0].value.int8Val);
	}
#line 6490 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 550:
#line 4143 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[1].value.int8Val) * (double)10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 6498 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 551:
#line 4147 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[1].value.int8Val) * (double)10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 6506 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 552:
#line 4151 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[2].value.int8Val) * (double)100.0 + (double)(yystack_[1].value.int8Val) * (double)10.0 + (double)(yystack_[0].value.int8Val);
	}
#line 6514 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 553:
#line 4155 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.doubleVal) = (double)(yystack_[2].value.int8Val) * (double)100.0 - (double)(yystack_[1].value.int8Val) * (double)10.0 - (double)(yystack_[0].value.int8Val);
	}
#line 6522 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;


#line 6526 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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


  const short int BisonDictionaryTextParser::yypact_ninf_ = -609;

  const signed char BisonDictionaryTextParser::yytable_ninf_ = -1;

  const short int
  BisonDictionaryTextParser::yypact_[] =
  {
     113,   614,   122,   621,   103,   145,   105,    25,  -609,   293,
     649,    22,   203,   234,   218,   361,   393,   449,   208,   271,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,    20,
      54,   225,   228,   231,   233,   257,   260,   262,   263,   265,
     267,   268,   269,   270,    29,    34,   473,   493,    57,   511,
     566,   704,   568,    93,   554,    22,  -609,   581,   601,   605,
     611,   105,   105,   532,   575,   272,   651,   273,   728,   274,
     783,   275,   812,   276,   869,   277,   907,   278,   908,   279,
     909,   281,   910,   282,   912,   283,   913,   284,   914,   285,
     915,   286,   916,   288,   917,   772,   291,  -609,   649,   292,
     803,   921,  -609,   223,   872,   799,  -609,  -609,  -609,  -609,
     148,   920,   922,   929,   931,   932,   932,  -609,   923,  -609,
    -609,   924,   895,  -609,   926,  -609,   927,  -609,   928,  -609,
     930,  -609,   933,  -609,   934,  -609,   935,  -609,   936,  -609,
     937,  -609,   938,  -609,   939,  -609,   940,  -609,   941,  -609,
     942,  -609,   904,   943,   947,   906,  -609,   955,   956,   204,
    -609,   925,   294,   297,   299,   313,   322,   323,   328,   329,
     331,   333,   334,   335,   336,   337,   339,   340,    65,   142,
     557,   511,  -609,  -609,   957,   958,  -609,   959,   959,   105,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,   341,  -609,   961,   342,
     953,   962,   963,   343,   344,   345,   347,   348,   349,   350,
     351,   352,   353,   354,   358,   359,   360,   363,   143,   177,
      33,   511,   964,   204,   204,   204,   212,   639,   204,   511,
     960,   365,   965,   371,   966,   379,   967,   388,   968,   394,
     969,   397,   970,   399,   971,   401,   972,   402,   973,   403,
     974,   405,   975,   406,   976,   407,   977,   408,   978,   409,
     979,   410,   980,   944,   411,  -609,   649,   413,  -609,   570,
     981,   991,   992,  -609,  -609,   983,   414,   984,   986,   982,
    -609,   415,   961,   996,   997,   710,   416,   716,   417,   718,
     418,   720,   419,   722,   420,   724,   423,   726,   424,   730,
     426,   732,   428,   734,   429,   736,   431,   738,   433,   740,
     437,   742,   454,   744,   458,   746,  1000,   460,  -609,   649,
     463,   748,  -609,   197,   985,   989,  -609,   993,   994,  -609,
     205,  -609,   998,   995,  -609,  -609,   999,  -609,  1001,  -609,
    1002,  -609,  1003,  -609,  1004,  -609,  1005,  -609,  1007,  -609,
    1008,  -609,  1009,  -609,  1012,  -609,  1013,  -609,  1014,  -609,
    1015,  -609,  1016,  -609,  1017,  -609,  1018,  -609,  1006,  1019,
    1023,  1010,  -609,   704,  -609,   465,  1031,  1032,  -609,  1024,
     760,  1025,   961,  1026,  -609,  1028,  1037,  1038,  -609,    96,
     752,  -609,   155,   754,  -609,   619,   756,  -609,   622,   758,
    -609,   625,   761,  -609,   646,   763,  -609,   652,   765,  -609,
     655,   767,  -609,   658,   769,  -609,  1040,   771,  -609,  1041,
     773,  -609,    19,   775,  -609,    27,   777,  -609,   680,   779,
    -609,   683,   781,  -609,   793,  1011,   791,  1033,  1020,  -609,
    -609,  1042,   794,  -609,   467,  -609,   796,   798,  1039,  1047,
    1044,  1046,  1050,  1051,  1052,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,   468,  -609,   961,   472,  1043,  1049,   704,   704,   704,
     800,   802,  1054,   704,  1055,   475,  1048,  1064,  -609,  -609,
    -609,  -609,   961,  1059,  1057,  1068,  1069,  1060,  1061,  -609,
    1070,  1073,  1074,  1065,  1066,  -609,  1075,  1071,  1072,  -609,
    1076,  1079,  1080,  1077,  1078,  -609,  1081,  1084,  1085,  1082,
    1083,  -609,  1087,  1086,  1088,  -609,  1089,  1090,  1091,  -609,
    1092,  1093,  1094,  -609,  1095,  1099,  1102,  1096,  1097,  -609,
    1103,  1098,  -609,  1107,  1100,  -609,  1109,  -609,  -609,  1104,
    1112,   954,  1105,    30,    35,  -609,  1111,  1106,  1108,  -609,
    1115,  1110,  1113,  -609,  1117,  1114,  1116,  -609,  1119,  1118,
    1120,   476,  -609,  1123,   961,   477,  1122,  1121,  -609,  1125,
     804,   479,  -609,  1130,  -609,  1131,  1134,  1135,  -609,  -609,
    -609,  -609,  -609,  1126,   480,  1129,  -609,   481,   961,  1128,
    -609,  1132,  1133,  -609,   608,  -609,  1137,   259,  1136,  -609,
    1138,  1142,  1143,  1139,   961,  -609,  1145,  1146,  -609,  -609,
    1140,  1149,  1151,  -609,  -609,  1144,  -609,  -609,  1147,  1152,
    1153,  -609,  -609,  1148,  1155,  1156,  -609,  -609,  1150,  -609,
    -609,  1154,  -609,  -609,  1157,  -609,  -609,  1158,  1159,  1161,
    -609,  -609,  1160,  -609,  1162,  -609,  1163,  -609,  -609,   591,
    1112,  -609,  -609,  1112,  -609,  1112,  1164,  -609,  -609,  1165,
    -609,  -609,  1166,  -609,  -609,  1167,  -609,  -609,   806,   482,
    1168,  1171,  -609,   483,   961,  -609,  1170,  -609,  1169,   808,
    1172,  1173,  1181,  1184,  -609,  1175,  1176,  1180,  -609,  1182,
    -609,   810,   814,  1178,  1179,  1183,  1185,   484,   485,   486,
     490,   492,   494,   495,   497,   499,   503,   504,   506,   507,
     521,   524,   199,   222,   220,   511,  1186,  -609,   932,   932,
    1187,  1190,  1191,  1192,  -609,   932,   932,  -609,  -609,  1194,
    1199,  -609,  1200,  1201,  -609,  -609,  -609,  -609,  1202,  1203,
    -609,  -609,  -609,  -609,  1204,  1205,  -609,   591,   591,   591,
    -609,  -609,  -609,  -609,  -609,   824,   818,  -609,  -609,  1206,
    -609,  1198,  -609,  1197,  -609,  1207,  -609,  -609,  1208,  1210,
    -609,  -609,   961,  1209,  1211,  -609,  1212,  -609,  1213,  -609,
    -609,  -609,  -609,   820,   529,   822,   531,   825,   533,   827,
     534,   829,   535,   832,   541,   834,   542,   836,   543,   838,
     545,   840,   546,   842,   547,   845,   548,   847,   549,   849,
     550,   851,   551,   853,  1053,   552,  -609,   649,   553,   855,
    -609,   221,  1127,  -609,   959,   959,  -609,  1214,   932,   932,
     959,   959,  1217,  1218,  1219,  1220,  1222,  1223,  1225,  1226,
    -609,  -609,  -609,  1221,  1224,  -609,  1227,   961,  1228,  -609,
    -609,  1229,  1230,  1232,  1233,   961,  -609,  1234,  1235,  -609,
     102,   857,  -609,   686,   859,  -609,   689,   861,  -609,   692,
     863,  -609,   695,   865,  -609,   698,   867,  -609,   701,   871,
    -609,   708,   873,  -609,   711,   876,  -609,  1231,   878,  -609,
    1236,   880,  -609,    53,   882,  -609,    60,   884,  -609,   714,
     886,  -609,   717,   888,  -609,   898,  1177,   892,  1239,  1193,
    -609,  -609,  1238,   894,  -609,   555,  -609,   959,   959,   932,
     932,   932,   932,  1237,  1242,  -609,  -609,  -609,  -609,  1240,
    1241,   961,  -609,  1243,  1247,  1244,  1245,  -609,  -609,  1246,
    1248,  -609,  1249,  1250,  1251,  -609,  1253,  1252,  1254,  -609,
    1255,  1256,  1257,  -609,  1261,  1258,  1259,  -609,  1263,  1260,
    1262,  -609,  1269,  1264,  1265,  -609,  1271,  1266,  1267,  -609,
    1276,  1270,  1272,  -609,  1277,  1273,  -609,  1279,  1274,  -609,
    1283,  1278,  1280,  -609,  1284,  1281,  1282,  -609,  1285,  1286,
    1287,  -609,  1291,  1288,  1289,  -609,  1292,  1290,  1293,   556,
    -609,  1299,   961,   558,  1295,  1294,  -609,  1303,   896,   561,
     959,   959,   959,   959,  1306,  1307,  -609,  -609,  1300,  1309,
    1310,  -609,  1301,  -609,  -609,  1302,  -609,  -609,  1304,  -609,
    -609,  1305,  -609,  -609,  1308,  -609,  -609,  1311,  -609,  -609,
    1312,  -609,  -609,  1313,  -609,  -609,  1314,  -609,  -609,  1315,
    -609,  1316,  -609,  1317,  -609,  -609,  1318,  -609,  -609,  1319,
    -609,  -609,  1320,  -609,  -609,  1321,  -609,  -609,   899,   565,
    1322,  1325,  -609,   569,   961,  -609,  1324,  -609,  1333,   901,
    1336,  1337,  -609,  1338,  1339,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,   911,   905,  -609,  -609,  1334,  -609,  1332,  -609,
    1335,  -609,  1340,  1343,  1344,  1346,  1347,  1341,  1342,  -609,
    1348,   961,  1349,  -609,  -609,  1345,  1353,  1354,  1357,  1358,
    -609,  -609,  1350,  1351,   961,  -609,  1361,  1362,  1363,  1364,
    -609,  -609,  1359,  1365,  1366,  1368,  1369,  -609,  1370,  1371,
    1372,  1373,  1374,  1375,  1376,  1377,  1378,  1379,  1380,  1381,
    1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391,
    1392,  1393,  1394,  1395,   932,   932,  1396,  1397,   959,   959,
     932,   932,   959,   959
  };

  const unsigned short int
  BisonDictionaryTextParser::yydefact_[] =
  {
       0,     0,     0,     0,   426,   427,     8,     0,     1,     0,
       0,     0,     0,     9,   428,   429,   372,   373,     0,     0,
      11,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   404,   405,     0,     0,
       0,    30,     0,   195,     0,     0,    10,   430,   431,   374,
     375,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   216,     0,     0,
     406,   407,   214,     0,   193,     0,     2,    31,     4,   196,
       0,     0,     0,   432,   433,   376,   377,     7,     0,   197,
     358,     0,     0,   198,     0,   199,     0,   200,     0,   201,
       0,   202,     0,   203,     0,   204,     0,   205,     0,   206,
       0,   207,     0,   208,     0,   209,     0,   210,     0,   211,
       0,   212,     0,     0,     0,     0,   240,   408,   409,     0,
     238,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     5,   434,   435,   530,   378,   379,     0,
     221,   359,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,     0,   236,     0,     0,
       0,   410,   411,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,    49,     0,
       0,   436,   437,   531,     6,     0,     0,   362,     0,   360,
     218,     0,     0,   412,   413,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   350,     0,
       0,     0,   348,     0,     0,     0,   246,     0,     0,   266,
       0,   287,     0,     0,   194,   220,     0,    32,     0,    33,
       0,    34,     0,    35,     0,    36,     0,    37,     0,    38,
       0,    39,     0,    40,     0,    41,     0,    42,     0,    43,
       0,    44,     0,    45,     0,    46,     0,    47,     0,     0,
       0,     0,    75,     0,    73,     0,   438,   439,   213,     0,
       0,     0,     0,     0,   242,     0,   414,   415,   247,     0,
       0,   248,     0,     0,   249,     0,     0,   250,     0,     0,
     251,     0,     0,   252,     0,     0,   253,     0,     0,   254,
       0,     0,   255,     0,     0,   256,     0,     0,   257,     0,
       0,   258,     0,     0,   259,     0,     0,   260,     0,     0,
     261,     0,     0,   262,     0,     0,     0,     0,     0,   354,
     264,     0,     0,   349,     0,   215,     0,     0,   448,   449,
       0,     0,     0,     0,     0,   244,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,    71,     0,     0,     0,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,   440,   441,   237,   363,
     217,   361,     0,     0,     0,   416,   417,     0,     0,   268,
       0,   364,   365,     0,     0,   269,     0,     0,     0,   270,
       0,   380,   381,     0,     0,   271,     0,   392,   393,     0,
       0,   272,     0,     0,     0,   273,     0,     0,     0,   274,
       0,     0,     0,   275,     0,   488,   489,     0,     0,   276,
       0,     0,   277,     0,     0,   278,     0,   542,   544,     0,
       0,     0,     0,   532,   533,   279,     0,     0,     0,   280,
       0,     0,     0,   281,     0,     0,     0,   282,     0,     0,
       0,     0,   283,     0,     0,     0,     0,     0,   286,     0,
       0,     0,   265,     0,   285,     0,   450,   451,   308,   347,
     346,   329,   239,     0,     0,     0,    53,     0,     0,     0,
      81,     0,     0,   101,     0,   122,     0,     0,     0,    55,
       0,   442,   443,     0,     0,   241,   418,   419,   331,   289,
       0,   366,   367,   290,   332,     0,   291,   333,     0,   382,
     383,   292,   334,     0,   394,   395,   293,   335,     0,   294,
     336,     0,   295,   337,     0,   296,   338,     0,   490,   491,
     297,   339,     0,   298,     0,   299,     0,   300,   546,   537,
       0,   340,   543,     0,   545,     0,     0,   301,   341,     0,
     302,   342,     0,   303,   343,     0,   304,   344,     0,     0,
       0,     0,   352,     0,     0,   306,     0,   267,     0,     0,
       0,     0,   452,   453,    48,     0,     0,     0,    77,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,   444,   445,
       0,     0,   420,   421,   310,   368,   369,   311,   312,   384,
     385,   313,   396,   397,   314,   315,   316,   317,   492,   493,
     318,   319,   320,   547,   548,   549,   541,   536,   534,   535,
     321,   322,   323,   324,   263,     0,     0,   325,   351,     0,
     356,     0,   328,     0,   288,     0,   307,   327,   454,   455,
      72,    52,     0,     0,     0,   100,     0,   120,     0,   143,
     182,   181,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   185,     0,     0,     0,
     183,     0,     0,    74,   446,   447,   219,     0,   422,   423,
     370,   371,   386,   387,   398,   399,   494,   495,   550,   551,
     540,   538,   539,     0,     0,   284,     0,     0,     0,   355,
     309,     0,   456,   457,     0,     0,    76,     0,     0,    82,
       0,     0,    83,     0,     0,    84,     0,     0,    85,     0,
       0,    86,     0,     0,    87,     0,     0,    88,     0,     0,
      89,     0,     0,    90,     0,     0,    91,     0,     0,    92,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,    96,     0,     0,    97,     0,     0,     0,     0,     0,
     189,    99,     0,     0,   184,     0,   243,   424,   425,   388,
     389,   400,   401,   496,   497,   552,   553,   305,   345,     0,
       0,     0,   330,   458,   459,     0,     0,   142,   162,     0,
       0,   103,     0,     0,     0,   104,     0,     0,     0,   105,
       0,     0,     0,   106,     0,     0,     0,   107,     0,     0,
       0,   108,     0,     0,     0,   109,     0,     0,     0,   110,
       0,     0,     0,   111,     0,     0,   112,     0,     0,   113,
       0,     0,     0,   114,     0,     0,     0,   115,     0,     0,
       0,   116,     0,     0,     0,   117,     0,     0,     0,     0,
     118,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     390,   391,   402,   403,   498,   499,   326,   353,     0,   460,
     461,    54,     0,   166,   124,     0,   125,   167,     0,   126,
     168,     0,   127,   169,     0,   128,   170,     0,   129,   171,
       0,   130,   172,     0,   131,   173,     0,   132,   174,     0,
     133,     0,   134,     0,   135,   175,     0,   136,   176,     0,
     137,   177,     0,   138,   178,     0,   139,   179,     0,     0,
       0,     0,   187,     0,     0,   141,     0,   102,     0,     0,
     500,   501,   357,   462,   463,    78,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    98,     0,     0,   160,   186,     0,   191,     0,   163,
       0,   123,     0,   502,   503,   464,   465,     0,     0,   119,
       0,     0,     0,   190,   144,     0,   504,   505,   466,   467,
     140,   180,     0,     0,     0,   165,   506,   507,   468,   469,
     161,   188,     0,   508,   509,   470,   471,   192,   510,   511,
     472,   473,   512,   513,   474,   475,   514,   515,   476,   477,
     516,   517,   478,   479,   518,   519,   480,   481,   520,   521,
     482,   483,   522,   523,   484,   485,   524,   525,   486,   487,
     526,   527,   528,   529
  };

  const short int
  BisonDictionaryTextParser::yypgoto_[] =
  {
    -609,  -609,  -609,   987,  -609,   -82,    -3,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -256,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -171,    11,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,   -69,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,   -39,  -284,  -609,   100,   -47,    98,    97,
       6,  -400,  -379,  -429,  -126,  -422,  -609,  -609,  -608,   -28
  };

  const short int
  BisonDictionaryTextParser::yydefgoto_[] =
  {
      -1,     2,     3,    12,    13,    38,    60,    61,   393,   390,
     717,   503,   495,   803,   496,   497,   498,   499,   500,   938,
    1136,   501,  1034,  1152,   115,    62,    63,   169,   164,   403,
     248,   220,   513,   242,   243,   244,   245,   246,   457,   789,
     247,   596,   878,    75,   298,   299,   524,    18,   534,   540,
     502,     7,   472,   558,   197,   572,   573,   574,   679,   776
  };

  const unsigned short int
  BisonDictionaryTextParser::yytable_[] =
  {
     198,    77,    79,    81,    83,    85,    87,    89,    91,    93,
      95,    97,    99,   101,   103,   106,   109,    64,   405,   113,
     290,   509,   586,   578,   127,   128,   165,   548,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,   567,   568,   569,    56,    57,
      73,   552,    58,   567,   568,   577,   682,   570,   117,   104,
      19,   684,   121,   341,   107,   570,   342,    64,   683,   582,
     344,    64,   777,   685,   119,   778,   122,   779,   354,   567,
     568,  1011,    59,    74,    76,   571,   567,   568,  1015,   105,
     112,   570,    74,   571,   108,   282,    74,    74,   570,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    74,   511,   571,
      74,   517,     8,    58,   518,   283,   571,   969,    74,    14,
     970,    16,    17,   251,   253,   255,   257,   259,   261,   263,
     265,   267,   269,   271,   273,   275,   277,   279,   281,   284,
     287,   289,   294,    59,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,    15,   285,   335,   346,   347,   348,   296,   190,   353,
     301,   521,   522,   523,   306,   308,   310,   312,   314,   316,
     318,   320,   322,   324,   326,   328,   330,   332,   334,   337,
     340,   343,   286,   336,   391,    74,    74,   338,   191,   615,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   462,   633,   843,
     463,   468,   469,   470,   240,   471,    65,   339,     9,    10,
      74,   620,   621,   622,    67,   725,    71,   628,   349,   350,
     849,   943,   846,   850,   944,    78,   170,   458,    80,   844,
     132,    82,    74,    84,   241,   727,   728,   729,   730,   731,
     732,   733,   734,   735,   736,   737,   738,   739,   740,   741,
     742,   743,   847,    74,   132,    74,   132,    86,    74,   744,
      88,    74,    90,    92,    74,    94,    74,    96,    98,   100,
     102,    72,   131,   134,   136,   138,   140,   142,   144,   146,
     701,   148,   150,   152,   154,   156,   158,    20,   160,   745,
      74,   163,   166,    74,   250,    74,    74,   252,    74,   254,
      74,    74,    74,    74,   719,   132,   132,   132,   132,   132,
     132,   132,   132,   256,   132,   132,   132,   132,   132,   132,
     751,   132,   258,   260,   132,   132,   505,    74,   262,   264,
      74,   266,    74,   268,   270,   272,   274,   276,   528,   278,
     280,   295,   300,   305,   307,   309,    74,   311,   313,   315,
     317,   319,   321,   323,   325,    74,    74,    68,   327,   329,
     331,    74,    74,   333,    74,   356,    74,    74,    74,    74,
      74,   358,    74,    74,    74,    74,    74,    74,    74,   360,
      74,    74,    74,    74,    74,    74,    74,    74,   362,    69,
     791,    74,    74,    74,   364,   601,    74,   366,   132,   368,
     544,   370,   372,   374,   132,   376,   378,   380,   382,   384,
     386,   389,   132,   392,   399,   404,   410,   413,   416,   419,
     422,   132,   614,   425,   428,   617,   431,   132,   434,   437,
     132,   440,   132,   443,   132,   132,   132,   446,   132,   132,
     132,   132,   132,   132,   132,    70,   132,   132,   132,   132,
     132,   132,   132,   132,   449,  1002,   132,   132,   452,   132,
     456,   132,   132,   459,   132,   504,   132,   600,   613,   110,
     132,  1012,   616,  1024,  1016,   630,   698,   702,   994,   709,
     715,   718,   786,   790,   813,   815,   817,   132,   884,   111,
     819,   132,   821,   132,   823,   825,   132,   827,    74,   829,
      74,    74,   998,   831,   833,    74,   835,   837,   132,    74,
      74,   114,   132,   132,   132,   132,   132,    74,    74,    74,
    1020,   839,   699,    74,   841,    74,   703,    74,    74,   891,
      74,   894,    74,   897,   900,   903,    74,    74,   129,    74,
      74,   906,   909,   912,   852,   915,   918,   921,   924,   927,
     930,   933,   937,   940,    74,  1038,  1098,    74,  1102,   120,
     288,  1109,   132,   960,   132,  1133,   132,   132,   132,  1137,
     116,   966,   118,   394,   132,   132,   132,   123,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   773,    74,    74,
      74,    74,   854,   855,   132,     9,    10,   124,   132,   860,
     861,   125,   132,   132,   468,   469,   723,   126,   724,   130,
       4,     5,   774,   775,     6,    16,    17,   527,   531,   532,
     533,   537,   538,   539,    11,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    56,    57,   543,   351,   352,  1048,     4,     5,
     547,   468,   469,   551,   555,   556,   557,   133,   814,   816,
     818,   820,   822,   824,   826,   828,   830,   832,   834,   836,
     838,   840,   842,   845,   848,   851,   468,   469,   581,   555,
     556,   585,   521,   522,   973,    16,    17,   977,   531,   532,
     981,   537,   538,   985,    56,    57,   989,     4,     5,   993,
      56,    57,   947,   948,   468,   469,   997,   555,   556,  1001,
     468,   469,  1019,   555,   556,  1023,   408,   409,  1101,   870,
     871,   872,   411,   412,   414,   415,   417,   418,   420,   421,
     423,   424,   426,   427,   135,   939,   429,   430,   432,   433,
     435,   436,   438,   439,   441,   442,   444,   445,   447,   448,
     450,   451,   453,   454,   460,   461,   468,   469,   519,   520,
     525,   526,   529,   530,   535,   536,   162,   541,   542,   545,
     546,   549,   550,   553,   554,   559,   560,   562,   563,   565,
     566,   575,   576,   579,   580,   583,   584,   587,   588,   137,
    1138,   589,   590,  1040,  1041,  1042,  1043,   592,   593,   167,
     598,   599,   602,   603,   604,   605,   623,   624,   625,   626,
     707,   708,   784,   785,   794,   795,   805,   806,   139,   978,
     807,   808,   873,   874,   875,   876,   889,   890,   892,   893,
     172,   895,   896,   898,   899,   901,   902,  1163,   904,   905,
     907,   908,   910,   911,   913,   914,   916,   917,   919,   920,
    1172,   922,   923,   925,   926,   928,   929,   931,   932,   934,
     935,   941,   942,   971,   972,   975,   976,   979,   980,   983,
     984,   987,   988,   991,   992,   141,  1039,   995,   996,   999,
    1000,   990,  1003,  1004,  1006,  1007,  1009,  1010,  1013,  1014,
    1017,  1018,  1021,  1022,  1025,  1026,  1027,  1028,  1030,  1031,
    1036,  1037,  1107,  1108,   171,  1131,  1132,  1141,  1142,  1147,
    1148,  1149,  1150,   143,   145,   147,   149,   168,   151,   153,
     155,   157,   159,   161,   192,   194,   193,   195,   196,   201,
     200,   199,   202,   203,   204,   216,   205,   219,   388,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   217,
     218,   221,   222,   291,   292,   293,   302,   249,   303,   304,
    1099,   297,   680,   974,  1103,     0,   355,   982,   345,   986,
      66,   357,   359,   361,   363,   365,   367,   369,   371,   373,
     375,   377,   379,   381,   383,   385,   387,   396,   397,   398,
     401,   400,   406,   407,   455,   465,   473,   466,   467,   474,
       0,     0,     0,     0,     0,   475,     0,   476,   477,   478,
     479,   480,   395,   481,   482,   483,   464,   402,   484,   485,
     486,   487,   488,   489,   490,   492,   493,   506,   507,   512,
     508,   510,   514,   515,   516,   606,   594,   491,   561,   564,
     597,   494,   591,   607,   631,     0,   618,   936,  1208,  1209,
     608,   595,   609,   619,  1212,  1213,   610,   611,   612,   627,
     632,   629,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   648,   649,   650,   646,   647,   653,
     654,   655,     0,   651,   652,   658,     0,   661,   656,   657,
     664,     0,   659,   667,   660,   668,   662,   663,   669,   665,
     666,   672,   670,   671,   673,   674,   675,   676,   678,   686,
     677,   681,   687,   689,   688,   692,   690,   695,     0,   691,
     693,   700,   694,   706,   696,   704,   697,   705,   710,   711,
     712,   713,   714,   716,   720,   726,   721,   722,   748,   749,
     746,   752,   753,   750,   747,   755,   754,   756,   759,   760,
     757,   762,   763,   758,   761,   768,   764,   769,   945,     0,
     765,     0,     0,   766,   767,     0,   770,   793,   771,   772,
     780,   781,   782,   783,   787,   788,   792,   798,   796,   797,
     799,   800,   801,   802,   809,   810,   804,   858,   859,   811,
     862,   812,   853,   856,   857,   863,   864,   865,   866,   867,
     868,   869,   879,   880,   882,   881,   883,     0,  1029,   877,
     887,   888,   885,   949,   950,   951,   952,   886,   953,   954,
     946,   955,   956,     0,  1033,   959,   963,   957,   964,  1005,
     958,   961,     0,  1044,  1008,   962,  1035,   965,  1045,  1049,
     967,   968,  1032,  1050,     0,  1047,  1046,  1055,     0,  1052,
    1051,  1058,  1053,  1061,  1054,     0,  1056,  1057,  1059,  1064,
    1060,  1067,  1062,  1063,  1065,  1066,  1068,  1070,  1069,  1073,
    1071,  1072,  1074,  1075,  1076,  1079,  1077,  1081,  1078,  1080,
    1082,  1083,  1086,  1089,  1084,     0,  1085,  1087,  1088,  1092,
    1095,     0,  1090,  1091,  1093,  1094,  1096,  1100,  1104,  1097,
    1105,  1106,  1110,  1111,  1112,  1113,  1114,  1115,  1116,     0,
    1117,  1118,     0,     0,  1119,     0,     0,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1134,  1135,
    1139,  1140,  1143,  1144,  1145,  1146,  1153,  1151,  1155,  1156,
    1157,  1154,  1158,  1159,     0,     0,  1162,  1160,  1161,  1166,
    1167,  1165,  1164,  1168,  1169,  1171,  1170,  1173,  1174,  1175,
    1176,  1178,  1179,  1177,  1180,  1181,  1182,  1183,  1184,  1185,
    1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,
    1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1207,  1210,  1211
  };

  const short int
  BisonDictionaryTextParser::yycheck_[] =
  {
     126,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    11,   302,    58,
     191,   400,   451,   445,    71,    72,   108,   427,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    26,    27,    28,    26,    27,
      30,   430,    30,    26,    27,    28,    26,    38,    61,    30,
      35,    26,    65,    30,    30,    38,    33,    61,    38,   448,
     241,    65,   680,    38,    63,   683,    65,   685,   249,    26,
      27,    28,    60,    63,    30,    66,    26,    27,    28,    60,
      33,    38,    63,    66,    60,    30,    63,    63,    38,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     3,    63,   402,    66,
      63,    25,     0,    30,    28,    60,    66,    25,    63,    26,
      28,    26,    27,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   199,    60,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    26,    30,    30,   243,   244,   245,   216,    30,   248,
     219,    26,    27,    28,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    60,    60,   286,    63,    63,    30,    60,   493,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    30,   512,    30,
      33,    26,    27,    28,    30,    30,    33,    60,     4,     5,
      63,   497,   498,   499,    26,   624,    38,   503,    36,    37,
      30,    30,    30,    33,    33,    30,    33,   339,    30,    60,
      63,    30,    63,    30,    60,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    60,    63,    63,    63,    63,    30,    63,    30,
      30,    63,    30,    30,    63,    30,    63,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
     594,    30,    30,    30,    30,    30,    30,    24,    30,    60,
      63,    30,    30,    63,    30,    63,    63,    30,    63,    30,
      63,    63,    63,    63,   618,    63,    63,    63,    63,    63,
      63,    63,    63,    30,    63,    63,    63,    63,    63,    63,
     634,    63,    30,    30,    63,    63,   395,    63,    30,    30,
      63,    30,    63,    30,    30,    30,    30,    30,   415,    30,
      30,    30,    30,    30,    30,    30,    63,    30,    30,    30,
      30,    30,    30,    30,    30,    63,    63,    26,    30,    30,
      30,    63,    63,    30,    63,    30,    63,    63,    63,    63,
      63,    30,    63,    63,    63,    63,    63,    63,    63,    30,
      63,    63,    63,    63,    63,    63,    63,    63,    30,    26,
     704,    63,    63,    63,    30,   464,    63,    30,    63,    30,
     424,    30,    30,    30,    63,    30,    30,    30,    30,    30,
      30,    30,    63,    30,    30,    30,    30,    30,    30,    30,
      30,    63,   491,    30,    30,   494,    30,    63,    30,    30,
      63,    30,    63,    30,    63,    63,    63,    30,    63,    63,
      63,    63,    63,    63,    63,    26,    63,    63,    63,    63,
      63,    63,    63,    63,    30,   914,    63,    63,    30,    63,
      30,    63,    63,    30,    63,    30,    63,    30,    30,    26,
      63,   923,    30,   932,   926,    30,    30,    30,   908,    30,
      30,    30,    30,    30,    30,    30,    30,    63,   802,    26,
      30,    63,    30,    63,    30,    30,    63,    30,    63,    30,
      63,    63,   911,    30,    30,    63,    30,    30,    63,    63,
      63,    30,    63,    63,    63,    63,    63,    63,    63,    63,
     929,    30,   591,    63,    30,    63,   595,    63,    63,    30,
      63,    30,    63,    30,    30,    30,    63,    63,    36,    63,
      63,    30,    30,    30,   745,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    63,    30,    30,    63,    30,    35,
      33,    30,    63,   877,    63,    30,    63,    63,    63,    30,
      34,   885,    34,    33,    63,    63,    63,    26,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    26,    63,    63,
      63,    63,   748,   749,    63,     4,     5,    26,    63,   755,
     756,    26,    63,    63,    26,    27,    28,    26,    30,    64,
      26,    27,    51,    52,    30,    26,    27,    28,    26,    27,
      28,    26,    27,    28,    33,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    26,    27,    28,    36,    37,   961,    26,    27,
      28,    26,    27,    28,    26,    27,    28,    36,   727,   728,
     729,   730,   731,   732,   733,   734,   735,   736,   737,   738,
     739,   740,   741,   742,   743,   744,    26,    27,    28,    26,
      27,    28,    26,    27,    28,    26,    27,    28,    26,    27,
      28,    26,    27,    28,    26,    27,    28,    26,    27,    28,
      26,    27,   858,   859,    26,    27,    28,    26,    27,    28,
      26,    27,    28,    26,    27,    28,    36,    37,  1032,   777,
     778,   779,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,   847,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    26,    27,    36,    37,
      36,    37,    36,    37,    36,    37,    24,    36,    37,    36,
      37,    36,    37,    36,    37,    36,    37,    36,    37,    36,
      37,    36,    37,    36,    37,    36,    37,    36,    37,    36,
    1104,    28,    29,   949,   950,   951,   952,    36,    37,    26,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,   896,
      36,    37,    28,    29,    36,    37,    36,    37,    36,    37,
      61,    36,    37,    36,    37,    36,    37,  1151,    36,    37,
      36,    37,    36,    37,    36,    37,    36,    37,    36,    37,
    1164,    36,    37,    36,    37,    36,    37,    36,    37,    36,
      37,    36,    37,    36,    37,    36,    37,    36,    37,    36,
      37,    36,    37,    36,    37,    36,   945,    36,    37,    36,
      37,   905,    36,    37,    36,    37,    36,    37,    36,    37,
      36,    37,    36,    37,    36,    37,    28,    29,    36,    37,
      36,    37,    36,    37,    62,    36,    37,    36,    37,    28,
      29,    36,    37,    36,    36,    36,    36,    26,    36,    36,
      36,    36,    36,    36,    34,    26,    34,    26,    26,    64,
      36,    38,    36,    36,    36,    61,    36,    61,    24,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      33,    26,    26,    26,    26,    26,    33,    62,    26,    26,
    1029,    30,    38,   893,  1033,    -1,    36,   899,    34,   902,
      13,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    26,    26,    36,
      34,    37,    26,    26,    24,    36,    28,    34,    34,    34,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    36,    36,    36,
      36,    36,    61,    36,    36,    36,    61,    65,    36,    36,
      36,    36,    36,    36,    36,    36,    33,    26,    26,    33,
      36,    36,    34,    26,    26,    26,    33,    61,    28,    28,
      28,    61,    61,    26,    26,    -1,    33,    24,  1204,  1205,
      36,    61,    36,    34,  1210,  1211,    36,    36,    36,    35,
      26,    36,    33,    36,    26,    26,    36,    36,    28,    26,
      26,    36,    36,    28,    28,    26,    26,    36,    36,    28,
      26,    26,    -1,    36,    36,    28,    -1,    28,    36,    36,
      28,    -1,    36,    28,    36,    26,    36,    36,    26,    36,
      36,    28,    36,    36,    36,    28,    36,    28,    26,    28,
      36,    36,    36,    28,    36,    28,    36,    28,    -1,    36,
      36,    28,    36,    28,    36,    33,    36,    36,    28,    28,
      26,    26,    36,    34,    36,    28,    34,    34,    26,    26,
      34,    26,    26,    34,    36,    26,    36,    26,    26,    26,
      36,    26,    26,    36,    36,    26,    36,    26,    61,    -1,
      36,    -1,    -1,    36,    36,    -1,    36,    28,    36,    36,
      36,    36,    36,    36,    36,    34,    36,    26,    36,    36,
      26,    36,    36,    33,    36,    36,    34,    26,    26,    36,
      26,    36,    36,    36,    34,    26,    26,    26,    26,    26,
      26,    26,    34,    36,    26,    28,    26,    -1,    61,    33,
      28,    28,    33,    26,    26,    26,    26,    36,    26,    26,
      36,    26,    26,    -1,    61,    28,    26,    36,    26,    28,
      36,    33,    -1,    26,    28,    36,    28,    34,    26,    26,
      36,    36,    33,    26,    -1,    34,    36,    28,    -1,    34,
      36,    28,    36,    28,    36,    -1,    36,    36,    36,    28,
      36,    28,    36,    36,    36,    36,    36,    28,    36,    28,
      36,    36,    36,    36,    28,    28,    36,    28,    36,    36,
      36,    28,    28,    28,    36,    -1,    36,    36,    36,    28,
      28,    -1,    36,    36,    36,    36,    36,    28,    33,    36,
      36,    28,    26,    26,    34,    26,    26,    36,    36,    -1,
      36,    36,    -1,    -1,    36,    -1,    -1,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    34,
      36,    28,    26,    26,    26,    26,    34,    33,    28,    26,
      26,    36,    26,    26,    -1,    -1,    28,    36,    36,    26,
      26,    36,    33,    26,    26,    34,    36,    26,    26,    26,
      26,    26,    26,    34,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26
  };

  const unsigned char
  BisonDictionaryTextParser::yystos_[] =
  {
       0,     3,    68,    69,    26,    27,    30,   118,     0,     4,
       5,    33,    70,    71,    26,    26,    26,    27,   114,    35,
      24,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    72,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    26,    27,    30,    60,
      73,    74,    92,    93,   117,    33,    70,    26,    26,    26,
      26,    38,    30,    30,    63,   110,    30,   110,    30,   110,
      30,   110,    30,   110,    30,   110,    30,   110,    30,   110,
      30,   110,    30,   110,    30,   110,    30,   110,    30,   110,
      30,   110,    30,   110,    30,    60,   110,    30,    60,   110,
      26,    26,    33,   110,    30,    91,    34,    73,    34,    92,
      35,    73,    92,    26,    26,    26,    26,   114,   114,    36,
      64,    30,    63,    36,    30,    36,    30,    36,    30,    36,
      30,    36,    30,    36,    30,    36,    30,    36,    30,    36,
      30,    36,    30,    36,    30,    36,    30,    36,    30,    36,
      30,    36,    24,    30,    95,    72,    30,    26,    26,    94,
      33,    62,    61,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      30,    60,    34,    34,    26,    26,    26,   121,   121,    38,
      36,    64,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    61,    36,    33,    61,
      98,    26,    26,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      30,    60,   100,   101,   102,   103,   104,   107,    97,    62,
      30,   110,    30,   110,    30,   110,    30,   110,    30,   110,
      30,   110,    30,   110,    30,   110,    30,   110,    30,   110,
      30,   110,    30,   110,    30,   110,    30,   110,    30,   110,
      30,   110,    30,    60,   110,    30,    60,   110,    33,   110,
      91,    26,    26,    26,   114,    30,   110,    30,   111,   112,
      30,   110,    33,    26,    26,    30,   110,    30,   110,    30,
     110,    30,   110,    30,   110,    30,   110,    30,   110,    30,
     110,    30,   110,    30,   110,    30,   110,    30,   110,    30,
     110,    30,   110,    30,   110,    30,    60,   110,    30,    60,
     110,    30,    33,   110,    91,    34,   100,   100,   100,    36,
      37,    36,    37,   100,    91,    36,    30,    36,    30,    36,
      30,    36,    30,    36,    30,    36,    30,    36,    30,    36,
      30,    36,    30,    36,    30,    36,    30,    36,    30,    36,
      30,    36,    30,    36,    30,    36,    30,    36,    24,    30,
      76,    72,    30,    75,    33,    61,    26,    26,    36,    30,
      37,    34,    65,    96,    30,   111,    26,    26,    36,    37,
      30,    36,    37,    30,    36,    37,    30,    36,    37,    30,
      36,    37,    30,    36,    37,    30,    36,    37,    30,    36,
      37,    30,    36,    37,    30,    36,    37,    30,    36,    37,
      30,    36,    37,    30,    36,    37,    30,    36,    37,    30,
      36,    37,    30,    36,    37,    24,    30,   105,    72,    30,
      36,    37,    30,    33,    61,    36,    34,    34,    26,    27,
      28,    30,   119,    28,    34,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    61,    36,    33,    61,    79,    81,    82,    83,    84,
      85,    88,   117,    78,    30,   110,    26,    26,    36,   119,
      36,   111,    33,    99,    34,    26,    26,    25,    28,    36,
      37,    26,    27,    28,   113,    36,    37,    28,   114,    36,
      37,    26,    27,    28,   115,    36,    37,    26,    27,    28,
     116,    36,    37,    28,   117,    36,    37,    28,   118,    36,
      37,    28,   119,    36,    37,    26,    27,    28,   120,    36,
      37,    28,    36,    37,    28,    36,    37,    26,    27,    28,
      38,    66,   122,   123,   124,    36,    37,    28,   122,    36,
      37,    28,   119,    36,    37,    28,   120,    36,    37,    28,
      29,    61,    36,    37,    33,    61,   108,    28,    36,    37,
      30,   110,    36,    37,    36,    37,    26,    26,    36,    36,
      36,    36,    36,    30,   110,   111,    30,   110,    33,    34,
      81,    81,    81,    36,    37,    36,    37,    35,    81,    36,
      30,    26,    26,   111,    33,    36,    26,    26,    36,    36,
      28,    26,    26,    36,    36,    28,    36,    36,    28,    26,
      26,    36,    36,    28,    26,    26,    36,    36,    28,    36,
      36,    28,    36,    36,    28,    36,    36,    28,    26,    26,
      36,    36,    28,    36,    28,    36,    28,    36,    26,   125,
      38,    36,    26,    38,    26,    38,    28,    36,    36,    28,
      36,    36,    28,    36,    36,    28,    36,    36,    30,   110,
      28,   111,    30,   110,    33,    36,    28,    36,    37,    30,
      28,    28,    26,    26,    36,    30,    34,    77,    30,   111,
      36,    34,    34,    28,    30,   119,    28,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    30,    60,    34,    36,    26,    26,
      34,   111,    26,    26,    36,    26,    26,    36,    36,    26,
      26,    36,    26,    26,    36,    36,    36,    36,    26,    26,
      36,    36,    36,    26,    51,    52,   126,   125,   125,   125,
      36,    36,    36,    36,    36,    37,    30,    36,    34,   106,
      30,   111,    36,    28,    36,    37,    36,    36,    26,    26,
      36,    36,    33,    80,    34,    36,    37,    36,    37,    36,
      36,    36,    36,    30,   110,    30,   110,    30,   110,    30,
     110,    30,   110,    30,   110,    30,   110,    30,   110,    30,
     110,    30,   110,    30,   110,    30,   110,    30,   110,    30,
     110,    30,   110,    30,    60,   110,    30,    60,   110,    30,
      33,   110,    91,    36,   121,   121,    36,    34,    26,    26,
     121,   121,    26,    26,    26,    26,    26,    26,    26,    26,
     126,   126,   126,    28,    29,    36,    37,    33,   109,    34,
      36,    28,    26,    26,   111,    33,    36,    28,    28,    36,
      37,    30,    36,    37,    30,    36,    37,    30,    36,    37,
      30,    36,    37,    30,    36,    37,    30,    36,    37,    30,
      36,    37,    30,    36,    37,    30,    36,    37,    30,    36,
      37,    30,    36,    37,    30,    36,    37,    30,    36,    37,
      30,    36,    37,    30,    36,    37,    24,    30,    86,    72,
      30,    36,    37,    30,    33,    61,    36,   121,   121,    26,
      26,    26,    26,    26,    26,    26,    26,    36,    36,    28,
     111,    33,    36,    26,    26,    34,   111,    36,    36,    25,
      28,    36,    37,    28,   113,    36,    37,    28,   114,    36,
      37,    28,   115,    36,    37,    28,   116,    36,    37,    28,
     117,    36,    37,    28,   118,    36,    37,    28,   119,    36,
      37,    28,   120,    36,    37,    28,    36,    37,    28,    36,
      37,    28,   122,    36,    37,    28,   122,    36,    37,    28,
     119,    36,    37,    28,   120,    36,    37,    28,    29,    61,
      36,    37,    33,    61,    89,    28,    36,    37,    30,   110,
     121,   121,   121,   121,    26,    26,    36,    34,   111,    26,
      26,    36,    34,    36,    36,    28,    36,    36,    28,    36,
      36,    28,    36,    36,    28,    36,    36,    28,    36,    36,
      28,    36,    36,    28,    36,    36,    28,    36,    36,    28,
      36,    28,    36,    28,    36,    36,    28,    36,    36,    28,
      36,    36,    28,    36,    36,    28,    36,    36,    30,   110,
      28,   111,    30,   110,    33,    36,    28,    36,    37,    30,
      26,    26,    34,    26,    26,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    37,    30,    36,    34,    87,    30,   111,    36,
      28,    36,    37,    26,    26,    26,    26,    28,    29,    36,
      37,    33,    90,    34,    36,    28,    26,    26,    26,    26,
      36,    36,    28,   111,    33,    36,    26,    26,    26,    26,
      36,    34,   111,    26,    26,    26,    26,    34,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,   121,   121,
      26,    26,   121,   121
  };

  const unsigned char
  BisonDictionaryTextParser::yyr1_[] =
  {
       0,    67,    68,    68,    68,    68,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      74,    76,    74,    77,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    78,    74,    79,    74,    80,    74,    74,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    84,    86,    85,    87,    85,    89,
      88,    90,    88,    91,    91,    92,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    94,    93,    95,    93,    96,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    97,    93,
      98,    93,    99,    93,    93,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   102,   103,
     105,   104,   106,   104,   108,   107,   109,   107,   110,   110,
     111,   111,   112,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     121,   121,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     126,   126,   126,   126
  };

  const unsigned char
  BisonDictionaryTextParser::yyr2_[] =
  {
       0,     2,     4,     5,     4,     5,     7,     5,     2,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     8,     0,
       8,     0,     9,     0,    12,     7,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     9,     0,     9,     0,    10,     0,    13,     8,
       1,     2,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     8,     5,
       4,     2,     7,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     9,
       4,     6,     2,     8,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
      10,     7,     6,     4,     9,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       8,    11,     6,     8,     4,    10,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
      10,     4,     4,     4,     5,     0,     8,     0,    11,     0,
       9,     0,    12,     1,     4,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     6,     0,     6,     0,     7,     0,    10,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     7,     0,     7,
       0,     8,     0,    11,     6,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     6,     3,     4,     2,     5,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     7,     4,     4,     2,     6,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     8,     5,     6,     4,     7,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     9,     6,     6,     4,
       8,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     8,     4,     4,     2,     3,
       0,     6,     0,     9,     0,     7,     0,    10,     2,     3,
       1,     3,     1,     3,     1,     1,     2,     2,     3,     3,
       4,     4,     1,     1,     2,     2,     3,     3,     4,     4,
       1,     1,     2,     2,     3,     3,     4,     4,     5,     5,
       6,     6,     1,     1,     2,     2,     3,     3,     4,     4,
       5,     5,     6,     6,     1,     1,     2,     2,     3,     3,
       4,     4,     5,     5,     6,     6,     7,     7,     8,     8,
       9,     9,    10,    10,    11,    11,     1,     1,     2,     2,
       3,     3,     4,     4,     5,     5,     6,     6,     7,     7,
       8,     8,     9,     9,    10,    10,    11,    11,     1,     1,
       2,     2,     3,     3,     4,     4,     5,     5,     6,     6,
       7,     7,     8,     8,     9,     9,    10,    10,    11,    11,
      12,    12,    13,    13,    14,    14,    15,    15,    16,    16,
      17,    17,    18,    18,    19,    19,    20,    20,     1,     1,
       2,     2,     3,     3,     4,     4,     5,     5,     6,     6,
       7,     7,     8,     8,     9,     9,    10,    10,    11,    11,
      12,    12,    13,    13,    14,    14,    15,    15,    16,    16,
      17,    17,    18,    18,    19,    19,    20,    20,    21,    21,
       1,     2,     1,     1,     3,     3,     3,     2,     4,     4,
       4,     3,     1,     2,     1,     2,     1,     2,     1,     1,
       2,     2,     3,     3
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
  "\"Array declaration\"", "\"Array of Struct field declaration\"",
  "\"Array of Struct field declaration (auto id)\"",
  "\"Array of Enum field declaration\"",
  "\"Array of Enum field declaration (auto id)\"",
  "\"Polymorph elements\"", "'<'", "'>'", "'|'", "'['", "']'", "','",
  "'-'", "$accept", "dictionary", "head", "dict_attributes",
  "dict_attribute", "USDS_TYPE", "tags", "tag", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "fields", "field", "struct_field_begin",
  "array_of_struct_field_begin", "enum_field_begin", "$@7", "$@8",
  "array_of_enum_field_begin", "$@9", "$@10", "poly_elements",
  "tags_auto_id", "tag_auto_id", "$@11", "$@12", "$@13", "$@14", "$@15",
  "$@16", "fields_auto_id", "field_auto_id", "struct_field_begin_auto_id",
  "array_of_struct_field_begin_auto_id", "enum_field_begin_auto_id",
  "$@17", "$@18", "array_of_enum_field_begin_auto_id", "$@19", "$@20",
  "array_dimension", "enumerators", "enumerator", "INT8_T", "UINT8_T",
  "INT16_T", "UINT16_T", "INT32_T", "UINT32_T", "INT64_T", "UINT64_T",
  "digits", "FLOAT_VALUE", "positive_major_float_digits",
  "negative_major_float_digits", "minor_float_digits", "float_exponent", YY_NULL
  };

#if DICTIONARY_TEXTDEBUG
  const unsigned short int
  BisonDictionaryTextParser::yyrline_[] =
  {
       0,   149,   149,   153,   157,   161,   168,   172,   176,   182,
     182,   185,   189,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     218,   218,   220,   224,   228,   232,   236,   240,   244,   248,
     252,   256,   260,   264,   268,   272,   276,   280,   284,   290,
     289,   298,   297,   303,   302,   308,   315,   325,   335,   345,
     355,   365,   375,   385,   395,   405,   415,   425,   435,   445,
     455,   465,   475,   487,   486,   499,   498,   510,   509,   521,
     535,   535,   538,   542,   546,   550,   554,   558,   562,   566,
     570,   574,   578,   582,   586,   590,   594,   598,   602,   607,
     612,   616,   620,   627,   636,   645,   654,   663,   672,   681,
     690,   699,   708,   717,   726,   735,   744,   753,   762,   771,
     781,   788,   798,   805,   816,   821,   826,   831,   836,   841,
     846,   851,   856,   861,   866,   871,   876,   881,   886,   891,
     896,   902,   908,   913,   918,   926,   936,   946,   956,   966,
     976,   986,   996,  1006,  1016,  1026,  1036,  1046,  1056,  1066,
    1076,  1086,  1097,  1106,  1117,  1126,  1138,  1143,  1148,  1153,
    1158,  1163,  1168,  1173,  1178,  1183,  1188,  1193,  1198,  1203,
    1208,  1214,  1219,  1227,  1234,  1248,  1247,  1253,  1252,  1262,
    1261,  1275,  1274,  1291,  1296,  1307,  1307,  1310,  1314,  1318,
    1322,  1326,  1330,  1334,  1338,  1342,  1346,  1350,  1354,  1358,
    1362,  1366,  1370,  1374,  1380,  1379,  1388,  1387,  1393,  1392,
    1398,  1405,  1415,  1425,  1435,  1445,  1455,  1465,  1475,  1485,
    1495,  1505,  1515,  1525,  1535,  1545,  1555,  1565,  1577,  1576,
    1589,  1588,  1600,  1599,  1611,  1626,  1626,  1629,  1633,  1637,
    1641,  1645,  1649,  1653,  1657,  1661,  1665,  1669,  1673,  1677,
    1681,  1685,  1689,  1693,  1698,  1703,  1707,  1711,  1718,  1727,
    1736,  1745,  1754,  1763,  1772,  1781,  1790,  1799,  1808,  1817,
    1826,  1835,  1844,  1853,  1862,  1872,  1879,  1889,  1896,  1907,
    1912,  1917,  1922,  1927,  1932,  1937,  1942,  1947,  1952,  1957,
    1962,  1967,  1972,  1977,  1982,  1987,  1993,  1999,  2004,  2009,
    2017,  2027,  2037,  2047,  2057,  2067,  2077,  2087,  2097,  2107,
    2117,  2127,  2137,  2147,  2157,  2167,  2177,  2188,  2197,  2208,
    2217,  2230,  2235,  2240,  2245,  2250,  2255,  2260,  2265,  2270,
    2275,  2280,  2285,  2290,  2295,  2300,  2306,  2311,  2319,  2326,
    2340,  2339,  2345,  2344,  2354,  2353,  2367,  2366,  2386,  2390,
    2399,  2399,  2402,  2407,  2418,  2422,  2426,  2430,  2434,  2447,
    2460,  2464,  2471,  2475,  2479,  2483,  2487,  2500,  2504,  2508,
    2518,  2522,  2526,  2532,  2538,  2545,  2552,  2560,  2568,  2584,
    2600,  2604,  2611,  2615,  2619,  2625,  2629,  2636,  2640,  2648,
    2652,  2668,  2672,  2676,  2686,  2690,  2694,  2700,  2706,  2713,
    2720,  2728,  2736,  2745,  2754,  2764,  2774,  2785,  2796,  2808,
    2820,  2833,  2846,  2867,  2888,  2892,  2899,  2903,  2907,  2913,
    2917,  2924,  2928,  2936,  2940,  2949,  2953,  2963,  2967,  2978,
    2982,  2994,  2998,  3011,  3015,  3036,  3040,  3044,  3054,  3058,
    3062,  3068,  3074,  3081,  3088,  3096,  3104,  3113,  3122,  3132,
    3142,  3153,  3164,  3176,  3188,  3201,  3214,  3228,  3242,  3258,
    3274,  3291,  3308,  3326,  3344,  3363,  3382,  3402,  3422,  3443,
    3464,  3486,  3508,  3531,  3554,  3583,  3612,  3618,  3627,  3631,
    3635,  3641,  3645,  3652,  3656,  3664,  3668,  3677,  3681,  3691,
    3695,  3706,  3710,  3722,  3726,  3739,  3743,  3757,  3761,  3777,
    3783,  3800,  3806,  3824,  3830,  3849,  3855,  3875,  3881,  3902,
    3908,  3930,  3936,  3959,  3965,  3989,  3995,  4029,  4035,  4041,
    4049,  4049,  4056,  4060,  4064,  4068,  4072,  4076,  4080,  4084,
    4088,  4092,  4099,  4103,  4110,  4114,  4121,  4126,  4134,  4138,
    4142,  4146,  4150,  4154
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
       2,     2,     2,     2,    65,    66,    38,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    36,
      60,    37,    61,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,    62,    34,     2,     2,     2,     2,
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
      51,    52,    53,    54,    55,    56,    57,    58,    59
    };
    const unsigned int user_token_number_max_ = 308;
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
#line 7790 "bisonDictionaryTextParser.cc" // lalr1.cc:1156
#line 4161 "bisonDictionaryTextParser.y" // lalr1.cc:1157

//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

