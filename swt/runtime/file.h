/*
 * file.h
 *
 *  Created on: 9 oct. 2019
 *      Author: azeddine El Bassbasi
 */

#ifndef SWT_RUNTIME_FILE_H_
#define SWT_RUNTIME_FILE_H_
#include "../core/core.h"
#ifdef __cplusplus
extern "C" {
#endif
SWT_PUBLIC FILE* w_fopen(const char *file, const char *mode);
enum {
	W_ATTRIBUTE_DIR = 1 << 0,
};

typedef struct w_finddir {
	const char *name;
	int attribute;
	wint64 creationTime;
	wint64 filesize;
} w_finddir;

SWT_PUBLIC wresult w_dir_list(const char *dir, w_iterator *files);

#ifdef __cplusplus
}
#endif
#endif /* SWT_RUNTIME_FILE_H_ */
