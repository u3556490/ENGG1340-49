# ENGG1340-49
 HKU Faculty of Engineering; ENGG1340 Group 49 (FONG Kwan Ching, NG Chin Tat); Project Idea 2: "Commodity Inventory System".
 
 ## Problem Statement
 A commodity inventory management system is to be built. It aims to help optimize the management process of commodities in warehouses and shops. Naturally, the amount and variety of commodities sold at a chain store increases with the size of the business, and with the firm's expansion the frequency at which commodity availability information are updated also increases rapidly. Before computerization, the process of stock-taking is tedious and prone to human errors. The introduction of computer based technologies help to reduce the difficulty of maintaining stocks at a good frequency, while redeucing the complexity of the process to its users, e.g. the computer takes care of the stock status and automatically issues warnings, thus the user (firm staff) does not need to be constantly worrying about them. This project aims to simulate one such computer commodity inventory management system.
 
 The following functionalities would be present:
 As dictated by the Project Idea in the Course Project Guideline document, the system should be able to:
 * Permit searching and filtering of commodity entries  
   Each attribute of the commodity could be used as filters. The staff may set and unset a filter which could contain more than one criteria.
 * Adding and updating commodities into the database  
   This can be manually input for imported from a file.
 * Remove entries of obsolete commodities  
   Warnings will be issued such that deletion is re-confirmed.
 * Automatically determine whether a commodity is out of stock, and issue proper warnings
 * Issue proper alerts when commodities are out of stock  
   Out of stock is defined to be the case that the amount of a commodity is below/equal to the warning level. If the commodity is available at multiple shops, the stock status at each shop will be handled independently.
 * Automatically sort the table of commodities inventory  
   That is, the user may sort the table by contents of columns, whether he/she is filtering it to look for something or not.
 
 We propose the following be additional functionalities:
 * Set warning level: if (amount of commodity <= warning level), issue warning
 * Contents of the inventory could be exported to file for backup purposes.  
   From these backups, the data about the inventory could be restored.
 
 Each commodity is represented as a row in a table, where columns (fields) are the attributes. The list of fields to implement are as follows (those marked with asterisk * are required):
 - ID                       
   Unique for each product.
 - Name*
 - Manufacturer*
 - Unit price*
 - Expiry date                       
   For commodities without one, its value would be set to all zeros.
 - Amount available at HQ/warehouse  
   As the same commodity would be sold in different branches at the same time, only one such entry is enough.
 - Stockpile status                  
   Warehouse stockpile <= warning level ? if yes, out of stock, else available.
 - Shop ID                           
   Non zero value unique for each shop.
 - Amount at shop*                    
 - Availability at shop*          
   Shop stockpile <= warning level ? if yes, out of stock, else available
 
 The same commodity may be sold at different branches/shops. Therefore the same commodity (same ID, same name, etc.) could appear more than once as different rows. Their shop IDs and availabilities would be different, while the fields "amount available at HQ/warehouse" and "stockpile status" will be set to zeros. Accordingly, entries about the commodity's availability at the HQ/warehouse would have "shop ID" "amount at shop" "availability at shop" set to zero as these are unnecessary.
 
 ## Problem Setting
 The problem is set in a chain grocery store or supermarket, where the need to manage the stock of goods clearly and efficiently is present. This system would be installed in the computer(s) at the company headquarters and is used to manage the stockpile of commodities **at the main warehouse**. It is assumed that restocking of goods is done at the warehouse (it is assumed that **the company has only _one_ such warehouse**) and goods will be delivered to individual shops/stores/branches when they run out of stock.
