/*
 * control.h
 *
 *  Created on: 21 avr. 2019
 *      Author: azeddine El Bassbasi
 */

#ifndef SRC_WIN32_WIDGETS_CONTROL_H_
#define SRC_WIN32_WIDGETS_CONTROL_H_

#if defined( __WIN32__) || defined(__WIN64__)
#include "menu.h"

#define STATE_RESIZE_DEFERRED (1 << (STATE_WIDGET_END + 0))
#define STATE_RESIZE_OCCURRED (1 << (STATE_WIDGET_END + 1))
#define STATE_LAYOUT_DATA_LOCALE (1 << (STATE_WIDGET_END + 2))
#define STATE_IGNORE_WM_CHANGEUISTATE (1 << (STATE_WIDGET_END + 3))
#define STATE_SET_FONT (1 << (STATE_WIDGET_END + 4))
#define STATE_THEME_BACKGROUND (1 << (STATE_WIDGET_END + 5))
#define STATE_PARENT_BACKGROUND (1 << (STATE_WIDGET_END + 6))
#define STATE_DISABLED (1 << (STATE_WIDGET_END + 7))
#define STATE_HIDDEN (1 << (STATE_WIDGET_END + 8))
#define STATE_CONTROL_END (STATE_WIDGET_END + 8)

typedef struct _w_control {
	struct _w_widget widget;
	union {
		w_font *font;
		struct _w_font _font;
	};
	int background;
	int foreground;
	int drawCount;
	w_cursor *cursor;
	w_menu *menu;
	w_composite *parent;
	HBITMAP backgroundImage;
	//HBRUSH hBrush;
} _w_control;
typedef struct _w_control_reserved _w_control_reserved;
struct _w_control_reserved {
	_w_widget_reserved widget;
	WNDPROC _window_proc;
	WNDPROC (*get_window_proc)(w_control *control,_w_control_reserved *reserved);
	HWND (*topHandle)(w_control *control);
	HWND (*borderHandle)(w_control *control);
	wresult (*create_widget)(w_control *control, _w_control_reserved *reserved);
	wuint64 (*check_style)(w_widget *widget, wuint64 style);
	wresult (*check_orientation)(w_control *control, w_composite *parent,
			_w_control_reserved *reserved);
	wresult (*create_handle)(w_control *control, _w_control_reserved *reserved);
	wresult (*subclass)(w_control *control, _w_control_reserved *reserved);
	wresult (*unsubclass)(w_control *control, _w_control_reserved *reserved);
	wresult (*check_background)(w_control *control,
			_w_control_reserved *reserved);
	wresult (*check_buffered)(w_control *control,
			_w_control_reserved *reserved);
	wresult (*check_composited)(w_control *control,
			_w_control_reserved *reserved);
	wresult (*set_default_font)(w_control *control,
			_w_control_reserved *reserved);
	wresult (*check_mirrored)(w_control *control,
			_w_control_reserved *reserved);
	wresult (*check_border)(w_control *control, _w_control_reserved *reserved);
	wresult (*check_gesture)(w_control *control, _w_control_reserved *reserved);
	wresult (*set_background)(w_control *control,
			_w_control_reserved *reserved);
	HWND (*widget_parent)(w_control *control, _w_control_reserved *reserved);
	DWORD (*widget_style)(w_control *control, _w_control_reserved *reserved);
	DWORD (*widget_extstyle)(w_control *control, _w_control_reserved *reserved);
	const char* (*window_class)(w_control *control,
			_w_control_reserved *reserved);
	int (*compute_size)(w_widget *widget, w_event_compute_size *e,
			_w_widget_reserved *reserved);
	int (*get_client_area)(w_widget *widget, w_event_client_area *e,
			_w_widget_reserved *reserved);
	int (*compute_trim)(w_widget *widget, w_event_compute_trim *e,
			_w_widget_reserved *reserved);
	dispatch_message messages[_WM_LAST];
};
#define _W_CONTROL(x) ((_w_control*)x)
#define _W_CONTROL_RESERVED(x) ((_w_control_reserved*)x)
#define _W_CONTROL_GET_RESERVED(x) ((_w_control_reserved*)_w_widget_get_reserved(W_WIDGET(x)))
//
/*
 * internal function
 */
void _w_control_style(w_widget *widget, w_widget *parent, int style,
		DWORD *dwExStyle, DWORD *dwStyle);
wresult _w_control_create_0(w_control *control, w_composite *parent,
		const char *clazz, DWORD dwExStyle, DWORD dwStyle);
void _w_control_def_proc(w_widget *widget, _w_event_platform *e,
		struct _w_widget_reserved *reserved);
HWND _w_control_h(w_control *control);
DWORD _w_control_widget_extstyle(w_control *control,
		_w_control_reserved *reserved);
const char* _w_control_window_class(w_control *control,
		_w_control_reserved *reserved);
DWORD _w_control_widget_style(w_control *control,
		_w_control_reserved *reserved);
wresult _w_control_create_handle(w_control *control,
		_w_control_reserved *reserved);
wresult _w_control_subclass(w_control *control, _w_control_reserved *reserved);
wresult _w_control_unsubclass(w_control *control,
		_w_control_reserved *reserved);
wresult _w_control_create(w_widget *widget, w_widget *parent, wuint64 style,
		w_widget_post_event_proc post_event);
//#define _w_control_get_drawing(x) (((_w_control*)x)->drawCount <= 0)
/*
 *  function
 */
HWND _CreateWindow(DWORD dwExStyle, const char *lpClassName, DWORD dwStyle,
		HWND hWndParent, LPVOID lpParam);
