 Stock Management and Billing System
 
 Made by Team Debuggers
 Abdullah Arif (BITF25A012) | Shehzada Ather (BITF25A047)
 Programming Fundamentals — Final Project

---
-> What is this program?

This is a stock management and billing program. It helps you keep track of your items in a shop or any business, 
manage prices, give discounts, and make bills for customers. It also saves customer records so you can look at them later.

---

-> What can it do?

* Admin can:
- Log in with a username and PIN
- View all items in stock
- Add new items
- Change the quantity or price of any item
- Delete an item
- Add discounts on specific items
- Add discounts on the whole bill
- View all past customer records
- Add new admins
- Change their own username
- Change their own PIN

User can:
- Log in or sign up
- Search items by item codes
- Search items by item name
- Check discount on whole bill
- Check discount on Items by name
- Check discount on Items by item code
- Buy items by entering item codes
- Get a receipt at the end with the total bill, discounts, date, and time

---

-> Files the program uses

The program reads and saves data using these text files.
Make sure they are in the same folder as the program:

- `Admin.txt` — stores admin usernames and PINs
- `stock.txt` — stores all items (code, quantity, price, name)
- `customerRecord.txt` — stores past customer bills
- `DiscountedItems.txt` — stores items that have a discount
- `DiscountOnBill.txt` — stores the discount percentage on the whole bill

---

-> How to run it

1. Make sure you have a C++ compiler (like g++ or MinGW)
2. Put all the .txt files in the same folder as the program
3. Compile the file:
   g++ Debuggers.cpp -o Debuggers
4. Run it:
   ./Debuggers

---

-> How to use it

When you open the program, it will ask you to pick a role:
- Press 1 for Admin
- Press 2 for User/Customer
- Press 0 to exit

Just follow the menu on screen. Everything is step by step.

---

-> Notes

- If a .txt file is missing, the program will show an error
- Discounts are saved as percentages
- Item codes must be unique
- The program saves bills automatically after checkout
