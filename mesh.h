#ifndef GCD_GRID_H
#define GCD_GRID_H

#include <stdlib.h>
#include <assert.h>

/**
 * Struct for regular mesh.
 */
typedef struct {
	/* Number of nodes. */
	int size;
	/* Grid spacing. */
	double h;
	/* Coords of left node. */
	double x0;
	/* Array of nodes coords (size). */
	double *xnodes;
	/* Array of cells coords (size-1). */
	double *xcells;
} mesh_t;

/**
 * Init regular mesh with constant step from a to b with ncells cells.
 */
void mesh_init(const int ncells, const double a, const double b, mesh_t *m)
{
	assert(b > a);
	assert(ncells > 0);
	int i;
	m->xcells = (double*)malloc(sizeof(double) * ncells);
	m->xnodes = (double*)malloc(sizeof(double) * (ncells + 1));
	m->size = ncells + 1;
	const double h = (b - a) / ncells;
	m->h = h;
	m->x0 = a;
	for (i = 0; i < ncells + 1; i++) {
		m->xnodes[i] = a + h * i;
	}
	for (i = 0; i < ncells; i++) {
		m->xcells[i] = m->xnodes[i] + h / 2.0;
	}
}

void mesh_free(mesh_t *m)
{
	m->size = 0;
	free(m->xnodes);
	free(m->xcells);
}

void mesh_save_data(const int n, const double *x, const double *u, const char *path)
{
	FILE *f;
	f = fopen(path, "w");
	int i;
	for (i = 0; i < n; i++) {
		fprintf(f, "%f %f\n", x[i], u[i]);
	}
	fclose(f);
}

void mesh_save_cells(const mesh_t *m, const double *cells, const char *path)
{
	mesh_save_data(m->size - 1, m->xcells, cells, path);
}

void mesh_save_nodes(const mesh_t *m, const double *nodes, const char *path)
{
	mesh_save_data(m->size, m->xnodes, nodes, path);
}

double *mesh_alloc_cells(const mesh_t *m)
{
	return (double*)calloc(m->size-1, sizeof(double));
}

double *mesh_alloc_nodes(const mesh_t *m)
{
	return (double*)calloc(m->size, sizeof(double));
}


#endif // GCD_GRID_H
