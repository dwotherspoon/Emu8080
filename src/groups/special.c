#include <i8080.h>
#include <groups/special.h>

/* Complement Accumulator */
void instr_cma(I8080_State *s) {
	s->regs[REG_A] = ~(s->regs[REG_A]);
	s->pc++;
}

/* Complement Carry */
void instr_cmc(I8080_State *s) {
	s->flags ^= FLG_C;
	s->pc++;
}

/* Set Carry */
void instr_stc(I8080_State *s) {
	s->flags |= FLG_C;
	s->pc++;
}

/* I/O */
void instr_in(I8080_State *s) {
	uint8_t p = s->mem[++s->pc];
	if (s->devices[p]) {
		s->regs[REG_A] = (*s->devices[p]->in)(s);
	}
	s->pc++;
}

void instr_out(I8080_State *s) {
	uint8_t p = s->mem[++s->pc];
	if (s->devices[p]) {
		(*s->devices[p]->out)(s);
	}
	s->pc++;
}

/* Interrupt just NOPs */
void instr_ei(I8080_State *s) {
	s->pc++;
}

void instr_di(I8080_State *s) {
	s->pc++;
}

/* No operation */
void instr_nop(I8080_State *s) {
	s->pc++;
}

/* Halt */
void instr_hlt(I8080_State *s) {
	s->hlt = 1;
}
