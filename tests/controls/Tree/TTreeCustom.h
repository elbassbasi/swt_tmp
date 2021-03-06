/*
 * TTreeCustom.h
 *
 *  Created on: 13 mai 2020
 *      Author: Azeddine El Bassbasi
 */

#ifndef TESTS_CONTROLS_TREE_TTREECUSTOM_H_
#define TESTS_CONTROLS_TREE_TTREECUSTOM_H_
#include "TTrees.h"
class Person {
public:
	Person(int i, int j);
public:
	char name[30];
	int i;
	int j;
	int progress;
};
class TTreeCustom: public WTree, public ITreeItem {
public:
	static void Registre(WTreeItem &parent);
	TTreeCustom();
	~TTreeCustom();
	WControl* GetControl(WComposite *parent);
	void CreateControl(WComposite *parent);
	bool OnItemMeasure(WTreeEvent &e);
	bool OnItemErase(WTreeEvent &e);
	bool OnItemPaint(WTreeEvent &e);
	bool OnItemGetValue(WTreeEvent &e);
	bool OnItemGetAttr(WTreeEvent &e);
	bool OnMouseDoubleClick(WMouseEvent &e);
	bool OnItemDispose(WTreeEvent &e);
	WFont fontBold;
	WText text;
};

#endif /* TESTS_CONTROLS_TREE_TTREECUSTOM_H_ */
