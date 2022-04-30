# Remove line numbers
s@^\d\d\d\d\d\d$@@ig;
s@^\d\d\d\d\d\d @@ig;

# Irrelevant directives
s@^(PAGE)$@* \1@ig;
s@^(CHN) @* \1 @ig;
s@^(REP) @* \1 @ig;
s@^(SKP) @* \1 @ig;
s@^(REL) @* \1 @ig;
s@^(REL)$@* \1@ig;
s@^(ENTRY)@* \1@ig;
s@^(EXTRN)@* \1@ig;
s@^(LST)@* \1@ig;

# Identify file boundaries
s@================================================================================================@@ig;
s@^FILE: \"SOS\.(.*)\.TEXT\"@FILE: SOS.S.\1@ig;

# Addressing mode MSB/LSB
s@\#\>@#@ig;
s@\#\<@/@ig;

# Equates, almost like opcodes -> .eq
s@^([A-Z0-9.]+)\ EQU @\1				.eq @ig;

# Title (ignored)
s@^SBTL @*				.TI @ig;

# DO/ELSE/FIN
s@^DO @				.do @ig;
s@^ELSE$@				.else@ig;
s@^ELSE (.*)$@				.else \1@ig;
s@^FIN$@				.fin@ig;

# Include
s@^INCLUDE @* INCLUDE @ig;

# Define Word DW -> .da
s@^DW @				.da @ig;
s@^([A-Z0-9.]+)\ DW @\1				.da @ig;

# Define Bytes DB/DFB -> .hs (mostly broken)
s@^DB @				.hs @ig;
s@^DFB @				.hs @ig;
s@^([A-Z0-9.]+)\ DB @\1				.hs @ig;
s@^([A-Z0-9.]+)\ DFB @\1				.hs @ig;

# Define Storage DS -> .BS
s@^([A-Z0-9.]+)\ DS @\1				.bs @ig;
s@^DS @				.bs @ig;

# ASCII strings ASC/CHR -> .AS
s@^([A-Z0-9.]+)\ ASC @\1				.as @ig;
s@^([A-Z0-9.]+)\ CHR @\1				.as @ig;
s@^ASC @				.as @ig;
s@^CHR @				.as @ig;

# Origin ORG -> .or
# S-C loses its sh!t when more than one apears, so morph them into .ph and .ep 
s@^DSECT@*				DSECT FIXME: find .or address@ig;
s@^ORG (.*$)@				.ph \1 FIXME: check if we need this@ig;
s@^DEND@				.ep @ig;

# MSB - need to be concerned if OFF is set (default is ON in S-C
s@^MSB @* FIXME - MSB @ig;

