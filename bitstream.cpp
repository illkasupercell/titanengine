double zuida(std::vector<double> vec) {
	std::vector<double> temp;
	for(int i = 0; i < vec.size(); i++)
		temp.push_back(vec[i]);
notend:
	if(temp.size() > 0) {
		if(temp.size() < 2) {
			double tmp = *(&temp[0]);
			return tmp;
		}
		else if(temp.size() >= 2) {
			double mini = temp[0];
			int ind = 0;
			for(int i = 0; i < temp.size(); i++)
				if(temp[i] < mini) {
					mini = temp[i];
					ind = i;
				}
			temp.erase(temp.begin() + ind);
			goto notend;
		}
	}
}
#if CHECK_GATE
#if TIME_STAT
    strcpy(func_curr0,func_curr); strcpy(func_curr,"cp_input 23");
#endif
#if APPL==1||APPL==2
    cycle_gate1();
#elif (!FDRAM_STAT0)&&(!FDRAM_STAT1)
    cycle_gate();
#endif
#endif
#if DB
    for(j = 0; j <= ichn; j++)
    if(pserv_chn[j]->chnst == READING || pserv_chn[j]->chnst == WRITING) {
#if FDRAM_DIN0
    buffer_fdram(pserv_chn[j]->update_iav, pserv_chn[j]->update_iav);
#endif
#if FDRAM_DIN2&&CBSIZE_IAV
    cbuffer_fdram(pserv_chn[j]->circle_av);
#endif
#endif /* End of #if DB */
    for(i=0; i < n_input_av; i++
#if CHECK_GATE
#if TIME_STAT
    ,strcpy(func_curr0,func_curr), strcpy(func_curr,"cp_input 24")
#endif
#if APPL==1||APPL==2
    ,cycle_gate1()
#elif (!FDRAM_STAT0)&&(!FDRAM_STAT1)
    ,cycle_gate()
#endif
#endif
