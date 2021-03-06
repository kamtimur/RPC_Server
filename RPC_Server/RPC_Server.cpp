#define _CRT_SECURE_NO_WARNINGS

#include "windows.h"
#include <iostream>
#include "interface_h.h"
#include "stdio.h"
#include <fstream>

#pragma comment(lib, "rpcrt4.lib")

using namespace std;

RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE, void*);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	RPC_STATUS status = NULL;

	status = RpcServerUseProtseqEpA(
		(RPC_CSTR)("ncacn_ip_tcp"),
		RPC_C_PROTSEQ_MAX_REQS_DEFAULT,
		(RPC_CSTR)("4747"),
		NULL);

	if (status)
		exit(status);

	status = RpcServerRegisterIf2(
		rpc_v1_0_s_ifspec,
		NULL,
		NULL,
		RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,
		RPC_C_LISTEN_MAX_CALLS_DEFAULT,
		(unsigned)-1,
		SecurityCallback);

	if (status)
		exit(status);

	status = RpcServerListen(1, RPC_C_LISTEN_MAX_CALLS_DEFAULT, 0);

	if (status)
		exit(status);
}

void* __RPC_USER midl_user_allocate(size_t size) {
	return malloc(size);
}

void __RPC_USER midl_user_free(void* p) {
	free(p);
}

RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE, void*) {
	return RPC_S_OK;
}

boolean impersonization(
	/* [in] */ handle_t Handle,
	/* [string][in] */ unsigned char *username,
	/* [string][in] */ unsigned char *password) {

	boolean check = LogonUserA(
		(LPCSTR)username,
		NULL,
		(LPCSTR)password,
		LOGON32_LOGON_INTERACTIVE,
		LOGON32_PROVIDER_DEFAULT,
		&Handle);

	if (!check) {
		cout
			<< "Logging user " << username << " has failed "
			<< "Pass is " << password << endl
			<< "Check is " << check << endl;
		return false;
	}

	if (!ImpersonateLoggedOnUser(Handle)) {
		cout << "Impersonalization as " << username << " has failed" << endl;
		return false;
	}

	cout << "Impersonalization as " << username << " has been successful " << endl;
	return true;
}

int deleteFile(
	/* [string][in] */ unsigned char *filename) {
	return DeleteFileA((LPCSTR)filename);
}

int createFile(
	/* [string][in] */ unsigned char *filename) {
	FILE *f = fopen((const char*)filename, "w");

	if (!f)
	{
		printf("read! %s\n", strerror(errno));
		return -1;
	}

	fclose(f);

	return 0;
}

int readFrom(
	/* [string][in] */ unsigned char *filename,
	/* [out] */ unsigned char readData[1024],
	/* [in] */ long offset) {

	FILE *f = fopen((const char*)filename, "rb");

	if (!f)
	{
		return -1;
	}
	fseek(f, offset, SEEK_SET);

	int readed = fread(readData, 1, 512, f);

	fclose(f);

	return readed;
}

int writeToFile(
	/* [string][in] */ unsigned char *filename,
	/* [in] */ unsigned char writeData[1024],
	/* [in] */ long count) {

	FILE *f = fopen((const char*)filename, "ab");

	if (fwrite(writeData, 1, count, f) != count) {
		fclose(f);
		return 1;
	}

	fclose(f);
	return 0;
}
