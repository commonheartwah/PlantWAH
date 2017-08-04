#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void ModifyResult(bool b)
{
	if (b)
	{
		printf("修改成功\n");

	}else{
		printf("修改失败\n");
	}

}

void DisplaySun()
{
	HWND gameh = ::FindWindow(NULL,"植物大战僵尸中文版");//句柄
	int sun = 0;
	
	DWORD processid;
	::GetWindowThreadProcessId(gameh,&processid);
	HANDLE processh = :: OpenProcess(PROCESS_ALL_ACCESS,false,processid);	
	DWORD byread;
	LPCVOID pbase = (LPCVOID)6987456;
	LPVOID rbuffer = (LPVOID)&sun;
	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);
	
	pbase = (LPCVOID)(sun + 1896);
	
	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);
	
	pbase = (LPCVOID)(sun + 21856);
	
	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);
	printf("您当前阳光为：%d\n",sun);

}
BOOL ModifySun(int wsun)
{
	HWND gameh = ::FindWindow(NULL,"植物大战僵尸中文版");//句柄
	int sun = 0;
	
	DWORD processid;
	::GetWindowThreadProcessId(gameh,&processid);
	HANDLE processh = :: OpenProcess(PROCESS_ALL_ACCESS,false,processid);	
	DWORD byread;
	LPCVOID pbase = (LPCVOID)6987456;
	LPVOID rbuffer = (LPVOID)&sun;
	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);
	
	pbase = (LPCVOID)(sun + 1896);
	
	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);
	
	pbase = (LPCVOID)(sun + 21856);
	
	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);
//	printf("阳光：%d\n",sun);
	
	
	//int wsun = 10000;
	DWORD bywrite;
	LPVOID wbuffer = (LPVOID)&wsun;
	
	BOOL result = ::WriteProcessMemory(processh,(LPVOID)pbase,wbuffer,4,&bywrite);

	return result;
}

void DisplayMoney()
{	
	HWND gameh = ::FindWindow(NULL,"植物大战僵尸中文版");//句柄
	int money = 0;

	DWORD processid;
	::GetWindowThreadProcessId(gameh,&processid);
	HANDLE processh = :: OpenProcess(PROCESS_ALL_ACCESS,false,processid);	
	DWORD byread;


	LPCVOID pbase = (LPCVOID)6987456;
	LPVOID	rbuffer = (LPVOID)&money;
	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);

	pbase = (LPCVOID)(money + 2092);

	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);

	pbase = (LPCVOID)(money + 40);

	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);

		printf("您当前金币：%d\n",money*10);

}

BOOL ModifyMoney(int wmoney)
{
	HWND gameh = ::FindWindow(NULL,"植物大战僵尸中文版");//句柄
	int money = 0;

	DWORD processid;
	::GetWindowThreadProcessId(gameh,&processid);
	HANDLE processh = :: OpenProcess(PROCESS_ALL_ACCESS,false,processid);	
	DWORD byread; 
	

	LPCVOID pbase = (LPCVOID)6987456;
	LPVOID	rbuffer = (LPVOID)&money;
	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);
	
	pbase = (LPCVOID)(money + 2092);
	
	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);
	
	pbase = (LPCVOID)(money + 40);
	
	::ReadProcessMemory(processh,pbase,rbuffer,4,&byread);
	
//	printf("您当前金币：%d\n",money*10);
	
	DWORD bywrite;
	wmoney = wmoney / 10;
	
	LPVOID mbuffer = (LPVOID)&wmoney;
	
	BOOL result = ::WriteProcessMemory(processh,(LPVOID)pbase,mbuffer,4,&bywrite);
	return result;
}

void MainMenu()
{

	printf("====菜单====\n");
	printf("1、修改阳光\n");
	printf("2、修改金币\n");
	printf("3、退出外挂\n");
	printf("============\n");

}


// Downloads By http://www.veryhuo.com
void main()
{
	HWND gameh = ::FindWindow(NULL,"植物大战僵尸中文版");//句柄
	RECT r;
	POINT p;
	
	::GetWindowRect(gameh,&r);
	printf("游戏信息：%d",r.left);
	
	printf("  %d\n",r.top);
	
	::GetCursorPos(&p);
	printf("鼠标信息：%d  %d\n",p.x,p.y);

	if (gameh == NULL)
	{
		printf("请先运行游戏，再打开外挂... 最火软件站 veryhuo.com");
		Sleep(3000);
		return;
	
	}
	/*
	::SetCursorPos(r.left + 540,r.top + 145);
	
	::Sleep(50);
	
	
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

	::SetCursorPos(p.x,p.y);*/
	int op = 0;

	while (1)
	{

		MainMenu();
		scanf("%d",&op);
		int temp = 0;
		
		switch (op)
		{
		case 1:
			DisplaySun();
			printf("请输入阳光的修改值\n");
			scanf("%d",&temp);
			ModifyResult(ModifySun(temp));
			temp = 0;
			break;
		case 2:
			DisplayMoney();
			printf("请输入金币的修改值\n");
			scanf("%d",&temp);
		    ModifyResult(ModifyMoney(temp));
			temp = 0;
			break;
		default:
			temp = 0;
			printf("三秒退出程序\n");
			Sleep(3000);
			printf("Bye\n");
			return;
			break;
		
		
		}
	}

}