# Opcodes
s@^ADC$@				adc @ig;
s@^ADC(\ )@				adc @ig;
s@^([A-Z0-9.]+)\ ADC$@\1				adc@ig;
s@^([A-Z0-9.]+)\ ADC @\1				adc @ig;
s@^AND$@				and @ig;
s@^AND(\ )@				and @ig;
s@^([A-Z0-9.]+)\ AND$@\1				and@ig;
s@^([A-Z0-9.]+)\ AND @\1				and @ig;
s@^ASL A$@				asl@ig;
s@^ASL A\ (.*$)@				asl@ig;
s@^([A-Z0-9.]+)\ ASL A$@\1				asl@ig;
s@^([A-Z0-9.]+)\ ASL A\ (.*$)@\1				asl@ig;
s@^ASL$@				asl @ig;
s@^ASL(\ )@				asl @ig;
s@^([A-Z0-9.]+)\ ASL$@\1				asl@ig;
s@^([A-Z0-9.]+)\ ASL @\1				asl @ig;
s@^BCC$@				bcc @ig;
s@^BCC(\ )@				bcc @ig;
s@^([A-Z0-9.]+)\ BCC$@\1				bcc@ig;
s@^([A-Z0-9.]+)\ BCC @\1				bcc @ig;
s@^BCS$@				bcs @ig;
s@^BCS(\ )@				bcs @ig;
s@^([A-Z0-9.]+)\ BCS$@\1				bcs@ig;
s@^([A-Z0-9.]+)\ BCS @\1				bcs @ig;
s@^BEQ$@				beq @ig;
s@^BEQ(\ )@				beq @ig;
s@^([A-Z0-9.]+)\ BEQ$@\1				beq@ig;
s@^([A-Z0-9.]+)\ BEQ @\1				beq @ig;
s@^BIT$@				bit @ig;
s@^BIT(\ )@				bit @ig;
s@^([A-Z0-9.]+)\ BIT$@\1				bit@ig;
s@^([A-Z0-9.]+)\ BIT @\1				bit @ig;
s@^BMI$@				bmi @ig;
s@^BMI(\ )@				bmi @ig;
s@^([A-Z0-9.]+)\ BMI$@\1				bmi@ig;
s@^([A-Z0-9.]+)\ BMI @\1				bmi @ig;
s@^BNE$@				bne @ig;
s@^BNE(\ )@				bne @ig;
s@^([A-Z0-9.]+)\ BNE$@\1				bne@ig;
s@^([A-Z0-9.]+)\ BNE @\1				bne @ig;
s@^BPL$@				bpl @ig;
s@^BPL(\ )@				bpl @ig;
s@^([A-Z0-9.]+)\ BPL$@\1				bpl@ig;
s@^([A-Z0-9.]+)\ BPL @\1				bpl @ig;
s@^BRK$@				brk @ig;
s@^BRK(\ )@				brk @ig;
s@^([A-Z0-9.]+)\ BRK$@\1				brk@ig;
s@^([A-Z0-9.]+)\ BRK @\1				brk @ig;
s@^BVC$@				bvc @ig;
s@^BVC(\ )@				bvc @ig;
s@^([A-Z0-9.]+)\ BVC$@\1				bvc@ig;
s@^([A-Z0-9.]+)\ BVC @\1				bvc @ig;
s@^BVS$@				bvs @ig;
s@^BVS(\ )@				bvs @ig;
s@^([A-Z0-9.]+)\ BVS$@\1				bvs@ig;
s@^([A-Z0-9.]+)\ BVS @\1				bvs @ig;
s@^CLC$@				clc @ig;
s@^CLC(\ )@				clc @ig;
s@^([A-Z0-9.]+)\ CLC$@\1				clc@ig;
s@^([A-Z0-9.]+)\ CLC @\1				clc @ig;
s@^CLD$@				cld @ig;
s@^CLD(\ )@				cld @ig;
s@^([A-Z0-9.]+)\ CLD$@\1				cld@ig;
s@^([A-Z0-9.]+)\ CLD @\1				cld @ig;
s@^CLI$@				cli @ig;
s@^CLI(\ )@				cli @ig;
s@^([A-Z0-9.]+)\ CLI$@\1				cli@ig;
s@^([A-Z0-9.]+)\ CLI @\1				cli @ig;
s@^CLV$@				clv @ig;
s@^CLV(\ )@				clv @ig;
s@^([A-Z0-9.]+)\ CLV$@\1				clv@ig;
s@^([A-Z0-9.]+)\ CLV @\1				clv @ig;
s@^CMP$@				cmp @ig;
s@^CMP(\ )@				cmp @ig;
s@^([A-Z0-9.]+)\ CMP$@\1				cmp@ig;
s@^([A-Z0-9.]+)\ CMP @\1				cmp @ig;
s@^CPX$@				cpx @ig;
s@^CPX(\ )@				cpx @ig;
s@^([A-Z0-9.]+)\ CPX$@\1				cpx@ig;
s@^([A-Z0-9.]+)\ CPX @\1				cpx @ig;
s@^CPY$@				cpy @ig;
s@^CPY(\ )@				cpy @ig;
s@^([A-Z0-9.]+)\ CPY$@\1				cpy@ig;
s@^([A-Z0-9.]+)\ CPY @\1				cpy @ig;
s@^DEC$@				dec @ig;
s@^DEC(\ )@				dec @ig;
s@^([A-Z0-9.]+)\ DEC$@\1				dec@ig;
s@^([A-Z0-9.]+)\ DEC @\1				dec @ig;
s@^DEX$@				dex @ig;
s@^DEX(\ )@				dex @ig;
s@^([A-Z0-9.]+)\ DEX$@\1				dex@ig;
s@^([A-Z0-9.]+)\ DEX @\1				dex @ig;
s@^DEY$@				dey @ig;
s@^DEY(\ )@				dey @ig;
s@^([A-Z0-9.]+)\ DEY$@\1				dey@ig;
s@^([A-Z0-9.]+)\ DEY @\1				dey @ig;
s@^EOR$@				eor @ig;
s@^EOR(\ )@				eor @ig;
s@^([A-Z0-9.]+)\ EOR$@\1				eor@ig;
s@^([A-Z0-9.]+)\ EOR @\1				eor @ig;
s@^INC$@				inc @ig;
s@^INC(\ )@				inc @ig;
s@^([A-Z0-9.]+)\ INC$@\1				inc@ig;
s@^([A-Z0-9.]+)\ INC @\1				inc @ig;
s@^INX$@				inx @ig;
s@^INX(\ )@				inx @ig;
s@^([A-Z0-9.]+)\ INX$@\1				inx@ig;
s@^([A-Z0-9.]+)\ INX @\1				inx @ig;
s@^INY$@				iny @ig;
s@^INY(\ )@				iny @ig;
s@^([A-Z0-9.]+)\ INY$@\1				iny@ig;
s@^([A-Z0-9.]+)\ INY @\1				iny @ig;
s@^JMP$@				jmp @ig;
s@^JMP(\ )@				jmp @ig;
s@^([A-Z0-9.]+)\ JMP$@\1				jmp@ig;
s@^([A-Z0-9.]+)\ JMP @\1				jmp @ig;
s@^JSR$@				jsr @ig;
s@^JSR(\ )@				jsr @ig;
s@^([A-Z0-9.]+)\ JSR$@\1				jsr@ig;
s@^([A-Z0-9.]+)\ JSR @\1				jsr @ig;
s@^LDA$@				lda @ig;
s@^LDA(\ )@				lda @ig;
s@^([A-Z0-9.]+)\ LDA$@\1				lda@ig;
s@^([A-Z0-9.]+)\ LDA @\1				lda @ig;
s@^LDX$@				ldx @ig;
s@^LDX(\ )@				ldx @ig;
s@^([A-Z0-9.]+)\ LDX$@\1				ldx@ig;
s@^([A-Z0-9.]+)\ LDX @\1				ldx @ig;
s@^LDY$@				ldy @ig;
s@^LDY(\ )@				ldy @ig;
s@^([A-Z0-9.]+)\ LDY$@\1				ldy@ig;
s@^([A-Z0-9.]+)\ LDY @\1				ldy @ig;
s@^LSR A$@				lsr@ig;
s@^LSR A\ (.*$)@				lsr@ig;
s@^([A-Z0-9.]+)\ LSR A$@\1				lsr@ig;
s@^([A-Z0-9.]+)\ LSR A\ (.*$)@\1				lsr@ig;
s@^LSR$@				lsr @ig;
s@^LSR(\ )@				lsr @ig;
s@^([A-Z0-9.]+)\ LSR$@\1				lsr@ig;
s@^([A-Z0-9.]+)\ LSR @\1				lsr @ig;
s@^NOP$@				nop @ig;
s@^NOP(\ )@				nop @ig;
s@^([A-Z0-9.]+)\ NOP$@\1				nop@ig;
s@^([A-Z0-9.]+)\ NOP @\1				nop @ig;
s@^ORA$@				ora @ig;
s@^ORA(\ )@				ora @ig;
s@^([A-Z0-9.]+)\ ORA$@\1				ora@ig;
s@^([A-Z0-9.]+)\ ORA @\1				ora @ig;
s@^PHA$@				pha @ig;
s@^PHA(\ )@				pha @ig;
s@^([A-Z0-9.]+)\ PHA$@\1				pha@ig;
s@^([A-Z0-9.]+)\ PHA @\1				pha @ig;
s@^PHP$@				php @ig;
s@^PHP(\ )@				php @ig;
s@^([A-Z0-9.]+)\ PHP$@\1				php@ig;
s@^([A-Z0-9.]+)\ PHP @\1				php @ig;
s@^PLA$@				pla @ig;
s@^PLA(\ )@				pla @ig;
s@^([A-Z0-9.]+)\ PLA$@\1				pla@ig;
s@^([A-Z0-9.]+)\ PLA @\1				pla @ig;
s@^PLP$@				plp @ig;
s@^PLP(\ )@				plp @ig;
s@^([A-Z0-9.]+)\ PLP$@\1				plp@ig;
s@^([A-Z0-9.]+)\ PLP @\1				plp @ig;
s@^ROL A$@				rol@ig;
s@^ROL A\ (.*$)@				rol@ig;
s@^([A-Z0-9.]+)\ ROL A$@\1				rol@ig;
s@^([A-Z0-9.]+)\ ROL A\ (.*$)@\1				rol@ig;
s@^ROL$@				rol @ig;
s@^ROL(\ )@				rol @ig;
s@^([A-Z0-9.]+)\ ROL$@\1				rol@ig;
s@^([A-Z0-9.]+)\ ROL @\1				rol @ig;
s@^ROR A$@				ror@ig;
s@^ROR A\ (.*$)@				ror@ig;
s@^([A-Z0-9.]+)\ ROR A$@\1				ror@ig;
s@^([A-Z0-9.]+)\ ROR A\ (.*$)@\1				ror@ig;
s@^ROR$@				ror @ig;
s@^ROR(\ )@				ror @ig;
s@^([A-Z0-9.]+)\ ROR$@\1				ror@ig;
s@^([A-Z0-9.]+)\ ROR @\1				ror @ig;
s@^RTI$@				rti @ig;
s@^RTI(\ )@				rti @ig;
s@^([A-Z0-9.]+)\ RTI$@\1				rti@ig;
s@^([A-Z0-9.]+)\ RTI @\1				rti @ig;
s@^RTS$@				rts @ig;
s@^RTS(\ )@				rts @ig;
s@^([A-Z0-9.]+)\ RTS$@\1				rts@ig;
s@^([A-Z0-9.]+)\ RTS @\1				rts @ig;
s@^SBC$@				sbc @ig;
s@^SBC(\ )@				sbc @ig;
s@^([A-Z0-9.]+)\ SBC$@\1				sbc@ig;
s@^([A-Z0-9.]+)\ SBC @\1				sbc @ig;
s@^SEC$@				sec @ig;
s@^SEC(\ )@				sec @ig;
s@^([A-Z0-9.]+)\ SEC$@\1				sec@ig;
s@^([A-Z0-9.]+)\ SEC @\1				sec @ig;
s@^SED$@				sed @ig;
s@^SED(\ )@				sed @ig;
s@^([A-Z0-9.]+)\ SED$@\1				sed@ig;
s@^([A-Z0-9.]+)\ SED @\1				sed @ig;
s@^SEI$@				sei @ig;
s@^SEI(\ )@				sei @ig;
s@^([A-Z0-9.]+)\ SEI$@\1				sei@ig;
s@^([A-Z0-9.]+)\ SEI @\1				sei @ig;
s@^STA$@				sta @ig;
s@^STA(\ )@				sta @ig;
s@^([A-Z0-9.]+)\ STA$@\1				sta@ig;
s@^([A-Z0-9.]+)\ STA @\1				sta @ig;
s@^STX$@				stx @ig;
s@^STX(\ )@				stx @ig;
s@^([A-Z0-9.]+)\ STX$@\1				stx@ig;
s@^([A-Z0-9.]+)\ STX @\1				stx @ig;
s@^STY$@				sty @ig;
s@^STY(\ )@				sty @ig;
s@^([A-Z0-9.]+)\ STY$@\1				sty@ig;
s@^([A-Z0-9.]+)\ STY @\1				sty @ig;
s@^TAX$@				tax @ig;
s@^TAX(\ )@				tax @ig;
s@^([A-Z0-9.]+)\ TAX$@\1				tax@ig;
s@^([A-Z0-9.]+)\ TAX @\1				tax @ig;
s@^TAY$@				tay @ig;
s@^TAY(\ )@				tay @ig;
s@^([A-Z0-9.]+)\ TAY$@\1				tay@ig;
s@^([A-Z0-9.]+)\ TAY @\1				tay @ig;
s@^TSX$@				tsx @ig;
s@^TSX(\ )@				tsx @ig;
s@^([A-Z0-9.]+)\ TSX$@\1				tsx@ig;
s@^([A-Z0-9.]+)\ TSX @\1				tsx @ig;
s@^TXA$@				txa @ig;
s@^TXA(\ )@				txa @ig;
s@^([A-Z0-9.]+)\ TXA$@\1				txa@ig;
s@^([A-Z0-9.]+)\ TXA @\1				txa @ig;
s@^TXS$@				txs @ig;
s@^TXS(\ )@				txs @ig;
s@^([A-Z0-9.]+)\ TXS$@\1				txs@ig;
s@^([A-Z0-9.]+)\ TXS @\1				txs @ig;
s@^TYA$@				tya @ig;
s@^TYA(\ )@				tya @ig;
s@^([A-Z0-9.]+)\ TYA$@\1				tya@ig;
s@^([A-Z0-9.]+)\ TYA @\1				tya @ig;

# Repair tabs
s@^([A-Z0-9.]{2,7}	)	@\1@ig;
s@^([A-Z0-9.]{8,12})\t\t\t@\1\t@ig;
