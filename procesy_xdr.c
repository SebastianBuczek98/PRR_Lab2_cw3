/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "procesy.h"

bool_t
xdr_message (XDR *xdrs, message *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->value, 64,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}
