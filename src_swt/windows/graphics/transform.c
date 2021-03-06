/*
 * transform.c
 *
 *  Created on: 1 avr. 2020
 *      Author: azeddine El Bassbasi
 */
#if defined( __WIN32__) || defined(__WIN64__)
#include "graphics.h"
void w_transform_init(w_transform *transform) {
}
void w_transform_dispose(w_transform *transform) {
}
wresult w_transform_create(w_transform *transform, w_transformmatrix *matrix) {
}
wresult w_transform_get_elements(w_transform *transform,
		w_transformmatrix *elements) {
}
wresult w_transform_identity(w_transform *transform) {
}
wresult w_transform_invert(w_transform *transform) {
}
wresult w_transform_isok(w_transform *transform) {
}
wresult w_transform_is_identity(w_transform *transform) {
}
wresult w_transform_multiply(w_transform *transform,
		w_transformmatrix *matrix) {
}
wresult w_transform_rotate(w_transform *transform, float angle) {
}
wresult w_transform_scale(w_transform *transform, float scaleX, float scaleY) {
}
wresult w_transform_set_elements(w_transform *transform,
		w_transformmatrix *matrix) {
}
wresult w_transform_shear(w_transform *transform, float shearX, float shearY) {
}
wresult w_transform_transform(w_transform *transform, w_pointf *points,
		size_t count) {
}
wresult w_transform_translate(w_transform *transform, float offsetX,
		float offsetY) {
}
#endif
