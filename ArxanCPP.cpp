(((UU)M[(((UU)c&255)<<16)+(UU)((U)(a+2))])<<8)+\
											((UU)M[(((UU)c&255)<<16)+(UU)((U)(a+3))])\
											)
#define write_byte(v,d)M[d]=v;
#define write_2bytes(v,d)	M[d]=					(v)>>8;\
							M[((d)+1)&0xFFffFF]=	(v)&255;
#define write_4bytes(v,d)	M[((d))&0xFFffFF]=		(v)>>24;\
							M[((d)+1)&0xFFffFF]=	(v)>>16;\
							M[((d)+2)&0xFFffFF]=	(v)>>8;\
							M[((d)+3)&0xFFffFF]=	(v)&255;
#define D ;switch(CONSUME_BYTE){k 0:goto G_HALT;k 1:goto G_LDA;k 2:goto G_LA;k 3:goto G_LDB;k 4:goto G_LB;k 5:goto G_SC;k 6:goto G_STA;k 7:goto G_STB;\
k 8:goto G_ADD;k 9:goto G_SUB;k 10:goto G_MUL;k 11:goto G_DIV;k 12:goto G_MOD;k 13:goto G_CMP;k 14:goto G_JMPIFEQ;k 15:goto G_JMPIFNEQ;\
k 16:goto G_GETCHAR;k 17:goto G_PUTCHAR;k 18:goto G_AND;k 19:goto G_OR;k 20:goto G_XOR;k 21:goto G_LSHIFT;k 22:goto G_RSHIFT;k 23:goto G_ILDA;\
k 24:goto G_ILDB;k 25:goto G_CAB;k 26:goto G_AB;k 27:goto G_BA;k 28:goto G_ALC;k 29:goto G_AHC;k 30:goto G_NOP;k 31:goto G_CBA;\
k 32:goto G_LLA;k 33:goto G_ILLDA;k 34:goto G_LLB;k 35:goto G_ILLDB;k 36:goto G_ILLDAA;k 37:goto G_ILLDBB;k 38:goto G_ILLDAB;k 39:goto G_ILLDBA;\
k 40:goto G_CA;k 41:goto G_CB;k 42:goto G_AC;k 43:goto G_BC;k 44:goto G_ISTA;k 45:goto G_ISTB;k 46:goto G_ISTLA;k 47:goto G_ISTLB;\
k 48:goto G_JMP;k 49:goto G_STLA;k 50:goto G_STLB;k 51:goto G_STC;k 52:goto G_PUSH;k 53:goto G_POP;k 54:goto G_PUSHA;k 55:goto G_POPA;\
k 56:goto G_ASTP;k 57:goto G_BSTP;k 58:goto G_COMPL;k 59:goto G_CPC;k 60:goto G_CALL;k 61:goto G_RET;k 62:goto G_FARILLDA;k 63:goto G_FARISTLA;\
k 64:goto G_FARILLDB;k 65:goto G_FARISTLB;k 66:goto G_FARPAGEL;k 67:goto G_FARPAGEST;k 68:goto G_LFARPC;k 69:goto G_FARCALL;k 70:goto G_FARRET;k 71:goto G_FARILDA;\
k 72:goto G_FARISTA;k 73:goto G_FARILDB;k 74:goto G_FARISTB;\
k 75:goto TB;k 76:goto TC;k 77:goto TD;k 78:goto TE;k 79:goto TF;\
k 80:goto U0;k 81:goto U1;k 82:goto U2;k 83:goto U3;k 84:goto U4;k 85:goto U5;k 86:goto U6;k 87:goto U7;\
k 88:goto U8;k 89:goto U9;k 90:goto UA;k 91:\
goto G_ALPUSH;k 92:goto G_BLPUSH;k 93:goto G_CPUSH;k 94:goto G_APUSH;k 95:goto G_BPUSH;\
k 96:goto G_ALPOP;k 97:goto G_BLPOP;k 98:goto G_CPOP;k 99:goto G_APOP;k 100:goto G_BPOP;\
k 101:goto G_INTERRUPT;k 102:goto G_CLOCK;\
k 103:goto G_ARX0;\
k 104:goto G_BRX0;k 105:goto V9;k 106:goto VA;k 107:goto VB;k 108:goto VC;k 109:goto VD;k 110:goto VE;k 111:goto VF;\
k 112:goto W0;k 113:goto W1;k 114:goto W2;k 115:goto W3;k 116:goto W4;k 117:goto W5;k 118:goto W6;k 119:goto W7;\
k 120:goto W8;k 121:goto W9;k 122:goto WA;k 123:goto WB;k 124:goto WC;k 125:goto WD;k 126:goto WE;\
k 127:goto WF;\
k 128:goto X0;k 129:goto X1;k 130:goto X2;k 131:goto X3;k 132:goto X4;\
k 133:goto X5;k 134:goto X6;k 135:goto X7;k 136:goto X8;k 137:goto X9;\
k 138:goto XA;k 139:goto XB;k 140:goto XC;k 141:goto XD;k 142:goto XE;k 143:goto XF;\
k 144:goto Y0;k 145:goto Y1;k 146:goto Y2;k 147:goto Y3;\
k 148:goto Y4;k 149:goto Y5;k 150:goto Y6;k 151:goto Y7;k 152:goto Y8;k 153:goto Y9;\
k 154:goto YA;k 155:goto YB;k 156:goto YC;k 157:goto YD;\
k 158:goto YE;k 159:goto YF;\
k 160:goto Z0;k 161:goto Z1;k 162:goto Z2;k 163:goto Z3;\
k 164:goto Z4;k 165:goto Z5;k 166:goto Z6;k 167:goto Z7;\
k 168:goto Z8;k 169:goto Z9;k 170:goto ZA;\
k 171:k 172:k 173:k 174:k 175:k 176:k 177:\
k 178:k 179:k 180:k 181:k 182:k 183:k 184:k 185:k 186:k 187:\
k 188:k 189:k 190:k 191:k 192:k 193:k 194:k 195:k 196:k 197:\
k 198:k 199:k 200:k 201:k 202:k 203:k 204:k 205:k 206:k 207:\
k 208:k 209:k 210:k 211:k 212:k 213:k 214:k 215:k 216:k 217:\
k 218:k 219:k 220:k 221:k 222:k 223:k 224:k 225:k 226:k 227:\
k 228:k 229:k 230:k 231:k 232:k 233:k 234:k 235:k 236:k 237:\
k 238:k 239:k 240:k 241:k 242:k 243:k 244:k 245:k 246:k 247:\
k 248:k 249:k 250:k 251:k 252:k 253:k 254:k 255:goto G_NOP;}
int e(){
register u program_counter_region=0;register U a=0,b=0,c=0,program_counter=0,stack_pointer=0; 
register UU RX0=0,RX1=0,RX2=0,RX3=0;R=0;di();
G_NOP:D
G_HALT:dcl();return 0;
G_AND:a&=b;D
G_OR:a|=b;D
G_XOR:a^=b;D
G_GETCHAR:a=gch()D
G_PUTCHAR:pch(a)D
G_LSHIFT:a<<=b&15;D
G_RSHIFT:a>>=b&15;D
G_ILDA:a=r(c)D
G_ILDB:b=r(c)D
G_CAB:c=((a&255)<<8)+(b&255)D
G_AB:a=b;D
G_BA:b=a;D
G_ALC:a=c&0xff;D
G_AHC:a=(c>>8)&255;D
G_CBA:c=((b&255)<<8)+(a&255)D
G_LLA:a=CONSUME_TWO_BYTES;D
G_ILLDA:a=Z_READ_TWO_BYTES_THROUGH_C;D
