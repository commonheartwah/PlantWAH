#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void ModifyResult(bool b)
{
	if (b)
	{
		printf("�޸ĳɹ�\n");

	}else{
		printf("�޸�ʧ��\n");
	}

}

void DisplaySun()
{
	HWND gameh = ::FindWindow(NULL,"ֲ���ս��ʬ���İ�");//���
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
	printf("����ǰ����Ϊ��%d\n",sun);

}
BOOL ModifySun(int wsun)
{
	HWND gameh = ::FindWindow(NULL,"ֲ���ս��ʬ���İ�");//���
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
//	printf("���⣺%d\n",sun);
	
	
	//int wsun = 10000;
	DWORD bywrite;
	LPVOID wbuffer = (LPVOID)&wsun;
	
	BOOL result = ::WriteProcessMemory(processh,(LPVOID)pbase,wbuffer,4,&bywrite);

	return result;
}

void DisplayMoney()
{	
	HWND gameh = ::FindWindow(NULL,"ֲ���ս��ʬ���İ�");//���
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

		printf("����ǰ��ң�%d\n",money*10);

}

BOOL ModifyMoney(int wmoney)
{
	HWND gameh = ::FindWindow(NULL,"ֲ���ս��ʬ���İ�");//���
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
	
//	printf("����ǰ��ң�%d\n",money*10);
	
	DWORD bywrite;
	wmoney = wmoney / 10;
	
	LPVOID mbuffer = (LPVOID)&wmoney;
	
	BOOL result = ::WriteProcessMemory(processh,(LPVOID)pbase,mbuffer,4,&bywrite);
	return result;
}

void MainMenu()
{

	printf("====�˵�====\n");
	printf("1���޸�����\n");
	printf("2���޸Ľ��\n");
	printf("3���˳����\n");
	printf("============\n");

}


// Downloads By http://www.veryhuo.com
void main()
{
	HWND gameh = ::FindWindow(NULL,"ֲ���ս��ʬ���İ�");//���
	RECT r;
	POINT p;
	
	::GetWindowRect(gameh,&r);
	printf("��Ϸ��Ϣ��%d",r.left);
	
	printf("  %d\n",r.top);
	
	::GetCursorPos(&p);
	printf("�����Ϣ��%d  %d\n",p.x,p.y);

	if (gameh == NULL)
	{
		printf("����������Ϸ���ٴ����... ������վ veryhuo.com");
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
			printf("������������޸�ֵ\n");
			scanf("%d",&temp);
			ModifyResult(ModifySun(temp));
			temp = 0;
			break;
		case 2:
			DisplayMoney();
			printf("�������ҵ��޸�ֵ\n");
			scanf("%d",&temp);
		    ModifyResult(ModifyMoney(temp));
			temp = 0;
			break;
		default:
			temp = 0;
			printf("�����˳�����\n");
			Sleep(3000);
			printf("Bye\n");
			return;
			break;
		
		
		}
	}

}


