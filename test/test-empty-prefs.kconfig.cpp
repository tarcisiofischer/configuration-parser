// DO NOT EDIT THIS FILE
// This file was automatically generated by configuration-parser
// There will be a .conf file somewhere which was used to generate this file
// See https://github.com/tcanabrava/configuration-parser

#include "test-empty-prefs.h"
#include <KConfig>
#include <KConfigGroup>
#include <KSharedConfig>

Preferences::Preferences(QObject *parent) : QObject(parent)
{
	load();
}

void Preferences::loadDefaults()
{
}
void Preferences::sync()
{
}

void Preferences::load()
{
}

Preferences* Preferences::self()
{
	static Preferences s;
	return &s;
}
