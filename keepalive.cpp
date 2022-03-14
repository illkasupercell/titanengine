if (op.size() == 1)
				{
					if (op[0].id == LexemID::REGISTER)
					{
						if (isSIBbase(registerName2registerId.at( std::get<std::string>(op[0].lexemas))))
							mnemonic.mnemonics.emplace_back(IndirectAddress{
								.base = Register(std::get<std::string>(op[0].lexemas))
								});
						else
							mnemonic.mnemonics.emplace_back(IndirectAddress{
								.index = Register(std::get<std::string>(op[0].lexemas))
								});
					}
					else if (op[0].id == LexemID::LABEL_USE)
						mnemonic.mnemonics.emplace_back(IndirectAddress{
							.disp = LabelUse(std::get<std::string>(op[0].lexemas))
							});
					else if (op[0].id == LexemID::NUMBER)
						mnemonic.mnemonics.emplace_back(IndirectAddress{
							.disp = Constant(std::get<int>(op[0].lexemas))
							});
				}
				else if (op.size() == 3)
				{
					if (const auto operation = std::get<std::string>(op[1].lexemas)[0]; operation == '+')
					{
						if (op[0].id == LexemID::REGISTER && op[2].id == LexemID::REGISTER)
						{
							if (isSIBbase(registerName2registerId.at(std::get<std::string>(op[0].lexemas))))
								mnemonic.mnemonics.emplace_back(IndirectAddress{
									.base = Register(std::get<std::string>(op[0].lexemas)),
									.index = Register(std::get<std::string>(op[2].lexemas))
									});
							else
								mnemonic.mnemonics.emplace_back(IndirectAddress{
									.base = Register(std::get<std::string>(op[2].lexemas)),
									.index = Register(std::get<std::string>(op[0].lexemas))
									});
						}
						else if (op[0].id == LexemID::REGISTER && op[2].id == LexemID::NUMBER)
						{
							if (isSIBbase(registerName2registerId.at(std::get<std::string>(op[0].lexemas))))
								mnemonic.mnemonics.emplace_back(IndirectAddress{
									.base = Register(std::get<std::string>(op[0].lexemas)),
									.disp = Constant(std::get<int>(op[2].lexemas))
									});
							else
								mnemonic.mnemonics.emplace_back(IndirectAddress{
									.index = Register(std::get<std::string>(op[0].lexemas)),
									.disp = Constant(std::get<int>(op[2].lexemas))
									});
						}
						else if (op[0].id == LexemID::REGISTER && op[2].id == LexemID::LABEL_USE)
						{
							if (isSIBbase(registerName2registerId.at(std::get<std::string>(op[0].lexemas))))
								mnemonic.mnemonics.emplace_back(IndirectAddress{
									.base = Register(std::get<std::string>(op[0].lexemas)),
									.disp = LabelUse(std::get<std::string>(op[2].lexemas))
									});
							else
								mnemonic.mnemonics.emplace_back(IndirectAddress{
								.index = Register(std::get<std::string>(op[0].lexemas)),
								.disp = LabelUse(std::get<std::string>(op[2].lexemas))
									});
						}
					}
					else if (operation == '*')
					{
						if (op[0].id == LexemID::NUMBER && op[2].id == LexemID::REGISTER)
							mnemonic.mnemonics.emplace_back(IndirectAddress{
								.base = Register(std::get<std::string>(op[2].lexemas)),
								.scale = static_cast<uint8_t>(std::get<int>(op[0].lexemas))
								});
					}
				}
				else if(op.size() == 5)
				{

					if (op[4].id == LexemID::REGISTER)
						mnemonic.mnemonics.emplace_back(IndirectAddress{
							.base  = Register(std::get<std::string>(op[4].lexemas)),
							.index = Register(std::get<std::string>(op[2].lexemas)),
							.scale = static_cast<uint8_t>(std::get<int>(op[0].lexemas))
							});
					else if (op[4].id == LexemID::NUMBER)
						mnemonic.mnemonics.emplace_back(IndirectAddress{
							.index = Register(std::get<std::string>(op[2].lexemas)),
							.scale = static_cast<uint8_t>(std::get<int>(op[0].lexemas)),
							.disp = Constant(std::get<int>(op[4].lexemas))
							});
					else if (op[4].id == LexemID::LABEL_USE)
						mnemonic.mnemonics.emplace_back(IndirectAddress{
							.index = Register(std::get<std::string>(op[2].lexemas)),
							.scale = static_cast<uint8_t>(std::get<int>(op[0].lexemas)),
							.disp = LabelUse(std::get<std::string>(op[4].lexemas))
							});
