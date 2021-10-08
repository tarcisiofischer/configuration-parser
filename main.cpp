/*
    SPDX-FileCopyrightText: 2021 Tomaz Canabrava <tcanabrava@kde.org>
    SPDX-License-Identifier: MIT
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

#include "meta-settings.h"
#include "statemachine.h"
#include "string-helpers.h"

#include <QtGlobal>
#include <QDebug>
#include <QFileInfo>
#include <QString>
#include <filesystem>

struct MetaConfiguration;

/* Generates the header file for the configuration */
void dump_header(
    const MetaConfiguration &config,
    const std::string &filename,
    const std::string &exportHeader);

/* generates the source fole for the configuration */
void dump_source(const MetaConfiguration &config, const std::string &filename);

void show_usage(const char appname[]) {
  qDebug() << "usage" << appname << " [--with-export-header=header] file.conf";
  qDebug() << "\t this will generate a header / source pair";
  qDebug() << "\t with everything you need to start coding.";
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    show_usage(argv[0]);
    return 0;
  }


  std::string export_header;
  if (argc == 3) {
    QString export_file(argv[1]);
    if (!export_file.contains("--with-xport-header=")) {
        export_header = export_file
            .split("=",
#if QT_VERSION < QT_VERSION_CHECK(5, 14, 0)
    QString::SkipEmptyParts
#else
    Qt::SkipEmptyParts
#endif
            )
            .at(1)
            .toStdString();
    }
 }

  const int file_pos = argc == 3 ? 2 : 1;

  std::string filename(argv[file_pos]);
  if (filename == "-h" || filename == "--help") {
    show_usage(argv[0]);
    return 0;
  }

  QFileInfo info(argv[file_pos]);
  if (!info.exists()) {
    qDebug() << "The specified file doesn't exist: " << info.fileName();
    return 0;
  }

  std::ifstream file(filename);
  if ((file.rdstate() & std::ifstream::failbit) != 0) {
    qDebug() << "could not open file.";
    return 0;
  }

  MetaConfiguration conf = parse_configuration(file);

  std::string outfile = std::filesystem::path(filename).filename().string();

  size_t substrSize = outfile.find_last_of('.');
  std::string name_without_ext = outfile.substr(0, substrSize);

  dump_header(conf, name_without_ext + ".h", export_header);
  dump_source(conf, name_without_ext + ".cpp");

  qDebug() << "files generated" << std::filesystem::absolute(name_without_ext + ".h").string();
  qDebug() << "files generated" << std::filesystem::absolute(name_without_ext + ".cpp").string();
}
