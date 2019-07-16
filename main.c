#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//**************************
struct worker{
	char num[20];	//雇员工号
	char name[20];	//雇员姓名
	char sex[6];	//雇员性别
	char age[6];	//雇员年龄
	char worksection[20];//雇员所在部门
}worker[100];		//最大录入100位员工资料

 int n=0;		//定义一个全局变量n
//**************************
void logmemu();//登陆界面函数
int login();//登录函数
void mainmenu();//主菜单函数
void power();//关于我们函数
void show();//雇员信息显示函数
void add();//雇员信息添加函数
void alter();//雇员信息修改函数
void del();//雇员信息删除函数
void search();//雇员信息查找函数
void read(); 	//文件读取函数
void save();	//文件写入函数
//****************************

int main()
{
	system("color 3B");//背景色与前景色控制
	logmemu();	//运行登陆界面
	if (n==0) read();//运行文件操作

}

void logmemu()//登录界面
{
	char choice;
	do
	{
		system ( "cls" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t**************** Welcome to use the system *************" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t                 罗德岛雇员管理系统登录菜单          " );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t*                   1.管理员登录                       *" );
		printf ( "\n\t*                   2.制作人员名单                     *" );
		printf ( "\n\t*                   0.退出系统                         *" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t             请使用人员输入对应数字进行操作  [ ]\b\b" );
		choice = getch();
		switch ( choice )
		{
		case'1':
			if ( login() == 1 )
			{
				mainmenu();
			}
			else
			{
				printf ( "\n管理员账号登录失败\n" );
			}
			break;
		case'2':
			power();
			break;
		case'0':exit ( 0 );
			break;
		default:
			printf ( "\n\t************输入数字错误！请在输入合法的数字选项！**********" );
			break;
		}
	}
	while ( choice != '0' );
}

int login()
{
	char administrator[ ] = "ad";		//设置管理员登录账号
	char administrator_pwd[ ] = "123";	//设置管理员登录密码
	char input_administrator[20];
	char input_administrator_pwd[20];
	int i,j;			//i用来限制账号登录失败后重新登录的次数,j是掩码下标
	int count = 0;			//count用来记录尝试登陆了多少次,

	for ( i = 0; i < 3; i++ )
	{
	printf ( "\n\t请输入管理员账号:" );
	scanf ( "%s", input_administrator );

	printf ( "\n\t请输入管理员密码:" );
	for(j=0;j<20;j++)		   		//掩码模块******
        {
            input_administrator_pwd[j]=getch();
            printf("*");				//将输入的密码用掩码显示
            if(input_administrator_pwd[j]==13) break;	//当输入回车时跳出循环
        }input_administrator_pwd[j]='\0';   		//输入完成后将最后一位替换成\0形成字符串
							//掩码模块结束******
	if ( strcmp ( administrator, input_administrator ) == 0 && strcmp ( administrator_pwd, input_administrator_pwd ) == 0 )//判断用户名和密码
	{return 1;}
	count++;
	if ( count >= 3 )
		{
		printf ( "\n输入达到上限，为确保账号安全将直接退出本系统！\n" );
		exit ( 0 );
		}
		printf ( "\n您输入的密码或账号错误！您还剩余%d次机会!\n", ( 3 - count ) );
	}
	return 0;
}

void mainmenu(){//主菜单界面

	char choice;
	do
	{
		system ( "cls" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t                  罗德岛雇员系统主菜单                  " );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t*                   1.显示雇员信息                     *" );
		printf ( "\n\t*                   2.录入雇员信息                     *" );
		printf ( "\n\t*                   3.修改雇员信息                     *" );
		printf ( "\n\t*                   4.删除雇员信息                     *" );
		printf ( "\n\t*                   5.查询雇员信息                     *" );
		printf ( "\n\t*                   0.返回系统登录菜单                 *" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t             请使用人员输入对应数字进行操作  [ ]\b\b" );
		choice = getch();
		switch ( choice )
		{
		case'1':read();show();system("pause");system("cls");
			break;
		case'2':add();
			break;
		case'3':alter();
			break;
		case'4':del();
			break;
		case'5':search();
			break;
		case'0':logmemu();
			break;
		default:printf ( "\n\t************输入数字错误！请在输入合法的数字选项！**********" );
			break;
		}
	}
	while ( choice != '0' );
}

void power(){//关于我们界面

	system("cls");
		printf ( "\n\t********************************************************" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t                  罗德岛雇员-系统关于我们             " );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t*                   1.技术支持：mizuhokaga             *" );
		printf ( "\n\t*                   2.售后人员：mizuhokaga             *" );
		printf ( "\n\t*                   0.返回上一级菜单                   *" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t********************************************************" );
	system("pause");
}

void show(){//显示雇员信息函数
	read();
	int i;//i为下标控制循环
	if(n<=0){
		system("cls");
		printf("\n\t无任何雇员，请先进行雇员招募\n");
		return ;
	}
	else{
		system("cls");
	for(i=0;i<n;i++){

		printf("\n");
		printf("\n\t工号\t姓名\t性别\t年龄\t部门\n");
		printf("\t%s \t%s \t%s \t%s \t%s \n",worker[i].num,worker[i].name,worker[i].sex,worker[i].age,worker[i].worksection);

		}

		//system("pause");

	}

}

void add(){//添加雇员信息函数
	int i;
	int flag;
	char choice;
	if(n>=100)
	{printf ( "\n\t   系统数据已满请联系技术人员    " );
		return ;
	}
	printf("\n");
	printf("\n");
	do{
	system("cls");
	flag=0;
	printf("\n");
	printf("\t\t\t<按 0与回车键 返回主界面> \n");
	printf("\t\t请输入员工工号:");
	scanf("%s",worker[n].num);
	if(strcmp(worker[n].num,"0")==0)//误入添加界面按0与回车键 返回主界面
	{ mainmenu();
	}
	for(i=0;i<n;i++){
		if(strcmp(worker[i].num,worker[n].num)==0){
				flag=1;
				break;
			}
			}
	if(flag){//比较员工号与输入的是否一致
		printf("\n\t   该员工号已存在，请重新输入:");
		printf("\n\t是否继续录入雇员信息?(y|n)\n");
		choice=getch();
		if(choice=='y'||choice=='Y'){
			flag=1;
		}
		else{
			flag=0;}
	}
	printf("\t\t请输入姓名:");
	scanf("%s",worker[n].name);
	printf("\t\t请输入员工性别:");
	scanf("%s",worker[n].sex);
	printf("\t\t请输入员工年龄:");
	scanf("%s",worker[n].age);
	printf("\t\t请输入员工部门:");
	scanf("%s",worker[n].worksection);
	printf("\t\t您录入的雇员信息:\n");
	printf("\n\t工号\t姓名\t性别\t年龄\t部门\n");
	printf("\t%s \t%s \t%s \t%s \t%s  \n",worker[n].num,worker[n].name,worker[n].sex,worker[n].age,worker[n].worksection);
		n++;
	printf("\n\t是否继续录入雇员信息?(y|n)\n");
		choice=getch();
		if(choice=='y'||choice=='Y'){
			flag=1;
		}
		else{
			flag=0;
		}

	}while((choice=='y'||choice=='Y'));
	save();
	printf("\n\t添加成功!\n");

}

void alter(){//修改雇员信息函数
	char info[50];	//修改完毕的雇员信息
	char change[20];//需要修改的雇员的工号
	int number;	//雇员信息在数据的位置
	int flag;
	char choice;
	int i;
	char menuchoice;//修改菜单的选择变量
	read();
	while(1){
			flag=0;
	system("cls");
	printf("\n\t请输入需要修改信息的雇员工号\n");
	printf("\n\t工号：");scanf("%s",change);
	for(i=0;i<n;i++){

		if(strcmp(worker[i].num,change)==0)
		{	flag=1;
			number=i;
			break;
		}
	}
	if(!flag){
		printf("\n\t无此雇员信息！！");
		printf("\n\t是否继续修改雇员信息?(y|n)\n");
		choice=getch();
		if(choice=='y'||choice=='Y'){
			flag=1;
		}
		else{
			flag=0;}
	}
	printf ( "\n\t********************************************************" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t                  罗德岛雇员修改界面                    " );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t*                   1.修改雇员工号                     *" );
		printf ( "\n\t*                   2.修改雇员姓名                     *" );
		printf ( "\n\t*                   3.修改雇员性别                     *" );
		printf ( "\n\t*                   4.修改雇员年龄                     *" );
		printf ( "\n\t*                   5.修改雇员所在部门                 *" );
		printf ( "\n\t*                   0.返回主菜单                       *" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t             请使用人员输入对应数字进行操作  [ ]\b\b" );
		menuchoice = getch();
		printf("\n\t请输入修改后的信息:");
		scanf("%s",info);
		switch(menuchoice){
			case'1':strcpy(worker[number].num,info);break;
			case'2':strcpy(worker[number].name,info);break;
			case'3':strcpy(worker[number].sex,info);break;
			case'4':strcpy(worker[number].age,info);break;
			case'5':strcpy(worker[number].worksection,info);break;
			case'0':mainmenu();break;
		}
		system("cls");
		printf("\n\t是否继续修改？（y|n）\n");
		choice=getch();
		if(choice=='y'||choice=='Y'){
			flag=1;
		}
		else{
			flag=0;
		}break;

	}save();
}

void del(){//删除雇员信息函数
	char choice;
	char del[20];//定义查找的一个字符串数组
	int i,j;//j是删除某个数组后交换，后面数组的一个变量;i是下标
	int flag;
	do{
		system("cls");
		flag=0;
		printf("\n\t请输入需要删除的雇员工号:");
		scanf("%s",del);
		for(i=0;i<n;i++)
		{
			if(strcmp(worker[i].num,del)==0)
				{
				n--;
				flag=1;
				for(j=i;j<n;j++)
				{
					worker[j]=worker[j+1];
				}break;

				}

		}
		if(!flag)
		{printf("\n\t无此人\n");
		 printf("\n\t是否继续继续删除雇员信息(按n返回主菜单)?(y|n)\n");
		 choice=getch();
		 if(choice=='y'||choice=='Y')
		 {flag=1;}
		 else {flag=0;}
		}
		else{
			printf("\n\t删除成功!\n");
			printf("\n\t是否继续继续删除雇员信息(按n返回主菜单)?(y|n)\n");
			choice=getch();
			if(choice=='y'||choice=='Y')
			{flag=1;}
			else {flag=0;}
			}
		}while((choice=='y'||choice=='Y'));
		save();
}

void search(){//查找雇员信息函数
	int i,j;
	char searchchoice;
	char searchname[20];//查找姓名的数组
	char searchnum[20];//查找工号的数组
	char choice,flag;

	while(1){

		system ( "cls" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t                 罗德岛雇员查询界面          " );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t*                   1.按雇员工号查询                   *" );
		printf ( "\n\t*                   2.按雇员姓名查询                   *" );
		printf ( "\n\t*                   0.返回主菜单                       *" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t********************************************************" );
		printf ( "\n\t             请使用人员输入对应数字进行操作  [ ]\b\b" );
		scanf("%s",&searchchoice);
		j =0;
		if(searchchoice=='1'){
			printf ( "\n\t请输入您需要查询的雇员的工号:" );
			scanf("%s",searchnum);
			for(i=0;i<n;i++)
			{	if(strcmp(worker[i].num,searchnum))
				{
		printf("\n");
		printf("\n\t工号\t姓名\t性别\t年龄\t部门\n");
		printf("\t%s \t%s \t%s \t%s \t%s \n",worker[i].num,worker[i].name,worker[i].sex,worker[i].age,worker[i].worksection);
			j=1;
				}
			}
		}else if(searchchoice=='2'){
			printf ( "\n\t请输入您需要查询的雇员的姓名:" );
			scanf("%s",searchname);
			for(i=0;i<n;i++)
			{	if(strcmp(worker[i].name,searchname))
				{
		printf("\n");
		printf("\n\t工号\t姓名\t性别\t年龄\t部门\n");
		printf("\t%s \t%s \t%s \t%s \t%s \n",worker[i].num,worker[i].name,worker[i].sex,worker[i].age,worker[i].worksection);
			j=1;
				}
			}

		}
		else if(searchchoice=='0'){mainmenu();}

		if(!flag){
			printf("\n\t\t系统查无此雇员!");
			printf("\n\t是否继续查询？（y|n）\n");
		choice=getch();
		if(choice=='y'||choice=='Y'){
			flag=1;
		}
		else{
			mainmenu();
		}break;
		}
	}

}

void save(){//保存雇员信息

    FILE *fp;
    int j;
    fp=fopen("c:\\雇员信息.txt","a+");//在c盘根目录下创建一个txt文件来储存雇员信息
    for(j=0;j<n;j++)
    {
    	fputs(worker[j].name,fp);
    	fprintf(fp,"\n");
    	fputs(worker[j].num,fp);
    	fprintf(fp,"\n");
    	fputs(worker[j].sex,fp);
    	fprintf(fp,"\n");
    	fputs(worker[j].age,fp);
    	fprintf(fp,"\n");
    	fputs(worker[j].worksection,fp);
    	fprintf(fp,"\n");

   }
    fclose(fp);
}

void read(){//读取雇员信息

    FILE *pr;
   pr=fopen("c:\\雇员信息.txt","r+");

    while(fscanf(pr,"%s %s %s %s %s",worker[n].name,worker[n].num,worker[n].sex,worker[n].age,worker[n].worksection)!=EOF)
    {
        n++;
    }
    fclose(pr);
}

