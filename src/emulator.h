// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <filesystem>

#include "core/linker.h"
#include "input/controller.h"
#include "sdl_window.h"
#include "common/observer/subscriber.h"

namespace Core {

using HLEInitDef = void (*)(Core::Loader::SymbolsResolver* sym);

struct SysModules {
    std::string_view module_name;
    HLEInitDef callback;
};

class Emulator {
public:
    Emulator();

    explicit Emulator(Common::Subscriber *toNotifyWhenExit);

    ~Emulator();

    void Run(const std::filesystem::path &file, const std::vector<std::string> args = {});
    std::unique_ptr<Frontend::WindowSDL> window;

private:
    void UpdatePlayTime(const std::string& serial) const;

    void LoadSystemModules(const std::string& game_serial);

    Core::MemoryManager* memory;
    Input::GameController* controller;
    Core::Linker* linker;
    std::chrono::steady_clock::time_point start_time;
    Common::Subscriber *m_toNotifyWhenExit;
};

} // namespace Core
