/*
    SPDX-FileCopyrightText: 2021 Tomaz Canabrava <tcanabrava@kde.org>
    SPDX-License-Identifier: MIT
*/

#pragma once

#include "parser/meta_settings.h"

namespace KConfigExport {

void dump_header(
    const MetaConfiguration &config,
    const std::string &filename,
    const std::string &exportHeader,
    bool generateSingleton);

void dump_source(
    const MetaConfiguration &config,
    const std::string &filename,
    bool generateSingleton);

}
