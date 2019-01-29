

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for interface.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, app_config, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __interface_h_h__
#define __interface_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __rpc_INTERFACE_DEFINED__
#define __rpc_INTERFACE_DEFINED__

/* interface rpc */
/* [implicit_handle][version][uuid] */ 

boolean impersonization( 
    /* [in] */ handle_t Handle,
    /* [string][in] */ unsigned char *username,
    /* [string][in] */ unsigned char *password);

int deleteFile( 
    /* [string][in] */ unsigned char *filename);

int createFile( 
    /* [string][in] */ unsigned char *filename);

int readFrom( 
    /* [string][in] */ unsigned char *filename,
    /* [out] */ unsigned char readData[ 1024 ],
    /* [in] */ long offset);

int writeToFile( 
    /* [string][in] */ unsigned char *filename,
    /* [in] */ unsigned char writeData[ 1024 ],
    /* [in] */ long count);


extern handle_t rpcHandle;


extern RPC_IF_HANDLE rpc_v1_0_c_ifspec;
extern RPC_IF_HANDLE rpc_v1_0_s_ifspec;
#endif /* __rpc_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


