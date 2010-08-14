#include <cloog/cloog.h>

#define ALLOC(type) (type*)malloc(sizeof(type))

CloogStride *cloog_stride_alloc(cloog_int_t stride, cloog_int_t offset)
{
	CloogStride *s;

	s = ALLOC(CloogStride);
	if (!s)
		cloog_die("memory overflow.\n");

	s->references = 1;
	cloog_int_init(s->stride);
	cloog_int_init(s->offset);
	cloog_int_set(s->stride, stride);
	cloog_int_set(s->offset, offset);

	return s;
}

CloogStride *cloog_stride_copy(CloogStride *stride)
{
	if (!stride)
		return stride;

	stride->references++;
	return stride;
}

void cloog_stride_free(CloogStride *stride)
{
	if (!stride)
		return;

	stride->references--;
	if (stride->references > 0)
		return;

	cloog_int_clear(stride->stride);
	cloog_int_clear(stride->offset);
	free(stride);
}
