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
	#include "dictionary\dataTypes\dictionaryArray.h"
	#include "dictionary\dataTypes\dictionaryBoolean.h"
	#include "dictionary\dataTypes\dictionaryDouble.h"
	#include "dictionary\dataTypes\dictionaryInt.h"
	#include "dictionary\dataTypes\dictionaryLong.h"
	#include "dictionary\dataTypes\dictionaryString.h"
	#include "dictionary\dataTypes\dictionaryUVarint.h"
	#include "dictionary\dataTypes\dictionaryStruct.h"
	#include "dictionary\dataTypes\dictionaryTagLink.h"
	
	#include "usdsTypes.h"
	
	#include "flexDictionaryTextScanner.h"
	#include <string>
	

#line 60 "bisonDictionaryTextParser.cc" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "bisonDictionaryTextParser.hh"

// User implementation prologue.
#line 83 "bisonDictionaryTextParser.y" // lalr1.cc:406

#undef yylex
#define yylex scanner->scan

#line 78 "bisonDictionaryTextParser.cc" // lalr1.cc:406


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

#line 28 "bisonDictionaryTextParser.y" // lalr1.cc:473
namespace usds {
#line 164 "bisonDictionaryTextParser.cc" // lalr1.cc:473

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
#line 93 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		dict->setID(input_text + (yystack_[5].value.stringVal)[0], (yystack_[5].value.stringVal)[1], (yystack_[4].value.UInt32Val), (yystack_[2].value.UInt8Val), (yystack_[0].value.UInt8Val));
	}
#line 619 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 3:
#line 97 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		// Finilize dictionary
		dict->finalizeDictionary();
	}
#line 628 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 6:
#line 110 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 636 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 7:
#line 114 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 644 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 8:
#line 118 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag((yystack_[5].value.typeVal), (yystack_[7].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)tag)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 653 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 9:
#line 123 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = dict->addTag(USDS_STRUCT, (yystack_[3].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 661 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 10:
#line 127 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
	
	}
#line 669 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 13:
#line 139 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 677 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 14:
#line 143 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		((DictionaryStruct*)tag)->addField((yystack_[2].value.typeVal), (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 685 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 15:
#line 147 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField((yystack_[5].value.typeVal), (yystack_[7].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryString*)field)->setDefaultEncode((yystack_[3].value.encodeVal));
	}
#line 694 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 16:
#line 152 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[4].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[2].value.stringVal)[0], (yystack_[2].value.stringVal)[1]);
	}
#line 703 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 17:
#line 157 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = tag->getParent();
	}
#line 711 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 18:
#line 164 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 720 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 19:
#line 169 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[4].value.typeVal), (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		dict_field->setNullable(true);
	}
#line 729 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 20:
#line 174 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		usds::DictionaryBaseType* dict_field = ((DictionaryStruct*)tag)->addField((yystack_[7].value.typeVal), (yystack_[9].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryString*)dict_field)->setDefaultEncode((yystack_[5].value.encodeVal));
		dict_field->setNullable(true);
	}
#line 739 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 21:
#line 180 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		field = ((DictionaryStruct*)tag)->addField(usds::USDS_TAG, (yystack_[6].value.Int32Val), input_text + (yystack_[3].value.stringVal)[0], (yystack_[3].value.stringVal)[1]);
		((DictionaryTagLink*)field)->setTag(input_text + (yystack_[4].value.stringVal)[0], (yystack_[4].value.stringVal)[1]);
		field->setNullable(true);
	}
#line 749 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 22:
#line 186 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag->setNullable(true);
		tag = tag->getParent();
	}
#line 758 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 23:
#line 194 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		tag = ((DictionaryStruct*)tag)->addField(usds::USDS_STRUCT, (yystack_[3].value.Int32Val), input_text + (yystack_[1].value.stringVal)[0], (yystack_[1].value.stringVal)[1]);
	}
#line 766 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 24:
#line 204 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt8Val) = (uint8_t)(yystack_[0].value.Int8Val);
	}
