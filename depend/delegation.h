#define ARG_TYPE_DOUBLE	2
// #define IS_ARG_DELEGATION_DOUBLE(x)	((ArgDelegationDouble *)(x))->type == ARG_TYPE_DOUBLE

typedef int ArgType;

typedef struct wrapper {
	ArgType type;
	Arg realArg[2];
} ArgDelegationDouble;

static void spreadlog(const char *msg) {
	sd_journal_send("MESSAGE=%s", msg, "PRIORITY=%i", LOG_INFO, NULL);
}

static Bool isArgDelegationDouble(const Arg *arg) {
	if (arg == NULL) {
		return False;
	}	
	ArgDelegationDouble *delegation = (ArgDelegationDouble *)(arg->v);
	return delegation->type == ARG_TYPE_DOUBLE;
}
