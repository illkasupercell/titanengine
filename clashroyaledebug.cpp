#define OPCODEFORMAT_CASE(opcode, format) case opcode: return format; break
inline OpcodeFormat getOpcodeFormat(Opcode opcode)
{
	switch (opcode)
	{
		OPCODEFORMAT_CASE(NOP		, OPCODE);
		OPCODEFORMAT_CASE(MOV_RR	, OPCODE_RR);
		OPCODEFORMAT_CASE(MOV_RC	, OPCODE_RC);
		OPCODEFORMAT_CASE(MOV_RM	, OPCODE_RM);
		OPCODEFORMAT_CASE(MOV_MR	, OPCODE_MR);
		OPCODEFORMAT_CASE(MOV_MC	, OPCODE_MC);
		OPCODEFORMAT_CASE(MOV_MM	, OPCODE_MM);
		OPCODEFORMAT_CASE(ADD		, OPCODE_RR);
		OPCODEFORMAT_CASE(SUB		, OPCODE_RR);
		OPCODEFORMAT_CASE(ADD_C	, OPCODE_RC);
		OPCODEFORMAT_CASE(SUB_C		, OPCODE_RC);
		OPCODEFORMAT_CASE(MUL		, OPCODE_RR);
		OPCODEFORMAT_CASE(DIV		, OPCODE_RR);
		OPCODEFORMAT_CASE(MUL_C	, OPCODE_RC);
		OPCODEFORMAT_CASE(DIV_C		, OPCODE_RC);
		OPCODEFORMAT_CASE(LEA		, OPCODE_RM);
		OPCODEFORMAT_CASE(INC		, OPCODE_R);
		OPCODEFORMAT_CASE(DEC		, OPCODE_R);
		OPCODEFORMAT_CASE(INT		, OPCODE_C8);
		OPCODEFORMAT_CASE(CMP_RC	, OPCODE_RC);
		OPCODEFORMAT_CASE(JMP		, OPCODE_C);
		OPCODEFORMAT_CASE(JZ		        , OPCODE_C);
		OPCODEFORMAT_CASE(JNZ		, OPCODE_C);
		OPCODEFORMAT_CASE(JG		, OPCODE_C);
		OPCODEFORMAT_CASE(JNG		, OPCODE_C);
		OPCODEFORMAT_CASE(JGZ		, OPCODE_C);
		OPCODEFORMAT_CASE(JL		        , OPCODE_C);
		OPCODEFORMAT_CASE(CALL		, OPCODE_C);
		OPCODEFORMAT_CASE(PUSH_R	, OPCODE_R);
		OPCODEFORMAT_CASE(PUSH_C	, OPCODE_C);
		OPCODEFORMAT_CASE(PUSH_C8	, OPCODE_C8);
		OPCODEFORMAT_CASE(POP_R	, OPCODE_R);
		OPCODEFORMAT_CASE(POP		, OPCODE);
		OPCODEFORMAT_CASE(POP8		, OPCODE);
		OPCODEFORMAT_CASE(POP_M8	, OPCODE_M);
		OPCODEFORMAT_CASE(POP_M16	, OPCODE_M);
		OPCODEFORMAT_CASE(OUT_M8	, OPCODE_MC);
		OPCODEFORMAT_CASE(OUT_M16	, OPCODE_MC);
		OPCODEFORMAT_CASE(OUT_C8	, OPCODE_CC8);
		OPCODEFORMAT_CASE(OUT_C16	, OPCODE_CC);
		OPCODEFORMAT_CASE(OUT_R	, OPCODE_RC);
		OPCODEFORMAT_CASE(IN_R		, OPCODE_RC);
		OPCODEFORMAT_CASE(IN_M8	, OPCODE_MC);
		OPCODEFORMAT_CASE(IN_M16	, OPCODE_MC);
		OPCODEFORMAT_CASE(RET		, OPCODE);

	default: return (OpcodeFormat)0xFF; break;
	}
}
#undef OPCODEFORMAT_CASE
