# @TEST-EXEC: bro %INPUT
# @TEST-EXEC: TEST_DIFF_CANONIFIER=$SCRIPTS/diff-remove-abspath btest-diff .stderr
# @TEST-EXEC: TEST_DIFF_CANONIFIER=$SCRIPTS/diff-remove-abspath btest-diff reporter.log

redef Reporter::warnings_to_stderr = F;
redef Reporter::errors_to_stderr = F;

global test: table[count] of string = {};

event bro_init()
	{
	print test[3];
	}