wresult _w_control_get_graphics(w_control *control, w_graphics *gc);
int _w_control_get_orientation(w_control *control);
wresult _w_control_set_orientation(w_control *control, int orientation);
int _w_control_get_text_direction(w_control *control);
wresult _w_control_set_text_direction(w_control *control, int textDirection);
int _w_control_print(w_control *control, w_graphics *gc);
w_accessible* _w_control_get_accessible(w_control *control);
wresult _w_control_get_bounds(w_control *control, w_point *location,
		w_size *size);
wresult _w_control_set_bounds(w_control *control, w_point *location,
		w_size *size);
w_region* _w_control_get_region(w_control *control);
wresult _w_control_set_region(w_control *control, w_region *region);
wresult _w_control_move_above(w_control *control, w_control *_control);
wresult _w_control_move_below(w_control *control, w_control *_control);
wresult _w_control_pack(w_control *control);
wresult _w_control_to_control(w_control *control, w_point *result,
		w_point *point);
wresult _w_control_to_display(w_control *control, w_point *result,
		w_point *point);
wresult _w_control_drag_detect(w_control *control, w_event *event);
wresult _w_control_get_drag_detect(w_control *control);
wresult _w_control_set_drag_detect(w_control *control, int dragDetect);
wresult _w_control_force_focus(w_control *control);
wresult _w_control_set_focus(w_control *control);
wresult _w_control_is_focus_control(w_control *control);
int _w_control_get_border_width(w_control *control);
wresult _w_control_get_drawing(w_control *control);
w_cursor* _w_control_get_cursor(w_control *control);
wresult _w_control_set_cursor(w_control *control, w_cursor *cursor);
wresult _w_control_get_enabled(w_control *control);
wresult _w_control_set_enabled(w_control *control, int enabled);
wresult _w_control_is_enabled(w_control *control);
wresult _w_control_get_font(w_control *control, w_font **font);
wresult _w_control_set_font(w_control *control, w_font *font);
w_color _w_control_get_background(w_control *control);
wresult _w_control_set_background(w_control *control, w_color color);
w_color _w_control_get_foreground(w_control *control);
wresult _w_control_set_foreground(w_control *control, w_color color);
wresult _w_control_get_layout_data(w_control *control, void **data);
wresult _w_control_new_layout_data(w_control *control, void **data,
		size_t size);
void _w_control_request_layout(w_control *control);
w_menu* _w_control_get_menu(w_control *control);
wresult _w_control_set_menu(w_control *control, w_menu *menu);
wresult _w_control_get_parent(w_control *control, w_composite **parent);
wresult _w_control_set_parent(w_control *control, w_composite *parent);
wresult _w_control_is_reparentable(w_control *control);
wresult _w_control_get_shell(w_control *control, w_shell **shell);
void _w_control_get_toolTip_text(w_control *control, w_string_ref **s);
wresult _w_control_set_toolTip_text(w_control *control, const char *text);
wresult _w_control_get_touch_enabled(w_control *control);
wresult _w_control_set_touch_enabled(w_control *control, int enabled);
wresult _w_control_get_visible(w_control *control);
wresult _w_control_set_visible(w_control *control, int visible);
wresult _w_control_is_visible(w_control *control);
wresult _w_control_redraw(w_control *control, w_rect *rect, int all);
wresult _w_control_set_redraw(w_control *control, int redraw);
wresult _w_control_set_capture(w_control *control, int capture);
wresult _w_control_traverse(w_control *control, int traversal, w_event *event);
wresult _w_control_update(w_control *control);
wresult _w_control_set_timer(w_control *control, wint64 ms, wushort id);
wresult _w_control_kill_timer(w_control *control, unsigned short id);
/*
 * private
 */
HBRUSH _w_control_find_brush(w_control *control, ULONG_PTR value, int lbStyle);
void _w_control_fill_background(w_control *control, HDC hDC, int pixel,
		RECT *rect);
void _w_control_draw_background_0(w_control *control, HDC hDC, RECT *rect,
		int pixel, int tx, int ty);
void _w_control_draw_background_1(w_control *control, HDC hDC, RECT *rect);
void _w_control_draw_background(w_control *control, HDC hDC);
void _w_control_init_graphics(w_control *control, w_graphics *gc, HDC hdc,
		int style);
/*
 *
 */
int _CONTROL_WM_DESTROY(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_CREATE(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_CTLCOLOR(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_CHANGEUISTATE(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_COMMAND(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_DRAWITEM(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_ERASEBKGND(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_GETOBJECT(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_GETDLGCODE(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_HELP(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_HSCROLL(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_INPUTLANGCHANGE(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_MEASUREITEM(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_MENUCHAR(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_MENUSELECT(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_MOVE(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_NCHITTEST(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_NOTIFY(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_PAINT(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_SETCURSOR(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_SIZE(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_SYSCOMMAND(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_TABLET_FLICK(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_TOUCH(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_TIMER(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_VSCROLL(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_WINDOWPOSCHANGED(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_WINDOWPOSCHANGING(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _CONTROL_WM_CTLCOLORCHILD(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
int _wm_control_Notify(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);

/*
 * post event proc
 */
int _CONTROL_WM_NULL(w_widget *widget, struct _w_event_platform *e,
		struct _w_widget_reserved *reserved);
wresult _w_control_post_event_platform(w_widget *widget, _w_event_platform *ee,
		_w_widget_reserved *reserved);
int _w_control_compute_size(w_widget *widget, struct w_event_compute_size *e,
		struct _w_widget_reserved *reserved);
int _w_control_post_event(w_widget *widget, struct w_event *ee);
void _w_control_dispose(w_widget *widget);
void _w_control_class_init(struct _w_control_class *clazz);
#endif
#endif /* SRC_WIN32_WIDGETS_CONTROL_H_ */
