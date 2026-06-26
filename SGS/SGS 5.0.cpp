#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
#include <string>
#define edition "5.0"
using namespace std;
//一堆注释//////////////////////////////////////////////////////// 
//多加两张兵粮寸断 (军争)
int shenfen,comshenfen;//玩家武将身份 电脑武将身份 
int niepan;//庞统 :涅槃 
int sijie;//审配 ：死节 
int haoqiang,luanji;//袁绍 ：豪强，乱击 
int jianxiong;//曹操 ：奸雄 
int weidi=14;//袁术 ：伪帝 
int jianshou;//曹仁 ：坚守 
int huben;//许褚 ：虎贲 
int leijishanghai;//张角：累计伤害 
int luoshen,qingcheng;//甄宓 //洛神，倾城 
int wodehuihe,difanghuihe;//贾诩 ：完杀 
int luanwu;//贾诩：乱武 
int roulin;//董卓：肉林 
int kurou;//黄盖：苦肉 
int gongxin,sizhonghuase[4];//吕蒙 ：攻心 
int lihun;//貂蝉 ：离魂 
int liyu;//吕布 ；利驭 
int qianghun,biao;//赵云：枪魂 
int shiyong;//华雄：恃勇 
int tiaodao,renchuan,shao;//麦克阿瑟：跳岛 ,仁川登陆 ,减少麻烦 
int shixue;//日本鬼子：嗜血 
int chaofeng,wansui;//dong
int wzshenyou;//无中生有 
int jiu;//【酒】 
int wanjialishi,comlishi,wanjiaxin,comxin,check_flag,bug_1;//玩家历史，电脑历史，玩家战绩，电脑战绩 ，查询标记 bug1:查询战绩总是累加 
string score;
void color(int a)//多种颜色 
{
/*亮白*/              if(a==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
/*蓝色*/              if(a==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
/*绿色*/              if(a==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
/*紫色*/              if(a==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
/*红色*/              if(a==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
/*黄色*/              if(a==5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
/*深蓝色*/            if(a==6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
/*土黄色or金黄色*/    if(a==7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);
/*灰色接近白*/        if(a==8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
/*青色*/			  if(a==9) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
}
void thank()
{
	color(2);
	system("cls");
	cout<<"感谢LI HAOXUAN,DONG WEIZHE,Mr.Dong,TT,in-提供的大力支持\n";
	Sleep(1000);
	cout<<"感谢以下网站提供的帮助:\n";
	Sleep(1000);
	cout<<"1.https://www.kktt.cn/ 图片转换格式\n";
	Sleep(1000);
	cout<<"2.https://www.sanguosha.com/wallpaperv 狗卡壁纸\n";
	Sleep(1000);
	cout<<"3.csdn.net 博客\n";
	Sleep(1000);
	system("pause");
	system("cls"); 
}
void speak()
{
    int k=rand()%9,t=rand()%9;
    color(t);
    if(k==0)
    {
    	cout<<"就这么建！——TT\n";
	}
    if(k==1)
    {
    	cout<<"切，强个屁。--Mr.Dong\n";
	}
	if(k==2)
    {
    	cout<<"见了老子还想跑！--Mr.Dong\n";
	}
	if(k==3)
    {
    	cout<<"以我有限的智慧，你肯定是抄的！--Mr.Dong\n";
	}
	if(k==4)
    {
    	cout<<"就这水平？--TT\n";
	}
	if(k==5)
	{
		cout<<"千万不要火并啊！——吴用\n";
	} 
	if(k==6)
	{
		cout<<"TO BE OR NOT TO BE，THIS IS A PROBLEM.----哈姆雷特\n";
	}
	if(k==7)
	{
		cout<<"业根！死期至矣！而翁归，自与汝复算尔！——成妻\n";
	}
	if(k==8)
	{
		cout<<"要是老师穿拖鞋上课，学生岂不是要用头走路？这难道不是显而易见的吗？——遂腾-击相\n";
	} 
	color(9);
    return ;
}
void save()//保存 
{
	char ch='-',kongge=' ';
	time_t now_time;
    now_time = time(NULL);
    struct tm* local_time;
    local_time = localtime(&now_time);
	ofstream outfile("data.txt", ios::binary | ios::app | ios::in | ios::out);
	outfile<<asctime(local_time)<<ch<<kongge<<wanjiaxin<<kongge<<comxin<<endl;
	outfile.close();
	/*时间另一种获取方式
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	outname << sys.wYear << "年" << sys.wMonth << "月" << sys.wDay << "日" << sys.wHour << "时" << sys.wMinute << "分" << sys.wSecond << "秒" << endl; 
	*/
}
struct pai//结构体：牌  
{
	//黑桃：0   红桃:1   草花：2    方片：3 
    int paifu;
    int huase;
    int yanse;
    int dianshu;
    int leixing;
    int changdu;
    void Kanpai()
    {
		if(paifu==0||paifu==1);
		else
		{
			color(4);
			printf("牌副参数错误！\n");
			color(9);
		}
		switch(huase)
		{
		    case 0:cout<<"黑桃";break;
		    case 1:cout<<"红桃";break;
		    case 2:cout<<"草花";break;
		    case 3:cout<<"方片";break;
		    case -1:cout<<"无色";break;
		    color(4);
		    default:printf("花色错误！\n");color(9);break;
		}
		switch(dianshu)
		{
		    case 0:cout<<"A ";break;
		    case 1:cout<<"2 ";break;
		    case 2:cout<<"3 ";break;
		    case 3:cout<<"4 ";break;
		    case 4:cout<<"5 ";break;
		    case 5:cout<<"6 ";break;
		    case 6:cout<<"7 ";break;
		    case 7:cout<<"8 ";break;
		    case 8:cout<<"9 ";break;
		    case 9:cout<<"10 ";break;
		    case 10:cout<<"J ";break;
		    case 11:cout<<"Q ";break;
		    case 12:cout<<"K ";break;
		    case -1:cout<<"无点数";break;
		    color(4);
		    default:printf("点数错误！\n"); color(9);break;
		}
		switch(leixing)
		{
		    case 101:cout<<"【杀】"<<endl;break;
		    case 102:cout<<"【闪】"<<endl;break;
		    case 103:cout<<"【桃】"<<endl;break;
		    case 201:cout<<"【过河拆桥】"<<endl;break;
		    case 202:cout<<"【顺手牵羊】"<<endl;break;
		    case 203:cout<<"【无中生有】"<<endl;break;
		    case 204:cout<<"【决斗】"<<endl;break;
		    case 205:cout<<"【借刀杀人】"<<endl;break;
		    case 206:cout<<"【桃园结义】"<<endl;break;
		    case 207:cout<<"【五谷丰登】"<<endl;break;
		    case 208:cout<<"【南蛮入侵】"<<endl;break;
		    case 209:cout<<"【万箭齐发】"<<endl;break;
		    case 210:cout<<"【无懈可击】"<<endl;break;
		    case 251:cout<<"【乐不思蜀】"<<endl;break;
		    case 252:cout<<"【闪电】"<<endl;break;
		    case 301:cout<<"【诸葛连弩(1)】"<<endl;break;
		    case 302:cout<<"【雌雄双股剑(2)】"<<endl;break;
		    case 303:cout<<"【青釭剑(2)】"<<endl;break;
		    case 304:cout<<"【青龙偃月刀(3)】"<<endl;break;
		    case 305:cout<<"【丈八蛇矛(3)】"<<endl;break;
		    case 306:cout<<"【贯石斧(3)】"<<endl;break;
		    case 307:cout<<"【方天画戟(4)】"<<endl;break;
		    case 308:cout<<"【麒麟弓(5)】"<<endl;break;
		    case 331:cout<<"【八卦阵】"<<endl;break;
		    case 361:cout<<"【赤兔(-1)】"<<endl;break;
		    case 362:cout<<"【大宛(-1)】"<<endl;break;
		    case 363:cout<<"【紫辛(-1)】"<<endl;break;
		    case 381:cout<<"【爪黄飞电(+1)】"<<endl;break;
		    case 382:cout<<"【的卢(+1)】"<<endl;break;
		    case 383:cout<<"【绝影(+1)】"<<endl;break;
		    case 384:cout<<"【兵粮寸断】"<<endl;break;
		    color(4);
		    default:printf("类型参数错误！");leixing=101;color(9);break;
		}
	}
};
void Qishixipai(pai A[2][4][13],pai paidui[104])//起始洗牌 
{
    int i,m,x,y,z,a[104]={0};//初始化为0 
    srand((unsigned)time(NULL));//随机数 
    for(i=1;i<=104;i++)
    {
        while(a[m=rand()%104]);
        {
            a[m]=i;
        }
    }
    for(i=0;i<=103;i++) 
    {
        x=(a[i]-1)/52;
        y=((a[i]-1)-52*x)/13;
        z=(a[i]-1)%13;
        paidui[i]=A[x][y][z];
    }
}
void Xipai(pai paidui[104],int*paiduishu,pai qipaidui[104],int*qipaishu)//洗牌 
{
	int i,m,a[104]={0};
	srand((unsigned)time(NULL));
	for(i=1;i<=(*qipaishu);i++)
	{
		while(a[m=rand()%(*qipaishu)]);
		a[m]=i;
	}
	for(i=0;i<=((*qipaishu)-1);i++)
	{
		paidui[i]=qipaidui[a[i]];
		qipaidui[a[i]].leixing=-1;
		(*paiduishu)++;
		(*qipaishu)--;
	}
	for(i=(*paiduishu);i<=103;i++)
	{
		paidui[i].leixing=-1;
	}
}
pai Mo1pai(pai A[104],int *x,pai B[104],int*y,int *b)//摸一张牌 
{
	pai p;
	if((*x)==0)
	{
		Xipai(A,x,B,y);
	}
	else if((*x)<0)
	{
		color(7);
		printf("摸牌参数错误！");
		color(9);
	}
	else;
	p=A[104-(*x)];
	(*x)--;
	(*b)++;
	return(p);
}
struct wujiang//观看手牌，装备牌，判定牌 
{
	char name;
	int tili;
	int tilishangxian;
	int shoupaishangxian;
	int huihekaishi;
	int panding;
	int mopai;
	int chupai;
	int qipai;
	int huihejieshu;
	int juese;
	pai shoupai[40];
	int shoupaishu;
	pai zhuangbei[4];
	int zhuangbeishu;
	pai pandingpai[3];
	int pandingshu;
	int juli[1];
	void Kanshoupai()//让玩家观看手牌 
	{
		printf("玩家当前手牌：\n");
		if(shoupaishu)
		{
			int m;
			for(m=0;m<=(shoupaishu-1);m++)
			{
				printf("%d ",m);
				(shoupai[m]).Kanpai();
			}
		}
		else 
		{
			color(5);
			printf("空城！\n");
			color(9);
		}
		printf("\n"); 
	}
	void Kanzhuangbei()//让玩家观看装备 
	{
		if(juese)printf("玩家");
		else printf("电脑");
		printf("当前装备：\n");
		///////////////////////////////////////////////////
		printf("0 武器： ");
		if((zhuangbei[0]).leixing==-1)color(5),printf("空\n"),color(9);
		else (zhuangbei[0]).Kanpai();
		//////////////////////////////////////////////////
		printf("1 防具： ");
		if((zhuangbei[1]).leixing==-1)color(5),printf("空\n"),color(9);
		else (zhuangbei[1]).Kanpai();
		//////////////////////////////////////////////////
		printf("2 进攻马： ");
		if((zhuangbei[2]).leixing==-1)color(5),printf("空\n"),color(9);
		else (zhuangbei[2]).Kanpai();
		/////////////////////////////////////////////////
		printf("3 防御马： ");
		if((zhuangbei[3]).leixing==-1)color(5),printf("空\n"),color(9);
		else (zhuangbei[3]).Kanpai();
		printf("\n");
	}
	void Kanpandingpai()//让玩家观看判定牌 
	{
		if(juese)printf("玩家");
		else printf("电脑");
		color(6);
		printf("当前判定区：\n");
		color(9);
		if((pandingpai[0]).leixing==-1)color(5),printf("空\n"),color(9);
		else
		{
			printf("0 ");
			(pandingpai[0]).Kanpai();
			if((pandingpai[1]).leixing==-1);
			else
			{
				printf("1 ");
				(pandingpai[1]).Kanpai();
				if((pandingpai[2]).leixing==-1);
				else
				{
					printf("2 ");
					(pandingpai[2]).Kanpai();
				}
			}
		}
	}
};
void Mopai(int*shoupaishu,pai shoupai[40],pai A[104],int *x,pai B[104],int*y,int juese)//摸牌   
{
	if(juese)
	{
		if(shenfen==15)
		{
			color(5);
			luoshen=0;
			printf("触发甄宓锁定技——洛神（准备阶段，你可以进行判定，若结果为黑色，你获得此牌，然后你可以重复此流程。）\n");
			color(9);
			while(luoshen==0)
			{
				pai p;
				p=Mo1pai(A,x,B,y,shoupaishu);
				shoupai[*shoupaishu-1]=p;
				p.Kanpai();
				if(p.huase==0||p.huase==2)
				{
					cout<<"你摸了一张牌\n";
					shoupai[*shoupaishu-1]=p;
				}
				else
				{
					color(4);
					cout<<"触发失败\n";
					luoshen=1;
					color(9);
				}
			}
		}
		if(shenfen==7&&wzshenyou==0)
		{
			color(5);
			cout<<"是否发动许褚锁定技——虎贲（少摸一张牌，杀与决斗伤害+1）\n";
			cout<<"是，按1\n";
			int x;
			cin>>x;
			if(x==1)
			{
				huben=1;
				printf("恭喜你获得许褚锁定技——虎贲（少摸一张牌，杀与决斗伤害+1）\n"); 
			} 
			color(9);
		} 
		else if(biao==0&&comshenfen!=2)
		{
			printf("玩家从牌堆摸2张牌\n");
		}
		if(shenfen==3&&wzshenyou==0)
		{
			color(5);
			printf("触发周瑜锁定技——英姿\n");
			color(9);
			pai g;
			g=Mo1pai(A,x,B,y,shoupaishu);
			shoupai[*shoupaishu-1]=g;
		}
		if(shenfen==25&&wzshenyou==0)
		{
			color(5);
			printf("触发Dong 韵存 锁定技——英姿\n");
			color(9);
			pai g;
			g=Mo1pai(A,x,B,y,shoupaishu);
			shoupai[*shoupaishu-1]=g;
		}
		if(shenfen==10&&wzshenyou==0)
		{
			color(5);
			printf("触发袁绍锁定技——2.豪强（可以多出一张杀，多摸一张牌）\n");
			color(9);
			pai g;
			g=Mo1pai(A,x,B,y,shoupaishu);
			shoupai[*shoupaishu-1]=g;
		}
		if(shenfen==9&&sijie==1&&wzshenyou==0)
		{
			sijie=0;
			color(5);
			cout<<"触发审配锁定技——死节\n";
			color(9);
			pai g,s,t;
			g=Mo1pai(A,x,B,y,shoupaishu);
			shoupai[*shoupaishu-1]=g;
			s=Mo1pai(A,x,B,y,shoupaishu);
			shoupai[*shoupaishu-1]=s;
			t=Mo1pai(A,x,B,y,shoupaishu);
			shoupai[*shoupaishu-1]=t;
		}
		if(shenfen==5&&wzshenyou==0)
		{
			color(5);
			int aw; 
			srand((unsigned)time(NULL));
			aw=rand()%10;
			if(aw%2==1)
			{
				 printf("触发曹操锁定技——屯田（摸牌时随机判定，若是奇数摸三张牌，偶数摸两张牌）\n");
				 cout<<"判定结果为奇数，多摸一张牌\n";
				 pai g; 
				 g=Mo1pai(A,x,B,y,shoupaishu);
			     shoupai[*shoupaishu-1]=g;
			}
			else
			{
				printf("触发曹操锁定技——屯田（摸牌时随机判定，若是奇数摸三张牌，偶数摸两张牌）\n");
				 cout<<"判定结果为偶数\n";
			}
			if(jianxiong>=2)
			{
				int a=jianxiong/2;
				printf("触发曹操锁定技——奸雄\n");
				printf("你摸了%d张牌\n",a);
				for(int i=1;i<=a;i++)
				{
					 pai g; 
					 g=Mo1pai(A,x,B,y,shoupaishu);
				     shoupai[*shoupaishu-1]=g;
				}
				jianxiong=jianxiong-2*a;
			}
			else
			{
				printf("无法触发曹操锁定技——奸雄\n");
			}
			color(9);
		}
		if(shenfen==11&&wzshenyou==0)
		{
			color(5);
			printf("触发袁术锁定技——伪帝（开局多摸14张牌，然后每回合依次递减2（到0为止））\n");
			for(int i=1;i<=weidi;i++)
			{
				 pai g; 
				 g=Mo1pai(A,x,B,y,shoupaishu);
			     shoupai[*shoupaishu-1]=g;
			} 
			printf("你摸了%d张牌\n",weidi);
			if(weidi>0)
			{
				weidi-=2;
			}
			color(9);
		}
		if(shenfen==7&&huben==1&&wzshenyou==0)
		{
			pai p;
			p=Mo1pai(A,x,B,y,shoupaishu);
			shoupai[*shoupaishu-1]=p;
		}
		else if(shenfen==23&&biao==1)
		{
			pai p;
			p=Mo1pai(A,x,B,y,shoupaishu);
			shoupai[*shoupaishu-1]=p;
		}
		else if(comshenfen==2&&!(jiu>0)&&shao==0)
		{
			color(4);
			cout<<"电脑触发道格拉斯-麦克阿瑟锁定技——围困（玩家摸牌阶段少摸一张牌）\n";
			pai p;
			p=Mo1pai(A,x,B,y,shoupaishu);
			shoupai[*shoupaishu-1]=p;
			color(9);
		}
		else
		{
			pai p;
			p=Mo1pai(A,x,B,y,shoupaishu);
			shoupai[*shoupaishu-1]=p;
			pai q;
			q=Mo1pai(A,x,B,y,shoupaishu);
			shoupai[*shoupaishu-1]=q;
		}
	}
	else 
	{
		color(3);
		printf("电脑从牌堆摸2张牌\n");
		color(9);
		pai p;
		p=Mo1pai(A,x,B,y,shoupaishu);
		shoupai[*shoupaishu-1]=p;
		pai q;
		q=Mo1pai(A,x,B,y,shoupaishu);
		shoupai[*shoupaishu-1]=q;
		if(shenfen==22&&liyu>=1)
		{
			printf("触发吕布锁定技——利驭(你使用杀对对方造成伤害时，摸对面一张牌，弃置对方一张牌，对方下回合多摸x张牌[x:你杀造成伤害的次数])\n"); 
			printf("电脑多摸了%d张牌\n",liyu); 
			for(int i=1;i<=liyu;i++)
			{
				 pai g[7]; 
				 g[i]=Mo1pai(A,x,B,y,shoupaishu);
			     shoupai[*shoupaishu-1]=g[i];
			}
		}
	} 
	if(shenfen==2&&niepan==1)
	{
		color(5);
		printf("触发庞统限定技——涅槃\n");
		niepan=3;
		pai g,s,t;
		g=Mo1pai(A,x,B,y,shoupaishu);
		shoupai[*shoupaishu-1]=g;
		s=Mo1pai(A,x,B,y,shoupaishu);
		shoupai[*shoupaishu-1]=s;
		t=Mo1pai(A,x,B,y,shoupaishu);
		shoupai[*shoupaishu-1]=t;
		color(9);
	} 
	int m;
	if(juese)//让玩家观看手牌(电脑不需要） 
	{
		printf("玩家当前手牌：\n");
		for(m=0;m<=(*shoupaishu-1);m++)
		{
			printf("%d ",m);
			(shoupai[m]).Kanpai();
		}
	}
	printf("牌堆还剩%d张牌！\n\n",*x);
}
void Qishishoupai(wujiang *w,pai A[104],int *x,pai B[104],int*y)//起始摸牌                                                  
{
	pai a;
	a=Mo1pai(A,x,B,y,&((*w).shoupaishu));
	(*w).shoupai[(*w).shoupaishu-1]=a;
	pai b;
	b=Mo1pai(A,x,B,y,&((*w).shoupaishu));
	(*w).shoupai[(*w).shoupaishu-1]=b;
	pai c;
	c=Mo1pai(A,x,B,y,&((*w).shoupaishu));
	(*w).shoupai[(*w).shoupaishu-1]=c;
	pai d;
	d=Mo1pai(A,x,B,y,&((*w).shoupaishu));
	(*w).shoupai[(*w).shoupaishu-1]=d;
	int m;
	if((*w).juese)
	{
		color(3);
		printf("玩家从牌堆摸4张牌\n");
		color(9);
		if(shenfen==10)
		{
			color(5);
			printf("触发袁绍限定技——1.四世三公（开局多摸七张牌）\n");
			color(9);
			for(int i=1;i<=7;i++)
			{
				pai a;
				a=Mo1pai(A,x,B,y,&((*w).shoupaishu));
				(*w).shoupai[(*w).shoupaishu-1]=a;
			 } 
		} 
		if(shenfen==14)
		{
			color(5); 
			printf("触发张角锁定技——黄天（开局体力-2，然后多摸4张牌）\n");
			color(9);
			((*w).tili)-=2;
			cout<<"你的体力： "<< ((*w).tili)<<endl;
			pai a;
			a=Mo1pai(A,x,B,y,&((*w).shoupaishu));
			(*w).shoupai[(*w).shoupaishu-1]=a;
			pai b;
			b=Mo1pai(A,x,B,y,&((*w).shoupaishu));
			(*w).shoupai[(*w).shoupaishu-1]=b;
			pai c;
			c=Mo1pai(A,x,B,y,&((*w).shoupaishu));
			(*w).shoupai[(*w).shoupaishu-1]=c;
			pai d;
			d=Mo1pai(A,x,B,y,&((*w).shoupaishu));
			(*w).shoupai[(*w).shoupaishu-1]=d;
		}
	}
	else 
	{
		color(7);
		printf("电脑从牌堆摸4张牌\n");
		color(9);
	}
	if((*w).juese)
	{
		printf("玩家当前手牌：\n");
		for(m=0;m<=((*w).shoupaishu-1);m++)
		{
			printf("%d ",m);
			((*w).shoupai[m]).Kanpai();
		}
	}
	printf("牌堆还剩%d张牌！\n\n",*x);
}
void Panding(pai paidui[104],int*paiduishu,pai qipaidui[104],int*qipaishu,wujiang*w1,wujiang*w2)//判定 
{
	paidui[*paiduishu].Kanpai();
	qipaidui[*qipaishu]=paidui[*paiduishu];
	(*paiduishu)--;
	(*qipaishu)++;
}
void GaiPanding(pai paidui[104],int*paiduishu,pai qipaidui[104],int*qipaishu,wujiang*w1,wujiang*w2)//张角改判
{
	color(5);
	printf("是否触发张角锁定技——鬼道（你可打出一张牌替换判定牌）\n");
	cout<<"是，输入1\n";
	color(9);
	int yw;
	cin>>yw;
	if(yw==1)
	{
		int y;
		pai w;
		if((*w1).juese)
		{
			(*w1).Kanshoupai();
			cout<<"输入弃置的牌\n";
			cin>>y;
			qipaidui[*qipaishu]=((*w1).shoupai)[y];
			w=qipaidui[*qipaishu];
			for(int i=y+1;i<=((*w1).shoupaishu);i++)
			{
				((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
			}
			((*w1).shoupaishu)--;
			(*qipaishu)++;
		}
		else
		{
			(*w2).Kanshoupai();
			cout<<"输入弃置的牌\n";
			cin>>y;
			qipaidui[*qipaishu]=((*w2).shoupai)[y];
			w=qipaidui[*qipaishu];
			for(int i=y+1;i<=((*w2).shoupaishu);i++)
			{
				((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
			}
			((*w2).shoupaishu)--;
			(*qipaishu)++;
		}
		color(5);
		cout<<"改判后的判定牌是："; 
		w.Kanpai();
		color(9);
	} 
	else
	{
		color(4);
		cout<<"未触发\n";
		color(9);
	}
} 
pai Zhangba(wujiang*w,pai qipaidui[104],int*qipaishu)//丈八蛇矛 
{
	int x,y;
	pai p;
	for(;;)
	{
		int i,j;
		printf("请输入任意两张手牌之前的编号，以空格隔开，以回车结束！(提醒：先输入编号大的，再输入编号小的)\n");
		scanf("%d",&x);
		scanf("%d",&y);
		if((x>=0)&&(x<(*w).shoupaishu)&&(y>=0)&&(y<(*w).shoupaishu-1))
		{
			switch((((*w).shoupai[x].huase)%2)+(((*w).shoupai[y].huase)%2))
			{
				case 0:p.yanse=0;break;
				case 2:p.yanse=1;break;
				case 1:p.yanse=2;break;
				default:color(4);printf("【丈八蛇矛】函数参数错误！\n");color(9);
			}
			qipaidui[*qipaishu]=(*w).shoupai[x];
			(*w).shoupai[x].leixing=-1;
			((*w).shoupaishu)--;
			(*qipaishu)++;
			qipaidui[*qipaishu]=(*w).shoupai[y];
			(*w).shoupai[y].leixing=-1;
			((*w).shoupaishu)--;
			(*qipaishu)++; printf("弃牌数：%d",*qipaishu);
			for(i=0;i<=(((*w).shoupaishu)+1);i++)
			{
				if((*w).shoupai[i].leixing==-1)
				{
					for(j=i+1;j<=(((*w).shoupaishu)+2);j++)
					{
						(*w).shoupai[j-1]=(*w).shoupai[j];
						i--;
					}
				}
			}
			printf("玩家把：\n");
			qipaidui[(*qipaishu)-2].Kanpai();
			qipaidui[(*qipaishu)-1].Kanpai();
			printf("当作一张");
			switch(p.yanse)
			{
				case 0:printf("黑色");break;
				case 2:color(4);printf("红色");color(9);break;
				case 1:printf("无色");break;
				default:color(2);printf("绿色");color(9);break;
			}
			printf("无点数的【杀】");
			p.dianshu=-1;
			p.leixing=101;
			return p;
			break;
		}
		color(4);
		printf("你将两张空气当作一张空气属性的【杀】使用或打出！\n");
		color(9);
		system("pause");
	}
}
int Xuanpai(wujiang*w,int t)//选打出什么牌 
{
	int x;
	if((*w).juese)
	{
		for(;;)
		{
			printf("出牌请输入手牌之前的编号，以回车结束！\n如果你想结束出牌阶段，请输入“-1”，以回车结束！\n");
			speak();
			color(5);
			if(shenfen==10)
			{
				printf("是否触发袁绍锁定技——4.乱击（出牌阶段，弃置两张牌，视为使用【万箭齐发】）\n");
				printf("是，输入99\n"); 
			} 
			if(shenfen==18)
			{
				printf("是否触发董卓锁定技——酒池\n");
				printf("是，输入99\n"); 
			}
			if(shenfen==19)
			{
				printf("是否触发黄盖锁定技——苦肉(减一点体力摸两张牌,减一点体力上限该回合杀伤害+2)\n");
				printf("是，输入111\n"); 
			} 
			if(shenfen==23)
			{
				cout<<"是否触发技能【龙胆】\n";
				cout<<"是，输入123\n"; 
			}
			if(shenfen==24)
			{
				color(3);
				printf("是否触发LI HAOXUAN技能——苦肉(减一点体力摸两张牌,减一点体力上限该回合杀伤害+2)\n");
				printf("是，输入502\n"); 
			} 
			color(9);
			scanf("%d",&x);
			if((x>=-1&&x<((*w).shoupaishu))||((x==100)&&((*w).zhuangbei[0].leixing==305))&&x!=99&&x!=111)
			{
				return x;
				break;
			}
			else if(shenfen==10&&x==99) 
			{
				color(1);
				printf("触发袁绍锁定技——4.乱击\n");
				color(9);
				return 101;
			}
			else if(shenfen==18&&x==99)
			{
				color(1);
				cout<<"触发董卓锁定技——酒池"<<endl;
				color(9);
				return 99;
			}
			else if((shenfen==19&&x==111)||(shenfen==24&&x==502))
			{
				color(1);
				cout<<"减一点体力还是减一点体力上限？？？\n";
				cout<<"减一点体力，输入1;减一点体力上限，输入2\n";
				color(9);
				int p;
				cin>>p;
				if(p==1)
				{
					return 111;
				}
				else
				{
					return 222;
				}
			}
			else if(shenfen==23&&x==123)
			{
				return 123;
			}
			else
			{
				color(4);
				printf("你打出了一张空气！\n");
				color(9);
			}
		}
	}
	else 
	{
		return t;
	}
}
pai Panpai(wujiang*w1,int*sha,int y,pai qipaidui[104],int*qipaishu)//判断是否能使用杀，闪，桃，无懈可击 
{
	pai p,q;
	p.leixing=0;
	q.leixing=-1;
	if(y==-1)
	{
		return q;
	}
	else
	{
		if(y==100)//能否使用丈八蛇矛 
		{
			if((*sha)>0||shenfen==1||renchuan==1)
			{
				if(shenfen==1&&(*w1).juese)
				{
					color(5);
					cout<<"触发张飞锁定技——咆哮\n";
					color(9);
				}
				else if(!(*w1).juese&&comshenfen==2)
				{
					color(5);
					cout<<"电脑本回合【杀】无限制\n";
					color(9); 
				}
				else if(!(*w1).juese&&comshenfen==3)
				{
					color(5);
					cout<<"电脑触发日本鬼子锁定技——凶残（【杀】无限制，每出一张杀-1体力）\n";
					color(9);
				}
				q=Zhangba(w1,qipaidui,qipaishu);
				printf("使用！\n");
				return q;
			}
			else
			{
				color(4);
				printf("当前回合使用【杀】的次数已用尽，你也不能使用【丈八蛇矛】效果！\n");
				color(9);
				return p;
			}
		}
		switch((*w1).shoupai[y].leixing)
		{
			case 101://是否能出杀 
			if(((*sha)>0)||((*w1).zhuangbei[0].leixing==301))//诸葛连弩
			{
				if(((*w1).zhuangbei[0].leixing==301))
				{
					color(3);
					printf("武器【诸葛连弩】效果被触发！\n");
					color(9);
				}
				return (*w1).shoupai[y];
				break;
			}
			else if(shenfen==1&&(*w1).juese)//咆哮
			{
				color(5);
				printf("张飞锁定技——咆哮触发\n");
				color(9); 
				return (*w1).shoupai[y];
				break;    
			}
			else if(renchuan==1&&!(*w1).juese&&comshenfen==2)
			{
				color(5);
				cout<<"电脑本回合【杀】无限制\n"; 
				color(9);
			} 
			else if(!(*w1).juese&&comshenfen==3)
			{
				color(5);
				cout<<"电脑触发日本鬼子锁定技——凶残（【杀】无限制，每出一张杀-1体力）\n";
				color(9);
			}
			else if(shenfen==10&&haoqiang==0&&(*w1).juese)
			{
				haoqiang=1;
				color(5);
				printf("触发袁绍锁定技——2.结交豪强（可以多出一张杀，多摸一张牌）\n");
				color(9);
				return (*w1).shoupai[y];
				break;    
			} 
			else
			{
				if((*w1).juese)
				color(4);
				printf("当前回合使用【杀】的次数已用尽，你不能使用【杀】！\n");
				color(9);
				return p;break;
			}
			case 102://是否能出闪 
			if((*w1).juese)
			{
				color(2);
				printf("当前不需要响应任何操作，你不能主动打出【闪】！（你闪谁呢！！！）\n");
				color(9);
				return p;break;
			}
			case 103://是否能出桃 
			if(((*w1).tili)<((*w1).tilishangxian))
			{
				return (*w1).shoupai[y];
				break;
			}
			else
			{
				if((*w1).juese)
				{
					color(2);
					printf("你并未受伤，不能对自己使用【桃】！(奶够啦啊！！！)\n");
					color(9);
				}
				return p;break;
			}
			case 210://是否能出无懈可击 
			if((*w1).juese)
			{
				color(3);
				printf("当前不需要响应任何锦囊，你不能主动打出【无懈可击】！\n");
				color(9);
				return p;break;
			}
			case 201:
			case 202:
			case 203:
			case 204:
			case 205:
			case 206:
			case 207:
			case 208:
			case 209:
			case 251:
			case 252:
			case 301:
			case 302:
			case 303:
			case 304:
			case 305:
			case 306:
			case 307:
			case 308:
			case 331:
			case 361:
			case 362:
			case 363:
			case 381:
			case 382:
			case 384:
			case 383:return (*w1).shoupai[y];break;
			default:color(4);printf("手牌类型参数错误！（游戏要崩啦）\n");color(9);return p;break;
		}
	}
}
int Mubiao(pai p,wujiang *w1,wujiang *w2,int*sha)//牌的目标是否合法  
{
	int x;
	switch(p.leixing)
	{
		case 101://杀的目标 
		if((*w1).juese)//玩家 
		{
			printf("请选择【杀】的目标！\n输入目标前的编号，以回车结束！\n0 电脑1\n");
			scanf("%d",&x);
			if(x==0)
			{
				if(shenfen==16)
				{
					color(5);
					printf("触发马超锁定技——马术(你计算与其他角色的距离-1)\n");
					(*w1).juli[0]-=1;
					color(9);
				} 
				if((*w1).zhuangbei[0].changdu>=(*w1).juli[0])//如果玩家装备的长度大于与电脑的距离 
				{
					(*sha)--;
					return ((*w2).juese);
				}
				else
				{
					color(4);
					printf("武器长度不够！\n");
					color(9);
					system("pause");
					return -2;
				}
			}
			else
			{
				color(4);
				printf("目标错误！（看准点！！！）\n");
				color(9);
				return -2;
			}
		}
		else
		{
			if((*w1).zhuangbei[0].changdu>=(*w1).juli[0])
			{
				(*sha)--;
				return((*w2).juese);
			}
			else 
			{
				return -2;
			}
		}
		break;
		case 103:return((*w1).juese);break;//桃 
		case 201://过河拆桥 
		if((*w1).juese)
		{
			printf("请选择【过河拆桥】的目标！\n输入目标前的编号，以回车结束！\n0 电脑1\n");
			scanf("%d",&x);
			if(x==0)
			{
				if((*w2).shoupaishu||(*w2).zhuangbeishu||(*w2).pandingshu)
				{
					return ((*w2).juese);
				}
				else
				{
					color(3);
					printf("目标没有牌！\n");
					color(9);
					return -2;
				}
			}
			else
			{
				color(4);
				printf("目标错误！（看准点！！！）\n");
				color(9);
				return -2;
			}
		}
		else 
		{
			return((*w2).juese);
		}
		break;
		case 202://顺手牵羊 
		if((*w1).juese)
		{
			printf("请选择【顺手牵羊】的目标！\n输入目标前的编号，以回车结束！\n0 电脑1\n");
			scanf("%d",&x);
			if(x==0)
			{
				if(((*w2).shoupaishu||(*w2).zhuangbeishu||(*w2).pandingshu)&&((*w1).juli[0]<=1))
				{
					return((*w2).juese);
				}
				else
				{
					color(4);
					printf("目标没有牌！\n");
					color(9);
					return -2;
				}
			}
			else
			{
				color(4);
				printf("目标错误！(看准点！！！)\n");
				color(9);
				return -2;
			}
		}
		else
		{
			if((*w1).juli[0]<=1)
			{
				return((*w2).juese);
			}
			else 
			{
				return -2;
			}
		}
		break;
		case 203://无中生有 
		return ((*w1).juese);break;
		case 204://决斗 
		if((*w1).juese)
		{
			printf("请选择【决斗】的目标！\n输入目标前的编号，以回车结束！\n0 电脑1\n");
			scanf("%d",&x);
			if(x==0)
			{
				return((*w2).juese);
			}
			else
			{
				color(4);
				printf("目标错误！(看准点！！！)\n");
				color(9);
				return -2;
			}
		}
		else 
		{
			return((*w2).juese);
		}
		break;
		case 205://借刀杀人 
		int y;
		if((*w1).juese)
		{
			printf("请选择【借刀杀人】的目标！\n输入目标前的编号，以回车结束！\n0 电脑1\n");
			scanf("%d",&x);
			if(x!=0)
			{
				color(4);
				printf("目标错误！（看准点！！！）\n");
				color(9);
				return -2;
			}
			else
			{
				if(((*w2).zhuangbei[0]).leixing<=300||((*w2).zhuangbei[0]).leixing>=331)
				{
					color(4);
					printf("目标装备区里没有武器！\n");
					color(9);
					return -2;
				}
				else
				{
					printf("请选择【杀】的目标！\n提示：【杀】的目标必须在【借刀杀人】的目标的攻击范围之内！\n输入目标前的编号，以回车结束！\n0 玩家\n");
					scanf("%d",&y);
					if(y!=0)
					{
						color(4);
						printf("目标错误！\n");
						color(9);
						return -2;
					}
					else
					{
						if(shenfen==16)
						{
							color(5);
							printf("触发马超锁定技——马术(你计算与其他角色的距离-1)\n");
							color(9);
							(*w2).juli[0]-=1; 
						}
						if(((*w2).zhuangbei[0].changdu)<(*w2).juli[0])
						{
							color(4);
							printf("武器距离不够！\n");
							color(9);
							return -2;
						}
						else
						{
							return((*w2).juese);
						}		
					}
				}
			}
		}
		else
		{
			if(((*w2).zhuangbei[0]).leixing<=300||((*w2).zhuangbei[0]).leixing>=331)
			{
				return -2;
			}
			else
			{
				if(((*w2).zhuangbei[0].changdu)<(*w2).juli[0])
				{
					return -2;
				}
				else 
				{
					return((*w2).juese);
				}
			}
		}
		break;
		case 206://桃园结义 
		case 207:return 99;break;//五谷丰登 
		case 208://南蛮入侵 
		case 209:return 100;break;//万箭齐发 
		case 384://兵粮寸断
		if((*w1).juese)
		{
			printf("请选择【兵粮寸断】的目标！\n输入目标前的编号，以回车结束！\n0 电脑1\n");
			scanf("%d",&x);
			if(x==0)
			{
				int i;
				for(i=0;i<=2;i++)
				{
					if((*w2).pandingpai[i].leixing==384)
					{
						i=-1;
						break;
					}
				}
				if(i==-1)
				{
					color(4);
					printf("目标判定区里不能同时存在两张相同的延时类锦囊！\n");
					color(9);
					return -2;
				}
				else 
				{
					return((*w2).juese);
				}
			}
			else
			{
				color(4);
				printf("目标错误！（看准点！！！）\n");
				color(9);
				return -2;
			}
		}
		else
		{
			int i;
			for(i=0;i<=2;i++)
			{
				if((*w2).pandingpai[i].leixing==384)
				{
					i=-1;
					break;
				}
			}
			if(i==-1)	
			{
				return -2;
			}
			else
			{
				return((*w2).juese);
			} 
		}
		break;
		case 251://乐不思蜀 
		if((*w1).juese)
		{
			printf("请选择【乐不思蜀】的目标！\n输入目标前的编号，以回车结束！\n0 电脑1\n");
			scanf("%d",&x);
			if(x==0)
			{
				int i;
				for(i=0;i<=2;i++)
				{
					if((*w2).pandingpai[i].leixing==251)
					{
						i=-1;
						break;
					}
				}
				if(i==-1)
				{
					color(4);
					printf("目标判定区里不能同时存在两张相同的延时类锦囊！\n");
					color(9);
					return -2;
				}
				else 
				{
					return((*w2).juese);
				}
			}
			else
			{
				color(4);
				printf("目标错误！（看准点！！！）\n");
				color(9);
				return -2;
			}
		}
		else
		{
			int i;
			for(i=0;i<=2;i++)
			{
				if((*w2).pandingpai[i].leixing==251)
				{
					i=-1;
					break;
				}
			}
			if(i==-1)	
			{
				return -2;
			}
			else
			{
				return((*w2).juese);
			} 
		}
		break;
		case 252://闪电 
		int i;
		for(i=0;i<=2;i++)
		{
			if((*w1).pandingpai[i].leixing==252)
			{
				i=-1;
				break;
			}	
		}
		if(i==-1)
		{
			if((*w1).juese)
			{
				color(4);
				printf("目标判定区里不能同时存在两张相同的延时类锦囊！\n");
				color(9);
			}
			return -2;
		}
		else 
		{
			return((*w2).juese);	
		}
		break;
		case 301:
		case 302:
		case 303:
		case 304:
		case 305:
		case 306:
		case 307:
		case 308:
		case 331:
		case 361:
		case 362:
		case 363:
		case 381:
		case 382:
		case 383:return((*w1).juese);break;
		default:return -2;break;
	}
}
void Da1pai(wujiang *w1,wujiang*w2,pai qipaidui[104],int *qipaishu,int x)//出牌结算 
{
	int i;
	if((x<0||x>=((*w1).shoupaishu))&&x!=100)
	{
		color(3);
		printf("你的牌呢？！\n");
		color(9);
	}
	else
	{
		switch(((*w1).shoupai)[x].leixing)
		{
			case 101:
			case 102:
			case 103:
			case 201:
			case 202:
			case 203:
			case 204:
			case 205:
			case 206:
			case 207:
			case 208:
			case 209:
			case 210:
			qipaidui[*qipaishu]=((*w1).shoupai)[x];
			for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
			((*w1).shoupaishu)--;
			(*qipaishu)++;
			break;
			case 251://乐不思蜀 
			for(i=1;i>=0;i--)(*w2).pandingpai[i+1]=(*w2).pandingpai[i];
			(*w2).pandingpai[0]=(*w1).shoupai[x];
			for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
			((*w1).shoupaishu)--;
			((*w2).pandingshu)++;
			break;
			case 252://闪电 
			for(i=1;i>=0;i--)(*w1).pandingpai[i+1]=(*w1).pandingpai[i];
			(*w1).pandingpai[0]=(*w1).shoupai[x];
			for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
			((*w1).shoupaishu)--;
			((*w1).pandingshu)++;
			break;
			case 384://兵粮寸断
			for(i=1;i>=0;i--)(*w2).pandingpai[i+1]=(*w2).pandingpai[i];
			(*w2).pandingpai[0]=(*w1).shoupai[x];
			for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
			((*w1).shoupaishu)--;
			((*w2).pandingshu)++;
			break; 
			case 301:
			case 302:
			case 303:
			case 304:
			case 305:
			case 306:
			case 307:
			case 308:
			if((*w1).zhuangbei[0].leixing==-1)
			{
				((*w1).zhuangbeishu)++;
			}
			else
			{
				qipaidui[*qipaishu]=((*w1).zhuangbei)[0];
				(*qipaishu)++;
			}
			(*w1).zhuangbei[0]=(*w1).shoupai[x];
			for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
			((*w1).shoupaishu)--;
			break;
			case 331:// 八卦阵
			if((*w1).zhuangbei[1].leixing==-1)
			{
				((*w1).zhuangbeishu)++;
			}
			else
			{
				qipaidui[*qipaishu]=((*w1).zhuangbei)[1];
				(*qipaishu)++;
			}
			(*w1).zhuangbei[1]=(*w1).shoupai[x];
			for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
			((*w1).shoupaishu)--;
			break;
			case 361:
			case 362:
			case 363:
			/*
			case 361:cout<<"【赤兔(-1)】"<<endl;break;
		    case 362:cout<<"【大宛(-1)】"<<endl;break;
		    case 363:cout<<"【紫辛(-1)】"<<endl;break;
			*/ 
			if((*w1).zhuangbei[2].leixing==-1)
			{
				((*w1).zhuangbeishu)++;
			}
			else
			{
				qipaidui[*qipaishu]=((*w1).zhuangbei)[2];
				(*qipaishu)++;
			}
			(*w1).zhuangbei[2]=(*w1).shoupai[x];
			for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
			((*w1).shoupaishu)--;
			break;
			case 381:
			case 382:
			case 383:
			/*
			case 381:cout<<"【爪黄飞电(+1)】"<<endl;break;
		    case 382:cout<<"【的卢(+1)】"<<endl;break;
		    case 383:cout<<"【绝影(+1)】"<<endl;break; 
			*/
			if((*w1).zhuangbei[3].leixing==-1)
			{
				((*w1).zhuangbeishu)++;
			}
			else
			{
				qipaidui[*qipaishu]=((*w1).zhuangbei)[3];
				(*qipaishu)++;
			}
			(*w1).zhuangbei[3]=(*w1).shoupai[x];
			for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
			((*w1).shoupaishu)--;
			break;
			default:break;
		}
	}
}
void Miaoshu(pai p,int juese,int duixiang)//输出对什么对象使用   OK
{
	if(juese==0)printf("电脑");
	else if(juese==1)printf("玩家");
	else color(4);printf("角色参数错误！\n");color(9);
	if(p.leixing<=300&&p.leixing>100||p.leixing==384)
	{
		switch(duixiang)
		{
			case -1:printf("打出");break;
			case 0:printf("对电脑使用");break;
			case 1:printf("对玩家使用");break;
			case 99:printf("使用");break;
			case 100:printf("对所有人使用");break;
			default:color(4);printf("对象参数错误\n");color(9);break;
		}
	}
	else if(p.leixing>=301&&p.leixing<=400)
	{
		printf("装备");
	}
	else 
	{
		color(4);
		printf("你出的是什么东西？\n");
		color(9);
	}
	p.Kanpai();
	if(!juese&&(p.leixing==101||p.leixing==204||p.leixing==205||p.leixing==207||p.leixing==208||p.leixing==209))
	{
		color(2);
		printf("请响应！\n");
		color(9);
	}
}
int Wuxie(pai *p,wujiang*w1,wujiang*w2,pai qipaidui[104],int*qipaishu,int a)//无懈可击 
{
	int x;
	if((*w1).juese)
	{
		printf("是否使用【无懈可击】响应？\n\n");
		int zanshicnt=0;
		for(;;)
		{
			zanshicnt++;
			if(zanshicnt>=20)//修复bug 
			{
				break;
			}
			(*w1).Kanshoupai();
			printf("如果要使用【无懈可击】请输入手牌之前编号，不需要请输入“-1”，以回车结束！\n");
			scanf("%d",&x);
			if(x==-1)
			{
				for(x=0;x<((*w2).shoupaishu);x++)
				{
					if((*w2).shoupai[x].leixing==210)
					{
						printf("电脑使用");
						((*w2).shoupai)[x].Kanpai();
						printf("对象是");
						(*p).Kanpai();
						(*p)=((*w2).shoupai)[x];
						qipaidui[*qipaishu]=((*w2).shoupai)[x];
						for(int i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
						((*w2).shoupaishu)--;
						(*qipaishu)++;
						a++;
						break;
					}
				}
				break;
			}
			else if((*w1).shoupai[x].leixing==210)
			{
				printf("玩家使用");
				((*w1).shoupai)[x].Kanpai();
				printf("对象是");
				(*p).Kanpai();
				(*p)=((*w1).shoupai)[x];
				qipaidui[*qipaishu]=((*w1).shoupai)[x];
				for(int i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
				((*w1).shoupaishu)--;
				(*qipaishu)++;
				(*w1).Kanshoupai();
				a++;
				break;
			}
			else 
			{
				color(4);
				printf("你确定你使用的是【无懈可击】？\n");
				color(9);
			}
		}
	}
	else
	{
		int zanshicnt=0;
		printf("是否使用【无懈可击】响应？\n");
		for(;;)
		{
			zanshicnt++;
			if(zanshicnt>=20)//修复bug 
			{
				break;
			}
			(*w2).Kanshoupai();
			printf("如果要使用【无懈可击】请输入手牌之前编号，不需要请输入“-1”，以回车结束！\n");
			scanf("%d",&x);
			if(x==-1)
			{
				break;
			}
			else if((*w2).shoupai[x].leixing==210)
			{
				printf("玩家使用");
				((*w2).shoupai)[x].Kanpai();
				printf("对象是");
				(*p).Kanpai();
				(*p)=((*w2).shoupai)[x];
				qipaidui[*qipaishu]=((*w2).shoupai)[x];
				for(int i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				(*qipaishu)++;
				(*w2).Kanshoupai();
				a++;
				break;
			}
			else
			{
				printf("你确定你使用的是【无懈可击】？\n");
			} 
		}
	}
	return a;
}
int Qiutao(wujiang*w,pai qipaidui[104],int*qipaishu)//求桃 
{
	int x;
	if((*w).juese)
	{
		for(;;)
		{
			printf("如果要使用【桃】请输入手牌之前的编号，不需要请输入“-1”，以回车结束！\n");
			scanf("%d",&x);
			if(x==-1)
			{
				return -1;
				break;
			}
			else if((*w).shoupai[x].leixing==103)
			{
				qipaidui[*qipaishu]=((*w).shoupai)[x];
				for(int i=x+1;i<=((*w).shoupaishu);i++)((*w).shoupai)[i-1]=((*w).shoupai)[i];
				((*w).shoupaishu)--;
				(*qipaishu)++;
				return 0;
				break;
			}
			else
			{
				color(2);
				printf("你确定你使用的是【桃】？\n");
				color(9);
			} 
		}
	}
	else
	{
		for(x=0;x<((*w).shoupaishu);x++)
		{
			if((*w).shoupai[x].leixing==103)
			{
				qipaidui[*qipaishu]=((*w).shoupai)[x];
				for(int i=x+1;i<=((*w).shoupaishu);i++)((*w).shoupai)[i-1]=((*w).shoupai)[i];
				((*w).shoupaishu)--;
				(*qipaishu)++;
				return 0;
				break;
			}
		}
		return -1;
	}
}
int Binsi(wujiang*w1,wujiang*w2,pai qipaidui[104],int*qipaishu)//濒死 
{
	if(((*w2).tili)>0)
	{
		return 0;
	}
	else
	{
		int i;
		if((*w1).juese)//电脑濒死，玩家是否出桃 
		{
			for(;;)
			{
				color(4);
				printf("电脑濒死，是否使用【桃】？\n");
				color(9);
				if(shenfen==17)
				{
					color(5);
					printf("触发贾诩锁定技——完杀(你的回合内，只有你能使用【桃】)\n");
					color(9);
					i=-1; 
				} 
				else
				{
					i=Qiutao(w1,qipaidui,qipaishu);
				}
				if(i==0)
				{
					((*w2).tili)++;
				}
				if((i==-1)||((*w2).tili>0))
				{
					break;
				}
			}
			if((*w2).tili>0)
			{
				return 0;
			}
			else
			{
				for(;;)
				{
					i=Qiutao(w2,qipaidui,qipaishu);
					if(i==0)
					{
						((*w2).tili)++;
					}
					if((i==-1)||((*w2).tili>0))
					{
						break;
					}
				}
				if((*w2).tili>0)
				{
					return 0;
				}
				else 
				{
					color(5);
					cout<<"！！！玩家胜利！！！\n";
					color(9);
					wanjiaxin++;
					return -1;
				}
			}
		}
		else
		{
			for(;;)
			{
				color(4);
				printf("玩家濒死，是否使用【桃】？\n");
				color(9);
				if(shenfen==13)
				{
					color(5);
					printf("触发获得华佗锁定技——急救(濒死时进行判定，若为奇数回2点体力，偶数-2点体力)\n");
					color(9); 
					srand((unsigned)time(NULL));
					if(rand()%2==1)
					{
						color(2);
						cout<<"Lucky dog!!!你增加两点体力\n";
						color(9);
						((*w2).tili)+=2;
					}
					else
					{
						color(4);
						cout<<"Bad luck!!!你再减两点体力\n";
						color(9);
						((*w2).tili)-=2;
					}
				}
				i=Qiutao(w2,qipaidui,qipaishu);
				if(i==0)((*w2).tili)++;
				if(shenfen==2&&niepan!=1)
				{
				    niepan=1;
				    color(2);
				    printf("触发庞统限定技——涅槃\n");
				    printf("玩家生命+3\n");
				    color(9);
				    (*w2).tili+=3;
				}
				if(shenfen==9&&sijie==0)
				{
					sijie=1;
					color(5);
					printf("触发审配锁定技——死节\n");
					color(9);
					(*w2).tili-=1;
				} 
				if(shenfen==10)
				{
					color(5);
					printf("触发袁绍锁定技——骄纵\n");
					color(4);
					printf("你受到二次伤害！！！\n");
					color(9);
					(*w2).tili-=1;
				} 
				if((i==-1)||((*w2).tili>0))
				{
					break;
				}
			}
			if((*w2).tili>0)
			{
				return 0;	
			}
			else 
			{
				color(4);
				cout<<"悲伤的故事···玩家失败\n";
				color(9);
				comxin++;
				return -1;
			}
		}
	}
}
int zhangjiao(pai p)//张角雷击 
{
	int fanhui=0;
	switch(p.huase)
	{
	    case 0:cout<<"黑桃  ";
		fanhui=2;
		break;
	    case 1:cout<<"红桃  ";break;
	    case 2:cout<<"草花  ";
		fanhui=1;
		break;
	    case 3:
		cout<<"方片  ";break;
	    case -1:cout<<"无色 \n";break;
	    default:color(4);printf("花色错误！ \n");color(9);break;
	}
	switch(p.leixing)
	{
		case 101:cout<<"【杀】"<<endl;break;
	    case 102:cout<<"【闪】"<<endl;break;
	    case 103:cout<<"【桃】"<<endl;break;
	    case 201:cout<<"【过河拆桥】"<<endl;break;
	    case 202:cout<<"【顺手牵羊】"<<endl;break;
	    case 203:cout<<"【无中生有】"<<endl;break;
	    case 204:cout<<"【决斗】"<<endl;break;
	    case 205:cout<<"【借刀杀人】"<<endl;break;
	    case 206:cout<<"【桃园结义】"<<endl;break;
	    case 207:cout<<"【五谷丰登】"<<endl;break;
	    case 208:cout<<"【南蛮入侵】"<<endl;break;
	    case 209:cout<<"【万箭齐发】"<<endl;break;
	    case 210:cout<<"【无懈可击】"<<endl;break;
	    case 251:cout<<"【乐不思蜀】"<<endl;break;
	    case 252:cout<<"【闪电】"<<endl;break;
	    case 301:cout<<"【诸葛连弩(1)】"<<endl;break;
	    case 302:cout<<"【雌雄双股剑(2)】"<<endl;break;
	    case 303:cout<<"【青釭剑(2)】"<<endl;break;
	    case 304:cout<<"【青龙偃月刀(3)】"<<endl;break;
	    case 305:cout<<"【丈八蛇矛(3)】"<<endl;break;
	    case 306:cout<<"【贯石斧(3)】"<<endl;break;
	    case 307:cout<<"【方天画戟(4)】"<<endl;break;
	    case 308:cout<<"【麒麟弓(5)】"<<endl;break;
	    case 331:cout<<"【八卦阵】"<<endl;break;
	    case 361:cout<<"【赤兔(-1)】"<<endl;break;
	    case 362:cout<<"【大宛(-1)】"<<endl;break;
	    case 363:cout<<"【紫辛(-1)】"<<endl;break;
	    case 381:cout<<"【爪黄飞电(+1)】"<<endl;break;
	    case 382:cout<<"【的卢(+1)】"<<endl;break;
	    case 383:cout<<"【绝影(+1)】"<<endl;break;
	    default:printf("类型参数错误！");break;
	}
	leijishanghai+=fanhui; 
	return fanhui;
}
int Shan(wujiang*w1,wujiang*w2,pai paidui[104],int*paiduishu,pai qipaidui[104],int*qipaishu)//闪 
{
	int x;
	if((*w2).juese)//玩家 
	{
		if(((*w2).zhuangbei[1].leixing==331)&&((*w1).zhuangbei[0].leixing!=303)||shenfen==4)//有八卦阵没有青虹剑 
		{
			if(shenfen==4)
			{
				color(5);
				printf("触发诸葛亮锁定技——空城\n");
				color(9);
			}
			for(;;)
			{
				int m;
				printf("是否发动【八卦阵】防具效果？\n0 否\n1 是\n请输入选项之前的编号，以回车结束！\n");
				scanf("%d",&m);
				if(m==1)
				{
					Panding(paidui,paiduishu,qipaidui,qipaishu,w1,w2);//函数直接判定 
					if(shenfen==14)
					{
						GaiPanding(paidui,paiduishu,qipaidui,qipaishu,w1,w2);
					}
					if(qipaidui[(*qipaishu)-1].huase%2)
					{
						printf("【八卦阵】判定成功！\n");
						if(shenfen==14)//张角 
						{
							pai p=((*w1).pandingpai[0]);
							int t=zhangjiao(p);
							if(t==2)
							{
								((*w1).tili)-=2;
								color(5);
								cout<<"雷公助你！！！对方遭到2点雷电伤害\n";
								color(9);
								system("pause");
							}
							else if(t==1)
							{
								((*w1).tili)-=1;
								((*w2).tili)++;
								color(5);
								cout<<"雷公助你！！！对方遭到1点雷电伤害,你回复1点体力\n";
								color(9);
								system("pause");
							}
							else
							{
								color(4);
								printf("Bad luck!!!\n");
								color(9);
							} 
						}
						return 0;
					}
				}
				else if(m==0)
				{
					printf("【八卦阵】判定失败！\n");
					break;
				}
				else 
				{
					color(4);
					printf("你确定你输入的是“0”或“1”？\n");
					color(9);
				}
			}
		}
		else if(((*w2).zhuangbei[1].leixing==331)&&((*w1).zhuangbei[0].leixing==303))
		{
			printf("【青釭剑】锁定技被触发！\n");
		}
		for(;;)
		{
			printf("请输入手牌之前的编号，或者输入“-1”放弃打出【闪】，以回车结束！\n");
			if(shenfen==23)
			{
				color(5);
				cout<<"若想发动【龙胆】，直接输入【杀】的编号即可\n";
				color(9);
			} 
			scanf("%d",&x);
			if(x==-1)
			{
				return -1;
				break;
			}
			else if((*w2).shoupai[x].leixing==102)
			{
				printf("玩家打出");
				((*w2).shoupai)[x].Kanpai();
				qipaidui[*qipaishu]=((*w2).shoupai)[x];
				for(int i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				(*qipaishu)++;
				return 0;
				break;
			}
			else if(shenfen==23&&(*w2).shoupai[x].leixing==101)
			{
				color(5);
				printf("触发赵云技能，将杀当闪打出\n");
				((*w2).shoupai)[x].Kanpai();
				qipaidui[*qipaishu]=((*w2).shoupai)[x];
				for(int i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				(*qipaishu)++;
				color(9);
				return 0;
				break;
			}
			else color(4),printf("你确定你打出的是【闪】？\n"),color(9);
		}
	}
	else
	{
		if(((*w2).zhuangbei[1].leixing==331)&&((*w1).zhuangbei[0].leixing!=303))
		{
			Panding(paidui,paiduishu,qipaidui,qipaishu,w1,w2);
			if(qipaidui[(*qipaishu)-1].huase%2)
			{
				printf("【八卦阵】判定成功！\n");
				return 0;
			}
			else 
			{
				printf("【八卦阵】判定失败！\n");
			}
		}
		else if(((*w2).zhuangbei[1].leixing==331)&&((*w1).zhuangbei[0].leixing==303)||shenfen==5)
		{
			if(shenfen==5)
			{
				color(5);
				printf("曹操锁定技——兵锋触发！\n");
				color(9);
			}
			printf("【青釭剑】锁定技被触发！\n");
		}
		int i;
		for(x=0;x<((*w2).shoupaishu);x++)
		{
			if((*w2).shoupai[x].leixing==102)
			{
				printf("电脑打出");
				((*w2).shoupai)[x].Kanpai();
				qipaidui[*qipaishu]=((*w2).shoupai)[x];
				for(i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				(*qipaishu)++;
				return 0;
				break;
			}
		}
		return -1;
	}
}
int Sha(wujiang *w1,wujiang*w2,pai paidui[104],int*paiduishu,pai qipaidui[104],int*qipaishu)//杀 
{
	int x;
	if(comshenfen==3&&(*w2).juese)
	{
		color(5);
		cout<<"电脑触发日本鬼子锁定技——凶残（【杀】无限制，每出一张杀-1体力）\n";
		color(9);
		(*w1).tili-=1; 
	} 
	if((*w2).juese)//玩家出闪 
	{
		printf("请打出【闪】响应【杀】！否则你将受到1点伤害！\n");
		if(shenfen==15&&qingcheng==0)
		{
			qingcheng=1;
			color(5);
			printf("触发甄宓锁定技——倾城（限一次，你视为打出闪）\n");
			color(9);
			x=0; 
		}
		else if(shenfen==25&&qingcheng==0)
		{
			qingcheng=1;
			color(5);
			printf("触发DONG 韵存 锁定技——倾国倾城（限一次，你视为打出闪）\n");
			color(9);
			system("pause"); 
			x=0; 
		}
		else
		{
			x=Shan(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
		}
		if(comshenfen==4)
		{
			cout<<"触发 趣学语文Mr.Dong锁定技——无双(使用杀时，你需出两张闪)"<<endl;
			color(4); 
			cout<<"                               -------------“见了老子还想跑？！？” "<<endl;
			color(9);
			x=Shan(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
		}
		if(x!=-1&&shenfen==14)
		{
			pai p;
			p=paidui[104-(*paiduishu)];
			(*paiduishu)--;
			p.Kanpai();
			int t=zhangjiao(p);
			if(t==2)
			{
				((*w1).tili)-=2;
				color(5);
				cout<<"雷公助你！！！对方遭到2点雷电伤害\n";
				color(9);
				system("pause");
				if(comshenfen==1)
				{
					color(5);
					cout<<"电脑触发华雄锁定技——恃勇（受到伤害摸两张牌）\n";
					color(9); 
					shiyong++;
				}
			}
			else if(t==1)
			{
				((*w1).tili)-=1;
				((*w2).tili)++;
				color(5);
				cout<<"雷公助你！！！对方遭到1点雷电伤害,你回复1点体力\n";
				color(9);
				system("pause");
				if(comshenfen==1)
				{
					color(5);
					cout<<"电脑触发华雄锁定技——恃勇（受到伤害摸两张牌）\n"; 
					color(9);
					shiyong++;
				}
			}
			else
			{
				color(4);
				printf("Bad luck!!!\n");
				color(9);
			} 
		}
		if(x==-1)
		{
			int i;
			((*w2).tili)--;
			color(4);
			printf("电脑对玩家造成1点伤害！\n");
			color(9);
			i=Binsi(w1,w2,qipaidui,qipaishu);
			if(shenfen==9)
			{
				color(5);
				printf("触发审配锁定技——1.刚烈（敌人对你伤害1点，你对敌人伤害一点）\n");
				color(9);
				((*w1).tili)--;
				i=Binsi(w1,w2,qipaidui,qipaishu);
			}
			if(shenfen==11)
			{
				color(5);
				printf("触发袁术锁定技——崩溃（杀对你造成额外一点伤害）\n");
				color(9);
				((*w2).tili)--;
				i=Binsi(w1,w2,qipaidui,qipaishu);
			} 
			if(shenfen==24)
			{
				color(4);
				printf("触发LI HAO XUAN锁定技——崩环（杀对你造成额外一点伤害）\n");
				color(9);
				system("pause"); 
				((*w2).tili)--;
				i=Binsi(w1,w2,qipaidui,qipaishu);
			} 
			return i;
		}
		else if(x==0&&((*w1).zhuangbei[0].leixing==306))//贯石斧
		{
			int i;
			if(((*w1).shoupaishu)>=2)
			{
				printf("电脑弃掉：\n");
				((*w1).shoupai)[0].Kanpai();
				qipaidui[*qipaishu]=((*w1).shoupai)[0];
				for(i=1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
				((*w1).shoupaishu)--;
				(*qipaishu)++;
				((*w1).shoupai)[0].Kanpai();
				qipaidui[*qipaishu]=((*w1).shoupai)[0];
				for(i=1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
				((*w1).shoupaishu)--;
				(*qipaishu)++;
				color(4);
				printf("发动【贯石斧】武器效果使【杀】造成伤害！\n");
				color(9);
				((*w2).tili)--;
				i=Binsi(w1,w2,qipaidui,qipaishu);
				return i;
			}
			else 
			{
				return 0;	
			}
		}
		else if(x==0&&((*w1).zhuangbei[0].leixing==304))//青龙偃月刀
		{
			int i;
			for(x=0;x<((*w1).shoupaishu);x++)
			{
				if((*w1).shoupai[x].leixing==101)
				{
					printf("电脑发动【青龙偃月刀】效果对玩家使用");
					((*w1).shoupai)[x].Kanpai();
					qipaidui[*qipaishu]=((*w1).shoupai)[x];
					for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
					((*w1).shoupaishu)--;
					(*qipaishu)++;
					i=Sha(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
					return i;
					break;
				}
			}
			return 0;
		}
	}
	else//电脑出闪 
	{
		if(shenfen==16)
		{
			color(5); 
			printf("触发马超锁定技——铁骑(当你使用【杀】指定目标后，你可以进行判定，若结果为红色，该角色不能使用【闪】）\n");
			color(9);
			pai p;
			p=paidui[104-(*paiduishu)];
			(*paiduishu)--;
			p.Kanpai();
			if(p.huase==1||p.huase==3)
			{
				color(5);
				cout<<"成功触发！！！\n";
				color(9);
				x=-1;
			}
			else
			{
				color(4);
				cout<<"oh no~~判定失败\n";
				color(9);
				x=Shan(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
			}
		}
		else
		{
			x=Shan(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
		}
		if(shenfen==22)
		{
			color(5);
			printf("触发吕布锁定技——无双(你使用杀时，对方需出两张闪，并进行判定，若为黑桃此杀伤害+1)\n");
			color(9);
			x=Shan(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
			if(x==-1)
			{
				color(4);
				cout<<"电脑表示他扛不住了\n"; 
				color(9);
			}
		}
		if(x==-1)
		{
			if(shenfen==1)
			{
				color(5);
				cout<<"触发张飞锁定技——咆哮（杀的次数无限制；出一张杀造成伤害，摸对方一张手牌）\n";
				color(9);
				if(((*w2).shoupaishu)>0)
				{
					srand((unsigned)time(NULL));
					int y=rand()%((*w2).shoupaishu);
					printf("你牵走了电脑的");
					((*w2).shoupai)[y].Kanpai();
					(*w1).shoupai[(*w1).shoupaishu]=((*w2).shoupai)[y];
					for(int i=y+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
					((*w2).shoupaishu)--;
					((*w1).shoupaishu)++;
				}
			} 
			if((*w1).zhuangbei[0].leixing==308||shenfen==6)//麒麟弓 
			{
				for(;;)
				{
					if(shenfen==6)
					{
						color(5);
						printf("触发黄忠锁定技——箭术\n");
						color(9);
					}
					if(shenfen==25)
					{
						color(5);
						printf("触发 DONG 韵存 锁定技——射术（自带不可拆麒麟弓）\n");
						color(9);
					} 
					printf("是否发动【麒麟弓】武器效果？\n0 否\n1 是\n");
					scanf("%d",&x);
					if(x==1)
					{
						if(((*w2).zhuangbei[2].leixing==-1)&&((*w2).zhuangbei[3].leixing==-1))
						{
							color(3);
							printf("电脑根本没有马，射你妹的马啊！\n");
							color(9);
							break;
						}
						else
						{
							for(;;)
							{
								printf("0 ");
								((*w2).zhuangbei[2]).Kanpai();
								printf("1 ");
								((*w2).zhuangbei[3]).Kanpai();
								printf("请选择要弃掉的马，输入之前的编号，以回车结束！\n");
								scanf("%d",&x);
								if((x==0)&&((*w2).zhuangbei[2].leixing!=-1))
								{
									printf("你弃掉了电脑的");
									((*w2).zhuangbei)[2].Kanpai();
									qipaidui[*qipaishu]=((*w2).zhuangbei)[2];
									((*w2).zhuangbeishu)--;
									(*qipaishu)++;
									((*w2).zhuangbei)[2].leixing=-1;
									((*w2).juli[0])++;
									break;
								}
								else if((x==1)&&((*w2).zhuangbei[3].leixing!=-1))
								{
									printf("你弃掉了电脑的");
									((*w2).zhuangbei)[3].Kanpai();
									qipaidui[*qipaishu]=((*w2).zhuangbei)[3];
									((*w2).zhuangbeishu)--;
									(*qipaishu)++;
									((*w2).zhuangbei)[3].leixing=-1;
									((*w1).juli[0])--;
									break;
								}
								else 
								{
									color(4);
									printf("射你妹的马！");
									color(9);
								}
							}
							break;
						}
					}
					else if(x==0)
					{
						break;
					}
					else 
					{
						color(2);
						printf("键盘上的“0”和“1”被你吃了吗？\n");
						color(9);
					}
				}
			}
			int i;
			((*w2).tili)--;
			color(4);
			printf("玩家对电脑造成1点伤害！\n");
			color(9);
			if(comshenfen==1)
			{
				color(5);
				cout<<"电脑触发华雄锁定技——恃勇（受到伤害摸两张牌）\n";
				color(9); 
				shiyong++;
			}
			if((shenfen==19||shenfen==24)&&kurou>0)
			{
				((*w2).tili)-=kurou;
				color(5);
				printf("触发锁定技——苦肉(减一点体力摸两张牌,减一点体力上限该回合杀伤害+2)\n");
				printf("你又对电脑造成%d点伤害！！！\n",kurou);
				color(9); 
				system("pause");
			}
			if(shenfen==18)
			{
				color(5);
				printf("触发董卓锁定技——肉林(你对敌人的伤害时,你进行判定，若为黑桃，弃置1~3张牌)\n");
				color(9);
				pai p;
				p=paidui[104-(*paiduishu)];
				(*paiduishu)--;
				p.Kanpai();
				if(p.huase==0)
				{
					cout<<"成功触发\n";
					roulin=1; 
				} 
			}
			if(shenfen==5)
			{
				color(5);
				printf("触发曹操锁定技——奸雄\n");
				color(9);
				jianxiong+=1; 
			} 
			if(shenfen==7&&huben==1)
			{
				color(5);
				cout<<"触发许褚锁定技——虎贲（少摸一张牌，杀与决斗伤害+1）\n";
				color(9);
				((*w2).tili)--;
			}
			if(shenfen==17&&luanwu==3)
			{
				color(5);
				printf("触发贾诩限定技——乱武(指定回合，杀或决斗伤害为3；多获得一个回合，身份为董卓)\n");
				((*w2).tili)-=2;
				color(4);
				cout<<"你对电脑又造成2点伤害\n";
				color(9);
			} 
			if(shenfen==18&&jiu>=1)
			{
				color(5);
				printf("触发董卓锁定技——酒池(随机弃置一张手牌，视为使用【酒】)\n");
				((*w2).tili)-=jiu;
				color(4);
				printf("你又对电脑造成%d点伤害！！！\n",jiu);
				color(9);
				jiu=0;
			}
			if(shenfen==22)
			{
				cout<<"判定牌为： "; 
				pai p;
				p=paidui[104-(*paiduishu)];
				(*paiduishu)--;
				p.Kanpai();
				if(p.huase==0)
				{
					color(4);
					cout<<"判定牌为黑桃，电脑受到二次伤害\n";
					color(9);
					((*w2).tili)--;
				}
				color(5);
				printf("触发吕布锁定技——利驭(你使用杀对对方造成伤害时，摸对面一张牌，弃置对方一张牌，对方下回合多摸一张牌)\n"); 
				color(9);
				if((*w2).shoupaishu>0)
				{
					srand((unsigned)time(NULL));
					int y=rand()%((*w2).shoupaishu);
					printf("你牵走了电脑的");
					((*w2).shoupai)[y].Kanpai();
					(*w1).shoupai[(*w1).shoupaishu]=((*w2).shoupai)[y];
					for(int i=y+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
					((*w2).shoupaishu)--;
					((*w1).shoupaishu)++;
				}
				if((*w2).shoupaishu>0)
				{	
					srand((unsigned)time(NULL));
					int y=rand()%((*w2).shoupaishu);
					printf("你弃掉了电脑的");
					((*w2).shoupai)[y].Kanpai();
					qipaidui[*qipaishu]=((*w2).shoupai)[y];
					for(int j=y+1;j<=((*w2).shoupaishu);j++)((*w2).shoupai)[j-1]=((*w2).shoupai)[j];
					((*w2).shoupaishu)--;
					(*qipaishu)++;
				}
				liyu++; 
			} 
			i=Binsi(w1,w2,qipaidui,qipaishu);
			return i;
		}
		else if(x==0&&((*w1).zhuangbei[0].leixing==306)||shenfen==7)//贯石斧
		{
			for(;;)
			{
				if(shenfen==7)
				{
					printf("触发许褚锁定技——裸衣\n");
				}
				printf("是否发动【贯石斧】武器效果？\n0 否\n1 是\n");
				scanf("%d",&x);
				if(x==1)
				{
					int i;
					if((*w1).shoupaishu+(*w1).zhuangbeishu<=2)
					{
						color(4);
						printf("你除了【贯石斧】以外连2张牌都没有，发动你妹的效果！\n");
						color(9);
						break;
					}
					else
					{
						printf("请分别弃掉两张牌！\n");
						for(i=0;i<=2;i++)
						{
							for(;;)
							{
								printf("请选择区域：\n0 手牌\n1 装备\n");
								scanf("%d",&x);
								if(x==0&&((*w1).shoupaishu==0))printf("你根本没有手牌，弃你妹啊！\n");
								else if(x==1&&((*w1).zhuangbeishu==1))printf("你根本没有别的装备，弃你妹啊！\n");
								else if(x>=0&&x<=1)break;
								else printf("键盘上的“0”和“1”被你吃了吗？\n");
							}
							if(x==0)
							{
								for(;;)
								{
									(*w1).Kanshoupai();
									printf("弃牌请输入手牌之前的编号，以回车结束！\n");
									scanf("%d",&x);
									if(x>=0&&x<((*w1).shoupaishu))break;
									else printf("弃你妹的手牌！\n");
								}
								printf("你弃掉了");
								((*w1).shoupai)[x].Kanpai();
								qipaidui[*qipaishu]=((*w1).shoupai)[x];
								for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
								((*w1).shoupaishu)--;
								(*qipaishu)++;
							}
							else
							{
								for(;;)
								{
									(*w1).Kanzhuangbei();
									printf("请输入装备之前的编号，以回车键结束！\n");
									scanf("%d",&x);
									if((((*w1).zhuangbei[x]).leixing!=-1)&&(x>=0)&&(x<=3))
									{
										printf("你弃掉了");
										((*w1).zhuangbei)[x].Kanpai();
										qipaidui[*qipaishu]=((*w1).zhuangbei)[x];
										((*w1).zhuangbeishu)--;
										(*qipaishu)++;
										((*w1).zhuangbei)[x].leixing=-1;
										break;
									}
									else
									{
										printf("弃你妹的装备！\n");
									}
								}
							}
						}
					}
					color(4);
					printf("玩家发动【贯石斧】武器效果使【杀】造成伤害！\n");
					color(9);
					((*w2).tili)--;
					if(comshenfen==1)
					{
						color(5);
						cout<<"电脑触发华雄锁定技——恃勇（受到伤害摸两张牌）\n";
						color(9); 
						shiyong++;
					}
					if(shenfen==19&&kurou>0)
					{
						((*w2).tili)-=kurou;
						color(5); 
						printf("触发黄盖锁定技——苦肉(减一点体力摸两张牌,减一点体力上限该回合杀伤害+2)\n");
						color(9);
					}
					if(shenfen==18)
					{
						color(5);
						printf("触发董卓锁定技——肉林(你对敌人的伤害时,你进行判定，若为黑桃，随机弃置1~3张牌)\n");
						color(9);
						pai p;
						p=paidui[104-(*paiduishu)];
						(*paiduishu)--;
						p.Kanpai();
						if(p.huase==0)
						{
							cout<<"成功触发\n";
							roulin=1; 
						} 
					}
					if(shenfen==18&&jiu>=1)
					{
						color(5);
						printf("触发董卓锁定技——酒池(随机弃置一张手牌，视为使用【酒】)\n");
						((*w2).tili)-=jiu;
						color(4);
						printf("你又对电脑造成%d点伤害！！！\n",jiu);
						color(9);
						jiu=0;
					}
					if(shenfen==22)
					{
						cout<<"判定牌为： "; 
						pai p;
						p=paidui[104-(*paiduishu)];
						(*paiduishu)--;
						p.Kanpai();
						if(p.huase==0)
						{
							color(4);
							cout<<"判定牌为黑桃，电脑受到二次伤害\n";
							color(9);
							((*w2).tili)--;
						}
						color(5);
						printf("触发吕布锁定技——利驭(你使用杀对对方造成伤害时，摸对面一张牌，弃置对方一张牌，对方摸一张牌)\n"); 
						color(9);
						srand((unsigned)time(NULL));
						int y=rand()%((*w2).shoupaishu);
						printf("你牵走了电脑的");
						((*w2).shoupai)[y].Kanpai();
						(*w1).shoupai[(*w1).shoupaishu]=((*w2).shoupai)[y];
						for(int i=y+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
						((*w2).shoupaishu)--;
						((*w1).shoupaishu)++;
						srand((unsigned)time(NULL));
						y=rand()%((*w2).shoupaishu);
						printf("你弃掉了电脑的");
						((*w2).shoupai)[y].Kanpai();
						qipaidui[*qipaishu]=((*w2).shoupai)[y];
						for(int j=y+1;j<=((*w2).shoupaishu);j++)((*w2).shoupai)[j-1]=((*w2).shoupai)[j];
						((*w2).shoupaishu)--;
						(*qipaishu)++;
					} 
					i=Binsi(w1,w2,qipaidui,qipaishu);
					return i;
					break;
				}
				else if(x==0)break;
				else color(3),printf("键盘上的“0”和“1”被你吃了吗？\n"),color(9);
			}
		}
		else if(x==0&&((*w1).zhuangbei[0].leixing==304))//青龙偃月刀
		{
			for(;;)
			{
				printf("是否发动【青龙偃月刀】武器效果？\n0 否\n1 是\n");
				scanf("%d",&x);
				if(x==1)
				{
					for(;;)
					{
						printf("请对电脑使用一张【杀】！\n请输入手牌之前的编号，或者输入“-1”放弃出【杀】，以回车结束！\n");
						(*w1).Kanshoupai();
						scanf("%d",&x);
						if(x==-1)
						{
							return 0;
							break;
						}
						else if((*w1).shoupai[x].leixing==101)
						{
							int i;
							printf("玩家对电脑使用");
							((*w1).shoupai)[x].Kanpai();
							qipaidui[*qipaishu]=((*w1).shoupai)[x];
							for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
							((*w1).shoupaishu)--;
							(*qipaishu)++;
							i=Sha(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
							return i;
							break;
						}
						else 
						{
							color(4);
							printf("你确定你打出的是【杀】？\n");
							color(9);
						}
					}
				}
				else if(x==0)
				{
					return 0;
					break;
				}
				else 
				{
					color(4);
					printf("你确定你输入的是“0”或“1”？\n");
					color(9);
				}
			}
		}
		else 
		{
			return 0;
		}
	}
	return 0;
}
void Tao(wujiang*w1)//桃 
{
	((*w1).tili)++;
	if((*w1).juese)
	{
		if(shenfen!=12)
		{
			color(2);
			printf("玩家恢复了1点体力！\n");
			color(9);
			if(shenfen==13)
			{
				color(5);
				cout<<"触发华佗锁定技——青囊\n";
				color(2);
				printf("你又恢复了1点体力！\n");
				((*w1).tili)++;
				color(9);
			}
		}
		else
		{
			if(((*w1).tili)<=2)
			{
				color(2);
				printf("玩家恢复了1点体力！\n");
				color(9);
			}
			else
			{
				color(5);
				printf("触发曹仁锁定技——无援(体力大于2时，桃无效)\n");
				color(9); 
				((*w1).tili)-=1;
			}
		}
	}
	else
	{ 
		color(2);
		printf("电脑恢复了1点体力！\n");
		color(9);
	}  
	if(((*w1).tili)>((*w1).tilishangxian))
	{
		color(3);
		printf("你被撑死了！\n");
		color(9);
		cout<<"你的体力/上限："<<((*w1).tili)<<'/'<<((*w1).tilishangxian)<<endl;
	}
}
void Chai(wujiang*w1,wujiang*w2,pai qipaidui[104],int*qipaishu)//过河拆桥 
{
	int i,x,y;
	if((*w1).juese)//玩家 
	{
		for(;;)
		{
			if((*w2).shoupaishu+(*w2).zhuangbeishu+(*w2).pandingshu==0)
			{
				color(4);
				printf("对方空城，拆你妹啊！\n");
				color(9);
				break;
			}
			else
			{
				printf("请选择想拆的区域，输入选项之前的编号，以回车结束！\n0 手牌\n1 装备区\n2 判定区\n");
				scanf("%d",&x);
				if(x==0&&((*w2).shoupaishu==0))color(3),printf("你拆掉了一张空气！\n"),color(9);
				else if(x==1&&((*w2).zhuangbeishu==0))color(7),printf("你拆掉了一张空气！\n"),color(9);
				else if(x==2&&((*w2).pandingshu==0))color(8),printf("你拆掉了一张空气！\n"),color(9);
				else if(x>=0&&x<=2)break;
				else color(3),printf("你拆掉了太空区里的一张牌！\n"),color(9);
			}
		}
		switch(x)
		{
			case 0://弃手牌 
			srand((unsigned)time(NULL));
			y=rand()%((*w2).shoupaishu);
			printf("你弃掉了电脑的");
			((*w2).shoupai)[y].Kanpai();
			qipaidui[*qipaishu]=((*w2).shoupai)[y];
			for(i=y+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
			((*w2).shoupaishu)--;
			(*qipaishu)++;
			break;
			case 1://弃装备 
			for(;;)
			{
				(*w2).Kanzhuangbei();
				printf("请输入装备之前的编号，以回车键结束！\n");
				scanf("%d",&y);
				if((((*w2).zhuangbei[y]).leixing!=-1)&&(y>=0)&&(y<=3))
				{
					printf("你弃掉了电脑的");
					((*w2).zhuangbei)[y].Kanpai();
					qipaidui[*qipaishu]=((*w2).zhuangbei)[y];
					((*w2).zhuangbeishu)--;
					(*qipaishu)++;
					((*w2).zhuangbei)[y].leixing=-1;
					if(!y)((*w2).zhuangbei)[y].changdu=1;
					else if(y==2)((*w2).juli[0])++;
					else if(y==3)((*w1).juli[0])--;
					break;
				}
				else 
				{
					color(4);
					printf("你弃掉了一张空气！\n");
					color(9);
				}
			}
			break;
			case 2://弃判定牌 
			for(;;)
			{
				(*w2).Kanpandingpai();
				printf("请输入判定牌之前的编号，以回车键结束！\n");
				scanf("%d",&y);
				if((*w2).pandingpai[y].leixing!=-1)
				{
					printf("你弃掉了电脑的");
					((*w2).pandingpai)[y].Kanpai();
					qipaidui[*qipaishu]=((*w2).pandingpai)[y];
					((*w2).pandingshu)--;
					(*qipaishu)++;
					((*w2).pandingpai)[y].leixing=-1;
					break;
				}
				else 
				{
					color(4);
					printf("你弃掉了一张空气！\n");
					color(9);
				}
			}
			break;
			default:break;
		}
	}
	else 
	{
		if((*w2).shoupaishu>0||(*w2).zhuangbeishu>0||(*w2).pandingshu>0)
		{
			if((*w2).zhuangbeishu)
			{
				if((*w2).zhuangbei[1].leixing!=-1)
				{
					printf("电脑弃掉了玩家的");
					((*w2).zhuangbei)[1].Kanpai();
					qipaidui[*qipaishu]=((*w2).zhuangbei)[1];
					((*w2).zhuangbeishu)--;
					(*qipaishu)++;
					((*w2).zhuangbei)[1].leixing=-1;
				}
				else if((*w2).zhuangbei[3].leixing!=-1)
				{
					printf("电脑弃掉了玩家的");
					((*w2).zhuangbei)[3].Kanpai();
					qipaidui[*qipaishu]=((*w2).zhuangbei)[3];
					((*w2).zhuangbeishu)--;
					(*qipaishu)++;
					((*w2).zhuangbei)[3].leixing=-1;
					((*w1).juli[0])--;
				}
				else if((*w2).zhuangbei[0].leixing!=-1)
				{
					printf("电脑弃掉了玩家的");
					((*w2).zhuangbei)[0].Kanpai();
					qipaidui[*qipaishu]=((*w2).zhuangbei)[0];
					((*w2).zhuangbeishu)--;
					(*qipaishu)++;
					((*w2).zhuangbei)[0].leixing=-1;
					((*w2).zhuangbei)[0].changdu=1;
				}
				else
				{
					printf("电脑弃掉了玩家的");
					((*w2).zhuangbei)[2].Kanpai();
					qipaidui[*qipaishu]=((*w2).zhuangbei)[2];
					((*w2).zhuangbeishu)--;
					(*qipaishu)++;
					((*w2).zhuangbei)[2].leixing=-1;
					((*w2).juli[0])++;
				}
			}
			else
			{
				srand((unsigned)time(NULL));
				y=rand()%((*w2).shoupaishu);
				printf("电脑弃掉了玩家的手牌");
				((*w2).shoupai)[y].Kanpai();
				qipaidui[*qipaishu]=((*w2).shoupai)[y];
				for(i=y+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				(*qipaishu)++;
			}
		}
	}
}
void Qian(wujiang *w1,wujiang *w2)//顺手牵羊 
{
	int i,x,y;
	if((*w1).juese)
	{
		for(;;)
		{
			if((*w2).shoupaishu+(*w2).zhuangbeishu+(*w2).pandingshu==0)
			{
				color(4);
				printf("对方空城啦！你牵走了一张寂寞！\n");
				color(9);
				break;
			}
			else
			{
				printf("请选择想牵的区域，输入选项之前的编号，以回车结束！\n0 手牌\n1 装备区\n2 判定区\n");
				scanf("%d",&x);
				if(x==0&&((*w2).shoupaishu==0))color(3),printf("你牵走了一张空气！\n"),color(9);
				else if(x==1&&((*w2).zhuangbeishu==0))color(3),printf("你牵走了一张空气！\n"),color(9);
				else if(x==2&&((*w2).pandingshu==0))color(3),printf("你牵走了一张空气！\n"),color(9);
				else if(x>=0&&x<=2)break;
				else color(4),printf("你牵走了太空区里的一张牌！\n"),color(9);
			}
		}
		switch(x)
		{
			case 0://手牌 
			srand((unsigned)time(NULL));
			y=rand()%((*w2).shoupaishu);
			printf("你牵走了电脑的");
			((*w2).shoupai)[y].Kanpai();
			(*w1).shoupai[(*w1).shoupaishu]=((*w2).shoupai)[y];
			for(i=y+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
			((*w2).shoupaishu)--;
			((*w1).shoupaishu)++;
			break;
			case 1://装备 
			for(;;)
			{
				(*w2).Kanzhuangbei();
				printf("请输入装备之前的编号，以回车键结束！\n");
				scanf("%d",&y);
				if((((*w2).zhuangbei[y]).leixing!=-1)&&(y>=0)&&(y<=3))
				{
					printf("你牵走了电脑的");
					((*w2).zhuangbei)[y].Kanpai();
					(*w1).shoupai[(*w1).shoupaishu]=((*w2).zhuangbei)[y];
					((*w2).zhuangbeishu)--;
					((*w1).shoupaishu)++;
					((*w2).zhuangbei)[y].leixing=-1;
					if(!y)((*w2).zhuangbei[y]).changdu=1;
					else if(y==2)((*w2).juli[0])++;
					else if(y==3)((*w1).juli[0])--;
					break;
				}
				else
				{
					color(4);
					printf("你弃掉了一张空气！\n");
					color(9);
				} 
			}
			break;
			case 2://判定 
			for(;;)
			{
				(*w2).Kanpandingpai();
				printf("请输入判定牌之前的编号，以回车键结束！\n");
				scanf("%d",&y);
				if((*w2).pandingpai[y].leixing!=-1)
				{
					printf("你牵走了电脑的");
					((*w2).pandingpai)[y].Kanpai();
					(*w1).shoupai[(*w1).shoupaishu]=((*w2).pandingpai)[y];
					((*w2).pandingshu)--;
					((*w1).shoupaishu)++;
					((*w2).pandingpai)[y].leixing=-1;
					break;
				}
				else
				{
					color(4);
					printf("你牵走了一张空气！\n");
					color(9);
				} 
			}
			break;
			default:break;
		}
	}
	else
	{
		if((*w2).shoupaishu+(*w2).zhuangbeishu+(*w2).pandingshu==0)
		{
			; 
		}
		else
		{
			if((*w2).zhuangbeishu)
			{
				if((*w2).zhuangbei[1].leixing!=-1)
				{
					printf("电脑牵走了玩家的");
					((*w2).zhuangbei)[1].Kanpai();
					(*w1).shoupai[(*w1).shoupaishu]=((*w2).zhuangbei)[1];
					((*w2).zhuangbeishu)--;
					((*w1).shoupaishu)++;
					((*w2).zhuangbei)[1].leixing=-1;
				}
				else if((*w2).zhuangbei[3].leixing!=-1)
				{
					printf("电脑牵走了玩家的");
					((*w2).zhuangbei)[3].Kanpai();
					(*w1).shoupai[(*w1).shoupaishu]=((*w2).zhuangbei)[3];
					((*w2).zhuangbeishu)--;
					((*w1).shoupaishu)++;
					((*w2).zhuangbei)[3].leixing=-1;
					((*w1).juli[0])--;
				}
				else if((*w2).zhuangbei[0].leixing!=-1)
				{
					printf("电脑牵走了玩家的");
					((*w2).zhuangbei)[0].Kanpai();
					(*w1).shoupai[(*w1).shoupaishu]=((*w2).zhuangbei)[0];
					((*w2).zhuangbeishu)--;
					((*w1).shoupaishu)++;
					((*w2).zhuangbei)[0].leixing=-1;
					((*w2).zhuangbei)[0].changdu=1;
				}
				else
				{
					printf("电脑牵走了玩家的");
					((*w2).zhuangbei)[2].Kanpai();
					(*w1).shoupai[(*w1).shoupaishu]=((*w2).zhuangbei)[2];
					((*w2).zhuangbeishu)--;
					((*w1).shoupaishu)++;
					((*w2).zhuangbei)[2].leixing=-1;
					((*w2).juli[0])--;
				}
			}
			else
			{
				srand((unsigned)time(NULL));
				y=rand()%((*w2).shoupaishu);
				printf("电脑牵走了玩家的手牌");
				((*w2).shoupai)[y].Kanpai();
				(*w1).shoupai[(*w1).shoupaishu]=((*w2).shoupai)[y];
				for(i=y+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				((*w1).shoupaishu)++;
			}
		}
	
	}
}
void Wuzhong(wujiang*w1,pai A[104],int *x,pai B[104],int*y)//无中生有 
{
	wzshenyou=1; //不要摸牌时发动多余的技能 
	Mopai(&((*w1).shoupaishu),(*w1).shoupai,A,x,B,y,(*w1).juese);
	wzshenyou=0;
}
int Juedou(wujiang*w1,wujiang*w2,pai qipaidui[104],int*qipaishu)//决斗 
{
	if(shenfen==23)
	{
		color(5);
		cout<<"若想发动【龙胆】，直接输入【闪】的编号即可\n";
		color(9);
	} 
	int i,j,x;
	if((*w1).juese)
	{
		for(;;)
		{
			j=0;
			for(x=0;x<((*w2).shoupaishu);x++)
			{
				if((*w2).shoupai[x].leixing==101)
				{
					printf("电脑打出");
					((*w2).shoupai)[x].Kanpai();
					qipaidui[*qipaishu]=((*w2).shoupai)[x];
					for(int i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
					((*w2).shoupaishu)--;
					(*qipaishu)++;
					j=1;
					break;
				}
			}
			if(shenfen==22)
			{
				color(5);
				printf("触发吕布锁定技——飞将（决斗对你伤害为0，决斗时对方需打出两张杀）\n");
				color(9); 
				for(x=0;x<((*w2).shoupaishu);x++)
				{
					if((*w2).shoupai[x].leixing==101)
					{
						printf("电脑打出");
						((*w2).shoupai)[x].Kanpai();
						qipaidui[*qipaishu]=((*w2).shoupai)[x];
						for(int i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
						((*w2).shoupaishu)--;
						(*qipaishu)++;
						j=1;
						break;
					}
				}
			}
			if(!j)
			{
				color(4);
				printf("玩家对电脑造成1点伤害！\n");
				color(9);
				((*w2).tili)--;
				if(comshenfen==1)
				{
					color(5);
					cout<<"电脑触发华雄锁定技——恃勇（受到伤害摸两张牌）\n";
					color(9); 
					shiyong++;
				}
				if(shenfen==7&&huben==1)
				{
					color(5);
					cout<<"触发许褚锁定技——虎贲（少摸一张牌，杀与决斗伤害+1）\n";
					color(9); 
					((*w2).tili)--;
				}
				if(shenfen==17&&luanwu==3)
				{
					color(5);
					printf("触发贾诩限定技——乱武(指定回合，杀或决斗伤害为3；多获得一个回合，身份为董卓)\n");
					color(4);
					((*w2).tili)-=2;
					cout<<"你对电脑又造成2点伤害\n";
					color(9);
				} 
				i=Binsi(w1,w2,qipaidui,qipaishu);
				return i;
				break;
			}
			j=0;
			for(;;)
			{
				printf("请打出一张【杀】响应【决斗】，否则你将受到1点伤害！\n请输入手牌之前的编号，或者输入“-1”放弃出【杀】，以回车结束！\n");
				if(((*w1).zhuangbei[0].leixing==305))
				{
					printf("如果想发动【丈八蛇矛】效果，请输入“100”，以回车结束！\n");
				}
				(*w1).Kanshoupai();
				scanf("%d",&x);
				if(x==-1)
				{
					int i;		
					if(shenfen==17)
					{
						color(5);
						printf("触发贾诩锁定技——帷幕(锁定技，你的回合内你不受到伤害）\n");
						color(9);
					} 
					else if(shenfen==22)
					{
						color(5);
						printf("触发吕布锁定技——飞将（决斗对你伤害为0，决斗时对方需打出两张杀）\n"); 
						cout<<"电脑对玩家造成0伤害\n";
						color(9);
					} 
					else
					{
						((*w1).tili)--;
						color(4);
						printf("电脑对玩家造成1点伤害！\n");
						color(9);
					}
					i=Binsi(w2,w1,qipaidui,qipaishu);
					return i;
					break;
				}
				else if(((*w1).zhuangbei[0].leixing==305)&&x==100)
				{
					pai p=Zhangba(w1,qipaidui,qipaishu);
					p.paifu=-1;
					printf("打出！\n");
					j=1;
					break;
				}
				else if((*w1).shoupai[x].leixing==101)
				{
					printf("玩家打出");
					((*w1).shoupai)[x].Kanpai();
					qipaidui[*qipaishu]=((*w1).shoupai)[x];
					for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
					((*w1).shoupaishu)--;
					(*qipaishu)++;
					j=1;
					break;
				}
				else if(shenfen==23&&(*w1).shoupai[x].leixing==102)
				{
					color(5);
					printf("触发赵云技能，将闪当杀打出\n");
					color(9); 
					((*w1).shoupai)[x].Kanpai();
					qipaidui[*qipaishu]=((*w1).shoupai)[x];
					for(i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
					((*w1).shoupaishu)--;
					(*qipaishu)++;
					j=1;
					break;					
				} 
				else 
				{
					color(3);
					printf("你确定你打出的是【杀】？\n");
					color(9);
				}
			}
		}
	}
	else//玩家出杀 
	{
		for(;;)
		{
			j=0;
			for(;;)
			{
				printf("请打出一张【杀】响应【决斗】，否则你将受到1点伤害！\n请输入手牌之前的编号，或者输入“-1”放弃出【杀】，以回车结束！\n");
				if(((*w1).zhuangbei[0].leixing==305))
				{
					printf("如果想发动【丈八蛇矛】效果，请输入“100”，以回车结束！\n");
				}
				(*w2).Kanshoupai();
				scanf("%d",&x);
				if(x==-1)
				{
					int i;
					if(shenfen==22)
					{
						color(5);
						printf("触发吕布锁定技——飞将（决斗对你伤害为0，决斗时对方需打出两张杀）\n"); 
						cout<<"电脑对玩家造成0伤害\n";
						color(9);
					} 
					else
					{
						color(5);
						printf("电脑对玩家造成1点伤害！\n");
						(*w2).tili--;
						color(9);
					} 
					i=Binsi(w1,w2,qipaidui,qipaishu);
					return i;
					break;
				}
				else if(((*w2).zhuangbei[0].leixing==305)&&x==100)
				{
					pai p=Zhangba(w2,qipaidui,qipaishu);
					p.paifu=-1;
					printf("打出！\n");
					j=1;
					break;
				}
				else if((*w2).shoupai[x].leixing==101)
				{
					printf("玩家打出");
					((*w2).shoupai)[x].Kanpai();
					qipaidui[*qipaishu]=((*w2).shoupai)[x];
					for(i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
					((*w2).shoupaishu)--;
					(*qipaishu)++;
					j=1;
					break;
				}
				else if(shenfen==23&&(*w2).shoupai[x].leixing==102)
				{
					color(5);
					printf("触发赵云技能，将闪当杀打出\n");
					color(9);
					((*w2).shoupai)[x].Kanpai();
					qipaidui[*qipaishu]=((*w2).shoupai)[x];
					for(i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
					((*w2).shoupaishu)--;
					(*qipaishu)++;
					j=1;
					break;
				}
				else 
				{
					color(3);
					printf("你确定你打出的是【杀】？\n");
					color(9);
				}
			}
			j=0;
			for(x=0;x<((*w1).shoupaishu);x++)
			{
				if((*w1).shoupai[x].leixing==101)
				{
					printf("电脑打出");
					((*w1).shoupai)[x].Kanpai();
					qipaidui[*qipaishu]=((*w1).shoupai)[x];
					for(int i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
					((*w1).shoupaishu)--;
					(*qipaishu)++;
					j=1;
					break;
				}
			}
			if(shenfen==22)
			{
				color(5);
				printf("触发吕布锁定技——飞将（决斗对你伤害为0，决斗时对方需打出两张杀）\n");
				color(9); 
				for(x=0;x<((*w1).shoupaishu);x++)
				{
					if((*w1).shoupai[x].leixing==101)
					{
						printf("电脑打出");
						((*w1).shoupai)[x].Kanpai();
						qipaidui[*qipaishu]=((*w1).shoupai)[x];
						for(int i=x+1;i<=((*w1).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
						((*w1).shoupaishu)--;
						(*qipaishu)++;
						j=1;
						break;
					}
				}
			}
			if(!j)
			{
				color(4);
				printf("玩家对电脑造成1点伤害！\n");
				color(9);
				((*w2).tili)--;
				if(comshenfen==1)
				{
					color(5);
					cout<<"电脑触发华雄锁定技——恃勇（受到伤害摸两张牌）\n";
					color(9); 
					shiyong++;
				}
				i=Binsi(w2,w1,qipaidui,qipaishu);
				return i;
				break;
			}
		}
	}
}
int Jiedao(wujiang*w1,wujiang*w2,pai paidui[104],int*paiduishu,pai qipaidui[104],int*qipaishu)//借刀杀人 
{
	int i,j=0,x;
	if((*w1).juese)
	{
		for(x=0;x<((*w2).shoupaishu);x++)
		{
			if((*w2).shoupai[x].leixing==101)
			{
				printf("电脑对玩家使用");
				((*w2).shoupai)[x].Kanpai();
				qipaidui[*qipaishu]=((*w2).shoupai)[x];
				for(int i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				(*qipaishu)++;
				j=1;
				break;
			}
		}
		if(j)
		{
			i=Sha(w2,w1,paidui,paiduishu,qipaidui,qipaishu);
			return i;
			printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w1).tili,(*w1).tilishangxian,(*w2).tili,(*w2).tilishangxian);
		}
		else
		{
			color(3);
			printf("电脑放弃使用【杀】，玩家获得电脑的武器");
			color(9);
			(*w2).zhuangbei[0].Kanpai();
			(*w1).shoupai[(*w1).shoupaishu]=((*w2).zhuangbei)[0];
			((*w2).zhuangbeishu)--;
			((*w1).shoupaishu)++;
			((*w2).zhuangbei)[0].leixing=-1;
			((*w2).zhuangbei)[0].changdu=1;
			(*w1).Kanshoupai();
			return 0;
		}
	}
	else
	{
		for(;;)
		{
			printf("请对电脑使用一张【杀】，否则电脑将获得你的武器！\n请输入手牌之前的编号，或者输入“-1”放弃出【杀】，以回车结束！\n");
			if(shenfen==23)
			{
				color(5);
				cout<<"若想发动【龙胆】，直接输入【闪】的编号即可\n";
				color(9);
			}
			if(((*w2).zhuangbei[0].leixing==305))
			{
				printf("如果想发动【丈八蛇矛】效果，请输入“100”，以回车结束！\n");
			}
			(*w2).Kanshoupai();
			scanf("%d",&x);
			if(x==-1)break;
			else if(((*w2).zhuangbei[0].leixing==305)&&x==100)
			{
				pai p=Zhangba(w2,qipaidui,qipaishu);
				p.paifu=-1;
				printf("使用！\n");
				j=1;
				break;
			}
			else if((*w2).shoupai[x].leixing==101)
			{
				printf("玩家对电脑使用");
				((*w2).shoupai)[x].Kanpai();
				qipaidui[*qipaishu]=((*w2).shoupai)[x];
				for(i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				(*qipaishu)++;
				j=1;
				break;
			}
			else if(shenfen==23&&(*w2).shoupai[x].leixing==102)
			{
				color(5);
				printf("触发赵云技能，将闪当杀打出");
				color(9);
				((*w2).shoupai)[x].Kanpai();
				qipaidui[*qipaishu]=((*w2).shoupai)[x];
				for(i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				(*qipaishu)++;
				j=1;
				break;
			}
			else 
			{
				color(4);
				printf("你确定你使用的是【杀】？\n");
				color(9);
			}
		}
		if(j)
		{
			i=Sha(w2,w1,paidui,paiduishu,qipaidui,qipaishu);
			return i;
			printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w2).tili,(*w2).tilishangxian,(*w1).tili,(*w1).tilishangxian);
		}
		else
		{
			color(3);
			printf("玩家放弃使用【杀】，电脑获得玩家的武器");
			color(9);
			((*w2).zhuangbei)[0].Kanpai();
			(*w1).shoupai[(*w1).shoupaishu]=((*w2).zhuangbei)[0];
			((*w2).zhuangbeishu)--;
			((*w1).shoupaishu)++;
			((*w2).zhuangbei)[0].leixing=-1;
			((*w2).zhuangbei)[0].changdu=1;
			return 0;
		}
	}
}
void Taoyuan(wujiang*w)//桃园三结义 
{
	if((*w).tili<(*w).tilishangxian)
	{
		((*w).tili)++;
		if((*w).juese)
		{
			color(2);
			printf("玩家恢复1点体力！\n");
			color(9);
			if(shenfen==13)
			{
				color(5);
				cout<<"触发华佗锁定技——青囊\n";
				color(2);
				printf("你又恢复了1点体力！\n");
				((*w).tili)++;
				color(9);
			}
		}
		else 
		{
			color(2);
			printf("电脑恢复1点体力！\n");
			color(9);
		}
	}
}
void Kaipai(pai paidui[104],int* paiduishu,int renshu,pai wugu[10])//五谷丰登开牌 
{
	int i;
	printf("五谷丰登开牌：\n");
	for(i=1;i<=renshu;i++)
	{
		wugu[i-1]=paidui[104-(*paiduishu)];
		(*paiduishu)--;
		printf("%d ",i-1);
		wugu[i-1].Kanpai();
	}
}
void Qupai(pai wugu[10],wujiang*w)//五谷丰登取牌 
{
	int i,x;
	printf("五谷丰登开牌：\n");
	for(i=0;(wugu[i].leixing)!=-1;i++)
	{
		printf("%d ",i);
		wugu[i].Kanpai();
	}
	if((*w).juese)
	{
		for(;;)
		{
			printf("请选择你想要的卡牌，输入卡牌之前的编号，以回车结束！\n");
			scanf("%d",&x);
			if(wugu[x].leixing!=-1)
			{
				printf("玩家选择");
				wugu[x].Kanpai();
				(*w).shoupai[(*w).shoupaishu]=wugu[x];
				((*w).shoupaishu)++;
				for(i=x+1;i<=9;i++)wugu[i-1]=wugu[i];
				wugu[9].leixing=-1;
				break;
			}
			color(3);
			printf("你选择了一张空气加入手牌！");
			color(9);
		}
	}
	else
	{
		printf("电脑选择");
		wugu[0].Kanpai();
		(*w).shoupai[(*w).shoupaishu]=wugu[0];
		((*w).shoupaishu)++;
		for(i=1;i<=9;i++)wugu[i-1]=wugu[i];
		wugu[9].leixing=-1;
	}
}
void Rengpai(pai wugu[10],pai qipaidui[104],int*qipaishu)//五谷丰登扔牌 
{
	int i;
	for(i=0;wugu[i].leixing!=-1;i++)
	{
		qipaidui[*qipaishu]=wugu[i];
		(*qipaishu)++;
		wugu[i].leixing=-1;
	}
}
int Nanman(wujiang*w1,wujiang*w2,pai qipaidui[104],int*qipaishu)//南蛮入侵 
{
	int i,x;
	if((*w1).juese)
	{
		for(x=0;x<((*w2).shoupaishu);x++)
		{
			if((*w2).shoupai[x].leixing==101)
			{
				printf("电脑打出");
				((*w2).shoupai)[x].Kanpai();
				qipaidui[*qipaishu]=((*w2).shoupai)[x];
				for(int i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				(*qipaishu)++;
				return 0;
				break;
			}
		}
		if(shenfen==8)
		{
			color(5);
			cout<<"发动孟获锁定技——南蛮（南蛮入侵对你无效，对敌伤害+1）\n";
			color(4);
			printf("玩家对电脑造成1点伤害！\n");
			((*w2).tili)--;
			color(9);
		} 
		color(4);
		printf("玩家对电脑造成1点伤害！\n");
		color(9);
		((*w2).tili)--;
		if(comshenfen==1)
		{
			color(5);
			cout<<"电脑触发华雄锁定技——恃勇（受到伤害摸两张牌）\n"; 
			shiyong++;
			color(9);
		}
		i=Binsi(w1,w2,qipaidui,qipaishu);
		return i;
	}
	else
	{
		for(;;)
		{
			printf("请打出一张【杀】响应【南蛮入侵】，否则你将受到1点伤害！\n请输入手牌之前的编号，或者输入“-1”放弃出【杀】，以回车结束！\n");
			if(((*w2).zhuangbei[0].leixing==305))printf("如果想发动【丈八蛇矛】效果，请输入“100”，以回车结束！\n");
			if(shenfen==23)
			{
				color(5);
				cout<<"若想发动【龙胆】，直接输入【闪】的编号即可\n";
				color(9);
			} 
			(*w2).Kanshoupai();
			scanf("%d",&x);
			if(x==-1)
			{
				int i;
				if(shenfen==8)
				{
					color(5);
					cout<<"发动孟获锁定技——南蛮（南蛮入侵对你无效，对敌伤害+1）\n";
					color(9);
				}
				else
				{
					((*w2).tili)--;
					color(4);
				    printf("电脑对玩家造成1点伤害！\n");
				    color(9);
				}
				i=Binsi(w1,w2,qipaidui,qipaishu);
				return i;
				break;
			}
			else if(((*w2).zhuangbei[0].leixing==305)&&x==100)
			{
				pai p=Zhangba(w2,qipaidui,qipaishu);
				p.paifu=-1;
				printf("使用！\n");
				return 0;
				break;
			}
			else if((*w2).shoupai[x].leixing==101)
			{
				printf("玩家打出");
				((*w2).shoupai)[x].Kanpai();
				qipaidui[*qipaishu]=((*w2).shoupai)[x];
				for(i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				(*qipaishu)++;
				return 0;
				break;
			}
			else if(shenfen==23&&(*w2).shoupai[x].leixing==102)
			{
				color(5);
				printf("触发赵云技能，将闪当杀打出\n");
				color(9);
				((*w2).shoupai)[x].Kanpai();
				qipaidui[*qipaishu]=((*w2).shoupai)[x];
				for(i=x+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				(*qipaishu)++;
				return 0;
				break;
			}
			else
			{
				color(3);
				printf("你确定你打出的是【杀】？\n");
				color(9);
			}
		}
	}
}
int Wanjian(wujiang*w1,wujiang*w2,pai paidui[104],int*paiduishu,pai qipaidui[104],int*qipaishu)//万箭齐发 
{
	int i;
	if(!(*w1).juese)
	{
		printf("请打出一张【闪】响应【万箭齐发】，否则你将受到1点伤害！\n");
	}
	i=Shan(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
	if(((*w1).juese)&&i!=-1&&shenfen==14)
	{
		pai p;
		p=paidui[104-(*paiduishu)];
		(*paiduishu)--;
		p.Kanpai();
		int t=zhangjiao(p);
		if(t==2)
		{
			((*w2).tili)-=2;
			color(4);
			cout<<"雷公助你！！！对方遭到2点雷电伤害\n";
			color(9);
			if(comshenfen==1)
			{
				color(5);
				cout<<"电脑触发华雄锁定技——恃勇（受到伤害摸两张牌）\n";
				color(9); 
				shiyong++;
			}
		}
		else if(t==1)
		{
			((*w2).tili)--;
			((*w1).tili)++;
			color(4);
			cout<<"雷公助你！！！对方遭到1点雷电伤害,你回复1点体力\n";
			color(9);
			if(comshenfen==1)
			{
				color(5);
				cout<<"电脑触发华雄锁定技——恃勇（受到伤害摸两张牌）\n";
				color(9); 
				shiyong++;
			}
		}
		else
		{
			color(3);
			printf("Bad luck!!!\n");
			color(9);
		} 
	}
	if(i==-1)
	{
		if((*w1).juese)
		{
			(*w2).tili--;
			color(4);
			cout<<"电脑受到一点伤害\n";
			color(9);
			if(comshenfen==1)
			{
				color(5);
				cout<<"电脑触发华雄锁定技——恃勇（受到伤害摸两张牌）\n";
				color(9); 
				shiyong++;
			}
		}
		else
		{
			(*w1).tili--;
			color(4);
			cout<<"玩家受到一点伤害\n";
			color(9);
		}
		i=Binsi(w1,w2,qipaidui,qipaishu);
		return i;
	}
	else return 0;
}
int Chupai(pai paidui[104],pai qipaidui[104],int *paiduishu,int*qipaishu,wujiang*w1,wujiang*w2,pai yuanshipaidui[2][4][13])//出什么牌 （important!!!)   OK
{
	pai p1;
	int sha=1;int y=-1,i,t=((*w1).shoupaishu)-1;
	if(!(*w1).juese&&comshenfen==3&&shixue==0)
	{
		if((*w1).tili<=(*w2).tili||(*w2).tilishangxian<4)
		{
			shixue=1;
			color(5);
			cout<<"电脑触发日本鬼子限定技——嗜血（体力上限改为1，视为使用（原体力上限-1）张【杀】）\n";
			color(9);
			int s=(*w1).tilishangxian-1;
			(*w1).tilishangxian=1;
			for(int k=1;k<=s;k++)
			{
				i=Sha(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
				if(i==-1){return -1;break;}
				if((*w1).juese)printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w1).tili,(*w1).tilishangxian,(*w2).tili,(*w2).tilishangxian);
				else printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w2).tili,(*w2).tilishangxian,(*w1).tili,(*w1).tilishangxian);
			}	
		}
	}
	if(!(*w1).juese&&comshenfen==1)
	{
		color(5);
		cout<<"电脑触发华雄锁定技——无前（每回合进行判定，为红桃牌你回复一点体力，否则电脑回复一点体力）\n";
		color(9);
		cout<<"判定牌为："; 
		pai p;
		p=paidui[104-(*paiduishu)];
		(*paiduishu)--;
		p.Kanpai();
		if(p.huase==1)
		{
			color(2);
			cout<<"你回复一点体力\n";
			(*w2).tili++;
			color(9);
		} 
		else
		{
			if((*w1).tili<(*w1).tilishangxian)
			{
				color(2);
				cout<<"电脑回复一点体力\n";
				(*w1).tili++;
				color(9);
			} 
		}
	} 
	if((*w1).juese&&shenfen==23&&qianghun>0&&(*w1).shoupaishu<qianghun)
	{
		color(5);
		cout<<"触发赵云锁定技——枪魂\n";
		color(9);
		int t=qianghun-(*w1).shoupaishu;
		for(int y=1;y<=t;y++)
		{
			biao=1;
			Wuzhong(w1,paidui,paiduishu,qipaidui,qipaishu);
			biao=0;
		}
		printf("你摸了%d张牌\n",t); 
	}
	if(!(*w1).juese&&comshenfen==2&&tiaodao==0&&(*w2).shoupai>0)
	{
		color(5);
		cout<<"触发道格拉斯-麦克阿瑟锁定技——跳岛（电脑出牌阶段开始视为使用【过河拆桥】）\n";
		color(9);
		int i=0,j=0;
		for(;;)
		{
			i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
			if(!i)break;
			j++;
			i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
			if(!i)break;
			j++;
		}
		if(!(j%2))Chai(w1,w2,qipaidui,qipaishu);
		else;
		if((*w1).juese)(*w1).Kanshoupai();
	} 
	if(!(*w1).juese&&comshenfen==2&&renchuan==0)
	{
		if((*w1).tili<=(*w2).tili||(*w2).shoupaishu>=8||shenfen==14||(*w2).tilishangxian>=5)
		{
			int i,j,r=2;
			renchuan=1;
			tiaodao=1;
			color(5);
			cout<<"电脑触发道格拉斯-麦克阿瑟限定技——仁川登陆（视为使用【南蛮入侵】【万箭齐发】各两次，【兵粮寸断】【乐不思蜀】一次，摸10张牌，【杀】无限制并修改跳岛）\n";
			color(9);
			while(r)
			{
				r--;
				i=0,j=0;
				for(;;)
				{
					i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
					if(!i)break;
					j++;
					i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
					if(!i)break;
					j++;
				}
				if(!(j%2))
				{
					i=Nanman(w1,w2,qipaidui,qipaishu);
					if(i==-1)return -1;
					if((*w1).juese)printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w1).tili,(*w1).tilishangxian,(*w2).tili,(*w2).tilishangxian);
					else printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w2).tili,(*w2).tilishangxian,(*w1).tili,(*w1).tilishangxian);
				}
				i=0,j=0;
				for(;;)
				{
					i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
					if(!i)break;
					j++;
					i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
					if(!i)break;
					j++;
				}
				if(!(j%2))
				{
					i=Wanjian(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
					if(i==-1)return -1;
					if((*w1).juese)printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w1).tili,(*w1).tilishangxian,(*w2).tili,(*w2).tilishangxian);
					else printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w2).tili,(*w2).tilishangxian,(*w1).tili,(*w1).tilishangxian);
				}
			}
			cout<<"电脑使用【乐不思蜀】【兵粮寸断】\n";
			pai p;
			p.leixing=251,p.dianshu=1,p.huase=1,p.paifu=1,p.yanse=1;
			for(i=1;i>=0;i--)(*w2).pandingpai[i+1]=(*w2).pandingpai[i];
			(*w2).pandingpai[0]=p;
			((*w2).pandingshu)++;
			p.leixing=384,p.dianshu=1,p.huase=1,p.paifu=1,p.yanse=1;
			for(i=1;i>=0;i--)(*w2).pandingpai[i+1]=(*w2).pandingpai[i];
			(*w2).pandingpai[0]=p;
			((*w2).pandingshu)++;
			////////////////////////////////////////////////////////
			for(int i=1;i<=5;i++)
			{
				Wuzhong(w1,paidui,paiduishu,qipaidui,qipaishu);
			} 	
		}
	}
	for(;;t--)
	{
		if(shiyong>0)
		{
			shiyong=0;
			color(5);
			cout<<"电脑触发华雄锁定技——恃勇\n";
			color(9);
			if((*w1).juese)
			{
				Wuzhong(w2,paidui,paiduishu,qipaidui,qipaishu);
			}
			else
			{
				Wuzhong(w1,paidui,paiduishu,qipaidui,qipaishu);
			}
		}
		if((*w1).juese)
		{
			printf("\n电脑当前手牌数：%d\n",((*w2).shoupaishu));
			(*w2).Kanzhuangbei();
			(*w1).Kanshoupai();
			(*w1).Kanzhuangbei();
		}
		int j=0;
		if((*w1).juese&&((*w1).zhuangbei[0].leixing==305))
		{
			printf("如果想发动【丈八蛇矛】效果，请输入“100”，以回车结束！\n");
		}
		if(roulin==1&&shenfen==18)
		{
			roulin=0; 
			int t; 
			color(5);
			printf("触发董卓锁定技——肉林(你对敌人的伤害时,你进行判定，若为黑桃，你随机弃置1~3张牌)\n");
			color(9);
			for(int i=1;i<=3;i++)
			{
				if(((*w1).shoupaishu)>0)
				{
					srand((unsigned)time(NULL));
					t=rand()%((*w1).shoupaishu);
					printf("随机弃掉了玩家的手牌：");
					pai p=((*w1).shoupai)[t];
					((*w1).shoupai)[t].Kanpai();
					qipaidui[*qipaishu]=((*w1).shoupai)[t];
					for(i=t+1;i<=((*w2).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
					((*w1).shoupaishu)--;
					(*qipaishu)++;
				}
			}	
		} 
		if((*w1).juese&&shenfen==23&&qianghun>0&&(*w1).shoupaishu<qianghun)
		{
			color(5);
			cout<<"触发赵云锁定技——枪魂\n";
			color(9);
			int t=qianghun-(*w1).shoupaishu;
			for(int y=1;y<=t;y++)
			{
				biao=1;
				Wuzhong(w1,paidui,paiduishu,qipaidui,qipaishu);
				biao=0;
			}
			printf("你摸了%d张牌\n",t); 
		}
		y=Xuanpai(w1,t);
		if(shenfen==18&&y==99)//董卓 
		{
			if((*w1).shoupaishu>0)
			{
				srand((unsigned)time(NULL));
				int t=rand()%((*w1).shoupaishu);
				printf("随机弃掉了玩家的手牌：");
				pai p=((*w1).shoupai)[t];
				((*w1).shoupai)[t].Kanpai();
				qipaidui[*qipaishu]=((*w1).shoupai)[t];
				for(i=t+1;i<=((*w2).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
				((*w1).shoupaishu)--;
				(*qipaishu)++;
				if(p.leixing==101||p.leixing==102||p.leixing==103)
				{
					color(5);
					printf("触发董卓锁定技——酒池(随机弃置1张手牌，视为使用【酒】;若弃置的手牌为基本牌，你摸两张牌(使用酒数量<=2))\n");
					color(9);
					if(jiu<=2)
					{
						Wuzhong(w1,paidui,paiduishu,qipaidui,qipaishu);
					} 
				} 
				jiu+=1;
				cout<<"你视为使用一张【酒】"<<endl; 
			}
			else
			{
				color(4);
				cout<<"你连一张牌都没有，发动个锤子！！！\n";
				color(9);
			} 
		}
		else if((shenfen==19||shenfen==24)&&y==111&&((*w1).tili)>1)//苦肉一点体力 
		{
			(*w1).tili--;
			color(5);
			printf("触发锁定技——苦肉(减一点体力摸两张牌,减一点体力上限该回合杀伤害+2)\n");
			color(9);
			Wuzhong(w1,paidui,paiduishu,qipaidui,qipaishu);
		} 
		else if((shenfen==19||shenfen==24)&&y==222&&((*w1).tilishangxian)>1)//苦肉一点体力上限 
		{
			(*w1).tilishangxian--;
			color(5);
			printf("触发锁定技——苦肉(减一点体力摸两张牌,减一点体力上限该回合杀伤害+2)\n");
			color(9);
			kurou+=2;
		}
		else if(shenfen==19&&(y==111||y==222)&&((*w1).tili==1||(*w1).tilishangxian==1))//把自己干死了 
		{
			color(4);
			cout<<"别苦肉了，人没有啦\n";
			color(9);
		}
		else if(shenfen==10&&y==101)
		{
			color(5);
			printf("触发袁绍锁定技——4.乱击（出牌阶段，弃置两张牌，视为使用【万箭齐发】）\n"); 
			color(9);
			if((*w1).shoupaishu>=2)
			{
				srand((unsigned)time(NULL));
				int t=rand()%((*w1).shoupaishu);
				printf("随机弃掉了玩家的手牌：");
				pai p=((*w1).shoupai)[t];
				((*w1).shoupai)[t].Kanpai();
				qipaidui[*qipaishu]=((*w1).shoupai)[t];
				for(i=t+1;i<=((*w2).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
				((*w1).shoupaishu)--;
				(*qipaishu)++;	
				int t2=rand()%((*w1).shoupaishu);
				printf("随机弃掉了玩家的手牌：");
				pai q=((*w1).shoupai)[t2];
				((*w1).shoupai)[t2].Kanpai();
				qipaidui[*qipaishu]=((*w1).shoupai)[t2];
				for(i=t2+1;i<=((*w2).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
				((*w1).shoupaishu)--;
				(*qipaishu)++;	
				for(;;)
				{
					i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
					if(!i)break;
					j++;
					i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
					if(!i)break;
					j++;
				}
				if(!(j%2))
				{
					i=Wanjian(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
					if((*w1).juese)printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w1).tili,(*w1).tilishangxian,(*w2).tili,(*w2).tilishangxian);
					else printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w2).tili,(*w2).tilishangxian,(*w1).tili,(*w1).tilishangxian);
				}
			}
			else
			{
				color(4);
				cout<<"你连两张牌都没有，发动个锤子！！！\n";
				color(9);
			}
		}
		else if(shenfen==23&&(*w1).juese&&y==123)
		{
			cout<<"杀当闪，输入1;闪当杀，输入2\n";
			int longdan;
			cin>>longdan;
			if(longdan==1)
			{
				cout<<"闪个寂寞\n";
			}
			else
			{
				cout<<"输入【闪】编号\n";
				int t;
				cin>>t;
				pai p=((*w1).shoupai)[t];
				if(p.leixing==102)
				{
					cout<<"你将";
					((*w1).shoupai)[t].Kanpai();
					cout<<"当【杀】使用\n";
					qipaidui[*qipaishu]=((*w1).shoupai)[t];
					for(i=t+1;i<=((*w2).shoupaishu);i++)((*w1).shoupai)[i-1]=((*w1).shoupai)[i];
					((*w1).shoupaishu)--;
					(*qipaishu)++;	
					i=Sha(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
				}
				else
				{
					color(4);
					cout<<"What are you doing?\n";
					color(9);
				}
			}
		}
		else//如果是正常出牌 
		{
			p1=Panpai(w1,&sha,y,qipaidui,qipaishu);//判断是否能使用牌 
			if((p1).leixing==-1)//如果不能 
			{
				if(!(*w1).juese&&comshenfen==2&&tiaodao==1&&(*w2).shoupai>0)
				{
					i=0,j=0;
					color(5);
					cout<<"触发道格拉斯-麦克阿瑟锁定技——跳岛（电脑结束阶段开始视为使用【过河拆桥】）\n";
					color(9);
					for(;;)
					{
						i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
						if(!i)break;
						j++;
						i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
						if(!i)break;
						j++;
					}
					if(!(j%2))Chai(w1,w2,qipaidui,qipaishu);
					else;
					if((*w1).juese)
					{
						(*w1).Kanshoupai();
					}
				} 
				break;
			}
			else if(!(*w1).juese&&comshenfen==4&&chaofeng==0&&(*w2).shoupai>0)
			{
				chaofeng=1;
				int k=rand();
				k%=4;
				i=0,j=0;
				color(5);
				cout<<"电脑触发 趣学语文Mr.Dong锁定技——嘲彘(每回合可拆掉玩家1-3张手牌)"<<endl;
				cout<<"                               -------------“髀肉复生是什么意思？” \n";
				system("pause"); 
				color(9);
				while(k--)
				{
					for(;;)
					{
						i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
						if(!i)break;
						j++;
						i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
						if(!i)break;
						j++;
					}
					if(!(j%2))Chai(w1,w2,qipaidui,qipaishu);
					else;
					if((*w1).juese)
					{
						(*w1).Kanshoupai();
					}
				}	
			} 
			else if((p1).leixing==0)//能 
			{
				continue;
			}
			else
			{
				int duixiang;//对象 
				duixiang=Mubiao(p1,w1,w2,&sha);//判断目标是否合法 
				if(duixiang==-2)continue;//不合法 
				else//合法 
				{
					if((*w1).juese)
					{
						if(shenfen==20)
						{
							//黑桃：0   红桃:1   草花：2    方片：3 
							sizhonghuase[p1.huase]=1;
							if(sizhonghuase[0]==1)
							{
								cout<<"截至目前你已打出黑桃牌\n";
							} 
							if(sizhonghuase[1]==1)
							{
								cout<<"截至目前你已打出红桃牌\n";
							} 
							if(sizhonghuase[2]==1)
							{
								cout<<"截至目前你已打出草花牌\n";
							}
							if(sizhonghuase[3]==1)
							{
								cout<<"截至目前你已打出方片牌\n";
							}
							if(sizhonghuase[0]==1&&sizhonghuase[1]==1&&sizhonghuase[2]==1&&sizhonghuase[3]==1)
							{
								color(5);
								cout<<"你可触发技能'攻心'\n";
								gongxin=1; 
								color(9);
							}
						}
					}
					Da1pai(w1,w2,qipaidui,qipaishu,y);//出牌结算 
					Miaoshu(p1,((*w1).juese),duixiang);//输出对什么对象使用 
					if(!((*w1).juese))//如果不是电脑回合 
					{
						printf("\n电脑当前手牌数：%d\n",((*w1).shoupaishu));
						(*w1).Kanzhuangbei();
						(*w2).Kanshoupai();
						(*w2).Kanzhuangbei();
					}
					switch(p1.leixing)
					{
						case 101://杀 
						i=Sha(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
						if(i==-1){return -1;break;}
						if((*w1).juese)printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w1).tili,(*w1).tilishangxian,(*w2).tili,(*w2).tilishangxian);
						else printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w2).tili,(*w2).tilishangxian,(*w1).tili,(*w1).tilishangxian);
						break;
						case 103://桃 
						Tao(w1);
						break;
						case 201://过河拆桥 
						if(!(*w1).juese&&shenfen==17)
						{
							if(p1.huase==0||p1.huase==2)
							{
								color(5);
								printf("触发贾诩锁定技——帷幕(锁定技，黑色锦囊牌的你无效;你的回合内你不受到伤害)\n");
								color(9);
								break; 
							}
						} 
						for(;;)
						{
							i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
						}
						if(!(j%2))Chai(w1,w2,qipaidui,qipaishu);
						else;
						if((*w1).juese)(*w1).Kanshoupai();
						break;
						case 202://顺手牵羊 
						if(!(*w1).juese&&shenfen==17)
						{
							if(p1.huase==0||p1.huase==2)
							{
								color(5);
								printf("触发贾诩锁定技——帷幕(锁定技，黑色锦囊牌的你无效;你的回合内你不受到伤害)\n");
								color(9);
								break; 
							}
						} 
						for(;;)
						{
							i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
						}
						if(!(j%2))Qian(w1,w2);
						else;
						if((*w1).juese)(*w1).Kanshoupai();
						break;
						case 203://无中生有 
						for(;;)
						{
							i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
						}
						if(!(j%2))Wuzhong(w1,paidui,paiduishu,qipaidui,qipaishu);
						else;
						break;
						case 204://决斗 
						if(!(*w1).juese&&shenfen==17)
						{
							if(p1.huase==0||p1.huase==2)
							{
								color(5);
								printf("触发贾诩锁定技——帷幕(锁定技，黑色锦囊牌的你无效;你的回合内你不受到伤害)\n");
								color(9);
								break; 
							}
						} 
						for(;;)
						{
							i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
						}
						if(!(j%2))
						{
							i=Juedou(w1,w2,qipaidui,qipaishu);
							if(i==-1)return -1;
							if((*w1).juese)printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w1).tili,(*w1).tilishangxian,(*w2).tili,(*w2).tilishangxian);
							else printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w2).tili,(*w2).tilishangxian,(*w1).tili,(*w1).tilishangxian);
						}
						break;
						case 205://借刀杀人 
						if(!(*w1).juese&&shenfen==17)
						{
							if(p1.huase==0||p1.huase==2)
							{
								color(5);
								printf("触发贾诩锁定技——帷幕(锁定技，黑色锦囊牌的你无效;你的回合内你不受到伤害)\n");
								color(9);
								break; 
							}
						} 
						for(;;)
						{
							i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
						}
						if(!(j%2))
						{
							i=Jiedao(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
							if(i==-1)return -1;
							if((*w1).juese)printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w1).tili,(*w1).tilishangxian,(*w2).tili,(*w2).tilishangxian);
							else printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w2).tili,(*w2).tilishangxian,(*w1).tili,(*w1).tilishangxian);
						}
						break;
						case 206://桃园结义 
						if(!(*w1).juese&&shenfen==17)
						{
							if(p1.huase==0||p1.huase==2)
							{
								color(5);
								printf("触发贾诩锁定技——帷幕(锁定技，黑色锦囊牌的你无效;你的回合内你不受到伤害)\n");
								color(9);
								break; 
							}
						} 
						for(;;)
						{
							i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
						}
						if(!(j%2))Taoyuan(w1);
						j=0;
						for(;;)
						{
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
						}
						if(!(j%2))Taoyuan(w2);
						break;
						case 207://五谷丰登 
						if(!(*w1).juese&&shenfen==17)
						{
							if(p1.huase==0||p1.huase==2)
							{
								color(5);
								printf("触发贾诩锁定技——帷幕(锁定技，黑色锦囊牌的你无效;你的回合内你不受到伤害)\n");
								color(9);
								break; 
							}
						} 
						pai wugu[10];
						for(i=1;i<=10;i++)wugu[i-1].leixing=-1;
						Kaipai(paidui,paiduishu,2,wugu);
						for(;;)
						{
							i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
						}
						if(!(j%2))Qupai(wugu,w1);
						for(;;)
						{
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
						}
						if(!(j%2))Qupai(wugu,w2);
						Rengpai(wugu,qipaidui,qipaishu); printf("弃牌数:%d\n",*qipaishu);
						break;
						case 208://南蛮入侵 
						if(!(*w1).juese&&shenfen==17)
						{
							if(p1.huase==0||p1.huase==2)
							{
								color(5);
								printf("触发贾诩锁定技——帷幕(锁定技，黑色锦囊牌的你无效;你的回合内你不受到伤害)\n");
								color(9);
								break; 
							}
						} 
						for(;;)
						{
							i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
						}
						if(!(j%2))
						{
							i=Nanman(w1,w2,qipaidui,qipaishu);
							if(i==-1)return -1;
							if((*w1).juese)printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w1).tili,(*w1).tilishangxian,(*w2).tili,(*w2).tilishangxian);
							else printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w2).tili,(*w2).tilishangxian,(*w1).tili,(*w1).tilishangxian);
						}
						break;
						case 209://万箭齐发 
						if(!(*w1).juese&&shenfen==17)
						{
							if(p1.huase==0||p1.huase==2)
							{
								color(5);
								printf("触发贾诩锁定技——帷幕(锁定技，黑色锦囊牌的你无效;你的回合内你不受到伤害)\n");
								color(9);
								break; 
							}
						} 
						for(;;)
						{
							i=Wuxie(&p1,w1,w2,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
							i=Wuxie(&p1,w2,w1,qipaidui,qipaishu,0);
							if(!i)break;
							j++;
						}
						if(!(j%2))
						{
							i=Wanjian(w1,w2,paidui,paiduishu,qipaidui,qipaishu);
							if(i==-1)return -1;
							if((*w1).juese)printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w1).tili,(*w1).tilishangxian,(*w2).tili,(*w2).tilishangxian);
							else printf("玩家当前体力值：%d/%d\n电脑当前体力值：%d/%d\n",(*w2).tili,(*w2).tilishangxian,(*w1).tili,(*w1).tilishangxian);
						}
						break;
						case 361://【赤兔(-1)】
						case 362://【大宛(-1)】
						case 363://【紫辛(-1)】
						((*w1).juli[0])--;break;//出牌方到敌人敌人距离-1 
						case 381://【爪黄飞电(+1)】
						case 382://【的卢(+1)】
						case 383://【绝影(+1)】
						((*w2).juli[0])++;break;//敌人到出牌方的距离+1 
						default:break;
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}
void Qipai(pai shoupai[20],int *shoupaishu,pai qipaidui[104],int *qipaishu,int juese,int *shoupaishangxian)//弃牌 
{
	int x;
	if((*shoupaishu)>(*shoupaishangxian))
	{
		if(juese!=1&&juese!=0)
		{
			color(4);
			printf("身份参数错误！");
			color(9);
		}
		int q=(*shoupaishu)-(*shoupaishangxian);
		if(comshenfen==2)
		{
			if(q-5<0)
			{
				q=0;
			}
			else
			{
				q-=5;
			}
		} 
		int i,j;
		for(j=1;j<=q;j++)
		{
			for(;;)
			{
				if(juese)
				{
					if(*shoupaishu<=8)
					{
						color(5);
						if(shenfen==12)
						{
							printf("触发曹仁锁定技——坚守(手牌数小于等于8时，不弃牌)\n");
						}
						else if(shenfen==24)
						{
							printf("触发LI HAOXUAN锁定技——坚守(手牌数小于等于8时，不弃牌)\n");
						}
						color(9);
						return ;
					} 
					if(shenfen==14&&leijishanghai<0&&(*shoupaishu)<=(*shoupaishangxian+2))
					{
						color(5);
						printf("触发张角已觉醒技——大吉（累计造成的伤害大于等于4时，体力+2，手牌上限+2）\n"); 
						color(9);
						return ;
					} 
					printf("弃牌请输入手牌之前的编号，以回车结束！\n注：一次只能弃一张牌\n");
					printf("手牌数：%d\n",*shoupaishu);
					scanf("%d",&x);
					if(x>=0&&x<(*shoupaishu))break;
					else 
					{
						color(4);
						printf("你弃掉了一张空气！\n");
						color(9);
					}
				}
				else
				{
					srand((unsigned)time(NULL));
					x=rand()%(*shoupaishu);
					break;
				}
			}
			qipaidui[*qipaishu]=shoupai[x];
			for(i=x+1;i<=(*shoupaishu);i++)shoupai[i-1]=shoupai[i];
			(*shoupaishu)--;
			if(juese)printf("弃牌阶段玩家弃置");
			else printf("弃牌阶段电脑弃置");
			qipaidui[*qipaishu].Kanpai();
			(*qipaishu)++;
			int m;
			if(juese)
			{
				printf("玩家当前手牌：\n");
				for(m=0;m<=(*shoupaishu-1);m++)
				{
					printf("%d ",m);
					(shoupai[m]).Kanpai();
				}
			} 
			printf("弃牌堆：%d\n",*qipaishu);
		}
	}
}
int Huihe(pai A[104],pai B[104],int *x,int *y,pai yuanshipaidui[2][4][13],wujiang *w1,wujiang *w2)//回合
{ 
	printf("\n回合开始阶段……\n");
	chaofeng=0;
	if(shenfen==14&&leijishanghai>=4&&((*w1).juese))
	{
		color(5);
		printf("触发张角觉醒技——大吉（累计造成的伤害大于等于4时，体力+2，手牌上限+2）\n"); 
		color(9);
		leijishanghai=-100000;
		((*w1).tili)+=2;
	}
	qianghun=0;
	if(shenfen==23&&(*w1).juese)
	{
		color(5);
		printf("是否触发赵云锁定技——枪魂(你可在回合开始阶段失去x点体力,本回合手牌若少于x则补至x张)\n");
		cout<<"是,输入即将失去的体力，否则输入0\n";
		color(9);
		int shi;
		cin>>shi;
		if(shi>0)
		{
			(*w1).tili-=shi;
			qianghun=shi;
		} 
	}
	kurou=0;//黄盖 
	jiu=0;//董卓 
	qingcheng=0;//甄宓 
	huben=0;//许褚 
	haoqiang=0;//袁绍 
	gongxin=0;//吕蒙
	memset(sizhonghuase,0,sizeof(sizhonghuase)); 
	if(shenfen==21&&(*w1).juese)
	{
		color(5);
		printf("是否触发貂蝉锁定技——离魂(你获得对方所有手牌，然后翻面)\n");
		printf("是，输入1\n");
		color(9);
		int u;
		cin>>u;
		if(u==1)
		{
			lihun=1;
			while((*w2).shoupaishu>0)
			{
				srand((unsigned)time(NULL));
				int y=rand()%((*w2).shoupaishu);
				printf("你牵走了电脑的");
				((*w2).shoupai)[y].Kanpai();
				(*w1).shoupai[(*w1).shoupaishu]=((*w2).shoupai)[y];
				for(int i=y+1;i<=((*w2).shoupaishu);i++)((*w2).shoupai)[i-1]=((*w2).shoupai)[i];
				((*w2).shoupaishu)--;
				((*w1).shoupaishu)++;
			}
		} 
	} 
	switch((*w1).huihekaishi)
	{
		case 0:break;
		default:color(4);printf("回合开始阶段参数错误！\n");color(9);break;
	}
	////////////////////////////////////////
	printf("判定阶段……\n");
	int K=0,bingliangcunduan=0;
	if(comshenfen==4&&!(*w1).juese)
	{
		cout<<"电脑触发 趣学语文Mr.Dong锁定技——天机(跳过判定阶段)";
		cout<<"               -------------“以我有限的智慧，你肯定是抄的！！！” \n";
	}
	else
	{
		if((*w1).pandingshu>0)
		{
			int i,j;
			for(;(*w1).pandingshu;)
			{
				switch((*w1).pandingpai[0].leixing)
				{
					case 251:printf("【乐不思蜀】开始判定……\n"); break;
					case 252:printf("【闪电】开始判定……\n");break;
					case 384:printf("【兵粮寸断】开始判定……\n");break;
					default:printf("【？？】开始判定……\n");break;
				}
				j=0;
				pai p=((*w1).pandingpai[0]);
				for(;;)
				{
					i=Wuxie(&p,w2,w1,B,y,0);
					if(!i)break;
					j++;
					i=Wuxie(&p,w1,w2,B,y,0);
					if(!i)break;
					j++;
				}
				switch((*w1).pandingpai[0].leixing)
				{
					case 251:
					if(!(j%2))
					{
						printf("【乐不思蜀】的判定牌是：");
						Panding(A,x,B,y,w1,w2);
						if(shenfen==14)
						{
							GaiPanding(A,x,B,y,w1,w2);
						}
						if((B[(*y)-1].huase)!=1)
						{
							printf("【乐不思蜀】判定成功！\n");
							color(3);
							if((*w1).juese)printf("玩家");
							else printf("电脑");
							printf("跳过出牌阶段！\n");
							system("pause");
							K=-1;
						}
						else 
						{
							printf("【乐不思蜀】判定失败！\n");
						}
					}
					B[*y]=(*w1).pandingpai[0];
					((*w1).pandingshu)--;
					(*w1).pandingpai[0]=(*w1).pandingpai[1];
					(*w1).pandingpai[1]=(*w1).pandingpai[2];
					(*w1).pandingpai[2].leixing=-1;
					(*y)++;
					break;
					case 252:
					if(!(j%2))
					{
						printf("【闪电】的判定牌是：");
						Panding(A,x,B,y,w1,w2);
						if(shenfen==14)
						{
							GaiPanding(A,x,B,y,w1,w2);
						}
						if((B[(*y)-1].huase==0)&&(B[(*y)-1].dianshu>=1)&&(B[(*y)-1].dianshu<=8))
						{
							printf("【闪电】判定成功！\n");
							printf("轰隆！！！\n");
							if((*w1).juese)
							{
								color(4);
								printf("正道的光，照在了你身上——玩家");
							}
							else 
							{
								color(4);
								printf("天助我也——电脑");
							}
							printf("受到3点巨额雷电伤害！\n");
							color(9);
							system("pause");
							((*w1).tili)=((*w1).tili)-3;
							i=Binsi(w2,w1,B,y);
							B[*y]=(*w1).pandingpai[0];
							((*w1).pandingshu)--;
							(*w1).pandingpai[0]=(*w1).pandingpai[1];
							(*w1).pandingpai[1]=(*w1).pandingpai[2];
							(*w1).pandingpai[2].leixing=-1;
							(*y)++;
							if(i==-1)
							{
								return -1;
							}
						}
						else
						{
							printf("【闪电】判定失败！\n");
							printf("幸哉幸哉\n");
							(*w2).pandingpai[2]=(*w2).pandingpai[1];
							(*w2).pandingpai[1]=(*w2).pandingpai[0];
							(*w2).pandingpai[0]=(*w1).pandingpai[0];
							(*w1).pandingpai[0]=(*w1).pandingpai[1];
							(*w1).pandingpai[1]=(*w1).pandingpai[2];
							(*w1).pandingpai[2].leixing=-1;
							((*w1).pandingshu)--;
							((*w2).pandingshu)++;
						}
						break;
						
					}
					case 384:
					if(!(j%2))
					{
						printf("【兵粮寸断】的判定牌是：");
						Panding(A,x,B,y,w1,w2);
						if(shenfen==14)
						{
							GaiPanding(A,x,B,y,w1,w2);
						}
						if((B[(*y)-1].huase!=2))
						{
							printf("【兵粮寸断】判定成功！\n");
							bingliangcunduan=-1;
							if((*w1).juese)
							{
								color(3);
								cout<<"你跳过摸牌阶段~~~\n";
								color(9);
							}
							else
							{
								color(3);
								cout<<"电脑跳过摸牌阶段~~~\n";
								color(9);
							}
						}
						else
						{
							cout<<"【兵粮寸断】判定失败！\n"; 
						}
						B[*y]=(*w1).pandingpai[0];
						((*w1).pandingshu)--;
						(*w1).pandingpai[0]=(*w1).pandingpai[1];
						(*w1).pandingpai[1]=(*w1).pandingpai[2];
						(*w1).pandingpai[2].leixing=-1;
						(*y)++;
						break;		
					}
					default:printf("判定牌错误！");
					} 
				printf("弃牌数:%d\n",*y);
			}
		}
		else if(!((*w1).pandingshu));
		else 
		{
			color(4);
			printf("判定阶段参数错误！\n");
			color(9);
		}
	}
	////////////////////////////////////////////
	printf("摸牌阶段……\n");
	if(bingliangcunduan==-1) 
	{
		if(((*w1).juese))
		{
			cout<<"兵粮寸断判定成功，玩家跳过摸牌阶段\n";
			system("pause");
		}
		else
		{
			cout<<"兵粮寸断判定成功，电脑跳过摸牌阶段\n";
			system("pause");
		}
	}
	else
	{
		switch((*w1).mopai)
		{
			case 0:Mopai(&((*w1).shoupaishu),(*w1).shoupai,A,x,B,y,(*w1).juese);break;
			case -1:break;
			default:color(4);printf("摸牌阶段参数错误！\n");color(9);break;
		}
	} 
	if((*w1).juese&&shenfen==20)
	{
		color(5);
		printf("是否触发吕蒙锁定技——克己(跳过出牌阶段，你摸2张牌，然后跳过弃牌阶段)\n");
		color(9);
		cout<<"是，输入1\n";
		int g;
		cin>>g;
		if(g==1)
		{
			Mopai(&((*w1).shoupaishu),(*w1).shoupai,A,x,B,y,(*w1).juese);
			K=-1;
		} 
	} 
	////////////////////////////////////////////////
	printf("出牌阶段……\n");
	if(comshenfen==4)
	{
		cout<<"电脑触发 趣学语文Mr.Dong锁定技——苦水(出牌阶段全场失去1点体力)";
		cout<<" --------“要不是当年我错1拖3，我的学校就没有师范二字。！” \n";
		(*w1).tili-=1;
		(*w2).tili-=1; 
		if(!(*w1).juese&&(*w2).tili>=4&&wansui==0)
		{
			wansui=1;
			color(4);
			cout<<"电脑触发 趣学语文Mr.Dong限定技——万岁(对全场造成3点伤害，玩家体力上限减1)";
			cout<<"--------“工具牛马螺丝钉？山呼万岁？大厦将倾？！！” \n";
			color(9);
			system("pause");
			(*w1).tili-=3;
			(*w2).tili-=3;
			(*w2).tilishangxian-=1; 
		}
		color(4);
		if(!(*w1).juese)
		{
			cout<<"电脑体力:"<<(*w1).tili<<"   玩家体力："<<(*w2).tili<<endl; 
		}
		else
		{
			cout<<"电脑体力:"<<(*w2).tili<<"   玩家体力："<<(*w1).tili<<endl; 
		}
		color(9);
	}
	if(K==-1)goto M;
	switch((*w1).chupai)
	{
		case 0://如果出牌 
		{
			int i;
			i=Chupai(A,B,x,y,w1,w2,yuanshipaidui);//一波神奇的操作~~~ 
			if(i==-1)
			{
				return -1;
				break;
			}
			else
			{
				break;
			}
		}
		case -1:break;//结束出牌 
		default:color(4);printf("出牌阶段参数错误！\n");color(9);break;
	}
	////////////////////////////////
	M:
	printf("弃牌阶段……\n");
	if(shenfen==20&&K==-1)
	{
		color(5);
		printf("触发吕蒙锁定技——克己(跳过出牌阶段，你摸2张牌，然后跳过弃牌阶段)\n");
		color(9); 
	}
	else if(comshenfen==3&&(*w1).tili<=0)
	{
		color(4);
		cout<<"日本鬼子玉碎了~~~~\n";
		color(9);
		return -1;
	}
	else if((*w1).tili<=0||(*w2).tili<=0)
	{
		if(!(*w1).juese)
		{
			cout<<"电脑体力:"<<(*w1).tili<<"   玩家体力："<<(*w2).tili<<endl; 
		}
		else
		{
			cout<<"电脑体力:"<<(*w2).tili<<"   玩家体力："<<(*w1).tili<<endl; 
		}
		if((*w1).juese&&(*w1).tili<=0)
		{
			color(4);
			cout<<"你嗝屁了\n";
		}
		else if((*w1).juese&&(*w2).tili<=0)
		{
			color(4);
			cout<<"电脑凉凉了\n";
		}
		else if(!(*w1).juese&&(*w1).tili<=0)
		{
			color(4);
			cout<<"电脑凉凉了\n";
		}
		else if(!(*w1).juese&&(*w2).tili<=0)
		{
			color(4);
			cout<<"你嗝屁了\n";
		}
		color(9);
		return -1;
	} 
	else
	{
		switch((*w1).qipai)
		{
			case 0:
			Qipai((*w1).shoupai,&((*w1).shoupaishu),B,y,(*w1).juese,&((*w1).tili));break;
			default:color(4);printf("弃牌阶段参数错误！\n");color(9);break;
		}
	}
	/////////////////////////////// 
	printf("回合结束阶段……\n");
	if(((*w1).juese))
	{
		if(shenfen==18&&(*w1).tili>(*w2).tili)
		{
			color(5); 
			printf("触发董卓锁定技——崩环(若你的体力为全场最大，你每回合减一点体力或体力上限)\n");
			color(9);
			printf("减一点体力,输入1;减一点体力上限,输入2\n");
			int x;
			cin>>x;
			if(x==1)
			{
				(*w1).tili--;
			}
			else
			{
				(*w1).tilishangxian--;
			}
			while((*w1).tilishangxian<(*w1).tili)
			{
				(*w1).tili--;
			} 
			cout<<"玩家体力/体力上限:"<< (*w1).tili<<'/'<<(*w1).tilishangxian<<endl;
		}
		else if(shenfen==23&&qianghun>0)//枪魂特判 
		{
			int i=Binsi(w2,w1,B,y);
			return i;
		}
		else if(shenfen==21)
		{
			color(5);
			printf("触发貂蝉锁定技——闭月(结束阶段摸两张牌)\n");
			color(9);
			Mopai(&((*w1).shoupaishu),(*w1).shoupai,A,x,B,y,(*w1).juese);
		} 
		else if(shenfen==25)
		{
			color(5);
			printf("触发DONG 韵存 锁定技——闭月羞花(结束阶段摸两张牌)\n");
			color(9);
			system("pause"); 
			Mopai(&((*w1).shoupaishu),(*w1).shoupai,A,x,B,y,(*w1).juese);
		}
		if(comshenfen==2)
		{
			shao=1;
			Mopai(&((*w1).shoupaishu),(*w1).shoupai,A,x,B,y,(*w1).juese);
			Mopai(&((*w1).shoupaishu),(*w1).shoupai,A,x,B,y,(*w1).juese);
			shao=0;
		} 
	}
	else 
	{
		if((*w1).tili>(*w2).tili&&comshenfen==2)
		{
			color(5);
			cout<<"电脑触发道格拉斯-麦克阿瑟锁定技——骄恣（体力为全场最大，获得【崩环】）\n";
			color(9);
			if((*w1).tili<(*w1).tilishangxian)
			{
				(*w1).tilishangxian--;
			}
			else
			{
				(*w1).tili--;
			}
			cout<<"电脑体力/体力上限:"<<(*w1).tili<<'/'<<(*w1).tilishangxian<<endl;
		}
	} 
	switch((*w1).huihejieshu)
	{
		case 0:break;
		default:color(4);printf("回合结束阶段参数错误！\n");color(9);break;
	}
	return 0;
}
void SGS()//三国杀板块  
{
	color(9);
	printf("玩前必读！！！\n");
	printf("三国杀记牌口诀:\n拆六顺五无中四\n南蛮决乐无懈三\n借刀五谷闪电二\n桃园箭盾两八卦\n十一武器弩二把\n三十杀和十五闪\n八桃加减马各三\n");   
	printf("注释:\n拆六顺五就是说'过河拆桥'有6张,'顺手牵羊'有5张,而无中四就是'无懈可击'有4张\n");
	printf("南蛮决乐无懈三，就是说'南蛮入侵'、'决斗'、'乐不思蜀'和'无懈可击'各有3张\n");
	printf("借刀五谷闪电二，意思是'借刀杀人'有2张，'五谷丰登'有2张，'闪电'也有2张\n");
	printf("桃园箭盾两八卦，意味着'桃园结义'、'万箭齐发'和'仁王盾'各有一张，而'八卦阵'有2张\n");
	printf("十一武器弩两把，就是说有11把武器，其中有2把诸葛连弩\n");
	printf("此外还有30个杀，15个闪，以及8个桃\n");
	printf("而控制距离的'+1马'和'-1马'都各有三张\n");
	system("pause");
	system("cls");
	printf("游戏开始！！！\n");
	printf("请选择武将：\n(输入武将前面的序号）\n");
	cout<<"标准包：\n";
	printf("1.张飞\n");
	printf("2.庞统\n");
	printf("3.周瑜\n");
	printf("4.诸葛亮\n");
	printf("5.曹操\n");
	printf("6.黄忠\n");
	printf("7.许褚\n");
	printf("8.孟获\n"); 
	printf("9.审配\n");
	printf("10.袁绍\n");
	printf("11.袁术\n");
	printf("12.曹仁\n"); 
	printf("13.华佗\n");
	color(7);
	printf("14.张角\n");
	color(9);
	printf("15.甄宓\n");
	printf("16.马超\n");
	printf("17.贾诩\n");
	printf("18.董卓\n");
	printf("19.黄盖\n");
	printf("20.吕蒙\n");
	printf("21.貂蝉\n");
	printf("22.吕布\n");
	printf("23.赵云\n");
	color(4);
	cout<<"警告：前方高能\n";
	color(2);
	printf("24.LI HAOXUAN\n");
	printf("25.DONG 韵存\n");
	color(9);
	printf("其他：平民\n");
	color(5);
	cin>>shenfen;
	if(shenfen==1)
	{
	    printf("恭喜你获得张飞锁定技——咆哮（杀的次数无限制；出一张杀造成伤害，摸对方一张手牌）\n");
	}
	if(shenfen==2)
	{
	    printf("恭喜你获得庞统限定技——涅槃（濒死时生命值回复为3，下回合多摸3张牌）\n");
	}
	if(shenfen==3)
	{
	    printf("恭喜你获得周瑜锁定技——英姿（你比别人多摸一张牌）\n");
	}
	if(shenfen==4)
	{
	    printf("恭喜你获得诸葛亮锁定技——空城（自带不可拆八卦阵）\n");
	}
	if(shenfen==5)
	{
	    printf("恭喜你获得曹操锁定技——兵锋（自带不可拆青釭剑）\n");
	    printf("恭喜你获得曹操锁定技——屯田（摸牌时随机判定，若是奇数摸三张牌，偶数摸两张牌）\n");
	    printf("恭喜你获得曹操锁定技——奸雄（每对用杀对敌产生两点伤害，下回合多模1张牌）\n");
	}
	if(shenfen==6)
	{
	    printf("恭喜你获得黄忠锁定技——箭术（自带不可拆麒麟弓）\n");
	}
	if(shenfen==7)
	{
	    printf("恭喜你获得许褚锁定技——裸衣（自带不可拆贯石斧）\n");
	    printf("恭喜你获得许褚锁定技——虎贲（少摸一张牌，杀与决斗伤害+1）\n"); 
	}
	if(shenfen==8)
	{
		printf("恭喜你获得孟获锁定技——南蛮（南蛮入侵对你无效，对敌伤害+1）\n");
	}
	if(shenfen==9)
	{
		printf("恭喜你获得审配锁定技——1.刚烈（敌人用杀对你伤害1点，你对敌人伤害一点（敌人体力值>1时）\n");
		printf("恭喜你获得审配锁定技——2.死节（濒死时需2个桃,若没死下回合多摸3张牌）\n"); 
	}
	if(shenfen==10) 
	{
		printf("恭喜你获得袁绍限定技——1.四世三公（开局多摸七张牌）\n");
		printf("恭喜你获得袁绍锁定技——2.结交豪强（可以多出一张杀，多摸一张牌）\n");
		printf("恭喜你获得袁绍锁定技——3.骄纵（濒死时需两张桃）\n"); 
		printf("恭喜你获得袁绍锁定技——4.乱击（出牌阶段，弃置两张牌，视为使用【万箭齐发】）\n");
	}
	if(shenfen==11)
	{
		printf("恭喜你获得袁术锁定技——伪帝（开局多摸14张牌，然后每回合依次递减2（到0为止））\n");
		printf("恭喜你获得袁术锁定技——崩溃（杀对你造成额外一点伤害）\n") ;
	}
	if(shenfen==12)
	{
		printf("恭喜你获得曹仁锁定技——坚守(手牌数小于等于8时，不弃牌)\n");
		printf("恭喜你获得曹仁锁定技——无援(体力大于2时，桃无效)\n"); 
	}
	if(shenfen==13)
	{
		printf("恭喜你获得华佗锁定技——青囊(使用桃/桃园三结义多回复一点生命)\n");
		printf("恭喜你获得华佗锁定技——急救(濒死时进行判定，若为奇数回2点体力，偶数-2点体力)\n"); 
	} 
	if(shenfen==14)
	{
		printf("张角：“苍天已死，黄天当立，岁在甲子，天下大吉！！！”\n"); 
		printf("恭喜你获得张角锁定技——雷击（使用或打出闪时进行判定，为黑桃电脑减2点体力，为草花电脑减1点体力，你加1点体力（可大于体力上限）)\n");
		printf("恭喜你获得张角锁定技——鬼道（你可打出一张牌替换判定牌,雷击不可改）\n");
		printf("恭喜你获得张角觉醒技——大吉（累计造成的伤害大于等于4时，体力+2，手牌上限+2）\n"); 
		printf("恭喜你获得张角限定技——黄天（开局体力-2，然后多摸4张牌）\n");
	}
	if(shenfen==15)
	{
		printf("恭喜你获得甄宓锁定技——洛神（准备阶段，你可以进行判定，若结果为黑色，你获得此牌，然后你可以重复此流程。\n"); 
		printf("恭喜你获得甄宓锁定技——倾城（限一次，你视为打出闪）\n");
	}
	if(shenfen==16)
	{
		printf("恭喜你获得马超锁定技——马术(你计算与其他角色的距离-1)\n");
		printf("恭喜你获得马超锁定技——铁骑(当你使用【杀】指定目标后，你可以进行判定，若结果为红色，该角色不能使用【闪】\n");
	} 
	if(shenfen==17)
	{
		printf("恭喜你获得贾诩锁定技——完杀(你的回合内，只有你能使用【桃】)\n");
		printf("恭喜你获得贾诩锁定技——帷幕(锁定技，黑色锦囊牌的你无效;你的回合内你不受到伤害)\n");
		printf("恭喜你获得贾诩限定技——乱武(指定回合，杀或决斗伤害为3；多获得一个回合，身份为董卓)\n");
	}
	if(shenfen==18)
	{
		printf("恭喜你获得董卓锁定技——酒池(随机弃置1张手牌，视为使用【酒】（无限制）,若弃置的手牌为基本牌，你摸两张牌(使用酒数量<=2))\n");
		printf("恭喜你获得董卓锁定技——肉林(你用杀对敌人的伤害时,你进行判定，若为黑桃，弃置1~3张牌)\n");
		printf("恭喜你获得董卓锁定技——崩环(若你的体力为全场最大，你每回合减一点体力或体力上限)\n");
	} 
	if(shenfen==19)
	{
		printf("恭喜你获得黄盖锁定技——苦肉(减一点体力摸两张牌,减一点体力上限该回合杀伤害+2)\n");
	}
	if(shenfen==20)
	{
		printf("恭喜你获得吕蒙锁定技——克己(跳过出牌阶段，你摸2张牌，然后跳过弃牌阶段)\n");
		printf("恭喜你获得吕蒙锁定技——攻心(如果你于出牌阶段打出4种不同花色的手牌，你额外获得一个回合)\n");
	}
	if(shenfen==21)
	{
		printf("恭喜你获得貂蝉锁定技——离魂(你获得对方所有手牌，然后翻面)\n"); 
		printf("恭喜你获得貂蝉锁定技——闭月(结束阶段摸两张牌)\n");
	}
	if(shenfen==22)
	{
		printf("恭喜你获得吕布锁定技——无双(你使用杀时，对方需出两张闪，并进行判定，若为黑桃此杀伤害+1)\n");
		printf("恭喜你获得吕布锁定技——飞将（决斗对你伤害为0，决斗时对方需打出两张杀）\n"); 
		printf("恭喜你获得吕布锁定技——利驭(你使用杀对对方造成伤害时，摸对面一张牌，弃置对方一张牌，对方下回合多摸x张牌[x:你杀造成伤害的次数])\n"); 
	}
	if(shenfen==23)
	{
		printf("恭喜你获得赵云锁定技——龙胆(你可将杀当闪，闪当杀(这样的【杀】不限次数))\n");
		printf("恭喜你获得赵云锁定技——枪魂(你可在回合开始阶段失去x点体力,本回合手牌若少于x则补至x张)\n");
	}
	if(shenfen==24||shenfen==25)
	{
		cout<<"前方出现隐藏BOSS"<<endl;
		if(shenfen==24)
		{
		 	printf("恭喜你获得LI HAOXUAN锁定技——坚守(手牌数小于等于8时，不弃牌)\n");
		 	printf("恭喜你获得LI HAOXUAN技能——苦肉(减一点体力摸两张牌,减一点体力上限该回合杀伤害+2)\n");
		 	printf("恭喜你获得LI HAO XUAN锁定技——崩环（杀对你造成额外一点伤害）\n");
		 	system("start PIC1.png");
		 	system("pause");
		}
		else if(shenfen==25)
		{
		 	printf("恭喜你获得 DONG 韵存 锁定技——英姿（你比别人多摸一张牌）\n");
		 	printf("恭喜你获得 DONG 韵存 锁定技——射术（自带不可拆麒麟弓）\n");
		 	printf("恭喜你获得 DONG 韵存 锁定技——闭月羞花(结束阶段摸两张牌)\n");
		 	printf("恭喜你获得 DONG 韵存 锁定技——倾国倾城（限一次，你视为打出闪）\n");
		 	system("start PIC2.png");
		 	system("pause");
		}
	} 
	color(7); 
	cout<<"电脑选取武将";
	srand((unsigned)time(NULL));
	if(shenfen==24||shenfen==25)
	{
		comshenfen=4;
		color(4);
		cout<<"趣学语文Mr.Dong\n";
		color(3);
		cout<<"电脑获得 趣学语文Mr.Dong锁定技——无双(使用杀时，你需出两张闪)"<<endl;
		cout<<"                               -------------“见了老子还想跑？！？” "<<endl;
		color(2);
		cout<<"电脑获得 趣学语文Mr.Dong锁定技——嘲彘(每回合可拆掉玩家1-3张手牌)"<<endl;
		cout<<"                               -------------“髀肉复生是什么意思？” \n";
		color(7);
		cout<<"电脑获得 趣学语文Mr.Dong锁定技——天机(跳过判定阶段)";
		cout<<"                 -------------“以我有限的智慧，你肯定是抄的！！！” \n";
		color(8);
		cout<<"电脑获得 趣学语文Mr.Dong锁定技——苦水(出牌阶段全场失去1点体力)";
		cout<<" --------“要不是当年我错1拖3，我的学校就没有师范二字。！” \n";
		color(9);
		color(4); 
		cout<<"电脑获得 趣学语文Mr.Dong限定技——万岁(对全场造成3点伤害，玩家体力上限减一)";
		cout<<"--------“工具牛马螺丝钉？山呼万岁？大厦将倾？！！” \n";
	}
	else
	{
		int t=rand()%4;
		if(t==0||t==2)
		{ 
			comshenfen=1;
			cout<<"华雄\n";
			cout<<"电脑获得华雄锁定技——恃勇（受到伤害摸两张牌）\n"; 
			cout<<"电脑获得华雄锁定技——无前（每回合进行判定，为红桃牌你回复一点体力，否则电脑回复一点体力(电脑体力不得大于体力上限，若玩家体力已满，视为增加一点护盾)）\n";
		}
		else if(t==1)
		{
			comshenfen=2;
			cout<<"道格拉斯-麦克阿瑟\n";
			cout<<"恭喜您遭遇强敌,我方体力上限+5，体力+5,手牌上限+5,结束阶段摸4张牌\n";
			cout<<"电脑获得道格拉斯-麦克阿瑟锁定技——跳岛（电脑出牌阶段开始视为使用【过河拆桥】）\n";
			cout<<"【跳岛】修改后：改为‘出牌阶段结束’\n" ; 
			cout<<"电脑获得道格拉斯-麦克阿瑟锁定技——围困（玩家摸牌牌阶段少摸一张牌）\n";
			cout<<"电脑获得道格拉斯-麦克阿瑟锁定技——骄恣（体力为全场最大，获得【崩环】）\n";
			cout<<"电脑获得道格拉斯-麦克阿瑟限定技——仁川登陆（视为使用【南蛮入侵】【万箭齐发】各两次，【兵粮寸断】【乐不思蜀】一次，摸10张牌，【杀】无限制并修改跳岛）\n";
		}
		else 
		{
			comshenfen=3;
			cout<<"日本鬼子\n";
			cout<<"电脑获得日本鬼子锁定技——凶残（【杀】无限制，每出一张杀-1体力）\n";
			cout<<"电脑获得日本鬼子限定技——嗜血（体力上限改为1，视为使用（原体力上限-1）张【杀】）\n";		
		}
	}
	
	color(9);
	system("pause");
	system("cls");
	void Kanshoupai(pai p);
	pai yuanshipaidui[2][4][13],qipaidui[208],paidui[208];
	//com:电脑      wanjia:玩家  
	wujiang wanjia,com;//wujiang结构体类型变量 
	com.tili=6;//体力 
	com.tilishangxian=6;//体力上限 
	if(shenfen==1||shenfen==5||shenfen==6||shenfen==7||shenfen==8||shenfen==10||shenfen==11||shenfen==12||shenfen==16||shenfen==19||shenfen==20)
	{
		wanjia.tili=4;
		wanjia.tilishangxian=4;
	} 
	else if(shenfen==23)//赵云 
	{
		wanjia.tili=2;
		wanjia.tilishangxian=2;		
	} 
	else if(shenfen==18)//董胖子 
	{
		wanjia.tili=9;
		wanjia.tilishangxian=9;
	}
	else if(shenfen==22)//吕布 
	{
		wanjia.tili=5;
		wanjia.tilishangxian=5;		
	} 
	else if(shenfen==24)//LI hao xuan
	{
		wanjia.tili=5;
		wanjia.tilishangxian=8;	
	}
	else 
	{
		wanjia.tili=3;
		wanjia.tilishangxian=3;
	}
	if(comshenfen==1)
	{
		com.tili+=1;
		com.tilishangxian+=1;
	} 
	else if(comshenfen==2)
	{
		com.tili+=4;
		com.tilishangxian+=4;	
		wanjia.tili+=5;
		wanjia.tilishangxian+=5;	
	}
	else if(comshenfen==4)
	{
		wanjia.tili+=2;
		wanjia.tilishangxian+=2;
		com.tili=20;
		com.tilishangxian=20;
	}
	com.huihekaishi=wanjia.huihekaishi=0;//回合开始 
	com.panding=wanjia.panding=0;//判定 
	com.mopai=wanjia.mopai=0;//摸牌 
	com.chupai=wanjia.chupai=0;//出牌 
	com.qipai=wanjia.qipai=0;//弃牌 
	com.huihejieshu=wanjia.huihejieshu=0;//回合结束 
	com.shoupaishu=wanjia.shoupaishu=0;//手牌数 
	com.pandingshu=wanjia.pandingshu=0;//判定的牌的数量 
	com.zhuangbeishu=wanjia.zhuangbeishu=0;//装备数 
	com.juese=0;wanjia.juese=1;//角色
	pai p;
	p.leixing=-1;
	com.zhuangbei[0]=com.zhuangbei[1]=com.zhuangbei[2]=com.zhuangbei[3]=wanjia.zhuangbei[0]=wanjia.zhuangbei[1]=wanjia.zhuangbei[2]=wanjia.zhuangbei[3]=p;//装备 
	com.zhuangbei[0].changdu=wanjia.zhuangbei[0].changdu=1;//装备长度 
	if(shenfen==25)
	{
		wanjia.zhuangbei[0].changdu=5;
	} 
	com.pandingpai[0]=com.pandingpai[1]=com.pandingpai[2]=wanjia.pandingpai[0]=wanjia.pandingpai[1]=wanjia.pandingpai[2]=p;//牌顶的牌 
	com.juli[0]=wanjia.juli[0]=1;//距离 
	for(int a=0;a<=1;a++)//两堆牌 （摸牌堆，弃牌堆） 
	{
		for(int b=0;b<=3;b++)//4种花色 
		{
			for(int c=0;c<=12;c++)//13个点数 
			{
				yuanshipaidui[a][b][c].paifu=a;
				yuanshipaidui[a][b][c].huase=b;
				yuanshipaidui[a][b][c].dianshu=c;
			}
		}
	}
	//2*4*13=104（张牌） 
	yuanshipaidui[0][0][0].leixing=204;
	yuanshipaidui[0][0][1].leixing=331;
	yuanshipaidui[0][0][2].leixing=201;
	yuanshipaidui[0][0][3].leixing=201;
	yuanshipaidui[0][0][4].leixing=304;yuanshipaidui[0][0][4].changdu=3;//青龙偃月刀(3)
	yuanshipaidui[0][0][5].leixing=251;
	yuanshipaidui[0][0][6].leixing=101;
	yuanshipaidui[0][0][7].leixing=101;
	yuanshipaidui[0][0][8].leixing=101;
	yuanshipaidui[0][0][9].leixing=101;
	yuanshipaidui[0][0][10].leixing=202;
	yuanshipaidui[0][0][11].leixing=201;
	yuanshipaidui[0][0][12].leixing=208;
	yuanshipaidui[0][1][0].leixing=209;
	yuanshipaidui[0][1][1].leixing=102;
	yuanshipaidui[0][1][2].leixing=103;
	yuanshipaidui[0][1][3].leixing=103;
	yuanshipaidui[0][1][4].leixing=308;yuanshipaidui[0][1][4].changdu=5;//麒麟弓(5)
	yuanshipaidui[0][1][5].leixing=103;
	yuanshipaidui[0][1][6].leixing=103;
	yuanshipaidui[0][1][7].leixing=103;
	yuanshipaidui[0][1][8].leixing=103;
	yuanshipaidui[0][1][9].leixing=101;
	yuanshipaidui[0][1][10].leixing=101;
	yuanshipaidui[0][1][11].leixing=103;
	yuanshipaidui[0][1][12].leixing=102;
	yuanshipaidui[0][2][0].leixing=204;
	yuanshipaidui[0][2][1].leixing=101;
	yuanshipaidui[0][2][2].leixing=101;
	yuanshipaidui[0][2][3].leixing=101;
	yuanshipaidui[0][2][4].leixing=101;
	yuanshipaidui[0][2][5].leixing=101;
	yuanshipaidui[0][2][6].leixing=101;
	yuanshipaidui[0][2][7].leixing=101;
	yuanshipaidui[0][2][8].leixing=101;
	yuanshipaidui[0][2][9].leixing=101;
	yuanshipaidui[0][2][10].leixing=101;
	yuanshipaidui[0][2][11].leixing=205;
	yuanshipaidui[0][2][12].leixing=205;
	yuanshipaidui[0][3][0].leixing=204;
	yuanshipaidui[0][3][1].leixing=102;
	yuanshipaidui[0][3][2].leixing=102;
	yuanshipaidui[0][3][3].leixing=102;
	yuanshipaidui[0][3][4].leixing=102;
	yuanshipaidui[0][3][5].leixing=101;
	yuanshipaidui[0][3][6].leixing=101;
	yuanshipaidui[0][3][7].leixing=101;
	yuanshipaidui[0][3][8].leixing=101;
	yuanshipaidui[0][3][9].leixing=101;
	yuanshipaidui[0][3][10].leixing=102;
	yuanshipaidui[0][3][11].leixing=103;
	yuanshipaidui[0][3][12].leixing=101;
	yuanshipaidui[1][0][0].leixing=252;
	yuanshipaidui[1][0][1].leixing=302;yuanshipaidui[1][0][1].changdu=2;//雌雄双股剑(2)
	yuanshipaidui[1][0][2].leixing=202;
	yuanshipaidui[1][0][3].leixing=202;
	yuanshipaidui[1][0][4].leixing=383;
	yuanshipaidui[1][0][5].leixing=303;yuanshipaidui[1][0][5].changdu=2;//青釭剑(2)
	yuanshipaidui[1][0][6].leixing=208;
	yuanshipaidui[1][0][7].leixing=101;
	yuanshipaidui[1][0][8].leixing=101;
	yuanshipaidui[1][0][9].leixing=101;
	yuanshipaidui[1][0][10].leixing=210;
	yuanshipaidui[1][0][11].leixing=305;yuanshipaidui[1][0][11].changdu=3;//丈八蛇矛(3)
	yuanshipaidui[1][0][12].leixing=362;
	yuanshipaidui[1][1][0].leixing=206;
	yuanshipaidui[1][1][1].leixing=102;
	yuanshipaidui[1][1][2].leixing=207;
	yuanshipaidui[1][1][3].leixing=207;
	yuanshipaidui[1][1][4].leixing=361;
	yuanshipaidui[1][1][5].leixing=251;
	yuanshipaidui[1][1][6].leixing=203;
	yuanshipaidui[1][1][7].leixing=203;
	yuanshipaidui[1][1][8].leixing=203;
	yuanshipaidui[1][1][9].leixing=101;
	yuanshipaidui[1][1][10].leixing=203;
	yuanshipaidui[1][1][11].leixing=201;
	yuanshipaidui[1][1][12].leixing=381;
	yuanshipaidui[1][2][0].leixing=301;yuanshipaidui[1][2][0].changdu=1;//诸葛连弩(1)
	yuanshipaidui[1][2][1].leixing=331;
	yuanshipaidui[1][2][2].leixing=201;
	yuanshipaidui[1][2][3].leixing=201;
	yuanshipaidui[1][2][4].leixing=382;
	yuanshipaidui[1][2][5].leixing=251;
	yuanshipaidui[1][2][6].leixing=208;
	yuanshipaidui[1][2][7].leixing=101;
	yuanshipaidui[1][2][8].leixing=101;
	yuanshipaidui[1][2][9].leixing=101;
	yuanshipaidui[1][2][10].leixing=101;
	yuanshipaidui[1][2][11].leixing=210;
	yuanshipaidui[1][2][12].leixing=210;
	yuanshipaidui[1][3][0].leixing=301;yuanshipaidui[1][3][0].changdu=1;//诸葛连弩(1)[有两把]
	yuanshipaidui[1][3][1].leixing=102;
	yuanshipaidui[1][3][2].leixing=202;
	yuanshipaidui[1][3][3].leixing=202;
	yuanshipaidui[1][3][4].leixing=306;yuanshipaidui[1][3][4].changdu=3;//贯石斧(3)
	yuanshipaidui[1][3][5].leixing=102;
	yuanshipaidui[1][3][6].leixing=102;
	yuanshipaidui[1][3][7].leixing=102;
	yuanshipaidui[1][3][8].leixing=102;
	yuanshipaidui[1][3][9].leixing=102;
	yuanshipaidui[1][3][10].leixing=102;
	yuanshipaidui[1][3][11].leixing=307;yuanshipaidui[1][3][11].changdu=4;//方天画戟(4) 
	yuanshipaidui[1][3][12].leixing=363;
	//////////////////////////////////////////////军争篇 
	yuanshipaidui[0][1][13].leixing=384;//兵粮寸断 
	yuanshipaidui[0][2][13].leixing=384;//兵粮寸断 
	int paiduishu=104;//104张牌 
	int qipaishu=0;//弃牌数 
	Qishixipai(yuanshipaidui,paidui);
	Qishishoupai(&wanjia,paidui,&(paiduishu),qipaidui,&(qipaishu));
	Qishishoupai(&com,paidui,&(paiduishu),qipaidui,&(qipaishu));
	//调用三个函数 
	int i;
	for(;;)//判断结束 
	{
		//玩家回合 
		wodehuihe=1;
		difanghuihe=0;
		if(shenfen==17&&luanwu==0)
		{
			color(5); 
			cout<<"是否使用贾诩限定技——乱武(指定回合，杀或决斗伤害为3；多获得一个回合，身份为董卓）\n";
			color(9);
			cout<<"是，输入1\n";
			int p;
			cin>>p;
			if(p==1)
			{
				color(5);
				cout<<"触发贾诩限定技——乱武(指定回合，杀或决斗伤害为3；多获得一个回合，身份为董卓）\n";
				color(9);
				luanwu=3; 
			}
		}
	    if(shenfen==21&&lihun==1)
		{
			lihun=0;
			color(5);
			printf("触发貂蝉锁定技——离魂(你获得对方所有手牌，然后翻面)\n");
			color(9);
			cout<<"你从背面翻至反面\n"; 
		}
		else
		{
			i=Huihe(paidui,qipaidui,&paiduishu,&qipaishu,yuanshipaidui,&wanjia,&com);//开始正式打牌 
		} 
	    if(shenfen==17&&luanwu==3)
	    {
	    	color(5);
	    	cout<<"触发贾诩限定技——乱武(指定回合，杀或决斗伤害为3；多获得一个回合，身份为董卓）\n";
	    	color(9);
	    	luanwu=-1;
	    	shenfen=18;
			i=Huihe(paidui,qipaidui,&paiduishu,&qipaishu,yuanshipaidui,&wanjia,&com);//贾诩以董卓的身份打牌 
			shenfen=17;
		}
		if(shenfen==20&&gongxin==1)
		{
			color(5);
			gongxin=0;
			printf("触发吕蒙锁定技——攻心(如果你于出牌阶段打出4种不同花色的手牌，你额外获得一个回合)\n");
			color(9);
			i=Huihe(paidui,qipaidui,&paiduishu,&qipaishu,yuanshipaidui,&wanjia,&com);
		}
	    if(i==-1)
	    {
	    	cout<<"游戏结束···\n"; 
	    	system("pause");
	        break;
	    }
	    //////////////////////
	    //电脑回合 
	    wodehuihe=0;
	    difanghuihe=1;
	    i=Huihe(paidui,qipaidui,&paiduishu,&qipaishu,yuanshipaidui,&com,&wanjia);
	    if(i==-1)
	    {
	    	cout<<"游戏结束···\n";
			system("pause"); 
	        break;
	    }
	}
	return ;
}
int main()
{
	system("title SGS");
	if (MessageBox(0, TEXT("除输入名字外，请不要输入任何字母，否则将导致游戏崩溃！"), TEXT("重要提示"), MB_OKCANCEL | MB_ICONINFORMATION) != IDOK)
	{
		MessageBox(0, TEXT("既然你不同意，那就别玩了"), TEXT("重要提示"), MB_OK);
		return 0;
	};
	color(9);
	cout<<"是否观看先导视频？是按1\n";
	int l1;
	cin>>l1;
	if(l1==1)
	{
		color(3);
		cout<<"请欣赏\n"; 
		color(9);
		system("start xiandao.mp4");
		system("pause");
		cout<<"抱歉放错了（抱歉放成OL魔貂蝉了）\n";
		system("start kv.mp4");
		system("pause");
	}
	system("cls"); 
	system("start sanguo.mp3") ;
	while(1)
	{
		system("cls");
		color(9);
		system("date /T");
		system("TIME /T");
		cout<<"欢迎来到";
		color(4);
		cout<<"三国杀                          "; 
		color(2);
		cout<<"珍爱生命，远离游戏\n";
		color(9);
		cout<<"1.三国杀 2.退出并保存";
		color(5);
		cout<<"(有彩蛋) ";
		color(9);
		cout<<"3.查看战绩 4.打开狗卡exe（需安装）5.换壁纸 6.致谢\n"; 
		cout<<"版本：";
		color(3);
		cout<<edition<<endl; 
		ofstream outfile("data.txt", ios::binary | ios::app | ios::in | ios::out);
		ifstream fin("data.txt");
		int a1,b1;
		while(fin>>score&&bug_1==0)//查询战绩 
		{
			if(score[0]=='-')
			{
				check_flag=1;
			}
			if(check_flag==1)
			{
				check_flag=0;
				fin>>a1>>b1;
				wanjialishi+=a1,comlishi+=b1;
			}
			//cout<<wanjialishi<<"     "<<comlishi<<endl; 
		}
		bug_1=1;
		color(9);
		int choose;
		cin>>choose;
		if(choose==1)
		{
			system("cls");
			SGS();
		} 
		else if(choose==2)
		{
			cout<<"开始保存.....................\n";
			save();
			Sleep(1000);
			cout<<"保存完毕.....................\n";
			system("pause"); 
			cout<<"游戏结束"<<endl; 
			cout<<"是否看see you again视频？是按1\n";
			int l2;
			cin>>l2;
			if(l2==1)
			{
				color(3);
				cout<<"请欣赏\n"; 
				color(9);
				system("start video.mp4");
				system("pause");
			}
			system("start seeyouagain.mp3");
			Sleep(1000);
			color(3);
			cout<<"另附浅墨大神的dream (RIP)"<<endl; 
			Sleep(1000);
			color(4);
			cout<<"All our dreams can come true, if we have the courage to pursue them. "<<endl; 
			Sleep(1000);
			cout<<"我们所有的梦想都可以成真，只要我们有勇气去追求它们。 "<<endl; 
			Sleep(1000);
			cout<<"                              ————沃尔特·迪斯尼"<<endl; 
			Sleep(1000);
			color(5);
			cout<<"我有一个梦想，将来的某一天，大家都能玩到蕴含着中国上下五千年本土文化的优质游戏大作。"<<endl; 
			Sleep(1000);
			cout<<"我有一个梦想，有一天，西游记能出ACT，让老外去体会中国文化西游记中”斗战胜佛”的打击快感，那一定比西方的动作巅峰之作《战神》、《鬼泣》更加深邃。"<<endl; 
			Sleep(1000);
			cout<<"我有一个梦想，有一天，上海滩能出沙盒游戏，而不是玩《GTA》感受美国梦，亦或是玩着《热血无赖》体验国外公司强行塞给我们的“中国文化”。"<<endl; 
			Sleep(1000);
			cout<<"我有一个梦想，有一天，不少3A大作不需要汉化，因为是我们自己的游戏，配音是中文，文化也是中国的。"<<endl; 
			Sleep(1000);
			cout<<"我有一个梦想，将来的某一天，国产游戏能像中国的其他产业一样，以一个领跑者的姿态，面对全世界，面对全宇宙，器宇轩昂，扬眉吐气。"<<endl; 
			Sleep(1000);
			cout<<"这会是由我们一起去完成的梦想。"<<endl; 
			Sleep(1000);
			cout<<"我等着我们的好消息。"<<endl; 
			Sleep(1000);
			cout<<"                                                                                                  浅墨 2013年5月于乌克兰"<<endl; 
			color(0);
			system("pause");
			break;
		}
		else if(choose==3) 
		{
			color(4); 
			printf("战绩\n");
			color(5);
			printf("玩家击杀电脑%d次\n",wanjialishi);
			printf("电脑击杀玩家%d次\n",comlishi);
			system("pause");
		}
		else if(choose==4) 
		{
			system("start yoka.exe");
		}
		else if(choose==5)
		{
			cout<<"1.人物（4张） 2.节日（28张）\n";
			cout<<"说明：win10不一定能（一次）换好,wait patiently please!\n";
			cout<<"把源文件放在桌面才能换\n";
			cout<<"可以手动换！见wallpaper\n";
			int cho;
			cin>>cho;
			if(cho==1)
			{
				system("start replace1.bat");
				system("pause");
			}
			else
			{
				system("start replace2.bat");
				system("pause");
			}
		}
		else
		{
			thank();
		}
	}
	return 0; 
}
