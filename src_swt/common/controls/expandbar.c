/*
 * expandbar.c
 *
 *  Created on: 26 ao�t 2019
 *      Author: azeddine El Bassbasi
 */
#include <swt.h>

wresult w_expandbar_create(w_expandbar *expandbar, struct w_toolkit *toolkit,
		w_composite *parent, wuint64 style, w_widget_post_event_proc post_event) {
	return _w_widget_create(W_WIDGET(expandbar), toolkit, W_WIDGET(parent),
			style, _W_CLASS_EXPANDBAR, post_event);
}
w_expandbar* w_expandbar_new(struct w_toolkit *toolkit, w_composite *parent,
                             wuint64 style, w_widget_post_event_proc post_event) {
	return W_EXPANDBAR(
			_w_widget_new(toolkit,W_WIDGET(parent),style,_W_CLASS_EXPANDBAR,post_event));
}
w_control* w_expanditem_get_control(w_expanditem *expanditem) {
	wresult result = W_WIDGETDATA_CHECK0(expanditem);
	if (result > 0) {
		return W_EXPANDITEM_GET_CLASS(expanditem)->get_control(expanditem);
	} else
		return 0;
}
wresult w_expanditem_get_expanded(w_expanditem *expanditem) {
	wresult result = W_WIDGETDATA_CHECK0(expanditem);
	if (result > 0) {
		return W_EXPANDITEM_GET_CLASS(expanditem)->get_expanded(expanditem);
	} else
		return W_FALSE;
}
int w_expanditem_get_header_height(w_expanditem *expanditem) {
	wresult result = W_WIDGETDATA_CHECK0(expanditem);
	if (result > 0) {
		return W_EXPANDITEM_GET_CLASS(expanditem)->get_header_height(expanditem);
	} else
		return 0;
}
int w_expanditem_get_height(w_expanditem *expanditem) {
	wresult result = W_WIDGETDATA_CHECK0(expanditem);
	if (result > 0) {
		return W_EXPANDITEM_GET_CLASS(expanditem)->get_height(expanditem);
	} else
		return 0;
}
wresult w_expanditem_set_control(w_expanditem *expanditem,
		w_control *control) {
	wresult result = W_WIDGETDATA_CHECK0(expanditem);
	if (result > 0) {
		return W_EXPANDITEM_GET_CLASS(expanditem)->set_control(expanditem,
				control);
	} else
		return result;
}
wresult w_expanditem_set_expanded(w_expanditem *expanditem, int expanded) {
	wresult result = W_WIDGETDATA_CHECK0(expanditem);
	if (result > 0) {
		return W_EXPANDITEM_GET_CLASS(expanditem)->set_expanded(expanditem,
				expanded);
	} else
		return result;
}
wresult w_expanditem_set_height(w_expanditem *expanditem, int height) {
	wresult result = W_WIDGETDATA_CHECK0(expanditem);
	if (result > 0) {
		return W_EXPANDITEM_GET_CLASS(expanditem)->set_height(expanditem,
				height);
	} else
		return result;
}
wresult w_expanditem_set_image(w_expanditem *expanditem, int image) {
	wresult result = W_WIDGETDATA_CHECK0(expanditem);
	if (result > 0) {
		return W_EXPANDITEM_GET_CLASS(expanditem)->set_image(expanditem, image);
	} else
		return result;
}
/*
 *
 */
wresult w_expandbar_get_item(w_expandbar *expandbar, int index,
		w_expanditem *item) {
	w_widgetdata_close(W_WIDGETDATA(item));
	wresult result = W_WIDGET_CHECK0(expandbar);
	if (result > 0) {
		return W_EXPANDBAR_GET_CLASS(expandbar)->get_item(expandbar, index,
				item);
	} else
		return result;
}
int w_expandbar_get_item_count(w_expandbar *expandbar) {
	wresult result = W_WIDGET_CHECK0(expandbar);
	if (result > 0) {
		return W_EXPANDBAR_GET_CLASS(expandbar)->get_item_count(expandbar);
	} else
		return 0;
}
void w_expandbar_get_items(w_expandbar *expandbar, w_iterator *items) {
	w_iterator_close(items);
	wresult result = W_WIDGET_CHECK0(expandbar);
	if (result > 0) {
		return W_EXPANDBAR_GET_CLASS(expandbar)->get_items(expandbar, items);
	}
}
int w_expandbar_get_spacing(w_expandbar *expandbar) {
	wresult result = W_WIDGET_CHECK0(expandbar);
	if (result > 0) {
		return W_EXPANDBAR_GET_CLASS(expandbar)->get_spacing(expandbar);
	} else
		return result;
}
wresult w_expandbar_insert_item(w_expandbar *expandbar,w_expanditem* item,const char* text,int index){
	w_widgetdata_close(W_WIDGETDATA(item));
	wresult result = W_WIDGET_CHECK0(expandbar);
	if (result > 0) {
		return W_EXPANDBAR_GET_CLASS(expandbar)->insert_item(expandbar,item,text,index);
	} else
		return result;
}
wresult w_expandbar_set_spacing(w_expandbar *expandbar, int spacing) {
	wresult result = W_WIDGET_CHECK0(expandbar);
	if (result > 0) {
		return W_EXPANDBAR_GET_CLASS(expandbar)->set_spacing(expandbar, spacing);
	} else
		return result;
}
