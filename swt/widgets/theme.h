/*
 * theme.h
 *
 *  Created on: 5 nov. 2019
 *      Author: azeddine El Bassbasi
 */

#ifndef SWT_WIDGETS_THEME_H_
#define SWT_WIDGETS_THEME_H_
#include "shell.h"
#ifdef __cplusplus
extern "C" {
#endif
/** classes  */
enum {
    W_THEME_CLASS_UNKNOWN =_W_CLASS_UNKNOWN,
    //widget
    W_THEME_CLASS_MENU =_W_CLASS_MENU,
    //control
            W_THEME_CLASS_BUTTON =_W_CLASS_BUTTON,
    W_THEME_CLASS_LABEL =_W_CLASS_LABEL,
    W_THEME_CLASS_LINK =_W_CLASS_LINK,
    W_THEME_CLASS_PROGRESSBAR =_W_CLASS_PROGRESSBAR,
    W_THEME_CLASS_SASH =_W_CLASS_SASH,
    W_THEME_CLASS_SCALE =_W_CLASS_SCALE,
    W_THEME_CLASS_SLIDER =_W_CLASS_SLIDER,
    W_THEME_CLASS_SCROLLBAR =_W_CLASS_SCROLLBAR,

    //scrollable
    W_THEME_CLASS_TEXT =_W_CLASS_TEXT,
    W_THEME_CLASS_LIST =_W_CLASS_LIST,

    //composite
    W_THEME_CLASS_COMPOSITE = _W_CLASS_COMPOSITE,
    W_THEME_CLASS_BROWSER =_W_CLASS_BROWSER,
    W_THEME_CLASS_TREE =_W_CLASS_TREE,
    W_THEME_CLASS_TABFOLDER =_W_CLASS_TABFOLDER,
    W_THEME_CLASS_COMBO =_W_CLASS_COMBO,
    W_THEME_CLASS_COOLBAR =_W_CLASS_COOLBAR,
    W_THEME_CLASS_DATETIME =_W_CLASS_DATETIME,
    W_THEME_CLASS_EXPANDBAR =_W_CLASS_EXPANDBAR,
    W_THEME_CLASS_GROUP =_W_CLASS_GROUP,
    W_THEME_CLASS_SPINNER =_W_CLASS_SPINNER,
    W_THEME_CLASS_TABLE =_W_CLASS_TABLE,
    W_THEME_CLASS_TOOLBAR =_W_CLASS_TOOLBAR,
    // item
    W_THEME_CLASS_TABITEM = _W_CLASS_LAST + 1,
    W_THEME_CLASS_TOOLITEM = _W_CLASS_LAST + 2,
    W_THEME_CLASS_LAST,
    /*
     * internal class
     */
    _W_THEME_CLASS_UNKNOWN =0,
    _W_THEME_CLASS_MENU,
    _W_THEME_CLASS_BUTTON,
    _W_THEME_CLASS_LABEL,
    _W_THEME_CLASS_LINK,
    _W_THEME_CLASS_PROGRESSBAR,
    _W_THEME_CLASS_SASH,
    _W_THEME_CLASS_SCALE,
    _W_THEME_CLASS_SLIDER,
    _W_THEME_CLASS_SCROLLBAR,
    _W_THEME_CLASS_TEXT,
    _W_THEME_CLASS_LIST,
    _W_THEME_CLASS_COMPOSITE,
    _W_THEME_CLASS_BROWSER,
    _W_THEME_CLASS_TREE,
    _W_THEME_CLASS_TABFOLDER,
    _W_THEME_CLASS_TABITEM,
    _W_THEME_CLASS_COMBO,
    _W_THEME_CLASS_COOLBAR,
    _W_THEME_CLASS_DATETIME,
    _W_THEME_CLASS_EXPANDBAR,
    _W_THEME_CLASS_GROUP,
    _W_THEME_CLASS_SPINNER,
    _W_THEME_CLASS_TABLE,
    _W_THEME_CLASS_TOOLBAR,
    _W_THEME_CLASS_TOOLITEM,
    _W_THEME_CLASS_LAST,
};

enum {

	/** Part states */
	W_THEME_SELECTED = W_SELECTED,
	W_THEME_FOCUSED = W_FOCUSED,
	W_THEME_HOT = W_HOT,
	W_THEME_PRESSED = W_PRESSED,
	W_THEME_ACTIVE = W_ACTIVE,
	W_THEME_DISABLED = W_DISABLED,
	W_THEME_DEFAULTED = W_DEFAULTED,
	W_THEME_GRAYED = W_GRAYED,

	/** Text and Image drawing flags */
	W_THEME_DRAW_LEFT = W_DRAW_LEFT,
	W_THEME_DRAW_TOP = W_DRAW_TOP,
	W_THEME_DRAW_RIGHT = W_DRAW_RIGHT,
	W_THEME_DRAW_BOTTOM = W_DRAW_BOTTOM,
	W_THEME_DRAW_HCENTER = W_DRAW_HCENTER,
	W_THEME_DRAW_VCENTER = W_DRAW_VCENTER,
	W_THEME_DRAW_CENTER = W_DRAW_CENTRE,

	/** Widget parts */
	W_THEME_WIDGET_NOWHERE = -1,
	W_THEME_WIDGET_WHOLE = 0,

	/** Scrollbar parts */
	W_THEME_SCROLLBAR_UP_ARROW = 1,
	W_THEME_SCROLLBAR_DOWN_ARROW = 2,
	W_THEME_SCROLLBAR_LEFT_ARROW = W_THEME_SCROLLBAR_UP_ARROW,
	W_THEME_SCROLLBAR_RIGHT_ARROW = W_THEME_SCROLLBAR_DOWN_ARROW,
	W_THEME_SCROLLBAR_UP_TRACK = 3,
	W_THEME_SCROLLBAR_DOWN_TRACK = 4,
	W_THEME_SCROLLBAR_LEFT_TRACK = W_THEME_SCROLLBAR_UP_TRACK,
	W_THEME_SCROLLBAR_RIGHT_TRACK = W_THEME_SCROLLBAR_DOWN_TRACK,
	W_THEME_SCROLLBAR_THUMB = 5,

	/** Scale parts */
	W_THEME_SCALE_UP_TRACK = 1,
	W_THEME_SCALE_LEFT_TRACK = W_THEME_SCALE_UP_TRACK,
	W_THEME_SCALE_DOWN_TRACK = 2,
	W_THEME_SCALE_RIGHT_TRACK = W_THEME_SCALE_DOWN_TRACK,
	W_THEME_SCALE_THUMB = 3,

	/** ToolItem parts */
	W_THEME_TOOLITEM_ARROW = 1,

	/** Combo parts */
	W_THEME_COMBO_ARROW = 1,
};
typedef struct w_theme {
    void *v_table; //not used in c
	struct _w_theme_class *clazz;
} w_theme;
typedef struct w_themedata {
    wuint clazz;
	wuint state;
    wuint64 style;
	w_rect *clientArea;
	union {
		struct {
			int selection;
			int minimum;
			int maximum;
			int increment;
			int pageIncrement;
			int thumb;
		} range;
		struct {
			w_rect *tabsArea;
			int tabsWidth;
			int tabsHeight;
			int selectedX;
			int selectedWidth;
			int spacing;
		} tab;
		struct {
			int position;
		} tabitem;
		struct {
			int headerWidth;
			int headerHeight;
			w_rect *headerArea;
		} group;
	};
} w_themedata;
typedef struct _w_theme_class {
	void (*dispose)(w_theme *theme);
	const char* (*get_name)(w_theme *theme);
    void (*compute_trim)(w_theme *theme,w_themedata *data,w_graphics *gc, w_rect *result);
    void (*draw_background)(w_theme *theme,w_themedata *data, w_graphics *gc, w_rect *bounds);
    void (*draw_focus)(w_theme *theme,w_themedata *data, w_graphics *gc, w_rect *bounds);
    void (*draw_image)(w_theme *theme,w_themedata *data, w_graphics *gc, w_rect *bounds,
                       w_image *image, int flags);
    void (*draw_text)(w_theme *theme,w_themedata *data, w_graphics *gc, w_rect *bounds,
                      const char *text, int length, int flags);
    void (*get_bounds)(w_theme *theme,w_themedata *data, int part,
                       w_rect *bounds, w_rect *result);
    int (*get_selection)(w_theme *theme,w_themedata *data, w_point *offset, w_rect *bounds);
    int (*hit_background)(w_theme *theme,w_themedata *data, w_point *position, w_rect *bounds);
    void (*measure_text)(w_theme *theme,w_themedata *data,w_graphics *gc, w_rect *bounds, w_rect *result,const char *text, size_t length, int flags);
	w_color  (*get_color)(w_theme *theme,wuint colorid);
	w_font* (*get_font)(w_theme *theme);
    w_cursor* (*get_cursor)(w_theme *theme, wuint id);
    w_image* (*get_image)(w_theme *theme, wuint id);
} _w_theme_class;
SWT_PUBLIC void w_theme_dispose(w_theme *theme);
SWT_PUBLIC const char* w_theme_get_name(w_theme *theme);
SWT_PUBLIC void w_theme_compute_trim(w_theme *theme,w_themedata *data,w_graphics *gc,
		w_rect *result);
SWT_PUBLIC void w_theme_draw_background(w_theme *theme,w_themedata *data, w_graphics *gc, w_rect *bounds);
SWT_PUBLIC void w_theme_draw_focus(w_theme *theme,w_themedata *data, w_graphics *gc, w_rect *bounds);
SWT_PUBLIC void w_theme_draw_image(w_theme *theme,w_themedata *data, w_graphics *gc, w_rect *bounds,w_image *image, int flags);
SWT_PUBLIC void w_theme_draw_text(w_theme *theme,w_themedata *data, w_graphics *gc, w_rect *bounds, const char *text, int length, int flags);
SWT_PUBLIC void w_theme_get_bounds(w_theme *theme,w_themedata *data, int part,
                                   w_rect *bounds,w_rect *result);
SWT_PUBLIC int w_theme_get_selection(w_theme *theme,w_themedata *data, w_point *offset, w_rect *bounds);
SWT_PUBLIC int w_theme_hit_background(w_theme *theme,w_themedata *data, w_point *position, w_rect *bounds);
SWT_PUBLIC void w_theme_measure_text(w_theme *theme,w_themedata *data,w_graphics *gc, w_rect *bounds,w_rect *result, const char *text, size_t length,
		int flags);
SWT_PUBLIC w_color  w_theme_get_color(w_theme *theme,wuint colorid);
SWT_PUBLIC w_font* w_theme_get_font(w_theme *theme);
SWT_PUBLIC w_cursor* w_theme_get_cursor(w_theme *theme, wuint id);
SWT_PUBLIC w_image* w_theme_get_image(w_theme *theme, wuint id);
SWT_PUBLIC wuint w_theme_internal_class_id(wuint clazz);

#ifdef __cplusplus
}
#endif
#endif /* SWT_WIDGETS_THEME_H_ */
