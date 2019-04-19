#ifndef DBIEPORT
#define DBIEPORT
#include "main.h"
#include <vector>

// -----------------------------
// function import_file: reads an address from the user and imports a
// whole inventory from that address.
// @params none
// @return vector<Commodity>: the inventory obtained
// -----------------------------
std::vector<main_header::Commodity> import_file();

// -----------------------------
// function export_file: reads an address from the user and exports the
// current inventory to that address.
// @params vector<Commodity> list: the inventory to export
// @return bool: whether the action is successful.
// -----------------------------
bool export_file(std::vector<main_header::Commodity> list);

#endif /* DBIEPORT */
