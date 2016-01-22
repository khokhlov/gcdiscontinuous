#ifndef GCD_INITIAL_H
#define GCD_INITIAL_H

#include <math.h>

#include "mesh.h"

void initial_sin(const int stride, const mesh_t *m, double *nodes, double *cells)
{
	int i;
	if (nodes != NULL) {
		for (i = 0; i < m->size; i++) {
			double x = m->xnodes[i] - stride;
			nodes[i] = sin(M_PI * x);
		}
	}
	if (cells != NULL) {
		for (i = 0; i < m->size-1; i++) {
			double x = m->xcells[i] - stride;
			cells[i] = sin(M_PI * x);
		}
	}
}

#endif // GCD_INITIAL_H

