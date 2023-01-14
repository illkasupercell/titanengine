private delegate void XFXOPDO(byte cmd);

	private delegate void FXCBOPDO(byte cmd, ushort adr);

	private delegate void ALUALGORITHM(byte src);

	public delegate byte MEMREADER(ushort ADDR);

	public ulong Tact;

	public Registers regs = new Registers();

	public bool HALTED;

	public bool IFF1;

	public bool IFF2;

	public byte IM;

	public bool BlockINT;

	public OPFX FX;

	public OPXFX XFX;

	public bool INT;

	public bool NMI;

	public bool RST;

	public byte FreeBUS = byte.MaxValue;

	public OnRDMEM ReadMemory;

	public OnWRMEM WriteMemory;

	public OnRDPORT ReadPort;

	public OnWRPORT WritePort;

	public OnCALLBACK OnCycle;

	private XFXOPDO[] opTABLE;

	private XFXOPDO[] fxopTABLE;

	private XFXOPDO[] edopTABLE;

	private XFXOPDO[] cbopTABLE;

	private FXCBOPDO[] fxcbopTABLE;

	private static byte[] conds = new byte[4] { 64, 1, 4, 128 };

	private static ALUALGORITHM[] alualg;

	private ALUALGORITHM[] alulogic;

	private static readonly string[] DirectZ80Code = new string[256]
	{
		"NOP", "LD     BC,$W", "LD     (BC),A", "INC    BC", "INC    B", "DEC    B", "LD     B,$N", "RLCA", "EX     AF,AF'", "ADD    HL,BC",
		"LD     A,(BC)", "DEC    BC", "INC    C", "DEC    C", "LD     C,$N", "RRCA", "DJNZ   $DIS", "LD     DE,$W", "LD     (DE),A", "INC    DE",
		"INC    D", "DEC    D", "LD     D,$N", "RLA", "JR     $DIS", "ADD    HL,DE", "LD     A,(DE)", "DEC    DE", "INC    E", "DEC    E",
		"LD     E,$N", "RRA", "JR     NZ,$DIS", "LD     HL,$W", "LD     ($W),HL", "INC    HL", "INC    H", "DEC    H", "LD     H,$N", "DAA",
		"JR     Z,$DIS", "ADD    HL,HL", "LD     HL,($W)", "DEC    HL", "INC    L", "DEC    L", "LD     L,$N", "CPL", "JR     NC,$DIS", "LD     SP,$W",
		"LD     ($W),A", "INC    SP", "INC    (HL)", "DEC    (HL)", "LD     (HL),$N", "SCF", "JR     C,$DIS", "ADD    HL,SP", "LD     A,($W)", "DEC    SP",
		"INC    A", "DEC    A", "LD     A,$N", "CCF", "LD     B,B", "LD     B,C", "LD     B,D", "LD     B,E", "LD     B,H", "LD     B,L",
		"LD     B,(HL)", "LD     B,A", "LD     C,B", "LD     C,C", "LD     C,D", "LD     C,E", "LD     C,H", "LD     C,L", "LD     C,(HL)", "LD     C,A",
		"LD     D,B", "LD     D,C", "LD     D,D", "LD     D,E", "LD     D,H", "LD     D,L", "LD     D,(HL)", "LD     D,A", "LD     E,B", "LD     E,C",
		"LD     E,D", "LD     E,E", "LD     E,H", "LD     E,L", "LD     E,(HL)", "LD     E,A", "LD     H,B", "LD     H,C", "LD     H,D", "LD     H,E",
		"LD     H,H", "LD     H,L", "LD     H,(HL)", "LD     H,A", "LD     L,B", "LD     L,C", "LD     L,D", "LD     L,E", "LD     L,H", "LD     L,L",
		"LD     L,(HL)", "LD     L,A", "LD     (HL),B", "LD     (HL),C", "LD     (HL),D", "LD     (HL),E", "LD     (HL),H", "LD     (HL),L", "HALT", "LD     (HL),A",
		"LD     A,B", "LD     A,C", "LD     A,D", "LD     A,E", "LD     A,H", "LD     A,L", "LD     A,(HL)", "LD     A,A", "ADD    A,B", "ADD    A,C",
		"ADD    A,D", "ADD    A,E", "ADD    A,H", "ADD    A,L", "ADD    A,(HL)", "ADD    A,A", "ADC    A,B", "ADC    A,C", "ADC    A,D", "ADC    A,E",
		"ADC    A,H", "ADC    A,L", "ADC    A,(HL)", "ADC    A,A", "SUB    B", "SUB    C", "SUB    D", "SUB    E", "SUB    H", "SUB    L",
		"SUB    (HL)", "SUB    A", "SBC    A,B", "SBC    A,C", "SBC    A,D", "SBC    A,E", "SBC    A,H", "SBC    A,L", "SBC    A,(HL)", "SBC    A,A",
		"AND    B", "AND    C", "AND    D", "AND    E", "AND    H", "AND    L", "AND    (HL)", "AND    A", "XOR    B", "XOR    C",
		"XOR    D", "XOR    E", "XOR    H", "XOR    L", "XOR    (HL)", "XOR    A", "OR     B", "OR     C", "OR     D", "OR     E",
		"OR     H", "OR     L", "OR     (HL)", "OR     A", "CP     B", "CP     C", "CP     D", "CP     E", "CP     H", "CP     L",
		"CP     (HL)", "CP     A", "RET    NZ", "POP    BC", "JP     NZ,$W", "JP     $W", "CALL   NZ,$W", "PUSH   BC", "ADD    A,$N", "RST    $T",
		"RET    Z", "RET", "JP     Z,$W", "*CB", "CALL   Z,$W", "CALL   $W", "ADC    A,$N", "RST    $T", "RET    NC", "POP    DE",
		"JP     NC,$W", "OUT    ($N),A", "CALL   NC,$W", "PUSH   DE", "SUB    $N", "RST    $T", "RET    C", "EXX", "JP     C,$W", "IN     A,($N)",
		"CALL   C,$W", "*IX", "SBC    A,$N", "RST    $T", "RET    PO", "POP    HL", "JP     PO,$W", "EX     (SP),HL", "CALL   PO,$W", "PUSH   HL",
		"AND    $N", "RST    $T", "RET    PE", "JP     (HL)", "JP     PE,$W", "EX     DE,HL", "CALL   PE,$W", "*ED", "XOR    $N", "RST    $T",
		"RET    P", "POP    AF", "JP     P,$W", "DI", "CALL   P,$W", "PUSH   AF", "OR     $N", "RST    $T", "RET    M", "LD     SP,HL",
		"JP     M,$W", "EI", "CALL   M,$W", "*IY", "CP     $N", "RST    $T"
	};
