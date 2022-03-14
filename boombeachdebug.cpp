template<typename _TraitsT>
  template<bool __icase, bool __collate>
    bool
    _Compiler<_TraitsT>::
    _M_expression_term(pair<bool, _CharT>& __last_char,
		       _BracketMatcher<_TraitsT, __icase, __collate>& __matcher)
    {
      if (_M_match_token(_ScannerT::_S_token_bracket_end))
	return false;

      const auto __push_char = [&](_CharT __ch)
      {
	if (__last_char.first)
	  __matcher._M_add_char(__last_char.second);
	else
	  __last_char.first = true;
	__last_char.second = __ch;
      };
      const auto __flush = [&]
      {
	if (__last_char.first)
	  {
	    __matcher._M_add_char(__last_char.second);
	    __last_char.first = false;
	  }
      };

      if (_M_match_token(_ScannerT::_S_token_collsymbol))
	{
	  auto __symbol = __matcher._M_add_collate_element(_M_value);
	  if (__symbol.size() == 1)
	    __push_char(__symbol[0]);
	  else
	    __flush();
	}
      else if (_M_match_token(_ScannerT::_S_token_equiv_class_name))
	{
	  __flush();
	  __matcher._M_add_equivalence_class(_M_value);
	}
      else if (_M_match_token(_ScannerT::_S_token_char_class_name))
	{
	  __flush();
	  __matcher._M_add_character_class(_M_value, false);
	}
      else if (_M_try_char())
	__push_char(_M_value[0]);
      // POSIX doesn't allow '-' as a start-range char (say [a-z--0]),
      // except when the '-' is the first or last character in the bracket
      // expression ([--0]). ECMAScript treats all '-' after a range as a
      // normal character. Also see above, where _M_expression_term gets called.
      //
      // As a result, POSIX rejects [-----], but ECMAScript doesn't.
      // Boost (1.57.0) always uses POSIX style even in its ECMAScript syntax.
      // Clang (3.5) always uses ECMAScript style even in its POSIX syntax.
      //
      // It turns out that no one reads BNFs ;)
      else if (_M_match_token(_ScannerT::_S_token_bracket_dash))
	{
	  if (!__last_char.first)
	    {
	      if (!(_M_flags & regex_constants::ECMAScript))
		{
		  if (_M_match_token(_ScannerT::_S_token_bracket_end))
		    {
		      __push_char('-');
		      return false;
		    }
		  __throw_regex_error(
		    regex_constants::error_range,
		    "Unexpected dash in bracket expression. For POSIX syntax, "
		    "a dash is not treated literally only when it is at "
		    "beginning or end.");
		}
	      __push_char('-');
	    }
	  else
	    {
	      if (_M_try_char())
		{
		  __matcher._M_make_range(__last_char.second, _M_value[0]);
		  __last_char.first = false;
		}
	      else if (_M_match_token(_ScannerT::_S_token_bracket_dash))
		{
		  __matcher._M_make_range(__last_char.second, '-');
		  __last_char.first = false;
		}
	      else
		{
		  if (_M_scanner._M_get_token()
		      != _ScannerT::_S_token_bracket_end)
		    __throw_regex_error(
		      regex_constants::error_range,
		      "Character is expected after a dash.");
		  __push_char('-');
		}
	    }
	}
