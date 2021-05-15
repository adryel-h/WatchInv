# Watch Inventory

## Description

The program mananges an inventory of Watches. It has a file (databases.csv) that contains all the current watches and at run-time the program will load all watches into the repository
and the user will then be able to:

- view all watches in the repository
- add a watch to the repository
- view only the smart/mechanical watches
- remove a watch by it's ID
- undo the previous operation (add or remove)

After exiting the application, the program will update the file (databases.csv) such that all changes made by the user are saved.
## Tests
The TestClass class is obviously used for testing the program. The files: TestDatabase.csv, TestSave.csv have the same scope of aiding the TestClass class in it's role of testing
the program. All the other classes/files are directly responsable for the functionality of the program
