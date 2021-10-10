// DO NOT EDIT THIS FILE
// This file was automatically generated by configuration-parser
// There will be a .conf file somewhere which was used to generate this file
// See https://github.com/tcanabrava/configuration-parser

#include "test-simple-prefs-aggregate-value.h"
#include <QSettings>

Preferences::Preferences(QObject *parent) : QObject(parent),
	_name(QStringLiteral("Afonso"))
{
	load();
}

QPoint Preferences::point() const
{
	return _point;
}

QString Preferences::name() const
{
	return _name;
}

int Preferences::age() const
{
	return _age;
}

void Preferences::setPoint(const QPoint& value)
{
	if (_point==value) {
		return;
	}
	if (pointRule && !pointRule(value)) {
		return;
	}
	_point = value;
	Q_EMIT pointChanged(value);
}

void Preferences::setName(const QString& value)
{
	if (_name==value) {
		return;
	}
	if (nameRule && !nameRule(value)) {
		return;
	}
	_name = value;
	Q_EMIT nameChanged(value);
}

void Preferences::setAge(int value)
{
	if (_age==value) {
		return;
	}
	if (ageRule && !ageRule(value)) {
		return;
	}
	_age = value;
	Q_EMIT ageChanged(value);
}

void Preferences::setPointRule(std::function<bool(QPoint)> rule)
{
	pointRule = rule;
}

void Preferences::setNameRule(std::function<bool(QString)> rule)
{
	nameRule = rule;
}

void Preferences::setAgeRule(std::function<bool(int)> rule)
{
	ageRule = rule;
}

QString Preferences::nameDefault() const
{
	return QStringLiteral("Afonso");
}
void Preferences::loadDefaults()
{
	setName(QStringLiteral("Afonso"));
}
void Preferences::sync()
{
	QSettings s;
	if (point() == pointDefault()){
		s.remove("point");
	} else { 
		s.setValue("point",point());
	}
	if (name() == nameDefault()){
		s.remove("name");
	} else { 
		s.setValue("name",name());
	}
	if (age() == ageDefault()){
		s.remove("age");
	} else { 
		s.setValue("age",age());
	}
}

void Preferences::load()
{
	QSettings s;
	setPoint(s.value("point").value<QPoint>());
	setName(s.value("name", QStringLiteral("Afonso")).value<QString>());
	setAge(s.value("age").value<int>());
}

Preferences* Preferences::self()
{
	static Preferences s;
	return &s;
}
