#include "gamedata.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

namespace nibashared {

staticdata::staticdata() {}

staticdata &staticdata::get() {
    static staticdata instance;
    return instance;
}

std::tuple<std::unordered_map<int, nibashared::character>,
           std::unordered_map<int, nibashared::magic>,
           std::unordered_map<int, nibashared::equipment>>
staticdata::all() {
    // a lot of data copying
    return std::make_tuple(characters_, magics_, equipments_);
}

const character &staticdata::character(int id) { return characters_.at(id); }

const magic &staticdata::magic(int id) { return magics_.at(id); }

const equipment &staticdata::equipment(int id) { return equipments_.at(id); }

} // namespace nibashared