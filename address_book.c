#include "address.h"

static void CheckCapacity(Contact* pc)
{
    if(pc->count == pc->capacity)
    {
        PeoInfo* str = (PeoInfo*)realloc(pc->data,(pc->capacity+INC_SZ)*sizeof(PeoInfo));
        if(str == NULL)
        {
            printf("AddContact::%s\n", strerror(errno));
        }
        else
        {
            pc->data = str;
            pc->capacity += INC_SZ;
            printf("增容成功!\n");
        }
    }
}

void LoadContact(Contact* pc)
{
    FILE* pfRead = fopen("contact.txt", "r");
    if(pfRead == NULL)
    {
        perror("LoadContact");
        return ;
    }
    PeoInfo tmp = {0};

    while(fread(&tmp, sizeof(PeoInfo), 1, pfRead))
    {
        CheckCapacity(pc);
        
        pc->data[pc->count] = tmp;
        pc->count++;
    }

    fclose(pfRead);
    pfRead = NULL;
}

// //静态的版本
// void InitContact(Contact* pc)
// {   
//     assert(pc);
//     pc->count = 0;
//     memset (pc->data, 0, sizeof(pc->data)); 
// }

//动态的版本
int InitContact(Contact* pc)
{   
    assert(pc);
    pc->count = 0;
    pc->data = (PeoInfo*)calloc(DEFAULT_SZ,sizeof(PeoInfo));
    if(pc->data == NULL)
    {
        printf("InitContact::%s\n", strerror(errno));
        return 1;
    }
    pc -> capacity = DEFAULT_SZ;
    //加载文件的信息到通讯录中
    LoadContact(pc);
    return 0;
}

// //静态的版本
// void AddContact(Contact* pc)
// {
//     assert(pc);
//     if(pc->count == MAX)
//     {
//         printf("通讯录已满，无法添加\n");
//         return;
//     }
//     printf("请输入名字:>");
//     scanf("%s", pc->data[pc->count].name);
//     printf("请输入年龄:>");
//     scanf("%d", & (pc->data[pc->count].age));
//     printf("请输入性别:>");
//     scanf("%s", pc->data[pc->count].sex);
//     printf("请输入电话:>");
//     scanf("%s", pc->data[pc->count].tele);
//     printf("请输入地址:>");
//     scanf("%s", pc->data[pc->count].addr);

//     pc->count ++;
//     printf("增加成功!\n");
// }

//动态的版本
void AddContact(Contact* pc)
{
    assert(pc);
    CheckCapacity(pc);

    printf("请输入名字:>");
    scanf("%s", pc->data[pc->count].name);
    printf("请输入年龄:>");
    scanf("%d", & (pc->data[pc->count].age));
    printf("请输入性别:>");
    scanf("%s", pc->data[pc->count].sex);
    printf("请输入电话:>");
    scanf("%s", pc->data[pc->count].tele);
    printf("请输入地址:>");
    scanf("%s", pc->data[pc->count].addr);

    pc->count ++;
    printf("增加成功!\n");
}

void ShowContact(const Contact* pc)
{
    assert(pc);
    int i = 0;
    printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n","名字", "年龄","性别","电话","地址");
    for(i=0;i<pc->count;i++)
    {
        printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n",
        pc->data[i].name,pc->data[i].age,pc->data[i].sex,pc->data[i].tele,pc->data[i].addr);
        
    }
}

static int FindName(Contact* pc, char name[])
{
    assert(pc);
    int i = 0;
    for(i=0;i<pc->count ;i++)
    {
        if(0 == strcmp(pc->data[i].name, name))
            return i;
    }
    return -1;
}

void DelContact(Contact* pc)
{
    assert(pc);
    int i = 0;
    if(pc->count == 0)
    {
        printf("通讯录为空，没有信息可以删除\n");
        return;
    }
    char name[MAX_NAME];
    printf("请输入要删除人的名字:>");
    scanf("%s", name);

    //删除
    //1.查找
    int pos = FindName(pc, name);
    if(pos == -1)
    {
        printf("要删除的人不存在!\n");
        return;
    }
    //2.删除
    for(i = pos; i<pc->count -1; i++)
    {
        pc->data[i] = pc->data[i+1];
    }
    pc -> count --;
    printf("删除成功\n");
}

void SearchContact(Contact* pc)
{
    assert(pc);
    int i = 0;
    if(pc->count == 0)
    {
        printf("通讯录为空，没有信息可以查找\n");
        return;
    }
    char name[MAX_NAME];
    printf("请输入要查找人的名字:>");
    scanf("%s", name);
    //1.查找
    int pos = FindName(pc, name);
    if(pos == -1)
    {
        printf("要查找的人不存在\n");
        return;
    }
    //2.打印
    printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n","名字", "年龄","性别","电话","地址");
    printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n",
            pc->data[pos].name,pc->data[pos].age,pc->data[pos].sex,pc->data[pos].tele,pc->data[pos].addr);
}

void ModifyContact(Contact* pc)
{
    assert(pc);
    int i = 0;
    if(pc->count == 0)
    {
        printf("通讯录为空，没有信息可以修改\n");
        return;
    }
    char name[MAX_NAME];
    printf("请输入要修改人的名字:>");
    scanf("%s", name);
    //1.查找
    int pos = FindName(pc, name);
    if(pos == -1)
    {
        printf("要修改的人不存在\n");
        return;
    }
    printf("要修改的人的信息已经查找到，接下来开始修改.\n");
    //2.修改
    printf("请输入名字:>");
    scanf("%s", pc->data[pos].name);
    printf("请输入年龄:>");
    scanf("%d", & (pc->data[pos].age));
    printf("请输入性别:>");
    scanf("%s", pc->data[pos].sex);
    printf("请输入电话:>");
    scanf("%s", pc->data[pos].tele);
    printf("请输入地址:>");
    scanf("%s", pc->data[pos].addr);

    printf("修改成功！\n");    
}

static int cmp_peo_by_name(const void* e1,const void* e2)
{
    return strcmp(((PeoInfo*)e1)->name,((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)
{
    assert(pc);
    qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
    printf("排序成功！\n");
}

void DestroyContact(Contact* pc)
{
    assert(pc);
    free(pc->data);
    pc->data = NULL;
}

void SaveContact(const Contact* pc)
{
    assert(pc);
    FILE* pfWrite = fopen("contact.txt", "wb");
    if(pfWrite == NULL)
    {
        perror("SaveContact");
        return;
    }

    int i = 0;
    for(i=0;i<pc->count;i++)
    {
        fwrite(pc->data+i, sizeof(PeoInfo), 1, pfWrite);
    }

    fclose(pfWrite);
    pfWrite = NULL;
}
