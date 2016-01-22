#include <stdio.h>

#include "mesh.h"
#include "initial.h"

int main(int argc, char **argv)
{
	mesh_t m;
	mesh_init(10, -1, 1, &m);
	double *un = mesh_alloc_nodes(&m);
	double *uc = mesh_alloc_cells(&m);
	initial_sin(0.0, &m, un, uc);
	mesh_save_cells(&m, uc, "cells.txt");
	mesh_save_nodes(&m, un, "nodes.txt");
	mesh_free(&m);
	return 0;
}
