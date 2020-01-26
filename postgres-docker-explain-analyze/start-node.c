#define INSTR_TIME_SET_CURRENT_LAZY(t) \
	(INSTR_TIME_IS_ZERO(t) ? INSTR_TIME_SET_CURRENT(t), true : false)

#define INSTR_TIME_SET_CURRENT(t)	((void) clock_gettime(PG_INSTR_CLOCK, &(t)))

/* Entry to a plan node */
void
InstrStartNode(Instrumentation *instr)
{
	if (instr->need_timer &&
		!INSTR_TIME_SET_CURRENT_LAZY(instr->starttime))
		elog(ERROR, "InstrStartNode called twice in a row");

	/* save buffer usage totals at node entry, if needed */
	if (instr->need_bufusage)
		instr->bufusage_start = pgBufferUsage;
}
