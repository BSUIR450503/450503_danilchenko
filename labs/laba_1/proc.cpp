// spo_1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#endif
void main( void )
{
#ifdef _WIN32
	int x = 9;
	
	STARTUPINFO StartupInfo;
    PROCESS_INFORMATION ProcInfo;
    TCHAR CommandLine[] = TEXT("child 9");


	ZeroMemory( &StartupInfo, sizeof(StartupInfo) );
    StartupInfo.cb = sizeof(StartupInfo);
    ZeroMemory( &ProcInfo, sizeof(ProcInfo) );

	if( !CreateProcess( NULL, // �� ������������ ��� ������ 
        CommandLine,	      // ��������� ������
        NULL,                 // ���������� �������� �� �����������. 
        NULL,                 // ���������� ������ �� �����������. 
        FALSE,                // ��������� ���������� ������������
        0,					  // ��� ������ �������� ��������
        NULL,                 // ���� ���������� ��������� ������������� ��������
        NULL,                 // ������������ ������� ������� ������������� ��������
        &StartupInfo,         // ��������� �� ���������  STARTUPINFO.
        &ProcInfo )           // ��������� �� ��������� ���������� � ��������.
      )
    
	{
        printf("CreateProcess failed with error code (%d).\n", GetLastError());
		system("pause");
        return;
    }
      
    WaitForSingleObject( ProcInfo.hProcess, INFINITE );

	DWORD dw = NULL;
	GetExitCodeProcess( ProcInfo.hProcess, &dw);

	printf("%d * %d = %d\n", x,x, (int)dw );
 
    CloseHandle( ProcInfo.hProcess );
    CloseHandle( ProcInfo.hThread );	
#else
	int x = 12;
	pid_t pid;
	int c;
	pid=fork();
	switch(pid) 
	{
		case -1:
			perror("fork");
			exit(1);
		case 0:
			x *=x;
			exit(x);
		default:
			wait(&c);
			WEXITSTATUS(rv);
			printf ("%d*%d = %d",x,x,rv/256);
	}
#endif

	system("pause");
}

