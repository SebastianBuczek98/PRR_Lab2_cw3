#include "procesy.h"


void
lab2_progr_1(char *host, char value[64])
{
	CLIENT *clnt;
	void  *result_1;
	message  getmsg_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, LAB2_PROGR, LAB2_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	
	strcpy(getmsg_1_arg.value, value);
	result_1 = getmsg_1(&getmsg_1_arg, clnt);
	if (result_1 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host = "localhost";
	while(1){
		char value[64];
		fgets(value, sizeof(value), stdin);
		lab2_progr_1 (host, value);
		fflush(stdin);
	}
	
	
exit (0);
}
