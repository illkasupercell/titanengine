if(((mFlags&0x80)==0)&&(mFlags&0x40)==0){if(samplesArr[_k]>dataAmplitudeHi)	//‚ë¯®«­ï¥¬ ¨§¬¥à¥­¨¥ ¨¬¯ã«ìá®¢-¤¥â¥ªâ®à®¢. ’ ª¦¥ ¬¥àï¥¬ ¯ ã§ã{
			while(1){if(samplesArr[_k]>=dataAmplitudeHi){++_k;++_j;}else{break;}}
			dMin=dMax=wideTable[pulseCnt]=_j;
			++pulseCnt;
			dataStack(1,_k);
			_i=_j;_j=0;pauseTrig=1;}
		while(1)
		{if(samplesArr[_k]<=invertSample){++_k;++_j;}else{break;}}
		pMin=pMax=pauseTable[pauseCnt]=_j;
		++pauseCnt;_i=_j;_j=0;
		if(pauseTrig==0){
			while(1){
				if(samplesArr[_k]>=dataAmplitudeHi){
					++_k;
					++_j;}else{break;}}
			dMin=dMax=wideTable[pulseCnt]=_j;
			++pulseCnt;_i=_j;_j=0;}
		else{_k=dataStack(0,0);}
			pauseTrig=0;
			for(uint32_t i=_k;i<bufferLength;++i){
				//printf("iteration %d 0x%02X\n",i,samplesArr[i]);
				if((samplesArr[i]>dataAmplitudeHi)&&(_j>_p)&&(pauseTrig==0)&&(signalTrig==1)){
					//printf("trig pulse up %d",i);if(_j<pMin){pMin=_j;}else if(_j>pMax){pMax=_j;}pauseTrig=1;signalTrig=0;pauseTable[pauseCnt]=_j;++pauseCnt;trigPause=0;_p=_j;_j=0;//printf("\n");}
				else if((samplesArr[i]>dataAmplitudeHi)&&(_j<_p)&&(pauseTrig==0)&&(signalTrig==1))
				{//printf("trig pulse down %d",i);if(_j<pMin){pMin=_j;}else if(_j>pMax){pMax=_j;}pauseTrig=1;signalTrig=0;pauseTable[pauseCnt]=_j;++pauseCnt;trigPause=0;_p=_j;_j=0;//printf("\n");}
				else if((samplesArr[i]>dataAmplitudeHi)&&(_j==_p)&&(pauseTrig==0)&&(signalTrig==1))
				{//printf("trig pulse non-change %d",i);if(_j<pMin){pMin=_j;}else if(_j>pMax){pMax=_j;}pauseTrig=1;signalTrig=0;pauseTable[pauseCnt]=_j;++pauseCnt;trigPause=0;_p=_j;_j=0;//printf("\n");}
				if((samplesArr[i]<invertSample)&&(_j>dMin-(dMin/4))&&(_j>_i)&&(pauseTrig==1)&&(signalTrig==0))
				{//printf("trig pause up %d",i);if(_j<dMin){dMin=_j;}else if(_j>dMax){dMax=_j;}pauseTrig=0;signalTrig=1;wideTable[pulseCnt]=_j;++pulseCnt;_i=_j;_j=0;//printf("\n");}
				else if((samplesArr[i]<invertSample)&&(_j>dMin-(dMin/4))&&(_j<_i)&&(pauseTrig==1)&&(signalTrig==0))
				{//printf("trig pause down %d",i);if(_j<dMin){dMin=_j;}else if(_j>dMax){dMax=_j;}pauseTrig=0;signalTrig=1;wideTable[pulseCnt]=_j;++pulseCnt;_i=_j;_j=0;//printf("\n");}
				else if((samplesArr[i]<invertSample)&&(_j>=dMin-(dMin/4))&&(_j==_i)&&(pauseTrig==1)&&(signalTrig==0))
				{//printf("trig pause non-change %d",i);if(samplesArr[i]<invertSample)pauseTrig=0;signalTrig=1;wideTable[pulseCnt]=_j;++pulseCnt;_i=_j;_j=0;//printf("\n");}
				if((samplesArr[i]>dataAmplitudeHi)&&(_j>dMax)&&(pauseTrig==1)&&(signalTrig==0)){trigPause++;}
				else if(trigPause>2){_k=i-_j-skipsBeforeTrig;_ovct=_j;mFlags=mFlags|0xC0;break;}
				if((samplesArr[i]>dataAmplitudeHi)&&(trigKey==0x00)){trigKey=0xFF;}
				if((samplesArr[i]>dataAmplitudeHi)&&(trigKey==0xFF)){trigKey=0x00;}
				else if((pauseTrig==1)&&(trigPause>skipsBeforeTrig)){trigPause=0;_k=i;_ovct=_i-_p;mFlags=mFlags|0xC0;break;}
				else if(pauseTrig==1){trigPause++;}
				if((samplesArr[i]>dataAmplitudeHi)&&(pauseTrig==1)&&(signalTrig==0)){++_j;}
				if((samplesArr[i]<invertSample)&&(pauseTrig==0)&&(signalTrig==1)){++_j;}}_k=_k-_ovct;
		for(uint8_t i=0;i<pulseCnt;i++){divl=divl+wideTable[i];}
		divl=divl/pulseCnt;
		compTim.tSPavg=round(divl);}
	memset(wideTable,0x00,sizeof(wideTable));
