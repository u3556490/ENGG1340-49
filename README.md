# ENGG1340-49
 HKU Faculty of Engineering; ENGG1340 Group 49 (FONG Kwan Ching, NG Chin Tat); Project Idea 2: "Commodity Inventory System".  
 Please note that sometimes mergings of conflicts would have the lines of code edited counted for Fong instead of by Ng as they actually are.  
 
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
   Unique for each product entry.
 - Name*
 - Manufacturer*
 - Unit price*
 - Expiry date                       
   For commodities without one, its value should be all zeros.
 - Amount available at HQ/warehouse  
   As the same commodity would be sold in different branches at the same time, its content repeats in different entries.
 - Stockpile status                  
   Warehouse stockpile <= warning level ? if yes, out of stock, else available.
 - Shop ID                           
   Non zero value unique for each shop.
 - Amount at shop*                    
 - Availability at shop* (out of stock status)         
   Shop stockpile <= warning level ? if yes, out of stock, else available
 
 The same commodity may be sold at different branches/shops. Therefore the same commodity (different ID but same name, etc.) could appear more than once as different rows. Their shop IDs and availabilities would be different. In order to ease understanding, the amount available at HQ/warehouse and the stockpile statuses are repeated in these entries, so the operator knows well which items and how are they having stock issues.
 
 ## Problem Setting
 The problem is set in a chain grocery store or supermarket, where the need to manage the stock of goods clearly and efficiently is present. This system would be installed in the computer(s) at the company headquarters and is used to manage the stockpile of commodities **at the main warehouse**. It is assumed that restocking of goods is done at the warehouse (it is assumed that **the company has only _one_ such warehouse**) and goods will be delivered to individual shops/stores/branches when they run out of stock. It is also assumed that IDs are always unique.
 
 ## Usage Manual
 #### Functionality and Features
   This application offers the following functionalities:  
   * Addition of one new commodity entry  
     Either by manually inputting each and every attribute or by importing from file.  
   * Removal of one specific commodity entry, specified by its id  
   * Import and load inventory from file  
     This is always a batch process involving file manipulation. The imported inventory will become the working inventory.  
   * Export and save current inventory to file  
     This is always a batch process involving file manipulation. The exported inventory is always the working inventory.
   * Search for entries 
     The user may search for each attribute equalling a given value. The results will become the working inventory. Thereby, searching behaves like a form of filtering.  
   * Filter inventory contents  
     The user may set multiple filters using multiple criteria, with target values being entered manually. Exact matches will become the set of items, that is set to be the working inventory.  
   * Unset filters and searches  
     This empties the selected list of entries (via searching or filtering alike) and the working inventory becomes the entire original inventory instead.  
   * Print out inventory contents to screen  
     Every time, only one entry would be shown, but one can skip to other entries, proceed to next or return to main menu.  
   * Sorting the working inventory.  
     The inventory could be sorted by each attribute in ascending order. While the working inventory could be sorted, the effects would not be written back to the whole main inventory (the superset of the selected ones), unless the main inventory is sorted.  
   * Set a new stockpile warning level to a commodity entry, specified by its id  
   * Stockpile checking  
     This is performed every time the main menu is loaded and one may perform it once more by explicitly requesting it. It will issue warnings printed on top of the main menu, with information about item id, name and stock issue details.  
   * Exiting the application
 
 #### Input/Output Specifications
   This application accepts input either manually or from files.  
   
   For manual input, the user is supposed to type in the values as instructed and then hit enter/return. Note that entering non-numeric values may occassionally be interpreted as a zero being entered so do avoid that at all costs and be careful. This is due to C++'s built in functions' design.  
   
   For file input and output, the following illustrates the way input/output files are organized:
   * Importing and exporting entries  
     In this case, each line in the input/output file (\*.txt) is an entry in the inventory table. **No empty lines should be present in the file.** From left to right, each attribute is **_separated by semicolons (;)_** and attributes are in the order of: **id; name; manufacturer; unit price; expiry date (ddmmyyyy, all zeros when not applicable); HQ stock amount; stockpile warning level; shop id; shop stockpile amount**. An example of an entry of a book is as follows:  
     > 000003;Deutsch als Fremdsprache: Themen Aktuell 1;Hueber;300.00;00000000;100;15;0001;20  
   * Adding entries via file  
     Each file should contain *only one* entry. The entry comes in the same format as described above.  
   * Updating entries by file  
     The file (txt) should be organized such that the **first line of the input is the number of updates**. Let the first line be of value _n_, then the following n lines shall contain **id of the item to edit, mnemonic of attribute to change, value to change to**, semicolon separated. The correspondence of mnemonics are as follows (mnemonic on the right):  
     > ID : id  
     > Name : name  
     > Manufacturer : manu  
     > Unit price: price  
     > Expiry date: date  
     > Amount at HQ/Warehouse: amt  
     > Shop ID: shop  
     > Shop amount: samt  
     
     As a result, an example of editing entries is as follows:  
     > 3  
     > 000003;name;Deutsch als Fremdsprache: Themen Aktuell 2  
     > 000003;amt;350  
     > 000007;name;SU can coupon  
 
 #### Compilation and Execution Producedures
  To compile this application, one executes **_make project_** in a Bash shell where make is available. The executable would be named **_project_**. Run it directly to get the application running.  

