/*
 * ExecProcNode wrapper that performs instrumentation calls.  By keeping
 * this a separate function, we avoid overhead in the normal case where
 * no instrumentation is wanted.
 */
static TupleTableSlot *
ExecProcNodeInstr(PlanState *node)
{
	TupleTableSlot *result;

	InstrStartNode(node->instrument);

	result = node->ExecProcNodeReal(node);

	InstrStopNode(node->instrument, TupIsNull(result) ? 0.0 : 1.0);

	return result;
}
