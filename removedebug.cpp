rule_t block_r = ch_p('{') >> *(~ch_p('}') | (~ch_p('{') >> block_r));
	rule_t bin_r = str_p("0b") >> bin_p[assign(m)];
	rule_t hex_r = str_p("0x") >> hex_p[assign(m)];
	rule_t dec_r = uint_p[assign(m)];
  rule_t id_r = alpha_p >> *(alnum_p | ch_p('_') | ch_p('.'));
  rule_t string_r = ch_p('"') >> (*(~ch_p('"')))[assign(s)] >> ch_p('"');
  rule_t channel_r = str_p("channel") >> *(space_p) >> id_r[assign(s)][assign_a(ch.name,s)][push_back_a(lstJSVars_,s)] >> *(space_p) >> ch_p('{') >>
    *(space_p 
			| (str_p("mode") >> *(space_p) >> ch_p('=') >> *(space_p) >> 
        	(str_p("in")[assign_a(ch.mode,(int)channel::IN)] | str_p("out")[assign_a(ch.mode,(int)channel::OUT)]) >> *(space_p) >> ch_p(';'))
			| (str_p("number") >> *(space_p) >> ch_p('=') >> *(space_p) >> int_p[assign(ch.number)] >> *(space_p) >> ch_p(';')) 
			| (str_p("channel") >> *(space_p) >> ch_p('=') >> *(space_p) >> int_p[assign(ch.ch)] >> *(space_p) >> ch_p(';')) 
			| (str_p("gain") >> *(space_p) >> ch_p('=') >> *(space_p) >> int_p[assign(ch.gain)] >> *(space_p) >> ch_p(';')) 
			| (str_p("type") >> *(space_p) >> ch_p('=') >> *(space_p) >>
					(str_p("analog")[assign_a(ch.type,(int)channel::ANALOG)] | str_p("discrete")[assign_a(ch.type,(int)channel::DISCRETE)]) >> *(space_p) >> ch_p(';'))
			| (str_p("mask") >> *(space_p) >> ch_p('=') >> *(space_p) >> 
					(bin_r[assign_a(ch.mask,m)] | hex_r[assign_a(ch.mask,m)] | dec_r[assign_a(ch.mask,m)]) >> *(space_p) >> ch_p(';'))
    ) >>
    ch_p('}') >> *(space_p) >> ch_p(';'); 
  rule_t device_r = str_p("device_info") >> *(space_p) >> id_r[assign(dev_info_.name)] >> *(space_p) >> ch_p('{') >>
    *(space_p | 
      (str_p("device") >> *(space_p) >> ch_p('=') >> *(space_p) >> string_r[assign_a(dev_info_.dev,s)] >> *(space_p) >> ch_p(';')) | 
      (str_p("blocking") >> *(space_p) >> ch_p('=') >> *(space_p) >> 
        (str_p("true")[assign_a(dev_info_.blocking,true)] | str_p("false")[assign_a(dev_info_.blocking,false)]) >> *(space_p) >> ch_p(';')) |
      (str_p("freq_ch") >> *(space_p) >> ch_p('=') >> *(space_p) >> int_p[assign(dev_info_.freq_ch)] >> *(space_p) >> ch_p(';')) | 
      (str_p("freq_sel_ch") >> *(space_p) >> ch_p('=') >> *(space_p) >> int_p[assign(dev_info_.freq_sel_ch)] >> *(space_p) >> ch_p(';')) |
      (str_p("speed") >> *(space_p) >> ch_p('=') >> *(space_p) >> int_p[assign(dev_info_.speed)] >> *(space_p) >> ch_p(';')) | 
      channel_r[assign_a(v,ch)][push_back_a(lstChannels_,v)]
    ) >>
    ch_p('}') >> *(space_p) >> ch_p(';');
  rule_t var_r = (str_p("var") >> *(space_p) >> id_r[assign(s)][push_back_a(lstJSVars_,s)] >>*(~ch_p(';')) >> ch_p(';'))[assign(s)][push_back_a(lstVars,s)];
  rule_t function_r = str_p("function") >> *(~ch_p('`'));
	//rule_t function_r = str_p("function") >> *(~ch_p('{')) >> block_r;
  rule_t script_r = str_p("script") >> *(space_p) >> ch_p('{') >>
    *(space_p |
      var_r[assign(s)][push_back_a(lstJSVars_,s)] |
      (function_r[assign(s)][push_back_a(lstFunc,s)] >> *(space_p) >> ch_p('`'))
    ) >>
    ch_p('}') >> *(space_p) >> ch_p(';');
