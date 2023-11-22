#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


#define INC_SZ 2
#define DEFAULT_SZ 3
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

//人的信息
typedef struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
} PeoInfo;

// //通讯录(静态版本)
// typedef struct Contact
// {
//     PeoInfo data[MAX];  //存放人的信息
//     int count;      //存放人的个数
// } Contact;

//通讯录(动态版本)
typedef struct Contact
{
    PeoInfo* data;  //存放人的信息
    int count;      //存放人的个数
    int capacity;   //当前通讯录的容量
} Contact;

//初始化通讯录
int InitContact(Contact* pc);

//增加联系人到通讯录
void AddContact(Contact* pc);

//显示通讯录中信息
void ShowContact(const Contact* pc);

//删除联系人
void DelContact(Contact* pc);

void DestroyContact(Contact* pc);

//查找联系人
void SearchContact(Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);

//排序通讯录中的内容(名字)
void SortContact(Contact* pc);

//保存通讯了
void SaveContact(const Contact* pc);

//加载文件的信息到通讯录
void LoadContact(Contact* pc);