// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    // defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double numberToFind);

    // defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example not found
    if (matchPtr != NULL)

        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);

    else

        printf("Employee ID is NOT found in the record\n");

    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

    if (matchPtr != NULL)

        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);

    else

        printf("Employee Tony Bobcat is NOT found in the record\n");

    // example phone found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-555-1215");

    if (matchPtr != NULL)
        printf("310-555-1215 is the number found in %d\n", matchPtr - EmployeeTable);
    else
        printf("310-555-1215 is NOT found in the record\n");

    // example phone not found
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "555-555-1215");

    if (matchPtr != NULL)
        printf("555-555-1215 is the number found in %d\n", matchPtr - EmployeeTable);
    else
        printf("555-555-1215 is NOT found in the record\n");

    // example salary found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);

    if (matchPtr != NULL)
        printf("$4.50 is the salary found in %d\n", matchPtr - EmployeeTable);
    else
        printf("$4.50 is NOT found in the record\n");

    // example salary not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.51);

    if (matchPtr != NULL)
        printf("$4.51 is the salary found in %d\n", matchPtr - EmployeeTable);
    else
        printf("$4.51 is NOT found in the record\n");

    return EXIT_SUCCESS;
}