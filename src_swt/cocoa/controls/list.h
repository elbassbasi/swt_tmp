/*
 * list.h
 *
 *  Created on: 11 oct. 2019
 *      Author: azeddine El Bassbasi
 */

#ifndef SRC_COCOA_CONTROLS_LIST_H_
#define SRC_COCOA_CONTROLS_LIST_H_
#ifdef __APPLE__
#include "../widgets/scrollable.h"

typedef struct _w_list {
	struct _w_scrollable scrollable;
} _w_list;

struct _w_list_reserved {
	struct _w_scrollable_reserved scrollable;

};
#define _W_LIST(x) ((_w_list*)x)
#define _W_LIST_RESERVED(x) ((struct _w_list_reserved*)x)
void _w_list_class_init(struct _w_list_class *clazz);

#endif
#endif /* SRC_GTK_CONTROLS_LIST_H_ */
