#include <i8080.h>
#include <groups/special.h>

/* Complement Accumulator - Affects: None */
void instr_cma(I8080_State *s) {
	DBG(s, "Instruction: cma\r\n");
	WRITE_REG(s, REG_A, ~(s->regs[REG_A]));
}

/* Complement Carry - Affects: C */
void instr_cmc(I8080_State *s) {
	DBG(s, "Instruction: cmc\r\n");
	COND_FLAG(s, !READ_FLAG(s, FLG_C), FLG_C);
}

/* Set Carry - Affects: C */
void instr_stc(I8080_State *s) {
	DBG(s, "Instruction: stc\r\n");
	COND_FLAG(s, 1, FLG_C);
}

/* I/O */
void instr_in(I8080_State *s) {
	uint8_t p = s->mem[s->pc + 1];
	DBG(s, "Instruction: in\r\n");
	if (s->devices[p]) {
		WRITE_REG(s, REG_A, (*s->devices[p]->in)(s));
	}
}

void instr_out(I8080_State *s) {
	uint8_t p = s->mem[s->pc + 1];
	DBG(s, "Instruction: out\r\n");
	if (s->devices[p]) {
		(*s->devices[p]->out)(s);
	}
}

/* Interrupt just NOPs */
void instr_ei(I8080_State *s) {
	DBG(s, "Instruction: ei\r\n");
}

void instr_di(I8080_State *s) {
	DBG(s, "Instruction: di\r\n");
}

/* No operation */
void instr_nop(I8080_State *s) {
	DBG(s, "Instruction: nop\r\n");
}

/* Halt */
void instr_hlt(I8080_State *s) {
	DBG(s, "Instruction: hlt\r\n");
	s->hlt = 1;
}