#line 774 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 25:
#line 208 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt8Val) = (uint8_t)(yystack_[1].value.Int8Val) * (uint8_t)10 + (uint8_t)(yystack_[0].value.Int8Val);
	}
#line 782 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 26:
#line 212 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		if ((yystack_[2].value.Int8Val) > (int8_t)2)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to uint8_t: too big value";

		(yylhs.value.UInt8Val) = (uint8_t)(yystack_[1].value.Int8Val)  * (uint8_t)10 + (uint8_t)(yystack_[0].value.Int8Val);
		
		if ((yystack_[2].value.Int8Val) == (int8_t)2 && (yylhs.value.UInt8Val) >= (uint8_t)56)
			throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << (yystack_[0].value.Int8Val) << " to uint8_t: too big value";
		
		(yylhs.value.UInt8Val) = (uint8_t)(yystack_[2].value.Int8Val) * (uint8_t)100 + (yylhs.value.UInt8Val);
		
	}
#line 799 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 27:
#line 225 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to uint8_t: too big value";
	}
#line 807 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 28:
#line 232 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = (uint32_t)(yystack_[0].value.Int8Val);
	}
#line 815 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 29:
#line 236 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 825 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 30:
#line 242 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 836 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 31:
#line 249 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[3].value.Int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 848 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 32:
#line 257 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[4].value.Int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.Int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 861 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 33:
#line 266 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.UInt32Val) = 
		(uint32_t)(yystack_[5].value.Int8Val) * (uint32_t)100000 + 
		(uint32_t)(yystack_[4].value.Int8Val) * (uint32_t)10000 + 
		(uint32_t)(yystack_[3].value.Int8Val) * (uint32_t)1000 + 
		(uint32_t)(yystack_[2].value.Int8Val) * (uint32_t)100 + 
		(uint32_t)(yystack_[1].value.Int8Val) * (uint32_t)10 + 
		(uint32_t)(yystack_[0].value.Int8Val);
	}
#line 875 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 34:
#line 276 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 890 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 35:
#line 287 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 906 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 36:
#line 299 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 923 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 37:
#line 312 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 948 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 38:
#line 333 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to uint32_t: too big value";
	}
#line 956 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 39:
#line 340 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = (int32_t)(yystack_[0].value.Int8Val);
	}
#line 964 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 40:
#line 344 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 974 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 41:
#line 350 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 985 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 42:
#line 357 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 997 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 43:
#line 365 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1010 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 44:
#line 374 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		(yylhs.value.Int32Val) = 
		(int32_t)(yystack_[5].value.Int8Val) * (int32_t)100000 + 
		(int32_t)(yystack_[4].value.Int8Val) * (int32_t)10000 + 
		(int32_t)(yystack_[3].value.Int8Val) * (int32_t)1000 + 
		(int32_t)(yystack_[2].value.Int8Val) * (int32_t)100 + 
		(int32_t)(yystack_[1].value.Int8Val) * (int32_t)10 + 
		(int32_t)(yystack_[0].value.Int8Val);
	}
#line 1024 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 45:
#line 384 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 1039 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 46:
#line 395 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 1055 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 47:
#line 407 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 1072 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 48:
#line 420 "bisonDictionaryTextParser.y" // lalr1.cc:846
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
#line 1097 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;

  case 49:
#line 441 "bisonDictionaryTextParser.y" // lalr1.cc:846
    {
		throw ErrorMessage(usds::ERROR_VALUE_CONVERSION) << "Can not convert the number " << (yystack_[10].value.Int8Val) << (yystack_[9].value.Int8Val) << (yystack_[8].value.Int8Val) << (yystack_[7].value.Int8Val) << (yystack_[6].value.Int8Val) << (yystack_[5].value.Int8Val) << (yystack_[4].value.Int8Val) << (yystack_[3].value.Int8Val) << (yystack_[2].value.Int8Val) << (yystack_[1].value.Int8Val) << "... to int32_t: too big value";
	}
