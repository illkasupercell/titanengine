#define CONSTRUCT_JUMP(name_, opcode_) else if(mnemonic.name == #name_) \
	subcompileMnemonic(mnemonic, {\
	{constructDescription(CONSTANT), opcode_},\
	{constructDescription(LABEL), opcode_}})

	CONSTRUCT_JUMP(JMP, JMP);

	CONSTRUCT_JUMP(JE, JZ);
	CONSTRUCT_JUMP(JZ, JZ);

	CONSTRUCT_JUMP(JNZ, JNZ);
	CONSTRUCT_JUMP(JNE, JNZ);

	CONSTRUCT_JUMP(JG, JG);
	CONSTRUCT_JUMP(JNLE, JG);
	CONSTRUCT_JUMP(JNLZ, JG);

	CONSTRUCT_JUMP(JLE, JNG);
	CONSTRUCT_JUMP(JLZ, JNG);
	CONSTRUCT_JUMP(JNG, JNG);

	CONSTRUCT_JUMP(JGE, JGZ);
	CONSTRUCT_JUMP(JGZ, JGZ);
	CONSTRUCT_JUMP(JNL, JGZ);

	CONSTRUCT_JUMP(JNGZ, JL);
	CONSTRUCT_JUMP(JNGE, JL);
	CONSTRUCT_JUMP(JL  , JL);

	CONSTRUCT_JUMP(JB, JB);
	CONSTRUCT_JUMP(JNAE, JB);
	CONSTRUCT_JUMP(JNAZ, JB);
	CONSTRUCT_JUMP(JC, JB);

	CONSTRUCT_JUMP(JNB, JNB);
	CONSTRUCT_JUMP(JAE, JNB);
	CONSTRUCT_JUMP(JAZ, JNB);
	CONSTRUCT_JUMP(JNC, JNB);

	CONSTRUCT_JUMP(JBE, JBZ);
	CONSTRUCT_JUMP(JBZ, JBZ);
	CONSTRUCT_JUMP(JNA, JBZ);

	CONSTRUCT_JUMP(JA, JA);
	CONSTRUCT_JUMP(JNBE, JA);
	CONSTRUCT_JUMP(JNBZ, JA);

	CONSTRUCT_JUMP(CALL, CALL);
#undef CONSTRUCT_JUMP
