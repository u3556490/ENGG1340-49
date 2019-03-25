# ENGG1340-49
 HKU Faculty of Engineering; ENGG1340 Group 49 (FONG Kwan Ching, NG Chin Tat); Project Idea 2: "Commodity Inventory System".
 
 ## Problem Statement
 A commodity inventory management system is to be built. It aims to help optimize the management process of commodities in warehouses and shops.
 
 The following functionalities would be present:
 As dictated by the Project Idea in the Course Project Guideline document, the system should be able to:
 * Permit searching and filtering of commodity entries
   Each attribute of the commodity could be used as filters. The staff may set and unset a filter which could contain more than one criteria.
 * Adding entries of new commodities
 * Remove entries of obsolete commodities
 * Automatically determine whether a commodity is out of stock, and issue proper warnings
 * Issue proper alerts when commodities are out of stock
 * To-do
   Auto check which shop lacks what commodity?
   Auto sort table?
   Allow updating of entries? from file?
   Auto save/backup inventory content to file?
 
 Each commodity is represented as a row in a table, where columns (fields) are the attributes. The list of fields to implement are as follows:
 - ID                                unique for each product
 - Name
 - Manufacturer
 - Place of origin
 - Unit price
 - Expiry date
 - Amount available at HQ/warehouse
 - Overall availability              warehouse stockpile <= 0 ? if yes, out of stock, else available
 - Shop ID                           unique for each shop
 - Amount at shop                    
 - Availability at shop              shop stockpile <= 0 ? if yes, out of stock, else available   
 - To-do
 The same commodity may be sold at different branches/shops. Therefore the same commodity (same ID, same name, etc.) could appear more than once as different rows. Their shop IDs and availabilities would be different.
 
 ## Problem Setting
 The problem is set in a chain grocery store or supermarket, where the need to manage the stock of goods clearly and efficiently is present. This system would be installed in the computer(s) at the company headquarters and is used to manage the stockpile of commodities **at the main warehouse**. It is assumed that restocking of goods is done at the warehouse (it is assumed that **the company has only _one_ such warehouse**) and goods are delivered to individual shops/stores/branches when they run out of stock.
  To-do
