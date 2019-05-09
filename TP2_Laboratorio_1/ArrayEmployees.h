typedef struct
{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
	int isEmpty;

}Employee;

int menu();

void initEmployees(Employee* list, int len);
int findEmpty(Employee* list, int len);
int findEmployeeById(Employee* list, int len, int id);

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int removeEmployee(Employee* list, int len, int id);
int modifyEmployee(Employee* list, int len, int id);
void printEmployee(Employee emp);
int printEmployees(Employee* list, int length);
int sortEmployees(Employee* list, int len, int order);