#line 1105 "bisonDictionaryTextParser.cc" // lalr1.cc:846
    break;


#line 1109 "bisonDictionaryTextParser.cc" // lalr1.cc:846
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


  const signed char BisonDictionaryTextParser::yypact_ninf_ = -47;

  const signed char BisonDictionaryTextParser::yytable_ninf_ = -1;

  const signed char
  BisonDictionaryTextParser::yypact_[] =
  {
      13,     5,    21,    22,   -47,    23,    14,    24,    26,    27,
      28,    18,    30,    31,    26,    32,    33,   -47,    35,   -47,
      36,    15,    37,   -47,    38,    39,    40,    34,    38,    41,
      42,    43,   -47,   -47,    -2,    33,    44,    45,   -11,    46,
      36,    47,    48,    49,    52,   -47,    51,   -47,   -47,    29,
      38,    53,    56,    54,    38,    38,    55,    60,    57,    58,
     -47,    61,     0,    62,   -47,   -47,     1,    66,   -10,     3,
      64,   -47,    63,     4,     6,    72,     8,   -47,    33,    65,
     -47,    69,   -47,    70,    59,   -47,    71,    36,   -47,    67,
      68,    75,    73,   -47,   -47,    10,   -47,   -47,    77,    74,
     -47
  };

  const unsigned char
  BisonDictionaryTextParser::yydefact_[] =
  {
       0,     0,     0,     0,     1,    28,     0,    29,     0,    30,
      24,     0,    31,    25,     0,    32,    26,     2,    33,    50,
      27,     0,    34,    51,     0,    35,    39,     0,     4,     0,
      36,    40,     3,     5,     0,    37,    41,     0,     0,     0,
      38,    42,     0,     0,     0,     9,    43,     6,     7,     0,
       0,    44,     0,     0,    11,     0,     0,    45,     0,     0,
      12,     0,     0,    46,     8,    10,     0,     0,     0,     0,
      47,    17,     0,     0,     0,     0,     0,    23,    48,     0,
      13,     0,    14,     0,     0,    16,     0,    49,    22,     0,
       0,     0,     0,    18,    19,     0,    21,    15,     0,     0,
      20
  };

  const signed char
  BisonDictionaryTextParser::yypgoto_[] =
  {
     -47,   -47,   -47,    76,   -47,   -47,   -46,   -47,   -47,    50,
     -47,   -17,   -35
  };

  const signed char
  BisonDictionaryTextParser::yydefgoto_[] =
  {
      -1,     2,    21,    27,    28,    50,    53,    54,    55,    11,
       6,    56,    20
  };

  const unsigned char
  BisonDictionaryTextParser::yytable_[] =
  {
      40,    43,    74,    37,    38,    67,    68,    29,    60,    61,
      39,    29,    69,    44,    75,    76,     1,     3,    77,    71,
      72,     4,    80,    81,    82,    83,    85,    86,    97,    98,
      24,     5,     7,     9,     8,    10,    12,    13,    14,    15,
      16,    18,    19,    87,    22,    23,    25,    26,    30,    31,
      32,    35,    36,    41,    52,     0,    46,    42,    34,    49,
      51,    45,    57,     0,    17,     0,    47,    48,    58,    63,
      59,    70,    62,    78,    79,    64,    65,    66,    73,    84,
      89,    90,    92,    88,    91,    93,    94,    95,    99,     0,
       0,    96,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33
  };

  const signed char
  BisonDictionaryTextParser::yycheck_[] =
  {
      35,    12,    12,     5,     6,     5,     6,    24,    54,    55,
      12,    28,    12,    24,    24,    12,     3,    12,    15,    18,
      19,     0,    18,    19,    18,    19,    18,    19,    18,    19,
      15,     9,     9,     9,    20,     9,     9,     9,    20,     9,
       9,     9,     9,    78,     9,     9,     9,     9,     9,     9,
      16,     9,     9,     9,    25,    -1,     9,    12,    17,     7,
       9,    15,     9,    -1,    14,    -1,    18,    18,    12,     9,
      16,     9,    17,     9,    11,    18,    18,    16,    12,     7,
      11,    11,    11,    18,    25,    18,    18,    12,    11,    -1,
      -1,    18,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28
  };

  const unsigned char
  BisonDictionaryTextParser::yystos_[] =
  {
       0,     3,    27,    12,     0,     9,    36,     9,    20,     9,
       9,    35,     9,     9,    20,     9,     9,    35,     9,     9,
      38,    28,     9,     9,    15,     9,     9,    29,    30,    37,
       9,     9,    16,    29,    17,     9,     9,     5,     6,    12,
      38,     9,    12,    12,    24,    15,     9,    18,    18,     7,
      31,     9,    25,    32,    33,    34,    37,     9,    12,    16,
      32,    32,    17,     9,    18,    18,    16,     5,     6,    12,
       9,    18,    19,    12,    12,    24,    12,    15,     9,    11,
      18,    19,    18,    19,     7,    18,    19,    38,    18,    11,
      11,    25,    11,    18,    18,    12,    18,    18,    19,    11,
      18
  };

  const unsigned char
  BisonDictionaryTextParser::yyr1_[] =
  {
       0,    26,    28,    27,    29,    29,    30,    30,    30,    31,
      30,    32,    32,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    34,    35,    35,    35,    35,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      38,    38
  };

  const unsigned char
  BisonDictionaryTextParser::yyr2_[] =
  {
       0,     2,     0,    11,     1,     2,     5,     5,     8,     0,
       8,     1,     2,     5,     5,     8,     5,     4,     7,     7,
      10,     7,     6,     4,     1,     2,     3,     4,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const BisonDictionaryTextParser::yytname_[] =
  {
  "$end", "error", "$undefined", "USDS", "DICTIONARY_VERSION",
  "\"Simple type\"", "\"STRING\"", "\"<Text encode>\"",
  "\"true or false\"", "\"Digit\"", "\"-Digit\"", "NULL_VALUE",
  "\"object name\"", "USDS_RESTRICT", "\"notRoot\"", "'{'", "'}'", "':'",
  "';'", "'='", "'.'", "\"uint8_t\"", "\"int32_t\"", "\"uint32_t\"", "'<'",
  "'>'", "$accept", "dictionary", "$@1", "tags", "tag", "$@2", "fields",
  "field", "struct_begin", "UINT8_T", "UINT32_T", "INT32_T", "digits", YY_NULL
  };

#if DICTIONARY_TEXTDEBUG
  const unsigned short int
  BisonDictionaryTextParser::yyrline_[] =
  {
       0,    93,    93,    92,   107,   107,   109,   113,   117,   123,
     122,   135,   135,   138,   142,   146,   151,   156,   163,   168,
     173,   179,   185,   193,   203,   207,   211,   224,   231,   235,
     241,   248,   256,   265,   275,   286,   298,   311,   332,   339,
     343,   349,   356,   364,   373,   383,   394,   406,   419,   440,
     446,   446
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
       2,     2,     2,     2,     2,     2,    20,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    17,    18,
      24,    19,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    15,     2,    16,     2,     2,     2,     2,
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
      21,    22,    23
    };
    const unsigned int user_token_number_max_ = 272;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 28 "bisonDictionaryTextParser.y" // lalr1.cc:1156
} // usds
#line 1591 "bisonDictionaryTextParser.cc" // lalr1.cc:1156
#line 448 "bisonDictionaryTextParser.y" // lalr1.cc:1157

//=================================================================================================

void usds::BisonDictionaryTextParser::error(const usds::BisonDictionaryTextParser::location_type &loc, const std::string &msg)
{
	throw ErrorMessage(usds::DICTIONARY_TEXT_PARSER__ERROR) << "Error in Text Dictionary!\n" << loc.begin.line << "." << loc.begin.column << ": " << msg;
}

